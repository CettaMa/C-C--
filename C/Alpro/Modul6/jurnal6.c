#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    int n,i,pass,temp; //mendeklarasikan i
    printf("Masukan jumlah data :");
    scanf("%d",&n); //menambah "&"

    int data[n]; //diubah agar mendeklarasikan array
    for (i = 0; i < n; i++)
    {
        printf("data ke-%d = ",i+1);
        scanf("%d",&data[i]); //mengganti "%s" dengan "%d"
    }
    
    for (pass = 1; pass < n; pass++)
    {
        for (i = 0; i < n-1; i++)
        {
            if (data[i]>data[i+1]){
            temp=data[i];
            data[i]=data[i+1];
            data[i+1]=temp;
            } //memperbaiki algoritma sesuai dengan algoritma bubble sort
        }
    }
    printf("\ndata setelah diurutkan :\n");
    for (i = 0; i < n; i++)
    {
        printf("data ke-%d = %d\n",i+1,data[i]);
    }
    
}