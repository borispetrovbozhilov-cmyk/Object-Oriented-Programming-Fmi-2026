//
// Created by Boris Bozhilov on 4/18/2026.
//

#include "Registration.h"

#include <cstring>

// utility functions
bool Registration::isLetter(const char c) {

    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Registration::isDigit(const char c) {

    return c >= '0' && c <= '9';
}

bool Registration::checkRegistrationValidity(const char* registration) {

    const unsigned int registrationLength = strlen(registration);

    // size checks
    if (registrationLength > MAX_LENGTH_OF_REGISTRATION) return false;
    if (registrationLength < MIN_LENGTH_OF_REGISTRATION) return false;

    // first part check
    if (registrationLength == MAX_LENGTH_OF_REGISTRATION && !isLetter(registration[0])) return false;
    if (!isLetter(registration[1])) return false;

    // second part check
    if (!isDigit(registration[2])) return false;
    if (!isDigit(registration[3])) return false;
    if (!isDigit(registration[4])) return false;
    if (!isDigit(registration[5])) return false;

    // third part check
    if (!isLetter(registration[6])) return false;
    if (!isLetter(registration[7])) return false;

    return true;
}

bool Registration::isValid() const {

    if (registration == nullptr) return false;
    return checkRegistrationValidity(registration);
}

// rule of 5
Registration::Registration(const char *registration) {

    if (!checkRegistrationValidity(registration)) return;

    const unsigned int registrationLength = strlen(registration);

    this->registration = new char[registrationLength];

    strncpy(this->registration, registration, registrationLength);
}

Registration::Registration(const Registration &other) {

    if (!other.isValid()) return;


}
