#include "generator/generator.h"
#include "judge/judge.h"
#include "mainGlobal.h"
#include "main.h"

int main(int argc, char *argv[]) {
	char folderPath[MAX_ARRAY_SIZE];
	char codePath[MAX_ARRAY_SIZE]="";
	int choice;
	system("cls");
	if(argc==1){
		do{
			choice=menuSelect();
			switch(choice){
				case 1 : system("cls");
							showPath();
							printf("Please input folder path ( must include validation code and folder containing inputs ): ");
							gets(folderPath);
							generator(folderPath);
							break;
				case 2 : system("cls");
							showPath();
							printf("Please input folder path ( must include folder containing inputs and outputs ): ");
							gets(folderPath);
							judge(folderPath,codePath,-1);
							strcpy(codePath,"");
							break;
				case 0 : exit(0);
			}
			system("cls");
		}while(1);
	}
	else{
	/*
		0 - unknown
		1 - for generator : -g path
		2 - for judge : -j testcase path
		3 - for judge : -j testcase path -c code path
		4 - for judge : -j testcase path -c code path -t time limit
		5 - help : -h or -help or -?
	*/
		choice=parser(argc,argv);
		double timeLimit;
		switch(choice){
			case 0 :printError("The syntax is Incorrect.\n");
					printf("For getting help enter : %s -h\n",PROGRAM_NAME);
					break;
			case 1 :generator(argv[2]);
					break;
			case 2 :judge(argv[2],codePath,0);
					break;
			case 3 :judge(argv[2],argv[4],0);
					break;
			case 4 :timeLimit=strtod(argv[6], NULL);
					judge(argv[2],argv[4],timeLimit);
					break;
			case 5 :printf("Generator : %s -g [file path]\n",PROGRAM_NAME);
					printf("Judge : %s -j [file path]\n",PROGRAM_NAME);
					printf("Judge : %s -j [file path] -c [code path]\n",PROGRAM_NAME);
					printf("Judge : %s -j [file path] -c [code path] -t [time limit]\n",PROGRAM_NAME);
					pressAnyKey();
					getch();
					break;
		}
	}
	return 0;
}
