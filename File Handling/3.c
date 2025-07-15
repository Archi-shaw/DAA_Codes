#include<stdio.h>
#include<stdlib.h>

int countDuplicate(int arr[], int n){
   int c=0;
    for(int i=0;i<n;++i){
    if(arr[i] == arr[i+1]){
        if(arr[i+1] == arr[i+2]){ break; }
        else{c++;}
    }
 }
 return c;
}

int mostRepeating(int arr[], int n){
    int most=0;
    for(int i=0;i<)
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
    fclose(fp); int dup = 0;
    for(int i=0;i<n-1;++i){
        if(arr[i] == arr[i+1]){
            dup = 1;
            break;
        }
    }
    if(dup != 1){
        printf(" Duplicate element is required");
        return 1;
    }
     countDuplicate(arr, n);

}