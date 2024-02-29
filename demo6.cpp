#include <iostream>
#include <algorithm>
#include <utility>
#include <math.h>
#include <vector>
#include <map>

// Number Hashing example
void num_hasing()
{
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    // precompute the frequency of each elements in the array
    int hash[13] = {0};
    for(int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    int q;
    std::cin >> q;
    while(q--)
    {
        int num;
        std::cin >> num;
        // fetching
        std::cout << hash[num] << std::endl;
    }

    delete arr;
/*
inputs:
5
1 3 2 1 2
5
1 
2 
5 
4 
10
outputs:
2
2
0
0
0
*/
}

// Character Hasing example
void char_hasing()
{
    int n;
    std::cin >> n;
    char* ch = new char[n];
    for(int i = 0; i < n; i++)
    {
        std::cin >> ch[i];
    }

    // precompute the frequency of each elements in the char array
    int hash[26] = {0};
    for(int i = 0; i < n; i++)
    {
        hash[ch[i] - 'a']++;
    }

    int q;
    std::cin >> q;
    while(q--)
    {
        char c;
        std::cin >> c;
        // fetching
        std::cout << hash[c - 'a'] << std::endl;
    }

    delete ch;    
/*
inputs:
5
a c e b b
4
a b c e
outputs: 
1
2
1
1
*/
}

// Character Hashing example --> for 256 characters as a whole
void char_hasing_full()
{
    int n;
    std::cin >> n;
    char* ch = new char[n];
    for(int i = 0; i < n; i++)
    {
        std::cin >> ch[i];
    }

    // precompute the frequency of each elements in the char array
    int hash[256] = {0};
    for(int i = 0; i < n; i++)
    {
        hash[ch[i]]++;
    }

    int q;
    std::cin >> q;
    while(q--)
    {
        char c;
        std::cin >> c;
        // fetching
        std::cout << hash[c] << std::endl;
    }

    delete ch;    
/*
inputs:
5
a c e b b
4
a b c e
outputs: 
1
2
1
1
*/
}

// using map (int inputs)
void num_map()
{
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    // precompute the frequency of each element in the map
    std::map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    // iterate in the map
    // for(auto it : mp)
    // {
    //     std::cout << it.first << "--> " << it.second << std::endl;
    // }

    int q;
    std::cin >> q;
    while(q--)
    {
        int num;
        std::cin >> num;
        std::cout << mp[num] << std::endl;
    }

    delete arr;   
/*
inputs:
7
1 2 3 1 3 2 12
4
2 3 12 1
outputs:
2
2
1
*/
}

// using map (char/string inputs)
void char_map()
{
    int n;
    std::cin >> n;
    char* arr = new char[n];
    std::map<char, int> mp;
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        mp[arr[i]]++;
    }

    // iterate in the map
    // for(auto it : mp)
    // {
    //     std::cout << it.first << "--> " << it.second << std::endl;
    // }

    int q;
    std::cin >> q;
    while(q--)
    {
        char c;
        std::cin >> c;
        std::cout << mp[c] << std::endl;
    }

    delete arr;   
/*
inputs:
5
a f c d a
4
a c d e
outputs:
2
1
1
0
*/
}



int main(int argc, char** argv)
{

    return 0;
}