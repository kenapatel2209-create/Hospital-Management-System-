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