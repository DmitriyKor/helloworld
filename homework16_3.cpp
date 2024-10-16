#include <iostream>

using namespace std;


class Vehicle
{
private:
    int mPassengers;
public:
    Vehicle(int pass_num): mPassengers(pass_num) {AutoparkSize++;}
    ~Vehicle(){AutoparkSize--;}
    static int AutoparkSize;
};

int Vehicle::AutoparkSize = 0;

int main()
{
    Vehicle *v1 = new Vehicle(4);
    Vehicle *v2 = new Vehicle(2);
    cout << Vehicle::AutoparkSize << endl;
    delete v1;
    cout << Vehicle::AutoparkSize << endl;
    delete v2;
    cout << Vehicle::AutoparkSize << endl;

    return 0;
}