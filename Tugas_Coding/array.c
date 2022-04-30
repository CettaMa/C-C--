#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int i,c;

struct data
{
    char nama[20];
    char indeks[10];
    int nilai;
}siswa[2];

   for (i = 0; i <2 ; i++)
   {
       printf("Masukan nama anda :");
       fgets(siswa[i].nama,20,stdin);
       strtok(siswa[i].nama,"\n");
       printf("Masukan Nilai :");
       scanf("%d",&siswa[i].nilai);
       if (siswa[i].nilai<=40)
       {
           strcpy(siswa[i].indeks,"E (Tidak Lulus)");
       }
       else if (40<=siswa[i].nilai && siswa[i].nilai<50)
       {
           strcpy(siswa[i].indeks,"D (Masih Kurang)");
       }
       else if (50<=siswa[i].nilai && siswa[i].nilai<65)
       {
           strcpy(siswa[i].indeks,"C (cukup)");
       }
       else if (65<=siswa[i].nilai && siswa[i].nilai<80)
       {
           strcpy(siswa[i].indeks,"B (Bagus)");
       }
       else
       {
           strcpy(siswa[i].indeks,"A (Hebat)");
       } 
    while ( (c = getchar()) != '\n' && c != EOF );
   }
    for ( i = 0; i <2; i++)
    {
        printf("Nama : %s\nDengan indeks : %s\n",siswa[i].nama,siswa[i].indeks);
    }
    
    
}