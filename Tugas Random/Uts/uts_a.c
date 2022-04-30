#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int n=3,m=6,i,j;
struct burung
{
    int kode;
    float komponen;
    char nama[20];
    int jml_bagus;
    float nilai;
    int rangking;
}cetta,arrcma[10],temp;

struct elemen
{
    int kode;
    char faktor[10];
    int nilai_dasar;
    char unik[10];
}komp,arrkom[10];

void isinilai() {
    printf("Mengisi data...\n");
    FILE *fp;
    FILE *fj;

    fp = fopen("burung.txt","w");
    fj =fopen("komponen.txt","w");

    strcpy(cetta.nama,"Mahadewa");
    cetta.kode=101;
    fwrite(&cetta, sizeof(cetta),1,fp);
    strcpy(cetta.nama,"Si Gacor");
    cetta.kode=102;
    fwrite(&cetta, sizeof(cetta),1,fp);
    strcpy(cetta.nama,"Manis Manja");
    cetta.kode=103;
    fwrite(&cetta, sizeof(cetta),1,fp);

    komp.kode=101;
    strcpy(komp.faktor,"suara");
    komp.nilai_dasar=60;
    strcpy(komp.unik,"Gacor");
    fwrite(&komp, sizeof(komp),1,fj);

    komp.kode=102;
    strcpy(komp.faktor,"suara");
    komp.nilai_dasar=85;
    strcpy(komp.unik,"Nyaring");
    fwrite(&komp, sizeof(komp),1,fj);

    komp.kode=103;
    strcpy(komp.faktor,"suara");
    komp.nilai_dasar=70;
    strcpy(komp.unik,"Merdu");
    fwrite(&komp, sizeof(komp),1,fj);

    komp.kode=101;
    strcpy(komp.faktor,"badan");
    komp.nilai_dasar=70;
    strcpy(komp.unik,"Gagah");
    fwrite(&komp, sizeof(komp),1,fj);

    komp.kode=102;
    strcpy(komp.faktor,"badan");
    komp.nilai_dasar=85;
    strcpy(komp.unik,"Besar");
    fwrite(&komp, sizeof(komp),1,fj);

    komp.kode=103;
    strcpy(komp.faktor,"badan");
    komp.nilai_dasar=70;
    strcpy(komp.unik,"-");
    fwrite(&komp, sizeof(komp),1,fj);

    fclose(fj);
    fclose(fp);
    printf("Data telah diisi!\n");
}

void darifile(int mode) {
    FILE *fp;
    FILE *fj;

    if (mode==0)
    {
        printf("Mengisi array...\n");
        fp=fopen ("burung.txt","r");
        for (i = 0; i < n; i++)
        {
            fread(&arrcma[i],sizeof(arrcma[i]),1,fp);
        }
        printf("Mengisi array selesai!\n");
        fclose(fp);
    }
    if (mode==1)
    {
        printf("mengisi array komponen...\n");
        fj=fopen ("komponen.txt","r");
        for ( i = 0; i < m; i++)
        {
            fread(&arrkom[i],sizeof(arrkom),1,fj);
        }
        printf("Mengisi array komponen selesai!\n");
        fclose(fj);
    }
    if (mode==2)
    {
        printf("Data burung dari burung.txt\n");
        for ( i = 0; i < n; i++)
        {
            printf("%d\t%s\t%.2f\t%f\n",arrcma[i].kode,arrcma[i].nama,arrcma[i].komponen,arrcma[i].nilai);
        }
        printf("\n");
    }
    if (mode==3)
    {
        printf("data komponen dari file komponen.txt\n");
        for ( i = 0; i < m; i++)
        {
            printf("%d\t%s\t%d\t%s\n",arrkom[i].kode,arrkom[i].faktor,arrkom[i].nilai_dasar,arrkom[i].unik);
        }
        printf("\n");
    }    
}

void isi_burung(){
    FILE *fp;
    FILE *fj;

    fp = fopen("burung.txt","r+");
    fj = fopen("komponen.txt","r+");
    for ( i = 0; i < n; i++)
    {
        float nilai_faktor=0;
        for ( j = 0; j < m; j++)
        {
            if (arrcma[i].kode==arrkom[j].kode)
            {
                if (strcmp(arrkom[j].unik,"Gacor")==0){
                    nilai_faktor=nilai_faktor+(arrkom[j].nilai_dasar*1.3);
                }
                if (strcmp(arrkom[j].unik,"Nyaring")==0){
                    nilai_faktor=nilai_faktor+(arrkom[j].nilai_dasar*1.4);
                }
                if (strcmp(arrkom[j].unik,"Merdu")==0){
                    nilai_faktor=nilai_faktor+(arrkom[j].nilai_dasar*1.5);
                }
                if (strcmp(arrkom[j].unik,"Gagah")==0){
                    nilai_faktor=nilai_faktor+(arrkom[j].nilai_dasar*1.3);
                }
                if (strcmp(arrkom[j].unik,"Besar")==0){
                    nilai_faktor=nilai_faktor+(arrkom[j].nilai_dasar*1.25);
                }
                if (arrkom[j].nilai_dasar>75 || arrkom[j].unik[0] != '-' ){
                    arrcma[i].jml_bagus++;
                } else {
                    nilai_faktor=nilai_faktor+arrkom[j].nilai_dasar;
                }
            }
            
        }
        arrcma[i].komponen=nilai_faktor;
        arrcma[i].nilai=arrcma[i].komponen*arrcma[i].jml_bagus;
    }
    fclose(fp);
    fclose(fj);
}

void urut(){
    int pass;
    FILE *fp;
    fp = fopen("burung.txt","r+");
    printf("Sebelum Diurutkan :\n");

    for ( i = 0; i < n; i++){
        printf("%d\t%s\t%.2f\t%f\t%d\n",arrcma[i].kode,arrcma[i].nama,arrcma[i].komponen,arrcma[i].nilai,arrcma[i].rangking);
    }
    
    printf("mengurutkan...\n");
    for ( pass = 0; pass < n; pass++){
        for ( i = pass+1; i < n; i++){
            if (arrcma[pass].nilai<arrcma[i].nilai){
                temp = arrcma[pass];
                arrcma[pass]=arrcma[i];
                arrcma[i]=temp;
            } 
        }
    }
    printf("selesai diurutkan.\n");
    for ( i = 0; i < n; i++){
        arrcma[i].rangking=i+1;
        fwrite(&arrcma[i],sizeof(arrcma[i]),1,fp);
        printf("%d\t%s\t%.2f\t%f\t%d\n",arrcma[i].kode,arrcma[i].nama,arrcma[i].komponen,arrcma[i].nilai,arrcma[i].rangking);
    }
    fclose(fp);
}

void membaca() {
    FILE *fp;
    fp  = fopen("burung.txt","r+");
    printf("Membaca file...\n");
    for ( i = 0; i < n; i++)
    {
        fread(&arrcma,sizeof(arrcma),1,fp);
    }
    printf("membaca file selesai.\n");
}

int main() {
    isinilai();
    for ( j = 0; j < 4; j++)
    {
        darifile(j);
    }
    printf("Menghitung data...\n");
    isi_burung();
    printf("Selesai!\n");
    urut();
    membaca();
    printf("Juara lomba adalah %s dengan nilai %.2f\n",arrcma[0].nama,arrcma[0].nilai);
}