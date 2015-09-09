#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct {
    int x, y, n;
    char state;
} uni;

typedef struct {
    float dist;
    uni a, b;
} close;

int cmpx(const void* a, const void* b) {
    uni *p1 = (uni *)a, *p2 = (uni *)b;
    return (p1->x - p2->x);
}

int cmpy(const void* a, const void* b) {
    uni *p1 = (uni *)a, *p2 = (uni *)b;
    return (p1->y - p2->y);
}

float distance(uni a, uni b) {
	return sqrt( pow(a.x - b.x, 2) + pow(a.y - b.y, 2) );
}

close find(uni univ[], int n) {
	int i, j, mid = n / 2;
	float dist;
	close min;
	if (n < 4) {
		//bruteforce
		min.dist = FLT_MAX;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				if (univ[i].state == univ[j].state)
					continue;
				dist = distance(univ[i], univ[j]);
				if (dist < min.dist) {
					min.a = univ[i];
					min.b = univ[j];
					min.dist = dist;
				}
			}
		}
	} else {
		uni strip[n];
		int size = 0;
		close left = find(univ, mid), right = find(univ + mid, n - mid);
		min = right.dist < left.dist ? right : left;
		//check in strip
		for (i = 0; i < n; i++)
			if (abs(univ[i].x - univ[mid].x) < min.dist)
				strip[size++] = univ[i];
		qsort(strip, size, sizeof(uni), cmpy);
		for (i = 0; i < size; i++) {
			for (j = i + 1; j < n && strip[i].y - strip[j].y < min.dist; j++) {
				if (strip[i].state == strip[j].state)
					continue;
				dist = distance(strip[i], strip[j]);
				if (dist < min.dist) {
					min.a = strip[i];
					min.b = strip[j];
					min.dist = dist;
				}
			}
		}
	}
	return min;
}

int main(int argc, char const *argv[]) {
	int tcase, i;
	char output[1024] = "";
	scanf("%d", &tcase);
	for (i = 0; i < tcase; ++i)
	{
		int unum, j, k;
		char out[1024];
		scanf("%d", &unum);
		uni univ[unum];
		for(j = 0; j < unum; j++) {
			scanf("%d %d %c", &univ[j].x, &univ[j].y, &univ[j].state);
			univ[j].n = j + 1;
		}
		qsort(univ, unum, sizeof(uni), cmpx);
    	close unic = find(univ, unum);
    	if (unic.dist == FLT_MAX)
    		sprintf(output, "%sCase %d: NO SOLUTION\n", output, i + 1);
    	else if(unic.a.state > unic.b.state)
			sprintf(output, "%sCase %d: %d %c %d %c\n", output, i + 1, unic.b.n, unic.b.state, unic.a.n, unic.a.state);
		else
			sprintf(output, "%sCase %d: %d %c %d %c\n", output, i + 1, unic.a.n, unic.a.state, unic.b.n, unic.b.state);
	}
	printf("\n%s", output);
	return 0;
}