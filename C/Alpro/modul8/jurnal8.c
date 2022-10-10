#include <stdio.h>
#include <stdlib.h>
#include <string.h> //menambahkan lib yang diperlukan

int main()
{
    char data[50];
    int i=0;
    FILE *fp;
    fp=fopen("data.txt", "w"); //mengganti dat.txt menjadi data.txt serta mode menjadi write    
    printf("--- Selamat Datang di Aplikasi Registrasi Mata Kuliah ---\n");
    printf(" Silahkan Masukkan Mata kuliah yang anda ambil\n\n");
    for(i=0; i<3; i++) //memperbaiki batas loop
    {
        printf("Masukkan mata kuliah ke-%d : ", i+1); fgets(data,50,stdin); strtok(data,"\n"); //mengganti scanf menjadi fgets
        fprintf(fp, "%s\n",data);
    }
    fclose(fp);
    printf("\n\n--- Mata Kuliah yang anda pilih telah berhasil disimpan ---\n\n");
    i = 1;
    fp=fopen("data.txt", "r"); //memperbaiki fpoen menjadi fopen
    printf("\n\n--- Review Mata Kuliah Yang Anda Ambil ---\n\n");

    while(fgets(data,sizeof(data),fp) && !feof(fp))
    {
        printf("Mata Kuliah ke-%d : %s", i,data); //mengubah data.txt menjadi data
        i++;
    }
    fclose(fp);
    return 0:
}