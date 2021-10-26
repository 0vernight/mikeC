#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


void main9() {
	int tel=1234;

	int i, j=0, k=0, t, n[4];
	while (tel)
	{
		i = tel % 10;
		i += 5;
		i %= 10;
		tel /= 10;
		n[j++] = i;
	}
	t = n[0];
	n[0] = n[3];
	n[3] = t;
	t = n[1];
	n[1] = n[2];
	n[2] = t;
	while (--j!=-1)
	{
		k = k * n[j]+n[j];
		printf("%d", n[j]);
	}
	printf("\n[%d]\n", k);

	
}