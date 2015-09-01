#include <stdio.h>
#include <math.h>
#define OUT(a, b) sprintf(out, "%d %c %d %c", a + 1, uni[a].state, b + 1, uni[b].state)

typedef struct {
    int x, y;
    char state;
} univ;

int main(int argc, char const *argv[]) {
	int tcase, i;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		int unum, j, k;
		float min = 0;
		char out[1024];
		scanf("%d", &unum);
		univ uni[unum];
		for(j = 0; j < unum; j++) {
			scanf("%d %d %c", &uni[j].x, &uni[j].y, &uni[j].state);
			int s1 = uni[j].state % 65;
			for (k = 0; k < j; ++k) {
				if (k == j)
					continue;
				float dist = sqrt( pow(uni[j].x - uni[k].x, 2) + pow(uni[j].y - uni[k].y, 2) );
				if( uni[j].state != uni[k].state && (dist < min || min == 0) ) {
					min = dist;
					int s2 = uni[k].state % 65;
					s1 < s2 ? OUT(j, k) : OUT(k, j);
				}
			}
		}
		sprintf(output, "%sCase %d: %s\n", output, i + 1, min ? out : "NO SOLUTION");
	}
	printf("\n%s", output);
	return 0;
}