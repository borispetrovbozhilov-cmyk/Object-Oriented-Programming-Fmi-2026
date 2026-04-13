#include <iostream>

#include "Employee.h"

int main() {

    Employee employee1 = Employee("Sarah", "HR", 2000.50);

    std::cout << employee1 << std::endl;
    std::cout << Employee();

    return 0;
}
