#include <iostream>

using namespace std;

unsigned long int Perimeter(unsigned short Length, unsigned short Height);

int main()
{
    cout << "Perimeter with sides 4 and 5 is " << Perimeter (4, 5);
}

unsigned long int Perimeter(unsigned short Length, unsigned short Height)
{
  return Length*2 + Height*2;
}