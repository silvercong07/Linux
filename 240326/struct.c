#include <stdio.h>

int main()
{
	struct ABC{
		char a;
		int b;
		double c;
	}size;
	printf("%ld\n", sizeof(size));
}
