#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void cek(float uang) {
    float temp;
    temp=uang*14.800;
    uang=temp/436;
    printf("%.3f Baht\n",uang);
}

int main(){
    float duit;
    printf("Masukan Uang (dalam dolar)\t:");
    scanf("%f",&duit);
    cek(duit);
    
}
/*void login(char user[20],int pass) {
    if (strcmp(user,"cetta")==0)
    {
        if (pass==1103213119)
        {
            printf("Anda Berhasil Log-In!\n");
        } else {
            printf("Password Anda salah!\n");
        }
        
    } else {
        printf("Username anda salah!\n");
    }
}

int main(){
    char username[20];
    int password;
    
    printf("Masukan Username\t:");
    fgets(username,20,stdin);
    strtok(username,"\n");
    printf("Masukan Password\t:");
    scanf("%d",&password);
    login(username,password);
}*/