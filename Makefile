# Project: hw-judge
# Makefile created by Dev-C++ 5.11 Edited by me !

CC       = gcc.exe
OBJ      = main.o generator/generator.o judge/judge.o common/showPath/showPath.o common/numberOfFiles/numberOfFiles.o common/compile/compile.o common/checkEmptyFile/checkEmptyFile.o common/checkDir/checkDir.o common/changeColor/changeColor.o common/copyFile/copyFile.o common/errorHandeling/errorHandeling.o
LINKOBJ  = main.o generator/generator.o judge/judge.o common/showPath/showPath.o common/numberOfFiles/numberOfFiles.o common/compile/compile.o common/checkEmptyFile/checkEmptyFile.o common/checkDir/checkDir.o common/changeColor/changeColor.o common/copyFile/copyFile.o common/errorHandeling/errorHandeling.o
BIN      = hw-judge.exe
CXXFLAGS = $(CXXINCS) -g3
CFLAGS   = $(INCS) -g3
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

generator/generator.o: generator/generator.c
	$(CC) -c generator/generator.c -o generator/generator.o $(CFLAGS)

judge/judge.o: judge/judge.c
	$(CC) -c judge/judge.c -o judge/judge.o $(CFLAGS)

common/showPath/showPath.o: common/showPath/showPath.c
	$(CC) -c common/showPath/showPath.c -o common/showPath/showPath.o $(CFLAGS)

common/numberOfFiles/numberOfFiles.o: common/numberOfFiles/numberOfFiles.c
	$(CC) -c common/numberOfFiles/numberOfFiles.c -o common/numberOfFiles/numberOfFiles.o $(CFLAGS)

common/compile/compile.o: common/compile/compile.c
	$(CC) -c common/compile/compile.c -o common/compile/compile.o $(CFLAGS)

common/checkEmptyFile/checkEmptyFile.o: common/checkEmptyFile/checkEmptyFile.c
	$(CC) -c common/checkEmptyFile/checkEmptyFile.c -o common/checkEmptyFile/checkEmptyFile.o $(CFLAGS)

common/checkDir/checkDir.o: common/checkDir/checkDir.c
	$(CC) -c common/checkDir/checkDir.c -o common/checkDir/checkDir.o $(CFLAGS)

common/changeColor/changeColor.o: common/changeColor/changeColor.c
	$(CC) -c common/changeColor/changeColor.c -o common/changeColor/changeColor.o $(CFLAGS)
	
common/copyFile/copyFile.o: common/copyFile/copyFile.c
	$(CC) -c common/copyFile/copyFile.c -o common/copyFile/copyFile.o $(CFLAGS)
	
common/errorHandeling/errorHandeling.o: common/errorHandeling/errorHandeling.c
	$(CC) -c common/errorHandeling/errorHandeling.c -o common/errorHandeling/errorHandeling.o $(CFLAGS)
	

