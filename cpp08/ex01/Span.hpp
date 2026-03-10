#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>

class Span {
private:
    unsigned int _n;
    std::vector<int> _storage;

public:
    Span(); 
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        if (_storage.size() + std::distance(begin, end) > _n)
            throw std::runtime_error("Span is full!");
        _storage.insert(_storage.end(), begin, end);
    }

    int shortestSpan();
    int longestSpan();
};

#endif