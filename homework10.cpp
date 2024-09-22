#include <iostream>

using namespace std;

using UINT =  unsigned int;

class SimpleCircle
{
private:
    UINT mRadius;  
public:
    SimpleCircle(UINT radius);
    ~SimpleCircle();
    void setRadius(UINT radius);
};



SimpleCircle::SimpleCircle(UINT radius)
{
    mRadius=radius;
}

SimpleCircle::~SimpleCircle()
{
}

void SimpleCircle::setRadius(UINT radius)
{
    mRadius=radius;
}


int main()
{
    SimpleCircle *circle = new SimpleCircle (18);
    SimpleCircle &rcircle = *circle;

    rcircle.setRadius(33);

    delete circle;
    return 0;
}