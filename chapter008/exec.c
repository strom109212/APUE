#include <apue.h>
#include <myerr.h>
#include <unistd.h>
#include <sys/wait.h>

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main()
{
	pid_t pid;
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)
	{
		if(execle("/home/apue/chapter008/get_id.elf", "get_id", "myarg1", "MY ARG2", (char*)0, env_init) < 0)
		{
			err_sys("exec error");
		}
	}
	
	if(waitpid(pid, NULL, 0) < 0)
	{
		err_sys("waitpid error");
	}
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)
	{
		if(execlp("get_id.elf", "get_id", "only 1 arg", (char *)0) < 0)
		{
			err_sys("execlp error");
		}
	}
	exit(0);
}
