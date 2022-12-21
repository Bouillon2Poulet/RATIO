#include <iostream>

#include "Rational.hpp"
#include "internal.hpp"

Rational<int> uRational(int nb_iter){
    Rational<int> u(1,3);
    for (int i=1; i<nb_iter; i++){
        //std::cout<<u<<std::endl;
        u=u*4.0 - 1;
    }
    return u;
}

float uFloat(int nb_iter){
    float u=1.0/3.0;
    for (int i=1; i<nb_iter; i++){
        //std::cout<<"u = "<<u<<std::endl;
        u=u*4 - 1;
    }
    return u;
}

int main(/*int argc, char **argv*/) {
    int nb_iter = 10;
    Rational<int> uR=uRational(nb_iter);
    float uF=uFloat(nb_iter);
    std::cout<<"Using Rational class, u(100) = "<<uR<<" = "<<uR.toFloat()<<std::endl;
    std::cout<<"Withou Rational class, u(100) = "<<uF<<std::endl;
   
    // std::cout<<Rational::floatToRational(1.5,10)<<std::endl;
    // std::cout<<Rational::floatToRational(2.,10)<<std::endl;
    // std::cout<<Rational::floatToRational(0.3333333,100)<<std::endl;
    // std::cout<<Rational::floatToRational(-0.666666666,10)<<std::endl;
    // std::cout<<"!!!"<<Rational::floatToRational(-10.459,10)<<std::endl;

    return 0;
}
