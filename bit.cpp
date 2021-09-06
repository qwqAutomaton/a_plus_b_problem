#include <iostream>
int C[5], A[5];
inline int lowbit(int x) { return x & (-x); }
int n;
void add(int x, int v)
{
	while (x <= n)
	{
		C[x] += v;
		x += lowbit(x);
	}
}
int query(int x)
{
	int ans = 0;
	while (x)
	{
		ans += C[x];
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
	n = 2;
	for (int i = 1; i <= n; i++)
		std::cin >> A[i];
	for (int i = 1; i <= n; i++)
		add(i, A[i]);
	std::cout << query(2);
	return 0;
}

