#include <iostream>

using namespace std;

int main()
{

    int Value;
    int *pValue = &Value;
    *pValue = 26;
    cout << *pValue << "\n";

    int &rValue = Value;
    rValue = 27;
    cout << *pValue;


    /*

    int Arr10x10 [10][10];
    for (int x=0;x<10;x++)
    {
        for (int y=0; y<10; y++) 
            {Arr10x10[x][y]=0;}
    }

    cout << "for:\n";
    for (int i=100; i<=200; i+=2)
    {
        cout << i << " ";
    }

    cout << "\nwhile:\n";
    int i=100;
    while (i<=200) 
    {
        cout << i << " ";
        i+=2;
    }

    cout << "\ndo while:\n";
    i=100;
    do
    {
        cout << i << " ";
        i+=2;
    } 
    while (i<=200);
   
  */
    return 0;
}