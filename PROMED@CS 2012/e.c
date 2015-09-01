#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int tcase, i;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		int width, length[100] = {0}, j = 0, k, l, counter = 1;
		char input[1024], *p, out[1024] = "";
		scanf("%d %[^\n]", &width, input);
		p = strtok(input, " ");
		while (p != NULL) {
			length[j++] = strtol(p, NULL, 10);
			p = strtok(NULL, " ");
		}
		for(k = 0; width; k++) {
			for(l = 0; l < length[k % j]; l++) {
				sprintf(out, "%s%c", out, counter ? '_' : ' ');
				if(!--width)
					break;
			}
			counter = !counter;
		}
		sprintf(output, "%sCase #%d:|%s|\n", output, i + 1, out);
		strcpy(out, "");
	}
	printf("\n%s", output);
	return 0;
}