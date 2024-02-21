#include <iostream>

void func1(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

void func2(int n)

{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

void func3(int n)
{
    int i, j;
    for(i = 1; i < n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            std::cout << j;
        }
        std::cout << '\n';
    }
}

void func4(int n)
{
    int i, j;
    for(i = 1; i < n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            std::cout << i;
        }
        std::cout << '\n';
    }
}

void func5(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i; j++)
        {   
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

void func6(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n - i; j++)
        {
            std::cout << j;
        }
        std::cout << '\n';
    }
}

void func7(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        // space
        for(j = 0; j < n - i - 1; j++)
        {
            std::cout << " ";
        }
        // starts
        for(j = 0; j < 2 * i + 1; j++)
        {
            std::cout << '*';
        }
        // space
        for(j = 0; j < n - i - 1; j++)
        {
            std::cout << " ";
        }
        std::cout << '\n';
    }
}

void func8(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            std::cout << " ";
        }
        for(int j = 0; j < 2*n - (2*i + 1); j++)
        {
            std::cout << "*";
        }
        for(j = 0; j < i; j++)
        {
            std::cout << " ";
        }
        std::cout << '\n';
    }
}

void func9(int n)
{
    func7(n);
    func8(n);   
}

void func10(int n)
{
    int i, j;
    for(i = 1; i <= 2 * n - 1; i++)
    {   
        int stars = i;
        if(i > n)
        {
            stars = 2 * n  - i;
        }
        for(j = 1; j <= stars; j++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }
    
}

void func11(int n)
{
    int i, j;
    int start = 1;
    for(i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            start = 1;
        }
        else{
            start = 0;
        }
        for(j = 0; j <= i; j++)
        {
            std::cout << start << " ";
            // start = 1 - start;
        }
        std::cout << '\n';
    }
}

void func12(int n)
{
    int i, j;
    int space = 2 * n - 2;
    for(i = 1; i <= n; i++)
    {
        // Number
        for(j = 1; j <= i; j++)
        {
            std::cout << j;
        }

        // space
        for(j = 1; j <= space; j++)
        {
            std::cout << " ";
        }

        // Number
        for(j = i; j >= 1; j--)
        {
            std::cout << j;
        }
        std::cout << '\n';
        space = space - 2;
    }
}

void func13(int n)
{
    int i, j;
    int num = 1;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            std::cout << num << " ";
            num = num + 1;
        }
        std::cout << '\n';
    }
}

void func14(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        char ch = 'A';
        for(j = 1; j <= i; j++)
        {
            std::cout << ch++;
        }
        std::cout << '\n';
    }
}

void func15(int n)
{
    int i, j;
    for(i = n; i >= 1; i--)
    {
        char ch = 'A';
        for(j = 1; j <= i; j++)
        {
            std::cout << ch++;
        }
        std::cout << '\n';
    }
}

void func16(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for(j = 0; j <= i; j++)
        {
            std::cout << ch;
        }
        std::cout << '\n';
    }
}

void func17(int n)
{
    int i, j;
    for(int i = 0; i < n; i++)
    {
        // Space
        for(j = 0; j < n - i - 1; j++)
        {
            std::cout << " ";
        }

        // Alphabets
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for(j = 1; j <= 2 * i + 1; j++)
        {
            std::cout << ch;
            if(j <= breakpoint)
            {
                ch++;
            }
            else{
                ch--;
            }
        }

        // Space
        for(j = 0; j < n - i - 1; j++)
        {
            std::cout << " ";
        }
        std::cout << '\n';
    }
}

void func18(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(char ch = 'E' - i; ch <= 'E'; ch++)
        {
            std::cout << ch << " ";
        }
        std::cout << '\n';
    }
}

void fun(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(char ch = 'A' + i; ch <= 'E'; ch++)
        {
            std::cout << ch << " ";
        }
        std::cout << '\n';
    }

    /*
    A B C D E
    B C D E
    C D E
    D E
    E
    */
}

void func19(int n)
{
    int i, j;

    // First half
    int inital_space = 0;
    for(i = 0; i < n; i++)
    {
        // stars
        for(j = 1; j <= n - i; j++)
        {
            std::cout << "*";
        }
        // spaces
        for(j = 0; j < inital_space; j++)
        {
            std::cout << " ";
        }
        // stars
        for(j = 1; j <= n - i; j++)
        {
            std::cout << "*";
        }
        inital_space = inital_space + 2;
        std::cout << '\n';
    }

    // Second Half
    inital_space = 2 * n - 2;
    for(i = 1; i <= n; i++)
    {
        // stars
        for(j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        // spaces
        for(j = 0; j < inital_space; j++)
        {
            std::cout << " ";
        }
        // stars
        for(j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        inital_space = inital_space - 2;
        std::cout << '\n';
    }
}

void func20(int n)
{
    int i, j;
    int inital_space = 2 * n - 2;
    for(i = 1; i <= 2 * n - 1; i++)
    {   
        int stars = i;
        if(i > n)
        {
            stars = 2 * n - i;
        }
        // stars
        for(j = 1; j <= stars; j++)
        {
            std::cout << "*";
        }
        // space
        for(j = 1; j <= inital_space; j++)
        {
            std::cout << " ";
        }
        // stars
        for(j = 1; j <= stars; j++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
        
        if(i < n)
        {
            inital_space = inital_space - 2;
        }
        else{
            inital_space = inital_space + 2;
        }
    }
}

void func21(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                std::cout << '*';
            }
            else{
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}

void func22(int n)
{
    int i, j;
    for(i = 0; i < 2 * n - 1; i++)
    {
        for(j = 0; j < 2 * n - 1; j++)
        {
            int top, left, right, down;
            top = i;
            left = j;
            right = (2 * n - 1) - 1 - j;
            down = (2 * n - 1) - 1 - i;
            std::cout << n - std::min(std::min(top, down), std::min(left, right)) << " ";
        }
        std::cout << '\n';
    }
}

int main(void)
{
    int t, i;
    std::cin >> t;
    for(i = 0; i < t; i++)
    {
        int n; 
        std::cin >> n;
        func22(n);
    }
}