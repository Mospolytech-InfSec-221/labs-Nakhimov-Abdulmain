#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main()
{
    std::string textin;
    int count = 0;
    std::map < std::string, double > text;

    std::getline(std::cin, textin);

    std::istringstream iss(textin);
    std::string line;
    while (std::getline(iss, line, ' ')) 
    {
        count++;
        if (text.find(line.c_str()) == text.end()) 
        {
            text.insert(std::pair<std::string, double>(line.c_str(), 1));
        }
        else 
        {
            text[line.c_str()]++;
        }
    }

    for (auto row : text) 
    {
        std::cout << row.first << ' ' << (row.second / count * 100) << '%' << std::endl;
    }
}
