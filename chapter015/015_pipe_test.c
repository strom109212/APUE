#include <apue.h>
#include <myerr.h>

int main()
{
    int n;
    pid_t pid;
    int fd[2];
    char line[MAXLINE];
    int buf_size = sysconf(_PC_PIPE_BUF);
    printf("_PC_PIPE_BUF:%d\n", buf_size); 
    if(pipe(fd) < 0)
    {
        printf("pipe error");
        return -1;
    }
    if ((pid = fork())< 0)
    {
        printf("fork error");
        return -1;
    }
    else if (pid > 0)
    {
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
    }
    else
    {
        close(fd[0]);
        write(fd[1], "pipe_test\n", 15);
        
    }
    return 0;
}
