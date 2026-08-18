#include <iostream>
#include "particle.h"



int main()
{
    
    Particle p(5.5, 10.0);

    std::cout << "X:" << p.GetX() << std::endl;
    std::cout << "Y:" << p.GetY() << std::endl;

    p.SetX(1.0);
    p.SetY(2.0);

    std::cout << "X:" << p.GetX() << std::endl;
    std::cout << "Y:" << p.GetY() << std::endl;


    return 0;
}