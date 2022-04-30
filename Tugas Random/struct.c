#include <stdio.h>
#include <stdlib.h>

int main() {
    struct data
    {
        char nama[30];
        int nim;
        int nilai;
        char indeks[15];
    } Mahasiswa;
    
    printf("Masukan nama anda!\n=");
    fgets(Mahasiswa.nama,30,stdin);
    fflush(stdin);
    strtok();
    printf("Masukan Nim anda!\n=");
    scanf("%d",&Mahasiswa.nim);
    printf("Masukan nilai anda!\n=");
    scanf("%d",&Mahasiswa.nilai);
    if (Mahasiswa.nilai > 70)
    {
        strcpy(Mahasiswa.indeks,"Lulus");
    }
    else {
        strcpy(Mahasiswa.indeks,"Tidak Lulus");
    }
    printf("Nama = %s\nDengan NIM = %d\nDinyatakan %s",Mahasiswa.nama,Mahasiswa.nim,Mahasiswa.indeks);
}