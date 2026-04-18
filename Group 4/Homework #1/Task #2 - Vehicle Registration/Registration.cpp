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
