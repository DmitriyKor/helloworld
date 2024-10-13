#include <iostream>

using namespace std;

class Rocket
{
protected:
    int mPower; 
public:
    Rocket (int power) : mPower (power) {};
    virtual ~Rocket(){};
    int GetPower() const {return mPower;};
    void SetPower(int power) {mPower=power;};
};

class Airplane
{
protected:
    int mSeatNumber;
public:
    Airplane(int seat_number) : mSeatNumber (seat_number) {};
    virtual ~Airplane(){};
    int GetSeatNumber() const {return mSeatNumber;};
    void SetSeatNumber(int seat_number) {mSeatNumber=seat_number;};
};

class JetPlane : public Rocket, public Airplane
{
protected:
    int mJetEngineNumber;
public:
    JetPlane (int power, int seat_number, int engine_number) : Rocket(power), Airplane(seat_number), 
        mJetEngineNumber(engine_number) {}; 
    virtual ~JetPlane(){};
    virtual int GetTotalPower() const {return mJetEngineNumber*mPower;};
};

class Boeing747 : public JetPlane
{
private:
    using Airplane::SetSeatNumber;
    using Rocket::SetPower;
public:
    Boeing747() : JetPlane(3000, 88, 2) {};
    virtual ~Boeing747(){};
};

int main()
{
    return 0;
}
