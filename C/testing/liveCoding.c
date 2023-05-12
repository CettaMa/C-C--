#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // int panjang,i=0,x,y, tinggi=0;

    // scanf("%d",&tinggi);
    // panjang=tinggi*2-1;
    // for ( i = 0; i < tinggi; i++)
    // {
    //     for ( x = 0; x < panjang; x++)
    //     {   
    //         if (x==panjang/2)
    //         {
    //             printf("*");
    //         }
    //         else {
    //             printf(" ");
    //         }
    //     }

    //     printf("\n");
    // }

    int n,i,x,y,temp;
    printf("Masukan banyak angka : ");
    scanf("%d",&n);
    int arrnumber[n];
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arrnumber[i]);
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arrnumber[i]);
    }
    print("\n")
    for ( x = 0; x < n; x++)
    {
        for ( y = 0; y <= n; y++)
        {    
        if (arrnumber[y]>arrnumber[y+1])
        {
            temp=arrnumber[y+1];
            arrnumber[y+1]=arrnumber[y];
            arrnumber[y]=temp;
        }
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arrnumber[i]);
    }
    
}
}
