//
// Created by Boris Bozhilov on 4/13/2026.
//

#include "Employee.h"

#include <cmath>
#include <cstring>
#include <iostream>

unsigned int Employee::countOfEmployees = 0;

// utility functions
void Employee::copyArrayOfEmployees(const Employee *source, const unsigned int sourceSize, Employee *&destination) {

    if(source == nullptr) return;

    delete[] destination;

    destination = new Employee[sourceSize];

    for (int i = 0; i < sourceSize; i++) {

        destination[i] = source[i];
    }
}

void Employee::freeArrayOfEmployees(Employee *&source) {

    delete[] source;
    source = nullptr;
}

void Employee::moveArrayOfEmployees(Employee *&source, Employee *&destination) noexcept {

    destination = source;
    source = nullptr;
}

bool Employee::isValid() const {

    if (id <= 0) return false;
    if (name == nullptr) return false;
    if (name[0] == '\0') return false;
    if (position == nullptr) return false;
    if (position[0] == '\0') return false;
    if (salary < 0) return false;

    return true;
}

unsigned int Employee::getID() const {

    return id;
}

// rule of 5
Employee::Employee() = default;

// not using the initializer list in order to check if the string values are valid first(avoiding zombie objects)
Employee::Employee(const char *name, const char *position, const double salary){

    if (strlen(name) >= MAX_STRING_CAPACITY - 1) return;
    if (strlen(position) >= MAX_STRING_CAPACITY - 1) return;

    // IDs start from 1 and are assigned based on the count of employees ever created
    this->id = ++countOfEmployees;
    this->salary = salary;

    Utils::copyString(name, this->name);
    Utils::copyString(position, this->position);
}

// name and position are set to nullptr in case other is invalid and other's strings are nullptr as well
// (which will cause the copyString() function to exit early and not initialize this's strings)
Employee::Employee(const Employee &other) : id(other.id), name(nullptr), position(nullptr), salary(other.salary){

    Utils::copyString(other.name, name);
    Utils::copyString(other.position, position);
}

Employee& Employee::operator=(const Employee &other) {

    if (this == &other) return *this;

    // if other isn't a valid Employee object then we don't copy its data and leave it as it is
    if (!other.isValid()) return *this;

    this->id = other.id;
    this->salary = other.salary;

    Utils::copyString(other.name, name);
    Utils::copyString(other.position, position);

    return *this;
}

Employee::Employee(Employee &&other) noexcept : id(other.id), salary(other.salary){

    Utils::moveString(other.name, name);
    Utils::moveString(other.position, position);

    other.id = 0;
    other.salary = -1;
}


Employee& Employee::operator=(Employee &&other) noexcept {

    if (this == &other) return *this;

    // if other isn't a valid Employee object then we don't steal its data and leave it as it is
    if (!other.isValid()) return *this;

    id = other.id;
    salary = other.salary;

    Utils::moveString(other.name, name);
    Utils::moveString(other.position, position);

    other.id = 0;
    other.salary = -1;

    return *this;
}

Employee::~Employee() {

    id = 0;
    salary = -1;
    Utils::freeString(name);
    Utils::freeString(position);
}

// methods
double Employee::getSalary() const {

    return salary;
}

Utils::ErrorCode Employee::updateSalary(const double amount) {

    if (amount <= 0) return Utils::ErrorCode::InvalidInput;

    salary = amount;

    return Utils::ErrorCode::OK;
}

unsigned int Employee::getCountOfEmployees() {

    return countOfEmployees;
}

unsigned int Employee::getLastEmployeeID() {

    return countOfEmployees;
}

// operators
Employee &Employee::operator++() {

    salary += salary * RATE_OF_SALARY_INCREASE;

    return *this;
}

Employee Employee::operator++(int) {

    Employee temp = Employee(*this);

    ++(*this);

    return temp;
}

bool Employee::operator==(const Employee &other) const {

    if (std::abs(salary - other.salary) < Utils::EPSILON) return id == other.id;
    return false;
}

std::strong_ordering Employee::operator<=>(const Employee &other) const {

    if (std::abs(salary - other.salary) < Utils::EPSILON) return id <=> other.id;
    if (salary < other.salary) return std::strong_ordering::less;
    return std::strong_ordering::greater;
}

std::ostream& operator<<(std::ostream& output, const Employee &employee) {

    output << employee.id << ": " << employee.name << ", " << employee.position << ", " << employee.salary << "$";

    return output;
}
