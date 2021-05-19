#include <stdio.h>
#include <unistd.h>

int main()
{
	int *p;
	int x[2] = {10, 20};

	p = x;
	printf("%d\n", p);
	p += 1;
	printf("%d\n", p);
	return (0);
}
