#include "Fixed.h"

#include <iostream>

Fixed::Fixed() {
    data_ = 0;
}

Fixed::Fixed(int const val) {
    data_ = val << fractionalBits_;
}

Fixed::Fixed(float const val) {
    data_ = static_cast<int>(val * (1 << fractionalBits_));
}

Fixed::~Fixed() {
    cleanUp();
}

Fixed::Fixed(const Fixed &other) {
    copyFrom(other);
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        cleanUp();
        copyFrom(other);
    }
    return *this;
}

bool Fixed::operator==(const Fixed &other) const {
    return data_ == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return data_ != other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return data_ < other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return data_ <= other.getRawBits();
}

bool Fixed::operator>(const Fixed &other) const {
    return data_ > other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return data_ >= other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    long int result = static_cast<long int>(data_) * other.getRawBits();
    result >>= fractionalBits_;
    Fixed fixed;
    fixed.setRawBits(static_cast<int>(result));
    return fixed;
}

Fixed Fixed::operator/(const Fixed &other) const {
    const long int result = (static_cast<long int>(data_) << fractionalBits_) / other.getRawBits();
    Fixed fixed;
    fixed.setRawBits(static_cast<int>(result));
    return fixed;
}

Fixed &Fixed::operator++() {
    data_++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed copy(*this);
    data_++;
    return copy;
}

Fixed &Fixed::operator--() {
    data_--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed copy(*this);
    data_--;
    return copy;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a < b ? b : a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return a < b ? b : a;
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

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed) {
    return ostream << fixed.toFloat();
}
