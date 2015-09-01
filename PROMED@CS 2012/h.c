#include <stdio.h>

int vow(char c) {
	return (c == 'a' || c == 'A' \
		|| c == 'e' || c == 'E' \
		|| c == 'i' || c == 'I' \
		|| c == 'o' || c == 'O' \
		|| c == 'u' || c == 'U' \
		);
}

int main(int argc, char const *argv[])
{
	int tcase, i;
	char output[1024] = "";
	scanf("%d%*c", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		char c, temp;
		int str[260] = {0}, j = 0, k = 0, same = 1;
		while ( ( c = getchar() ) != ' ' )
			str[j++] = vow(c);
		while ( ( c = getchar() ) != '\n' )
			if (vow(c) != str[k++])
				same = 0;
		sprintf(output, "%sCase #%d: %s\n", output, i + 1, same ? "same" : "different");
	}
	printf("\n%s", output);
	return 0;
}