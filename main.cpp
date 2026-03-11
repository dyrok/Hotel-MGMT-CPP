/*
 * Hotel Management System
 * B.Tech CSE 2025-29 | Semester II | Case Study 107
 *
 * Features:
 *   - View all rooms with availability status
 *   - Book a room (Check In) with customer name and days
 *   - Check Out a customer and display the final bill
 *   - Menu-driven interface using switch-case and do-while loop
 *
 * Room Types and Rates:
 *   Single  - Rs. 1000 per day
 *   Double  - Rs. 2000 per day
 *   Deluxe  - Rs. 5000 per day
 */

#include <iostream>
#include <string>
using namespace std;

// -----------------------------------------------
// Constants: total rooms and daily rates per type
// -----------------------------------------------
const int MAX_ROOMS   = 10;
const int SINGLE_RATE = 1000;   // Rs. per day for Single room
const int DOUBLE_RATE = 2000;   // Rs. per day for Double room
const int DELUXE_RATE = 5000;   // Rs. per day for Deluxe room


// ================================================
// CLASS: Room
// Represents a single hotel room with all details
// ================================================
class Room {
private:
    int    roomNumber;      // Unique room identifier (e.g., 101, 202, 301)
    string roomType;        // "Single", "Double", or "Deluxe"
    bool   isAvailable;     // true = can be booked | false = currently occupied
    string customerName;    // Name of the checked-in customer (empty if vacant)
    int    daysStayed;      // Number of nights the customer is staying

public:
    // -----------------------------------------------
    // Default Constructor
    // Called automatically when Room array is declared.
    // Sets all members to safe initial values.
    // -----------------------------------------------
    Room() {
        roomNumber   = 0;
        roomType     = "";
        isAvailable  = true;
        customerName = "";
        daysStayed   = 0;
    }

    // -----------------------------------------------
    // setRoom: assigns the room's identity details
    // Called once by initRooms() at program start
    // -----------------------------------------------
    void setRoom(int num, string type, bool available) {
        roomNumber  = num;
        roomType    = type;
        isAvailable = available;
    }

    // -----------------------------------------------
    // setCustomer: pre-fills customer data for rooms
    // that are already booked when the program starts
    // -----------------------------------------------
    void setCustomer(string name, int days) {
        customerName = name;
        daysStayed   = days;
    }

    // -----------------------------------------------
    // Getter functions — provide read-only access
    // to private data members from outside the class
    // -----------------------------------------------
    int    getRoomNumber()   { return roomNumber;   }
    string getRoomType()     { return roomType;     }
    bool   getIsAvailable()  { return isAvailable;  }
    string getCustomerName() { return customerName; }
    int    getDaysStayed()   { return daysStayed;   }

    // -----------------------------------------------
    // checkIn: assigns a customer to this room
    //   - stores name and number of days
    //   - marks the room as occupied (isAvailable = false)
    // -----------------------------------------------
    void checkIn(string name, int days) {
        customerName = name;
        daysStayed   = days;
        isAvailable  = false;   // room is now booked
    }

    // -----------------------------------------------
    // checkOut: releases the room after a customer leaves
    //   - clears customer info
    //   - marks the room as available again
    // -----------------------------------------------
    void checkOut() {
        customerName = "";
        daysStayed   = 0;
        isAvailable  = true;    // room is free for new booking
    }

    // -----------------------------------------------
    // calculateBill: returns total charge for the stay
    //   total = rate per day * number of days stayed
    // -----------------------------------------------
    int calculateBill() {
        int rate = 0;
        if      (roomType == "Single") rate = SINGLE_RATE;
        else if (roomType == "Double") rate = DOUBLE_RATE;
        else if (roomType == "Deluxe") rate = DELUXE_RATE;
        return rate * daysStayed;
    }
};


