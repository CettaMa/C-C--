#include<stdio.h>
#include<stdlib.h>

int main(){
    int x[2][2];
    int y[2][2];
    int z[2][2];
    int i;
    int b;

    printf("====Matrix X====\n");
    for (i=0;i<2;i++){
        for(b=0;b<2;b++){
            printf("Masukkan Nilai matrik baris %d kolom %d :",i+1,b+1);
            scanf("%d",&x[i][b]);
        }
    }
    for (i=0;i<2;i++){
    printf("| ");
    for(b=0;b<2;b++){
    printf("%d",x[i][b]);
    }
    printf(" |\n");
    }
    printf("====Matrix Y====\n");
    for (i=0;i<2;i++){
        for(b=0;b<2;b++){
        printf("Masukkan Nilai matrik baris %d kolom %d : ",i+1,b+1);scanf("%d",&y[i][b]);
        }
    }  
    for (i=0;i<2;i++){
        printf("| ");
        for(b=0;b<2;b++){
            printf("%d",y[i][b]);
        }
    printf(" |\n");
    }
    for (i=0;i<2;i++){
        for(b=0;b<2;b++){
        z[i][b]=x[i][b]+y[i][b];
    }
    }
    printf("Hasil penjumlahan matrix X dan Y\n");
    for (i=0;i<2;i++){
        printf("| ");
        for(b=0;b<2;b++){
            printf("%d",z[i][b]);
        }
        printf(" |\n");
    }
}