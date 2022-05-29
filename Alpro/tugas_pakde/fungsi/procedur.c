#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,n,x[100];
 
void inputdata() {
       for ( i = 0; i < n; i++){
        printf("Masukan data array X ke-%d\t:",i+1);
        scanf("%d",&x[i]);
       }
}
 
void output() {
   for ( i = 0; i < n; i++){
       printf("data X[%d] adalah\t:%d\n",i,x[i]);
   }
}
 
 void rata(){
    float rata;
    for ( i = 0; i < n; i++){
         rata=rata+x[i];
    }
    rata=(float)rata/n;
    printf("\nArray X memiliki rata-rata\t:%.2f\n",rata);
 }

void cari(){
    int carinilai,ketemu,indeks;

    printf("Masukan nilai yang ingin dicari\t:");
    scanf("%d",&carinilai);

    for ( i = 0; i < n; i++){
        if (carinilai==x[i]){
            ketemu=1;
            indeks=i;
            break;
        } else {
            ketemu=0;
        }
    }
    if (ketemu==1){
        printf("\nnilai %d ditemukan di indeks %d\n",carinilai,indeks);
    } else {
        printf("\nNilai tidak ditemukan\n");
    }
}

int main(){
   printf("Masukan Jumlah data\t:");
   scanf("%d",&n);
   
   inputdata();

   printf("\nArray X\t:\n");
   
   output();

   rata();

   cari();

}
