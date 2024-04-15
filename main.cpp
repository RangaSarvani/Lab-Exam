#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"

using namespace std;

int main() {
    // Define vector to store employees 
    vector<Employee> employees;

    // Read from input file
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening files!" << endl;
        return 1; // Exit the program indicating error
    }

    string command;
    while (inputFile >> command) {
        if (command == "NEW") {
            int id;
            string firstName, lastName;
            inputFile >> id >> firstName >> lastName;
            employees.push_back(Employee(id, firstName, lastName));
        } else if (command == "RAISE") {
            int id, percentage;
            inputFile >> id >> percentage;
            for (auto &employee : employees) {
                if (employee.getID() == id) {
                    employee.giveRaise(percentage);
                    break;
                }
            }
        } else if (command == "PAY") {
            for (auto &employee : employees) {
                employee.pay();
            }
        } else if (command == "FIRE") {
            int id;
            inputFile >> id;
            for (auto it = employees.begin(); it != employees.end(); ) {
                if (it->getID() == id) {
                    it = employees.erase(it); // Erase and update iterator
                } else {
                    ++it; // Move to the next element
                }
            }
        }
    }

    // Write to output file
    for (const auto &employee : employees) {
        outputFile << "Name: " << employee.getName() << ", ID Number " << employee.getID() << endl;
        if (employee.isEmployed()) {
            outputFile << "Current pay rate: $" << employee.getPayRate() << endl;
        } else {
            outputFile << "Not employed with the company." << endl;
        }
        outputFile << "Pay earned to date: $" << employee.getBalance() << endl;
        outputFile << endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    return 0; // Exit the program indicating success
}