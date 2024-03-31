#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#define INT_MIN -2147483647

// Subarray's with XOR 'k'
// brute
int subarraysWithSumK(std::vector <int> a, int b) {
    int n = a.size();
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int x_or = 0;
            for(int k = i; k < j; k++)
            {
                x_or = x_or ^ a[k];
                if(x_or == b){
                    count++;
                }
            }
        }
    }
    return count;
}

// better solved
int subarraysWithSum_K(std::vector <int> a, int b) {
    int n = a.size();
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int x_or = 0;
        for(int j = i; j < n; j++)
        {
            x_or = x_or ^ a[j];
            if(x_or == b){
                count++;
            }
        }
    }
    return count;
}

// optimal solved
int subarraysWithSum__k(std::vector<int>& a, int b) {
    int x_or = 0;
    std::map<int, int> mp;
    mp[x_or]++;
    int count = 0;
    for(int i = 0; i < a.size(); i++)
    {
        x_or = x_or ^ a[i];
        int x = x_or ^ b;
        count = count + mp[x];
        mp[x_or]++;
    }
    return count;
}

// marge overlapping intervals
// brute force
std::vector<std::vector<int>> mergeOverlappingIntervals(std::vector<std::vector<int>>& arr){
    int n = arr.size();
    std::sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> ans;
    for(int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j][0] <= end){
                end = std::max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// most optimal
std::vector<std::vector<int>> merge_Overlapping_Intervals(std::vector<std::vector<int>>& arr){
    int n = arr.size();
    std::sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> ans;
    for(int i = 0; i < n; i++)
    {
        if(ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = std::max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
    /*
    std::vector<std::vector<int>> intervals = {
        {1, 3}, 
        {2, 6}, 
        {8, 10}, 
        {15, 18},
        {15, 17}
    };
    std::vector<std::vector<int>> mergedIntervals = merge_Overlapping_Intervals(intervals);
    std::cout << "Merged Intervals:" << std::endl;
    for (const auto& interval : mergedIntervals) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    */
}

// merge two subarrays without extra spaces
// brute force approach 
void mergeTwoSortedArraysWithoutExtraSpace(std::vector<int> &a, std::vector<int> &b){
	int n = a.size();
    int m = b.size();
    std::vector<int> new_arr;
    int left = 0; 
    int right = 0;

    while(left < n && right < m)
    {
        if(a[left] <= b[right])
        {
            new_arr.push_back(a[left]);
            left++;
        }
        else{
            new_arr.push_back(b[right]);
            right++;
        }
    }

    while(left < n) 
        new_arr.push_back(a[left++]);
    while(right < m)
        new_arr.push_back(b[right++]);
	
    for(int i = 0; i < new_arr.size(); i++)
    {
        if(i < n)
            a[i] = new_arr[i];
        else
            b[i - n] = new_arr[i];
    }
    
    for(int i : a) 
        std::cout << i << " ";
    std::cout << '\n';
    for(int j : b) 
        std::cout << j << " ";
}

// optimal sol-- 1
void mergeTwoSortedArraysWithoutExtra_Space(std::vector<int> &a, std::vector<int> &b){
    int n = a.size();
    int m = b.size();
    int left = n - 1;
    int right = 0;
    while(left >= 0 && right < m){
        if(a[left] >= b[right])
        {
            std::swap(a[left], b[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for(auto& i : a)
        std::cout << i << " ";
    std::cout << std::endl;
    for(auto& i : b)
        std::cout << i << " ";
}

int main(void)
{
    std::vector<int> a = {1, 4, 5, 7} ;
    std::vector<int> b = {2, 3, 6};
    mergeTwoSortedArraysWithoutExtra_Space(a, b);
    
    return 0;
}