#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#define LONG_MIN -2147483647

// two sum - brute force O(n^2)
bool two_sum(std::vector<int>& a, int target)
{
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = i + 1; j < a.size(); j++)
        {
           if(a[i] + a[j] == target) return true;         
        }
    }
    return false;
}
// finding indices
std::vector<int> two__sum(std::vector<int>& a, int target)
{
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = i + 1; j < a.size(); j++)
        {
            if(a[i] + a[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// better
std::string read(std::vector<int>& book, int n, int target)
{
    std::map <int, int> mpp;
    for(int i = 0; i < n; i++)
    {
        int a = book[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end())
        {
            return "YES";
        }
        mpp[a] = i;
    }
    return "NO";
}
// finding indices
std::vector<int> re(std::vector<int>& a, int target)
{
    std::map<int, int> mp;
    for(int i = 0; i < a.size(); i++)
    {
        int x = a[i];
        int m = target - x;
        if(mp.find(m) != mp.end())
            return {mp[m], i};
        mp[x] = i;
    }
    return {-1, -1};

/*
std::vector<int> a = {2, 3, 1, 7, 11, 4};
std::vector<int> o = re(a, 101);
if(o[0] != -1 && o[1] != -1) std::cout << o[0] << " " << o[1];
else std::cout << "invalid";
*/
}

// optimal for yes/no
std::string two___sum(std::vector<int>& a, int target)
{
    int l = 0, r = a.size() - 1;
    std::sort(a.begin(), a.end());
    while(l < r)
    {
        int sum = a[l] + a[r];
        if(sum == target)
            return "YES";
        else if(sum < target) l++;
        else r--;
    }
    return "NO";
}

// 0's 1's 2's
std::vector<int> zero_one_two(std::vector<int>& a)
{
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == 0) 
            count_0++;
        else if(a[i] == 1) 
            count_1++;
        else 
            count_2++;
    }
    for(int i = 0; i < count_0; i++)
        a[i] = 0;
    for(int i = count_0; i < count_0 + count_1; i++)
        a[i] = 1;
    for(int i = count_0 + count_1; i < a.size(); i++)
        a[i] = 2;
    return a;
}

// majority element checking (element count > n / 2)
int majority_element(std::vector<int>& a)
{
    for(int i = 0; i < a.size(); i++)
    {
        int count = 0;
        for(int j = 1; j < a.size(); j++)
        {
            if(a[i] == a[j])
                count++;
        }
        if(count > (a.size()) / 2)
            return a[i];
    }
}

int majority__element(std::vector<int>& a)
{
    std::map<int, int> mp;
    for(int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
    }
    for(auto i : mp)
    {
        if(i.second > (a.size()) / 2)
            return i.first;
    }
    return -1;
}

int majority___element(std::vector<int>& a)
{
    int count1 = 0;
    int element;
    for(int i = 0; i < a.size(); i++)
    {
        if(count1 == 0)
        {
            count1 = 1;
            element = a[i];
        }
        else if(a[i] == element)
        {
            count1++;
        }
        else{
            count1--;
        }
    }
    int count2 = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == element)
            count2++;
    }
    if(count2 > (a.size()) / 2)
        return element;
    return -1;
}

// Kadane's Algorithm [used for finding the maximum subarray sum]
long long max_Subarray_Sum(std::vector<int> a)
{
    long long sum = 0;
    long long max = LONG_MIN;
    for(int i = 0; i < a.size(); i++)
    {
        sum = sum + a[i];
        if(sum > max)
        {
            max = sum;
        }
        if(sum < 0)
        {
            sum = 0;
        }
    }
    if(max < 0)
        return 0;
    else
        return max;
}

// Rearrange Array Elements by Sign 
std::vector<int> alternateNumbers(std::vector<int>& a)
{
    std::vector<int> positive;
    std::vector<int> negetive;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] < 0)
            negetive.push_back(a[i]);
        else
            positive.push_back(a[i]);
    }
    
    for(int i = 0; i < (a.size()) / 2; i++)
    {
        a[2 * i] = positive[i];
        a[2 * i + 1] = negetive[i];
    }
    return a;
}

std::vector<int> alternate_Numbers(std::vector<int>& a)
{
    std::vector<int> ans(a.size(), 0);
    int p = 0, n = 1;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] > 0)
        {
            ans[p] = a[i];
            p = p + 2;
        }
        else{
            ans[n] = a[i];
            n = n + 2;
        }
    }
    return ans;
}

std::vector<int> alternate___Numbers(std::vector<int>& a)
{
    std::vector<int> positive, negetive;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] > 0)
            positive.push_back(a[i]);
        else
            negetive.push_back(a[i]);
    }

    if(positive.size() > negetive.size())
    {
        for(int i = 0; i < negetive.size(); i++)
        {
            a[i * 2] = positive[i];
            a[i * 2 + 1] = negetive[i];
        }
        int index = negetive.size() * 2;
        for(int i = positive.size(); i < negetive.size(); i++)
        {
            a[index] = positive[i];
            index++;
        }
    }
    else{
        for(int i = 0; i < positive.size(); i++)
        {
            a[i * 2] = positive[i];
            a[i * 2 + 1] = negetive[i];
        }
        int index = positive.size() * 2;
        for(int i = negetive.size(); i < positive.size(); i++)
        {
            a[index] = negetive[i];
            index++;
        }
    }
    return a;
}

// Next Permutation
std::vector<int> nextGreaterPermutation(std::vector<int> &a) 
{
    // Greatest Scam on Earth (belongs to algorithm.h)
    std::next_permutation(a.begin(), a.end());
    return a;
}

std::vector<int> next_GreaterPermutation(std::vector<int> &a) 
{
    int n = a.size();
    int bp = -1;
    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i] < a[i + 1])
        {
            bp = i;
            break;
        }
    }
    if(bp == -1)
    {
        std::reverse(a.begin(), a.end());
        return a;
    }

    for(int i = n - 1; i > bp; i--)
    {
        if(a[i] > a[bp])
        {
            std::swap(a[i], a[bp]);
            break;
        }
    }

    std::reverse(a.begin() + bp + 1, a.end());

    return a;
}

int main()
{
    
}