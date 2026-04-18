//
// Created by Boris Bozhilov on 4/18/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_REGISTRATION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_REGISTRATION_H
#include <compare>
#include <iosfwd>


class Registration {

private:

    static constexpr unsigned int MAX_LENGTH_OF_REGISTRATION = 8;

    char* registration = nullptr;

    // utility functions
    static bool isLetter(const char c);
    static bool isDigit(const char c);

public:

    // utility functions
    bool isValid() const;

    // rule of 5
    Registration() = delete;
    Registration(char* registration);

    Registration(const Registration& other);
    Registration& operator=(const Registration& other);

    Registration(Registration&& other) noexcept;
    Registration& operator=(Registration&& other) noexcept;

    ~Registration();

    // methods
    char* getRegistrationAsString() const;

    // operators
    bool operator==(const Registration& other) const;
    std::strong_ordering operator<=>(const Registration& other) const;
    friend std::ostream& operator<<(std::ostream& output, const Registration& registration);
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_REGISTRATION_H
