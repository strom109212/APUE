/**/
#include "apue.h"
#include "myerr.h"
#define BUFFSIZE 4096

int main()
{
    int num;
    int ret;
    char buf[BUFFSIZE];
    while(1)
    {
        num = read(STDIN_FILENO, buf, BUFFSIZE);
        if(num > 0)
        {
            ret = write(STDOUT_FILENO, buf, num);
            if(ret != num)
            {
                printf("errno = %d, write error\n", errno);
                break;
            }
        }
        
        if(num < 0)
        {
            printf("errno = %d, read error\n", errno);
            break;
        }
        
        if(num == 0)
        {
            break;
        }
    }
	return 0;
}

