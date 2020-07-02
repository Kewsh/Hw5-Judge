#include "errorHandeling.h"

/** 
 * This function prints press any key to continue in std output and then we should press something to continue
 */

void pressAnyKey(){
	puts("Press any key to continue...");
	getch();
}

/** 
 * This function gets a message and prints it in RED
 */

void printError(char message[]){
	colorMessage(RED,message,WHITE);
}
