//백준 8589
//OX 퀴즈

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS


int main(){
    int i,n;
    int j,sum,temp;
    char test[80] = {};
    int l,length;
    
    scanf("%d",&n);
    
    for (i=0;i<n;i++){
        
        sum=0;
        temp=1;
        length=0;
        
        scanf("%s",test);

        for (l=0; test[l]!='\0'; l++)
            length++;

        for (j=0;j<length;j++)
        {
            if (test[j] == 'X')
            {
                sum+=0;
                temp=1;
            }
            else if ((test[j-1]!='O')==1)
            {
                sum+=1;
                
            }
            else
            {
                temp+=1;
                sum+=temp;
            }
        }
        printf("%d\n",sum);
        
    }
    
    return 0; 
}

