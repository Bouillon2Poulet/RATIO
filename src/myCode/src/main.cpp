#include <iostream>

#include "Rational.hpp"
#include "internal.hpp"


int main(int argc, char **argv) {

    std::cout<<Rational::floatToRational(1.5,10)<<std::endl;
    std::cout<<Rational::floatToRational(2.,10)<<std::endl;
    std::cout<<Rational::floatToRational(0.3333333,100)<<std::endl;
    std::cout<<Rational::floatToRational(-0.666666666,10)<<std::endl;
    std::cout<<"!!!"<<Rational::floatToRational(-10.459,10)<<std::endl;

    return 0;
}
