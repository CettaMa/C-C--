#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Buah{
char kode[4],nama [10], asal[15];
int jumlah, hargabeli, hargajual, terjual, sisa,untung;
}temp;
struct Buah buah[6]=
{"102","Apel","Malang",20,1750,2000,5,0,0,
"103","Jeruk","Pontianak",10,1500,3000,10,0,0,
"101","Durian","Lampung",15,10000,20000,7,0,0,
"104","Nanas","Sumbang",25,3000,5000,8,0,0,
"106","Buah Naga","DIY",30,2500,3500,15,0,0,
"105","Mangga","Jawa Barat",50,2000,4000,25,0,0};

void isibuah(){

FILE *fp;

fp = fopen("data.txt","w");

fwrite(&buah,sizeof(buah),1,fp);
fwrite(&buah,sizeof(buah),1,fp);
fwrite(&buah,sizeof(buah),1,fp);
fwrite(&buah,sizeof(buah),1,fp);
fwrite(&buah,sizeof(buah),1,fp);
fwrite(&buah,sizeof(buah),1,fp);

fclose(fp);
};

void baca(int jdata){
int i;

FILE *fp;
fp = fopen("data.txt","r");
for ( i = 0; i < jdata; i++)
{
fread(&buah[i],sizeof(buah[i]),1,fp);
printf("%s\t%s \t%s \t%d\t%d\t%d\t%d\t%d\t%d\n",buah[i].kode, buah[i].nama, buah[i].asal, buah[i].jumlah, buah[i].hargabeli, buah[i].hargajual, buah[i].terjual, buah[i].untung, buah[i].sisa);
}

printf("\n");
fclose(fp);
}


void SisaUntung(int jdata)
{
FILE *fp;

fp = fopen("data.txt", "r");
fread(&temp,sizeof(temp),1,fp);
int totaluntung;
int i, j;
char currentkode[4], currentnama[10], currentasal[15];
int currentjumlah=0, currenthargabeli=0, currenthargajual=0, currentterjual=0;
int currentsisa=0, currentuntung=0;

printf("\nPerhitungan keuntungan");
if(feof(fp)){
printf("File tidak ada\n");
}
else
i=0; j=0;
while(i<jdata){
currentsisa=0;
currentjumlah=0;
totaluntung=0;

strcpy(currentkode,buah[i].kode);
strcpy(currentnama,buah[i].nama);
strcpy(currentasal,buah[i].asal);
currentjumlah = buah[i].jumlah;
currenthargabeli = buah[i].hargabeli;
currenthargajual = buah[i].hargajual;
currentterjual = buah[i].terjual;
currentsisa = buah[i].sisa;
currentuntung = buah[i].untung;
buah[i].sisa = buah[i].terjual;
while(currentkode==buah[j].kode){
currentjumlah=currentjumlah+buah[j].jumlah;
totaluntung=totaluntung+((currentterjual*(buah[j].hargajual-buah[j].hargabeli)));
j++;
}
currentsisa = currentjumlah - buah[i].terjual;
printf("\n");
printf("%s\t%s \t%s \t%d\t%d\t%d\t%d\t%d\t%d",currentkode, currentnama, currentasal, currentjumlah, currenthargabeli, currenthargajual, currentterjual, currentsisa, totaluntung);


strcpy(buah[i].kode,currentkode);
strcpy(buah[i].nama,currentnama);
strcpy(buah[i].asal,currentasal);
buah[i].jumlah = currentjumlah;
buah[i].hargabeli = currenthargabeli;
buah[i].hargajual = currenthargajual;
buah[i].terjual = currentterjual;
buah[i].sisa = currentsisa;
buah[i].untung = currentuntung;

i++;
}

fclose(fp);

}

void OlahFile(int jdata,int mode)
{
int i;
FILE *fp;

switch(mode)
{
case 1:
// printf("Mengisi array Brg\n");
fp = fopen("data.txt","w");
for ( i = 0; i < 6; i++)
{
fwrite(&buah[i],sizeof(buah[i]),1,fp);
}
fclose(fp);
break;
case 2:
// printf("mengisi array jual");
fp = fopen("data.txt","r");
for (i = 0; i < 10; i++)
{
fread(&buah[i],sizeof(buah[i]),1,fp);
}
fclose(fp);
break;
}
}


void urut(int jdata)//pengurutan bubble
{
int i, k;

FILE *fp;
fp = fopen("data.txt","r");

for ( i = 0; i < jdata; i++)
{
for ( k = 0; k < jdata-1; k++)
{
if(strcmp(buah[k].nama,buah[k+1].nama)>0)
{
temp = buah[k];
buah[k] = buah[k+1];
buah[k+1] = temp;
}
}
}
printf("\n\nSetelah diurutkan\n");
for ( i = 0; i < jdata; i++)
{
fwrite(&buah[i],sizeof(buah[i]),1,fp);
printf("%s\t%s \t%s \t%d\t%d\t%d\t%d\t%d\t%d\n",buah[i].kode, buah[i].nama, buah[i].asal, buah[i].jumlah, buah[i].hargabeli, buah[i].hargajual, buah[i].terjual, buah[i].untung, buah[i].sisa);
}
fclose(fp);
}

int main()
{
int jdata,mode;
jdata=6;
printf("Muhammad Afif Fadhlurrahaman, Kelas TK4504, NIM 1103210161\n");
isibuah();
baca(jdata);
SisaUntung(jdata);
OlahFile(jdata,mode);
urut(jdata);
}