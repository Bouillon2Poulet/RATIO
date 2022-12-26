#ifndef __DEMO__HPP
#define __DEMO__HPP

void demo();
void chapter1();
void chapter2();
void chapter3();
void chapter4();
void demoEnd();
void uRational(int nb_iter);
void uFloat(int nb_iter);

using namespace rational;

void demo(){
    system("clear");
    std::cout<<"Bienvenue dans la demo de la librairie Rational !"<<std::endl;
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<"Appuyez sur une touche pour continuer"<<std::endl;
    char c ;
    std::cin>>c;
    system("clear");
    
    std::cout<<"Au fil de cette demo, nous allons vous presenter les fonctionnalites de la librairie!"<<std::endl<<std::endl;
    std::cout<<"Sommaire :"<<std::endl;
    std::cout<<"1 - Classe Rational"<<std::endl;
    std::cout<<"2 - Constructeurs et operateurs"<<std::endl;
    std::cout<<"3 - Methodes"<<std::endl;
    std::cout<<"4 - Mauvaises pratiques"<<std::endl;
    std::cout<<"\n\nVeuillez selectionner un chapitre"<<std::endl;
    std::cin>>c;
    std::string s = "1234";

    while (s.find(c)==std::string::npos){
        std::cin>>c;
    }
    switch (c){
        case '1': chapter1();
        [[fallthrough]];
        case '2': chapter2();
        [[fallthrough]];
        case '3': chapter3();
        [[fallthrough]];
        case '4': chapter4();
    }
    demoEnd();
}

void chapter1(){
    system("clear");
    std::cout<<"Tout d'abord, pourquoi ?"<<std::endl<<std::endl;
    std::cout<<"La librairie Rational propose une alternative a la representation des reels par des nombres a virgule flottante"<<std::endl;
    std::cout<<"Elle permet de reduire les erreurs d'arrondis dus a leur stockage en memoire"<<std::endl;
    std::cout<<"Prenons l'exemple de la suite suivante :"<<std::endl;
    std::cout<<"    u0 = 1/3"<<std::endl;
    std::cout<<"    un+1 = 4un - 1"<<std::endl<<std::endl;
    std::cout<<"On constate qu'au bout de 4 iterations, la suite diverge en utilisant des nombres a virgule flottante :"<<std::endl<<std::endl;
    uFloat(10);
    std::cout<<"C'est a cause de ces fameux arrondis !"<<std::endl;
    std::cout<<"Regardons ce qu'il se passe en utilisant notre classe Rational :"<<std::endl;
    uRational(10);
    std::cout<<"Emouvant non ? :^)"<<std::endl;
    std::cout<<"\n\n\n"<<"Presser une touche -> Page suivante"<<std::endl;
    char a;
    std::cin>>a;
    
    system("clear");
    std::cout<<"La classe Rational se compose de deux arguments :"<<std::endl;
    std::cout<<"    _n : le numerateur"<<std::endl;
    std::cout<<"    _d : le denominateur, il ne peut pas etre negatif"<<std::endl<<std::endl;
    std::cout<<"La classe est un template, elle peut donc prendre differents types d'integrals en entree"<<std::endl;
    std::cout<<"Liste des types acceptes :"<<std::endl;
    std::cout<<"   short\n   int\n   long int\n   long long int\n"<<std::endl<<std::endl;
    std::cout<<"D'autres types sont egalement acceptes mais leur utilisation est deconseillee :"<<std::endl<<std::endl;
    std::cout<<"   bool\n   char\n   char8_t\n   char16_t\n   char32_t\n   wchar_t\n"<<std::endl<<std::endl;
    std::cout<<"\n\n\n"<<"Presser une touche -> Page suivante"<<std::endl;
    std::cin>>a;

    system("clear");
    std::cout<<"Nous avons fait le choix de passer la classe en template pour faciliter la representation des grands nombre"<<std::endl;
    std::cout<<"Neanmoins elle reste sujette a l'overflow, l'utilisateur doit alors choisir le bon type pour le template afin de ne pas depasser les valeurs max et min des parametres de la classe"<<std::endl;
    std::cout<<"\n\n"<<std::endl;
    std::cout<<"La classe comprend la notion d'infini :"<<std::endl;
    std::cout<<"    (+/-)1/0"<<std::endl;
    std::cout<<"\nAinsi, toute operation qui inclue l'infini resultera en l'infini (positif ou negatif)"<<std::endl;
    std::cout<<"\nLe Rational 0/0 resulte en une erreur, le chiffre zero etant represente par 0/1"<<std::endl;
    std::cout<<"\n\n\n"<<"Presser une touche -> Chapitre suivant"<<std::endl;
    std::cin>>a;
    return;
}

