#include <stdio.h>
#include <stdlib.h>

void pengurutan(){
}
int main() {
    int i,j;
    char temp[10];
    char huruf='a';
    char huruf2='b';
    printf("Data yang belum disortir :\n");
    
    printf("%c\n%c",huruf,huruf2);

    if (huruf<huruf2)
    {
        strcpy(temp,huruf);
        strcpy(huruf,huruf2);
        strcpy(huruf2,temp);
    }
    
    
    printf("\ndata yang telah disortir :\n");
    printf("%c\n%c",huruf,huruf2);
    printf("\n");
    
}