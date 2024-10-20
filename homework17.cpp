#include <iostream>

using namespace std;

class Vehicle
{
private:
    int mPassengers;
    int mHorsePower;
    int mMaxSpeed;
    static int AutoparkSize;

public:
    Vehicle(int pass_num, int power, int max_speed) : mPassengers(pass_num),
        mHorsePower(power), mMaxSpeed(max_speed) { AutoparkSize++; }
    ~Vehicle() { AutoparkSize--; }
    static int GetAutoparkSize() { return AutoparkSize; }
    int GetPassengers() const { return mPassengers; }
    int GetHorsePower() const { return mHorsePower; }
    int GetMaxSpeed() const { return mMaxSpeed; }
};

int Vehicle::AutoparkSize = 0;

typedef int (Vehicle::*MFuncPtr)() const;

int main()
{
    MFuncPtr pFunc = &Vehicle::GetPassengers;
    MFuncPtr MFunc1 =  &Vehicle::GetHorsePower;
    MFuncPtr MFunc2 =  &Vehicle::GetMaxSpeed;

    
    cout << "Vehicle count=" << Vehicle::GetAutoparkSize() << endl;

    Vehicle *v1 = new Vehicle(4, 150, 160);
    cout << "Created a vehicle with a number of passengers " << (v1->*pFunc)() << endl;
    cout << "Other params: " << (v1->*MFunc1)() <<", "<< (v1->*MFunc2)() << endl;
   
    Vehicle *v2 = new Vehicle(2, 240, 210);
    cout << "Created a vehicle with a number of passengers " << (v2->*pFunc)() << endl;

    Vehicle *v3 = new Vehicle(12, 140, 180);
    cout << "Created a vehicle with a number of passengers " << (v3->*pFunc)() << endl;

    cout << "Vehicle count=" << Vehicle::GetAutoparkSize() << endl;
    delete v1;
    cout << "Vehicle count=" << Vehicle::GetAutoparkSize() << endl;
    delete v2;
    cout << "Vehicle count=" << Vehicle::GetAutoparkSize() << endl;
    delete v3;
    cout << "Vehicle count=" << Vehicle::GetAutoparkSize() << endl;

    return 0;
}