#include <iostream>

#include "Rational.hpp"
#include "internal.hpp"
#include <vector>

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
    std::cout<<"Without Rational class, u(100) = "<<uF<<std::endl;

    float a = 5.5;
    Rational<int> b = Rational<int>::toRational(a,10);
    std::cout<<"b = "<<b<<std::endl;

    // std::vector<int> my_vector{1,2,2};
    // Rational<int> c = Rational<int>::toRational(my_vector,10);
    // std::cout<<"c = "<<c<<std::endl;

    return 0;
}
