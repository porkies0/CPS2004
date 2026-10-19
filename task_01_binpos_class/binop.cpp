#include "binop.h"
#include <iostream>
#include <string>
#include <fstream>

BinOps::BinOps(double op1, double op2, char op) : operand1(op1), operand2(op2), op(op) {}

void BinOps::setOperand1(double op1) {
    operand1 = op1;
}

void BinOps::setOperand2(double op2) {
    operand2 = op2;
}

void BinOps::setOp(char op) {
    this->op = op;
}

double BinOps::getOperand1() const {
    return operand1;
}

double BinOps::getOperand2() const {
    return operand2;
}

char BinOps::getOp() const {
    return op;
}

double BinOps::evaluate() const {

    if (op == '+'){
        return operand1 + operand2;
    }
    else if (op == '-'){
        return operand1 - operand2;
    }
    else if (op == '*'){
        return operand1 * operand2;
    }
    else if (op == '/'){
        if (operand2 == 0) {
            throw std::runtime_error("Division by zero");
        }
        return operand1 / operand2;
    }
    throw std::invalid_argument("Invalid operator");
}
 


std::string BinOps::toString() const{
    return std::to_string(operand1) + " " + op + " " + std::to_string(operand2);
}