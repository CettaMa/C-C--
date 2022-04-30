#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int i,j,k,n;
int jumlah;
struct data
{
    char nama[20];
    int nim;
    int nilakhir;
    int mklulus;
    char status[15];
}mahasiswa,arraymhs[20],temp;



struct data1
{
    int nim;
    char NamaMK[10];
    int uts;
    int uas;
}nilai,arraynilmk[20];


void Isidata(){
    FILE *fp;
    FILE *fj;
fp = fopen("student.txt", "w");
fj = fopen("Nilai.txt", "w");
strcpy(mahasiswa.nama,"Asep Surasep");
mahasiswa.nim=111;
fwrite(&mahasiswa, sizeof(mahasiswa), 1, fp);
strcpy(mahasiswa.nama,"Cici Cianjuran");
mahasiswa.nim=112;
fwrite(&mahasiswa, sizeof(mahasiswa), 1, fp);
strcpy(mahasiswa.nama,"bandun Bondowoso");
mahasiswa.nim=113;
fwrite(&mahasiswa, sizeof(mahasiswa), 1, fp);


nilai.nim=111;
strcpy(nilai.NamaMK,"Fisika");
nilai.uts=80;
nilai.uas=70;
fwrite(&nilai, sizeof(nilai), 1, fj);

nilai.nim=112;
strcpy(nilai.NamaMK,"Fisika");
nilai.uts=70;
nilai.uas=60;
fwrite(&nilai, sizeof(nilai), 1, fj);

nilai.nim=113;
strcpy(nilai.NamaMK,"Fisika");
nilai.uts=40;
nilai.uas=35;
fwrite(&nilai, sizeof(nilai), 1, fj);

nilai.nim=111;
strcpy(nilai.NamaMK,"Kalkulus");
nilai.uts=70;
nilai.uas=90;
fwrite(&nilai, sizeof(nilai), 1, fj);

nilai.nim=111;
strcpy(nilai.NamaMK,"Agama");
nilai.uts=90;
nilai.uas=80;
fwrite(&nilai, sizeof(nilai), 1, fj);

nilai.nim=111;
strcpy(nilai.NamaMK,"Agama");
nilai.uts=50;
nilai.uas=40;
fwrite(&nilai, sizeof(nilai), 1, fj);

fclose(fj);
fclose(fp);
printf("Isidata ok\n");
}

void isimhs (int n){
    FILE *fp;
    fp =fopen("student.txt","w");
    printf("Data Mahasiswa :\n");

    for ( i = 0; i < n; i++)
    {   
        scanf("%*c");
        printf("Masukan nama\t:");
        fgets(mahasiswa.nama,20,stdin);
        strtok(mahasiswa.nama,"\n");
        printf("Masukan NIM\t:");
        scanf("%d",&mahasiswa.nim);
        fwrite(&mahasiswa,sizeof(mahasiswa),1,fp);
        printf("%s %d\n",mahasiswa.nama,mahasiswa.nim);
    }   
    fclose(fp);
}

void isinilai (int jumlah) {
    FILE *fj;
    fj =fopen("Nilai.txt","w");
    
    for (i = 0; i < jumlah; i++)
    {   
        printf("Masukan NIM\t:");
        scanf("%d",&nilai.nim);
        scanf("%*c");
        printf("Masukan Mata Kuliah\t:");
        fgets(nilai.NamaMK,10,stdin);
        strtok(nilai.NamaMK,"\n");
        printf("UTS\t:");
        scanf("%d",&nilai.uts);
        printf("UAS\t:");
        scanf("%d",&nilai.uas);
        fwrite(&nilai,sizeof(nilai),1,fj);
    }
    fclose(fj);
    
}

void file2array (int mode,int n,int jumlah) {
    FILE *fp;
    FILE *fj;
    if (mode==0)
    {
        printf("\nMemasukan data array mahasiswa :\n");
        fp = fopen ("student.txt","r");
        for ( i = 0; i < n; i++)
        {
            fread(&arraymhs[i],sizeof(arraymhs[i]),1,fp);
            printf("%d\t%s\n",arraymhs[i].nim,arraymhs[i].nama);            
        }
        fclose(fp);
    } else {
        printf("\nMemasukan data array nilai :\n");
        fj = fopen ("Nilai.txt","r");
        
        for ( i = 0; i < jumlah; i++)
        {
            fread(&arraynilmk[i],sizeof(arraynilmk[i]),1,fj);
            printf("%d\t%s\t%d\t%d\n",arraynilmk[i].nim,arraynilmk[i].NamaMK,arraynilmk[i].uts,arraynilmk[i].uas);
        }
        fclose(fj);
    }
}

void urut (int n){
    FILE *fp;
    fp=fopen("student.txt","r+");
    printf("\nMengurutkan...\n");
    for ( i = 1; i < n-1; i++)
    {
        j=0;
        for (k = 1; k < n-i; k++)
        {
            if (arraymhs[j].nama[0]<arraymhs[k].nama[0])
            {
                j=k;
                temp=arraymhs[j];
                arraymhs[j]=arraymhs[n-i];
                arraymhs[n-i]=temp;
            }
        }
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d\t%s\n",arraymhs[i].nim,arraymhs[i].nama);
    }
    fclose(fp);
}

void isimaha(int n,int jumlah) {
    FILE *fp;
    FILE *fj;
    fp=fopen("student.txt","r+");
    fj=fopen("Nilai.txt","r+");
    for ( i = 0; i < n; i++)
    {
        int jumlahmk=0;
        int ratamk;
        int mklulus=0;
        int totalnilai=0;
        for ( j = 0; j < jumlah; j++)
        {
            if (arraymhs[i].nim==arraynilmk[j].nim)
            {
                jumlahmk++;
                if (((arraynilmk[j].uas+arraynilmk[j].uts)*0.5)>60){
                    mklulus++;
                }
                totalnilai=totalnilai+((arraynilmk[j].uas+arraynilmk[j].uts)/2);
            }
        }
        ratamk=totalnilai/jumlahmk;
        arraymhs[i].nilakhir=ratamk;
        arraymhs[i].mklulus=mklulus;
        printf("\n%d\t%s\t%d\t%d",arraymhs[i].nim,arraymhs[i].nama,arraymhs[i].nilakhir,arraymhs[i].mklulus);
        fwrite(&arraymhs[i],sizeof(arraymhs[i]),1,fp);
    }
    fclose(fp);
}

void status(int n) {
    FILE *fp;
    fp=fopen("student.txt","r+");
    printf("\nMengisi status pada student.txt\n");
    for ( i = 0; i < n; i++)
    {
        fread(&arraymhs[i],sizeof(arraymhs[i]),1,fp);
        if (arraymhs[i].nilakhir>60 && arraymhs[i].mklulus==3)
        {
            strcpy(arraymhs[i].status,"Lulus");
            
        } else {
            strcpy(arraymhs[i].status,"Tidak Lulus");
        }
        printf("%d\t%s  \t%d\t%d\t dan %s\n",arraymhs[i].nim,arraymhs[i].nama,arraymhs[i].nilakhir,arraymhs[i].mklulus,arraymhs[i].status);
    }
    
    fclose(fp);
}

int main() {
    int x,z;
    printf("Masukan jumlah Mahasiswa\t:");
    scanf("%d",&x);
    isimhs(x);
    printf("Masukan jumlah Mata Kuliah\t:");
    scanf("%d",&z);
    isinilai(z);
    for ( j = 0; j < x-1; j++)
    {
        file2array(j,x,z);
    }
    urut(x);
    isimaha(x,z);
    status(x);
}