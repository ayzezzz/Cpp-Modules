#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &copy) { *this = copy; }
RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
        this->_stack = copy._stack;
    return *this;
}

void RPN::calculate(const std::string &argv)
{
    for (size_t i = 0; i < argv.length(); i++)
    {
        char c = argv[i];
        if (isspace(c))
            continue;

        if (isdigit(c))
        {
            _stack.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");

            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            if (c == '+')
                _stack.push(a + b);
            else if (c == '-')
                _stack.push(a - b);
            else if (c == '*')
                _stack.push(a * b);
            else if (c == '/')
            {
                if (b == 0)
                    throw std::runtime_error("Error: division by zero");
                _stack.push(a / b);
            }
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    std::cout << _stack.top() << std::endl;
}