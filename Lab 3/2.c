#include <stdio.h>
#include <stdlib.h>

int insertionSort(int arr[], int n) {
    int i, j, key, comparisons = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int readFile(const char *filename, int arr[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return -1;
    }
    int n = 0;
    while (fscanf(fp, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(fp);
    return n;
}

void writeFile(const char *filename, int arr[], int n) {
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n, comparisons;
    int arr[600]; 
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    char inputFile[30], outputFile[30];

    switch (choice) {
        case 1:
            strcpy(inputFile, "inAsce.dat");
            strcpy(outputFile, "outInsAsce.dat");
            break;
        case 2:
            strcpy(inputFile, "inDesc.dat");
            strcpy(outputFile, "outInsDesc.dat");
            break;
        case 3:
            strcpy(inputFile, "inRand.dat");
            strcpy(outputFile, "outInsRand.dat");
            break;
        default:
            printf("Exiting...\n");
            return 0;
    }

    n = readFile(inputFile, arr);
    if (n <= 0) return 0;

    printf("Before Sorting: ");
    display(arr, n);

    comparisons = insertionSort(arr, n);

    writeFile(outputFile, arr, n);

    printf("After Sorting: ");
    display(arr, n);

    printf("Number of Comparisons: %d\n", comparisons);

    if (choice == 1)
        printf("Scenario: Best Case\n");
    else if (choice == 2)
        printf("Scenario: Worst Case\n");
    else
        printf("Scenario: Average Case\n");

    return 0;
}
