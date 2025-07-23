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
