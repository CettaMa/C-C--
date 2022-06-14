#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,j;

void reguler() {
    system("cls");
    puts("\t\t\t\t\t================================");
    puts ("\t\t\t\t\tMENU TIKET  REGULER");
    puts("\t\t\t\t\t================================");

	char name[10][8], Tname[10][8], temp[8];
	int N , hargatiket,total,uang2;
	printf("Masukkan Banyak Tiket dan Nama untuk masing-masing tiket:");
	scanf("%d", &N);
	printf("Masukkan %d Nama\n", N);
	for (i=0; i< N ; i++) {
		scanf("%s",name[i]);
		strcpy (Tname[i], name[i]);
	}
	for (i=0; i < N-1 ; i++) {//bubble short
		for (j=i+1; j< N; j++) {
			if(strcmp(name[i],name[j]) > 0) {
				strcpy(temp,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}
		}
	}
	printf("\n----------------------------------------\n");
	printf("Nama\tUrutan dari A-B\tdan List nama\n");
	printf("------------------------------------------\n");
	for (i=0; i< N ; i++) {
		printf("%s\t\t%s\n",Tname[i], name[i]);
	}
	printf("------------------------------------------\n");
	 total=N*10000;
    printf("\n");
    printf("\n");
    printf("\n");
	printf("----------------Uang yang Harus dimasukkan----------------\n");
	printf("Uang minimal yang harus anda masukkan adalah RP %d: \n" , total);

	printf("Masukkan jumlah uang :");
    scanf("%d",uang2);
    if(uang2>total){
        printf("Silahkan Ambil Kembalian Anda ");
        printf("PRESS ENTER TO CONTINUE");fclose(data);getchar();system("cls");s_reguler();
    }
    if(uang2=total){
        printf("Uang Anda Pas ");
        printf("PRESS ENTER TO CONTINUE");fclose(data);getchar();system("cls");s_reguler();
    }
    else if(uang2<total){
        printf("Uang anda Kurang , silahkan kembali ke menu utama");
        printf("PRESS ENTER TO CONTINUE");fclose(data);getchar();system("cls");main();
    }



	fclose(data);
	printf ("Data diterima\n");
}

int main(){
    regular();
}