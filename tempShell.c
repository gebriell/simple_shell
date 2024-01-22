#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 102
#define maximumTokens 4

int main (int argc, char * argv[]) {
    
    char userInput[SIZE];
    int totalTokens, currentTokens = 0;
    char * token;
    char * executable;
    char * tokenArray[maximumTokens];
    
    while(true) {
    
        printf("Burcho Shells lol: ");
        fgets(userInput, SIZE, stdin);
        token = strtok (userInput, " ");

        while (token != NULL)
        {
            tokenArray[currentTokens++] = token;
            token = strtok (NULL, " ");
            totalTokens = currentTokens;
            printf("The command line argument is %s \n\n", token);
        }
    
        for (int i = 0; i < totalTokens; i++) 
            printf("In array %d, there is %s \n", i, tokenArray[i]);
    
        printf("Total number of tokens = %d \n\n", totalTokens);
    
        executable = tokenArray[0];
        printf("The executable file is %s \n\n", executable);
        printf("The command line argument is %s \n\n", token);
        
        if (strcmp(userInput, "exit") == 0) {
            break;
        }

        printf("Put together, it should say: %s %s \n", executable, token);
    }
    return 0;
}

// token gives gibberish because %s doesn't work with entire pointer arrays
// token will pass into execvp though because it works there

// use malloc for buffer
// keep count of the number of tokens/token in an incrementer
// then take that value and pass it into the pointer array
// pointerarray[0] will be executable
// strcat pointerarray or other will be arguments

// int totalTokens: will store the total number of substrings
// int subIterator: will iterate through tokenArray

// char * buffer = malloc (SIZE) 
// https://stackoverflow.com/questions/14554811/char-usage-and-printing
// look into malloc for tokenArray, and include null pointer

// some kind of loop to iterate over
// the tokens and give you totalTokens

// make char * tokenArray[totalTokens]

// find a way to declare char * tokenArray[totalTokens]
// until then 100 tokens max. if > 100, stop fetching