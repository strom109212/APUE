#include <apue.h>
#include <myerr.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");	
	}
	else if(pid != 0)
	{
		sleep(2);
		exit(2);
	}
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if( pid != 0)
	{
		sleep(4);
		abort();
	}
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid != 0)
	{
		execl("/home/apue/chapter008/sh","sh", (char*)0);
		exit(7);
	}

	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid != 0)
	{
		sleep(8);
		exit(0);
	}
	sleep(6);
	kill(getpid(), SIGKILL);
	exit(6);
}	
