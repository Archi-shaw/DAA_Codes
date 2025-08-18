#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the size  of the array:");
    scanf("%d" , &n);
    int arr[n];
    for(int i=0;i<n;++i){
        scanf("%d", & arr[i]);
    }
    int res[n]; res[0] =arr[0];
    printf("%d ", res[0]);
    for(int i=1;i<n;++i){
       res[i] = res[i-1]+ arr[i];
       printf("%d " , res[i]);
    }
}