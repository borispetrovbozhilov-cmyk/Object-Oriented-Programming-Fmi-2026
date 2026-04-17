//
// Created by Boris Bozhilov on 4/13/2026.
//

#include "Utils.h"

#include <cstring>

void Utils::copyString(const char* source, char*& destination) {

    if (source == nullptr) return;
    if (source[0] == '\0') return;

    delete[] destination;

    unsigned int sourceLength = strlen(source);

    destination = new char[sourceLength + 1];

    strncpy(destination, source, sourceLength);

    destination[sourceLength] = '\0';
}

void Utils::freeString(char*& source) {

    delete[] source;
    source = nullptr;
}

void Utils::moveString(char*& source, char*& destination) noexcept {

    destination = source;
    source = nullptr;
}