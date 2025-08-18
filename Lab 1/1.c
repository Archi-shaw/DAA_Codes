#include<stdio.h>
#include<stdlib.h>

void sortArray(int arr[], int n){    // Using bubble sort for sorting the array
   for(int i=0;i<n-1;++i){
    for(int j=0;j<n-i-1;++j){
        if(arr[j] > arr[j+1]){
            int temp = arr[j];
             arr[j] = arr[j+1];
             arr[j+1] = temp;
        }
    }
   }
}

int main(){
    FILE *fp;
    int n;
    fp = fopen("input.txt" , "r"); // taking input in a file
    if(fp == NULL){
        printf("couldn't open file \n"); // edge cases 
        return 1;
    }
    fscanf(fp , "%d" , &n);  // Taking input for the size of the array 
    if(n<2){  // edge case 
        printf("Needs atleast two element");
        fclose(fp);  // closing the file once 
        return 1;
    }
    int arr[n];
    for(int i=0;i<n;i++){
        fscanf(fp , "%d" ,&arr[i]); // Taking input of the array in the file
    }
    fclose(fp);
    sortArray(arr,n);
    int secondLargest = -1, secondsmalllest =-1;
    for(int i = 0;i<n;++i){    // Computing second smallest no
        if( arr[i] != arr[0]){
            secondsmalllest = arr[i];
            break;
        }
    }
    for(int i = n-2;i>=0;--i){             // Computing second Largest no
        if( arr[i] != arr[n-1]){
            secondLargest = arr[i];
            break;
        }
    }
    if(secondsmalllest == -1 && secondLargest == -1){      // Edge case
        printf(" Second Largest and second smallest element not found");
    }
    else{
    printf(" Second Largest %d" , secondLargest);
    printf("Second Smallest %d" , secondsmalllest);
}
return 0;
}