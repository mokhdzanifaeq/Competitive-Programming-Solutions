#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int tcase, i, j;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		int member, adult = 0, child = 0, old = 0;
		char input[1024], *p;
		scanf("%d %[^\n]", &member, input);
		int age[member];
		p = strtok(input, " ");
		for (j = 0; j < member; j++) {
			int age = strtol(p, NULL, 10);
			if (age > 59)
				old++;
			else if (age > 11)
				adult++;
			else
				child++;
			p = strtok(NULL, " ");
		}
		int voucher = strtol(p, NULL, 10);
		int price = ( old + child - (adult < voucher ? adult : voucher) ) * 110 + adult * 140;
		sprintf(output, "%sCase #%d: RM%.2f\n", output, i + 1, (float)price);
	}
	printf("\n%s", output);
	return 0;
}