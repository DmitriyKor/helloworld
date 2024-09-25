#include <iostream>

using namespace std;

using UINT =  unsigned int;

class SimpleCircle
{
private:
    UINT &rRadius;
public:
    SimpleCircle() : rRadius(*(new UINT)) {rRadius=0;}
    SimpleCircle(UINT radius);
    SimpleCircle(const SimpleCircle &circle);
    ~SimpleCircle();
    void setRadius(UINT radius);
    UINT getRadius() {return rRadius;};
    SimpleCircle& operator++();
    SimpleCircle operator++(int);
    SimpleCircle& operator=(const SimpleCircle& circle);
};



SimpleCircle::SimpleCircle(UINT radius) : rRadius(*(new UINT))
{   
    rRadius = radius;
}

SimpleCircle::SimpleCircle(const SimpleCircle &circle): rRadius(*(new UINT))
{
    rRadius = circle.rRadius;
}
 

SimpleCircle::~SimpleCircle()
{
    delete &rRadius;
}

void SimpleCircle::setRadius(UINT radius)
{
    rRadius=radius;
}

SimpleCircle& SimpleCircle::operator++()
{
    rRadius++;
    return *this;
}

SimpleCircle SimpleCircle::operator++(int)
{
    SimpleCircle temp=*this;
    ++*this;
    return temp;
}

SimpleCircle& SimpleCircle::operator=(const SimpleCircle& circle)
{
    if (this!=&circle)    
        rRadius=circle.rRadius;        
    return *this;
}


int main()
{
    SimpleCircle c1;
    SimpleCircle c2(9);
    c1++;
    c2++;
    cout << "radius of c1 is " << c1.getRadius() << endl;
    cout << "radius of c2 is " << c2.getRadius() << endl;
    c1=c2;
    cout << "radius of c1 is " << c1.getRadius() << endl;
    cout << "radius of c2 is " << c2.getRadius() << endl;
    return 0;
}