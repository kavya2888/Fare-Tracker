#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <algorithm>

using namespace std;

class ServicePlatform {
public:
    virtual double calculateCost() = 0;
    virtual string getName() = 0;
    virtual void displayDetails() = 0;
    virtual ~ServicePlatform() {}
};

class RideSharingService : public ServicePlatform {
protected:
    double distance;
    double surgeMultiplier;

public:
    RideSharingService(double dist, double surge)
        : distance(dist), surgeMultiplier(surge) {}
};


class Uber : public RideSharingService {
public:
    Uber(double dist, double surge)
        : RideSharingService(dist, surge) {}

    double calculateCost() override {
        return (50 + distance * 12) * surgeMultiplier;
    }

    string getName() override {
        return "Uber";
    }

    void displayDetails() override {
        cout << "Uber Ride | Distance: "
             << distance
             << " km | Surge: "
             << surgeMultiplier
             << "x\n";
    }
};

class Ola : public RideSharingService {
public:
    Ola(double dist, double surge)
        : RideSharingService(dist, surge) {}

    double calculateCost() override {
        return (40 + distance * 11) * surgeMultiplier;
    }

    string getName() override {
        return "Ola";
    }

    void displayDetails() override {
        cout << "Ola Ride | Distance: "
             << distance
             << " km | Surge: "
             << surgeMultiplier
             << "x\n";
    }
};

class FoodDeliveryService : public ServicePlatform {
protected:
    double orderValue;
    double deliveryDistance;

public:
    FoodDeliveryService(double orderVal,
                        double deliveryDist)
        : orderValue(orderVal),
          deliveryDistance(deliveryDist) {}
};

class Swiggy : public FoodDeliveryService {
public:
    Swiggy(double orderVal,
           double deliveryDist)
        : FoodDeliveryService(orderVal,
                              deliveryDist) {}

    double calculateCost() override {
        return orderValue +
               20 +
               (deliveryDistance * 3);
    }

    string getName() override {
        return "Swiggy";
    }

    void displayDetails() override {
        cout << "Swiggy Order | Order Value: ₹"
             << orderValue
             << " | Distance: "
             << deliveryDistance
             << " km\n";
    }
};


class Zomato : public FoodDeliveryService {
public:
    Zomato(double orderVal,
           double deliveryDist)
        : FoodDeliveryService(orderVal,
                              deliveryDist) {}

    double calculateCost() override {
        return orderValue +
               15 +
               (deliveryDistance * 4);
    }

    string getName() override {
        return "Zomato";
    }

    void displayDetails() override {
        cout << "Zomato Order | Order Value: ₹"
             << orderValue
             << " | Distance: "
             << deliveryDistance
             << " km\n";
    }
};


class FareTracker {
private:
    vector<shared_ptr<ServicePlatform>> services;

public:
    void addService(shared_ptr<ServicePlatform> service) {
        services.push_back(service);
    }

    void compareServices() {

        double minimumCost = 1e9;
        string bestService;

        cout << "\n=================================\n";
        cout << " SMART FARE TRACKER DASHBOARD\n";
        cout << "=================================\n\n";

        for (auto &service : services) {

            service->displayDetails();

            double cost = service->calculateCost();

            cout << "Total Cost: ₹"
                 << fixed
                 << setprecision(2)
                 << cost
                 << "\n\n";

            if (cost < minimumCost) {
                minimumCost = cost;
                bestService = service->getName();
            }
        }

        cout << "---------------------------------\n";
        cout << "Recommended Platform: "
             << bestService
             << "\n";

        cout << "Estimated Cost: ₹"
             << minimumCost
             << "\n";
        cout << "---------------------------------\n";
    }
};

int main() {

    FareTracker tracker;

    // Ride-sharing example
    double rideDistance = 10;   // km
    double surge = 1.2;

    tracker.addService(
        make_shared<Uber>(
            rideDistance,
            surge));

    tracker.addService(
        make_shared<Ola>(
            rideDistance,
            surge));

    // Food-delivery example
    double orderValue = 300; // ₹
    double deliveryDistance = 4;

    tracker.addService(
        make_shared<Swiggy>(
            orderValue,
            deliveryDistance));

    tracker.addService(
        make_shared<Zomato>(
            orderValue,
            deliveryDistance));

    tracker.compareServices();

    return 0;
}
