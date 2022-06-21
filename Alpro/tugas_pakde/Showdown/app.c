#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i,j,k;
struct mahasiswa
{
    char nama[25];
    char nim[10];
    float ipk;
    int SKSlulus;
}mhs[10],temp,cetta;

struct komponen
{
    char nim[10];
    char namamk[10];
    int sks,uts,uas;
    char indeks;
}komp,tempkomp,arrkomp[20];


void isimhs(int n,int m){
    printf("Mengisi data\n");
    FILE *fp;
    FILE *fj;
    fj=fopen("Nilai.txt","w");
    fp=fopen("Mahasiswa.txt","w");
    //megisi data mahasiswa
    
    strcpy(cetta.nama,"Cici Cianjuran");
    strcpy(cetta.nim,"110402");
    fwrite(&cetta,sizeof(cetta),1,fp);

    strcpy(cetta.nama,"Bandung Bondowoso");
    strcpy(cetta.nim,"110403");
    fwrite(&cetta,sizeof(cetta),1,fp);

    strcpy(cetta.nama,"Edi Dermayu");
    strcpy(cetta.nim,"110404");
    fwrite(&cetta,sizeof(cetta),1,fp);

    strcpy(cetta.nama,"Budi Banjaran");
    strcpy(cetta.nim,"110401");
    fwrite(&cetta,sizeof(cetta),1,fp);

    strcpy(cetta.nama,"Dudi Durudi");
    strcpy(cetta.nim,"110405");
    fwrite(&cetta,sizeof(cetta),1,fp);


    //megisi data komponen
    strcpy(komp.nim,"110401");
    strcpy(komp.namamk,"Fisika");
    komp.sks=3;
    komp.uts=80;
    komp.uas=85;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110402");
    strcpy(komp.namamk,"Fisika");
    komp.sks=3;
    komp.uts=70;
    komp.uas=60;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110403");
    strcpy(komp.namamk,"Fisika");
    komp.sks=3;
    komp.uts=40;
    komp.uas=35;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110403");
    strcpy(komp.namamk,"Kalkulus");
    komp.sks=4;
    komp.uts=30;
    komp.uas=30;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110404");
    strcpy(komp.namamk,"Kalkulus");
    komp.sks=4;
    komp.uts=60;
    komp.uas=65;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110405");
    strcpy(komp.namamk,"Kalkulus");
    komp.sks=4;
    komp.uts=90;
    komp.uas=70;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110401");
    strcpy(komp.namamk,"Agama");
    komp.sks=2;
    komp.uts=90;
    komp.uas=80;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110402");
    strcpy(komp.namamk,"Agama");
    komp.sks=2;
    komp.uts=75;
    komp.uas=60;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110401");
    strcpy(komp.namamk,"Binggris");
    komp.sks=3;
    komp.uts=80;
    komp.uas=85;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110402");
    strcpy(komp.namamk,"Binggris");
    komp.sks=3;
    komp.uts=70;
    komp.uas=70;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110403");
    strcpy(komp.namamk,"Binggris");
    komp.sks=3;
    komp.uts=90;
    komp.uas=80;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110404");
    strcpy(komp.namamk,"Binggris");
    komp.sks=3;
    komp.uts=30;
    komp.uas=40;
    fwrite(&komp,sizeof(komp),1,fj);
    
    strcpy(komp.nim,"110405");
    strcpy(komp.namamk,"Binggris");
    komp.sks=3;
    komp.uts=60;
    komp.uas=50;
    fwrite(&komp,sizeof(komp),1,fj);

    printf("Mengisi Data selesai!\n\n");
    
    fclose(fp);
    fclose(fj);
}

