#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct mahasiswa{
    char nim[20],nama[20],MK[20];
    int nilai;
}mhs,arrmhs[10],Temp;

void isimhs(){
    FILE *fp;
    fp=fopen("datamhsacak.txt","w");

    strcpy(mhs.nim,"1103213118");
    strcpy(mhs.nama,"rafiandi");
    strcpy(mhs.MK,"fisika");
    mhs.nilai=80;
    fwrite(&mhs,sizeof(mhs),1,fp);

    strcpy(mhs.nim,"1103213124");
    strcpy(mhs.nama,"david");
    strcpy(mhs.MK,"fisika");
    mhs.nilai=90;
    fwrite(&mhs,sizeof(mhs),1,fp);
    strcpy(mhs.nim,"1103213130");
    strcpy(mhs.nama,"ibrahim");
    strcpy(mhs.MK,"fisika");
    mhs.nilai=89;
    fwrite(&mhs,sizeof(mhs),1,fp);
    strcpy(mhs.nim,"1103213118");
    strcpy(mhs.nama,"rafiandi");
    strcpy(mhs.MK,"kalkulus");
    mhs.nilai=70;
    fwrite(&mhs,sizeof(mhs),1,fp);
    strcpy(mhs.nim,"1103213124");
    strcpy(mhs.nama,"david");
    strcpy(mhs.MK,"kalkulus");
    mhs.nilai=80;
    fwrite(&mhs,sizeof(mhs),1,fp);
    strcpy(mhs.nim,"1103213130");
    strcpy(mhs.nama,"ibrahim");
    strcpy(mhs.MK,"kalkulus");
    mhs.nilai=79;
    fwrite(&mhs,sizeof(mhs),1,fp);
    strcpy(mhs.nim,"1103213130");
    strcpy(mhs.nama,"ibrahim");
    strcpy(mhs.MK,"agama");
    mhs.nilai=94;
    fwrite(&mhs,sizeof(mhs),1,fp);
    strcpy(mhs.nim,"1103213118");
    strcpy(mhs.nama,"rafiandi");
    strcpy(mhs.MK,"agama");
    mhs.nilai=90;
    fwrite(&mhs,sizeof(mhs),1,fp);
    strcpy(mhs.nim,"1103213130");
    strcpy(mhs.nama,"ibrahim");
    strcpy(mhs.MK,"pkn");
    mhs.nilai=86;
    fwrite(&mhs,sizeof(mhs),1,fp);
    fclose(fp);
}

void bacamhs(jdata){
    int i;
    FILE *fp;
    fp=fopen("datamhsacak.txt","r");
    for(i=0;i<jdata;i++){
        fread(&arrmhs[i],sizeof(arrmhs[i]),1,fp);
        printf("%s %s\n",arrmhs[i].nim, arrmhs[i].MK);
    }
    fclose(fp);
}

void urutnim(jdata){
    int i,Pass,Imax;
    for(Pass=1;Pass<=jdata-1;Pass++){
        Imax=0;
        for(i=1;i<=jdata-Pass;i++)
            if(strcmp(arrmhs[Imax].nim,arrmhs[i].nim)<0)
                Imax=i;
        Temp=arrmhs[Imax];
        arrmhs[Imax]=arrmhs[jdata-Pass];
        arrmhs[jdata-Pass]=Temp;
    }
    FILE *fj;
    fj=fopen("datamhsurut.txt","w");
    printf("Setelah diurutkan\n");
    for(i=0;i<jdata;i++){
        printf("%s %s %d\n", arrmhs[i]. nim,arrmhs[i].nama,arrmhs[i].nilai);
        fwrite(&arrmhs[i],sizeof(arrmhs[i]),1,fj);
    }
    fclose(fj);
}

void konsolidasi(){
    FILE *fj;
    fj=fopen("datamhsurut.txt","r");
    fread(&mhs,sizeof(mhs),1,fj);
    int jumlahnilai,cacah;
    char currentnim[20],currentnama[20];
    float rata;
    if(feof(fj)){
        printf("File kosong\n");
    }
    else{
        while(!feof(fj)){
            jumlahnilai=0;
            cacah=0;
            //printf("%s %s\n",mhs.nim,mhs.nama);
            strcpy(currentnim,mhs.nim);
            strcpy(currentnama,mhs.nama);
            while(!feof(fj) && strcmp(currentnim,mhs.nim)==0){
                jumlahnilai+=mhs.nilai;
                cacah++;
                fread(&mhs,sizeof(mhs),1,fj);
            }
            rata=(float)jumlahnilai/cacah;
            printf("Mahasiswa dengan nim %s bernama %s memiliki rata-rata %f\n",currentnim,currentnama,rata);
        }
    }
    fclose(fj);
}

int main()
{
    int jdata;
    jdata=9;
    isimhs();
    bacamhs(jdata);
    urutnim(jdata);
    konsolidasi();
    return 0;
}


