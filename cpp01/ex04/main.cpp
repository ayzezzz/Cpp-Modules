#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << " Error: arguments" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile(filename);
    if (!infile.is_open())
    {
        std::cout << " Error: not open the file" << std::endl;
        return 1;
    }
    std::string new_filename = filename + ".replace";
    std::ofstream outfile(new_filename);
    if (!outfile.is_open())
    {
        std::cout << " Error: not create the file" << std::endl;
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
        outfile << line << std::endl;
    }
    return 0;
}