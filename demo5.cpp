#include <iostream>
#include <algorithm>
#include <utility>
#include <math.h>
#include <vector>
#include <string.h>

// Pair
void pair_explained()
{
    std::pair<int, int> p = {2, 4};
    std::cout << p.first << " " << p.second << std::endl;

    std::pair<int, std::pair<int, int>> a = {1, {3, 9}};
    std::cout << a.first << " " << a.second.first << " " << a.second.second << std::endl; 

    std::pair<int, int> arr[] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}};
    std::cout << arr[0].first << " " << arr[0].second << std::endl;
    std::cout << arr[1].first << " " << arr[1].second << std::endl;
    /*
    2 4
    1 3 9
    0 1
    0 2
    */
}

int main(int argc, char** argv)
{
    pair_explained();
    
    return 0;
}