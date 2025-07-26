// SmartFareTracker.cpp
// Simulates fare tracking for delivery/taxi apps (Zomato, Swiggy, Ola, Uber)

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

struct FareEntry {
    string service;
    float fare;
    string timestamp;
};

string getCurrentTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buf);
}

void generateMockFareData(const string& filename, int entries) {
    ofstream fout(filename);
    vector<string> services = {"Zomato", "Swiggy", "Uber", "Ola"};
    srand(time(0));

    for (int i = 0; i < entries; ++i) {
        string service = services[rand() % services.size()];
        float fare = 50 + rand() % 500 + (rand() % 100) / 100.0; // ₹50 to ₹550
        string timestamp = getCurrentTime();
        fout << service << "," << fixed << setprecision(2) << fare << "," << timestamp << endl;
    }

    fout.close();
}

vector<FareEntry> loadFareData(const string& filename) {
    vector<FareEntry> entries;
    ifstream fin(filename);
    string line;

    while (getline(fin, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find_last_of(',');

        if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) continue;

        string service = line.substr(0, pos1);
        float fare = stof(line.substr(pos1 + 1, pos2 - pos1 - 1));
        string timestamp = line.substr(pos2 + 1);

        entries.push_back({service, fare, timestamp});
    }

    return entries;
}

void displayFareTrend(const vector<FareEntry>& entries) {
    cout << "\n--- Fare Trend Dashboard (ASCII Graph) ---\n";
    for (const auto& entry : entries) {
        cout << left << setw(8) << entry.service << " ₹" << setw(6) << entry.fare << " ";
        int bar = static_cast<int>(entry.fare / 10);
        for (int i = 0; i < bar; ++i) cout << "#";
        cout << "\n";
    }
}

void alertForLowFares(const vector<FareEntry>& entries, float threshold) {
    cout << "\n--- Alerts for Low Fares (Below ₹" << threshold << ") ---\n";
    for (const auto& entry : entries) {
        if (entry.fare < threshold) {
            cout << "[ALERT] " << entry.service << " - ₹" << entry.fare << " at " << entry.timestamp << endl;
        }
    }
}

int main() {
    string filename = "mock_fares.csv";
    int mockEntries = 10;
    float alertThreshold = 150.0;

    generateMockFareData(filename, mockEntries);
    vector<FareEntry> fares = loadFareData(filename);

    displayFareTrend(fares);
    alertForLowFares(fares, alertThreshold);

    return 0;
}
