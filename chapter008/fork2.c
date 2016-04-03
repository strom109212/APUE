#include <apue.h>
#include <myerr.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	printf("(0)parent pid = %ld\n", (long)getpid());
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)
	{
		printf("(1)first child pid = %ld\n", (long)getpid());
		if((pid = fork()) < 0)
		{
			err_sys("fork error");
		}
		else if (pid > 0)
		{
			exit(0);
		}
		
		printf("(2)second child pid = %ld\n", (long)getpid());
		sleep(5);
		printf("(2)second child, parent pid = %ld\n", (long)getppid());
		exit(0);
	}
	
	printf("(0)first child pid = %ld\n", (long)pid);	
	if(waitpid(pid, NULL, 0) != pid)
	{
		err_sys("waitpid error");
	}

	exit(0);
}
