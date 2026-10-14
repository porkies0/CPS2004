#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct BinOp {
    double operand1;
    double operand2;
    string op;
};


int main() {

    double temp;
    int n = 100;
    BinOp* array = new BinOp[n];
    int count = 0;
    cout << "Enter binary operations (operand1 operator operand2), one per line. Type Ctrl+D to finish input." << endl;

    while (count < n && (cin >> array[count].operand1 >> array[count].op >> array[count].operand2)) {
        count++;
    }

    try {
        ofstream outputFile("binops_output.txt");
        if (!outputFile.is_open()) {
            throw -1;
        }

        for (int i = 0; i < count; i++) {
        if (array[i].op == "+") {

            temp = array[i].operand1 + array[i].operand2;

        } else if (array[i].op == "-") {

            temp = array[i].operand1 - array[i].operand2;

        } else if (array[i].op == "*") {

            temp = array[i].operand1 * array[i].operand2;

        } else if (array[i].op == "/") {

            if (array[i].operand2 == 0) {

                outputFile << array[i].operand1 << " / 0 -> Error: Division by zero" << endl;
                continue;

            } else {

                temp = array[i].operand1 / array[i].operand2;

            }
        } else {

            outputFile << "Invalid operator: " << array[i].op << endl;
            continue;

        }
        outputFile << array[i].operand1 << " " << array[i].op << " " << array[i].operand2 << " = " << temp << endl;
        }

        outputFile.close();

    } catch (const int error) {
        cerr << "Error: " << error << endl;
    }

    delete[] array;

    return 0;
}