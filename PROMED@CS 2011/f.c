#include <stdio.h>
#include <string.h>
#include <stlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[]) {
	int tcase, i;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		int max = -1, min = 101, gap = 0, j = 0, k, member, num, temp;
		char input[1024], *p;
		scanf("%d %[^\n]", &member, input);
		int mark[member];
		p = strtok(input, " ");
		while (p != NULL) {
			sscanf(p, "%d", &num);
			mark[j++] = num;
			max = max > num ? max : num;
			min = min < num ? min : num;
			p = strtok(NULL, " ");
		}
		qsort(mark, member, sizeof(int), cmpfunc);
		for (j = 0; j < member - 1; j++) {
			k = mark[j + 1] - mark[j];
			gap =  k > gap ? k : gap;
		}
		sprintf(output, "%sClass %d\nMax %d, Min %d, Largest gap %d\n", output, i + 1, max, min, gap);
	}
	printf("\n%s", output);
	return 0;
}