void isimhsmanual(int n,int m){
    FILE *fp;
    FILE *fj;

    fp=fopen("Mahasiswa.txt","w");
    fj=fopen("Nilai.txt","w");
    for ( i = 0; i < n; i++)
    {
        printf("Nama\t:");
        fgets(cetta.nama,25,stdin);
        strtok(cetta.nama,"\n");
        printf("NIM\t:");
        fgets(cetta.nim,10,stdin);
        strtok(cetta.nim,"\n");
        fwrite(&cetta,sizeof(cetta),1,fp);
    }
    for ( i = 0; i < m; i++)
    {
        printf("NIM\t:");
        fgets(komp.nim,10,stdin);
        strtok(komp.nim,"\n");
        printf("Nama MK\t:");
        fgets(komp.namamk,10,stdin);
        strtok(komp.namamk,"\n");
        printf("SKS\t:");
        scanf("%d",&komp.sks);
        printf("UTS\t:");
        scanf("%d",&komp.uts);
        printf("UAS\t:");
        scanf("%d",&komp.uas);
        scanf("%*c");
        fwrite(&komp,sizeof(komp),1,fj);
    }
    fclose(fj);
    fclose(fj);
}

void buatarray(int mode,int n,int m){
    FILE *fp;
    FILE *fj;

    switch (mode)
    {
    case 0:
        fp=fopen("Mahasiswa.txt","r");
        printf("Mengisi Array Mahasiswa...\n");
        for ( i = 0; i < n; i++)
        {
            fread(&mhs[i],sizeof(mhs[i]),1,fp);
        }
        fclose(fp);
        printf("Selesai!\n");
        break;
    
    default:
        fj=fopen("Nilai.txt","r");
        printf("Mengisi Array Nilai...\n");
        for ( i = 0; i < m; i++)
        {
            fread(&arrkomp[i],sizeof(arrkomp[i]),1,fj);
        }
        printf("Selesai!\n\n");
        fclose(fj);
        break;
    }
}

void simpfile(int mode,int n,int m){
    FILE *fp;
    FILE *fj;

    switch (mode)
    {
    case 1:
        fp=fopen("Mahasiswa.txt","w");
        for ( i = 0; i < n; i++)
        {
            fwrite(&mhs[i],sizeof(mhs[i]),1,fp);
        }
        fclose(fp);
        break;
    
    default:
        fj=fopen("Nilai.txt","w");
        for ( i = 0; i < m; i++)
        {
            fwrite(&arrkomp[i],sizeof(arrkomp[i]),1,fj);
        }
        fclose(fj);
        break;
    }
}

void tampil(int pil,int n,int m){
    FILE *fp;
    FILE *fj;
    switch (pil)
    {
    case 1:
        fp=fopen("Mahasiswa.txt","r");
        printf("\n\nMenampilkan data mahasiswa (Tanpa Array)\n");
        for ( i = 0; i < n; i++)
        {
            fread(&temp,sizeof(temp),1,fp);
            printf("%s      \t%s\t%.2f\t%d\n",temp.nama,temp.nim,temp.ipk,temp.SKSlulus);
        }
        fclose(fp);
        break;
    
    case 2:
        fj=fopen("Nilai.txt","r");
        printf("\n\nMenampilkan data nilai (Tanpa Array)\n");
        for ( i = 0; i < m; i++)
        {
            fread(&tempkomp,sizeof(tempkomp),1,fj);
            printf("%s\t%s   \t%d\t%d\t%d\t%c\n",tempkomp.nim,tempkomp.namamk,tempkomp.sks,tempkomp.uts,tempkomp.uas,tempkomp.indeks);
        }
        fclose(fj);
        break;

    case 3:
        fp=fopen("Mahasiswa.txt","r");
        printf("\n\nMenampilkan data mahasiswa\n");
        for ( i = 0; i < n; i++)
        {
            printf("%s      \t%s\t%.2f\t%d\n",mhs[i].nama,mhs[i].nim,mhs[i].ipk,mhs[i].SKSlulus);
        }
        fclose(fp);
        break;

    case 4:
        fj=fopen("Nilai.txt","r");
        printf("\n\nMenampilkan data nilai\n");
        for ( i = 0; i < m; i++)
        {
            printf("%s\t%s   \t%d\t%d\t%d\t%c\n",arrkomp[i].nim,arrkomp[i].namamk,arrkomp[i].sks,arrkomp[i].uts,arrkomp[i].uas,arrkomp[i].indeks);
        }
        fclose(fj);
        break;
    default:
        printf("\nCetta Maulana Andhika\t1103213119\tTK-45-04\n");
        break;
    }
}

