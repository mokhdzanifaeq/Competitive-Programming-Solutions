#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int tcase, i;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		int cx, cy, tx, ty, min[2];
		double temp, dist = 28284.27;
		scanf("%d %d", &cx, &cy);
		while(1) {
			scanf("%d %d", &tx, &ty);
			if (tx == 10001 && ty == 10001)
				break;
			temp = sqrt( pow(cx - tx, 2) + pow(cy - ty, 2) );
			if (temp < dist) {
				dist = temp;
				min[0] = tx;
				min[1] = ty;
			} else if (temp == dist) {
				if ( ty > min[1] || (ty == min[1] && tx > min[0]) ) {
					min[0] = tx;
					min[1] = ty;
				}
			}
		}
		sprintf(output, "%sCase %d: %d %d\n", output, i + 1, min[0], min[1]);
	}
	printf("\n%s", output);
	return 0;
}