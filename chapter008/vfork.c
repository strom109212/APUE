/*vfork 函数用于创建一个新进程，该新进程的目的是执行exec一个新程序*/
/*可移植程序不应该使用该函数*/
#include <apue.h>
#include <myerr.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int g_iVar = 5;

int main()
{
	int iVar;
	pid_t pid;
	iVar = 88;
	printf("befor vfork\n");
	printf("pid = %ld, g_iVar = %d, iVar = %d\n", (long)getpid(), g_iVar, iVar);
	if((pid = vfork()) < 0)
	{
		err_sys("fork error");
	}	
	else if(pid == 0)
	{
		g_iVar++;
		iVar++;	
		_exit(0);
	}
	printf("after vfork\n");
	printf("pid = %ld, g_iVar = %d, iVar = %d\n", (long)getpid(), g_iVar, iVar);
	exit(0);
}

