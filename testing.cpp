#include <iostream>
#include <cstdint>

int main() {
    __int128_t a = 1000000000000000000LL;  // Đổi giá trị a, b, và c theo mong muốn
    __int128_t b = 2000000000000000000LL;
    __int128_t c = 1500000000000000000LL;

    if (a * b > c) {
        std::cout << "a * b > c" << std::endl;
    } else {
        std::cout << "a * b <= c" << std::endl;
    }

    return 0;
}
