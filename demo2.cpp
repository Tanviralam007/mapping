#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

void digit_extraction(int x)
{
    int count = 0;
    while(x > 0)
    {
        int last_digit = x % 10;
        count++;
        x = x / 10;
    }
    std::cout << count;
}

void reverse_number(int n)
{
    int rev_num = 0;
    while(n > 0)
    {
        int last_digit = n % 10;
        rev_num = (rev_num * 10) + last_digit;
        n = n / 10;
    }
    std::cout << rev_num;
}

void palindrom(int n)
{
    int rev_num = 0;
    int replica = n;
    while(n > 0)
    {
        int last_digit = n % 10;
        rev_num = (rev_num * 10) + last_digit;
        n = n / 10;
    }
    if(rev_num == replica) std::cout << "true";
    else std::cout << "false";
    
}

void amstrong_number(int n)
{
    int sum = 0;
    int replica = n;
    while(n > 0)
    {
        int last_digit = n % 10;
        sum = sum + std::pow(last_digit, 3);
        n = n / 10; 
    }
    if(sum == replica) std::cout << "true";
    else std::cout << "false";
}

void print_all_division(int n)
{
    // int i;
    // for(i = 1; i <= n; i++)
    // {
    //     if(n % i == 0)
    //     {
    //         std::cout << i << " ";
    //     }
    // }

    std::vector<int> ls;
    for(int i = 1; i <= std::sqrt(n); i++) // instead of std::sqrt(n), we can use i * i <= n, i.e. 6 * 6 <= 36
    {
        if(n % i == 0)
        {
            ls.push_back(i);
            
            if((n / i) != i)
            {
                ls.push_back(n / i);
            }
        }
    }
    std::sort(ls.begin(), ls.end());
    for(auto it : ls)
    {
        std::cout << it << " ";
    }
}

void prime_number_check(int n)
{
    int count = 0; 
    for (int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            count++;
        }
    }
    if(count == 2) std::cout << "p";
    else std::cout << "n";
    
}

int gcd(int a, int b)
{
    int min = std::min(a, b);
    for(int i = min; i >= 1;i--)
    {
        if((a % i == 0) && (b % i == 0)){
            return i;
        }
    }
}

int gcd_eu(int a, int b)
{
    while(a > 0 && b > 0)
    {
        if(a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if(a == 0)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main(void)
{
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
    }
}