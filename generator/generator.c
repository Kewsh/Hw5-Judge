#include "generator.h"

/** 
 * This function checks str is ended with suffix or not
 * 
 * @param str is the main string that should be checked at the end
 * @param suffix is string that should be checked with the end of main string
 *
 * @return integer 0 if str ends with the given suffix otherwise returns 1
 *
 */

int endsWith(const char str[], const char suffix[]){
	int strLen = strlen(str);
	int suffixLen = strlen(suffix);
	int difLen = strLen - suffixLen;
	
	if(difLen < 0)
		return 1;
		
	while(suffixLen >= 0)
		if(str[suffixLen+difLen] != suffix[suffixLen--])
			return 1;
	return 0;
}

int isNumerical(const char number[]){
	int i=0;
	while(number[i]){
		if(!isdigit(number[i])){
			return 0;
		}
		i++;
	}
	return 1; // 1 for ok
}

/** 
 * This function checks input files in the "in" folder
 * 
 * @param inputs is array of files must be checked
 * @param inputsLen is the len of inputs array
 *
 * @return integer 0 if format of files is correct otherwise 1
 *
 */

int checkInputs(char inputs[][5], int inputsLen){
	int check[MAX_ARRAY_SIZE], index;
	for(index=0; index<inputsLen; index++)
		check[index] = 0;
	for(index=0; index<inputsLen; index++){
		if(!isNumerical(inputs[index]))
			return 1;
		check[atoi(inputs[index])-1] = 1;
	}
	for(index=0; index<inputsLen; index++)
		if(check[index] == 0)
			return 1;
	return 0;
}

/** 
 * This function checks feed of generator to meet the requirements
 * 
 * @param filePath is the path of feed of generator
 *
 * @return integer 0 in case generator's feed meets standards and requirements , also prints result of failures on screen
 *
 */

int checkFormat(const char filePath[]){ // validation
	if(checkDir(filePath)==-1){
		changeColor(RED);
		printf("the given path is incorrect...\n");
		changeColor(WHITE);
		return 1;
	}
	chdir(filePath);
	char checkFile[MAX_ARRAY_SIZE];
	struct dirent *de; // explained in __generate__ function
	DIR *dr; // DIR pointer for directory search 
	
	int inCheck = 0, codeCheck = 0;
	dr = opendir(".");
	while ((de = readdir(dr)) != NULL){
		strcpy(checkFile, de->d_name);
		if(!strcmp(checkFile, "..") || !strcmp(checkFile, "."))	// "." and ".." are directory paths that are always present
			continue;
		else if(!strcmp(checkFile, "in")) // found "in" folder
			inCheck = 1;
		else if(!strcmp(checkFile, "code.c")) // found testcode (code.c)
			codeCheck = 1;
		else if(strcmp(checkFile, "code.exe")){ // other files and folders except executable testcode (code.exe)
			changeColor(RED);
			printf("the main folder should only include \"in\" folder and \"code.c\" ...\n");
			changeColor(WHITE);		
			return 1;
		}
	}
	if(inCheck != 1){
		changeColor(RED);
		printf("the main folder must contain the \"in\" folder...\n");
		changeColor(WHITE);
		return 1;
	}	
	if(codeCheck != 1){
		changeColor(RED);
		printf("the main folder must contain the \"code.c\"...\n");
		changeColor(WHITE);
		return 1;
	}
	
	char inputs[MAX_ARRAY_SIZE][5];
	int inputCounter = 0, inputsLen = 0;
	dr = opendir("in");							// checking the "in" folder that should only include .txt
	while ((de = readdir(dr)) != NULL){
		strcpy(checkFile, de->d_name);
		if(!strcmp(checkFile, "..") || !strcmp(checkFile, "."))
			continue;
		else if(endsWith(checkFile, ".txt")){
			changeColor(RED);
			printf("the \"in\" folder should only include \".txt\" files...\n");
			changeColor(WHITE);
			return 1;
		}
		checkFile[strlen(checkFile)-4] = '\0';
		strcpy(inputs[inputsLen++], checkFile);
		inputCounter++;
	}
	if(!inputCounter){
		changeColor(RED);
		printf("the \"in\" folder should not be empty...\n");
		changeColor(WHITE);
		return 1;
	}
	
	if(checkInputs(inputs, inputsLen)){	// checking file names
		changeColor(RED);
		printf("file names must be numerical and sorted...\n");
		changeColor(WHITE);
		return 1;	
	}
		
	return 0;
}

