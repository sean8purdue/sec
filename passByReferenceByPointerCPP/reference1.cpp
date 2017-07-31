#include <stdio.h>
#include <iostream>
using namespace std;

#define CMD 100

void getCmd(char *);
char * getCmd1();

void getCmdRef(char&);
void getCmdRef1(char &);

int main() {
    // 1 pass by pointer 1
    char *cmd = NULL;
    getCmd(cmd);
    fprintf(stderr, "%s\n", cmd);
    // print (null) nothing since cmd is still NULL
    //cout << cmd << endl;
    // segmentation fault
    //fprintf(stderr, "%s\n", cmd);


    // 2 pass by pointer 2
    char *cmd1 = NULL;
    cmd1 = getCmd1();
    fprintf(stderr, "%s\n", cmd1);
    // print hello world
    free(cmd1);
    fprintf(stderr, "%s\n", cmd1);
    // Dangerous!!
    // still print hello world, because free just tell OS, we will not use that mem, but OS might not delete the content start from this addrss.

    // Dangerous 2 !!
    strcpy(cmd1, "hello world again");
    fprintf(stderr, "%s\n", cmd1);
    // still print hello world again
    // this address is still can be used, but may be overwriten by other malloc call in the future!!!!!

    // safe
    // after free assign cmd1 to NULL
    cmd1 = NULL;
    // the following statements will cause SegFault!
    //strcpy(cmd1, "hello world again");
    //fprintf(stderr, "%s\n", cmd1);

    char cmdRef;
    //getCmdRef(cmdRef);
    //cout << cmdRef << endl;

    char *ref1;
    //getCmdRef1(&ref1);
}

void getCmd(char *nCmd) {
    nCmd = (char *) malloc( CMD * sizeof(char) );
    memset(nCmd, '\0', sizeof(*nCmd));
    strcpy(nCmd, "hello world");
}

char * getCmd1() {
    char * cmd = (char *) malloc( CMD * sizeof(char) );
    memset(cmd, '\0', sizeof(*cmd));
    strcpy(cmd, "hello world");
    return cmd;
}

void getCmdRef(char& cmdRef) {
    //cmdRef = (char) malloc( CMD * sizeof(char) );
    //char c;
    //int i = 0;
    //// get user input string with getchar
    //while ( (c = getchar()) != '\n' && (i < (CMD-1))   ) {
        //cmdRef[i++] = c; 
    //}
    //cmdRef[i] = '\0';
    cmdRef = 's';

}

void getCmdRef1(char& ref1) {

}
