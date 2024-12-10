//group10 (Kj Taylor, Faolan Paz, Ivan Rodriguez)
//10/10/24
//Madlibs 
#include <stdio.h>
#define CSIZE 100
void FillStory(char userInputs[100][100], int rows, int columns, char* fname);
void madread(FILE* fp1, char userInputs[100][100]);
void adj(int inputCount, int cols, char userInputs[100][100]);
void verb(int inputCount, int cols, char userInputs[100][100]);
void noun(int inputCount, int col, char userInputs[100][100]);

int main(int argc, char** argv) {
    FILE* fptr = fopen(argv[1] , "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 2;
    }
    char userInputs[100][100];
    madread(fptr, userInputs);
    fclose(fptr);

    FillStory(userInputs, 100, 100, argv[1]);

    return 0;
}

void FillStory(char userInputs[100][100], int rows, int columns, char* fname) {
    int nameint = 0;
    int inputCount = 0;
    int storyCount = 0;
    int userCount = 0;
    char temp[CSIZE][CSIZE];
    FILE* f = fopen(fname, "r");
    
    while (fgets(temp[storyCount], CSIZE, f) != NULL) {
        
        if (storyCount % 2 == 0) {
            printf("%s", temp[storyCount]);  
            storyCount++;
        }
        
        else {
            
            if (inputCount < rows) {
                printf("%s", userInputs[inputCount]);
                inputCount++;
            }
            storyCount++;
        }
    }
    fclose(f);

}


void madread(FILE* fp1, char userInputs[100][100]) {
    int nameint;
    int inputCount = 0;
    char temp[CSIZE][CSIZE];
    for (nameint = 0; nameint <= CSIZE; nameint++) {
        fgets(temp[nameint] , CSIZE, fp1);
        if (temp[nameint][1] == '\0' || temp[nameint][2] == '\0') {
            switch(temp[nameint][0]){
                case 'A':
                  //function for adjective
                  adj(inputCount, CSIZE, userInputs);
                  inputCount++;
                  break;

                case 'N':
                   //Function for noun
                   noun(inputCount, CSIZE, userInputs);
                   inputCount++;
                   break;

                case 'V':
                    //function for Verb
                    verb(inputCount, CSIZE, userInputs);
                    inputCount++;
                   break;

                 default:
                   break;
            }
        }
    }
}

void adj(int inputCount, int cols, char userInputs[100][100]){
    printf("enter an adjective: ");
    fgets(userInputs[inputCount], CSIZE, stdin);
}

void verb(int inputCount, int cols, char userInputs[100][100]){
    printf("enter a verb: ");
    fgets(userInputs[inputCount], CSIZE, stdin);
}

void noun(int inputCount, int col, char userInputs[100][100]){
    printf("enter a noun: ");
    fgets(userInputs[inputCount], CSIZE, stdin);
}

