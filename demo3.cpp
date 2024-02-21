#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <cstring>
#include <string>
#include <vector>

void problem_set1(int i, int n)
{
    if(i > n)
    {
        return;
    }
    else{
        std::cout << "marium" << std::endl;
        problem_set1(i + 1, n);
    }
}

void problem_set2(int i, int n)
{
    if(i > n){
        return;
    }
    else{
        std::cout << i << " ";
        problem_set2(i + 1, n);
    }
}

void problem_set3(int i, int n)
{
    if(i < 1)
    {
        return;
    }
    else{
        std::cout << i << " ";
        problem_set3(i - 1, n);
    }
}

void problem_set4(int i, int n)
{
    if(i < 1)
    {
        return;
    }
    else{
        problem_set4(i - 1, n);
        std::cout << i << " ";
    }
}

void problem_set5(int i, int n)
{
    if(i > n)
    {
        return;
    }
    else{
        problem_set5(i + 1, n);
        std::cout << i << " ";
    }
}

/// Functional sum
int problem_set6(int n)
{
    if(n < 0)
    {
        return 0;
    }
    else{
        return n + problem_set6(n - 1);
    }
}

// Parameterized sum
void problem_set7(int i, int sum)
{
    if(i < 1)
    {
        std::cout << sum;
        return;
    }
    else{
        problem_set7(i - 1, sum + i);
    }
}

// Factorial
int problem_set8(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else{
        return n * problem_set8(n - 1);
    }
}

// reverse
void problem_set9(int* arr, int l, int r)
{
    if(l >= r)
        return;
    else
    {
        std::swap(arr[l], arr[r]);
        problem_set9(arr, l + 1, r - 1);
    }
}

void problem_set10(int* arr, int i, int n)
{
    if(i >= n / 2)
        return;
    else{
        std::swap(arr[i], arr[n - i - 1]);
        problem_set10(arr, i + 1, n);
    }
}


// Palindrome
bool problem_set11(char* ch, int i)
{
    if(i >= std::strlen(ch) / 2) 
        return true;
    if(ch[i] != ch[std::strlen(ch) - i - 1]) 
        return false;
    problem_set11(ch, i + 1);
}

// Fibonacci -- Without recursion
void f(int n)
{
    std::vector<int> fb(n);
    fb[0] = 0;
    fb[1] = 1;
    for(int i = 2; i < fb.size(); i++)
        fb[i] = fb[i - 2] + fb[i - 1];
}

// Fibonacci -- With recursion
int fib(int n)
{
    if(n == 0 || n == 1) return n;
    else return fib(n - 1) + fib(n - 2);
}


// Driver Code
signed main(int argc, char** argv, char** envp)
{
    
}