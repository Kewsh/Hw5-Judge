#pragma once
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include "../common/common.h"

int compareFiles(const char path1[],const char path2[]);
int checkFormatJudge (const char filePath[]);
int judge(const char filePath[],char codePath[],double timeLimit);
