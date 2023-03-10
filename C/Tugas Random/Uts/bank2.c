#include <stdio.h> //mengganti stdin menjadi stdio
#include <stdlib.h>
#include <string.h>

int CekSaldo()
{
    FILE *fp;
    int saldo=0;
    fp = fopen("saldo.txt", "r");// mengubah mode pembuka file
    if (fp == NULL)
    {
        fclose(fp);
        fp = fopen("saldo.txt", "w");// mengubah mode pembuka file
        fprintf(fp, "%d", saldo);
    }
    else
    {
        fscanf(fp,"%d",&saldo); 
        printf("hey");
    }
    fclose(fp);

    return saldo; // mengganti true menjadi saldo
}

int TambahSaldo(int uang)
{
    FILE *fp;
    int saldo;
    
    saldo = CekSaldo();
    saldo = saldo + uang;
    
    fp = fopen("saldo.txt", "w");
    fprintf(fp, "%d", saldo);
    fclose(fp);

    return saldo;
}

int KurangSaldo(int uang)
{
    FILE *fp; //menambahkan *
    int saldo;

    saldo = CekSaldo();

    if (saldo >= uang) //mengganti = > menjadi > =
    {
        saldo = saldo - uang;
    }
    else
    {
        return -1;
    }

    fp = fopen("saldo.txt", "w");
    fprintf(fp, "%d", saldo);
    fclose(fp);

    return saldo;
}

void MainMenu()
{
    int pilih;
    int saldo, uang;
    printf("====== Bank SEA ======\n");
    printf("1. Setor Tunai\n");
    printf("2. Tarik Tunai\n");
    printf("3. Info Saldo\n");
    printf("4. Keluar\n\n");
    printf("Pilih : ");
    scanf("%d", &pilih);

    switch (pilih)
    {
        case 1 : {
            system("cls");
            uang=0;
            printf("====== Bank SEA ======\n");
            printf("Jumlah Uang : Rp.");
            scanf("%d", &uang);
            saldo = TambahSaldo(uang);
            printf("Saldo Anda = Rp.%d\n", saldo);
            system("pause");
            system("cls");
            MainMenu();
        }

        case 2 : {
            system("cls");
            printf("====== Bank SEA ======\n");
            printf("Jumlah Uang : Rp.");
            scanf("%d", &uang);
            saldo = KurangSaldo(uang);
            if (saldo >= 0)
            {
                printf("Saldo Anda = Rp.%d\n", saldo);
            }
            else
            {
                printf("Saldo Anda Tidak Cukup!!!\n");
            }
            system("pause");
            system("cls");
            MainMenu();
            break;
        }

        case 3 : {
            system("cls");
            printf("====== Bank SEA ======\n");
            saldo = CekSaldo();
            printf("Saldo Anda = Rp.%d\n", saldo);
            system("pause");
            system("cls");
            MainMenu();
            break;
        }

        case 4 : {
            system("cls");
            printf("Terimaksih\n");
            system("pause");
            exit(0);
            break;
        }

        default : {
            printf("Pilihan Tidak Ada!!!\n");
            break;
        }
    }
}

int main()
{
    char username[10], password[10]; //menggunaka format deklarasi string yang benar
    printf("====== Bank SEA ======\n");
    printf("username : ");
    fgets(username,10,stdin);//mengganti scanf menjadi fgets ((kata pak burhan))
    strtok(username,"\n");
    printf("password : ");
    fgets(password,10,stdin);//mengganti scanf menjadi fgets ((kata pak burhan))
    strtok(password,"\n");
    printf("%s %s",password,username);
    if ((strcmp(username,"ilham")==0) && (strcmp(password,"123")==0)) //mengganti == menjadi strcmp untuk membandingkan string
    {
        system("cls");
        MainMenu();
    } else {
        printf("Akun tidak terdaftar!!!\n");
        system("pause");
        system("cls");
        main();
    }
}