#include <unistd.h>
#include <apue.h>
#include <myerr.h>
#include <fcntl.h>

int main()
{
	if (open("tempfile", O_RDWR) < 0)
	{
		err_sys("open error for tempfile");
	}
	
	if (unlink("tempfile") < 0)
	{
		err_sys("unlink error for tempfile");
	}
	sleep(30);
	printf("done\n");
	return 0;
}
