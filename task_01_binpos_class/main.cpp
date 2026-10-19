#include <iostream>
#include <string>
#include <fstream>
#include "binop.h"
#include <limits>
#include <cmath>


using namespace std;

int main() {

    int capacity = 5;
    BinOps* expressions = new BinOps[capacity];
    int count = 0;

    while (count != capacity){

        std::cout << "Expresion" << " " << (count + 1) << ":" << " ";
        double left, right;
        char op;

        if (std::cin >> left >> op >> right){
            expressions[count].setOperand1(left);
            expressions[count].setOperand2(right);
            expressions[count].setOp(op);
        }
        else{
            if (cin.eof()){
                cout << " Input stream ended ";
                break;
            }
        
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input\n";
        }

        count++;
    }

    std::ofstream os("output.txt");
    if (!os) {
        std::cerr << "Error while opening output.txt\n";
        delete[] expressions;
        return 1;
    }

    double value;
    for (int i = 0; i < count; i++){
        try {
            value = expressions[i].evaluate();
            round(value);
            os << expressions[i].toString() << " = " << value << "\n";
        } catch (const std::exception& e) {
            os << expressions[i].toString() << " -> Error: " << e.what() << "\n";
        }
        
    }
    delete[] expressions;
    return 0;
}