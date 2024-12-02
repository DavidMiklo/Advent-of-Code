#include "C:\Users\Lenovo\OneDrive\Desktop\Uni\C++\AoC\help.hpp"

int part1()
{
    ll sol = 0;
    vector<int> left{};
    vector<int> right{};
    while (getline(file, line))
    {
        stringstream ss(line);
        int l, r;
        ss >> l >> r;
        left.push_back(l);
        right.push_back(r);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for (int i = 0; i < left.size(); ++i)
    {
        sol += abs(left[i] - right[i]);
    }
    file.clear();
    file.seekg(0, std::ios::beg);

    return sol;
}

int part2()
{
    ll sol = 0;
    vector<int> left{};
    unordered_map<int,int> m;

    while (getline(file, line))
    {
        stringstream ss(line);
        int l, r;
        ss >> l >> r;
        left.push_back(l);
        m[r]++;
    }
    for (int i = 0; i < left.size(); ++i)
    {
        sol += left[i] * m[left[i]];
    }

    return sol;
}

int main()
{
    cout << part1() << endl;
    cout << part2();

    return 0;
}