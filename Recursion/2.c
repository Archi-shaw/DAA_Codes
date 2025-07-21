#include <stdio.h>
#include <stdlib.h>

int gcd(int n1, int n2){
    if(n2 != 0){
        return gcd(n2,(n1%n2));
    }
        return n1;   
}

int main(){
    int n;
    printf("Enter no of pairs:");
    scanf("%d", &n);
    int result[n];
    for(int i=0;i<n;i++){
    int n1,n2;
    printf("Enter n1: \n");
    scanf("%d", &n1);
    printf("Enter n2 \n");
    scanf("%d", &n2);
    result[i] = gcd(n1,n2);
    }
    for(int i=0;i<n;i++){
        printf("%d \n", result[i]);
    }
}