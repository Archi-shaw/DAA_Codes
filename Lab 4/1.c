#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long long comparisons = 0;  

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
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
    int choice, n;
    int arr[600];
    char inputFile[30], outputFile[30];

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(inputFile, "inAsce.dat");
            strcpy(outputFile, "outMergeAsce.dat");
            break;
        case 2:
            strcpy(inputFile, "inDesc.dat");
            strcpy(outputFile, "outMergeDesc.dat");
            break;
        case 3:
            strcpy(inputFile, "inRand.dat");
            strcpy(outputFile, "outMergeRand.dat");
            break;
        default:
            printf("Exiting...\n");
            return 0;
    }

    n = readFile(inputFile, arr);
    if (n <= 0) return 0;

    printf("Before Sorting: ");
    display(arr, n);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    mergeSort(arr, 0, n - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);

    long long timeTaken = (end.tv_sec - start.tv_sec) * 1000000000LL + 
                          (end.tv_nsec - start.tv_nsec);

    writeFile(outputFile, arr, n);

    printf("After Sorting: ");
    display(arr, n);

    printf("Number of Comparisons: %lld\n", comparisons);
    printf("Execution Time: %lld nanoseconds\n", timeTaken);

    return 0;
}
