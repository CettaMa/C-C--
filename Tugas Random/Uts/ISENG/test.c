#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login(int L){
    struct aplikasi{
    char data[50],data2[50];
    int  password, password2;
    }app[50];
    int i=0;
    FILE *fp;
    fp = fopen("registrasi.txt", "w");
    printf("Silahkan melakukan Registrasi Terlebih Dahulu : \n");

    for(i=0;i<1;i++){
    
    }
    printf("Username : ");
    fgets(app[i].data,50,stdin);
    strtok(app[i].data,"\n");
    printf("Password : ");
    scanf("%d",&app[i].password);
    scanf("%*c");
    fprintf(fp, "Akun yang telah diregistrasi\n");
    fprintf(fp, "Username : %s\n", app[i].data);
    fprintf(fp, "Password : %d\n", app[i].password);
    printf("Silahkan Login Keakun Yang Telah Diregistrasi\n");
    for(i=0;i<1;i++){
    
    }
    printf("Username : ");
    fgets(app[i].data2,50,stdin);
    strtok(app[i].data2,"\n");
    printf("Password : ");
    scanf("%d",&app[i].password2);
    fprintf(fp, "Akun yang digunakan untuk login\n");
    fprintf(fp, "Username : %s\n", app[i].data2);
    fprintf(fp, "Password : %d\n", app[i].password2);
    fclose(fp);

    fp = fopen("registrasi.txt", "r");

    if(strcmp(app[i].data,app[i].data2)==0){
        if(app[i].password2 == app[i].password){
            printf("Login Sukses");
        }
    }   else    {
            printf("Maaf Username Atau Password Salah");
    }
    fclose(fp);
}
void mahasiswa(int m){
    int menu,nim;
    char nama[30],hadir[10];
    printf("(1) Melihat Jadwal\n");
    printf("(2) Melakukan Presensi\n");
    printf("Silahkan Memilih Menu Berikut : ");
    scanf("%d",&menu);
    if (menu=1){
        printf("BERIKUT ADALAH MENU MELIHAT JADWAL : \n");
    }
    else if (menu=2){
        printf("BERIKUT ADALAH MENU PRESENSI : ");
        printf("Masukkan Nama : \n");scanf("%s",&nama[30]);
        printf("Masukkan NIM : ");scanf("%d",&nim);
        printf("Ketik Hadir untuk Melakukan Presensi : ");scanf("%d",hadir[10]);
    }
}

int main (){
    int L,pilih;
    printf("-----Selamat datang diaplikasi Presencia-----\n");
    printf("(1) Untuk Masuk Sebagai Mahasiswa\n");
    printf("(2) Untuk Masuk sebagai Dosen\n");
    printf("Silahkan memilih masuk sebagai : ");
    scanf("%d",&pilih);
    scanf("%*c");
    if (pilih=1){
        login(L);
    }
    else if (pilih=2){
        login(L);
    }
return 0;
}