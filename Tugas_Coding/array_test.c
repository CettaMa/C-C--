#include <stdio.h>
#include <stdlib.h>

int main() {
int uang=15000,transaksi = 0,c;
char kondisi ='y';

printf("Program Pembelian Batagor dan Siomay");
printf("\nPilihan : ");
printf("\n1.Membeli Batagor Seharga 5000");
printf("\n2.Membeli siomay Seharga 7000");
printf("\nAnda memiliki uang sebanyak %d ",uang);

while (kondisi=='y')
{
  //mengganti batas menjadi 7000
  if (uang>7000) {
    printf("\nMasukan pilihan anda :");
  //menambahkan scanf untuk mengambil input pengguna
  scanf("%d",&transaksi);
  while ( (c = getchar()) != '\n' && c != EOF );
  if (transaksi==1)
  {
    uang=uang-5000;
    printf("\nPembelian Batagor berhasil,sisa uang anda %d ",uang);
    printf("\nIngin melanjutkan pembelian ? (y/n) ");
    //menambah scanf untuk mengambil input pengguna apa ingin melanjutkan transaksi atau tidak
    scanf("%c",&kondisi);
  }
  //mengganti "elif" menjadi if
  if (transaksi==2)
  {
    uang = uang-7000;
    printf("\nPembelian Siomay berhasil,sisa uang anda %d ",uang);
    printf("\nIngin melanjutkan pembelian ? (y/n)");
    //menambah scanf untuk mengambil input pengguna apa ingin melanjutkan transaksi atau tidak
    scanf("%c",&kondisi);
  }
  } else {
    printf("\nUang anda kurang,silahkan minta uang ke mamah terlebih dahulu");
    kondisi = 'n';
  }
}
//mengganti "transaksi" menjadi uang
printf("\n\nTerima Kasih telah melakukan pembelian,sisa uang anda %d",uang);
return 0;
}
