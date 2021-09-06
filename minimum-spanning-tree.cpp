#include <iostream>
#include <algorithm>
struct Edge
{
	int from, to, dis;
	bool operator<(const Edge &e) const { return dis < e.dis; }
} e[10];
int pre[10];
int root(int r) { return pre[r] ^ r ? pre[r] = root(pre[r]) : r; }
int main()
{
	std::cin >> e[1].dis >> e[2].dis;
	for (int i = 1; i <= 4; i++)
		pre[i] = i;
	e[1].from = 1;
	e[1].to = 2;
	e[2].from = 2;
	e[3].to = 3;
	std::sort(e + 1, e + 3);
	int ans = 0;
	for (int i = 1; i <= 2; i++)
	{
		int rx = root(e[i].from), ry = root(e[i].to);
		if (rx ^ ry)
		{
			ans += e[i].dis;
			pre[rx] = ry;
		}
	}
	std::cout << ans;
	return 0;
}

