#include <iostream>
#include <vector>

int f(int n)
{
	std::vector<int> fb(n);
	fb[0] = 0;
	fb[1] = 1;
	for(int i = 2; i < n; i++)
	{
		fb[i] = fb[i - 2] + fb[i - 1];
	}
	return fb[n - 1];
}

/// Naive algorithm for gcd
int gcd(int a, int b)
{
	int m = std::min(a, b);
	int gcd;
	for(int i = m; i > 0; i--)
	{
		if((a % i == 0) && (b % i == 0))
		{
			gcd = i;
			return gcd;
		}
	}
}
/// using Euclid's algorithm
int gcd_eu(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	else{
		return gcd_eu(b, a % b);
	}
}

int main()
{
	/*
	int n = 5;
	for(int i = 1; i <= n; i++){
		std::cout << f(i) << " ";
	}
	*/

	std::cout << gcd_eu(10, 15);

}
