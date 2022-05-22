#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nama[10],nim[15];
    float ipk;
    int i,lanjut,n;

    FILE *fp;
    fp =fopen("cetta.txt","a");

    printf("Modul 8\t===Operasi file===\n");

    printf("Masukan jumlah siswa yang ingin ditambahkan :");
    scanf("%d",&n);

    for ( i = 0; i < n; i++)
    {
        scanf("%*c");
        printf("Nama\t:");
        fgets(nama,10,stdin);
        strtok(nama,"\n");
        printf("NIM\t:");
        fgets(nim,15,stdin);
        strtok(nim,"\n");
        printf("IPK\t:");
        scanf("%f",&ipk);
        fprintf(fp,"%s %s %.2f\n",nama,nim,ipk);
    }
    fclose(fp);
    
}
    