/** 
 * This function copies content of second file into first file
 * 
 * @param filePAth is the path of feed of generator
 *
 * @return integer 0 in case generator's feed meets standards and requirements , also prints result of failures on screen
 *
 */

int generator(const char filePath[]){
	int compileStatus=-1; // 0 for ok
	int fileFormatError=-1; // 0 for ok
	int numberOfInputs,copyResult;
	char testCaseDir[MAX_ARRAY_SIZE];
	char testCaseDirIn[MAX_ARRAY_SIZE];
	char testCaseDirOut[MAX_ARRAY_SIZE];
	char cmd[MAX_ARRAY_SIZE];
	char strNumber[MAX_ARRAY_SIZE];
	char buffer[MAX_ARRAY_SIZE];
	char completeFilePath[MAX_ARRAY_SIZE];
	char temp[MAX_ARRAY_SIZE];
	char initialPath[MAX_ARRAY_SIZE];
	strcpy(initialPath,getcwd(buffer, sizeof(buffer)));
	sprintf(testCaseDir, "%s/../testcases", filePath);
	sprintf(testCaseDirIn, "%s/inputs", testCaseDir);
	sprintf(testCaseDirOut, "%s/outputs", testCaseDir);
	fileFormatError=checkFormat(filePath);
	chdir(initialPath);
	if(fileFormatError==0){ // checking for validation of path file given
		sprintf(completeFilePath, "%s/code.c", filePath);
		sprintf(buffer, "%s/code.exe", filePath); // place and name of result exe file
		compileStatus=compile(completeFilePath,buffer);
		sprintf(buffer, "%s/in", filePath);		
		numberOfInputs=numberOfFiles(buffer);
	}
	else{
		pressAnyKey();
		getch();
		return -1;
	}
	if(compileStatus==0){
		changeColor(GREEN);
		printf("Compiled succesfully.\n");
		changeColor(WHITE);
		pressAnyKey();
		getch();
		mkdir(testCaseDir);
		mkdir(testCaseDirIn);
		mkdir(testCaseDirOut);
		int i;
		chdir(filePath);
		system("cls");
		for(i=0;i<numberOfInputs;i++){ // generating ouput from given code
			sprintf(cmd, "code.exe <in/%d.txt >../testcases/outputs/output%d.txt", i+1, i+1);			
			puts(cmd);
			system(cmd);
			//system("code.exe <in/1.txt >../testcases/outputs/1.txt"); // sample
		}
		// assume every output is ok :
		showPath();
		for(i=0;i<numberOfInputs;i++){ // loop to create input files in testcase folder
			sprintf(temp, "in/%d.txt", i+1);
			sprintf(buffer, "../testcases/inputs/input%d.txt", i+1);
			puts(temp);
			copyResult=copyFile(buffer,temp);
			if(copyResult==-1){
				changeColor(RED);
				printf("Error accured ...\n");
				printf("Failed to copy inputs to testcase folder.");
				changeColor(WHITE);
				pressAnyKey();
				getch();
				if (remove("code.exe") != 0) {
					changeColor(RED);
					printf("Unable to delete the exe file ...");
					changeColor(WHITE);
					getch();
				}
				chdir("..");
				return -1;
			}	
		}
		if (remove("code.exe") != 0) {
			changeColor(RED);
			printf("Unable to delete the exe file ...");
			changeColor(WHITE);
			getch();
		}
		chdir(initialPath);
		system("cls");
		changeColor(GREEN);
		printf("Done.\n");
		changeColor(WHITE);
		pressAnyKey();
		getch();
		system("cls");
	}
	else{
		changeColor(RED);
		printf("\nCompile failed.\n");
		changeColor(WHITE);
		pressAnyKey();
		getch();
		return -1;
	}
}