void chapter2(){
    system("clear");
    std::cout<<"Il existe 4 constructeurs pour instancier un Rational :"<<std::endl;
    std::cout<<"   - default constructor -> Rational<int>(1/0):"<<std::endl;
    std::cout<<"   - input constructor -> Rational<T>(T& n, T& d):"<<std::endl;
    std::cout<<"   - copy constructor -> Rational<T>(Rational<T>& r):"<<std::endl;
    std::cout<<"   - value constructor -> Rational<T>(A& value):"<<std::endl<<std::endl;
    std::cout<<"Exemple :"<<std::endl;
    std::cout<<"    Rational r1<int> = Rational<int>()"<<std::endl;
    Rational r1 = Rational<int>();
    std::cout<<"-> r1 = "<<r1<<std::endl;
    std::cout<<"    Rational<int> r2 = Rational<int>(-5,2)"<<std::endl;
    Rational r2 = Rational<int>(-5,2);
    std::cout<<"-> r2 = "<<r2<<std::endl;
    std::cout<<"    Rational<int> r3 = Rational<int>(r2)"<<std::endl;
    Rational r3 = Rational<int>(-5,2);
    std::cout<<"-> r3 = "<<r3<<std::endl;
    std::cout<<"    Rational<int> r4 = Rational<int>(3.5)"<<std::endl;
    Rational r4 = Rational<int>(3.5f);
    std::cout<<"-> r4 = "<<r4<<std::endl;
    
    std::cout<<"\n\n"<<std::endl;
    std::cout<<"nb: le value constructor prend un type A en argument, en suite c'est la fonction toRational qui s'occupe de convertir A en un Rational"<<std::endl;
    std::cout<<"\n\n\n"<<"Presser une touche -> Page suivante"<<std::endl;
    char a;
    std::cin>>a;
    system("clear");
    std::cout<<"La classe Rational comprend des surcharges pour les operateurs d'operations et de comparaisons :"<<std::endl;
    std::cout<<"   +, +=, -, -="<<std::endl;
    std::cout<<"   *, *=, /, /="<<std::endl;
    std::cout<<"   ==, !="<<std::endl;
    std::cout<<"   >, >=, <, <="<<std::endl<<std::endl;
    std::cout<<"Exemple :"<<std::endl;
    std::cout<<"Rational r5 = Rational(5,2);"<<std::endl;
    Rational<int> r5 = Rational<int>(5,2);
    std::cout<<"Rational r6 = Rational(-3,2);"<<std::endl<<std::endl;
    Rational<int> r6 = Rational<int>(-3,2);
    std::cout<<"    r5+r6 = "<<r1+r2<<std::endl;
    std::cout<<"    r5-r6 = "<<r1-r2<<std::endl;
    std::cout<<"    r5*r6 = "<<r1*r2<<std::endl;
    std::cout<<"    r5/r6 = "<<r1/r2<<std::endl<<std::endl;
    bool b1 = r5>r6;
    std::cout<<"    r5>r6 = "<<std::boolalpha<<b1<<std::endl;
    bool b2 = r5<r6;
    std::cout<<"    r5<r6 = "<<std::boolalpha<<b2<<std::endl;
    bool b3 = r5==r6;
    std::cout<<"    r5==r6 = "<<std::boolalpha<<b3<<std::endl;
    bool b4 = r5!=r6;
    std::cout<<"    r5!=r6 = "<<std::boolalpha<<b4<<std::endl;


    std::cout<<"\nL'operateur << de std::ostream a egalement ete surcharge :"<<std::endl;
    Rational<int> r = Rational<int>(5,2);
    std::cout<<"Rational r = Rational(5,2)\nstd::cout<<\"r = \"<<r<<std::endl"<<std::endl;
    std::cout<<"-> r = "<<r<<std::endl;
    std::cout<<"\n\n\n"<<"Presser une touche -> Chapitre suivant"<<std::endl;
    std::cin>>a;
    return;
}

