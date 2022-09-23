#include <stdio.h>

int main()

{
	float r, h, area, volume, Pi=3.14;
	scanf("%f %f", &r, &h);
	area = Pi * r * r;
	volume = area * h;

	printf("area=%.2f,volume=%.2f", area, volume);
	return 0;
}