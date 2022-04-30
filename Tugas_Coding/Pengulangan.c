#include <stdio.h>
#include <stdlib.h>


int main()
{ 
 struct sayuran{
 char nama[10],jenis[10],kualitas;
 int banyak,harga,total;
 };
 struct sayuran syr[10];
 int i,N,totalsemua=0,cacahsemua=0;
 float rata=0;
 printf(" Masukkan cacah data yang akan diinputkan: ");
 scanf("%d",&N);fflush(stdin);
 fflush(stdin);
 for(i=1;i<=N;i++){
 printf(" Data ke-%d\n",i);
 printf(" Nama : ");
 fgets(syr[i].nama,10,stdin);
 strtok(syr[i].nama,"\n");fflush(stdin);
 printf(" Jenis : ");
 fgets(syr[i].jenis,10,stdin);
 strtok(syr[i].jenis,"\n");fflush(stdin);
 printf(" Banyak : ");
 scanf("%d",&syr[i].banyak);fflush(stdin);
 printf(" Kualitas : ");
 scanf("%c",&syr[i].kualitas);fflush(stdin);
 if(strcmp(syr[i].jenis,"daun")==0){
 if(syr[i].kualitas=='A'){
 syr[i].harga=1000;
 }
 else{
 syr[i].harga=750;
 }
 }
 else{
 if(syr[i].kualitas=='A'){
 syr[i].harga=2000;
 }
 else if(syr[i].kualitas=='B'){
 syr[i].harga=1500;
 }
 else{
 syr[i].harga=1000;
 }
 }
 syr[i].total=syr[i].harga*syr[i].banyak;
 printf(" %s %s %c %d %d %d\n",syr[i].nama,syr[i].jenis,syr[i].kualitas,syr[i].banyak,syr[i].harga,syr[i].total);
 cacahsemua=cacahsemua+syr[i].banyak;
 totalsemua=totalsemua+syr[i].total;
 rata=(float)totalsemua/cacahsemua;
 }
 printf(" Total semua harga barang %d",totalsemua);
 printf("\n Cacah semua barang %d",cacahsemua);
 printf("\n Rata-Rata harga barang %.2f",rata);
 return 0;
}