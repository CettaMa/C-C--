#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imt (float berat, float tinggi){
    float imt;
    tinggi=tinggi*0.01;
    tinggi=(tinggi*tinggi);
    imt=berat/tinggi;
    if (imt<18.5)
    {
        printf("IMT :%.2f\n",imt);
        printf("Kamu terlalu kurus!\n");
    } else if (imt>=18.5 && imt<25){
        printf("IMT :%.2f\n",imt);
        printf("Kamu IDEAL\n");
    }else {
        printf("IMT :%.2f\n",imt);
        printf("Kamu Kegendutan!\nJaga pola Makannya!\n");
    }
    
}
int main(){
    float bb,tb;
    printf("Masukan Berat badan anda\t:");
    scanf("%f",&bb);
    printf("Masukan tinggi badan anda\t:");
    scanf("%f",&tb);
    imt(bb,tb);
}