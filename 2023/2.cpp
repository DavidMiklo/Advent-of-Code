#include "C:\Users\Lenovo\OneDrive\Desktop\Uni\C++\adventofcode\help.hpp"

struct Bag
{
    int red = 0;
    int blue = 0;
    int green = 0;
    Bag() = default;

    bool is_valid()
    {
        return this->red <= 12 &&
               this->green <= 13 &&
               this->blue <= 14; 
    }
};

void part_one()
{
    int sol = 0;

    while (getline(file, line))
    {
        std::stringstream ss(line);
        Bag bag;
        int id, num;
        std::string trash, colour;
        char c;

        ss >> trash >> id >> c;
        while (ss >> num >> colour)
        {
            if (colour.find("red") != std::string::npos) bag.red = std::max(bag.red, num);
            else if (colour.find("blue") != std::string::npos) bag.blue = std::max(bag.blue, num);
            else if (colour.find("green") != std::string::npos) bag.green = std::max(bag.green, num);
        }

        if (bag.is_valid()) sol += id;
        
    }
    std::cout << sol << std::endl;
}

void part_two()
{
    int sol = 0;
    file.clear();
    file.seekg(0, std::ios::beg);

    while (getline(file, line))
    {
        std::stringstream ss(line);
        Bag bag;
        int id, num;
        std::string trash, colour;
        char c;

        ss >> trash >> id >> c;
        while (ss >> num >> colour)
        {
            if (colour.find("red") != std::string::npos) bag.red = std::max(bag.red, num);
            else if (colour.find("blue") != std::string::npos) bag.blue = std::max(bag.blue, num);
            else if (colour.find("green") != std::string::npos) bag.green = std::max(bag.green, num);
        }
        sol += bag.red * bag.green * bag.blue;
    }
    std::cout << sol << std::endl;
}


int main(int argc, char *argv[])
{
    part_one();
    part_two();

    return 0;
}