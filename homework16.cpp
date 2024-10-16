#include <iostream>

using namespace std;


class Vehicle
{
public:
    virtual ~Vehicle(){}
    virtual int GetVehicleClass()=0;
    virtual string GetBrand()=0;
};

class Car : public Vehicle
{
public:
    virtual int GetVehicleClass() {return 2;}
    virtual void GetTuningOptionsTable(void * Table, int * row_number)=0;
};

class Bus : public Vehicle
{
public:
    virtual int GetVehicleClass() {return 4;}
};

class SportsCar : public Car
{
public:
     void GetTuningOptionsTable(void * Table, int * row_number) {Table=nullptr; row_number=0;}
};

class Wagon : public Car
{
public:
     void GetTuningOptionsTable(void * Table, int * row_number) {Table=nullptr; row_number=0;}
};


class Coupe : public Car
{
public:
     void GetTuningOptionsTable(void * Table, int * row_number) {Table=nullptr; row_number=0;}
};
 

int main()
{
    return 0;
}