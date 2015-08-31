#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int tcase, i, j, ih, im, fh, fm, min;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; i++) {
		int count = 0, counter;
		float hp, mp;
		scanf("%d %d %d %d", &ih, &im, &fh, &fm);
		if (fh * 60 + fm < ih * 60 + im)
			min = (fh + 12) * 60 + fm - ih * 60 - im;
		else
			min = fh * 60 + fm - ih * 60 - im;
		hp = ih * 30.0 + 0.5 * im;
		mp = im * 6.0;
		if (mp > hp)
			counter = 0;
		for (j = 1; j <= min; j++) {
			hp = fmod( (hp + 0.5), 360.0 );
			mp = fmod( (mp + 6.0), 360.0 );
			if (mp < hp)
				counter = 1;
			else if (counter) {
				counter = 0;
				count++;
			}
		}
		sprintf(output, "%s%02d:%02d %02d:%02d %d\n", output, ih, im, fh, fm, count);
	}
	printf("\n\n%s", output);
	return 0;
}
