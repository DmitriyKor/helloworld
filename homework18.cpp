#include <iostream>
#include <cstring>

using namespace std;

class String 
{
public:
    String(const char * newstr){
        len = strlen(newstr);
        mstr = new char [len + 1];
        strcpy(mstr, newstr);
        mstr[len]='\0';
    }
    String(const String& aString){
        len = strlen(aString.mstr);
        mstr = new char [len + 1];
        strcpy(mstr, aString.mstr);    
        mstr[len]='\0';
    }
    ~String(){delete[] mstr;len=0;}
    friend ostream& operator<<(ostream& os, const String& AString); 
private:
    int len;
    char * mstr;
};

class Animal
{
private:
    int Value;
    String * mName;
public:
    Animal(const char * newstr) {mName = new String(newstr);}
    ~Animal(){delete mName;}
};

class Set
{

};

class BoundedArray
{
private:
    Set mSet;
};

int main()
{
    String *str1 = new String("test string");
    cout << *str1;
    delete str1;
    return 0;
}

ostream& operator<<(ostream& os, const String& AString)
{
    os << AString.mstr;
    return os;
}