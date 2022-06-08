#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct test
    {
        int nim,nilai;
        char nama[20];
    }mahasiswa,arraymahasiswa;
    
    FILE *fp;
    fp=fopen("text.txt","w");
    scanf("%d",&input);
    fwrite(&input,10,1,fp);
    fclose(fp);
    fp=fopen("text.txt","r");
    fread(&output,10,1,fp);
    printf("%d",output);
}