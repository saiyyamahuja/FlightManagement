# Airline Ticket Booking System

## Overview
This C program implements a simple airline ticket booking system using a linked list. It allows users to book flights, check ticket prices, view booking details, confirm payments, and cancel bookings.

## Features
- **Flight Management:** Stores flight details (serial number, code, destination, and price) in a linked list.
- **Booking System:** Allows users to book flights based on available destinations.
- **Ticket Price Inquiry:** Retrieves and displays ticket prices, including tax calculations.
- **View Booking Details:** Displays passenger details and flight information.
- **Payment Confirmation:** Ensures payment is made correctly before confirming the booking.
- **Cancellation:** Cancels a booking and invalidates the ticket code.

## How It Works
### 1. Flight Storage
Flights are stored as a linked list using the `struct Flight`. New flights are added dynamically.

### 2. Booking Process
- The user enters personal details (name, age, gender, travel date, and location).
- The destination is selected, and the system assigns a flight code.
- If a valid destination is provided, a confirmation message with the booking code is displayed.

### 3. Checking Ticket Prices
- The user enters their booking code.
- The system retrieves the ticket price and calculates the total cost (including a 13% tax).

### 4. Viewing Booking Details
- Displays all booking details, including the destination, passenger information, and price.

### 5. Payment Process
- The user enters the exact payment amount.
- If the correct amount is paid, the booking is confirmed; otherwise, it is canceled.

### 6. Cancellation Process
- If the payment has been made, the user can enter their booking code to cancel.
- The system resets the ticket code and invalidates the booking.

## Usage Instructions
1. Compile the program using:
   ```sh
   gcc flight_booking.c -o flight_booking
   ```
2. Run the executable:
   ```sh
   ./flight_booking
   ```
3. Follow the menu options to book, check prices, view details, confirm payment, or cancel bookings.

## Limitations
- Currently supports only predefined destinations.
- Limited flight database, which can be expanded dynamically.
- Does not save bookings after the program terminates.

## Future Improvements
- Implement a file system to save and load bookings.
- Add more destinations dynamically.
- Enhance user input validation.

## Author
Saiyyam Ahuja

