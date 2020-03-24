/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

static int add(int a, int b){return a + b;}
static int minus(int a, int b){return a - b;}
static int mult(int a, int b){return a * b;}
static int division(int a, int b){return a / b;}
static int modulo(int a, int b){return a % b;}

static int calc(int nbr1, int nbr2, char op){
    switch (op)
    {
    case '+':
            return add(nbr1, nbr2);
            break;
    case '-':
            return minus(nbr1, nbr2);
            break;
    case '*':
            return mult(nbr1, nbr2);
            break;
    case '/':
            return division(nbr1, nbr2);
            break;
    case '%':
            return modulo(nbr1, nbr2);
            break;
    default:
            return 0;
            break;
    }
}

Parser::Parser(){}

Parser::~Parser(){}

void Parser::feed(const std::string &expression){
    int i = 0;
    int nbr1;
    int nbr2;
    int tmp = 0;
    char op;

    while(expression[i] != '\0'){
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%'){
            operators.push(expression[i]);
            ++i;
        }
        else if (expression[i] >= '0' && expression[i] <= '9'){
            tmp = 0;
            while (expression[i] && expression[i] >= '0' && expression[i] <= '9'){
                //std::cout << tmp << std::endl;
                //std::cout << expression[i] << std::endl;

                tmp = tmp * 10 + expression[i] - '0';
                ++i;
                //std::cout << tmp << std::endl;
            }
            values.push(tmp);
        }
        else if (expression[i] == ')'){
            nbr1 = values.top();
            values.pop();
            nbr2 = values.top();
            values.pop();
            op = operators.top();
            operators.pop();
            //std::cout << calc(nbr1, nbr2, op) << "$$$$$$$$$$$$$$" <<std::endl;
            values.push(calc(nbr2, nbr1, op));
            ++i;
        }
        else ++i;
    }
    nbr1 = values.top();
    values.pop();
    if (!values.empty()){
        if (!operators.empty()){
            op = operators.top();
            operators.pop();
            nbr1 = calc(values.top(), nbr1, op);
        } else {
            nbr1 += values.top();
            values.pop();
        }
    }
    values.push(nbr1);
}

int Parser::result() const{
    return values.top();
}

void Parser::reset(){
    while(!values.empty())
        values.pop();
    while(!operators.empty())
        operators.pop();
}
