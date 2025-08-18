#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a; 
    }
    return gcd(b, a % b); 
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error opening file", argv[0]);
        return 1;
    }
    
    char* inputFile = argv[1];
    char* outputFile = argv[2];
    
    FILE* inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        printf("Cannot open input file %s\n", inputFile);
        return 1;
    }
    
    FILE* outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        printf("Cannot create output file %s\n", outputFile);
        fclose(inFile);
        return 1;
    }
    
    int num1, num2;
    int pairCount = 0;
    
    printf("Processing pairs of numbers for GCD calculation:\n");
    
    while (fscanf(inFile, "%d %d", &num1, &num2) == 2) {
        int result = gcd(num1, num2);
        fprintf(outFile, "The GCD of %d and %d is %d\n", num1, num2, result);
        pairCount++;
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
    
    printf("\nGCD calculation completed for %d pairs.\n", pairCount);
    
    if (pairCount < 20) {
        printf("Input file contains only %d pairs. Requirement was at least 20 pairs.\n", pairCount);
    }
    
    return 0;
}