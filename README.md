#  Smart Fare Tracker

Smart Fare Tracker compares prices and estimated arrival/delivery times across multiple service platforms, helping users choose the most cost-effective and time-efficient option.

The system can support:

-  Ride-Hailing Services: Uber vs Ola
-  Food Delivery Services: Swiggy vs Zomato

---

##  Features

- Compare fares across Uber and Ola
- Compare delivery charges across Swiggy and Zomato
- Intelligent recommendation based on:
  -  Lowest Cost
  -  Fastest ETA
  -  Distance Efficiency
- CSV-based data analysis
- Simple and extensible architecture
- Easy integration of additional platforms such as Rapido, Dunzo, Blinkit, etc.

---

##  Sample Data Fields

| Field | Description |
|---------|-------------|
| Timestamp | Date and time of observation |
| Platform | Uber, Ola, Swiggy, or Zomato |
| Service Type | Taxi or Food Delivery |
| Cost (₹) | Fare or delivery charge |
| Distance (km) | Estimated travel/delivery distance |
| Estimated Time (min) | Expected arrival or delivery time |

---

##  How It Works

1. Reads service data from a CSV file.
2. Categorizes records by service type:
   - Taxi Services
   - Food Delivery Services
3. Compares available platforms within the same time window.
4. Recommends the best option based on user preference:
   - Lowest Cost
   - Fastest Service
   - Shortest Distance

---

## Ride-Hailing Comparison

Platforms:
- Uber
- Ola

The system compares:
- Fare
- ETA
- Distance


## Food Delivery Comparison

Platforms:
- Swiggy
- Zomato

The system compares:
- Delivery Charges
- Estimated Delivery Time
- Delivery Distance

### Example Output

SMART FARE TRACKER

Enter Ride Distance : 8 km
Current Time        : 10:00 AM

----- Ride Sharing Comparison -----

Platform : Uber
Fare     : ₹185
ETA      : 12 min

Platform : Ola
Fare     : ₹172
ETA      : 14 min

-----------------------------------
Best Ride Option
-----------------------------------
Platform : Ola
Fare     : ₹172
ETA      : 14 min
Savings  : ₹13 compared to Uber


=========================================

Order Value  : ₹350
Delivery Area: IIT Kharagpur

----- Food Delivery Comparison -----

Platform : Swiggy
Cost     : ₹70
ETA      : 25 min
Distance : 4.5 km

Platform : Zomato
Cost     : ₹85
ETA      : 30 min
Distance : 4.5 km

-----------------------------------
Best Food Delivery Option
-----------------------------------
Platform : Swiggy
Cost     : ₹70
ETA      : 25 min
Distance : 4.5 km
Savings  : ₹15 compared to Zomato

=========================================

##  Technologies Used

- C++
- File Handling
- CSV Parsing
- Data Structures & Algorithms
- Decision-Based Recommendation Logic

---

##  Future Enhancements

- Live API integration for real-time tracking
- Surge pricing analysis
- Historical trend visualization
- Personalized recommendation engine
- Web dashboard for interactive comparisons

---








