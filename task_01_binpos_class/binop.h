
#ifndef BINOPS_H
#define BINOPS_H
#include <string>

class BinOps {
private:
    double operand1;
    double operand2;
    char op;

public:

    BinOps() = default;
    BinOps(double op1, double op2, char op);

    void setOperand1(double op1);
    void setOperand2(double op2);
    void setOp(char op);

    double getOperand1() const;
    double getOperand2() const;
    char getOp() const;
    double evaluate() const;
    
    std::string toString() const;

};

#endif // BINOPS_H