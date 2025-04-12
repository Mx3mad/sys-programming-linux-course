#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("Usage: %s [The text to be echoed]\n\tThere is Nothing to be echoed\n", argv[0]);
		exit(-1);
	}
	char** p;
	for(p = argv+1; *p != NULL; p++)
	{
		printf("%s", *p);
		if(*(p+1) != NULL) printf(" ");
	}
	printf("\n");
	return 0;
}
