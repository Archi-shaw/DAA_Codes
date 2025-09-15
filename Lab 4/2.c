#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long long comparisons = 0;  
int bestCase = 1; 
int sortOrder = 1;  
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        comparisons++;
        if ((sortOrder == 1 && arr[j] <= pivot) || 
            (sortOrder == 2 && arr[j] >= pivot)) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }

    int temp = arr[i + 1]; 
    arr[i + 1] = arr[high]; 
    arr[high] = temp;
    int partIndex = (i + 1);
    int leftSize = partIndex - low;
    int rightSize = high - partIndex;
    if (leftSize == 0 || rightSize == 0) {
        bestCase = 0; 
    }

    return partIndex;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    int choice, n,order;
    int arr[600];
    char inputFile[30], outputFile[30];

    printf("MAIN MENU \n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(inputFile, "inAsce.dat");
            strcpy(outputFile, "outQuickAsce.dat");
            sortOrder = 1;  
            break;
        case 2:
            strcpy(inputFile, "inDesc.dat");
            strcpy(outputFile, "outQuickDesc.dat");
            sortOrder = 2; 
            break;
        case 3:
            strcpy(inputFile, "inRand.dat");
            strcpy(outputFile, "outQuickRand.dat");
            printf("Choose order for Random Data (1 = Ascending, 2 = Descending): ");
            scanf("%d", &order);
            if (order != 1 && order != 2) { 
            order = 1; 
            }
            sortOrder = order; 
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

    quickSort(arr, 0, n - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);

    long long timeTaken = (end.tv_sec - start.tv_sec) * 1000000000LL + 
                          (end.tv_nsec - start.tv_nsec);

    writeFile(outputFile, arr, n);

    printf("After Sorting: ");
    display(arr, n);

    printf("Number of Comparisons: %lld\n", comparisons);
    printf("Execution Time: %lld nanoseconds\n", timeTaken);

    if (bestCase)
        printf("Scenario: Best-case partitioning\n");
    else
        printf("Scenario: Worst-case partitioning\n");

    return 0;
}
