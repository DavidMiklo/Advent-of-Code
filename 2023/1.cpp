#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

std::fstream file("X");
std::string line;

const std::map<std::string, int> numbers = 
{
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
};

void part_one()
{
    int sol = 0;
    while (getline(file, line))
    {
        std::vector<int> num;
        for (int i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i]))
                num.push_back(line[i] - '0');
        }
        sol += (num.front()) * 10 + (num.back());
    }

    std::cout << sol << '\n';
}

void part_two()
{
    int sol = 0;
    while (getline(file, line))
    {
        std::vector<int> num;
        for (int i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i]))
                num.push_back(line[i] - '0');

            for (int j = 3; j < 6; j++)
            {
                std::string word = line.substr(i, j);
                if (numbers.count(word))
                    num.push_back(numbers.at(word));
            }
        }
        sol += (num.front()) * 10 + (num.back());
    }

    std::cout << sol << '\n';
}

int main(int argc, char *argv[])
{
    part_one();
    part_two();

    return 0;
}
