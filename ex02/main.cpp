#include "Fixed.h"

#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    // 元のテスト
    std::cout << "=== 元のテスト ===" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    // 追加テスト: 比較演算子
    std::cout << "\n=== 比較演算子テスト ===" << std::endl;
    Fixed c(1.5f);
    Fixed d(1.5f);
    Fixed e(2.5f);

    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != e: " << (c != e) << std::endl;
    std::cout << "c < e: " << (c < e) << std::endl;
    std::cout << "e > c: " << (e > c) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "e >= c: " << (e >= c) << std::endl;

    // 追加テスト: 算術演算子
    std::cout << "\n=== 算術演算子テスト ===" << std::endl;
    std::cout << "c + e = " << (c + e) << std::endl;
    std::cout << "e - c = " << (e - c) << std::endl;
    std::cout << "c * e = " << (c * e) << std::endl;
    std::cout << "e / c = " << (e / c) << std::endl;

    // 追加テスト: デクリメント
    std::cout << "\n=== デクリメントテスト ===" << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "--c: " << --c << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "c--: " << c-- << std::endl;
    std::cout << "c: " << c << std::endl;

    // 追加テスト: min関数
    std::cout << "\n=== min関数テスト ===" << std::endl;
    std::cout << "min(c, e): " << Fixed::min(c, e) << std::endl;

    return 0;
}
