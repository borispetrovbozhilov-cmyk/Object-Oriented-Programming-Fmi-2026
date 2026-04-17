//
// Created by Boris Bozhilov on 4/13/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_UTILS_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_UTILS_H
#include "Employee.h"

namespace Utils {

    constexpr double EPSILON = 0.01;

    enum class ErrorCode {
        OK,
        NotFound,
        Duplicate,
        InvalidInput,
        Full
    };

    void copyString(const char* source, char*& destination);
    void freeString(char*& source);
    void moveString(char*& source, char*& destination) noexcept;

    void copyArrayOfEmployees(const Employee* source, const unsigned int sourceSize, Employee*& destination);
    void freeArrayOfEmployees(Employee*& source);
    void moveArrayOfEmployees(Employee*& source, Employee*& destination) noexcept;
}


#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_UTILS_H
