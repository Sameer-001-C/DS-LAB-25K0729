#ifndef PARTICLE_H
#define PARTICLE_H


class Particle
{

private:

    double x;
    double y;

public:

    Particle(double x, double y)
    {
    	this->x = x;
    	this->y = y;
	}


	virtual void Jump() = 0;

    void SetX(double x)
    {
    	this->x = x;
	}
	
    void SetY(double y)
    {
    	this->y = y;
	}

    double GetX() const
    {
    	return x;
	}
	
    double GetY() const
    {
    	return y;
	}

};



#endif
