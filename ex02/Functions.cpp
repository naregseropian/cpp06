#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
    int r = rand() % 3;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a; // Suppress unused variable warning
    }
    catch (...) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)b;
        }
        catch (...) {
            try {
                C& c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void)c;
            }
            catch (...) {
                std::cout << "Unknown Type" << std::endl;
            }
        }
    }
}
