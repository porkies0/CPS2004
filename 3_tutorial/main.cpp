#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class MyClass (){

    private: 
        
        int field1;
        string field2;

    public:

        MyClass(): field1(2) field2("Hello world") {
            cout << "Consturctor called" << endl;
        }

        




}