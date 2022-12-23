#include <iostream>

#include "Rational.hpp"
#include "internal.hpp"
#include <string>
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

void chapter1();
void chapter2();
void chapter3();
void chapter4();

int main(/*int argc, char **argv*/) {
    int nb_iter = 10;
    Rational<int> uR=uRational(nb_iter);
    float uF=uFloat(nb_iter);
    std::cout<<"Using Rational class, u(100) = "<<uR<<" = "<<uR.toFloat()<<std::endl;
    std::cout<<"Without Rational class, u(100) = "<<uF<<std::endl;

    float a = 5.5;
    Rational<int> b = Rational<int>::toRational(a,10);
    std::cout<<"b = "<<b<<std::endl;

    Rational<int> r1 = Rational<int>(5,1);
    Rational<int> r2 = Rational<int>(4,1);
    Rational<int> r3 = Rational<int>(10,3);
    Rational<int> r4 = Rational<int>(-4,2);

    //std::cout<<Rational<int>::min(r1,r2,r3,r4)<<std::endl;
    std::cout<<Rational<int>::max(r1,r2,r3,r4)<<std::endl;

    system("clear");
    std::cout<<"Bienvenue dans la demo de la librairie Rational !"<<std::endl;
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<"Appuyez sur une touche pour continuer"<<std::endl;
    char c ;
    std::cin>>c;
    system("clear");

    bool inMenu = 1;
    
    std::cout<<"Au fil de cette demo, nous allons vous presenter les fonctionnalites de la librairie!"<<std::endl<<std::endl;
    std::cout<<"Sommaire :"<<std::endl;
    std::cout<<"1 - Classe Rational"<<std::endl;
    std::cout<<"2 - Constructeurs"<<std::endl;
    std::cout<<"3 - Methodes"<<std::endl;
    std::cout<<"4 - Pour aller + loin"<<std::endl;
    std::cout<<"\n\nVeuillez selectionner un chapitre"<<std::endl;
    std::cin>>c;
    std::string s = "1234";

    while (s.find(c)==std::string::npos){
        std::cout<<"!!!";
        std::cin>>c;
    }
    switch (c){
        case '1': std::cout<<"!!";
                chapter1();
                break;
        case '2': chapter2();
                break;
        case '3': chapter3();
                break;
        case '4': chapter4();
                break;
    }

    return 0;
}

void chapter1(){
    system("clear");
    std::cout<<"La classe Rational se compose de deux arguments :"<<std::endl;
    std::cout<<"    _n : le numerateur"<<std::endl;
    std::cout<<"    _d : le denominateur, il ne peut pas etre negatif"<<std::endl<<std::endl;
    std::cout<<"La classe est un template, elle peut donc prendre differents types d'integrals en entree"<<std::endl;
    std::cout<<"Liste des types acceptes :"<<std::endl;
    std::cout<<"   short\n   int\n   long\n   long long\n"<<std::endl<<std::endl;
    std::cout<<"D'autres types sont egalement acceptes mais leur utilisation est deconseillee :"<<std::endl<<std::endl;
    std::cout<<"   bool\n   char\n   char8_t\n   char16_t\n   char32_t\n   wchar_t\n"<<std::endl<<std::endl;

    return;
}

void chapter2(){
    return;
}

void chapter3(){
    return;
}

void chapter4(){
    return;
}