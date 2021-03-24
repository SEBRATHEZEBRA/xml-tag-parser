# XML Tag Parser

## Files used:\
src/ -> tagParser.cpp: The source file of the tag parser, contains the data
        structure storing all the tags information as well as the definition of all the
        functions that interact with this data structure.  

     -> driver.cpp: Contains the main function of the project, which has the user
        input loop. Makes calls to functions that interact with the data structure
        in the source file.

include/ -> tagParser.h: The header file of tagParser.cpp, contains all the
            declarations of the functions and structures used in the source file.

bin/ -> location where the executable is stored once compiled.

output/ -> tags.txt: the file where the tags are dumped.

Makefile: Compiles and runs the executable with ease.

## Usage
For all of the following make sure you are in the main directory.
To compile the project:
```bash
make
```

To execute the executable:
```bash
make run
```

To clean the bin:
```bash
make clean
```
