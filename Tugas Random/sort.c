#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void datakcg()
{

    FILE fp;
    struct kucing{
        char nama[10];
        char jenis[10];
        int mutu,nilakhir,badan,bulu,diskon;
        float hargaakhir,harga;
        }kcg[10],bacakcg[10];
    int i,n;
    int k,Pass,Temp,Tukar,nilakhir,badan,bulu,diskon;
    float hargaakhir,harga;

    fp = fopen("Kucing.txt","w");
    printf("Masukkan Jumlah Kucing : ");
    scanf("%d",&n);
    fflush(stdin);
    for(i=0;i<n;i++){
        printf("Nama Kucing : ");
        fflush(stdin);
        fgets(kcg[i].nama,10,stdin);
        strtok(kcg[i].nama,"\n");
        printf("Jenis Kucing : ");
        fflush(stdin);
        fgets(kcg[i].jenis,10,stdin);
        strtok(kcg[i].jenis,"\n");
        printf("Mutu Kucing : ");
        scanf("%d",&kcg[i].mutu);
        if(strcmp(kcg[i].jenis,"Kampung")==0){
            switch(kcg[i].mutu){
                case 1 : kcg[i].badan=50;kcg[i].bulu=50;kcg[i].diskon=10;break;
                case 2 : kcg[i].badan=30;kcg[i].bulu=50;kcg[i].diskon=15;break;
                default : printf("error");
                }
            kcg[i].nilakhir = kcg[i].badan+kcg[i].bulu;
            kcg[i].harga = kcg[i].nilakhir 500;
            kcg[i].hargaakhir = kcg[i].harga * (100 - kcg[i].diskon)/100;
            }
        else if(strcmp(kcg[i].jenis,"Persia")==0){
            kcg[i].nilakhir = kcg[i].badan+kcg[i].bulu;
            switch(kcg[i].mutu){
                case 1 : kcg[i].badan=100;kcg[i].bulu=200;kcg[i].diskon=10;break;
                case 2 : kcg[i].badan=75;kcg[i].bulu=150;kcg[i].diskon=15;break;
                case 3 : kcg[i].badan=50;kcg[i].bulu=120;kcg[i].diskon=20;break;
                default : printf("error");
            }
            kcg[i].nilakhir = kcg[i].badan+kcg[i].bulu;
            kcg[i].harga = kcg[i].nilakhir * 1000;
            kcg[i].hargaakhir = kcg[i].harga * (100 - kcg[i].diskon)/100;
        }
        fwrite(&kcg[i],sizeof(kcg[i]),1,fp);
    }
    printf("\n");
    printf("Berikut data kucing :");
    fclose(fp);

    fp = fopen("Kucing.txt", "r");
    for(i=0;i<n;i++){
        fread(&bacakcg[i],sizeof(bacakcg[i]),1,fp);
        printf("\nNama : %s. Dengan jenis %s mutu-%d dengan harga %.2f",bacakcg[i].nama,bacakcg[i].jenis,bacakcg[i].mutu,bacakcg[i].hargaakhir);
        }
    Pass = 1; Tukar =1;
    while (Pass <= n-1 && Tukar==1) {
    Tukar = 0;
    for (k=1;k<=n-Pass;k++) {
        if (strcmp(bacakcg[k-1].nama,bacakcg[k].nama)>0){
        strcpy(Temp,bacakcg[k].nama);
        strcpy(bacakcg[k].nama,bacakcg[k-1].nama);
        strcpy(bacakcg[k-1].nama,Temp);
        Tukar = 1;}
        Pass = Pass + 1;}

    printf("Sorting menurut nama menggunakan modified bubblesort :");

    for(i=0;i<n;i++){
        printf("%s\n",kcg[i].nama);
    }
}
    int main()
    {
        datakcg();

        return 0;
    }