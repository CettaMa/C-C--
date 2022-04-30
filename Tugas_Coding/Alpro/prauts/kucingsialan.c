#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data1
{
    char nama[15];
    char jenis[10];
    int mutu;
    int nilakhir;
    int harga;
    float diskon;
}kucing[3],temp;

struct data2
{
    char nama[10];
    char aspek;
    int kualitas;
    int nilai;
    int nilaspek;
}nilai[3];

void file() {
    FILE *fp;
    fp =fopen("Kucing.txt","w");
    int i=0,n,pass=1,j;

    printf("Jumlah kucing :");
    scanf("%d",&n);

    for (i = 0; i < n; i++)
    {
        scanf("%*c");
        printf("Masukan Nama kucing :");
        fgets(kucing[i].nama,15,stdin);
        strtok(kucing[i].nama,"\n");
        printf("Masukan Jenis Kucing :");
        fgets(kucing[i].jenis,10,stdin);
        strtok(kucing[i].jenis,"\n");
        printf("Masukan Mutu :");
        scanf("%d",&kucing[i].mutu);
        printf("Diskon :");
        scanf("%f",&kucing[i].diskon);
        kucing[i].diskon=(100-kucing[i].diskon)/100;
        fwrite(&kucing[i],sizeof(kucing[i]),1,fp);
    }
    fclose(fp);

    fp=fopen("kucing.txt","w");

    for (i = 0; i < n; i++)
    {
        if (strcmp(kucing[i].jenis,"kampung")==0)
        {
        switch (kucing[i].mutu)
        {
        case 1:
            kucing[i].nilakhir=100;
            kucing[i].harga=kucing[i].nilakhir*500;
            kucing[i].harga=(float)kucing[i].harga*kucing[i].diskon;
            break;
        
        default:
            kucing[i].nilakhir=80;
            kucing[i].harga=kucing[i].nilakhir*500;
            kucing[i].harga=(float)kucing[i].harga*kucing[i].diskon;
            break;
        }
        } else {
        switch (kucing[i].mutu)
        {
        case 1:
            kucing[i].nilakhir=300;
            kucing[i].harga=kucing[i].nilakhir*1000;
            kucing[i].harga=(float)kucing[i].harga*kucing[i].diskon;
            break;
        case 2:
            kucing[i].nilakhir=225;
            kucing[i].harga=kucing[i].nilakhir*1000;
            kucing[i].harga=(float)kucing[i].harga*kucing[i].diskon;
        default:
            kucing[i].nilakhir=62;
            kucing[i].harga=kucing[i].nilakhir*1000;
            kucing[i].harga=(float)kucing[i].harga*kucing[i].diskon;
            break;
        }
        }
    }
    //sorting menggunakan nama
    printf("\nDiurutkan menurut nama\t:\n");
    i=0;
    while (i<=2 && pass==1)
    {
        pass=0;
        for (j = 1; j < 3-i ; j++)
        {
            if (kucing[j].nama[0]>kucing[j+1].nama[0])
            {
                temp=kucing[j+1];
                kucing[j+1]=kucing[j];
                kucing[j]=temp;
                pass=1;
            }
        i++;
        }
        
    }
           
    
    for (i = 0; i < n; i++)
    {
        printf("\nNama\t\t:%s\njenis\t\t:%s\nMutu\t\t:%d\nNilai Akhir\t:%d\nDiskon\t\t:%.2f\nHarga\t\t:%d\n",kucing[i].nama,kucing[i].jenis,kucing[i].mutu,kucing[i].nilakhir,kucing[i].diskon,kucing[i].harga);
    }
    i=0;
    //sorting menggunakan harga
    printf("\nDiurutkan menurut harga\t:\n");
    while (i<=2 && pass==1)
    {
        pass=0;
        for ( j = 0; j < 3-1; j++)
        {
            if (kucing[j].harga>kucing[j+1].harga)
            {
                temp=kucing[j+1];
                kucing[j+1]=kucing[j];
                kucing[j]=temp;
                pass=1;
            }
           i++; 
        }
        
    }
    for (i = 0; i < n; i++)
    {
        printf("\nNama\t\t:%s\njenis\t\t:%s\nMutu\t\t:%d\nNilai Akhir\t:%d\nDiskon\t\t:%.2f\nHarga\t\t:%d\n",kucing[i].nama,kucing[i].jenis,kucing[i].mutu,kucing[i].nilakhir,kucing[i].diskon,kucing[i].harga);
    } 
}

int main() {
    file();
    return 0;
}
