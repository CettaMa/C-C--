#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,b,k,MatriksA[4],MatriksB[4],MatriksHasil[4];

  printf("===MATRIKS A===\n");
  printf("Masukan nilai matriks baris 1 kolom 1 :");
  scanf("%d",&MatriksA[1]);
  printf("Masukan nilai matriks baris 1 kolom 2 :");
  scanf("%d",&MatriksA[2]);
  printf("Masukan nilai matriks baris 2 kolom 1 :");
  scanf("%d",&MatriksA[3]);
  printf("Masukan nilai matriks baris 2 kolom 2 :");
  scanf("%d",&MatriksA[4]);
  
  printf("\n|");
  for (i = 1; i <=2; i++)
  {   
    printf(" %d ",MatriksA[i]);
  }
  printf("|\n|");
  for (i = 3; i <=4; i++)
  {   
    printf(" %d ",MatriksA[i]);
  }
  
  printf("|\n");
  printf("===MATRIKS B===\n"); 
  i=1;
  for (b = 1; b <= 2; b++)
    for (k= 1; k <= 2; k++)
    {
      printf("Masukan nilai matriks baris %d kolom %d :",b,k);
      scanf("%d",&MatriksB[i]);
      i++;
    }
  printf("\n|");
  for (i = 1; i <=2; i++)
  {   
    printf(" %d ",MatriksB[i]);
  }
  printf("|\n|");
  for (i = 3; i <=4; i++)
  {   
    printf(" %d ",MatriksB[i]);
  }
  printf("|\n");
  for (i = 1; i <= 4; i++)
  {
    MatriksHasil[i]=MatriksA[i]-MatriksB[i];
  }
  printf("\nHasil dari pengurangan matriks adalah :\n");
  printf("\n|");
  for (i = 1; i <=2; i++)
  {   
    printf(" %d ",MatriksHasil[i]);
  }
  printf("|\n|");
  for (i = 3; i <=4; i++)
  {   
    printf(" %d ",MatriksHasil[i]);
  }
  printf("|\n");
}
return 0;