// ================================================
// FUNCTION: initRooms
// Sets up the hotel's room inventory at startup.
// 10 rooms total: 3 Single, 3 Double, 4 Deluxe
// 3 rooms are pre-booked to simulate a real hotel.
// ================================================
void initRooms(Room rooms[]) {
    // --- Single Rooms (101-103) ---
    rooms[0].setRoom(101, "Single", true);          // Available
    rooms[1].setRoom(102, "Single", true);          // Available
    rooms[2].setRoom(103, "Single", false);         // Pre-booked
    rooms[2].setCustomer("Priya Patel", 2);

    // --- Double Rooms (201-203) ---
    rooms[3].setRoom(201, "Double", true);          // Available
    rooms[4].setRoom(202, "Double", false);         // Pre-booked
    rooms[4].setCustomer("Rohan Mehta", 1);
    rooms[5].setRoom(203, "Double", true);          // Available

    // --- Deluxe Rooms (301-304) ---
    rooms[6].setRoom(301, "Deluxe", true);          // Available
    rooms[7].setRoom(302, "Deluxe", true);          // Available
    rooms[8].setRoom(303, "Deluxe", false);         // Pre-booked
    rooms[8].setCustomer("Anjali Singh", 3);
    rooms[9].setRoom(304, "Deluxe", true);          // Available
}


// ================================================
// FUNCTION: findRoom
// Searches for a room by its room number.
// Uses a linear scan through the array.
// Returns: index of the room if found, -1 if not found
// ================================================
int findRoom(Room rooms[], int size, int roomNum) {
    for (int i = 0; i < size; i++) {
        if (rooms[i].getRoomNumber() == roomNum) {
            return i;   // found at array index i
        }
    }
    return -1;  // no room with that number exists
}


// ================================================
// FUNCTION: showMenu
// Displays the main navigation menu
// ================================================
void showMenu() {
    cout << "\n====================================\n";
    cout << "     HOTEL MANAGEMENT SYSTEM\n";
    cout << "====================================\n";
    cout << "  1. View All Rooms\n";
    cout << "  2. Book Room (Check In)\n";
    cout << "  3. Check Out\n";
    cout << "  4. Exit\n";
    cout << "------------------------------------\n";
    cout << "Enter your choice: ";
}


// ================================================
// FUNCTION: viewRooms
// Displays all rooms in a formatted table showing
// room number, type, and current availability.
// ================================================
void viewRooms(Room rooms[], int size) {
    cout << "\n+-----------+----------+-------------+\n";
    cout << "| Room No.  |   Type   |   Status    |\n";
    cout << "+-----------+----------+-------------+\n";

    for (int i = 0; i < size; i++) {
        // Print room number (left-padded for alignment)
        cout << "| " << rooms[i].getRoomNumber() << "      | ";

        // Print room type (padded to 8 chars for alignment)
        string type = rooms[i].getRoomType();
        cout << type;
        if (type == "Single")      cout << "   | ";
        else if (type == "Double") cout << "   | ";
        else                       cout << "   | ";   // Deluxe

        // Print availability status
        if (rooms[i].getIsAvailable()) {
            cout << "Available   |\n";
        } else {
            cout << "Booked      |\n";
        }
    }

    cout << "+-----------+----------+-------------+\n";
}


// ================================================
// FUNCTION: displayBill
// Prints the formatted checkout receipt.
// Takes room by reference (&) to avoid copying the object
// — same pattern as: void performAction(BankAccount &account, ...)
// ================================================
void displayBill(Room &room) {
    // Get rate separately so we can display it line by line
    int rate = 0;
    if      (room.getRoomType() == "Single") rate = SINGLE_RATE;
    else if (room.getRoomType() == "Double") rate = DOUBLE_RATE;
    else if (room.getRoomType() == "Deluxe") rate = DELUXE_RATE;

    cout << "\n========== CHECKOUT BILL ===========\n";
    cout << "Customer Name  : " << room.getCustomerName()  << "\n";
    cout << "Room Number    : " << room.getRoomNumber()     << "\n";
    cout << "Room Type      : " << room.getRoomType()       << "\n";
    cout << "Days Stayed    : " << room.getDaysStayed()     << "\n";
    cout << "Rate per Day   : Rs. " << rate                 << "\n";
    cout << "------------------------------------\n";
    cout << "Total Amount   : Rs. " << room.calculateBill() << "\n";
    cout << "====================================\n";
    cout << "Thank you for staying with us!\n";
}


