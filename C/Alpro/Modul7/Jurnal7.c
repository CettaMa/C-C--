#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, pass=0, jumlah=0,low=0;
    char nama[30];
    char cari, temp;
    printf("Masukan Nama anda :");
    fgets(nama,30,stdin);
    strtok(nama,"\n");
    printf("Masukan data huruf yang dicari :");
    scanf("%c",&cari);
    printf("Mengurutkan data...\n");

    for ( pass = 0; pass < strlen(nama); pass++)
    {
        for ( i = pass+1; i < strlen(nama); i++)
        {
            if (nama[pass]>nama[i])
            {
                temp=nama[pass];
                nama[pass]=nama[i];
                nama[i]=temp;
            }
        }
    }
    strtok(nama," ");
    int high=strlen(nama)-1;
    printf("Pengurutan selesai.");
    printf("%s %d",nama,high);

    while (low <= high)
    {
        int mid =(high + low)/2;
        printf("\nmid : %d",mid);
        if (nama[mid]==cari){
            i=mid;
            while (nama[i]==nama[i+1]){
                jumlah++;
                i++;
            }   
            i=mid;
            while (nama[i]==nama[i-1]){
                jumlah++;
                i--;
            }
            jumlah++;        }
        if (nama[mid]>=cari){
            high=mid -1;
        }
         if (nama[mid]<=cari){
            low=mid +1;
        }
        pass++;
    }
    if (jumlah>=1){
        printf("\nterdapat %d buah huruf %c pada nama\n",jumlah,cari);
    } else {
        printf("\nHuruf %c tidak ditemukan.\n",cari);
    }
}