void urut(int mode,int n,int m){
    int x,y,z,pass=1,tukar=1,imax,max;
    max=mhs[0].SKSlulus;
    for ( i = 0; i < n; i++)
    {
        if (mhs[i].SKSlulus>max)
        {
            max=mhs[i].SKSlulus;
        }
    }
    int data[n];
    for ( i = 0; i < n; i++)
    {
        data[i]=mhs[i].SKSlulus;
    }
    int hit[max+1];
    switch (mode)
    {
    case 1:
    printf("Mengurutkan..\n");
        for ( pass = 1; pass <= n-1; pass++)
        {
            for (x = 1; x <=n-pass; x++)
            {
                if (strcmp(mhs[x-1].nim,mhs[x].nim)>0)
                {
                    temp=mhs[x];
                    mhs[x]=mhs[x-1];
                    mhs[x-1]=temp;
                }
            } 
        }
        break;
    
    case 2:
        for (pass = 1; pass <= m-1; pass++)
        {
            imax=0;
            for ( x = 1; x <=m-pass; x++)
            {
                if (strcmp(arrkomp[imax].namamk,arrkomp[x].namamk)>0)
                {
                    imax=x;
                    printf("Tukar!\n");
                }
            }
            tempkomp=arrkomp[imax];
            arrkomp[imax]=arrkomp[m-pass];
            arrkomp[m-pass]=tempkomp;
        }
        break;

    case 3:
        for ( pass = 0; pass < n; pass++)
        {
            tukar=0;
            for ( k = 0; k < n-pass-1; k++)
            {
                if (mhs[k].ipk<mhs[k+1].ipk)
                {
                    temp=mhs[k];
                    mhs[k]=mhs[k+1];
                    mhs[k+1]=temp;
                    tukar++;
                }
            }
            if (tukar==0)
            {
                break;
            }
        }
        break;

    default:
        for ( x = 0; x <= max; x++){
            hit[x]=0;
        }
        for ( x = 0; x < n; x++)
        {
            hit[data[x]]++;;
        }
        z=n-1;        
        for ( x = 0; x <=max; x++)
        {
            if (hit[x] !=0)
            {
                for ( y = 1; y <= hit[x]; y++)
                {
                    data[z]=x;
                    z--;
                }
            }
        }
        printf("SKS lulus diurutkan berdasarkan terbesar :\n");
        for ( x = 0; x < n; x++)
        {
            printf("%d ",data[x]);
        }
        printf("\n");
        break;
    }
}

void buatindex(int n,int m){
    buatarray(2,n,m);
    int nilai;
    for ( i = 0; i < m; i++)
    {
        nilai=0;
        nilai=(arrkomp[i].uts*0.4)+(arrkomp[i].uas*0.6);
        switch (nilai)
        {
        case 80 ... 100: 
            arrkomp[i].indeks='A';
            break;
        
        case 70 ... 79: 
            arrkomp[i].indeks='B';
            break;
        case 55 ... 69: 
            arrkomp[i].indeks='C';
            break;
        case 40 ... 54: 
            arrkomp[i].indeks='D';
            break;       
        default:
        arrkomp[i].indeks='E';
            break;
        }
    }
}

