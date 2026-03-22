#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
        _vecTime = other._vecTime;
        _deqTime = other._deqTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fillVector(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        std::string arg = av[i];

        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
            throw ErrorException();

        long val = std::strtol(av[i], NULL, 10);

        if (val < 0 || val > INT_MAX)
            throw ErrorException();

        _vec.push_back(static_cast<int>(val));
    }
}

void PmergeMe::fillDeque(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        std::string arg = av[i];

        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
            throw ErrorException();

        long val = std::strtol(av[i], NULL, 10);

        if (val < 0 || val > INT_MAX)
            throw ErrorException();

        _deq.push_back(static_cast<int>(val));
    }
}

std::vector<int> generateJacobsthal(int n)
{
    std::vector<int> j;
    if (n == 0)
        return j;
    j.push_back(1);
    if (n == 1)
        return j;
    j.push_back(3);
    while (j.back() < n)
    {
        int next = j[j.size() - 1] + 2 * j[j.size() - 2];
        j.push_back(next);
    }
    return j;
}

void PmergeMe::sortVector(std::vector<int> &v)
{
    int n = v.size();
    if (n <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? v[n - 1] : -1;

    for (int i = 0; i < n - 1; i += 2) {
        if (v[i] < v[i + 1])
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
        else
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);
    
    sortVector(mainChain);

    int first_pending = -1;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first == mainChain[0]) {
            first_pending = pairs[i].second;
            break;
        }
    }
    mainChain.insert(mainChain.begin(), first_pending);

    std::vector<int> pending;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first && pairs[j].second != first_pending) {
                pending.push_back(pairs[j].second);
            }
        }
    }

    std::vector<int> jacob = generateJacobsthal(pending.size());
    int lastPos = 0;
    for (size_t i = 0; i < jacob.size(); ++i) {
        int pos = std::min(jacob[i], (int)pending.size());
        for (int j = pos - 1; j >= lastPos; --j) {
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pending[j]);
            mainChain.insert(it, pending[j]);
        }
        lastPos = pos;
    }

    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
    v = mainChain;
}

void PmergeMe::sortDeque(std::deque<int> &d)
{
    int n = d.size();
    if (n <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? d[n - 1] : -1;

    for (int i = 0; i < n - 1; i += 2) {
        if (d[i] < d[i + 1])
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
        else
            pairs.push_back(std::make_pair(d[i], d[i + 1]));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);
    
    sortDeque(mainChain);

    int first_pending = -1;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first == mainChain[0]) {
            first_pending = pairs[i].second;
            break;
        }
    }
    mainChain.push_front(first_pending);

    std::deque<int> pending;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first && pairs[j].second != first_pending) {
                pending.push_back(pairs[j].second);
            }
        }
    }

    std::vector<int> jacob = generateJacobsthal(pending.size());
    int lastPos = 0;
    for (size_t i = 0; i < jacob.size(); ++i) {
        int pos = std::min(jacob[i], (int)pending.size());
        for (int j = pos - 1; j >= lastPos; --j) {
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pending[j]);
            mainChain.insert(it, pending[j]);
        }
        lastPos = pos;
    }

    if (hasStraggler) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
    d = mainChain;
}

void PmergeMe::run(int ac, char **av)
{
    clock_t start = clock();
    fillVector(ac, av);
    printSequence("Before: ", _vec);
    sortVector(_vec);
    _vecTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    fillDeque(ac, av);
    sortDeque(_deq);
    _deqTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;

    printSequence("After:  ", _vec);

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << _vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << _deqTime << " us" << std::endl;
}

void PmergeMe::printSequence(const std::string &title, const std::vector<int> &v)
{
    std::cout << title;
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i > 10)
        {
            std::cout << "[...]";
            break;
        }
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}