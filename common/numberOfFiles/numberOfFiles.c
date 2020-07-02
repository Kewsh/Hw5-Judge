#include "numberOfFiles.h"

/** 
 * This function tries to return number of files in path given ( without . and .. )
 * 
 * @param filePAth is the path of directory needed to be checked
 *
 * @return integer as number of files ( -1 for error )
 *
 */

int numberOfFiles(const char filePath[]){
	struct dirent *de;  // Pointer for directory entry 
	int fileCounter=0; 
    DIR *dr = opendir(filePath); 
    if (dr == NULL){  // opendir returns NULL if couldn't open directory
        printError("Could not open current directory.\n" ); 
        return -1; 
    } 
    while ((de = readdir(dr)) != NULL){
//    	printf("%s\n", de->d_name);
        fileCounter++;
	}
    closedir(dr);
    return fileCounter-2; 
}
