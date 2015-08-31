#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
 {
 	int tcase, length, i = 0, j = 0, k = 0;
 	char input[1024], output[1024] = "", current[4];
 	char str[8][4] = {"MMM", "GMM", "MGM", "MMG", "MGG", "GMG", "GGM", "GGG"};
 	scanf("%d", &tcase);
 	for (;i < tcase; i++) {
 		char combination[8] = {0};
 		scanf("%s", input);
 		sprintf(output, "%s%s", output, "\n");
 		length = strlen(input);
 		for (j = 0; j < length; j += 3) {
 			sprintf(current, "%c%c%c", input[j], input[j+1], input[j+2]);
 			for(k = 0; k < 8; k++)
 				strcmp(current, str[k]) == 0 && combination[k]++;
 		}
 		for (j = 0; j < 8; j++)
 			sprintf(output, "%s%d", output, combination[j]);
 	}
 	printf("%s\n", output);
 	return 0;
 }