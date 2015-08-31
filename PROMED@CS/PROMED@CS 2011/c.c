#include <stdio.h>

int inMap(int value, int container[]) {
	int i = 0;
	for (; container[i] != 0; i++)
		if (value == container[i])
			return i;
	return -1;
}

int main(int argc, char const *argv[])
{
	int tcase, x, y, i, j, k, l;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		int key = 0, sum = 0, max = 0, xMap, yMap;
		int nodes[100] = {0}, map[100][100] = {0};
		while (1) {
			scanf("%d %d", &x, &y);
			if (!x && !y) break;
			xMap = inMap(x, nodes);
			yMap = inMap(y, nodes);
			if (xMap == -1) {
				nodes[key] = x;
				x = key++;
			} else
				x = xMap;
			if (yMap == -1) {
				nodes[key] = y;
				y = key++;
			} else
				y = yMap;
			map[x][y] = 1;
		}
		//utilizing floyd-warshall algorithm
		for (j = 0; j < key; j++) {
			for (k = 0; k < key; k++) {
				for (l = 0; l < key; l++) {
						if (map[k][l] == 0 && k != l)
							map[k][l] = 9999;
						if (map[k][j] + map[j][l] < map[k][l])
							map[k][l] = map[k][j] + map[j][l];
				}
			}
		}
		for (j = 0; j < key; j++)
			for (k = 0; k < key; k++)
				sum += map[j][k];
		sprintf(output, "%sCase %d: %.2f degrees\n", output, i + 1, (float)sum/key);
	}
	printf("\n\n%s", output);
	return 0;
}