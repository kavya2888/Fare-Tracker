#  Smart Fare Tracker

Smart Fare Tracker is a C++-based fare comparison and recommendation system that helps users choose the most cost-effective service across ride-hailing and food-delivery platforms.

The application leverages Object-Oriented Programming (OOP) principles to model different service providers and generate intelligent recommendations based on cost, ETA, and distance.

Supported Platforms:

*  Ride-Hailing Services: Uber, Ola
*  Food Delivery Services: Swiggy, Zomato

---

## Features

* Compare ride fares across Uber and Ola
* Compare delivery costs across Swiggy and Zomato
* Intelligent recommendation engine
* ETA-based service comparison
* Distance-aware cost evaluation
* Fully object-oriented architecture
* Easy integration of new platforms such as Rapido, Blinkit, Dunzo, Amazon Fresh, etc.

---

## Object-Oriented Design

The system is built using the following OOP concepts:

### Abstraction

A common abstract base class (`ServicePlatform`) defines the interface for all services.

### Inheritance

Specialized classes inherit from common service categories:

```text
ServicePlatform
│
├── RideSharingService
│     ├── Uber
│     └── Ola
│
└── FoodDeliveryService
      ├── Swiggy
      └── Zomato
```

### Polymorphism

Each platform implements its own pricing strategy through overridden `calculateCost()` methods.

### Encapsulation

Platform-specific data such as fare, distance, delivery charges, and ETA are maintained within their respective classes.

---

## How It Works

1. User provides ride or delivery requirements.
2. The system gathers platform-specific pricing information.
3. Individual platform classes calculate estimated costs.
4. The recommendation engine compares all available options.
5. The most cost-effective platform is displayed along with estimated savings.

---

## Ride-Hailing Comparison

Platforms:

* Uber
* Ola

Comparison Parameters:

* Fare
* Distance
* Surge Multiplier
* ETA

Output:

* Best Ride Option
* Estimated Fare
* Savings Compared to Alternatives

---

## Food Delivery Comparison

Platforms:

* Swiggy
* Zomato

Comparison Parameters:

* Delivery Charges
* Delivery Distance
* ETA

Output:

* Best Food Delivery Option
* Estimated Cost
* Savings Compared to Alternatives

---

## Example Output

```text
=========================================
          SMART FARE TRACKER
=========================================

Enter Ride Distance : 8 km
Current Time        : 10:00 AM

----- Ride Sharing Comparison -----

Platform : Uber
Fare     : ₹185
ETA      : 12 min

Platform : Ola
Fare     : ₹172
ETA      : 14 min

-----------------------------------------
Best Ride Option
-----------------------------------------
Platform : Ola
Fare     : ₹172
ETA      : 14 min
Savings  : ₹13 compared to Uber

=========================================

Order Value   : ₹350
Delivery Area : IIT Kharagpur

----- Food Delivery Comparison -----

Platform : Swiggy
Cost     : ₹70
ETA      : 25 min
Distance : 4.5 km

Platform : Zomato
Cost     : ₹85
ETA      : 30 min
Distance : 4.5 km

-----------------------------------------
Best Food Delivery Option
-----------------------------------------
Platform : Swiggy
Cost     : ₹70
ETA      : 25 min
Distance : 4.5 km
Savings  : ₹15 compared to Zomato

=========================================
```

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* STL (Vectors, Smart Pointers)
* Dynamic Polymorphism
* Inheritance & Abstraction
* Recommendation Logic

---

## Future Enhancements

* Real-time API integration
* Dynamic surge pricing analysis
* Multi-factor recommendation scoring
* Historical fare trend tracking
* GUI/Web dashboard
* Personalized user preferences

---

## Learning Outcomes

* Applied core OOP principles in a real-world use case
* Designed extensible software architecture
* Implemented recommendation and comparison logic
* Strengthened C++ design and problem-solving skills









