#include "Fixed.h"

#include <iostream>

static void PrintLog(const std::string &message) {
    std::cout << message << std::endl;
}

Fixed::Fixed() {
    data_ = 0;
    PrintLog("Default constructor called");
}

Fixed::~Fixed() {
    cleanUp();
    PrintLog("Destructor called");
}

Fixed::Fixed(const Fixed &other) {
    copyFrom(other);
    PrintLog("Copy constructor called");
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        cleanUp();
        copyFrom(other);
    }
    PrintLog("Copy assignment operator called");
    return *this;
}

int Fixed::getRawBits() const {
    PrintLog("getRawBits member function called");
    return data_;
}

void Fixed::setRawBits(int const raw) {
    PrintLog("setRawBits member function called");
    data_ = raw;
}

void Fixed::copyFrom(const Fixed &other) {
    data_ = other.getRawBits();
}

void Fixed::cleanUp() {
    data_ = 0;
}
