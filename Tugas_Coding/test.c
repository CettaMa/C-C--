#include <stdio.h>
#include <stdlib.h>

int main () {
    int hasil,c;
    char *p;
struct data
{
    char nama[20];
    int nilai;
}siswa1;

struct data2
{
    char nama[20];
    int nilai;
}siswa3;

printf("Masukan nama anda :");
fgets(siswa1.nama,20,stdin);
strtok(siswa1.nama,"\n");
printf("Masukan nilai anda :");
scanf("%d",&siswa1.nilai);

while ( (c = getchar()) != '\n' && c != EOF ); //untuk clear buffer, masih belum mengerti cara kerjanya

printf("Masukan nama anda :");
fgets(siswa3.nama,20,stdin);
strtok(siswa3.nama,"\n");
printf("Masukan nilai anda :");
scanf("%d",&siswa3.nilai);

hasil=siswa1.nilai + siswa3.nilai;
printf("Jumlah dari nilai %s dan %s adalah = %d",siswa1.nama,siswa3.nama,hasil);
}