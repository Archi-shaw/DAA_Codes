#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int decimal, char* binary, int index) {
    if (decimal == 0) {
        if (index == 16) return;
        binary[15 - index] = '0';
        decimalToBinary(0, binary, index + 1);
        return;
    }
    
    if (index < 16) {
        binary[15 - index] = (decimal % 2) + '0';
        decimalToBinary(decimal / 2, binary, index + 1);
    }
}

void getBinary(int decimal, char* binary) {
    for (int i = 0; i < 16; i++) {
        binary[i] = '0';
    }
    binary[16] = '\0';
    
    if (decimal == 0) {
        return; 
    }
    
    decimalToBinary(decimal, binary, 0);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Invalid input", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    char* inputFile = argv[2];
    char* outputFile = argv[3];
    
    FILE* inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        printf("Error: Cannot open input file %s\n", inputFile);
        return 1;
    }
    
    FILE* outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        printf("Cannot create output file %s\n", outputFile);
        fclose(inFile);
        return 1;
    }
    
    int decimal;
    int count = 0;
    char binary[17];
    
    printf("Converting first %d decimal numbers to binary:\n", n);
    
    while (count < n && fscanf(inFile, "%d", &decimal) == 1) {
        getBinary(decimal, binary);
        fprintf(outFile, "The binary equivalent of %d is %s\n", decimal, binary);
        count++;
    }
    
    fclose(inFile);
    fclose(outFile);
    
    printf("Contents of output file '%s':\n", outputFile);
    
    outFile = fopen(outputFile, "r");
    if (outFile != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), outFile)) {
            printf("%s", line);
        }
        fclose(outFile);
    }
    
    printf("\nConversion completed for %d numbers.\n", count);
    return 0;
}