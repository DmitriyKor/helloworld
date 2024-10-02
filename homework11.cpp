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
    virtual Rectangle* Clone() {return new Rectangle(this->mLength, this->mWidth);};
    virtual ~Rectangle() {};
    void ShowSize() {cout<<mLength <<' ' <<mWidth << "\n"; }
};


class Square : public Rectangle
{
private:
public:
    Square (int length) : Rectangle(length, length){}
    virtual Square* Clone() {return new Square(this->mLength);};
};




int main()
{
    Rectangle *s1, *s2;

    s1=new Square(5);
    s2=s1->Clone();

    s1->ShowSize();
    s2->ShowSize();

    
    delete s1;
    delete s2;

    return 0;
}
