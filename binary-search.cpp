#include <iostream>

int check(int cur, int a, int b)
{
	if (cur < a + b)
		return -1;
	if (cur > a + b)
		return 1;
	return 0;
}

int main()
{
	int a, b;
	std::cin >> a >> b;
	int l = -2e9, r = 2e9;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int res = check(mid, a, b);
		if (res < 0)
			l = mid + 1;
		else if (res > 0)
			r = mid - 1;
		else
		{
			std::cout << mid;
			return 0;
		}
	}
	std::cout << "QwQ\n";
	return 0;
}