void chapter3(){
    system("clear");
    std::cout<<"La methode principale de la librairie est : static Rational<T> toRational(A& v,int nbIter), elle permet de trier le type A de la value v a convertir :"<<std::endl;
    std::cout<<"Elle prend en premier parametre la valeur a convertir et en deuxieme le nombre d'iteration (dans le cas ou A=float)"<<std::endl;
    std::cout<<"    si A=Rational -> renvoie le meme Rational"<<std::endl;
    std::cout<<"    si A=integral -> renvoie Rational(v,1)"<<std::endl;
    std::cout<<"    si A=float -> utilise un algorithme de conversion"<<std::endl<<std::endl;
    std::cout<<"    sinon -> renvoie une exception"<<std::endl<<std::endl;
    std::cout<<"Exemples :"<<std::endl;
    std::cout<<"Rational<int> a = Rational::toRational(5,10)"<<std::endl;
    Rational<int> a = Rational<int>::toRational<int>(5,10);
    std::cout<<"a ="<<a<<std::endl;
    std::cout<<"Rational<int> b = Rational::toRational(a,10)"<<std::endl;
    Rational<int> b = Rational<int>::toRational<Rational<int>>(a,10);
    std::cout<<"b ="<<b<<std::endl;
    std::cout<<"Rational<int> c = Rational::toRational(5.9,10)"<<std::endl;
    Rational<int> c = Rational<int>::toRational<float>(5.9f,10);
    std::cout<<"c ="<<c<<std::endl<<std::endl;
    std::cout<<"\n\n\n"<<"Presser une touche -> Page suivante"<<std::endl;
    char z;
    std::cin>>z;
    system("clear");

    std::cout<<"La classe Rational comprend plusieurs methodes basiques"<<std::endl;
    std::cout<<"Certaines se servent de la STL en passant le Rational en float grace a la methode toFloat() :"<<std::endl;
    std::cout<<"    cos()"<<std::endl;
    std::cout<<"    sin()"<<std::endl;
    std::cout<<"    tan()"<<std::endl;
    std::cout<<"    sqrt()"<<std::endl;
    std::cout<<"    exp()"<<std::endl<<std::endl;
    std::cout<<"La methode pow() est une fonction recursive :"<<std::endl;
    Rational<int> r1 = Rational<int>(5,3);
    std::cout<<"Rational<int> r1 = Rational<int>(5,3)\nr1.pow(5) = "<<r1.pow(5)<<std::endl<<std::endl;
    std::cout<<"Les methodes min et max sont des fonctions recusives variadics :"<<std::endl;
    Rational<int> r2 = Rational<int>(5,3);
    Rational<int> r3 = Rational<int>(8,9);
    Rational<int> r4 = Rational<int>(-4,3);
    Rational<int> r5 = Rational<int>(-1,5);
    std::cout<<"   Rational<int> r2 = Rational<int>(5/3);\n   Rational<int> r3 = Rational<int>(8/9);\n   Rational<int> r4 = Rational<int>(-4/3);\n   Rational<int> r5 = Rational<int>(-1/5);\n"<<std::endl;
    std::cout<<"Rational<int>::min(r2,r3,r4,r5) = "<<Rational<int>::min(r2,r3,r4,r5)<<std::endl;
    std::cout<<"Rational<int>::max(r2,r3,r4,r5) = "<<Rational<int>::max(r2,r3,r4,r5)<<std::endl;
    std::cout<<"\n\n\n"<<"Presser une touche -> Chapitre suivant"<<std::endl;
    std::cin>>z;
    return;
}

