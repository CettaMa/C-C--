#include <stdio.h>
#include <stdlib.h>

void bilmin(float bil[20]) {
    float min;
    int i, n;
    printf("====Input====\n");
    printf("N :");
    scanf("%d",&n);
    min=1000;
    for (i = 0; i < n; i++)
    {
        printf("Numb-%d :",i);
        scanf("%f",&bil[i]);
        if (bil[i]<min) {
        min=bil[i];
        }
    }
    printf("=====Output====\n");
    printf("Minimum Of Number :%.2f\n",min);
        
}

int main () {
    float bilangan[20];
    bilmin(bilangan);
    return 0;

}