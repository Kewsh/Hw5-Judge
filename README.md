# *C Based judge system*


##  *Team kansor ( former Codeck ! ) :*
* [@Kewsh](https://github.com/Kewsh)
* [@ar-ekt](https://github.com/ar-ekt)
* [@xiiwiix](https://github.com/xiiwiix)


## Windows :
* Use [Makefile](https://github.com/xiiwiix/Hw5-Judge/blob/master/Makefile) and MinGW make

* Or use code below :

```
gcc main.c generator/generator.c judge/judge.c common/showPath/showPath.c common/numberOfFiles/numberOfFiles.c common/compile/compile.c common/checkEmptyFile/checkEmptyFile.c common/checkDir/checkDir.c common/changeColor/changeColor.c common/copyFile/copyFile.c common/errorHandeling/errorHandeling.c common/searchInFile/searchInFile.c -o hw-judge.exe

```



## Usage :
- Straight approach :
  - run `hw-judge.exe` and choose option
- Command line approach :
  - `hw-judge.exe -g [file path]` to use generator
  - `hw-judge.exe -j [testcase folder path] -c [code path]` to use judge
  - `hw-judge.exe -j [testcase folder path]` to use judge without code ( program will ask for code input in next steps )
  - `hw-judge.exe -j [testcase folder path] -c [code path] -t [time limit]` to use judge with time limit
  - `hw-judge.exe -h | -help | -?` for help

## Requirements :
- #### Generator :

  - Generator's feed is a folder containing exactly one folder named `in` and one `.c` file names as `code.c`
  - Folder named `in` must include txt files named as `1.txt 2.txt 3.txt ...`

- #### Judge:
  - A folder containing exactly two folders named as `inputs` and `outputs`
  - `inputs` folder must have txt files named as ```input1.txt input2.txt input3.txt ...```
  - `outputs` folder must have txt files named as ```output1.txt output2.txt output3.txt ...```

Judge requirements are covered in case you use generator to produce judge's feed


