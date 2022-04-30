#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,n,bilangan;
    printf("===Program pengecekan Ganjil Genap===\n");
    printf("masukan jumlah pengulangan :");
    scanf("%d",&n);

    for (i = 1; i <= n; i++)
    {
        printf("masukan angka ke-%d :",i);
        scanf("%d",&bilangan);
        if (bilangan%2==1)
        {
            printf("angka %d merupakan bilangan ganjil\n",bilangan);
        } else {
            printf("angka %d merupakan bilangan genap\n",bilangan);
        }
        
    }
    

}