#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    int id;
    std::string firstName;
    std::string lastName;
    double payRate;
    double balance;
    bool employed;

public:
    Employee(int id, std::string firstName, std::string lastName);
    void giveRaise(int percentage);
    void fire();
    bool isEmployed() const;
    void pay();
    void setPayRate(double rate);
    void addToBalance(double amount);
    std::string getName() const;
    int getID() const;
    double getPayRate() const;
    double getBalance() const;
};

#endif