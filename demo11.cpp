// Moderately Hard
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#define INT_MIN -2147483647

/// pascal triangle
//--> type-1: given row and column, find the element at that plece --> O(r)
int nCr(int n, int r)
{
    if(r > n - r)
        r = n - r;
    
    long long result = 1;
    for(int i = 0; i < r; i++)
    {
        result = result * (n - i);
        result = result / (i + 1);
    }
    return result;
}

// --> type 2: print any nth row of a pascel
//_> t 1:
void nthrow(int n)
{
    int a = 1;
    std::cout << a << " ";
    for(int i = 1; i <= n; i++){
        std::cout << nCr(n, i) << " ";
    }
}
// _> t 2:
std::vector<long long> nth_row_generate(int row)
{
    long long ans = 1;
    std::vector<long long> ans_row;
    ans_row.push_back(1);
    for(int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ans_row.push_back(ans);
    }
    return ans_row;
}

// type 3: print the entire pascel (brute force)
std::vector<std::vector<long long>> pascel_triangle(int nth)
{
    std::vector<std::vector<long long>> ans;
    for(int row = 0; row < nth; row++)
    {
        std::vector<long long> temp;
        for(int col = 0; col <= row; col++)
        {
            temp.push_back(nCr(row, col));
        }
        ans.push_back(temp);
    }
    return ans;
}
// optimal solve
std::vector<std::vector<long long>> pasceltriangle(int nth)
{
    std::vector<std::vector<long long>> ans;
    for(int i = 1; i <= nth; i++)
        ans.push_back(nth_row_generate(i));
    return ans;

    /*
    std::vector<std::vector<long long>> a = pasceltriangle(n);
    for(auto& it: a){
        for(auto& element : it){
            std::cout << element << " ";
        }
        std::cout << '\n';
    }
    */
}

// Majority Element --------
// (type 2: greater then (>) n / 3 times, where n = num of elements in the list
std::vector<int> majority_element(std::vector<int>& a) // tc -> O(n^2)
{
    std::vector<int> li;
    for(int i = 0; i < a.size(); i++)
    {
        if(li.size() == 0 || li[0] != a[i])
        {
            int count = 0;
            for(int j = 0; j < a.size(); j++)
            {
                if(a[j] == a[i])
                    count++;
            }
            if(count > (a.size()) / 3)
                li.push_back(a[i]);
        }
        if(li.size() == 2)
            break;
    }
    return li;
}
// better sol
std::vector<int> majorityElement(std::vector<int>& v) 
{
	std::map<int, int> mp;
    std::vector<int> ls;
    int min = (int)(v.size()) / 3 + 1;
    for(int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;
        if(mp[v[i]] == min)
            ls.push_back(v[i]);
        if(ls.size() == 2)
            break;
    }
    return ls;
}

// optimal solve
std::vector<int> majority__element(std::vector<int>& v)
{
    std::vector<int> lst;
	int count1 = 0;
	int count2 = 0;
	int element1 = INT_MIN;
	int element2 = INT_MIN;
	int n = v.size();
	int min = (int)n / 3 + 1;

	for(int i = 0; i < n; i++)
	{
		if(count1 == 0 && element2 != v[i])
		{
			count1 = 1;
			element1 = v[i];
		}
		else if(count2 == 0 && element1 != v[i])
		{
			count2 = 1;
			element2 = v[i];
		}
		else if(v[i] == element1)
			count1++;
		else if(v[i] == element2)
			count2++;
		else
			count1--, count2--;
	}

	count1 = 0, count2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(v[i] == element1)
			count1++;
		if(v[i] == element2)
			count2++;
	}
	if(count1 >= min) 
		lst.push_back(element1);
	if(count2 >= min)
		lst.push_back(element2);
	return lst;
}

// 3 Sum - brute force -------
std::vector<std::vector<int>> triplet(std::vector<int>& arr, int n)
{
    std::set<std::vector<int>> st;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    std::vector<int> temp = {arr[i], arr[j], arr[k]};
                    std::sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    std::vector<std::vector<int>> ls(st.begin(), st.end());
    return ls;
}

// better solve (hashing)
std::vector<std::vector<int>> Triplet(std::vector<int>& arr, int n)
{
    std::set<std::vector<int>> st;
    for(int i = 0; i < n; i++)
    {
        std::set<int> hashset;
        for(int j = i + 1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);
            if(hashset.find(third) != hashset.end())
            {
                std::vector<int> temp = {arr[i], arr[j], third};
                std::sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    std::vector<std::vector<int>> ls(st.begin(), st.end());
    return ls;
}

// extreme optimal --> using 2-pointer method
std::vector<std::vector<int>> triplet_ex(std::vector<int>& arr, int n)
{
    std::vector<std::vector<int>> ans;
    std::sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;

        while(j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum > 0){
                j++;
            }
            else if(sum < 0){
                k--;
            }
            else{
                std::vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                while(j < k && arr[j] == arr[j - 1])
                    j++;
                while(j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

// Four sum -----
// B force
std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    int n = nums.size();
    std::set<std::vector<int>> st;
    for(int i = 0; i < n - 3; i++)
    {
        for(int j = i + 1; j < n - 2; j++)
        {
            for(int k = j + 1; k < n - 1; k++)
            {
                for(int l = 0; l < n; l++)
                {
                    long long sum;
                    sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target)
                    {
                        std::vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        std::sort(temp.begin(), temp.end());
                        st.insert(temp);
                    } 
                }
            }
        }
    }
    std::vector<std::vector<int>> ans(st.begin(), st.end());
    return ans;
}

// better
std::vector<std::vector<int>> four_Sum(std::vector<int>&nums, int target) {
    int n = nums.size();
    std::set<std::vector<long long>> st;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            std::set<long long> hashset;
            for(int k = j + 1; k < n; k++)
            {
                long long fourth = target - (nums[i] + nums[j] + nums[k]);
                if(hashset.find(fourth) != hashset.end())
                {
                    std::vector<long long> temp = {nums[i], nums[j], nums[k], fourth};
                    std::sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }

    std::vector<std::vector<int>> ans(st.begin(), st.end());
    return ans;
}

// most optimal
std::vector<std::vector<int>> four__Sum(std::vector<int> &nums, int target)
{
    int n = nums.size();
    std::vector<std::vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        for(int j = i + 1; j < n; j++)
        {
            if(j != (i + 1) && nums[j] == nums[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l)
            {
                long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                if(sum < target)
                    k++;
                else if(sum > target)
                    l--;
                else if(sum == target){
                    std::vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    
                    while(k < l && nums[k] == nums[k - 1])
                        k++;
                    while(k < l && nums[l] == nums[l + 1])
                        l--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    std::vector<int> a = {1, 2, 1, 0, 1};
    std::vector<std::vector<int>> output = four__Sum(a, 5);
    for(auto& i : output)
    {
        for(auto& a : i){
            std::cout << a << " ";
        }
        std::cout << '\n';
    }
    
    return 0;
}