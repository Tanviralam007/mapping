#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>

void selection_sort(std::vector<int>& arr)
{
    for(int i = 0; i <= arr.size() - 2; i++)
    {
        int min = i;
        for(int j = i; j <= arr.size() - 1; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        std::swap(arr[min], arr[i]);
    }
}

// O(n)
void bubble_sort(std::vector<int>& arr)
{
    for(int i = arr.size() - 1; i >= 1; i--)
    {
        bool is_swaped = false;
        for(int j = 0; j <= i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                is_swaped = true;
            }
        }
        if(is_swaped == false) break;
        // else std::cout << "runn\n";
    }
}

void insertion_sort(std::vector<int>& arr)
{
    for(int i = 0; i <= arr.size() - 1; i++)
    {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j])
        {
            std::swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}


/// Merge Sort
void merge(std::vector<int>& arr, int low, int mid, int high)
{
    std::vector<int> temp;
    int left = low;
    int right = mid + 1;
    
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copying temp array to main array
    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    
}

void merge_sort(std::vector<int>& arr, int low, int high)
{
    if(low == high)
    {
        return;
    }
    else
    {
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


// Quick Sort
int partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j)
    {
    while(arr[i] <= pivot && i <= high - 1)
        i++;
    while(arr[j] > pivot && j >= low - 1)
        j--;

    if(i < j)
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);
    return j;
}

void quick_sort(std::vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}


int main(int argc, char** argv)
{   
    
 
    return 0;
}