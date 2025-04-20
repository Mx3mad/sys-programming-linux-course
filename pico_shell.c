#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define IN_SIZE 16384
#define DIR_SIZE 8192

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("Usage: Pico Shell doesn't have arguments, please run it again without arguments\n");
		exit(-1);
	}

	char input[IN_SIZE];
	while (1)
	{
		input[0] = 0;
		printf("PicoSha >> ");
		if (fgets(input, IN_SIZE, stdin) == NULL)
		{
			printf("EOF or Failed to read the input\n");
		       	break;
		}
		input[strlen(input) - 1] = 0;
		if (strlen(input) == 0)
			continue;
		int new_argc = strlen(input);
		char **new_argv = malloc(sizeof(char*) * new_argc + 1);
		char *temp = strtok(input, " ");
		int i = 1, k = 0;
		while (temp != NULL)
		{
			new_argv[k] = malloc(strlen(temp) + 1);			
			strcpy(new_argv[k], temp);
			k++;
			temp = strtok(NULL, " ");
		}
		new_argv[k] = NULL;
		new_argc = k;
		if (!strcmp(new_argv[0], "echo"))
		{
			for (; i < new_argc; i++)
			{
				printf("%s", new_argv[i]);
				if (i < new_argc - 1)
					printf(" ");
			}
			printf("\n");
			continue;
		}
		else if (!strcmp(new_argv[0], "pwd"))
		{
			if (new_argc > 1)
				printf("Usage: 'pwd' command doesn't have arguments. Arguments are ignored.\n");
			int dir_size = DIR_SIZE;
			char *cur_working_dir = (char *)malloc(dir_size);
			if (getcwd(cur_working_dir, dir_size) == NULL)
			{
				printf("Error: Failed to get the pathname (pathname is too long)\n");
				continue;
			}
			printf("%s\n", cur_working_dir);
			free(cur_working_dir);
			continue;
		}
		else if (!strcmp(new_argv[0], "cd"))
		{
			if (new_argc != 2)
			{
				printf("Usage: cd [new_directory_path]\n");
				continue;
			}
			if (chdir(new_argv[1]) < 0)
			{
				printf("Error: Couldn't change the working directory to %s (it probably doesn't exist).\n", new_argv[1]);
                                continue;
			}
		}
		else if (!strcmp(new_argv[0], "exit"))
		{
			if (new_argc > 1)
				printf("Usage: 'exit' command doesn't have arguments. Arguments are ignored.\n");
			printf("See u later (>ᴗ<)づ\n");
			break;
		}
		else
		{
			pid_t child_pid = fork();
			if (child_pid > 0) //This is parent
			{
				int status;
				wait(&status);
			}
			else if (child_pid == 0) //This is child
			{
				char** new_envp = { NULL };
				execvp(new_argv[0], new_argv);
				printf("UNIX CMD: Failed to execute the command\nEither the name is wrong/doesn't exist, or the kernel failed to execute it for some reason.\n");
				exit(-1);
			}
			else
				printf("UNIX CMD: Failed to fork\n");
		}
		for(i = 0; i < new_argc; i++)
			free(new_argv[i]);
		free(new_argv);
	}
	return 0;

}
