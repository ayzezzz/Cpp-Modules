#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
    T *array;
    unsigned int length;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

    unsigned int size() const;

    class BoundsException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Error: Index out of bounds";
        }
    };
};

#include "Array.tpp"

#endif