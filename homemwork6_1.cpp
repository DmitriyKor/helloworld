#include <iostream>
using namespace std;

int IntToPower(int Value, int Power)
{
    if (Power>1) return Value*IntToPower(Value, Power-1);
    else return Value;
};

int main()
{
    int EnteredValue, EnteredPower;
    cout << "Enter value: ";
    cin >> EnteredValue;
    cout << "Enter power: ";
    cin >> EnteredPower;
    cout << "Result is: " << IntToPower(EnteredValue, EnteredPower);
    return 0;
}