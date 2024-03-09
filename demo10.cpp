#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#define INT_MIN -2147483647

// Leaders in an array
std::vector<int> superiorElements(std::vector<int>& a)
{
    std::vector<int> ans;
    for(int i = 0; i < a.size(); i++)
    {
        int l = 1;
        for(int j = i + 1; j < a.size(); j++)
        {
            if(a[j] > a[i])
            {
                l = 0;
                break;
            }
        }
        if(l == 1)
            ans.push_back(a[i]);
    }
    return ans;
}

std::vector<int> superior_Elements(std::vector<int>& a)
{
    std::vector<int> ans;
    int maximum = INT_MIN;
    for(int i = a.size() - 1; i >= 0; i--)
    {
        if(a[i] > maximum)
            ans.push_back(a[i]);
        maximum = std::max(maximum, a[i]);
    }
    return ans;
}

//  Longest Successive Elements - optimal O(n + n log n)
int longestSuccessiveElements(std::vector<int>&a) 
{
    std::sort(a.begin(), a.end());
    int longest_count = 1;
    int count = 0;
    int last_smallest = INT_MIN;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] - 1 == last_smallest)
        {
            count++;
            last_smallest = a[i];
        }
        else if(a[i] != last_smallest)
        {
            count = 1;
            last_smallest = a[i];
        }
        longest_count = std::max(longest_count, count);
    }
    return longest_count;
}

// Set Matrix zero B 
std::vector<std::vector<int>> zeroMatrix(std::vector<std::vector<int>> &matrix, int n, int m) {
	std::vector<int> col(m, 0), row(n, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
/*
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 1}
    };
    matrix = zeroMatrix(matrix, 4, 4);
    std::cout << "output matrix: " << '\n';
    for(const auto& row : matrix)
    {
        for(auto& val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
*/
}

// Op
std::vector<std::vector<int>> zeromatrix(std::vector<std::vector<int>> & matrix, int n, int m)
{
    int col0 = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 0)
            {
                // mark i-th row
                matrix[i][0] = 0;
                // mark j-th col
                if(j != 0)
                {
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    //  Mark with 0 from (1,1) to (n-1, m-1):
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(matrix[i][j] != 0)
            {
                // check the col and row
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] == 0;
                }
            }
        }
    }

    // Finally mark the 1st col & then 1st row:
    if(matrix[0][0] == 0){
        for(int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }
    if(col0 == 0){
        for(int i = 0; i < n; i++){
            matrix[i][0] = 0;
        }
    }
    return matrix;
}

// rotate matrix in 90 degree
void rotateMatrix(std::vector<std::vector<int>> &mat){
    int n = mat.size();
	std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans[j][n - 1 - i] = mat[i][j];
        }
    }

	for(const auto& row : ans)
    {
        for(auto& val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    /*
    expected output:
    13 9 5 1
    14 10 6 2
    15 11 7 3
    16 12 8 4
    */
}

void rotate_matrix(std::vector<std::vector<int>>& mat)
{
    int n = mat.size();
    // transpose the matrix
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            std::swap(mat[i][j], mat[j][i]);
        }
    }

    // reverse each row of the matrix
    for(int i = 0; i < n; i++)
    {
        std::reverse(mat[i].begin(), mat[i].end());
    }
}

// spiral matrix
std::vector<int> spiralMatrix(std::vector<std::vector<int>>&MATRIX) {
    int n = MATRIX.size();
    int m = MATRIX[0].size();
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    std::vector<int> ans;
    while(top <= bottom && left <= right)
    {
        // left to right
        for(int i = left; i <= right; i++)
        {
            ans.push_back(MATRIX[top][i]);
        }
        top++;

        for(int i = top; i <= bottom; i++)
        {
            ans.push_back(MATRIX[i][right]);
        }
        right--;

        if(top <= bottom){
            for(int i = right; i >= left; i--)
            {
                ans.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }

        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            {
                ans.push_back(MATRIX[i][left]);
            }
            left++;
        }
    }
    return ans;
    // 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
}

// number pf subarrays with sum k _better_ near about O(n^2)
int findAllSubarraysWithGivenSum(std::vector<int>& arr, int k) {
    int c = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < arr.size(); j++)
        {
            sum = sum + arr[j];
            if(sum == k)
                c++;
        }
    }
    return c;
}

// using prefix sum, map
int findAllSubarraysWithGiven_Sum(std::vector<int>& arr, int k){
    std::unordered_map<int, int> mp;
    mp[0] = 1;
    int p = 0, c = 0, remove;
    for(int i = 0; i < arr.size(); i++)
    {
        p = p + arr[i];
        remove = p - k;
        c = c + mp[remove];
        mp[p] = mp[p] + 1;
    }   
    return c;
    // 1, 2, 3, -3, 1, 1, 1, 4, 2, -3 --> for k = 3 --> 8 sub-arrays
}

int main(void)
{
    
}