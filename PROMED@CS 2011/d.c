#include <stdio.h>
#include <string.h>

int remain(char dividend[], int divisor, int carry, int now, int len) {
	if(now == len)
		return carry;
	int number = carry * 10 + (dividend[now] - '0');
	carry = number % divisor;
	return remain(dividend, divisor, carry, now + 1, len);
}

int main(int argc, char const *argv[])
{
	int tcase, i;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; i++) {
		char dividend[1024];
		int divisor, ans, n = 0;
		scanf("%d", &divisor);
		do {
			sprintf(dividend, "%s%d", dividend, 7);
			ans = remain(dividend, divisor, 0, 0, strlen(dividend));
			n++;
		} while (ans != 0);
		sprintf(output, "%sCase %d: %d\n", output, i + 1, n);
		strcpy(dividend, ""); //empty dividend
	}
	printf("\n%s", output);
	return 0;
}