#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>

using namespace std;

// Abstract Base Class
class ServicePlatform {
public:
    virtual double calculateCost() = 0;
    virtual string getName() = 0;
    virtual void displayDetails() = 0;
    virtual ~ServicePlatform() {}
};

// Ride Sharing Services

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
             << surgeMultiplier << "x\n";
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
             << surgeMultiplier << "x\n";
    }
};


// Food Delivery Services

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
        return orderValue + 20 + (deliveryDistance * 3);
    }

    string getName() override {
        return "Swiggy";
    }

    void displayDetails() override {
        cout << "Swiggy Order | Order Value: ₹"
             << orderValue
             << " | Distance: "
             << deliveryDistance << " km\n";
    }
};

class Zomato : public FoodDeliveryService {
public:
    Zomato(double orderVal,
           double deliveryDist)
        : FoodDeliveryService(orderVal,
                              deliveryDist) {}

    double calculateCost() override {
        return orderValue + 15 + (deliveryDistance * 4);
    }

    string getName() override {
        return "Zomato";
    }

    void displayDetails() override {
        cout << "Zomato Order | Order Value: ₹"
             << orderValue
             << " | Distance: "
             << deliveryDistance << " km\n";
    }
};

// Shopping Services

class ShoppingService : public ServicePlatform {
protected:
    double productPrice;
    double shippingCharge;
    double discountPercent;

public:
    ShoppingService(double price,
                    double shipping,
                    double discount)
        : productPrice(price),
          shippingCharge(shipping),
          discountPercent(discount) {}
};

class Amazon : public ShoppingService {
public:
    Amazon(double price,
           double shipping,
           double discount)
        : ShoppingService(price,
                          shipping,
                          discount) {}

    double calculateCost() override {
        return (productPrice * (1 - discountPercent / 100.0))
               + shippingCharge;
    }

    string getName() override {
        return "Amazon";
    }

    void displayDetails() override {
        cout << "Amazon Product | Price: ₹"
             << productPrice
             << " | Discount: "
             << discountPercent << "%\n";
    }
};

class Flipkart : public ShoppingService {
public:
    Flipkart(double price,
             double shipping,
             double discount)
        : ShoppingService(price,
                          shipping,
                          discount) {}

    double calculateCost() override {
        return (productPrice * (1 - discountPercent / 100.0))
               + shippingCharge;
    }

    string getName() override {
        return "Flipkart";
    }

    void displayDetails() override {
        cout << "Flipkart Product | Price: ₹"
             << productPrice
             << " | Discount: "
             << discountPercent << "%\n";
    }
};

// Fare Tracker Engine
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

        cout << "SMART FARE TRACKER\n";

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

        cout << "Recommended Platform: "
             << bestService << "\n";

        cout << "Estimated Cost: ₹"
             << minimumCost << "\n";
    }
};

// Main Function

int main() {

    FareTracker tracker;

    // Ride Sharing
    tracker.addService(
        make_shared<Uber>(10, 1.2));

    tracker.addService(
        make_shared<Ola>(10, 1.2));

    // Food Delivery
    tracker.addService(
        make_shared<Swiggy>(300, 4));

    tracker.addService(
        make_shared<Zomato>(300, 4));

    // Shopping
    tracker.addService(
        make_shared<Amazon>(2000, 50, 10));

    tracker.addService(
        make_shared<Flipkart>(2000, 30, 8));

    tracker.compareServices();

    return 0;
}
