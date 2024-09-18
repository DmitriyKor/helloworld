#include <iostream>

using namespace std;

int main()
{
    //9.1
    int Value;
    int *pValue = &Value;
    *pValue = 26;
    cout << *pValue << "\n";
    int &rValue = Value;
    rValue = 27;
    cout << *pValue;

    //9.2, 9.3
    const int *pVar;
    int varOne;
    pVar=&varOne;
    varOne=6;
    //*pVar=7; //тут помилка
    int varTwo;
    pVar=&varTwo;

    //9.4
    int * pValue1 = new int;
    *pValue1=22;
    delete pValue1;
    pValue1 = nullptr;  //9.5

    //9.6
    for (int i=0; i<10; i++)
    {
        int * pValue2 = new int;  
        delete pValue2;  //9.7  
    }
   
    return 0;
}