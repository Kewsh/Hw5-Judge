#include "checkDir.h"

/** 
 * This function checks if a directory exists ot not
 * 
 * @param dirPath is the path of directory needed to be checked
 *
 * @return integer 1 in case of existence and -1 in opposite case
 *
 */

int checkDir(const char dirPath[]){
	DIR* dir = opendir(dirPath);
	if (dir) {
	    closedir(dir);
	    return 1;
	}
	else {
	    return -1;
	}
}