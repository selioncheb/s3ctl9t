/*
student: Nikolskiy Yuriy
group: 8005
theme: classes and universums

Rule: E = A / B / C v D
*/
#include <iostream>
#include "GCalcs.cpp"

using namespace std;

int main()
{
   
   
   
  
    
    
    
    Gcalcs* gc;
    
    int twi_key1;
   
   
    int i = 0;
    cout << "Select type of program" << endl
        << "1 - Enter values with keyboard" << endl
        << "2 - Generate values with pseudo random" << endl
        <<"Selection - ";
    cin >> twi_key1;
   
    switch (twi_key1)
    {
    case 2: 
      
        gc = new Gcalcs();
    
        break;
    case 1:
        char* bufA = new char[24];
        char* bufB = new char[24];
        char* bufC = new char[24];
        char* bufD = new char[24];
        
        cout << "Enter string of values A (asiydasf...)" << endl;
        cin >> bufA;
        cout << "Enter string of values B" << endl;
        cin >> bufB;
        cout << "Enter string of values C" << endl;
        cin >> bufC;
        cout << "Enter string of values D" << endl;
        cin >> bufD;
        cout << "use lists or arrays? "<<endl<<"1 - List"<<endl<<"2 - Array"<<endl<<"Selection - ";
        cin >> twi_key1;
        gc = new Gcalcs(bufA, bufB, bufC, bufD, twi_key1);
       
        break;
   
    }
   
    }

