/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:19:30 by zayaz             #+#    #+#             */
/*   Updated: 2026/03/11 12:31:22 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm> 
#include <stdexcept> 
#include <limits>    

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {
}

Span::Span(const Span &other) {
    *this = other;
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        this->_n = other._n;
        this->_storage = other._storage;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_storage.size() >= _n)
        throw std::runtime_error("Span is full: cannot add more numbers.");
    _storage.push_back(number);
}

int Span::longestSpan() {
    if (_storage.size() < 2)
        throw std::runtime_error("Not enough elements to find a span.");

    int min = *std::min_element(_storage.begin(), _storage.end());
    int max = *std::max_element(_storage.begin(), _storage.end());
    
    return (max - min);
}

int Span::shortestSpan() {
    if (_storage.size() < 2)
        throw std::runtime_error("Not enough elements to find a span.");

    std::vector<int> sorted = _storage;
    std::sort(sorted.begin(), sorted.end());

    int minDiff = std::numeric_limits<int>::max();

    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        int currentDiff = sorted[i + 1] - sorted[i];
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
        }
    }
    
    return minDiff;
}