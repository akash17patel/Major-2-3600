//header files
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <error.h>
#define BUF_SIZE 300

//forward declaration
int cd(char *pathGiven);
int hasThisPrex(char const *, char const *);

//main function
int main(){

    //buffer to store user input
    char str[BUF_SIZE];
    //shown before input taken each time
    char *promptShown = "USER_NAME>";
    //token
    char *token;
    token = strtok (str," ");
    //loop t take input
    while(str != NULL){
        //empty
        bzero(str, BUF_SIZE);
        //print prompt rst each time
        printf("%s",promptShown);
        //get user input in str buffer
        fgets(str, BUF_SIZE, stdin);
        //check for cd
        if(hasThisPrex(str,"cd") == 0){
            // check for path for cd command
            token = strchr(str,' ');
            //parse parameter to cd command
            if(token) {
                char *tempTok = token + 1;
                token = tempTok;
                char *locationOfNewLine = strchr(token, '\n');
                if(locationOfNewLine) {
                    *locationOfNewLine = '\0';
                }
                // calling cd method which is user dened
                cd(token);
            }
        }
    }
    //return
    return 0;
}
//check whether q is present in p or not as a prex
int hasThisPrex(char const *p, char const *q)
{
    int i = 0;
    for(i = 0;q[i];i++)
    {
        if(p[i] != q[i])
            return -1;
    }
    return 0;
}
// user deend cd command
int cd(char *pth){
    char path[BUF_SIZE];
    strcpy(path,pth);
    char cwd[BUF_SIZE];
    if(pth[0] != '/'){
        // now true for the dir in current working directory
        getcwd(cwd,sizeof(cwd));
        strcat(cwd,"/");
        strcat(cwd,path);
        chdir(cwd);
    }else{
        chdir(pth);
    }
return 0;
}