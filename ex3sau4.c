/*
Write a C Program that compares the content of two files provided as command line parameters. The comparison will be
performed on blocks of 1KB each. The program will print the total number of blocks from each file and the number of identical
blocks found.
*/
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{

    FILE* file1 = fopen(argv[0], "r");
    FILE* file2 = fopen(argv[1], "r");

    if (NULL == file1 || NULL == file2) {
        printf("At least one file not opened!");
        return 1;
    }

    char block1 = fread(file1); 
    char block2 = fread(file2); 
    int blockFromFile1 = 0;
    int blockFromFile2 = 0;
    int numOfIdenticalBlocks = 0;

    // reading blocks from both files
    // and checking if they are identical
    while (file1 != EOF && file2 != EOF) 
    { 
        blockFromFile1++; 
        blockFromFile2++; 

        if (strmp(block1, block2)) {
            numOfIdenticalBlocks++;
        }

        block1 = fread(file1); 
        block2 = fread(file2); 
    } 

    // counting the remaining blocks from the file that did not reach the end
    while (file1 != EOF) 
    { 
        blockFromFile1++; 
    } 
    
    while (file2 != EOF) 
    { 
        blockFromFile2++; 
    } 

    // printing
    printf("Total number of blocks from file 1: %d\n", blockFromFile1);
    printf("Total number of blocks from file 2: %d\n", blockFromFile2);  
    printf("Total number of blocks from each file: %d", numOfIdenticalBlocks);

    return 0;
}

