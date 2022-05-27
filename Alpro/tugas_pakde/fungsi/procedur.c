#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,n;

void inputdata(int n,int *y) {
        printf("Masukan data array X ke-%d\t:",i+1);
        scanf("%d",&*y);
}

void output(int i, int y) {
    printf("data X[%d] adalah\t:%d\n",i+1,y);
}

int main(){
    printf("Masukan Jumlah data\t:");
    scanf("%d",&n);
    int x[n];
    for ( i = 0; i < n; i++){
        inputdata(n,&x[i]);
    }
    for ( i = 0; i < n; i++)
    {
        output(i,x[i]);
    }
}