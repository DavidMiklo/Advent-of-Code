#include "C:\Users\Lenovo\OneDrive\Desktop\Uni\C++\adventofcode\help.hpp"

int part_one(std::regex pattern)
{
    ll sol = 0;
    while (getline(file, line))
    {
        std::smatch match;
        auto it = line.cbegin();

        while (std::regex_search(it, line.cend(), match, pattern))
        {
            sol += stoi(match[1]) * stoi(match[2]);
            it = match.suffix().first;
        }
    }
    return sol;
}

int part_two(std::regex pattern)
{
    file.clear();
    file.seekg(0, std::ios::beg);
    ll sol = 0;
    bool flag = true;

    while (getline(file, line))
    {
        std::smatch match;
        auto it = line.cbegin();

        while (std::regex_search(it, line.cend(), match, pattern))
        {  
            if (match.str() != "do" && match.str() != "don't" && flag)
            {
                sol += stoi(match[1]) * stoi(match[2]);
            }
            else 
            {
                flag = match.str() == "do";
            }
            
            it = match.suffix().first;
        }
    }
    return sol;
}


int main()
{
    cout << part_one(std::regex(R"(mul\((\d+),(\d+)\))")) << endl;
    cout << part_two(std::regex("mul\\((\\d{1,3}),(\\d{1,3})\\)|don\\'t|do")) << endl;

    return 0;
}
