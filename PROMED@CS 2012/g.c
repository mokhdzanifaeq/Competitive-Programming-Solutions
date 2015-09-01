#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int tcase, i;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		int num, j = 0, odd = 0, even = 0;
		scanf("%d", &num);
		num = pow(num, 3);
		while ( num && (!odd || !even) ) {
			int now = num % 10;
			now & 1 ? odd++ : even++;
			num /= 10;
		}
		sprintf( output, "%sCase #%d: %s\n", output, i + 1, ( even && odd ? "MIXED" : (even ? "EVEN" : "ODD") ) );
	}
	printf("\n%s", output);
	return 0;
}