#  Smart Fare Tracker

Smart Fare Tracker compares fare data from multiple service platforms such as **Ola, Uber, Swiggy, and Zomato** and recommends the most economical and time-efficient option based on user preferences like **lowest price, shortest ETA, or distance**.

---

##  Features

- Real-time fare comparison across multiple platforms
- Best Option Selector based on:
  -  Lowest Fare
  -  Fastest Delivery/Arrival Time
  -  Distance Efficiency
- Dynamic dashboards for fare trends
- Easy to customize and extend to additional platforms such as Rapido and Dunzo

---

##  Sample Data Fields

| Field | Description |
|---------|-------------|
| Timestamp | Date and time of fare observation |
| Platform | Name of the platform (Uber, Ola, Swiggy, Zomato, etc.) |
| Fare (₹) | Total fare at the time |
| Distance (km) | Estimated trip/delivery distance |
| Estimated Time (min) | ETA or delivery time |

---

##  How It Works

1. Reads fare data from a CSV file.
2. Filters entries by time or service type (Taxi/Food Delivery).
3. Compares fares across all available platforms within the selected time window.
4. Recommends the best option based on the user's preference:
   - Price
   - Time
   - Distance

---

##  Example Output

### Taxi Service

```text
Best Option at 10:00 AM:
Uber - ₹145, ETA: 14 min








