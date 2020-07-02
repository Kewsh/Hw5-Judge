#include "showPath.h"

/** 
 * This function shows the path we are in right now
 */

void showPath(){
	char cwd[MAX_ARRAY_SIZE];
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
	    printf("Current working dir: %s\n", cwd);
	}
	else {
	    printError("Unable to show path ...");
	}
}
