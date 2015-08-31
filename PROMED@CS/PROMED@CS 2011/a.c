#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int tcase, length, i = 0, j =0;
	char input[1024], output[1024] = "";
	scanf("%d", &tcase);
	for (;i < tcase; i++)
	{
		sprintf(output, "%s%s", output, "\n\n");
		scanf(" %[^\n]", input);
		length = strlen(input) - 1;
		for (j = 0; j < length; ++j)
			sprintf(output, "%s%s", output, input[j] == ' ' ? "\n" : "*");
	}
	printf("%s\n", output);
	return 0;
}