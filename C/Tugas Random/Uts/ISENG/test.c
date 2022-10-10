#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang{
    char kode[3];
    char nama[10];
    char jenis[10];
    int jmlbeli,hargabeli,sisa,untung;
}brg[100],temp;

struct Penjualan{
    char tanggal[10];
    int kode,jumlah,harga;
    float diskon;
}jual[100],temp2;

int i,j,k,N;


void isi_Barang(){
    ///Pengisian File Barang.txt
    FILE *fp;
    fp=fopen("Barang.txt","w");
    printf("Masukan Banyak Barang yang ingin di-inputkan: ");
    scanf("%d",&N);
    fflush(stdin);

    for (i=0;i<N;i++){
    printf("Kode Barang: ");
    fgets(temp.kode,sizeof(temp.kode),stdin);
    strtok(temp.kode,"\n");
    fflush(stdin);

    printf("Nama Barang: ");
    fflush(stdin);
    fgets(temp.nama,sizeof(temp.nama),stdin);
    strtok(temp.nama,"\n");
    fflush(stdin);

    printf("Jenis Barang: ");
    fgets(temp.jenis,sizeof(temp.jenis),stdin);
    strtok(temp.jenis,"\n");
    fflush(stdin);

    printf("Jumlah Beli: ");
    scanf("%d",&temp.jmlbeli);
    fflush(stdin);

    printf("Harga Jual: ");
    scanf("%d",&temp.hargabeli);
    fflush(stdin);
    fwrite(&temp,sizeof(temp),1,fp);
    }
    fclose(fp);
    printf("Data Tersimpan Kedalam File Barang.txt!\n");
}


void isi_Jual(){
    ///Pengisian File Jual.txt
    FILE *fpj;
    fpj=fopen("Jual.txt","w");
    printf("Masukan banyak tipe barang yang ingin dimasukan data penjualannya: ");
    scanf("%d",&N);
    fflush(stdin);

    for (i=0;i<N;i++){
    printf("Tanggal: ");
    fgets(temp2.tanggal,sizeof(temp2.tanggal),stdin);
    strtok(temp2.tanggal,"\n");
    fflush(stdin);

    printf("Kode: ");
    scanf("%d",&temp2.kode);
    fflush(stdin);

    printf("Jumlah: ");
    scanf("%d",&temp2.jumlah);
    fflush(stdin);

    printf("Harga: ");
    scanf("%d",&temp2.harga);
    fflush(stdin);
    //diskon nanti ke % in
    printf("Diskon: ");
    scanf("%f",&temp2.diskon);
    fflush(stdin);
    fwrite(&temp2,sizeof(temp2),1,fpj);
    }
    fclose(fpj);
    printf("Data Tersimpan Kedalam File Jual.txt!\n");
}

void isi(){
    FILE *fp;
    fp=fopen("Barang.txt","w");
    strcpy(brg[1].kode,"666");
    strcpy(brg[1].nama,"First");
    strcpy(brg[1].jenis,"Barang");
    brg[1].jmlbeli=66;
    brg[1].hargabeli=666000;
    fwrite(&brg[1],sizeof(brg[1]),1,fp);

    strcpy(brg[1].kode,"777");
    strcpy(brg[1].nama,"Second");
    strcpy(brg[1].jenis,"Barang2");
    brg[1].jmlbeli=77;
    brg[1].hargabeli=777000;
    fwrite(&brg[1],sizeof(brg[1]),1,fp);

    strcpy(brg[1].kode,"888");
    strcpy(brg[1].nama,"Third");
    strcpy(brg[1].jenis,"Barang3");
    brg[1].jmlbeli=888;
    brg[1].hargabeli=888000;
    fwrite(&brg[1],sizeof(brg[1]),1,fp);
    fclose(fp);
    
    FILE *fpj;
    fpj=fopen("Jual.txt","w");
    strcpy(jual[1].tanggal,"101010");
    jual[1].jumlah=666;
    jual[1].harga=1000;
    jual[1].diskon=60;
    
    strcpy(jual[2].tanggal,"101010");
    jual[2].jumlah=777;
    jual[2].harga=1100;
    jual[2].diskon=70;
    
    strcpy(jual[3].tanggal,"101010");
    jual[3].jumlah=888;
    jual[3].harga=1200;
    jual[3].diskon=80;
    
    fprintf(fpj,"%s %d %d %d\n",jual[1].tanggal,jual[1].jumlah,jual[1].harga,jual[1].diskon);
    fprintf(fpj,"%s %d %d %d\n",jual[2].tanggal,jual[2].jumlah,jual[2].harga,jual[2].diskon);
    fprintf(fpj,"%s %d %d %d\n",jual[3].tanggal,jual[3].jumlah,jual[3].harga,jual[3].diskon);

    fclose(fpj);
}

