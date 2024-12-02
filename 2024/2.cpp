#include "C:\Users\Lenovo\OneDrive\Desktop\Uni\C++\AoC\help.hpp"

bool is_bad(vector<ll> v)
{
    bool inc = false, dec = false, skip = false;

    for (ll i = 0; i < v.size() - 1; ++i)
    {
        ll diff = v[i] - v[i + 1];

        if (abs(diff) < 1 || abs(diff) > 3)
        {                
            return true;
        }
        if (diff > 0) dec = true;
        if (diff < 0) inc = true;
        if (dec && inc) 
        {
            return true;
        }
    }
    return false;
}

bool try_damped(vector<ll> v)
{
    for (ll i = 0; i < v.size(); ++i)
    {
        vector<ll> temp_vector = v;
        temp_vector.erase(temp_vector.begin() + i);

        if (!is_bad(temp_vector)) 
        {
            return true;
        }
    }
    return false;
}

int part1(vector<vector<ll>> input)
{
    return std::count_if(input.begin(), input.end(), [](const auto& v) {return !is_bad(v);});
}

int part2(vector<vector<ll>> input) 
{
    return std::count_if(input.begin(), input.end(), [](const auto& v) {return !is_bad(v) || try_damped(v);});
}

int main()
{
    vector<vector<ll>> input = get_ints();
    cout << part1(input) << endl;
    cout << part2(input);

    return 0;
}
