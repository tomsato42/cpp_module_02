#include "Fixed.h"

#include <iostream>

static void PrintLog(const std::string &message) {
    std::cout << message << std::endl;
}

Fixed::Fixed() {
    data_ = 0;
    PrintLog("Default constructor called");
}

Fixed::Fixed(int const val) {
    data_ = val << fractionalBits_;
    PrintLog("Int constructor called");
}

Fixed::Fixed(float const val) {
    data_ = static_cast<int>(val * (1 << fractionalBits_));
    PrintLog("Float constructor called");
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
    return data_;
}

void Fixed::setRawBits(int const raw) {
    data_ = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(data_) / (1 << fractionalBits_);
}

int Fixed::toInt() const {
    return data_ >> fractionalBits_;
}

void Fixed::copyFrom(const Fixed &other) {
    data_ = other.getRawBits();
}

void Fixed::cleanUp() {
    data_ = 0;
}

std::ostream & operator<<(std::ostream &ostream, const Fixed &fixed) {
    return ostream << fixed.toFloat();
}
