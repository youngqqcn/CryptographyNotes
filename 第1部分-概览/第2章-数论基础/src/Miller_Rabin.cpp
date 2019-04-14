// Miller_Rabin.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"

#include <iostream>
using namespace std;
#define rd(x) (rand()%(x))
typedef unsigned long long ll;

#if 0
ll pow_mod(ll a, ll b, ll r)
{
	ll ans = 1, buff = a;
	while (b)
	{
		if (b & 1)
			ans = (ans*buff) % r;
		buff = (buff*buff) % r;
		b >>= 1;
	}
	return ans;
}
#endif

long long mod_mul(long long a, long long b, long long n)
{
	long long res = 0;
	while (b) 
	{
		if (b & 1) res = (res + a) % n;
		a = (a + a) % n;
		b >>= 1;
	}
	return res;
}

long long pow_mod(long long a, long long b, long long n) 
{
	long long res = 1;
	while (b)
	{
		if (b & 1) res = mod_mul(res, a, n);
		a = mod_mul(a, a, n);
		b >>= 1;
	}
	return res;
}

bool Mille_Rabin_Test(ll n, ll a, ll d)
{
	if (n == 2) return true;
	if (n == a) return false;
	if (!(n & 1)) return false;
	while (!(d & 1)) d >>= 1;
	ll t = pow_mod(a, d, n);
	while (d != n - 1 && t != n - 1 && t != 1) 
	{
		t = t*t%n;//������ܷ�ֹ����İ취����Ӧ������Ϊ10^18�η���
		d <<= 1;
	}
	return t == n - 1 || (d & 1) == 1;//Ҫôt�ܱ��n-1��Ҫôһ��ʼt�͵���1
}

bool isprime(ll n)
{
	int a[] = { 2,3,5,7 };//�����Լ�����[2,N-1]���ڵ������rand����%��n-2��+2
	for (int i = 0; i <= 3; ++i) 
	{
		if (n == a[i]) return true;
		if (!Mille_Rabin_Test(n, a[i], n - 1)) return false;
	}
	return true;
}

int main()
{
	int t, ans = 0;
	ll N;
	//for (cin >> t; t; t--) 
	{
		cin >> N;
		cout << ((isprime(N)) ? "Yes" : "No") << endl;
	}
	system("pause");
	return 0;
}


