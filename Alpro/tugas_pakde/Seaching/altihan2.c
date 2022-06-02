#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,n;

struct altihan2
{
    char nama[20];
    int nim;
    char kelas[20];
}mahasiswa[20];

void procarinim(int nim,int *indeks){
    i=0;
    mahasiswa[n].nim=nim;

    while (mahasiswa[i].nim!=nim)
    {
        i=i+1;
    }
    if (i<n)
    {
        *indeks=i;
    } else {
        *indeks=-1;
    }
    
}

int main(){
    int carinim,indeksnim;
    printf("Masukan jumlah mahasiswa\t:");
    scanf("%d",&n);
    scanf("%*c");
    for ( i = 0; i < n; i++)
    {
        printf("Nama\t:");
        fgets(mahasiswa[i].nama,20,stdin);
        strtok(mahasiswa[i].nama,"\n");
        printf("NIM\t:");
        scanf("%d",&mahasiswa[i].nim);
        scanf("%*c");
        printf("Kelas\t:");
        fgets(mahasiswa[i].kelas,20,stdin);
        strtok(mahasiswa[i].kelas,"\n");
        printf("%s %d %s\n",mahasiswa[i].nama,mahasiswa[i].nim,mahasiswa[i].kelas);
    }
    
    printf("Masukan nim yang ingin dicari\t:");
    scanf("%d",&carinim);
    procarinim(carinim,&indeksnim);
    if (indeksnim==-1)
    {
        printf("Mahasiswa tidak ditemukan\n");
    } else {
        printf("mahasiswa ditemukan\nNama\t:%s\nKelas\t:%s\n",mahasiswa[indeksnim].nama,mahasiswa[indeksnim].kelas);
    }
    
}