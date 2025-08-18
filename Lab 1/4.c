#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    int i;
    for (i = p2 - 1; i > 0; i--) {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }
}

int main() {
    int arr[100], n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Before ROTATE:\t");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);

    ROTATE_RIGHT(arr, 5);

    printf("\nAfter  ROTATE:\t");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}

