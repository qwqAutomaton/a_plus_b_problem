#include <iostream>
#include <cstring>

int graph[5][5];

int main()
{
	memset(graph, 0x3f, sizeof(graph));
	int n = 4;
	for (int i = 1; i <= n; i++)
		graph[i][i] = 0;
	std::cin >> graph[1][2] >> graph[2][3];
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j && j != k && i != k)
					graph[i][j] = std::min(graph[i][k] + graph[k][j], graph[i][j]);
	std::cout << graph[1][3];
	return 0;
}

