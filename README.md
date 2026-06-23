# Smart Fare Tracker

Smart Fare Tracker is a C++-based multi-platform comparison and recommendation system that helps users identify the most cost-effective option across ride-hailing, food-delivery, and shopping platforms.

The application leverages Object-Oriented Programming (OOP) principles to model different service providers and generate intelligent recommendations based on cost, ETA, distance, and discounts.

Supported Platforms:

* Ride-Hailing Services: Uber, Ola
* Food Delivery Services: Swiggy, Zomato
* Shopping Platforms: Amazon, Flipkart, Myntra

---

## Features

* Compare ride fares across Uber and Ola
* Compare delivery costs across Swiggy and Zomato
* Compare product prices across Amazon, Flipkart, and Myntra
* Intelligent recommendation engine
* ETA-based service comparison
* Distance-aware cost evaluation
* Discount-aware shopping recommendations
* Fully object-oriented architecture
* Easy integration of new platforms such as Rapido, Blinkit, Dunzo, Zepto, and Amazon Fresh

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
├── FoodDeliveryService
│     ├── Swiggy
│     └── Zomato
│
└── ShoppingService
      ├── Amazon
      ├── Flipkart
      └── Myntra
```

### Polymorphism

Each platform implements its own pricing strategy through overridden `calculateCost()` methods.

### Encapsulation

Platform-specific data such as fare, distance, delivery charges, discounts, and ETA are maintained within their respective classes.

---

## How It Works

1. User provides ride, delivery, or shopping requirements.
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

## Shopping Comparison

Platforms:

* Amazon
* Flipkart
* Myntra

Comparison Parameters:

* Product Price
* Shipping Charges
* Discounts
* Delivery Time

Output:

* Best Shopping Option
* Final Cost
* Savings Compared to Alternatives

---

## Example Output

```text
          SMART FARE TRACKER
=========================================

Platform : Uber
Cost     : ₹204

Platform : Ola
Cost     : ₹180

Platform : Swiggy
Cost     : ₹332

Platform : Zomato
Cost     : ₹331

Platform : Amazon
Cost     : ₹1850

Platform : Flipkart
Cost     : ₹1870

Platform : Myntra
Cost     : ₹1720

-----------------------------------------
Recommended Platform
-----------------------------------------
Platform : Myntra
Cost     : ₹1720
-----------------------------------------
```

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* STL (Vectors, Smart Pointers)
* Dynamic Polymorphism
* Inheritance & Abstraction
* Encapsulation
* Recommendation Logic

---

## Future Enhancements

* Real-time API integration
* Dynamic surge pricing analysis
* Multi-factor recommendation scoring
* Historical fare and price trend tracking
* GUI/Web dashboard
* Personalized user preferences
* Machine learning-based recommendation engine

---

## Learning Outcomes

* Applied core OOP principles in a real-world use case
* Designed extensible software architecture
* Implemented recommendation and comparison logic
* Strengthened C++ design and problem-solving skills
* Utilized STL containers and smart pointers for scalable software development




