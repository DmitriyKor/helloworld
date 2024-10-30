#include <iostream>

using namespace std;

int main()
{
    //1
    int value1;
    cout << "Enter non-zero value: \n";
    cin >> value1;
    cout << "Entered value " << value1 << endl;
    if (value1==0)
        cerr << "Wrong entry\n";
    else 
        clog << "Correct entry\n";
    //2
    cin.ignore(INT_MAX, '\n');
    char FullName[256];
    cout << "Now enter the full name: \n";
    cin.getline(FullName, 256, '\n');
    cout << "You have entered: " << FullName << endl;
    //3
    char ch;
    cout << "enter a phrase: ";
    while (cin.get(ch))
    {
        if (ch == '!') 
            cout << '$'; 
        else if (ch == '#') 
            continue;
        else
            cout << ch;
    }


    return 0;
}