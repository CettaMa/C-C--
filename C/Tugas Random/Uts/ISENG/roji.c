#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rozi{
char nama[10], jenis[10] ;

int  kode,jmlbeli,hargabeli,sisa ,untung;
}bar[20], arrbar[20],temp;

struct jual{
char tanggal;
int  kode, jumlah, harga ;
float diskon;
}ju[20],arrju[20];


void isibarang(){
FILE *fp;
fp=fopen("barang.txt","w");
bar[0].kode=101;
strcpy(bar[0].nama,"Lux");
strcpy(bar[0].jenis,"Sabun");
bar[0].jmlbeli=10;
bar[0].hargabeli=1000;
fwrite(&bar[0],sizeof(bar[0]),1,fp);

bar[1].kode=102;
strcpy(bar[1].nama,"Rinso");
strcpy(bar[1].jenis,"Sabun");
bar[1].jmlbeli=20;
bar[1].hargabeli=1500;
fwrite(&bar[1],sizeof(bar[1]),1,fp);

bar[2].kode=103;
strcpy(bar[2].nama,"Kacang");
strcpy(bar[2].jenis,"Makanan");
bar[2].jmlbeli=25;
bar[2].hargabeli=500;
fwrite(&bar[2],sizeof(bar[2]),1,fp);




bar[3].kode=104;
strcpy(bar[3].nama,"MamaLime");
strcpy(bar[3].jenis,"Sabun");
bar[3].jmlbeli=20;
bar[3].hargabeli=1250;
fwrite(&bar[3],sizeof(bar[3]),1,fp);



bar[4].kode=105;
strcpy(bar[4].nama,"Fanta");
strcpy(bar[4].jenis,"Makanan");
bar[4].jmlbeli=15;
bar[4].hargabeli=2000;
fwrite(&bar[4],sizeof(bar[4]),1,fp);



bar[5].kode=106;
strcpy(bar[5].nama,"Ember");
strcpy(bar[5].jenis,"Plastik");
bar[5].jmlbeli=10;
bar[5].hargabeli=10000;
fwrite(&bar[5],sizeof(bar[5]),1,fp);

}

void bacadata(){
FILE*fp;
fp=fopen("barang.txt","r");
int i;
for(i=0;i<6;i++){
fread(&arrbar[i],sizeof(arrbar)[i],1,fp);
}
for(i=0;i<6;i++){
    printf("%d\t %s\t %s\t %d\t  %d\t %d\t %d\t \n", arrbar[i].kode, arrbar[i].nama, arrbar[i].jenis, arrbar[i].jmlbeli, arrbar[i].hargabeli, arrbar[i].sisa , arrbar[i].untung );
}
fclose(fp);
}



void isijual(){
FILE *fj;
fj=fopen("Jual.txt","w");




strcpy(ju[0].tanggal,"01-01-18");
ju[0].kode = 101;
ju[0].jumlah = 1;
ju[0].harga = 1200;
ju[0].diskon = 10;
fwrite(&ju[0],sizeof(ju[0]),1,fj);

strcpy(ju[1].tanggal,"01-01-18");
ju[1].kode = 103;
ju[1].jumlah = 2;
ju[1].harga = 750;
ju[1].diskon = 5;
fwrite(&ju[1],sizeof(ju[1]),1,fj);

strcpy(ju[2].tanggal,"01-01-18");
ju[2].kode = 104;
ju[2].jumlah = 1;
ju[2].harga = 1500;
ju[2].diskon = 0;
fwrite(&ju[2],sizeof(ju[2]),1,fj);

strcpy(ju[3].tanggal,"01-01-18");
ju[3].kode = 105;
ju[3].jumlah = 2;
ju[3].harga = 2500;
ju[3].diskon = 0;
fwrite(&ju[3],sizeof(ju[3]),1,fj);

strcpy(ju[4].tanggal,"01-01-18");
ju[4].kode = 101;
ju[4].jumlah = 1;
ju[4].harga = 1200;
ju[4].diskon = 0;
fwrite(&ju[4],sizeof(ju[4]),1,fj);

strcpy(ju[5].tanggal,"02-01-18");
ju[5].kode = 102;
ju[5].jumlah = 2;
ju[5].harga = 2000;
ju[5].diskon = 0;
fwrite(&ju[5],sizeof(ju[5]),1,fj);

strcpy(ju[6].tanggal,"02-01-18");
ju[6].kode = 105;
ju[6].jumlah = 2;
ju[6].harga = 2250;
ju[6].diskon = 0;
fwrite(&ju[6],sizeof(ju[6]),1,fj);

strcpy(ju[7].tanggal,"02-01-18");
ju[7].kode = 106;
ju[7].jumlah = 2;
ju[7].harga = 15000;
ju[7].diskon = 25;
fwrite(&ju[7],sizeof(ju[7]),1,fj);

strcpy(ju[8].tanggal,"03-01-18");
ju[8].kode = 101;
ju[8].jumlah = 1;
ju[8].harga = 1500;
ju[8].diskon = 10;
fwrite(&ju[8],sizeof(ju[8]),1,fj);

strcpy(ju[9].tanggal,"03-01-18");
ju[9].kode = 106;
ju[9].jumlah = 2;
ju[9].harga = 15000;
ju[9].diskon = 10;
fwrite(&ju[9],sizeof(ju[9]),1,fj);


fclose(fj);
}


void bacajual(){
FILE *fj;
fj=fopen("Jual.txt","r");
int i;

fread(&arrju,sizeof(arrju),1,fj);
for(i=0;i<20;i++){
    printf("%s\t %d\t %d\t %d\t %f\n", arrju[i].tanggal,  arrju[i].kode, arrju[i].jumlah , arrju[i].harga ,arrju[i].diskon);
}
fclose(fj);
}





void urut(int n){
FILE *fp;
fp=fopen("barang.txt","r+");
for(int i=0;i<n;i++){
    fread(&arrbar[i],sizeof(arrbar[i]),1,fp);
}

int i,k,pass;
for (pass=1;pass<=n-1;pass++){
 for (k=1;k<=n-pass;k++){
 if (arrbar[k-1].hargabeli > arrbar[k].hargabeli){
 temp = arrbar[k];
 arrbar[k]=arrbar[k-1];
 arrbar[k-1]=temp;
 }
 }
}

fclose(fp);
}


int main(){
printf("Nama : \tFahrul Rozi \t NIM : 1103210235 \t Kelas : TK4504");
printf("\n");
isibarang();
bacadata();
isijual();
printf("\n");
bacajual();

printf("Sebelum urut\n");
urut(3);
printf("Setelah urut\n");
bacadata();
return 0;
}