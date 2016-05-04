/*test lseek */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    //test stdin
    if(lseek(STDIN_FILENO, 0, SEEK_SET) == -1)
    {
        printf("STDIN_FILENO can not lseek\n");
    }
    else
    {
        printf("STDIN_FILENO can lseek\n");
    }

    //test 1.txt
    fd = open("1.txt", O_RDWR | O_CREAT | O_TRUNC);
    if(lseek(fd, 0, SEEK_SET) == -1)
    {
        printf("1.txt can not lseek");
    }
    else 
    {
        printf("1.txt can lseek");
    }
        
    return 0;
}
