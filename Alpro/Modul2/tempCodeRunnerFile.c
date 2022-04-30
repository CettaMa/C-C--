#include <stdio.h>
#include <stdlib.h>

int main() {
    int numb1,numb2,hasil;
    char operator;

    printf("nama : Cetta Maulana Andhika\nNIM : 1103213119\nOperator : ");
    scanf("%c",&operator);
    fflush(stdin);
    printf("numb1 :");
    scanf("%d",&numb1);
    printf("numb2 : ");
    scanf("%d",&numb2);
    printf("====OUTPUT====\n");

    if (operator=='+')
    {
        hasil=numb1+numb2;
        printf("%d + %d = %d\n",numb1,numb2,hasil);
    } else if (operator=='-')
    {
        hasil=numb1-numb2;
        printf("%d - %d = %d\n",numb1,numb2,hasil);
    }else if (operator=='*')
    {
        hasil=numb1*numb2;
        printf("%d * %d = %d\n",numb1,numb2,hasil);
    }else if (operator=='/')
    {
        hasil=numb1/numb2;
        printf("%d / %d = %d\n",numb1,numb2,hasil);
    }else if (operator=='%')
    {
        hasil=numb1%numb2;
        printf("%d mod %d = %d\n",numb1,numb2,hasil);
    }
    
}