void hitungip(int n,int m){
    FILE *fp;
    FILE *fj;

    fp=fopen("Mahasiswa.txt","r+");
    fj=fopen("Nilai.txt","r+");
    
    fread(&cetta,sizeof(cetta),1,fp);
    fread(&komp,sizeof(komp),1,fj);

    int jumlahsks,skslulus,jumlahbobot;
    float ipk;

    if (feof(fp) && feof(fj))
    {
        printf("File Kosong!\n");
    } else {
        for ( i = 0; i < n; i++)
        {
            jumlahsks=0;
            skslulus=0;
            jumlahbobot=0;
            while (!feof(fj) && strcmp(cetta.nim,komp.nim)==0)
            {   
                if (komp.indeks=='A'){
                    jumlahbobot=jumlahbobot+(4*komp.sks);
                    jumlahsks=jumlahsks+komp.sks;
                } else if (komp.indeks=='B'){
                    jumlahbobot=jumlahbobot+(3*komp.sks);
                    jumlahsks=jumlahsks+komp.sks;
                } else if (komp.indeks=='C'){
                    jumlahbobot=jumlahbobot+(2*komp.sks);
                    jumlahsks=jumlahsks+komp.sks;
                } else if (komp.indeks=='D'){
                    jumlahbobot=jumlahbobot+(1*komp.sks);
                    jumlahsks=jumlahsks+komp.sks;
                } else if (komp.indeks=='E'){
                    jumlahsks=jumlahsks+komp.sks;
                }
                fread(&komp,sizeof(komp),1,fj);
            }
            cetta.ipk=(float)jumlahbobot/jumlahsks;
            cetta.SKSlulus=jumlahsks;
            mhs[i]=cetta;
            fread(&cetta,sizeof(cetta),1,fp);
        }
        fclose(fp);
        fclose(fj);
        simpfile(1,n,m);
    }
}

void isiip(int n,int m){
    int x,y,z,pass;
        for ( pass = 1; pass <= m-1; pass++)
        {
            for (x = 1; x <=m-pass; x++)
            {
                if (strcmp(arrkomp[x-1].nim,arrkomp[x].nim)>0)
                {
                    tempkomp=arrkomp[x];
                    arrkomp[x]=arrkomp[x-1];
                    arrkomp[x-1]=tempkomp;
                }
            } 
        }
    urut(1,n,m);
    simpfile(1,n,m);
    simpfile(2,n,m);
    
    hitungip(n,m);
    
}

void peringkat(int n,int m){

    urut(3,n,m);

    printf("\nPeringkat 3 besar untuk IP tertinggi :\n");
    for ( i = 0; i < 3; i++)
    {
        printf("No.%d\t%s      \t%s\t%.2f\t%d\n",i+1,mhs[i].nama,mhs[i].nim,mhs[i].ipk,mhs[i].SKSlulus);
    }
    
}

void dropout(int n,int m){
    printf("\nMahasiswa DO karena IPK :\n");
    for ( i = 0; i < n; i++)
    {
        if (mhs[i].ipk<2.00)
        {
            printf("%s      \t%s\tdengan IPK :%.2f\t%d\n",mhs[i].nama,mhs[i].nim,mhs[i].ipk,mhs[i].SKSlulus);
        }
    }
    printf("\nMahasiswa DO Dikarenakan nilai E :\n");
    int x,y,z,pass;
        for ( pass = 1; pass <= m-1; pass++)
        {
            for (x = 1; x <=m-pass; x++)
            {
                if (strcmp(arrkomp[x-1].nim,arrkomp[x].nim)>0)
                {
                    tempkomp=arrkomp[x];
                    arrkomp[x]=arrkomp[x-1];
                    arrkomp[x-1]=tempkomp;
                }
            } 
        }
    urut(1,n,m);
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            if ((strcmp(mhs[i].nim,arrkomp[j].nim)==0)&&arrkomp[j].indeks=='E')
            {
                printf("%s      \t%s\t%.2f\tMata Kuliah : %s\t%c\n",mhs[i].nama,mhs[i].nim,mhs[i].ipk,arrkomp[j].namamk,arrkomp[j].indeks);
            }
        }
    }
}

