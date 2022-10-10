#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, pass, temp;
    int carinilai;
    int indeksnilai=-1; //nilai indeks yang dicari
    int low = 0, high; //deklarasi nilai atas dan bawah
    printf("Masukan Jumlah data\t:");
    scanf("%d",&high);
    int isidata[high];

    for (i = 0; i < high; i++)
    {
        printf("Data Ke-%d\t:",i+1);
        scanf("%d",&isidata[i]);
    }
    printf("Mengurutkan data...\n");
    for (pass = 0; pass < high; pass++)
    {
        for (i = pass+1; i < high; i++)
        {
            if (isidata[pass]>isidata[i])
            {
                temp=isidata[pass];
                isidata[pass]=isidata[i];
                isidata[i]=temp;
            }
        }
    }
    printf("Pengurutan selesai!\n");
    high-1;
    printf("Nilai Yang dicari :");
    scanf("%d",&carinilai); //memasukan nilai yang ingin dicari    
    while (low <= high){
        int mid =(high+low)/2;
        printf("Mid : %d\n",mid);
        if (isidata[mid]==carinilai){ //apabila nilai ditemukan, algortima akan berhenti
            indeksnilai=mid;
            break; 
        }
        
        if (isidata[mid]>carinilai){ //nilai tidak ditemukan, mengganti nilai tengah dengan nilai atas
            high=mid -1;
        }
        if (isidata[mid]<carinilai){ //nilai tidak ditemukan, mengganti nilai tengah dengan nilai bawah
            low=mid +1;
        }
    }
    if (indeksnilai>=0){
        printf("Nilai terdapat pada indeks :%d",indeksnilai);
    } else {
        printf("Nilai tidak ditemukan");
    } //menampilkan data
}