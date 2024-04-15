#include "Employee.h"

Employee::Employee(int id, std::string firstName, std::string lastName)
    : id(id), firstName(firstName), lastName(lastName), payRate(10.00), balance(0), employed(true) {}

void Employee::giveRaise(int percentage) {
    double raiseAmount = payRate * (percentage / 100.0);
    payRate += raiseAmount;
}

void Employee::fire() {
    employed = false;
    payRate = 0;
}

bool Employee::isEmployed() const {
    return employed;
}

void Employee::pay() {
    balance += payRate;
}

void Employee::setPayRate(double rate) {
    payRate = rate;
}

void Employee::addToBalance(double amount) {
    balance += amount;
}

std::string Employee::getName() const {
    return firstName + " " + lastName;
}

int Employee::getID() const {
    return id;
}

double Employee::getPayRate() const {
    return payRate;
}

double Employee::getBalance() const {
    return balance;
}
