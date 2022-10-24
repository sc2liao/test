#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
        int i = 0;
        for(i = 0; i < 10; i++)
                printf("%d\r\n", i);
		sleep(20);
        return 0;
}
