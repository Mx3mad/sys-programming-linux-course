#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_SIZE 8192
int main(int argc, char** argv)
{
	if(argc > 1)
	{
		printf("Femto Shell doesn't have arguments, please run it again without arguments\n");
		exit(-1);
	}

	char command[5] = "", input[IN_SIZE];
	do
	{
		command[0] = '\0'; input[0] = '\0';
		printf("FemtoSha > ");
		if(fgets(input, IN_SIZE, stdin) == NULL)
		{
			printf("Please enter something, anything, please.\n");
			continue;
		}
		int i;
		for(i = 0; i < 4 && input[i] != '\0'; i++)
			command[i] = input[i];
		command[i] = '\0';
		if(strcmp(command, "echo") != 0 && strcmp(command, "exit") != 0)
		{
			printf("Invalid command\n");
			continue;
		}
		//printf("%s\n", command);
		if(strcmp(command, "echo") == 0)
		{
			//printf("echoing...\n");
			i++;
			char *output = &input[i];
			printf("%s", output);	
		}

	} while(strcmp(command, "exit") != 0);
	
	printf("See u later (>ᴗ<)づ\n");
	return 0;

}
