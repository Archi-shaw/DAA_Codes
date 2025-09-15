// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct person {
//     int id;
//     char name[100];
//     int age;
//     int height;
//     int weight
// };
// struct person* arr = NULL;
// int n=0;
// int heap_size =0;
// struct person* minHeap = NULL;

// void swap(struct person* a, struct person* b){
//     struct person temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void minHeapify(struct person* heap, int i){
//     int smallest = i;
//     int left = 2*i + 1;
//     int right = 2*i+2;
//     if( left< heap_size && heap[left].age < heap[smallest].age){
//         smallest = left;
//     }
//     if( right<heap_size && heap[right].age < heap[smallest].age){
//         smallest = right;
//     }
//     if( smallest != i){
//         swap(&heap[i], &heap[smallest]);
//         minHeapify(heap,smallest);
//     }
// }

// void buildMinHeap(struct person* heap){
//     for(int i=(heap_size/2)-1; i>=0; i--){
//         minHeapify(heap,i);
//     }
// }


// void maxHeapify(struct person* heap, int i){
//     int largest = i;
//     int left = 2*i + 1;
//     int right = 2*i+2;
//     if( left< heap_size && heap[left].age > heap[largest].age){
//         largest = left;
//     }
//     if( right<heap_size && heap[right].age > heap[largest].age){
//         largest = right;
//     }
//     if(largest != i){
//         swap(&heap[i], &heap[largest]);
//         maxHeapify(heap, largest);
//     }
// }

// void buildMaxHeap(struct person* heap){
//     for(int i=(heap_size/2)-1; i>=0; i--){
//         maxHeapify(heap,i);
//     }
// }

// // Operations

// void readData(char* filename){
//     FILE* file = fopen(filename, "r");
//     if(file == NULL){
//         printf("Could not open file %s  \n", filename);
//         return;
//     }
//     arr = (struct person *)malloc(n * sizeof(struct person));
//     for (int i = 0; i < n; i++) {
//         fscanf(fp, "%d [^\t] %d %d %d", 
//                &arr[i].id, &arr[i].name, &arr[i].age, &arr[i].height, &arr[i].weight);
//     }
//     fclose(fp);
//     printf("Data loaded successfully!\n");
// }

// void displayData() {
//     printf("Id\tName\t\t\tAge\tHeight\tWeight(pound)\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d\t%-15s\t%d\t%d\t%d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
//     }
// }

// void insertMin-heap(struct person p){
//     if(heap_size == n){
//         printf(" Heap is full. Cannot insert a new person data.");
//         return;
//     }
//     heap_size++;
//     int i = heap_size-1;
//     heap[i] = p;
//     while( i!=0 && minHeap[(i-1)/2].age > minHeap[i].age){
//         swap(&minHeap[i], &minHeap[(i-1)]/2);
//         i = (i-1)/2;
//     }
// }


// int main(){
//    int choice;
//    char filename[50] = "students.txt"; 
//     do{
//         printf("Menu: \n");
//         printf("1. Read Data from File\n");
//         printf("2. Create a Min-heap based on the age\n");
//         printf("3. Create a Max-heap based on the weight\n");
//         printf("4. Display weight of the youngest person\n");
//         printf("5. Insert a new person into the Min-heap\n");
//         printf("6. Delete the oldest person");
//         printf("7. EXIT \n");

//         int choice;
//         printf("Enter your choice:");
//         scanf("%d", &choice);
//         switch(choice){
//             case 1: 
//                 readData(filename);
//                 break;
//             case 2:
//                 struct person* minHeap;
//                 createMinHeap();
//                 break;
//             case 3:
//                 createMaxHeap();
//                 break;
//             case 4:
//                 displayYoungesWeight();
//                 break;
//             case 5:
//                 insertPerson();
//                 break;
//             case 6:
//                deleteOldestPerson();
//                break;
//             case 7:
//                exit(0);
//                break;
//             default: 
//                printf("Invalid choice. Please try again. \n");  
//         }
//     }

// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char name[100];
    int age;
    int height;
    int weight;
};

struct person* arr = NULL;
int n = 0;
int heap_size = 0;
struct person* heap = NULL;

void swap(struct person* a, struct person* b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < heap_size && heap[l].age < heap[smallest].age) smallest = l;
    if (r < heap_size && heap[r].age < heap[smallest].age) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}
void buildMinHeap() {
    for (int i = heap_size/2 - 1; i >= 0; i--) minHeapify(i);
}

void maxHeapify(int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < heap_size && heap[l].weight > heap[largest].weight) largest = l;
    if (r < heap_size && heap[r].weight > heap[largest].weight) largest = r;
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(largest);
    }
}
void buildMaxHeap() {
    for (int i = heap_size/2 - 1; i >= 0; i--) maxHeapify(i);
}

void readData(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Could not open file %s\n", filename);
        return;
    }
    fscanf(fp, "%d", &n);
    arr = (struct person*) malloc(n * sizeof(struct person));
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d %[^\t] %d %d %d", 
               &arr[i].id, arr[i].name, &arr[i].age, &arr[i].height, &arr[i].weight);
    }
    fclose(fp);
    printf("Data loaded successfully!\n");
}

void displayData() {
    printf("Id\tName\t\t\tAge\tHeight\tWeight\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-15s\t%d\t%d\t%d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }
}

void displayYoungestWeight() {
    if (heap_size == 0) {
        printf("Heap is empty!\n");
        return;
    }
    float kg = heap[0].weight * 0.453592;
    printf("Weight of youngest student: %.2f kg\n", kg);
}

void insertMinHeap(struct person p) {
    heap_size++;
    heap = realloc(heap, heap_size * sizeof(struct person));
    int i = heap_size - 1;
    heap[i] = p;
    while (i != 0 && heap[(i-1)/2].age > heap[i].age) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main() {
    int choice;
    char filename[50] = "students.txt";
    do {
        printf("\nMenu:\n");
        printf("1. Read Data from File\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                readData(filename);
                displayData();
                break;
            case 2:
                heap_size = n;
                heap = malloc(n * sizeof(struct person));
                memcpy(heap, arr, n * sizeof(struct person));
                buildMinHeap();
                printf("Min-heap created on Age.\n");
                break;
            case 3:
                heap_size = n;
                heap = malloc(n * sizeof(struct person));
                memcpy(heap, arr, n * sizeof(struct person));
                buildMaxHeap();
                printf("Max-heap created on Weight.\n");
                break;
            case 4:
                displayYoungestWeight();
                break;
            case 5: {
                struct person p;
                printf("Enter Id Name Age Height Weight: ");
                scanf("%d %s %d %d %d", &p.id, p.name, &p.age, &p.height, &p.weight);
                insertMinHeap(p);
                printf("Inserted successfully!\n");
                break;
            }
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 6);

    free(arr);
    free(heap);
    return 0;
}
