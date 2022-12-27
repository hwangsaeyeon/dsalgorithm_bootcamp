#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int fibo(int n){
    int fibo[45];
    int i;
    fibo[0]=0;
    fibo[1]=1;
    for (i=2;i<n+2;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    return fibo[n];
    
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d",fibo(n));
    
}
