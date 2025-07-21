#include <stdio.h>

int  dup(int *f){
    int dup=0;
   for (int i = 0; i < 1000; i++) {
        if (f[i] >= 2){
            dup = dup + (f[i]/2);
        } 
    }
    return dup;
}

int  repeat(int *f){
    int maxcount =0,count=0,mostRepeated;
   for (int i = 0; i < 1000; i++) {
        if (f[i] > 1) count++;
        if (f[i] > maxcount && f[i] >=2) {
            maxcount = f[i];
            mostRepeated = i;
        }
    }
    return mostRepeated;
}


int main() {
    int n, i;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    int arr[n];
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        printf("File not found!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    printf("The content of the array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);

    int freq[1000] = {0};
    for (i = 0; i < n; i++) freq[arr[i]]++;

    int count = dup(freq);
    int mostrepeated = repeat(freq);
    
    printf("\nTotal number of duplicate values = %d\n", count);
    printf("The most repeating element in the array = %d\n", mostrepeated);
    return 0;
}
