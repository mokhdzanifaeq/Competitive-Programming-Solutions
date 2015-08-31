#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int tcase, i;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		int max = -1, min = 101, gap = 0, mark[50] = {0}, j = 0, k, member, num, temp;
		char input[1024], *p;
		scanf("%d %[^\n]", &member, input);
		p = strtok(input, " ");
		while (p != NULL) {
			sscanf(p, "%d", &num);
			mark[j++] = num;
			max = max > num ? max : num;
			min = min < num ? min : num;
			p = strtok(NULL, " ");
		}
		//bubble sorting
		for (j = 0; j < member; j++) {
			for (k = 0; k < member - 1; k++) {
				if (mark[k] > mark[k + 1]) {
					temp = mark[k + 1];
					mark[k + 1] = mark[k];
					mark[k] = temp;
				}
			}
		}
		for (j = 0; j < member - 1; j++) {
			k = mark[j + 1] - mark[j];
			gap =  k > gap ? k : gap;
		}
		sprintf(output, "%sClass %d\nMax %d, Min %d, Largest gap %d\n", output, i + 1, max, min, gap);
	}
	printf("\n\n%s", output);
	return 0;
}