// Binary Search Problems 1 --> 27
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define INT_MAX 2147483647

int b_s(std::vector<int>& a, int target)
{
    int l = 0;
    int h = a.size() - 1;
    while(l <= h)
    {
        int m = (l + h) / 2;
        // int m = l + (h - l) / 2;
        if(a[m] == target)
            return m;
        else if(target > a[m])
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

int b_s_rec(std::vector<int>& a, int l, int h, int target)
{
    l = 0;
    h = a.size() - 1;
    if(l > h)
        return -1;
    else{
        int m = (l + h) / 2;
        // int m = l + (h - l) / 2;
        if(a[m] == target)
            return m;
        else if(target > a[m])
            return b_s_rec(a, m + 1, h, target);
        else
            return b_s_rec(a, l, m - 1, target);
    }
}

// Implement to lower bound in 2 ways
int lowerbound(std::vector<int>& a, int target){
    int l = 0;
    int h = a.size() - 1;
    int ans = a.size();
    while(l <= h)
    {
        int mid = l + (h - l) / 2;
        if(a[mid] >= target){
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}
int lower_bound_2(std::vector<int>& a, int target){
    int lb = std::lower_bound(a.begin(), a.end(), target) - a.begin();
    return lb;
}

// Implement upper bound in 2 ways
int upperbound(std::vector<int>& a, int target)
{
    int l = 0;
    int h = a.size() - 1;
    int ans = a.size();
    while(l <= h)
    {
        int mid = l + (h - l) / 2;
        if(a[mid] > target){
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}
int upper_bound_2(std::vector<int>& a, int target){
    int ub = std::upper_bound(a.begin(), a.end(), target) - a.begin();
    return ub;
}

// Floor and Ceil of an array
int find_floor(std::vector<int>& a, int target)
{
    int low = 0;
    int high = a.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(a[mid] <= target){
            ans = a[mid];
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
int find_ceil(std::vector<int>& a, int target)
{
    int low = 0;
    int high = a.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(a[mid] >= target){
            ans = a[mid];
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
std::pair<int, int> getFloorAndCeil(std::vector<int>& a, int n, int x)
{
    int f = find_floor(a, x);
    int c = find_ceil(a, x);
    return {f, c};
}

// First and last occurrences in the array O(n)
std::pair<int, int> first_and_last(std::vector<int>& a, int x)
{
    int first = -1, last = -1;
    for(int i = 0; i < a.size() - 1; i++){
        if(a[i] == x){
            if(first == -1)
                first = i;
            last = i;
        }
    }
    return {first, last};
}
// O(2 * log n)
int lower_bound(std::vector<int>& a, int target){
	int low = 0, high = a.size() - 1, ans = a.size();
	while(low <= high){
		int mid = low + (high - low) / 2;
        // for lower bound arr[mid] >= target
		if(a[mid] >= target){
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return ans;
}
int upper_bound(std::vector<int>& a, int target){
	int low = 0, high = a.size() - 1, ans = a.size();
	while(low <= high){
		int mid = low + (high - low) / 2;
        // for upper bound arr[mid] > target
		if(a[mid] > target){
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return ans;
}
std::pair<int, int> first_And_Last_Position(std::vector<int>& arr, int n, int k)
{
	int l = lower_bound(arr, k);
	if(l == n || arr[l] != k) return {-1, -1};
	int u = upper_bound(arr, k);
	return{l, u - 1};
}
// using only binary search concept
int first_occurrence(std::vector<int>& a, int t)
{
    int low = 0;
    int high = a.size() - 1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] == t){
            first = mid;
            high = mid - 1;
        }
        else if(a[mid] > t){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return first;
}
int last_occurrence(std::vector<int>& a, int t)
{
    int low = 0;
    int high = a.size() - 1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] == t){
            last = mid;
            low = mid + 1;
        }
        else if(a[mid] > t){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return last;
}
std::pair<int, int> first_And_LastPosition(std::vector<int>& arr, int n, int k)
{
	int f = first_occurrence(arr, k);
	if(f == -1) return {-1, -1};
	int l = last_occurrence(arr, k);
	return{f, l};
}
// using only binary search concept finding the number of occurrences of an element
int first_occurrence(std::vector<int>& a, int t)
{
    int low = 0;
    int high = a.size() - 1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] == t){
            first = mid;
            high = mid - 1;
        }
        else if(a[mid] > t){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return first;
}
int last_occurrence(std::vector<int>& a, int t)
{
    int low = 0;
    int high = a.size() - 1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] == t){
            last = mid;
            low = mid + 1;
        }
        else if(a[mid] > t){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return last;
}
std::pair<int, int> firstAndLastPosition(std::vector<int>& arr, int n, int k)
{
	int f = first_occurrence(arr, k);
	if(f == -1) return {-1, -1};
	int l = last_occurrence(arr, k);
	return{f, l};
}
int count(std::vector<int>& arr, int n, int x) {
	std::pair<int, int> count = firstAndLastPosition(arr, n, x);
	if(count.first == -1) return 0;
	else return count.second - count.first + 1;
}

//  Search Element in Rotated Sorted Array - I
int search(std::vector<int>& arr, int n, int k)
{
    int low = 0;
    int high = n - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] == k)
            return mid;

        else if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        else if(arr[mid] <= arr[high]){
            if(arr[mid] <= k && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
//  Search Element in Rotated Sorted Array - II
bool searchInARotatedSortedArrayII(std::vector<int>& A, int k)
{
    int low = 0;
    int high = A.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(A[mid] == k)
            return true;
        if(A[low] == A[mid] && A[mid] == A[high]){
            low++;
            high--;
            continue;
        }

        if(A[low] <= A[mid]){
            if(A[low] <= k && k <= A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        else if(A[mid] <= A[high]){
            if(A[mid] <= k && k <= A[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

// Find Minimum in Rotated Sorted Array
int findMin(std::vector<int>& arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[low] <= arr[mid]){
            ans = std::min(ans, arr[low]);
            low = mid + 1;
        }
        else if(arr[mid] <= arr[high]){
            ans = std::min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

// Find out how many times array has been rotated
int findKRotation(std::vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else if(arr[mid] <= arr[high]){
            if(arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;        
}

//  Single Element in a Sorted Array
int singleNonDuplicate(std::vector<int>& arr)
{
	if(arr.size() == 1){
        return arr[0];
    }
    for(int i = 0; i < arr.size(); i++){
        if(i == 0)
            if(arr[i] != arr[i + 1])
                return arr[i];
        else if(i == arr.size() - 1)
            if(arr[i] != arr[i - 1])
                return arr[i];
        else
            if(arr[i] != arr[i + 1] && arr[i] != arr[i - 1])
                return arr[i];
    }
}
// most optimized
int singleNonDuplicate_(std::vector<int>& arr)
{
    if(arr.size() == 1)
        return arr[0];
    if(arr[0] != arr[1])
        return arr[0];
    if(arr[arr.size() - 1] != arr[arr.size() - 2])
        return arr[arr.size() - 1];
    
    int low = 1;
    int high = arr.size() - 2;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        // getting the pure single element since both the left and right doesn't match
        if(arr[mid] != arr[mid -1] && arr[mid] != arr[mid + 1]) 
            return arr[mid];
        // now the eleminate of left half
        if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0) && arr[mid] == arr[mid + 1])
            low = mid + 1;
        // now eleminate the right half
        else 
            high = mid - 1;
    }
    return -1;
}

// Finding the peak element from an sorted list
int findPeakElement(std::vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
            return i; // for index
    }
    return -1;
}
// more optimized
int find_PeakElement(std::vector<int> &arr) 
{
    int n = arr.size();
    if(n == 1)
        return 0;
    if(arr[0] > arr[1])
        return 0;
    if(arr[n - 1] > arr[n - 2])
        return n - 1;
    int low = 1;
    int high = n - 2;
    while(low <= high){
        int mid = low + (high - low) / 2;
        // pick element will be like  __ < mid > __
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if(arr[mid] > arr[mid - 1])
            low = mid + 1;
        else if(arr[mid] > arr[mid + 1])
            high = mid - 1;
        // if there are two peak element in the array
        else
            low = mid + 1;
    }
    return -1;
}

// Square Root of a number - Using Binary Search Concept
int floorSqrt(int n)
{
    int low = 0;
    int high = n;
    int ans = 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(std::pow(mid, 2) <= n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

// Find the Nth root of an Integer - Using Binary Search Concept
int func(int mid, int n, int m){
    long long ans = 1;
    for(int i = 0; i <= n; i++){
        // return 2 if > m
        ans = ans * mid;
        if(ans > m)
            return 2;
    }
    // return 1 if == m
    if(ans == m) return 1;
    else return 0; // return 0 if < m
}
int NthRoot(int n, int m) 
{
    int low = 0;
    int high = m;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int midx = func(mid, n, m);
        if(midx == 1)
            return mid;
        else if(midx == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main(){
    
    
}