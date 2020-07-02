#pragma once
#include "../mainGlobal.h"

int generator(const char filePath[]);
int checkFormat(const char filePath[]);
int endsWith(const char str[], const char suffix[]);
int checkInputs(char inputs[][MAX_ARRAY_SIZE], int inputsLen);
int isNumerical(const char number[]);