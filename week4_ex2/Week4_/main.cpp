#include <iostream>
#include "math.h"

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << add(a, b, c) << std::endl;

    double d, e;
    std::cin >> d >> e;
    std::cout << add(d, e) << std::endl;

    int f, g;
	std::cin >> f >> g;
    std::cout << multiply(f, g) << std::endl;
	return 0;
}