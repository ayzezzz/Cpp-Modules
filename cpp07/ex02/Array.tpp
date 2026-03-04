#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), length(n) {}

template <typename T>
Array<T>::Array(const Array &other) : array(NULL), length(0)
{
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] array;
        length = other.length;
        if (length > 0)
        {
            array = new T[length];
            for (unsigned int i = 0; i < length; i++)
                array[i] = other.array[i];
        }
        else
        {
            array = NULL;
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= length)
        throw BoundsException();
    return array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= length)
        throw BoundsException();
    return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return length;
}
