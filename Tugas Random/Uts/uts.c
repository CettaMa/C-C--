#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int cacahmat=0;
int totalmat=0;
int pass=1;
int n,i,j;
int totaljeniscat=0;
int totaljenisbatu=0;
    struct material
    {
        char nama[15];
        char jenis[10];
        int banyak;
        int kualitas;
        int harga;
        int totalmasing;
    }cetta[11],temp;
    

int main(){
    printf("Nama\t: Cetta Maulana A\tNIM\t:1103213119\tTK-45-04\n");
    printf("Masukan Jumlah data\t:");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%*c");
        printf("Nama\t:");
        fgets(cetta[i].nama,15,stdin);
        strtok(cetta[i].nama,"\n");
        printf("Jenis\t:");
        fgets(cetta[i].jenis,10,stdin);
        strtok(cetta[i].jenis,"\n");
        printf("Banyak\t:");
        scanf("%d",&cetta[i].banyak);
        printf("Kualitas\t:");
        scanf("%d",&cetta[i].kualitas);
        if (strcmp(cetta[i].jenis,"batu")==0)
        {
            switch (cetta[i].kualitas)
            {
            case 1:
                cetta[i].harga=2000;
                cetta[i].totalmasing=cetta[i].banyak*cetta[i].harga;
                break;
            case 2:
                cetta[i].harga=2500;
                cetta[i].totalmasing=cetta[i].banyak*cetta[i].harga;
                break;
            default:
                cetta[i].harga=3000;
                cetta[i].totalmasing=cetta[i].banyak*cetta[i].harga;
                break;
            }
            totaljenisbatu=totaljenisbatu+cetta[i].totalmasing;
        } else {
            if (cetta[i].kualitas==1)
            {
                cetta[i].harga=10000;
                cetta[i].totalmasing=cetta[i].banyak*cetta[i].harga;
            } else {
                cetta[i].harga=15000;
                cetta[i].totalmasing=cetta[i].banyak*cetta[i].harga;
            }
            
            totaljeniscat=totaljeniscat+cetta[i].totalmasing;
        }
        totalmat=totalmat+cetta[i].totalmasing;
        cacahmat=cacahmat+cetta[i].banyak;
    }
    for ( i = 0; i < n; i++)
    {
        printf("Nama :%s\tJenis :%s\tBanyak :%d\tKualitas :%d\tHarga :Rp.%d\tTotal Masing :Rp.%d\n",cetta[i].nama,cetta[i].jenis,cetta[i].banyak,cetta[i].kualitas,cetta[i].harga,cetta[i].totalmasing);
    }
    printf("Total Semua Barang :%d\tCacah :%d\tDengan rata-rata :%f\n",totalmat,cacahmat,(float)totalmat/cacahmat);
    printf("\nSetelah Diurutkan :\n");

    i=0;
    while (i<=n-1 && pass==1)
    {
        pass=0;
        for (j = 1; j < n-i ; j++)
        {
            if (cetta[j-1].kualitas>cetta[j].kualitas)
            {
                temp=cetta[j];
                cetta[j]=cetta[j-1];
                cetta[j-1]=temp;
                pass=1;
            }
        i++;
        }
        
    }
    for ( i = 0; i < n; i++)
    {
        printf("Nama :%s\tJenis :%s\tBanyak :%d\tKualitas :%d\tHarga :Rp.%d\tTotal Masing :Rp.%d\n",cetta[i].nama,cetta[i].jenis,cetta[i].banyak,cetta[i].kualitas,cetta[i].harga,cetta[i].totalmasing);
    }
    printf("Total Jenis Cat : Rp.%d\tTotal jenis batu : Rp.%d\n",totaljeniscat,totaljenisbatu);
}