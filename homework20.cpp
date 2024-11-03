#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int  main (int argc, char *argv[])
{
    if (argc==1) {
        cout << "No parameter specified\n";
        return 1;
    }
   
    ifstream strm1(argv[1], ios_base::in /*| ios_base::binary*/);    
    if (strm1) {
        cout << "Content of file '" << argv[1] << "':\n\n";
        char ch;
        while (strm1 >> ch){
            if (isalpha(ch) || ch=='/n' || isspace(ch))
                cout << ch;
            else 
                cout << " ";    
        }                 
        strm1.close();
    }  
    else {
        cout << "Cannot open file\n";
       // return 1;
    }
    
    cout << "\n\nThe list of arguments in the backward order:\n";
    for (int ArgInd=argc-1; ArgInd>0; ArgInd--)
        cout << argv[ArgInd] << endl;

    return 0;
}