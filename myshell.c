#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define buffer 102

void tokenizer (char userInput[], char *cla[]) {
    
    int counter = 0;
    char *substringOfInput;

    if (fgets(userInput, buffer, stdin)) {
        userInput[strlen(userInput) - 1] = '\0';

        substringOfInput = strtok_r(userInput, " ", &userInput);
        while (substringOfInput != NULL) {
            cla[counter] = substringOfInput;
            substringOfInput = strtok_r(NULL, " ", &userInput);
            counter++;
        }
        cla[counter] = NULL;
    }
    else {
        exit(0);
    }
}

int main(int argc, char * argv[]) {
    
    char userInput[buffer];
    char *cla[buffer]; // pointer array
    char executable[buffer];
    pid_t processID;
    int processStatus;
    int counter = 0;
    char *substringOfInput;

    while (true) {
        if (argv[1] != NULL) {
            printf("%s", argv[1]);
        }
        else {
            printf("> ");
        }

    if (fgets(userInput, buffer, stdin)) {
        userInput[strlen(userInput) - 1] = '\0';

        substringOfInput = strtok(userInput, " ");
        while (substringOfInput != NULL) {
            cla[counter] = substringOfInput;
            substringOfInput = strtok(NULL, " ");
            counter++;
        }
        cla[counter] = NULL;
    }
    else {
        exit(0);
    }
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        if (strcmp(userInput, "exit") == 0) {
            break;
        }

        int pid = fork();
        if (pid == 0) {
            strcat(executable, cla[0]);
            if (execvp(executable, cla) < 0)
            {
                printf("Command '%s' not found\n", executable);
                exit(2);
            }
        }
        else {
            processID = wait(&processStatus);
            if (WIFEXITED(processStatus)) {
                printf("Child %d, exited with %d\n", processID, WEXITSTATUS(processStatus));
            }
        }
    }
    return 0;
}