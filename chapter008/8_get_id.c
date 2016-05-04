/*get process id：pid, ppid, uid, euid, gid, egid*/
#include <unistd.h>
#include <stdio.h>
int main()
{
	printf("pid	= %d\n", getpid());
	printf("getppid	= %d\n", getppid());
	printf("getuid	= %d\n", getuid());
	printf("geteuid	= %d\n", geteuid());
	printf("getgid	= %d\n", getgid());
	printf("getegid	= %d\n", getegid());
	return 0;
}
