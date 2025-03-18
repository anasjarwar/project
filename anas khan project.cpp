#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct User {
    string username;
    string password;
};

struct Booking {
    string username;
    string destination;
    string transport;
    string hotel;
};

vector<User> users;
vector<Booking> bookings;
string destinations[] = {"Karachi", "Hyderabad", "Sakhar", "Jamshoro"};
int numDestinations = 4;

void clearScreen() {
    system("CLS");
}

void pauseScreen() {
    cout << "Press any key to continue...";
    cin.ignore(); cin.get();
}

void registerUser() {
    clearScreen();
    User user;
    cout << "\nEnter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;
    users.push_back(user);
    cout << "User registered successfully! ";
    pauseScreen();
}

bool loginUser(string &username) {
    clearScreen();
    string inputUser, inputPass;
    cout << "\nEnter username: ";
    cin >> inputUser;
    cout << "Enter password: ";
    cin >> inputPass;
    
    for (int i = 0; i < users.size(); i++) {
        if (users[i].username == inputUser && users[i].password == inputPass) {
            username = inputUser;
            cout << "\nLogin successful! Welcome, " << username << "! ";
            pauseScreen();
            return true;
        }
    }
    cout << "Invalid credentials! ";
    pauseScreen();
    return false;
}

void searchDestinations() {
    clearScreen();
    cout << "\nAvailable destinations:\n";
    for (int i = 0; i < numDestinations; i++) {
        cout << "- " << destinations[i] << endl;
    }
    pauseScreen();
}

void bookTrip(const string &username) {
    clearScreen();
    Booking booking;
    booking.username = username;
    cout << "\nEnter destination: ";
    cin >> booking.destination;
    cout << "Enter transport mode (Flight/Bus/Train): ";
    cin >> booking.transport;
    cout << "Enter hotel name: ";
    cin >> booking.hotel;
    bookings.push_back(booking);
    cout << "Booking successful for " << username << "! ";
    pauseScreen();
}

void cancelTrip(const string &username) {
    clearScreen();
    for (int i = 0; i < bookings.size(); i++) {
        if (bookings[i].username == username) {
            bookings.erase(bookings.begin() + i);
            cout << "\nYour booking has been cancelled successfully. ";
            pauseScreen();
            return;
        }
    }
    cout << "\nNo bookings found for cancellation. ";
    pauseScreen();
}

void viewBookings(const string &username) {
    clearScreen();
    cout << "\nYour Bookings:\n";
    bool found = false;
    for (int i = 0; i < bookings.size(); i++) {
        if (bookings[i].username == username) {
            cout << "Destination: " << bookings[i].destination << ", Transport: " << bookings[i].transport << ", Hotel: " << bookings[i].hotel << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No bookings found.";
    }
    pauseScreen();
}

int main() {
    int choice;
    string username;
    
    while (true) {
        clearScreen();
        if (username.empty()) {
            cout << "\n1. Register\n2. Login\n3. Exit\nEnter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    registerUser();
                    break;
                case 2:
                    if (!loginUser(username)) {
                        username = ""; 
                    }
                    break;
                case 3:
                    return 0;
                default:
                    cout << "Invalid choice! ";
                    pauseScreen();
            }
        } else {
            cout << "\n1. Search Destinations\n2. Book Trip\n3. Cancel Trip\n4. View Bookings\n5. Logout\nEnter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    searchDestinations();
                    break;
                case 2:
                    bookTrip(username);
                    break;
                case 3:
                    cancelTrip(username);
                    break;
                case 4:
                    viewBookings(username);
                    break;
                case 5:
                    username = "";
                    break;
                default:
                    cout << "Invalid choice! ";
                    pauseScreen();
            }
        }
    }
}
