#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    float tinggiBadan, beratBadan,BMI;
    printf("Masukan tinggi badan anda : ");
    scanf("%f",&tinggiBadan);
    // strtok("\n",tinggiBadan);
    printf("Masukan berat badan anda : ");
    scanf("%f",&beratBadan);
    // strtok("\n",beratBadan);
    tinggiBadan=tinggiBadan/100;
    tinggiBadan=pow(tinggiBadan, 2);
    BMI=beratBadan/tinggiBadan;
    printf("%f %f Berat badan ideal kamu adalah = %f",tinggiBadan,beratBadan,BMI);
}