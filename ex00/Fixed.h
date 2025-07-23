#ifndef FIXED_H
#define FIXED_H

class Fixed {
public:
    Fixed();

    ~Fixed();

    Fixed(const Fixed &);

    Fixed &operator=(const Fixed &);

    int getRawBits(void) const;

    void setRawBits(int const raw);

private:
    int data_;
    static const int fractionalBits_ = 8;

    void copyFrom(const Fixed &);

    void cleanUp();
};

#endif // FIXED_H
