#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,n,ketemu;
struct data
{
    int nim;
    char nama[20];
    char kelas[20];
}mahasiswa[30],temp;

void carinim(int *indeks,int nimcari){
    int awal,tengah,akhir;
    awal=0;
    akhir=n-1;
    tengah=(awal+akhir)/2;

    while ((awal<=akhir) && (nimcari!=mahasiswa[tengah].nim)){
        if (nimcari<mahasiswa[tengah].nim){
            akhir=tengah-1;
        }
        if (nimcari>mahasiswa[tengah].nim){
            awal=tengah+1;
        }
        tengah=(awal+akhir)/2;
        printf("mid :%d\n",tengah);
    }
    if (nimcari==mahasiswa[tengah].nim){
        ketemu=1;
        *indeks=tengah;
    } else {
        *indeks=-1;
    }
}

void urut(){
    int j;
    printf("mengurutkan...\n");

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-1; j++)
        {
            if (mahasiswa[j].nim>mahasiswa[j+1].nim)
            {
                temp=mahasiswa[j];
                mahasiswa[j]=mahasiswa[j+1];
                mahasiswa[j+1]=temp;
            }
        }
    }
    printf("Selesai!\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d %s\n",mahasiswa[i].nim,mahasiswa[i].nama);
    }
}

int main(){
    int indeksnim,cari;
    printf("Jumlah\t:");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("Nim\t:");
        scanf("%d",&mahasiswa[i].nim);
        scanf("%*c");
        printf("Nama\t:");
        fgets(mahasiswa[i].nama,20,stdin);
        strtok(mahasiswa[i].nama,"\n");
        printf("Kelas\t:");
        fgets(mahasiswa[i].kelas,20,stdin);
        strtok(mahasiswa[i].kelas,"\n");
    }
    printf("Masukan Nim yang dicari\t:");
    scanf("%d",&cari);

    urut();
    
    carinim(&indeksnim,cari);

    if (indeksnim==-1)
    {
        printf("Mahasiswa tidak ditemukan\n");
    } else {
        printf("Nama\t:%s\nKelas\t:%s\n",mahasiswa[indeksnim].nama,mahasiswa[indeksnim].kelas);
    }
    
}