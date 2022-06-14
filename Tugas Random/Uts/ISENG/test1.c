#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct burung{
        char nama[20];
        char kode[50];
        int jml_bagus,ranking;
        float nilai,komponen;
        }rayyan[20],arrrayyan[20],rayyantemp;

struct isikomponen{
        int nilai_dasar;
        char kode[10];
        char faktor[10];
        char unik[10];
        }komp[10],arrkomponen[10];

void isidata() {
    FILE* fp;
    fp = fopen("burung.txt", "w");

    strcpy(rayyan[0].nama, "Mahadewa");
    strcpy(rayyan[0].kode, "B01");
    fwrite(&rayyan[0], sizeof(rayyan[0]), 1, fp);

    strcpy(rayyan[1].nama, "Si Gacor");
    strcpy(rayyan[1].kode, "B02");
    fwrite(&rayyan[1], sizeof(rayyan[1]), 1, fp);

    strcpy(rayyan[2].nama, "Manis Manja");
    strcpy(rayyan[2].kode, "K01");
    fwrite(&rayyan[2], sizeof(rayyan[2]), 1, fp);

    fclose(fp);
}

void isikomponen()  {
    FILE* fkomponen = fopen("komponen.txt", "w");

    strcpy(komp[0].kode, "B01");
    strcpy(komp[0].faktor, "Suara");
    komp[0].nilai_dasar = 60;
    strcpy(komp[0].unik, "Gacor");
    fwrite(&komp[0], sizeof(komp[0]), 1, fkomponen);

    strcpy(komp[1].kode, "B02");
    strcpy(komp[1].faktor, "Suara");
    komp[1].nilai_dasar = 85;
    strcpy(komp[1].unik, "Nyaring");
    fwrite(&komp[1], sizeof(komp[1]), 1, fkomponen);

    strcpy(komp[2].kode, "K01");
    strcpy(komp[2].faktor, "Suara");
    komp[2].nilai_dasar = 70;
    strcpy(komp[2].unik, "Merdu");
    fwrite(&komp[2], sizeof(komp[2]), 1, fkomponen);

    strcpy(komp[3].kode, "B01");
    strcpy(komp[3].faktor, "Badan");
    komp[3].nilai_dasar = 70;
    strcpy(komp[3].unik, "Gagah");
    fwrite(&komp[3], sizeof(komp[3]), 1, fkomponen);

    strcpy(komp[4].kode, "B02");
    strcpy(komp[4].faktor, "Badan");
    komp[4].nilai_dasar = 85;
    strcpy(komp[4].unik, "Besar");
    fwrite(&komp[4], sizeof(komp[4]), 1, fkomponen);

    strcpy(komp[5].kode, "K01");
    strcpy(komp[5].faktor, "Badan");
    komp[5].nilai_dasar = 70;
    strcpy(komp[5].unik, "-");
    fwrite(&komp[5], sizeof(komp[5]), 1, fkomponen);

    fclose(fkomponen);
}
    void isi_burung()
    {
        int i,jml_sementara[10];
        float multiplier,nilaisementara[10];
        FILE* fburung = fopen("burung.txt","a");
        FILE* fkomponen = fopen("komponen.txt","r");
        fread(&arrrayyan[i],sizeof(arrrayyan[i]),1,fburung);
        fread(&arrkomponen[i],sizeof(arrkomponen[i]),1,fkomponen);
        for(i=0;i<6;i++){
            if (strcmp(arrkomponen[i].unik,"Gacor") == 0){multiplier=1.3;}
            else if(strcmp(arrkomponen[i].unik,"Nyaring") == 0){multiplier=1.4;}
            else if(strcmp(arrkomponen[i].unik,"Merdu") == 0){multiplier=1.5;}
            else if(strcmp(arrkomponen[i].unik,"Gagah") == 0){multiplier=1.3;}
            else if(strcmp(arrkomponen[i].unik,"Besar") == 0){multiplier=1.25;}
            else if(strcmp(arrkomponen[i].unik,"-") == 0){multiplier=1;}
            nilaisementara[i] = (float)arrkomponen[i].nilai_dasar*multiplier;
            jml_sementara[i]=0;
            if(arrkomponen[i].nilai_dasar>80 || (strcmp(arrkomponen[i].unik,"-") != 0)){jml_sementara[i]=1;}
            printf("Kode %s, Faktor %s dan Nildasar %d memiliki nilai %f\n",arrkomponen[i].kode,arrkomponen[i].faktor,arrkomponen[i].nilai_dasar, nilaisementara[i]);
                }
        for(i=0;i<3;i++){
            arrrayyan[i].jml_bagus=jml_sementara[i]+jml_sementara[i+3];
            arrrayyan[i].komponen=nilaisementara[i]+nilaisementara[i+3];
            arrrayyan[i].nilai=arrrayyan[i].komponen*arrrayyan[i].jml_bagus;
            
            printf("%s bernilai %f dan Jml_bagus %d dan nilai akhir %f\n",arrrayyan[i].nama,arrrayyan[i].komponen,arrrayyan[i].jml_bagus,arrrayyan[i].nilai);
        }
        fwrite(&arrrayyan, sizeof(arrrayyan), 1, fburung);
        fclose(fburung);
        fclose(fkomponen);
    }

    void tampilkanburung()
    {
        int i;
        FILE *fburung = fopen("burung.txt","r");
        for(i=0;i<3;i++){
            fread(&arrrayyan[i],sizeof(arrrayyan[i]),1,fburung);
            printf("%s\t%s\t%f\t%f\t%d\n",arrrayyan[i].kode,arrrayyan[i].nama,arrrayyan[i].komponen,arrrayyan[i].nilai,arrrayyan[i].ranking);
        }
        printf("\n");
        fclose(fburung);
    }

    void tampilkankomp()
    {
        int i;
        FILE *fkomponen = fopen("komponen.txt","r");
        printf("Data komponen dari file komponen.txt\n");
        for(i=0;i<6;i++){
            fread(&arrkomponen[i],sizeof(arrkomponen[i]),1,fkomponen);
            printf("%s\t%s\t%d\t%s\n",arrkomponen[i].kode,arrkomponen[i].faktor,arrkomponen[i].nilai_dasar,arrkomponen[i].unik);
        }
        fclose(fkomponen);
    }

    void urut()
    {
        int i;
        FILE *fburung = fopen("burung.txt","r");
        fread(&arrrayyan[i],sizeof(arrrayyan[i]),1,fburung);
        printf("Data burung sebelum diurutkan : \n");
        for(i=0;i<3;i++){
        printf("%s\t%s\t%f\t%f\t%d\n",arrrayyan[i].kode,arrrayyan[i].nama,arrrayyan[i].komponen,arrrayyan[i].nilai,arrrayyan[i].ranking);
        }
    }

    void mode()
    {
        int status=0;
        int pil;
        printf("Masukkan [1] untuk memasukkan data kedalam burung.txt\n");
        printf("Masukkan [2] untuk memasukkan data kedalam komponen.txt\n");
        printf("Masukkan [3] untuk menampilkan data burung.txt\n");
        printf("Masukkan [4] untuk menampilkan data komponen.txt\n");
        printf("Masukkan [5] untuk melanjutkan input Array Burung\n");
        printf("Masukkan [6] untuk melakukan pengurutan\n");
        while(status==0){
        printf("Input : ");
        scanf("%d",&pil);
        switch(pil){
            case 1 : isidata();break;
            case 2 : isikomponen();break;
            case 3 : tampilkanburung();break;
            case 4 : tampilkankomp();break;
            case 5 : isi_burung();break;
            case 6 : urut();status=1;break;
               }}
    }

int main()
{
    mode();
}