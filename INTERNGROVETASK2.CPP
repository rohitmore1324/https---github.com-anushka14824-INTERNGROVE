#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class
class Employee {
protected:
    string name;
    double salary;

public:
    Employee(string n, double s) : name(n), salary(s) {}

    virtual void displayInfo() const {
        cout << "Employee Name: " << name << "\nSalary: $" << salary << endl;
    }

    virtual ~Employee() {} // Virtual destructor
};

// Derived class: Manager
class Manager : public Employee {
public:
    Manager(string n, double s) : Employee(n, s) {}

    void displayInfo() const override {
        cout << "Manager Info: \n" << "Name: " << name << "\nSalary: $" << salary << endl;
    }
};

// Derived class: Developer
class Developer : public Employee {
public:
    Developer(string n, double s) : Employee(n, s) {}

    void displayInfo() const override {
        cout << "Developer Info: \n" << "Name: " << name << "\nSalary: $" << salary << endl;
    }
};

// Derived class: Intern
class Intern : public Employee {
public:
    Intern(string n, double s) : Employee(n, s) {}

    void displayInfo() const override {
        cout << "Intern Info: \n" << "Name: " << name << "\nSalary: $" << salary << endl;
    }
};

int main() {
    vector<Employee*> employees;

    // Creating different types of employees
    employees.push_back(new Manager("Alice", 80000));
    employees.push_back(new Developer("Bob", 60000));
    employees.push_back(new Intern("Charlie", 30000));

    // Displaying information for each employee
    cout << "Employee Information:\n";
    for (const auto& emp : employees) {
        emp->displayInfo();
        cout << "---------------------\n";
    }

    // Clean up memory
    for (auto emp : employees) {
        delete emp;
    }

    return 0;
}
