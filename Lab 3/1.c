#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
   int n = (rand() % 20) + 1;
    printf("Array size: %d\n", n);
    
    long long arr[n];
        for(int i = 0; i < n; i++){
        arr[i] = (rand() % 100) + i * 2; 
    }
    
    printf("sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%lld ", arr[i]);
    }
    printf("\n");
    
    long long key = rand() % 120; 
    printf("Searching for key: %lld\n", key);
    
    int left = 0, right = n - 1, comp = 0, index = -1; 
    
    while(left <= right){ 
        int mid = left + (right - left) / 2; 
        comp++;
        
        if(arr[mid] == key){
            index = mid;
            break;
        }
        else if(arr[mid] < key){
            left = mid + 1; 
        }
        else{
            right = mid - 1;
        }
    }
    
    if(index == -1){
        printf("Element not found\n");
        printf("Number of comparisons: %d\n", comp);
        printf("WORST CASE\n");
    }
    else{
        printf("%lld is found at index %d\n", key, index);
        printf("Number of comparisons: %d\n", comp);
        
        if(comp == 1){
            printf("BEST CASE\n");
        }
        else{
            printf("AVERAGE CASE\n");
        }
    }
    
    return 0;
}