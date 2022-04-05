# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int main()
{
    // close stdout and open output file
    close(STDOUT_FILENO);
    open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0700);
    int rc = vfork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child process\n");
    }
    else
    {
        printf("Parent process\n");
    }
    return 0;
}