/*
struct mahasiswa{
    char nim[20],nama[20];
    int totnilai;
}mhs,arrmhs[5],Temp;

struct nilai{
    char nim[20],MK[20];
    int nilai;
}nil,arrnil[10],tnil;

void isimhs(){         // Sengaja diisikan dalam keadaan urut nim
    FILE *fp;
    fp=fopen("datamhs.txt","w");
    strcpy(mhs.nim,"1103213118");
    strcpy(mhs.nama,"rafiandi");
    fwrite(&mhs,sizeof(mhs),1,fp);
    strcpy(mhs.nim,"1103213124");
    strcpy(mhs.nama,"david");
    fwrite(&mhs,sizeof(mhs),1,fp);
    strcpy(mhs.nim,"1103213130");
    strcpy(mhs.nama,"ibrahim");
    fwrite(&mhs,sizeof(mhs),1,fp);
    fclose(fp);
}
void isinil(){
    FILE *fp;
    fp=fopen("datanil.txt","w");
    strcpy(nil.nim,"1103213118");
    strcpy(nil.MK,"fisika");
    nil.nilai=80;
    fwrite(&nil,sizeof(nil),1,fp);
    strcpy(nil.nim,"1103213124");
    strcpy(nil.MK,"fisika");
    nil.nilai=90;
    fwrite(&nil,sizeof(nil),1,fp);
    strcpy(nil.nim,"1103213130");
    strcpy(nil.MK,"fisika");
    nil.nilai=70;
    fwrite(&nil,sizeof(nil),1,fp);
    strcpy(nil.nim,"1103213118");
    strcpy(nil.MK,"kalkulus");
    nil.nilai=70;
    fwrite(&nil,sizeof(nil),1,fp);
    strcpy(nil.nim,"1103213124");
    strcpy(nil.MK,"kalkulus");
    nil.nilai=80;
    fwrite(&nil,sizeof(nil),1,fp);
    strcpy(nil.nim,"1103213130");
    strcpy(nil.MK,"kalkulus");
    nil.nilai=80;
    fwrite(&nil,sizeof(nil),1,fp);
    strcpy(nil.nim,"1103213130");
    strcpy(nil.MK,"agama");
    nil.nilai=90;
    fwrite(&nil,sizeof(nil),1,fp);
    strcpy(nil.nim,"1103213118");
    strcpy(nil.MK,"agama");
    nil.nilai=90;
    fwrite(&nil,sizeof(nil),1,fp);
    strcpy(nil.nim,"1103213130");
    strcpy(nil.MK,"pkn");
    nil.nilai=100;
    fwrite(&nil,sizeof(nil),1,fp);
    fclose(fp);
}


void bacadata(mode,jdata){
    int i;
    FILE *fp;
    if (mode==1){
        fp=fopen("datamhs.txt","r");
        for(i=0;i<jdata;i++)
          fread(&arrmhs[i],sizeof(arrmhs[i]),1,fp);
    }
    else {
        fp=fopen("datanil.txt","r");
        for(i=0;i<jdata;i++)
          fread(&arrnil[i],sizeof(arrnil[i]),1,fp);

    }
}

void urutnim(jdata){
    int i,Pass,Imax;
    for(Pass=1;Pass<=jdata-1;Pass++){
        Imax=0;
        for(i=1;i<=jdata-Pass;i++)
            if(strcmp(arrnil[Imax].nim,arrnil[i].nim)<0)
                Imax=i;
        tnil=arrnil[Imax];
        arrnil[Imax]=arrnil[jdata-Pass];
        arrnil[jdata-Pass]=tnil;
    }
    FILE *fj;
    fj=fopen("urutnil.txt","w");
    printf("Setelah diurutkan\n");
    for(i=0;i<jdata;i++){
        printf("%s %s %d\n", arrnil[i]. nim,arrnil[i].MK,arrnil[i].nilai);
        fwrite(&arrnil[i],sizeof(arrnil[i]),1,fj);
    }
    fclose(fj);
}

void unseparated(jmhs,jnilai){
    int i,j;
    FILE *fp,*fj ;
    fp=fopen("datamhs.txt","r");
    fj=fopen("urutnil.txt","r");
    int jumlahnilai,cacah;
    char currentnim[20],currentnama[20];
    float rata;
    /*if(feof(fp)){
        printf("File tidak ada\n");
    }
    else
        */

  /*      i=0;j=0;
        while(i<jmhs){
            fread(&arrmhs[i],sizeof(arrmhs[i]),1,fp);
            printf("%s %s\n",arrmhs[i].nim,arrmhs[i].nama);
            i++;
        }
        while(j<jnilai){
            fread(&arrnil[j],sizeof(arrnil[j]),1,fj);
            printf("%s %d\n",arrnil[j].nim,arrnil[j].nilai);
            j++;
        }
        fclose(fp);
        fclose(fj);
        i=0;j=0;
        while(i<jmhs){
            jumlahnilai=0;
            cacah=0;
            rata=0;
            //printf("%s %s\n",arrmhs[i].nim,arrmhs[i].nama);
            strcpy(currentnim,arrmhs[i].nim);
            strcpy(currentnama,arrmhs[i].nama);
            while(strcmp(currentnim,arrnil[j].nim)==0){
              //printf("%s %d\n",arrnil[j].nim,arrnil[j].nilai);
              jumlahnilai+=arrnil[j].nilai;
              cacah++;
              j++;
            }

            //printf("%d %d\n",jumlahnilai,cacah);
            rata=(float)jumlahnilai/cacah;
            printf("Mahasiswa dengan nim %s bernama %s memiliki rata-rata %f\n",currentnim,currentnama,rata);

        i++;
        }
}

int main()
{
    int jmhs,jnilai;
    jmhs=3;
    jnilai=9;
    isimhs();
    isinil();
    bacadata(1,jmhs);
    bacadata(2,jnilai);
    urutnim(jnilai);
    unseparated(jmhs,jnilai);
    return 0;
}
*/