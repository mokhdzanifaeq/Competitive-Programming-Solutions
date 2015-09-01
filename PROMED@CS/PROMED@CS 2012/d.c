#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int tcase, i, j, k;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		char input1[1024], input2[1024];
		scanf("%s", input1);
		scanf("%s", input2);
		int len1 = strlen(input1) + 1;
		int len2 = strlen(input2) + 1;
		//utilizing dynamic programming table
		int table[len1][len2];
		memset(table, 0, sizeof(table[0][0]) * len1 * len2);
		for (j = 1; j < len1; ++j) {
			for (k = 1; k < len2; ++k) {
				if (input1[j - 1] == input2[k - 1])
					table[j][k] = table[j][k - 1] + table[j - 1][k] + 1;
				else
					table[j][k] = table[j][k - 1] + table[j - 1][k] - table[j - 1][k -1];
			}
		}
		sprintf(output, "%sCase #%d: %d\n", output, i + 1, (table[--len1][--len2] + 1) % 1000000003);
	}
	printf("\n%s", output);
	return 0;
}