/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:04:06 by zayaz             #+#    #+#             */
/*   Updated: 2026/03/23 10:04:07 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <limits>

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    double _vecTime;
    double _deqTime;

    void sortVector(std::vector<int> &v);
    void sortDeque(std::deque<int> &d);

    void fillVector(int ac, char **av);
    void fillDeque(int ac, char **av);

    void printSequence(const std::string &title, const std::vector<int> &v);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run(int ac, char **av);
};
class ErrorException : public std::invalid_argument
{
public:
    ErrorException() : std::invalid_argument("Error") {}
};
#endif