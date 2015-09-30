#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>

//char * cmd;
#define DEBUG 0

/* Flag set by .--verbose.. */
static int verbose_flag;

/* Flag set by .--debugon.. */
static int debug_flag;

/* Flag set by .--timeonly.. */
static int timeonly_flag;

#define VER_MAJOR 0
#define VER_MINOR 99

void version(char * name)
{
	printf("%s Version %d.%d\n",name,VER_MAJOR,VER_MINOR);
}

void usage(char * name)
{
	printf("%s <options> [time]\n",name);
	printf("where <options>:\n");
	printf("  --timeonly              Prints only the unixtime.\n");
	printf("  -t,--time <UNIX TIME>   Specifies the unixtime.\n");
	printf("  -h,--help               Shows help/usage.\n");
	printf("  -v,--version            Shows gorram version.\n");
}

int main(int argc, char * argv[])
{
    int c,i;
    time_t secs;
    struct tm * timeinfo;
    
	timeonly_flag = 0;
    debug_flag= 0;
    verbose_flag=0;
    
	// initialize to current time
    secs = time(NULL);
     
	while (1)
	{
		static struct option long_options[] =
		{
			/* These options set a flag. */
			{"verbose",  no_argument,       &verbose_flag, 1},
			{"brief",    no_argument,       &verbose_flag, 0},
			{"debug",    no_argument,         &debug_flag, 1},
			{"nodebug",  no_argument,         &debug_flag, 0},
			{"timeonly", no_argument,      &timeonly_flag, 1},

			/* These options don't set a flag.
				We distinguish them by their indices. */
			//{"append",  no_argument,          0, 'b'},
			{"version",   no_argument,          0, 'v'},
			{"help",      no_argument,          0, 'h'},
			{"time",      required_argument,    0, 't'},
			//{"delete",  required_argument, 0, 'd'},
			//{"create",  required_argument, 0, 'c'},
			//{"file",    required_argument, 0, 'f'},
			{0, 0, 0, 0} 
		};
		/* getopt_long stores the option index here. */
		int option_index = 0;
     
		c = getopt_long (argc, argv, "vht:",
			long_options, &option_index);
     
		/* Detect the end of the options. */
		if (c == -1)
			break;
     
		switch (c)
		{
			case 0:
				/* If this option set a flag, do nothing else now. */
				if (long_options[option_index].flag != 0)
					break;
				printf ("option %s", long_options[option_index].name);
				if (optarg)
					printf (" with arg %s", optarg);
				printf ("\n");
				break;
     
			case 'v':
				version(argv[0]);
				exit(0);
				break;

			case 'h':
				usage(argv[0]);
				exit(0);
				break;

			case 't':
				secs = atol(optarg);
				break;
     
//			case 'b':
//				puts ("option -b\n");
//				break;
//
//			case 'c':
//				printf ("option -c with value `%s'\n", optarg);
//				break;
    
			case '?':
				/* getopt_long already printed an error message. */
				break;
     
			default:
				abort ();
		}
	}
     
	/* Instead of reporting .--verbose.
		and .--brief. as they are encountered,
		we report the final status resulting from them. */
	if (verbose_flag)
		puts ("verbose flag is set");

	if (debug_flag)
		puts ("debug flag is set");
     
	/* Print any remaining command line arguments (not options). */
	if (optind < argc)
	{
		if (debug_flag) 
			printf ("non-option ARGV-elements: ");
		while (optind < argc) {
			secs = atol(argv[optind++]);
			if (debug_flag)
				printf ("%s ", argv[optind++]);
		}
		if (debug_flag)
			putchar ('\n');
	}

    if (debug_flag)
    {
        printf("argc: %d\n",argc);
        for (i=0;i<argc;i++)
            printf("argv[%d]: '%s'\n",i,argv[i]);
    }

//    if (argc == 2)
//        secs = atol(argv[1]);

    if (debug_flag)
        printf("secs: %ld\n",secs);

    if (timeonly_flag)
        printf("%ld\n",secs);

//    memset(cmd,0x00,sizeof(cmd));
//    if (argc > 2)
//        strcpy(cmd,argv[2]);

//    printf("cmd: '%s'\n",cmd);

    timeinfo = localtime( &secs);

    if (!timeonly_flag)
		printf("Date-Time for (%ld) unix seconds is: %s\n",secs,asctime(timeinfo));

    exit(0);
}

