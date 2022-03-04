/*
 * https://quera.org/problemset/10330/
 * Author: https://github.com/smh997/
 */
#include <iostream>
#include <math.h>
using namespace std;
#define num long long int
 num park[5003] = {0};
 num block[5003];
 num mod = 1e9 + 7;
 
num power(num a,num b,num n)
{
    num res = 1;
    a %= n;
    while(b)
    {
        if(b&1)
            res = (res * a) % n;
        b >>= 1;
        a = (a * a) % n;
    }
    return res;
}


int main()
{
	int n,k;
	cin >> n >> k;
	for(int x = 0; x < k + 1; x++)
	{
		block[0] = power((num)2, x, mod);
		for(int y = 1; y < x + 1; y++)
			block[y] = (park[y - 1] + park[y + 1]) % mod;
		for(int y = 0; y < x + 1; y++)
			park[y] = block[y];
	}
	num ans = 0;
	for(int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		ans = (ans + park[abs(m)]) % mod;
	}
	cout << ans << endl;
	return 0;
}