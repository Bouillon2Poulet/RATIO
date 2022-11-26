#include <iostream>

#include "Rational.hpp"


int main(int argc, char **argv) {

    Rational r(2,3);
    Rational d(-4,10);

    std::cout << "r.n : " << r.n() << std::endl;
    std::cout << "d.n : " << d.n() << std::endl;
    d=d+r;
    std::cout << "d.n : " << d.n() << "d.d : " << d.d() << std::endl;

    return 0;
}
