# OOP_Week4
# 📌 Overview
transportstation.cpp – A simple Public Transportation Station Management System built with Object-Oriented Programming (OOP) in C++.

The system manages:

Vehicles (regular buses & express buses)

Passengers

Stations and scheduled routes

It demonstrates key OOP principles:

Classes & objects

Inheritance

Encapsulation

Polymorphism

# ⚙️ Build & Run Instructions
### On Linux / macOS / WSL:

```bash
g++ transportstation.cpp -o transport
./transport
```

### On Windows (MinGW g++):

```bash
g++ transportstation.cpp -o transport.exe
transport.exe
```
### 🤖 AI Disclosure
Author: Nguyen Minh Thanh – 24110132

I used ChatGPT to assist with:

Brainstorming ideas for class design and method structure

Improving code readability and encapsulation

Understanding how to override virtual functions effectively

All code has been written, tested, and personalized before submission. The AI was used ethically as a support tool, not for full code generation.

### 📝 Reflection
During this assignment, I gained a deeper understanding of Object-Oriented Programming (OOP) concepts, especially inheritance and polymorphism. Designing the Vehicle base class and extending it with the ExpressBus subclass helped me clearly see how inheritance allows us to avoid code duplication while adapting behavior for different types of vehicles.

Implementing virtual and overridden methods gave me practical experience in applying polymorphism to real-world scenarios. I also learned how to manage relationships between objects — such as linking passengers to vehicles and scheduling routes at stations — and how to structure interactive menus for user input.

One challenge I faced was ensuring that booking logic respected vehicle capacity and that station schedules didn’t exceed limits. While I implemented features like adding, canceling, and viewing bookings, I realized that deeper integration (e.g., syncing station schedules with vehicle status) would require more advanced design patterns. This is something I hope to improve in future versions.

Overall, this project was a valuable exercise in applying OOP principles to a realistic transportation scenario.
