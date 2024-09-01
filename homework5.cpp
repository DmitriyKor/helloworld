#include <iostream>

using namespace std;

unsigned long int Perimeter(unsigned short Length, unsigned short Height);

short DivideUShort(unsigned short a, unsigned short b);

int main()
{
    cout << "Perimeter with sides 4 and 5 = " << Perimeter (4, 5);

    cout << "\nEnter two values:\n";
    
    unsigned short value1, value2;

    cin >> value1;
    cin >> value2;

    short res = DivideUShort(value1, value2);

    if (res==-1) cout << "\nWrong divider, cannot be 0";
    else cout << "result = " << res;


}

unsigned long int Perimeter(unsigned short Length, unsigned short Height)
{
  return Length*2 + Height*2;
}


short DivideUShort(unsigned short a, unsigned short b)
{
    if (b) return a/b;
    else return -1;
}