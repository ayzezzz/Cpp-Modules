#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) { *this = copy; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        this->_rates = copy._rates;
    return *this;
}

std::string BitcoinExchange::trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    std::istringstream ssY(date.substr(0, 4));
    std::istringstream ssM(date.substr(5, 2));
    std::istringstream ssD(date.substr(8, 2));

    if (!(ssY >> year) || !(ssM >> month) || !(ssD >> day))
        return false;
    if (year < 2008 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[2] = 29;

    if (day > daysInMonth[month])
        return false;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string &dbFile)
{
    std::ifstream file(dbFile.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t comma = line.find(',');
        if (comma != std::string::npos)
        {
            std::string date = line.substr(0, comma);
            double rate = std::atof(line.substr(comma + 1).c_str());
            _rates[date] = rate;
        }
    }
}

void BitcoinExchange::processInput(const std::string &inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        try
        {
            size_t pipe = line.find('|');
            if (pipe == std::string::npos)
                throw std::runtime_error("bad input => " + line);

            std::string date = trim(line.substr(0, pipe));
            std::string valStr = trim(line.substr(pipe + 1));

            if (!isValidDate(date))
                throw std::runtime_error("bad input => " + date);

            char *endptr;
            double value = std::strtod(valStr.c_str(), &endptr);
            if (*endptr != '\0' && !isspace(*endptr))
                throw std::runtime_error("bad input => " + valStr);

            if (value < 0)
                throw std::runtime_error("not a positive number.");
            if (value > 1000)
                throw std::runtime_error("too large a number.");

            std::map<std::string, double>::iterator it = _rates.lower_bound(date);
            if (it != _rates.begin() && it->first != date)
                --it;

            if (it->first > date && it == _rates.begin())
                throw std::runtime_error("no data for this date.");

            std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}