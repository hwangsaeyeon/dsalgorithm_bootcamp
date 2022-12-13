//비밀지도

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>

int main(){
    int num,i;
    int arr1[16] = {0};
    int arr2[16] = {0};
    int val1, val2;
    
    
    do{
        printf("정수 n 입력 (1<=n<=16) : ");
        scanf("%d", &num);
    } while ((num >= 1 & num<=16)==0);
    
    int square = pow(2,num);
    
    for (i=0 ; i<num ; i++)
    {
        do{
            printf("array1 값 입력 : ");
            scanf("%d", &val1);
        } while((val1>=0 & val1<=square-1)==0);
        arr1[i] = val1;
        
    }
    
    for (i=0 ; i<num ; i++)
    {
        do{
            printf("array2 값 입력 : ");
            scanf("%d", &val2);
        } while((val2>=0 & val2<=square-1)==0);
        arr2[i] = val2;
        
    }
    
    int j, or=0, m, n;
    char result[16] = "";
    for (i=0 ; i<num ; i++){
        
        or = (arr1[i]|arr2[i]);
        for (j=num-1 ; j>=0 ; j--){
            m = or / 2;
            n = or % 2;
            or = m;
            
            if (n == 1)
                result[j] = '#';
            else
                result[j] = ' ';
            
        }
        printf(result);
        printf("    \n");
        
    }
}
