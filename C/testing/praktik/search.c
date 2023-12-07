#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        Searching adalah algoritma yang digunakan untuk mencari nilai dari sebuah Array 

        Algoritma pencarian dibagi 2:
        1. Sequential Search: Algoritma yang memeriksa setiap data /  nilai dari indeks pertama array 
           tersebut sampai indeks terakhir array tersebut.
           Contoh: Linear Search

        2. Interval Search: Algoritma yang lebih efisien karena tidak harus mengecek semua indeks dalam
           array tersebut, namun array tersebut harus diurutkan terlebih dahulu.
           Contoh: Binary Search 
    */

    // /*
    //     Linear Search adalah metode yang bekerja dengan cara mengecek satu persatu isi array tersebut dari awal
    // */

    // int i;
    // int arr_nilai[5] = {53, 3, 31, 43, 65};
    // int size = sizeof(arr_nilai)/sizeof(arr_nilai[0]);
    
    // // Nilai yang dicari
    // int targetNilai;
    // printf("Masukkan nilai yang dicari: ");
    // scanf("%d",&targetNilai);

    // int indexTarget = -1;

    // for (i = 0; i < size; i++){
    //     if (targetNilai == arr_nilai[i]){
    //         indexTarget = i;
    //     }
    // }

    // if (indexTarget == -1){
    //     printf("\n\nNilai yang dicari tidak ditemukan\n\n");
    // }
    // else{
    //     printf("\n\nNilai ditemukan pada indeks: %d\n\n", indexTarget);
    // }


    /*
        Binary Search hanya bisa digunakan setela diurutkan
    */

    int arr_nilai[5] = {253, 643, 594, 193, 773};
    
    int targetNilai;
    printf("Masukkan nilai yang dicari: ");
    scanf("%d",&targetNilai);

    int indexTarget = -1;
    
    int low = 0, high = 4;

    while (low <= high){
        int mid = (low + high) / 2;
        printf("mid: %d\n", mid);

        if (arr_nilai[mid] == targetNilai){
            indexTarget = mid;
            break;
        }

        if (arr_nilai[mid] > targetNilai){
            high = mid - 1;
        }

        if (arr_nilai[mid] < targetNilai){
            low = mid + 1;
        }
    }

    if (indexTarget == - 1){
        printf("Nilai yang dicari tidak ditemukan\n\n");
    }
    else{
        printf("Nilai yang dicari ditemukan pada index: %d\n", indexTarget);
    }
    return 0;
}