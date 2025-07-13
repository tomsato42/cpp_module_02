#ifndef FIXED_H
#define FIXED_H
#include <iosfwd>

class Fixed {
public:
    Fixed();

    Fixed(int const val);

    Fixed(float const val);

    ~Fixed();

    Fixed(const Fixed &);

    Fixed &operator=(const Fixed &);

    // The 6 comparison operators
    bool operator==(const Fixed &other) const;

    bool operator!=(const Fixed &other) const;

    bool operator<(const Fixed &other) const;

    bool operator<=(const Fixed &other) const;

    bool operator>(const Fixed &other) const;

    bool operator>=(const Fixed &other) const;

    // The 4 arithmetic operators
    Fixed operator+(const Fixed &other) const;

    Fixed operator-(const Fixed &other) const;

    Fixed operator*(const Fixed &other) const;

    Fixed operator/(const Fixed &other) const;

    // The increment and decrement operators
    Fixed &operator++();

    Fixed operator++(int);

    Fixed &operator--();

    Fixed operator--(int);

    // The min and max functions
    static Fixed &min(Fixed &a, Fixed &b);

    static const Fixed &min(const Fixed &a, const Fixed &b);

    static Fixed &max(Fixed &a, Fixed &b);

    static const Fixed &max(const Fixed &a, const Fixed &b);

    int getRawBits(void) const;

    void setRawBits(int const raw);

    float toFloat(void) const;

    int toInt(void) const;

private:
    int data_;
    static const int fractionalBits_ = 8;

    void copyFrom(const Fixed &);

    void cleanUp();
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed);

#endif // FIXED_H
