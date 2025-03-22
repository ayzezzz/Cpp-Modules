/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:34:12 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/10 14:29:48 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << " Error: arguments 🤡" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream infile(filename.c_str());

    if(filename.empty() || s1.empty() || s2.empty())
			return std::cout << "Any argument cannot be empty 🤡" << std::endl,1;
    
    if (!infile.is_open())
    {
        std::cout << " Error: not open the file 🤡" << std::endl;
        return 1;
    }
    std::string new_filename = filename + ".replace";
    std::ofstream outfile(new_filename.c_str());
    if (!outfile.is_open())
    {
        std::cout << " Error: not create the file 🤡" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(infile, line))
    {
        size_t loc = 0;
        while ((loc = line.find(s1, loc)) != std::string::npos)
        {
            line = line.substr(0, loc) + s2 + line.substr(loc + s1.length());
            loc += s2.length();
        }
        outfile << line ;
        if(!infile.eof())
            outfile << std::endl;
    }
    return 0;
}