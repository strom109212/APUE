/*fork创建的子进程是父进程的副本，拥有父进程数据空间、堆、栈等的副本*/
/*对子进程变量的修改不影响父进程中该变量的值*/

/*若执行 ./fork.elf > out.txt*/
/*preintf("befor fork\n") 会被执行两次*/
#include <apue.h>
#include <myerr.h>
#include <fcntl.h>
#include <unistd.h>

int g_iVal;
char buf[] = "a write to stdout\n";

int main()
{
	int var;
	pid_t pid;
	var = 100;
	
	if(write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1 )
	{
		err_sys("write error for stdout");
	}
	
	printf("befor fork\n");

	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)
	{
		g_iVal++;
		var++;
	}
	else
	{
		sleep(2);
	}
	
	printf("after fork\n");
	printf("pid = %ld, g_iVal = %d, var = %d\n", (long)getpid(), g_iVal, var);
	
	return 0;
}
