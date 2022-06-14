#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n=5,m=13,i,j,k;
struct mahasiswa
{
    char nama[25];
    char nim[10];
    float ipk;
    int SKSlulus;
}mhs[10],temp,cetta;

struct komponen
{
    char nim[10];
    char namamk[10];
    int sks,uts,uas;
    char indeks;
}komp,tempkomp,arrkomp[20];


void isimhs(){
    printf("Mengisi data\n");
    FILE *fp;
    FILE *fj;
    fj=fopen("Nilai.txt","w");
    fp=fopen("Mahasiswa.txt","w");
    //megisi data mahasiswa
    strcpy(cetta.nama,"Budi Banjaran");
    strcpy(cetta.nim,"110401");
    fwrite(&cetta,sizeof(cetta),1,fp);

    strcpy(cetta.nama,"Cici Cianjuran");
    strcpy(cetta.nim,"110402");
    fwrite(&cetta,sizeof(cetta),1,fp);

    strcpy(cetta.nama,"Bandung Bondowoso");
    strcpy(cetta.nim,"110403");
    fwrite(&cetta,sizeof(cetta),1,fp);

    strcpy(cetta.nama,"Edi Dermayu");
    strcpy(cetta.nim,"110404");
    fwrite(&cetta,sizeof(cetta),1,fp);

    strcpy(cetta.nama,"Dudi Durudi");
    strcpy(cetta.nim,"110405");
    fwrite(&cetta,sizeof(cetta),1,fp);

    //megisi data komponen
    strcpy(komp.nim,"110401");
    strcpy(komp.namamk,"Fisika");
    komp.sks=3;
    komp.uts=80;
    komp.uas=85;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110402");
    strcpy(komp.namamk,"Fisika");
    komp.sks=3;
    komp.uts=70;
    komp.uas=60;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110403");
    strcpy(komp.namamk,"Fisika");
    komp.sks=3;
    komp.uts=40;
    komp.uas=35;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110403");
    strcpy(komp.namamk,"Kalkulus");
    komp.sks=4;
    komp.uts=30;
    komp.uas=30;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110404");
    strcpy(komp.namamk,"Kalkulus");
    komp.sks=4;
    komp.uts=60;
    komp.uas=65;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110405");
    strcpy(komp.namamk,"Kalkulus");
    komp.sks=4;
    komp.uts=90;
    komp.uas=70;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110401");
    strcpy(komp.namamk,"Agama");
    komp.sks=2;
    komp.uts=90;
    komp.uas=80;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110402");
    strcpy(komp.namamk,"Agama");
    komp.sks=2;
    komp.uts=75;
    komp.uas=60;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110401");
    strcpy(komp.namamk,"Binggris");
    komp.sks=3;
    komp.uts=80;
    komp.uas=85;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110402");
    strcpy(komp.namamk,"Binggris");
    komp.sks=3;
    komp.uts=70;
    komp.uas=70;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110403");
    strcpy(komp.namamk,"Binggris");
    komp.sks=3;
    komp.uts=90;
    komp.uas=80;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110404");
    strcpy(komp.namamk,"Binggris");
    komp.sks=3;
    komp.uts=30;
    komp.uas=40;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110405");
    strcpy(komp.namamk,"Binggris");
    komp.sks=3;
    komp.uts=60;
    komp.uas=50;
    fwrite(&komp,sizeof(komp),1,fj);

    printf("Mengisi Data selesai!\n\n");
    
    fclose(fp);
    fclose(fj);
}

void buatarray(int mode){
    FILE *fp;
    FILE *fj;

    switch (mode)
    {
    case 0:
        fp=fopen("Mahasiswa.txt","r");
        printf("Mengisi Array Mahasiswa...\n");
        for ( i = 0; i < n; i++)
        {
            fread(&mhs[i],sizeof(mhs[i]),1,fp);
            printf("%s\t%s\n",mhs[i].nim,mhs[i].nama);
        }
        fclose(fp);
        printf("Selesai!\n");
        break;
    
    default:
        fj=fopen("Nilai.txt","r");
        printf("Mengisi Array Nilai...\n");
        for ( i = 0; i < m; i++)
        {
            fread(&arrkomp[i],sizeof(arrkomp[i]),1,fp);
            printf("%s\t%s    \t%d\t%d\t%d\n",arrkomp[i].nim,arrkomp[i].namamk,arrkomp[i].sks,arrkomp[i].uts,arrkomp[i].uas);
        }
        printf("Selesai!\n\n");
        fclose(fj);
        break;
    }
}

void simpfile(int mode){
    FILE *fp;
    FILE *fj;

    switch (mode)
    {
    case 0:
        printf("Menyimpan File...\n");
        fp=fopen("Mahasiswa.txt","w");
        for ( i = 0; i < n; i++)
        {
            fwrite(&mhs[i],sizeof(mhs[i]),1,fp);
        }
        printf("Menyimpan selesai!\n");
        fclose(fp);
        break;
    
    default:
        printf("Menyimpan File...\n");
        fj=fopen("Nilai.txt","w");
        for ( i = 0; i < m; i++)
        {
            fwrite(&arrkomp[i],sizeof(arrkomp[i]),1,fp);
        }
        printf("Menyimpan selesai!\n");
        fclose(fj);
        break;
    }
}

int main(){
    isimhs();
    for ( j = 0; j < 2; j++)
    {
        buatarray(i);
    }
    for ( j = 0; j < 2; j++)
    {
        simpfile(j);
    }
    
}