void ganti(char carinim[10], char carimk[10],int *m,int n){
    int indeks,x,pass,pilganti,change;

    FILE *fj;
    fj=fopen("Nilai.txt","w");

    for ( i = 0; i < *m; i++)
    {
        if (strcmp(arrkomp[i].nim,carinim)==0 && strcmp(arrkomp[i].namamk,carimk)==0)
        {
            indeks=i;
            break;
        }
    }
    if (indeks==0)
    {
        printf("Mata Kuliah tidak ditemukan!\n");
    } else {
        printf("Masukan Komponen Yang ingin diganti\t:\n[1] UTS\n[2] UAS\n[3] Hapus Nilai\nInput :");
        scanf("%d",&pilganti);
        switch (pilganti)
        {
        case 1:
            printf("Masukan Nilai UTS\t:");
            scanf("%d",&change);
            scanf("%*c");
            arrkomp[indeks].uts=change;
            simpfile(2,n,*m);
            fclose(fj);
            buatarray(1,n,*m);
            buatindex(n,*m);
            isiip(n,*m);
            tampil(4,n,*m);
            break;
        
        case 2:
            printf("Masukan Nilai UAS\t:");
            scanf("%d",&change);
            scanf("%*c");
            arrkomp[indeks].uas=change;
            simpfile(2,n,*m);
            fclose(fj);
            buatarray(1,n,*m);
            buatindex(n,*m);
            isiip(n,*m);
            tampil(4,n,*m);
            break;

        default:
            strcpy(arrkomp[indeks].nim,"\0");
        for ( pass = 1; pass <= *m-1; pass++)
        {
            for (x = 1; x <=*m-pass; x++)
            {
                if (strcmp(arrkomp[x-1].nim,arrkomp[x].nim)>0)
                {
                    tempkomp=arrkomp[x];
                    arrkomp[x]=arrkomp[x-1];
                    arrkomp[x-1]=tempkomp;
                }
            } 
        }
        for ( i = 1; i < *m; i++)
        {
            fwrite(&arrkomp[i],sizeof(arrkomp[i]),1,fj);
        }
        *m=*m-1;
        fclose(fj);
        buatarray(1,n,*m);
        break;
        }
    }
    
}

void carimaha(int *indeks, char carinama[25],int n) {
    int pass,x,awal=1,akhir,tengah;
    akhir=n-1;
    *indeks=-1;
    for ( pass = 1; pass <= n-1; pass++)
        {
            for (x = 1; x <=n-pass; x++)
            {
                if (strcmp(mhs[x-1].nama,mhs[x].nama)>0)
                {
                    temp=mhs[x];
                    mhs[x]=mhs[x-1];
                    mhs[x-1]=temp;
                }
            } 
        }
    tengah=(awal+akhir)/2;
    while ((awal<=akhir) && strcmp(carinama,mhs[tengah].nama)!=0)
    {
        if (strcmp(carinama,mhs[tengah].nama)>0)
        {
            awal=tengah+1;
        } else if(strcmp(carinama,mhs[tengah].nama)<0) 
        {
            akhir=tengah-1;
        }
        tengah=(awal+akhir)/2;
    }
    if (strcmp(carinama,mhs[tengah].nama)==0)
    {
        *indeks=tengah;
    }
}

int main(){
    int N,M,indeks;
    int pilmode;
    char Carinim[10],CariMK[10],Carinama[25];
    printf("Dibuat Oleh : Cetta Maulana A.\t1103213110\tTK-45-04\n");
    printf("Masukan Jumlah Mahasiswa :");
    scanf("%d",&N);
    printf("Masukan Jumlah Nilai :");
    scanf("%d",&M);
    scanf("%*c");
    isimhs(N,M);
    // isimhsmanual(N,M);
    for ( j = 0; j < 2; j++)
    {
        buatarray(i,N,M);
    }
    tampil(3,N,M);
    tampil(4,N,M);
    buatindex(N,M);
    isiip(N,M);
    peringkat(N,M);
    dropout(N,M);
    printf("Masukan NIM yang ingin dicari : ");
    fgets(Carinim,10,stdin);
    strtok(Carinim,"\n");
    printf("Masukan Mata Kuliah yang ingin dicari : ");
    fgets(CariMK,10,stdin);
    strtok(CariMK,"\n");
    ganti(Carinim,CariMK,&M,N);
    isiip(N,M);
    dropout(N,M);
    printf("Masukan Nama Mahasiswa Yang dicari :");
    fgets(Carinama,25,stdin);
    strtok(Carinama,"\n");
    carimaha(&indeks,Carinama,N);
    if (indeks==-1)
    {
        printf("Mahasiswa tidak ditemukan\n");
    } else {
        printf("Mahasiswa ditemukan :\n%s\t%s\t%.2f\t%d\n",mhs[indeks].nama,mhs[indeks].nim,mhs[indeks].ipk,mhs[indeks].SKSlulus);
    }
}