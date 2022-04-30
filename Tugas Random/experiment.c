#include <stdlib.h>
#include <stdio.h>

int main(){
    int i,j,k;
    int nim;
    char nama[10];

    FILE *fp;
    fp = fopen ("x.txt","w");
    scanf("%d",&j);

    for ( i = 0; i < j; i++)
    {
        scanf("%d",&nim);
        scanf("%*c");
        fgets(nama,10,stdin);
        strtok(nama,"\n");
        fwrite(&nim,sizeof(nim),1,fp);
        fwrite(&nama,sizeof(nama),1,fp);
    }
    
}