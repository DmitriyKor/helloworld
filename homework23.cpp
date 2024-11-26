#include <iostream>
#include <math.h>

using namespace std;

class ENumericException
{
public: 
    ENumericException(string message) : mMessage(message) {}
    ~ENumericException() {}
    string GetMessage() const {return mMessage;}
private:
    string mMessage;
};

class ENumericExceptionDetailed : public ENumericException
{
public:
    ENumericExceptionDetailed(string message, string variable) : ENumericException(message), 
    mVariable(variable) {}
    string GetVariable() const {return mVariable;}
private:
    string mVariable;
};

#define AllowedRange 1000000
#define PI 3.14159265

double ProcessTwoNumbers(double X, double Y)
{
    if (X==0)
        throw ENumericException("First parameter is wrong");
    
    if (abs(X) > AllowedRange) 
        throw ENumericExceptionDetailed("Out of range", "X");
    if (abs(Y) > AllowedRange) 
        throw ENumericExceptionDetailed("Out of range", "Y");

    return atan2(Y, X) * 180 / PI; 
}

int main()
{
    double Azimuth1;
    try
    {
        Azimuth1 = ProcessTwoNumbers(5, 5000000);
        cout << "Result is " << Azimuth1;
    }
 
    catch(const ENumericExceptionDetailed & e)
    {
        cout << "Error occured: " << e.GetMessage() << ", variable " << e.GetVariable();
        return 1;
    }
    
    catch(const ENumericException & e)
    {
        cout << "Error occured: " << e.GetMessage();
        return 1;
    }
    
    catch (...)
    {
        cout  << "Other unknown error occured";     
    }

    return 0;
}