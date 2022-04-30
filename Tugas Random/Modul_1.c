#include <stdio.h>
#include <stdlib.h>

int main() {

int sisi,persegi,alas,tinggi;
float jari2,segitiga,lingkaran;
//input data
printf("=== Jurnal Nomor 2 ===\n");
printf("Masukkan Sisi : ");
scanf("%d",&sisi);
printf("Masukkan alas : ");
scanf("%d",&alas);
printf("Masukkan Tinggi : ");
scanf("%d",&tinggi);
printf("Masukkan Jari - Jari : ");
scanf("%f",&jari2);

persegi = sisi*sisi;
segitiga = alas*tinggi/2;
lingkaran = 3.14*jari2*jari2;
printf ("Sebuah persegi dengan sisi %d cm memiliki luas sebesar %d cm\n",sisi,persegi);
printf ("Sebuah segitiga dengan alas %d cm dan tinggi %d cm memiliki luas sebesar %.2fcm\n",alas,tinggi,segitiga);
printf ("Sebuah lingkaran dengan jari - jari %.0f cm memiliki luas sebesar %.2f cm\n",jari2,lingkaran);
return 0;
}