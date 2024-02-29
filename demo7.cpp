#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define INT_MAX 1e9
// finding the largest number 
int largest_element(std::vector<int>& arr)
{
    int l = arr[0];
    for(int i = 1; i <= arr.size(); i++)
    {
        if(arr[i] > l)
        {
            l = arr[i];
        }
    }
    return l;
}

// finding the second largest
int second_largest(std::vector<int>& arr)
{
    int large = arr[0];
    int s_large = -1;
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > large)
        {
            s_large = large;
            large = arr[i];
        }
        else if(arr[i] < large && arr[i] > s_large)
        {
            s_large = arr[i];
        }
    }
    return s_large;
}

int second_smallest(std::vector<int>& arr)
{
    int small = arr[0];
    int s_small = INT_MAX;
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] < small)
        {
            s_small = small;
            small = arr[i];
        }
        else if(arr[i] != small && arr[i] < s_small)
        {
            s_small = arr[i];
        }
    }
    return s_small;
}

// If an array is sorted
bool is_sorted(std::vector<int>& arr)
{
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Remove duplicate elements and return how many of the elements are unique(brute force)
int remove_duplicate(std::vector<int>& arr)
{
    std::set<int> st;
    for(int i = 0; i < arr.size(); i++)
    {
        st.insert(arr[i]);
    }
    // std::cout << "elements: ";
    // for(auto s : st){
    //     std::cout << s << " ";
    // }
    return st.size();
}

// optimal
int rem_duplicate(std::vector<int>& arr)
{
    int i = 0; 
    for(int j = 1; j < arr.size(); j++)
    {
        if(arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

// rotate left one space
std::vector<int> leftrotate(std::vector<int>& arr)
{
    int temp = arr[0];
    for(int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[arr.size() - 1] = temp;
    return arr;
}

// Brute Force Solution
/*
std::vector<int> leftrotateanypos(std::vector<int>& arr, int d)
{
    d = d % arr.size();
    std::vector<int> temp(d);
    //Copying the first d'th indexed elements to temp[] array
    for(int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    // left shifting
    for(int i = d; i < arr.size(); i++)
    {
        arr[i - d] = arr[i];
    }
    // plugged in the temp[] array elements to the main array
    for(int i = arr.size() - d; i < arr.size(); i++)
    {
        arr[i] = temp[i - (arr.size() - d)];
    }
    return arr;
}
*/

// Optimal Solution for Rotate left at any position
void reverse(std::vector<int>& arr, int start, int end)
{
    while(start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
std::vector<int> leftrotateanypos(std::vector<int>& arr, int d)
{
    reverse(arr, 0, d - 1);
    reverse(arr, d, arr.size() - 1);
    reverse(arr, 0, arr.size() - 1);
    return arr;
    // std::reverse(arr.begin(), arr.begin() + d);
    // std::reverse(arr.begin() + d, arr.end());
    // std::reverse(arr.begin(), arr.end());
    // return arr;
}

// moving non zero elements to left [1 2 3 4 5 0 0 0] --> brute force
std::vector<int> nonzero(std::vector<int>& arr)
{
    // step -- 1
    std::vector<int> n;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] != 0)
        {
            n.push_back(arr[i]);
        }
    }
    
    // step -- 2
    int non_zeros = n.size();
    for(int i = 0; i < non_zeros; i++)
    {
        arr[i] = n[i];
    }

    // step -- 3
    for(int i = non_zeros; i < arr.size(); i++)
    {
        arr[i] = 0;
    }

    return arr;
}
// optimal tc O(n) sc O(1)
std::vector<int> non_zero(std::vector<int>& arr)
{
    int j = -1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == 0)
        {
            j = i; 
            break;
        }
    }
    
    if(j == -1)
    {
        return arr;
    }

    for(int i = j + 1; i < arr.size(); i++)
    {
        if(arr[i] != 0)
        {
            std::swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;

/*
    std::vector<int> vec = {1, 2, 0, 3, 0, 4, 5, 0, 6, 7};
    std::cout << "Before: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << "\n";
    // vec = non_zero(vec);
    std::cout << "After: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << "\n";
*/
}

// union of 2 array's --> brute force
std::vector<int> unionoftwolist(std::vector<int>& a, std::vector<int>& b)
{
    std::set<int> st;
    int n1 = a.size();
    int n2 = b.size();
    
    // inserting unique elements to the set
    for(int i = 0; i < n1; i++)
    {
        st.insert(a[i]);
    }
    for(int i = 0; i < n2; i++)
    {
        st.insert(b[i]);
    }
    // for(int i : st) 
    //     std::cout << i << " ";
    // new array to contain the unique elements;
    std::vector<int> u;
    for(auto it : st)
    {
        u.push_back(it);
    }
    return u;
}

// optimal solve
std::vector<int> union_of_two_list(std::vector<int>& a, std::vector<int>& b)
{
    int num1 = a.size();
    int num2 = b.size();
    int i = 0, j = 0;
    std::vector<int> u;
    while(i < num1 && j < num2)
    {
        if(a[i] <= b[j])
        {
            if(u.empty() || u.back() != a[i])
            {
                u.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if(u.empty() || u.back() != b[j])
            {
                u.push_back(b[j]);
            }
            j++;
        }
    }
    // if one of the array got distorted, then the remaining elements will get inserted
    while(j < num2)
    {
        if(u.empty() || u.back() != b[j])
        {
            u.push_back(b[j]);
        }
        j++;
    }
    while(i < num1)
    {
        if(u.empty() || u.back() != a[i])
        {
            u.push_back(a[i]);
        }
        i++;
    }
    
    return u;
}


// some issues around here -->
std::vector<int> intersectionoftwolist(std::vector<int>& a, std::vector<int>& b)
{
    int num1 = a.size();
    int num2 = b.size();
    std::vector<int> ans;
    std::vector<int> visited(num2, 0);
    for(int i = 0; i < num1; i++)
    {
        for(int j = 0; j < num2; j++)
        {
            if(a[i] == b[j] && visited[j] == 0)
            {
                ans.push_back(a[i]);
                visited[j] = 1;
                break;
            }
            if(b[j] > a[i])
            {
                break;
            }
        }
    }
    return ans;
}

// optimal solution for finding intersection
std::vector<int> intersectionoftwo_list(std::vector<int>& a, std::vector<int>& b)
{
    int num1 = a.size();
    int num2 = b.size();
    int i = 0, j = 0;
    std::vector<int> ans;
    while(i < num1 && j < num2)
    {
        if(a[i] < b[j])
        {
            i++;
        }
        else if(a[i] > b[j])
        {
            j++;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}
int main(void)
{

}