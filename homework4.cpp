#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cout << "Enter A:";
    cin >> A;
    cout << "Enter B:";
    cin >> B;

    if (A>B)
        A = B;
    else
        B = A;
    cout << "\nNow both have less value, A=" << A << ", B=" << B;
   
    return 0;
}