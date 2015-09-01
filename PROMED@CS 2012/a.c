#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int tcase, i, j;
	char input[1024], output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i) {
		int alphabet[27] = {0}, valid = 1;
		scanf(" %[^\n]", input);
		int length = strlen(input);
		if (length < 2 || length > 27)
			valid--;
		else {
			for (j = 0; j < length; ++j) {
				if(input[j] < 65 || input[j] > 90) {
					valid--;
					break;
				}
				int key = input[j] - 64;
				if(alphabet[key] > 0) {
					valid--;
					break;
				}
				alphabet[key]++;
			}
		}
		sprintf( output, "%sCase #%d: %s\n", output, i + 1, (valid ? "VALID" : "INVALID") );
	}
	printf("\n%s", output);
	return 0;
}