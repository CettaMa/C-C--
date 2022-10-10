#include <stdio.h>
#include <stdlib.h>

int main () {
int nim;
float tugas1, tugas2, uts, uas,rata;

printf("Masukan NIM = ");
scanf("%d",&nim);
printf("Masukan nilai Tugas 1 = ");
scanf("%f",&tugas1);
printf("Masukan nilai Tugas 2 = ");
scanf("%f",&tugas2);
printf("Masukan nilai UTS = ");
scanf("%f",&uts);
printf("Masukan nilai UAS = ");
scanf("%f",&uas);

rata=(tugas1 + tugas2 + uts + uas)/4;

printf ("=== Data Diri ===\nNIM: %d\n",nim);
printf("Nilai : %.2f, %.2f, %.2f, %.2f\n",tugas1,tugas2,uts,uas);
printf("Rata - Rata : %.2f\n",rata);

    return 0;
}