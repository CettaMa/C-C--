#include <stdio.h>
#include <stdlib.h>

struct material{
    char nama[20],jenis[10],kualitas;
    int banyak,kode,harga,totalmasing;
    }temp,haris[50];
    void data(N){
    int i,totalmat=0,cacahmat=0,data,totalcat=0,totalbatu=0;
    float rata=0;
    printf(" Nama : Muhammad Musyaffakul Harisna, NIM : 1103213131, Kelas : TK-45-04\n");
    
    for(i=0;i<N;i++){
        printf(" Nama : ");
        fgets(haris[i].nama,20,stdin);
        strtok(haris[i].nama,"\n");
        printf(" Jenis : ");
        fgets(haris[i].jenis,10,stdin);
        strtok(haris[i].jenis,"\n");
        printf(" Kode : ");
        scanf("%d",&haris[i].kode);scanf("%*c");
        printf(" Banyaknya : ");
        scanf("%d",&haris[i].banyak);scanf("%*c");
        printf(" Kualitas : ");
        scanf("%c",&haris[i].kualitas);scanf("%*c");
        if(strcmp(haris[i].jenis,"batu")==0){
            if(haris[i].kualitas=='A'){
                haris[i].harga=2500;
            }
            else{
                haris[i].harga=3000;
            }
        }
        else{
            if(haris[i].kualitas=='A'){
                haris[i].harga=10000;
            }
            else if(haris[i].kualitas=='B'){
                haris[i].harga=15000;
            }
            else{
                haris[i].harga=20000;
            }
        }
    }
    printf("\n");
    for(i=0;i<N;i++){
        haris[i].totalmasing=haris[i].harga*haris[i].banyak;
        printf(" Nama %s Jenis %s Kode %d Kualitas %c Banyak: %d Harga: %d Total Masing = %d\n",
        haris[i].nama,haris[i].jenis,haris[i].kode,haris[i].kualitas,haris[i].banyak,haris[i].harga,haris[i].totalmasing);
        cacahmat=cacahmat+haris[i].banyak;
        totalmat=totalmat+haris[i].totalmasing;
        rata=(float)totalmat/cacahmat;
    }
    printf(" Total semua harga: %d, cacah: %d, dengan rata-rata %f\n\n",totalmat,cacahmat,rata);
    printf(" Setelah Di urutkan\n");
    for(data=0;data<N;data++){
        for(i=0;i<N;i++){
            if(haris[data].kualitas<haris[i].kualitas){
                temp=haris[data];
                haris[data]=haris[i];
                haris[i]=temp;
            }
        }
    }
    for(i=0;i<N;i++){
        printf(" Nama %s Jenis %s Kode %d Kualitas %c Banyak: %d Harga: %d Total Masing = %d\n",
        haris[i].nama,haris[i].jenis,haris[i].kode,haris[i].kualitas,haris[i].banyak,haris[i].harga,haris[i].totalmasing);
    }
    for(i=0;i<N;i++){
        if(strcmp(haris[i].jenis,"batu")==0){
            totalbatu=totalbatu+haris[i].totalmasing;
        }
        else{
            totalcat=totalcat+haris[i].totalmasing;
        }
    }

    printf(" Total Jenis Cat= %d\n Total Jenis Batu= %d\n",totalcat,totalbatu);
}

    void seq3(int N, int X, int *IX){
        int i;
        haris[N].kode=X;
        i=0;
        while (haris[i].kode!=X){
            i=i+1;
        }
        if (i<N){
            *IX=i;
        }
        else {
            *IX=-1;
        }

        for ( i = 0; i < N; i++)
        {
            printf(" Nama %s Jenis %s Kode %d Kualitas %c Banyak: %d Harga: %d Total Masing = %d\n",haris[i].nama,haris[i].jenis,haris[i].kode,haris[i].kualitas,haris[i].banyak,haris[i].harga,haris[i].totalmasing);
        }
        

    }
    int main(){
        int N,X,IX,i;
        printf(" Jumlah data = ");
        scanf("%d",&N);scanf("%*c");
        data(N);
        printf("\n Masukkan Kode yang ingin dicari : ");
        scanf("%d", &X); scanf("%*c");
        seq3(N,X,&IX);
        if(IX==-1){
            printf(" Data yang dIcari dengan kode %d Tidak ditemukan",X);
        }
        else {
            printf(" Data yang dicari : \n Nama : %s\n Jenis : %s\n kode : %d\n Banyak : %d\n Kualitas : %c\n",
                   haris[IX].nama, haris[IX].jenis,haris[IX].kode, haris[IX].banyak, haris[IX].kualitas);
        }

return 0;
}