#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        File adalah identitas dari data yang disimpan di dalam berkas sistem yang dapat diakses dan diatur oleh pengguna

        Deklarasi file: (Di Dalam Program Utama)
        
        FILE *variabel_file;


        Dalam pengoperasian file, file perlu dibuka saat ingin melakukan operasi dan ditutup setelah selesai operasi

        Deklarasi open dan close file: (Di Dalam Program Utama)

        variabel_file = fopen("nama_file.txt","mode");


        
        Terdapat beberapa mode yang terdapat pada operasi file:
        1. r = untuk membaca file (file harus ada)
        2. w = untuk menulis file (file yang sudah ada akan dihapus)
        3. a = untuk membuka file yang sudah ada dan pada prosesnya dilakukan penambahan saat menulis
               (jika file belum ada, file akan dibuat secara otomatis)
        4. r+ = untuk membaca file, tapi bisa menulis juga
        5. w+ = untuk menulis file tetapi juga untuk membaca (file yang sudah ada akan dihapus)
        6. a+ = Membuka file yang sudah ada dan prosesnya dilakukan penambahan saat menulis dan membaca file
    */

    FILE *fp;
    // fp = fopen("test.txt","w");
    // fputs("Jadi begini, ya begitu aja si", fp);
    // printf("File telah diisi\n\n");
    // fclose(fp);

    // char str[100];
    // fp = fopen("test.txt","r");
    // fgets(str,100,fp);
    // printf("Hasil dari membaca file:\n%s\n\n", str);


    //CRUD file
    char *nama_kucing[] ={
        "Ya'qub Qomarudin Dibizah", "Khalid Kashimiri", "Khidir Karawitah", "Ismail Ahmad Khan Nabawi", "Utsman Abdul Jalil Shisha", "Muhammad Sumbul"
    };
    int size = sizeof(nama_kucing) / sizeof(nama_kucing[0]);
    int i;

    // printf("Nama kucing yang ingin dimasukkan: \n");
    // for(i=0; i<size; i++){
    //     puts(nama_kucing[i]);
    // }
    // printf("\n");

    FILE *fo;
    // printf("=== Menulis ===");

    // fo = fopen("kucing.txt","w");
    // for(i = 0; i < size; i++){
    //     fputs(nama_kucing[i], fo);
    //     fputs("\n", fo);
    // }
    // printf("\nNama kucing sudah masuk\n\n");
    // fclose(fo);


    printf("\n=== Membaca ===\n");
    
    char baca_nama[size][100];
    i = 0;
    fo = fopen("kucing.txt", "r");

    if (fo == NULL){
        printf("Tidak ada data file\n\n");
    }
    else{
        printf("Nama-nama kucing kamu:\n");
        while (fgets(baca_nama[i], sizeof(baca_nama), fo) != NULL ){
            printf("%s", baca_nama[i]);
        }
    }
    fclose(fo);

    printf("\n=== Menghapus ===\n");
    int x = 0;
    FILE *fx;
    
    fx = fopen("kucing.txt", "w");
    
    fclose(fx);
    printf("Nama kucing berhasil dihapus (bukan kucingnya)\n\n");

    
    return 0;
}