    #include <stdio.h>
    #include <string.h>
    void mhsdasar()
    {
    int i,N,totalgajikar=0;
    struct data
    {
       char  namakar[40];
       int  gol,gajitetap,gajihadir,gajilembur,kehadiran;
       float gajitotal;
       
    };
       FILE *fp;    // Perhatikan bentuk deklarasinya : FILE ditambah asterik (*) dan nama variabel file
       struct data kar[5],arrkar[5];

       //membuka file baru untuk ditulis
       fp = fopen("hsdasar.txt", "w");  // Perhatikan mode untuk menulis file adalah 'w'. 'w+': menulis dan menambah.
       printf("Jumlah Karyawan ");
       scanf("%d",&N);
       // Sama dg fflush(stdin); =>Membuang karakter terakhir ( ENTER ) dr input. Untuk menghindari error dari input string

    // Pengisian data ( bukan pembacaan; untuk keperluan pengujian program saat dibuat. Agar tidak lama input data
    /*
        strcpy(mhs[0].nama,"Budi Asih");
        mhs[0].nim=111;
        mhs[0].nilai=70;

        strcpy(mhs[1].nama,"Cica K");
        mhs[1].nim=112;
        mhs[1].nilai=30;

        strcpy(mhs[2].nama,"Dudu Didu");
        mhs[2].nim=113;
        mhs[2].nilai=80;

        for (i=0;i<N;i++)
            fwrite(&mhs[i],sizeof(mhs[i]),1,fp);
        fclose(fp);
    */



      //membaca N buah data dan mencatat ke file
     for (i=0;i<N;i++)              // mengulang sebanyak N kali
       {
        
        //Untuk membaca string, gunakan fgets( var_string, panjang, stdin). Jangan gunakan gets !
        scanf("%*c");
        printf("Masukkan nama Karyawan ");
        fgets(kar[i].namakar, 40, stdin);
        

        //membuang karakter terakhir ( ENTER )
        strtok(kar[i].namakar,"\n");

        printf("Nama Karyawan %s\n",kar[i].namakar); //unt mengecek apakah data nama yang dimasukkan sama yang diketik
        printf("Golongan : ");
        scanf("%d", &kar[i].gol);
        //printf("Nim %d\n",mhs.nim);
        printf("Kehadiran : ");
        scanf("%d", &kar[i].kehadiran);

        // Menulis data ke file dalam bentuk file text
        /*
        fprintf(fp,"%s\n",mhs.nama);
        fprintf(fp,"%d\n",mhs.nim);
        fprintf(fp,"%d\n",mhs.nilai);
        */
        // Menulis data ke file dalam bentuk file sequensial
        fwrite(&kar[i],sizeof(kar[i]),1,fp);
        }  // AKHIR DARI FOR

       //Menutup file
       fclose(fp);

       //Membuka file untuk dibaca
       fp = fopen("hsdasar.txt", "r");
       // unt menghitung total data nilai

       for (i=0;i<N;i++)  //Perhatikan : i dimulai dr 1, krn dipakai dalam indeks array! Kondisi jadi : i<N
       {
        //membaca baris file dan hasilnya disimpan di array dengan nama arrmhs
        // File sequensial:
        fread(&arrkar[i],sizeof(arrkar[i]),1,fp);

        //File text:
        /*
        fgets(arrmhs[i].nama, sizeof(arrmhs[i].nama), (FILE*)fp);
        fscanf(fp, "%d\n", &arrmhs[i].nim);  // membaca data integer
        fscanf(fp, "%d\n", &arrmhs[i].nilai);  // membaca data integer
        */

        printf("Data : %s %d %d\n", arrkar[i].namakar, arrkar[i].gol, arrkar[i].kehadiran);
        }

       //MENGOLAH DATA YANG SUDAH DIMASUKKAN KE ARRAY
        //a. menentukan indeks tiap mhs
        //b. menampilkan mhs yang lulus

        //a. menentukan indeks mhs
        for (i=0;i<N;i++)   // ada N data, jadi pengulangan dilakukan N x, indeks i dimulai dari 0
        {
            arrkar[i].gajilembur=0;
          switch (arrkar[i].gol)   // Bisa juga memakai if bertingkat
          {
            case 1 :
             if (arrkar[i].kehadiran>150)
             {
                 arrkar[i].gajitetap=500000;
                 arrkar[i].gajihadir=arrkar[i].kehadiran*6000;
                 arrkar[i].gajilembur=(float)(arrkar[i].kehadiran-150)*500*1.5;
                 arrkar[i].gajitotal=arrkar[i].gajitetap+arrkar[i].gajihadir+arrkar[i].gajilembur;
             } else {
                 arrkar[i].gajitetap=500000;
                 arrkar[i].gajihadir=arrkar[i].kehadiran*6000;
                 arrkar[i].gajitotal=arrkar[i].gajitetap+arrkar[i].gajihadir+arrkar[i].gajilembur;
             }
             break;
            case 2 :
            if (arrkar[i].kehadiran>150)
             {
                 arrkar[i].gajitetap=450000;
                 arrkar[i].gajihadir=arrkar[i].kehadiran*5000;
                 arrkar[i].gajilembur=(float)(arrkar[i].kehadiran-150)*450*1.5;
                 arrkar[i].gajitotal=arrkar[i].gajitetap+arrkar[i].gajihadir+arrkar[i].gajilembur;
             } else {
                 arrkar[i].gajitetap=450000;
                 arrkar[i].gajihadir=arrkar[i].kehadiran*5000;
                 arrkar[i].gajitotal=arrkar[i].gajitetap+arrkar[i].gajihadir+arrkar[i].gajilembur;
             }
            break;
            case 3 :
            if (arrkar[i].kehadiran>150)
             {
                 arrkar[i].gajitetap=400000;
                 arrkar[i].gajihadir=arrkar[i].kehadiran*4000;
                 arrkar[i].gajilembur=(float)(arrkar[i].kehadiran-150)*400*1.5;
                 arrkar[i].gajitotal=arrkar[i].gajitetap+arrkar[i].gajihadir+arrkar[i].gajilembur;
             } else {
                 arrkar[i].gajitetap=400000;
                 arrkar[i].gajihadir=arrkar[i].kehadiran*4000;
                 arrkar[i].gajitotal=arrkar[i].gajitetap+arrkar[i].gajihadir+arrkar[i].gajilembur;
             }
            break;
            case 4 :
             if (arrkar[i].kehadiran>150)
             {
                 arrkar[i].gajitetap=350000;
                 arrkar[i].gajihadir=arrkar[i].kehadiran*3500;
                 arrkar[i].gajilembur=(float)(arrkar[i].kehadiran-150)*350*1.5;
                 arrkar[i].gajitotal=arrkar[i].gajitetap+arrkar[i].gajihadir+arrkar[i].gajilembur;
             } else {
                 arrkar[i].gajitetap=350000;
                 arrkar[i].gajihadir=arrkar[i].kehadiran*3500;
                 arrkar[i].gajitotal=arrkar[i].gajitetap+arrkar[i].gajihadir+arrkar[i].gajilembur;
             }
             break;
            case 5 :
            if (arrkar[i].kehadiran>150)
             {
                 arrkar[i].gajitetap=300000;
                 arrkar[i].gajihadir=arrkar[i].kehadiran*3000;
                 arrkar[i].gajilembur=(float)(arrkar[i].kehadiran-150)*300*1.5;
                 arrkar[i].gajitotal=arrkar[i].gajitetap+arrkar[i].gajihadir+arrkar[i].gajilembur;
             } else {
                 arrkar[i].gajitetap=300000;
                 arrkar[i].gajihadir=arrkar[i].kehadiran*3000;
                 arrkar[i].gajitotal=arrkar[i].gajitetap+arrkar[i].gajihadir+arrkar[i].gajilembur;
             }
            break;
            default : printf("Golongan salah");
          }
          totalgajikar=totalgajikar+arrkar[i].gajitotal;
          printf("%s Dengan golongan %d\nKehadiran :%d\ngaji tetap=%d\ngaji hadir=%d\ngaji lembur=%d\n",arrkar[i].namakar,arrkar[i].gol,arrkar[i].kehadiran,arrkar[i].gajitetap,arrkar[i].gajihadir,arrkar[i].gajilembur);
        }
        printf("Total gaji adalah : %d \n",totalgajikar);

        /* b. Menampiilkan yang lulus => lulus berati nilainya A,B,C atau D
        printf("Daftar mahasiswa yang lulus: \n");
        for (i=0;i<N;i++){
          if (arrmhs[i].indeks<'E' )  // Perhatikan bahwa untuk karakter, 'A'<'B'<'C'<'D'<'E'
             printf("%s dengan nim %d lulus dengan indeks %c\n",arrmhs[i].nama,arrmhs[i].nim,arrmhs[i].indeks);
        }*/

       fclose(fp);
    }

    int main(){
        mhsdasar();

        return 0;
    }