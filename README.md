# Hotel Management System (C++)

A console-based Hotel Management System built in C++ for B.Tech CSE Semester II (Case Study 107).

The project demonstrates core OOP and programming fundamentals using a practical menu-driven application.

## Features

- View all rooms with current status (Available or Booked)
- Book a room (check-in) with customer name and stay duration
- Check out a customer and generate a formatted bill
- Validate common user input cases:
	- Non-existent room number
	- Attempt to book an already occupied room
	- Invalid stay duration
	- Attempt to check out an already vacant room
- Preloaded room data to simulate a real hotel state

## Room Inventory

Total rooms: `10`

- Single: `101-103` at `Rs. 1000/day`
- Double: `201-203` at `Rs. 2000/day`
- Deluxe: `301-304` at `Rs. 5000/day`

### Pre-booked at Startup

- Room 103: Priya Patel (2 days)
- Room 202: Rohan Mehta (1 day)
- Room 303: Anjali Singh (3 days)

## Tech Stack

- Language: C++
- Libraries used: Standard Library (`iostream`, `string`)
- Programming concepts used:
	- Classes and objects
	- Encapsulation (private members + getters)
	- Constructors
	- Array of objects
	- Functions and switch-case
	- Looping (`do-while`, `for`)
	- Basic input validation

## Project Structure

```
cpp-hotel-mgmt/
├── main.cpp     # Source code
├── main         # Compiled binary (if present)
└── README.md
```

## Build and Run

### Prerequisites

- A C++ compiler (recommended: `g++`)

### Compile

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
```

### Run

```bash
./main
```

## Menu Options

1. View All Rooms
2. Book Room (Check In)
3. Check Out
4. Exit

## Billing Logic

Checkout bill is calculated as:

`Total Bill = Daily Rate x Number of Days Stayed`

Where:

- Single rate: `Rs. 1000/day`
- Double rate: `Rs. 2000/day`
- Deluxe rate: `Rs. 5000/day`

## Sample Workflow

1. Start the program.
2. Select option `1` to view room status.
3. Select option `2` to book an available room.
4. Enter room number, customer name, and number of days.
5. Select option `3` to check out and view the generated bill.
6. Select option `4` to exit.

## Notes

- This is a terminal-based educational project.
- Data is stored in memory only during runtime.
- On restarting the application, room data resets to initial predefined values.

## Author

Developed as part of B.Tech CSE (2025-29), Semester II case study work by Neel Prabir Singh.
