#include "Functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    Base* ptr = generate();

    std::cout << "Identifying by pointer: ";
    identify(ptr);

    std::cout << "Identifying by reference: ";
    identify(*ptr);

    delete ptr;

    return 0;
}
