//
// Created by Boris Bozhilov on 4/6/2026.
//

#include "Image.h"

#include <fstream>
#include <iostream>


// utility functions
int Image::getSizeOfData() const{

    return width * height * COUNT_OF_CHANNELS_RGB;
}

void Image::setToInvalidState() {

    pType = 0;
    width = -1;
    height = -1;
    maxVal = 0;
    data = nullptr;
}

void Image::copyDataFrom(const Image& other) const {

    const int dataSize = other.getSizeOfData();

    // perhaps strncpy() can be used, but I find this more intuitive
    for (int i = 0; i < dataSize; i++) {

        data[i] = other.data[i];
    }
}

// rule of 5
Image::Image() = default;

Image::Image(const char *fileName) {
    std::ifstream inputFile(fileName, std::ios::binary);

    if (!inputFile.is_open()){
        *this = Image();
        return;
    }

    char imageType[2] = {0};
    int tempMaxVal = -1;

    inputFile >> imageType[0] >> imageType[1];
    inputFile >> width;
    inputFile >> height;
    inputFile >> tempMaxVal;

    maxVal = (char)tempMaxVal;

    if (imageType[0] != 'P') {
        *this = Image();
        return;
    }

    this->pType = imageType[1] - '0';

    inputFile.ignore();

    const int dataSize = this->getSizeOfData();

    // NOTE this is the only way I can think of, avoiding using reinterpret cast
    // char* tempSignedCharData = new char[dataSize];
    //
    // inputFile.read(tempSignedCharData, dataSize);
    //
    // data = (unsigned char*)tempSignedCharData;

    data = new unsigned char[dataSize];
    inputFile.read(reinterpret_cast<char*>(data), dataSize);

    // final check if the object is valid
    if (!*this) {
        *this = Image();
        return;
    }

    inputFile.close();
}

Image::Image(const Image &other) : pType(other.pType), width(other.width), height(other.height), maxVal(other.maxVal){

    if (other.data == nullptr) {
        data = nullptr;
        return;
    }

    delete[] data;

    data = new unsigned char[other.getSizeOfData()];

    copyDataFrom(other);
}

Image &Image::operator=(const Image &other) {

    if (this == &other) return *this;

    if (!other) return *this;

    pType = other.pType;
    width = other.width;
    height = other.height;
    maxVal = other.maxVal;

    copyDataFrom(other);

    return *this;
}

Image::Image(Image &&other) noexcept : pType(other.pType), width(other.width),
height(other.height), maxVal(other.maxVal), data(other.data){

    other.setToInvalidState();
}

Image &Image::operator=(Image &&other) noexcept {

    if (this == &other) return *this;

    if (!other) return *this;

    // freeing our data
    delete[] data;

    // stealing other's data
    pType = other.pType;
    width = other.width;
    height = other.height;
    maxVal = other.maxVal;
    data = other.data;

    // leaving other in a correct "invalid" state
    other.setToInvalidState();

    return *this;
}

Image::~Image() {

    delete[] data;
    this->setToInvalidState();
}

// operators
Image::operator bool() const {

    if (data == nullptr) return false;

    // NOTE we are going to set it to work with only ppm and pgm that are binary, for now
    if (pType != 5 && pType != 6) return false;
    if (width <= 0) return false;
    if (height <= 0) return false;

    // NOTE we are going to accept only 255 as a maxval value, for now
    if (maxVal != 255) return false;

    return true;
}

// creating the image
void Image::createImage(const char* fileName) const {

    std::ofstream outputImage(fileName, std::ios::binary);

    outputImage << "P" << 0 + pType << std::endl;
    outputImage << width << " " << height << std::endl;
    outputImage << 0 + maxVal << std::endl;

    outputImage.write(reinterpret_cast<char*>(data), getSizeOfData());

    outputImage.close();
}
