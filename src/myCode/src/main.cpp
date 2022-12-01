#include <iostream>

#include "Rational.hpp"
#include "internal.hpp"


int main(int argc, char **argv) {

    // Rational r(2,3);
    // Rational d(-4,10);

    // std::cout << "r.n : " << r.n() << std::endl;
    // std::cout << "d.n : " << d.n() << std::endl;
    // d=d+r;
    // std::cout << "d.n : " << d.n() << "d.d : " << d.d() << std::endl;
    std::cout<<Rational::floatToRational(1.5,10)<<std::endl;
    std::cout<<Rational::floatToRational(2.,10)<<std::endl;
    std::cout<<Rational::floatToRational(0.3333333,100)<<std::endl;
    std::cout<<Rational::floatToRational(-0.666666666,10)<<std::endl;
    std::cout<<"!!!"<<Rational::floatToRational(-10.459,10)<<std::endl;

    return 0;
}
