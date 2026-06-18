SMART FARE TRACKER 
This project compares fare data from various service platforms such as Ola, Uber, Swiggy, and Zomato, and recommends the most economical and time-efficient option based on user preferences (like lowest price, shortest ETA, or distance).

Features
Real-time fare comparison across multiple platforms
Best Option Selector based on:
    Lowest Fare
    Fastest Delivery/Arrival Time
    Distance efficiency
Dynamic dashboards for fare trends
Easy to customize and extend to more platforms (Rapido, Dunzo, etc.)

Sample Data Fields Used
Field	Description
Timestamp	Date and time of fare observation
Platform	Name of the app (Uber, Ola, Swiggy...)
Fare (₹)	Total fare at the time
Distance (km)	Estimated distance of trip
Estimated Time (min)	ETA or delivery time

How it Works
Reads fare data from a CSV file.
Filters entries by time or service type (taxi/food).
Compares all platforms available for the same time window.
Displays the best fare option based on user preference:
      Price
      Time
      Distance

Example Output
Best Option at 10:00 AM for Taxi:
Uber - ₹145, ETA: 14 min

Best Option at 10:00 AM for Food Delivery:
Swiggy - ₹70, ETA: 25 min

Technologies Used
C++ for core logic and file parsing








