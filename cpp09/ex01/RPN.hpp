#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <exception>

class RPN
{
private:
    std::stack<int> _stack;

public:
    RPN();
    RPN(const RPN &copy);
    RPN &operator=(const RPN &copy);
    ~RPN();

    void calculate(const std::string &argv);
};

#endif