void buat_Array(int mode){
    i=0;
    char pilihan='n';
    FILE *fp;
    FILE *fpj;
    do{
    printf("Masukan kembali Mode yang diinginkan");
    scanf("%d",&mode);
    fflush(stdin);

    switch (mode)
    {
    case 1:
        //Pembacaan File Barang.txt
        ///rewind
        printf("masuk switch\n");
        fp=fopen("Barang.txt","r");
        while (!feof(fp) && (fread(&brg[i],sizeof(brg[i]),1,fp))!=NULL)
        {
            i++;
        }
        
        //Menampilkan, BELOM KELAR
        for (j=0;j<i;j++)
        {
            printf("%s\t%s\t%s\t%d\t%d\n",brg[j].kode,brg[j].nama,brg[j].jenis,brg[j].jmlbeli,brg[j].hargabeli);
        }

        fclose(fp);
        pilihan = 'n';
        break;

    default:
        //Pembacaan File Jual.txt
        fpj=fopen("Jual.txt","r");
        ///rewind
        while (!feof(fpj) && (fread(&jual[i],sizeof(jual[i]),1,fpj))!=NULL)
        {
            i++;
        }
        //Menampilkan, BELOM KELAR
        for (j=0;j<i;j++)
        {
           printf("%s, %d, %d, %d, %.2f\n",jual[j].tanggal,jual[j].kode,jual[j].jumlah,jual[j].harga,jual[j].diskon);
        }

        fclose(fpj);
        pilihan = 'n';
        break;

    }
    printf("Apakah Anda ingin menampilkan isi File lagi? atau isi File yang Lain?[y/n]\n");
    scanf("%c",&pilihan);
    fflush(stdin);
    printf("[1]File Barang.txt [2]File jual.txt {1/2}\nMasukan Mode untuk menampilkan isi File: ");
    scanf("%d",&mode);
    fflush(stdin);
    }while(pilihan=='y' );//DIBIKIN BOLEAN AJA TAR.
}


void sisaBarang(){
    FILE *fp;
    FILE *fpj;
    fp=fopen("Barang.txt","r");
        while (!feof(fp) && (fread(&brg[i],sizeof(brg[i]),1,fp))!=NULL)
        {
            i++;
        }

    fpj=fopen("Jual.txt","r");
        while (!feof(fpj) && (fread(&jual[i],sizeof(jual[i]),1,fpj))!=NULL)
        {
            i++;
        }
}


int main()
{
    int mod;
    printf("Nama: Dafyno Madadyu, Kelas: TK-45-04, NIM: 1103210112\n");
    printf("\n");
    printf("|0|!-----Program Pengolahan Toko-----!|0|\n");
    isi();


    //isi_Barang();
    //isi_Jual();
    printf("[1]File Barang.txt [2]File jual.txt {1/2}\nMasukan Mode untuk menampilkan isi File: ");
    scanf("%d",&mod);
    fflush(stdin);
    buat_Array(mod);

    return 0;
}