void chapter4(){
    system("clear");
    std::cout<<"La librairie comprend un systeme d'exception qui permet a l'utilisateur de bien utiliser cette derniere"<<std::endl;
    std::cout<<"Voici une liste des cas qui peut mener a un crash :"<<std::endl;
    std::cout<<"    - Passer un type A != integral, floating_points, Rational au constructeur ou a la methode static toRational()"<<std::endl;
    std::cout<<"    - Essayer de construire un Rational(0,0), le zero correspondant a Rational(1,0)"<<std::endl;
    std::cout<<"    - Appeler la methode invert sur Rational(1,0) et Rational(0,1)"<<std::endl<<std::endl;
    std::string errorString;
    try {
        Rational r = Rational(0,0);
    } catch(std::exception& e){
        errorString = e.what();
    }
    std::cout<<"Exemple :\n   try{\n   Rational(0,0)\n} catch (std::exception& e){\nstd::cout<<e.what()<<std::endl;\n}\n->"<<errorString<<std::endl;
    std::cout<<"\nDe plus, des static_asserts permettent de verifier qu'a toute instantiation de la classe Rational<T>, T correspondent bien a un integral"<<std::endl;
    std::cout<<"En effet, cela n'aurait pas de sens de creer un Rational avec des floats au numerateur et denominateur !"<<std::endl;
    std::cout<<"\n\n\n"<<"Presser une touche -> Page suivante"<<std::endl;
    char a;
    std::cin>>a;

    system("clear");
    std::cout<<"Enfin, un ensemble de test unitaires se trouvent dans src/myTest/src/sample_test.cpp"<<std::endl;
    std::cout<<"Chemin vers l'executable : build/myTest/myUnitTests"<<std::endl;
    std::cout<<"Ces derniers assurent que toutes les fonctionnalites de la librairie fonctionnent !"<<std::endl;
    std::cout<<"\n\n\n"<<"Presser une touche -> Fin de la demo"<<std::endl;
    std::cin>>a;
    return;
}

void demoEnd(){
    system("clear");
    std::cout<<"FIN DE LA DEMO"<<std::endl<<std::endl;
    std::cout<<"Merci d'avoir telecharge notre librairie Rational !"<<std::endl;
    std::cout<<"Nous esperons que celle-ci vous sera utile !\n\n\n"<<std::endl;
    std::cout<<"Credits :"<<std::endl;
    std::cout<<"    Romain Serres"<<std::endl;
    std::cout<<"    Mathilde Stocchi"<<"\n\n";
    std::cout<<"Remerciements :"<<std::endl;
    std::cout<<"    Jules Fouchy"<<std::endl;
    std::cout<<"    Guy Luong"<<std::endl;
    std::cout<<"    Matteo Leclercq"<<std::endl;
    std::cout<<"    Elise Massa"<<std::endl;

}

void uRational(int nb_iter){
    Rational<int> u(1,3);
    for (int i=1; i<nb_iter; i++){
        std::cout<<"    u"<<i<<" = "<<u<<std::endl;
        u=u*4.0 - 1;
    }
    std::cout<<std::endl;
}

void uFloat(int nb_iter){
    float u=1.0/3.0;
    for (int i=1; i<nb_iter; i++){
        std::cout<<"    u"<<i<<" = "<<u<<std::endl;
        u=u*4 - 1;
    }
    std::cout<<std::endl;
}
#endif