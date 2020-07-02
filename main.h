#include "mainGlobal.h"

// Declaration and definition of code was made here to avoid main.c complication

/** 
 * This function creates menu options and forces to choose one
 * 
 * @returns an integer as users choice
 *
 */
 
int menuSelect(){
	system("cls");
	printf("\n\n\t\t\t   ___           _                             _                 \n");
	printf("\t\t\t  |_  |         | |                           | |                \n");
	printf("\t\t\t    | |_   _  __| | __ _  ___    ___ _   _ ___| |_ ___ _ __ ___  \n");
	printf("\t\t\t    | | | | |/ _` |/ _` |/ _ \\  / __| | | / __| __/ _ \\ '_ ` _ \\ \n");
	printf("\t\t\t/\\__/ / |_| | (_| | (_| |  __/  \\__ \\ |_| \\__ \\ ||  __/ | | | | |\n");
	printf("\t\t\t\\____/ \\__,_|\\__,_|\\__, |\\___|  |___/\\__, |___/\\__\\___|_| |_| |_|\n");
	printf("\t\t\t                    __/ |             __/ |                      \n");
	printf("\t\t\t                   |___/             |___/                       \n\n\n\n");
	printf("\t			1 - make testcases ( input file and code needed )\n");
	printf("\t			2 - judge ( testcase file and a code needed )\n");
	printf("\t			0 - quit\n\n");
	int c;
	char s[3];
	while(1){
		printf("\t			please enter your choice (0-2): ");
		gets(s);
	if(strcmp(s,"0")==0){
		return 0;
	}
	else if(strcmp(s,"1")==0){
		return 1;
	}
	else if(strcmp(s,"2")==0){
		return 2;
	}
	fflush(stdin);
	}
}

/** 
 * This function takes main program options and parses it
 * 
 * @param argc is the same as main's argc
 * @param argv is the same as main's argv
 *
 * @return integer as result of parsing command line arguments
 *
 */

int parser(int argc , char *argv[]){
	/*
		0 - unknown
		1 - for generator : -g path
		2 - for judge : -j testcase path
		3 - for judge : -j testcase path -c code path
		4 - for judge : -j testcase path -c code path -t time limit
		5 - help : -h or -help or -?
	*/
	if(strcmp(argv[1],"-g")==0 && argc==3){
		return 1;
	}
	else if(strcmp(argv[1],"-j")==0 && argc==3){
		return 2;
	}
	else if(strcmp(argv[1],"-j")==0 && argc==5){
		return 3;
	}
	else if ((strcmp(argv[1],"-h")==0 || strcmp(argv[1],"-h")==0 || strcmp(argv[1],"-?")==0 || strcmp(argv[1],"-help")==0) && argc==2){
		return 4;
	}
	else if(strcmp(argv[1],"-j")==0 && argc==7){
		return 5;
	}
	else {
		return 0;
	}
}
