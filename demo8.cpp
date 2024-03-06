#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <map>

// findin the missing number --> brute force
int missingnumber(std::vector<int>& a, int N)
{
    for(int i = 1; i <= N; i++)
    {
        int flag = 0;
        for(int j = 0; j < a.size(); j++)
        {
            if(a[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0) 
            return i;
    }
}
// better
int missing_number(std::vector<int>& a, int N)
{
    std::vector<int> table(a.size() + 1, 0);
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] >= 1 && a[i] <= N)
        {
            table[a[i]] = 1;
        }
    }
    for(int i = 1; i <= N; i++)
    {
        if(table[i] == 0)
        {
            return i;
        }
    }
}
// optimal
int missing__number(std::vector<int>& a, int N)
{
    int sum = (N * (N + 1)) / 2;
    int s = 0;
    for(int i = 0; i < a.size(); i++)
    {
        s = s + a[i];
    }
    return sum - s;
}
// most optimal
int missing___number(std::vector<int>& a, int N)
{
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < N - 1; i++)
    {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}
// 3 consecutive number
int consecutive_ones(std::vector<int>& a)
{
    int count = 0;
    int maximum = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == 1)
        {
            count++;
            maximum = std::max(maximum, count);
        }
        else{
            count = 0;
        }
    }
    return maximum;
}
// Find the number that appears once, and the other numbers twice --> brute force O(n^2)
int getSingleElement(std::vector<int>& a)
{
    for(int i = 0; i < a.size(); i++)
    {
        int num = a[i];
        int count = 0;
        for(int j = 0; j < a.size(); j++)
        {
            if(a[j] == num)
            {
                count++;
            }
        }
        if(count == 1) 
            return num;
    }
}
// O(n)
int get_Single_Element(std::vector<int>& a)
{
    int x = 0;
    for(int i = 0; i < a.size(); i++)
    {
        x = x ^ a[i];
    }
    return x;
}

// Longest Subarray with sum K [positives] O(n^2)
int longestSubarrayWithSumK(std::vector<int> a, int k) {
    int len = 0;
    for(int i = 0; i < a.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < a.size(); j++)
        {
            sum = sum + a[j];
            if(sum == k)
            {
                len = std::max(len, j - i + 1);
            }
        }
    }
    return len;
}

// int longestSubarrayWithSumK(std::vector<int> a, int k)
// {}



int main()
{   
    std::vector<int> a = {2, 3, 1, 7, 11, 4};
    std::cout << two___sum(a, 100);
}