#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//char * cmd;
#define DEBUG 0

int main(int argc, char * argv[])
{
    int i;
    time_t secs;
    struct tm * timeinfo;

    secs = time(NULL);

    if (DEBUG)
    {
        printf("argc: %d\n",argc);
        for (i=0;i<argc;i++)
            printf("argv[%d]: '%s'\n",i,argv[i]);
    }

    if (argc > 1)
        secs = atol(argv[1]);

    if (DEBUG)
        printf("secs: %ld\n",secs);

//    memset(cmd,0x00,sizeof(cmd));
//    if (argc > 2)
//        strcpy(cmd,argv[2]);

//    printf("cmd: '%s'\n",cmd);

    timeinfo = localtime( &secs);

    printf("Date-Time for (%ld) unix seconds is: %s\n",secs,asctime(timeinfo));

    exit(0);
}

