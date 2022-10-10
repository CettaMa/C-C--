#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tabint[9];
int i,n=9;

void carinilai3(int *indeksnilai){
    *indeksnilai=tabint[0];

    for ( i = 0; i <= n; i++)
    {
        if (tabint[i]%3==0)
        {
            if (tabint[i]>*indeksnilai)
            {
                *indeksnilai=i;
            }
        }
    } 
}

void cariindeks3(int *indeksnilai){
    *indeksnilai=tabint[0];

    for ( i = 0; i <= n; i++)
    {
        if (i%3==0)
        {
            if (tabint[i]>*indeksnilai)
            {
                *indeksnilai=i;
            }
        }
    } 

}

int main(){
    int indeks;

    for ( i = 0; i < n; i++)
    {
        printf("Masukan nilai array %d\t:",i);
        scanf("%d",&tabint[i]);
    }
    carinilai3(&indeks);
    printf("Nilai kelipatan tiga terbesar adalah %d dengan indeks %d\n",tabint[indeks],indeks);

    cariindeks3(&indeks);
    printf("Nilai kelipatan tiga terbesar adalah %d dengan indeks %d\n",tabint[indeks],indeks);
}