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
}komp,arrkomp[10],tempkom;

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
    strcpy(cetta.nama,"Manis Mnja");
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

    switch (mode)
    {
    case 0:
        printf("Mengisi array...\n");
        fp=fopen ("burung.txt","r");
        for (i = 0; i < n; i++)
        {
            fread(&arrcma[i],sizeof(arrcma[i]),1,fp);
        }
        printf("Mengisi array selesai!\n");
        fclose(fp);
        break;
    
    case 1:
        printf("mengisi array komponen...\n");
        fj=fopen ("komponen.txt","r");
        for ( i = 0; i < m; i++)
        {
            fread(&arrkomp[i],sizeof(arrkomp),1,fj);
        }
        printf("Mengisi array komponen selesai!\n");
        fclose(fj);
        break;

    case 2:
        printf("Data burung dari burung.txt\n");
        for ( i = 0; i < n; i++)
        {
            printf("%d\t%s\t%.2f\t%f\n",arrcma[i].kode,arrcma[i].nama,arrcma[i].komponen,arrcma[i].nilai);
        }
        printf("\n");
        break;
    
    default:
        printf("data komponen dari file komponen.txt\n");
        for ( i = 0; i < m; i++)
        {
            printf("%d\t%s\t%d\t%s\n",arrkomp[i].kode,arrkomp[i].faktor,arrkomp[i].nilai_dasar,arrkomp[i].unik);
        }
        printf("\n");
        break;
    }   
}

// void isi_burung(){
//     FILE *fp;
//     FILE *fj;

//     fp = fopen("burung.txt","r+");
//     fj = fopen("komponen.txt","r+");
//     for ( i = 0; i < n; i++)
//     {
//         float totalnilai=0;
//         for ( j = 0; j < m; j++)
//         {
//             if (arrcma[i].kode==komp.kode)
//             {
//                 if (strcmp(komp.unik,"Gacor")==0){
//                     totalnilai=totalnilai+(komp.nilai_dasar*1.3);
//                 }
//                 if (strcmp(komp.unik,"Nyaring")==0){
//                     totalnilai=totalnilai+(komp.nilai_dasar*1.4);
//                 }
//                 if (strcmp(komp.unik,"Merdu")==0){
//                     totalnilai=totalnilai+(komp.nilai_dasar*1.5);
//                 }
//                 if (strcmp(komp.unik,"Gagah")==0){
//                     totalnilai=totalnilai+(komp.nilai_dasar*1.3);
//                 }
//                 if (strcmp(komp.unik,"Besar")==0){
//                     totalnilai=totalnilai+(komp.nilai_dasar*1.25);
//                 }
//                 if (komp.nilai_dasar>75 || komp.unik[0] != '-' ){
//                     arrcma[i].jml_bagus++;
//                 } else {
//                     totalnilai=totalnilai+komp.nilai_dasar;
//                 }
//             }
            
//         }
//         arrcma[i].komponen=totalnilai;
//         arrcma[i].nilai=arrcma[i].komponen*arrcma[i].jml_bagus;
//     }
//     fclose(fp);
//     fclose(fj);
// }

void isi_burung2(){
    FILE *fp;
    FILE *fj;

    fp = fopen("burung.txt","r+");
    fj = fopen("komponen.txt","r+");

    fread(&cetta,sizeof(cetta),1,fp);
    fread(&komp,sizeof(komp),1,fj);
    
    int totalnilai,jumlah,curkode;
    char curnama[20];
    float rata;

    if (feof(fj) && feof(fp))
    {
        printf("File kosong\n");
    } else {
        while (!feof(fp) && !feof(fj))
        {
            totalnilai=0;
            jumlah=0;

            curkode=cetta.kode;
            strcpy(curnama,cetta.nama);
            while (!feof(fj) && curkode==komp.kode)
            {
                if (strcmp(komp.unik,"Gacor")==0){
                    totalnilai=totalnilai+(komp.nilai_dasar*1.3);
                } else if (strcmp(komp.unik,"Nyaring")==0){
                    totalnilai=totalnilai+(komp.nilai_dasar*1.4);
                } else if (strcmp(komp.unik,"Merdu")==0){
                    totalnilai=totalnilai+(komp.nilai_dasar*1.5);
                } else if (strcmp(komp.unik,"Gagah")==0){
                    totalnilai=totalnilai+(komp.nilai_dasar*1.3);
                } else if (strcmp(komp.unik,"Besar")==0){
                    totalnilai=totalnilai+(komp.nilai_dasar*1.25);
                }
                if (komp.nilai_dasar>75 || komp.unik[0] != '-' ){
                    cetta.jml_bagus++;
                    jumlah++;
                } else {
                    totalnilai=totalnilai+komp.nilai_dasar;
                }
                fread(&komp,sizeof(komp),1,fj);
            }
            cetta.komponen=totalnilai;
            cetta.nilai=totalnilai*cetta.jml_bagus;
            printf("Burung dengan kode %d bernama %s memiliki nilai akhir %.2f\n",curkode,curnama,cetta.nilai);
            fread(&cetta,sizeof(cetta),1,fp);
        }
    }
    fclose(fj);
} 

void urut(){
    int Pass,Imax;
    FILE *fp;
    fp = fopen("komponen.txt","r+");
    printf("Sebelum Diurutkan :\n");

    for ( i = 0; i < m; i++){
        fread(&arrkomp[i],sizeof(arrkomp[i]),1,fp);
        printf("%d\t%s\t%d\t%s\n",arrkomp[i].kode,arrkomp[i].faktor,arrkomp[i].nilai_dasar,arrkomp[i].unik);
    }
    fclose(fp);
    
    printf("mengurutkan...\n");
    
    for(Pass=1;Pass<=m-1;Pass++){
        Imax=0;
        for(i=1;i<=m-Pass;i++)
            if(arrkomp[Imax].kode<arrkomp[i].kode)
                Imax=i;
        tempkom=arrkomp[Imax];
        arrkomp[Imax]=arrkomp[m-Pass];
        arrkomp[m-Pass]=tempkom;
    }
    
    fp = fopen("komponen.txt","w");
    printf("selesai diurutkan.\n");
    for ( i = 0; i < m; i++){
        fwrite(&arrkomp[i],sizeof(arrkomp[i]),1,fp);
        printf("%d\t%s\t%d\t%s\n",arrkomp[i].kode,arrkomp[i].faktor,arrkomp[i].nilai_dasar,arrkomp[i].unik);
    }
    fclose(fp);
}

// void membaca() {
//     FILE *fp;
//     fp  = fopen("burung.txt","r+");
//     printf("Membaca file...\n");
//     for ( i = 0; i < n; i++)
//     {
//         fread(&arrcma,sizeof(arrcma),1,fp);
//     }
//     printf("membaca file selesai.\n");
//     fclose(fp);
// }

int main() {
    isinilai();
    for ( j = 0; j < 4; j++)
    {
        darifile(j);
    }
    urut();
    printf("Menghitung data...\n");
    isi_burung2();
    printf("Selesai!\n");

}