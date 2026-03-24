# Hospital-Management-System-
## 1. Introduction
The Hospital Management System is a software application developed using C++ to efficiently manage hospital operations such as patient records, appointments, and treatment details. In traditional systems, managing patient data manually can be time-consuming and error-prone. This system aims to digitize and simplify hospital processes.
The project uses basic data structures and object-oriented programming concepts of C++ like classes, objects, and file handling. It helps hospital staff to store, retrieve, and manage patient information quickly and accurately.

## 2. Objectives
•	To develop a computerized system for managing hospital data 
•	To store patient details such as name, ID, disease, and treatment 
•	To reduce manual work and improve efficiency 
•	To provide quick access to patient records 
•	To implement basic operations like add, search, delete, and display 
•	To apply C++ concepts like OOP and file handling in a real-world project 

## 3. System Design
The system uses:
- structure for storing patient data
- Function for each operations

## 4. Features
- Add patient
- Display patient
- Search patient
- Delete Patient

## 5. Implementation of Code
#include <iostream>
#include <fstream>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string disease;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Disease: ";
        cin >> disease;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nDisease: " << disease << endl;
    }
};

// Add Patient
void addPatient() {
    Patient p;
    ofstream file("patients.txt", ios::app); // append mode

    p.input();
    file << p.id << " " << p.name << " " << p.age << " " << p.disease << endl;

    file.close();
    cout << "Patient saved permanently!\n";
}

// Display All Patients
void displayPatients() {
    Patient p;
    ifstream file("patients.txt");

    while (file >> p.id >> p.name >> p.age >> p.disease) {
        p.display();
    }

    file.close();
}

// Search Patient
void searchPatient() {
    Patient p;
    int id, found = 0;

    cout << "Enter ID to search: ";
    cin >> id;

    ifstream file("patients.txt");

    while (file >> p.id >> p.name >> p.age >> p.disease) {
        if (p.id == id) {
            p.display();
            found = 1;
        }
    }

    if (!found)
        cout << "Patient not found!\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addPatient(); break;
        case 2: displayPatients(); break;
        case 3: searchPatient(); break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

## 6. Conclusion
The Hospital Management System developed in C++ successfully demonstrates how basic programming concepts can be applied to solve real-world problems. The system simplifies the process of managing patient data and reduces manual errors. It is user-friendly, efficient, and can be further enhanced by adding features like appointment scheduling, billing system, and graphical interface. This project helps in understanding file handling, classes, and data management in C++.