// ================================================
// FUNCTION: bookRoom
// Handles the complete check-in process:
//   1. Shows available rooms
//   2. Takes room number, customer name, and days
//   3. Validates input and books the room
// ================================================
void bookRoom(Room rooms[], int size) {
    int    roomNum;
    string name;
    int    days;

    // Step 1: Show only the available rooms to help user decide
    cout << "\n--- Currently Available Rooms ---\n";
    bool anyAvailable = false;
    for (int i = 0; i < size; i++) {
        if (rooms[i].getIsAvailable()) {
            cout << "  Room " << rooms[i].getRoomNumber()
                 << " (" << rooms[i].getRoomType() << ")"
                 << "  -  Rs. ";
            // Display daily rate alongside each room
            if (rooms[i].getRoomType() == "Single")      cout << SINGLE_RATE;
            else if (rooms[i].getRoomType() == "Double") cout << DOUBLE_RATE;
            else                                          cout << DELUXE_RATE;
            cout << "/day\n";
            anyAvailable = true;
        }
    }

    // Edge case: hotel is fully occupied
    if (!anyAvailable) {
        cout << "Sorry! All rooms are currently booked. Please try again later.\n";
        return;
    }

    // Step 2: Get room choice
    cout << "\nEnter Room Number to Book: ";
    cin >> roomNum;

    // Step 3: Check the room number exists in the system
    int idx = findRoom(rooms, size, roomNum);
    if (idx == -1) {
        cout << "Room " << roomNum << " does not exist! Please check the room number.\n";
        return;
    }

    // Step 4: Check the room is actually available
    if (!rooms[idx].getIsAvailable()) {
        cout << "Sorry! Room " << roomNum << " is already booked. Please choose another room.\n";
        return;
    }

    // Step 5: Get customer name
    // IMPORTANT: cin.ignore() discards the leftover '\n' character that stays
    // in the input buffer after pressing Enter for the room number.
    // Without this, getline() would instantly read an empty string
    // instead of waiting for the user to type the customer's name.
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, name);

    // Step 6: Get number of days
    cout << "Enter Number of Days: ";
    cin >> days;

    // Validate days is a positive number
    if (days <= 0) {
        cout << "Invalid number of days! Please enter at least 1.\n";
        return;
    }

    // Step 7: Perform the check-in
    rooms[idx].checkIn(name, days);

    // Confirmation message
    cout << "\nRoom Booked Successfully!\n";
    cout << "Room Number : " << rooms[idx].getRoomNumber() << "\n";
    cout << "Room Type   : " << rooms[idx].getRoomType()   << "\n";
    cout << "Customer    : " << name                        << "\n";
    cout << "Days        : " << days                        << "\n";
}


// ================================================
// FUNCTION: checkOutRoom
// Handles the complete check-out process:
//   1. Takes room number
//   2. Validates it is a booked room
//   3. Displays the bill
//   4. Releases the room
// ================================================
void checkOutRoom(Room rooms[], int size) {
    int roomNum;

    cout << "\nEnter Room Number for Check Out: ";
    cin >> roomNum;

    // Check the room number exists
    int idx = findRoom(rooms, size, roomNum);
    if (idx == -1) {
        cout << "Room " << roomNum << " does not exist! Please check the room number.\n";
        return;
    }

    // Check the room is currently occupied (not vacant)
    if (rooms[idx].getIsAvailable()) {
        cout << "Room " << roomNum << " is not currently occupied!\n";
        return;
    }

    // Display the final bill before releasing the room
    displayBill(rooms[idx]);

    // Release the room: clears customer data, marks as available
    rooms[idx].checkOut();

    cout << "\nRoom " << roomNum << " is now available for new bookings.\n";
}


// ================================================
// MAIN FUNCTION
// Entry point: initializes rooms, runs the menu loop
// ================================================
int main() {
    Room rooms[MAX_ROOMS]; // Array of 10 Room objects (default constructor called for each)
    initRooms(rooms);      // Populate with hotel room data

    int choice;

    cout << "\nWelcome to ABC Hotel Management System!\n";

    // do-while ensures the menu is shown at least once.
    // The loop continues until the user chooses option 4 (Exit).
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                viewRooms(rooms, MAX_ROOMS);
                break;
            case 2:
                bookRoom(rooms, MAX_ROOMS);
                break;
            case 3:
                checkOutRoom(rooms, MAX_ROOMS);
                break;
            case 4:
                cout << "\nThank you for using the Hotel Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}
