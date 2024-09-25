#include <iostream>

using namespace std;

class Shape
{
private:
public:
    Shape(){};
    ~Shape(){};
};

class Rectangle : public Shape
{
protected:
    int mLength;
    int mWidth;
public:
    Rectangle(int length, int width){mLength=length; mWidth=width;};
};


class Square : public Rectangle
{
private:
public:
    Square(int length) : Rectangle(length, length){}
};

int main()
{
    return 0;
}