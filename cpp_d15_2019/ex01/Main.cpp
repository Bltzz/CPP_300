#include <iostream>
#include <string>
#include "ex01.hpp"
#include "toto.cpp"

int  main(){
    toto a;
    toto b;
    ::compare(&a, &b);
    //std::cout << "a = " << a << ", b = " << b << std::endl;
    //std::cout << "min(a, b) = " << ::compare(a, b) << std::endl;
    //std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    //std::cout << "add(a, b) = " << ::add(a, b) << std::endl;

    std::string c = "chaine0";
    std:: string d = "chaine1";
    ::compare(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::compare(c, d) << std::endl;
    //std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    //std::cout  << "add(c, d) = " << ::add(c, d) << std::endl;
}