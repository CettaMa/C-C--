#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    //deklarasi variabel
    int n,i,j,jumlah=0,totalharga=0;
    float rata=0;    
    struct sortir
    {
        int harga;
        char namasayur[10];
    };
    
    struct Sayuran
    {
        char nama[10];
        char jenis[10];
        int banyak;
        char kualitas;
        int harga;
        int total;
    };
    
    //input variabel
    printf("Masukan jumlah sayuran yang ingin diinput :");
    scanf("%d",&n);
    scanf("%*c");
    struct Sayuran syr[n];
    struct sortir sayuran[n];
    struct sortir temp;
    for (i = 0; i < n; i++)
    {
        printf("\nData ke-%d\n",i+1);
        printf("Nama \t\t:");
        fgets(syr[i].nama,10,stdin);
        strtok(syr[i].nama,"\n");
        printf("Jenis \t\t:");
        fgets(syr[i].jenis,10,stdin);
        strtok(syr[i].jenis,"\n");
        printf("Banyak \t\t:");
        scanf("%d",&syr[i].banyak);
        printf("Kualitas \t:");
        scanf("%*c");
        scanf("%c",&syr[i].kualitas);
        scanf("%*c");
        //kalkulasi grade dan juga jenis sayur
        if (strcmp(syr[i].jenis,"daun")==0)
        {
            switch (syr[i].kualitas)
            {
            case 'A':
                syr[i].harga =1000;
                syr[i].total=syr[i].harga*syr[i].banyak;
                break;
            
            default:
                syr[i].harga =750;
                syr[i].total=syr[i].harga*syr[i].banyak;
                break;
            }
        } else if (strcmp(syr[i].jenis,"umbi")==0) {
            switch (syr[i].kualitas)
            {
            case 'A':
                syr[i].harga =2000;
                syr[i].total=syr[i].harga*syr[i].banyak;
                break;
            case 'B':
                syr[i].harga =1500;
                syr[i].total=syr[i].harga*syr[i].banyak;
                break;
            default:
                syr[i].harga =500;
                syr[i].total=syr[i].harga*syr[i].banyak;
                break;
            }
        }
        //memasukan data data sayuran untuk dirata ratakan nanti
        jumlah=jumlah+syr[i].banyak;
        totalharga=totalharga+syr[i].total;
        printf("%s %s %d %c %d %d",syr[i].nama,syr[i].jenis,syr[i].banyak,syr[i].kualitas,syr[i].harga,syr[i].total);
        sayuran[i].harga=syr[i].total;
        strcpy(sayuran[i].namasayur,syr[i].nama);
        
    }
    //merata ratakan harga sayuran
    rata=(float)totalharga/jumlah;

    //sorting
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-1; j++)
        {
            if (sayuran[j].harga<sayuran[j+1].harga)
            {
                temp=sayuran[j];
                sayuran[j]=sayuran[j+1];
                sayuran[j+1]=temp;
            }
            
        }
        
    }
    
    printf("\nTotal semua harga sayuran \t:Rp.%d",totalharga);
    printf("\nJumlah semua sayuran \t\t:%d",jumlah);
    printf("\nRata-Rata total bahan makanan \t:Rp.%.2f\n",rata);
    printf("Daftar sayuran\t:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s  \t%d\n",sayuran[i].namasayur,sayuran[i].harga);
    }
    
    return 0;
}