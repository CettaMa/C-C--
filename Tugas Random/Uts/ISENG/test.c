#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int x=5,y=3;
    do
    {
        x=x-x%y;
        x=x-x/y;
        printf("%d ",x);
    } while (x>1);
    
}

