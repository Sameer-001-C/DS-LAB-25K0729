#include "particle.h"


Particle::Particle(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Particle::GetX() const
{
    return x;
}

double Particle::GetY() const
{
    return y;
}

void Particle::SetX(double x)
{
    this->x = x;
}

void Particle::SetY(double y)
{
    this->y = y;
}



