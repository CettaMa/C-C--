#include <stdio.h>
#include <stdlib.h>

int main() {
    int pil_konverse,nilai_awal,pil_konverse2;
    float hasil_konversi;
    printf("Konversi Satuan Panjang (dari)\n1.Gross\n2.Lusin\n3.Rim\nMau konversi kemana? ");
    scanf("%d",&pil_konverse);
    switch (pil_konverse)
    {
    case 1:
        printf("Masukan Nilai Konversi : ");
        scanf("%d",&nilai_awal);
        printf("Konversi (Dari-Ke)\n1.Gross-Lusin\n2.Gross-Rim\nMau konversi kemana? ");
        scanf("%d",&pil_konverse2);
        if (pil_konverse2==1) {
            hasil_konversi=nilai_awal*12;
        } else {
            hasil_konversi=nilai_awal*500;
        }
        break;
    case 2:
        printf("Masukan Nilai Konversi : ");
        scanf("%d",&nilai_awal);
        printf("Konversi (Dari-Ke)\n1.Lusin-Gross\n2.Lusin-Rim\nMau konversi kemana? ");
        scanf("%d",&pil_konverse2);
        if (pil_konverse2==1) {
            hasil_konversi=(float)nilai_awal/12;
        } else {
            hasil_konversi=(float)(nilai_awal*12)/500;
        }
        break;
    default:
        printf("Masukan Nilai Konversi : ");
        scanf("%d",&nilai_awal);
        printf("Konversi (Dari-Ke)\n1.Rim-Gross\n2.Rim-Lusin\nMau konversi kemana? ");
        scanf("%d",&pil_konverse2);
        if (pil_konverse2==1) {
            hasil_konversi=(float)(nilai_awal*500)/144;
        } else {
            hasil_konversi=(float)(nilai_awal*500)/12;
        }
        break;
    }
    printf("Hasil dari konversi adalah %.2f",hasil_konversi);
    return 0;
}
