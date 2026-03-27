/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:08:02 by zayaz             #+#    #+#             */
/*   Updated: 2026/03/23 10:08:03 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>

class BitcoinExchange {
private:
    std::map<std::string, double> _rates; 
    std::string trim(const std::string& str);
    bool isValidDate(const std::string& date);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& copy);
    BitcoinExchange& operator=(const BitcoinExchange& copy);
    ~BitcoinExchange();

    void loadDatabase(const std::string& dbFile);
    void processInput(const std::string& inputFile);
};

#endif