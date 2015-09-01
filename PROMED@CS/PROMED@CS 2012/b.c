#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int tcase, i, j;
	char input[65535], output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		int counter = 1, count = 0;
		scanf(" %[^\n]", input);
		int length = strlen(input);
		if (length < 101 || length > 65534)
			count--;
		else {
			for (j = 0; j < length; ++j) {
				if (input[j] == '0')
					counter = 1;
				else if (counter) {
					counter--;
					count++;
				}
			}
		}
		sprintf(output, "%sCase #%d: %d\n", output, i + 1, count);
	}
	printf("\n%s", output);
	return 0;
}