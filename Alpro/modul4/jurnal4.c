#include <stdio.h>
#include <stdlib.h>

int main() {
   /* int nim[10];
    int i;

    for ( i = 0; i <=9; i++)
    {
        printf("Isi array ke-%d :",i);
        scanf("%d",&nim[i]);
    }
    printf("NIM :");
    for (i = 0; i <=9; i++)
    {
        printf("%d",nim[i]);
    }
    printf("\n");
    for (i = 6; i <=9; i++)
    {
        printf("Isi array ke-%d akan diubah menjadi :",i);
        scanf("%d",&nim[i]);
    }
    printf("NIM :");
    for (i = 0; i <=9; i++)
    {
        printf("%d",nim[i]);
    }
    printf("\n");*/

    struct data {
    char ulang;
    char NamaMhs[30];
    char NIM[10];
    int Tugas,Quis,UTS,UAS;
    float NilaiAkhir;
    }mhs[10];

    int n,i;
    printf("Jumlah Mahasiswa : ");
    scanf("%d", &n);
    scanf("%*c");
    for(i=0;i<n;i++)
    {
        
        printf("Masukkan Nama Mahasiswa\t : ");
        fgets(mhs[i].NamaMhs,30,stdin);
        strtok(mhs[i].NamaMhs,"\n");
        printf("Masukkan NIM Mahasiswa\t : ");
        fgets(mhs[i].NIM,10,stdin);
        strtok(mhs[i].NIM,"\n");
        printf("Masukkan Nilai Tugas \t : ");
        scanf("%d", &mhs[i].Tugas);
        printf("Masukkan Nilai Quis \t : ");
        scanf("%d", &mhs[i].Quis);
        printf("Masukkan Nilai UTS   \t : ");
        scanf("%d", &mhs[i].UTS);
        printf("Masukkan Nilai UAS   \t : ");
        scanf("%d", &mhs[i].UAS);
        scanf("%*c");
        mhs[i].NilaiAkhir=((0.2*(mhs[i].Tugas+mhs[i].Quis))+((mhs[i].UTS+mhs[i].UAS)));
    }
    printf("Nama\t NIM\t Tugas\t Quis\t UTS\t UAS\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", mhs[i].NamaMhs,mhs[i].NIM,mhs[i].Tugas, mhs[i].UTS, mhs[i].UAS, mhs[i].Quis, mhs[i].NilaiAkhir);
    }
    return 0;
}