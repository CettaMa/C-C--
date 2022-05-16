#include <iostream>
#include <ncurses.h>
#include <string.h>
#include <windows.h>

using namespace std;
struct node {
    int npm;
    char nama[40], ttl[35], jeniskelamin[2], jurusan[25], alamat[30];
    node *next;
 } *head;
 //node *awal_ptr=NULL;
 node *posisi;
 int pil, nmr;
 //funsi tools
 COORD coord= {0,0};
 void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
 void CariData(int nmr)
{
    bool ketemu=false;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->npm == nmr){
            ketemu = true;
            system("cls");
            cout<<"DATA BERHASIL DITEMUKAN"<<endl;
            cout<<"NPM\t\t\t            : "<<temp->npm<<"  ";
            cout<<"NAMA\t\t\t           : "<<temp->nama<<"  ";
            cout<<"TEMPAT TANGGAL LAHIR : "<<temp->ttl<<"  ";
            cout<<"JENIS KELAMIN\t      : "<<temp->jeniskelamin<<"  ";
            cout<<"JURUSAN\t\t\t        : "<<temp->jurusan<<"  ";
            cout<<"ALAMAT\t\t\t         : "<<temp->alamat<<"  ";
            cout<<"\nTEKAN ENTER UNTUK MELANJUTKAN PROSES";
            getch();
        }
    temp=temp->next;
    }
    if(ketemu == false)
    {
        system("cls");
        cout<<"MAAF DATA DENGAN NPM "<<nmr<<" TIDAK DI TEMUKAN\nTEKAN ENTER UNTUK MELANJUTKAN PROSES";
        getch();
    }
}
void inputDataMhs(int nmr)
 {
    struct node *temp;
    cout << "Masukkan Nama                  : ";   cin >> temp->nama;
    cout << "Masukkan Tempat/Tanggal-lahir  : ";   cin >> temp->ttl;
    cout << "Masukkan Jenis Kelamin         : ";   cin >> temp->jeniskelamin;
    cout << "Masukkan Jurusan               : ";   cin >> temp->jurusan;
    cout << "Masukkan Alamat                : ";   cin >> temp->alamat;
    temp->npm=nmr;
}
void cetak_tengah(int brs, char *teks)
{
    gotoxy(40-strlen(teks)/2,brs);cout<<teks;
}

int count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
    n=n->next;
    c++;
    }
    return c;
}

bool cekData(int nmr)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->npm == nmr)
            return false;
        else
            return true;
    temp=temp->next;
    }
    return true;
}

 //Fugnsi Tambah data
 void tambah(int nmr )
{
    struct node *temp;
    temp = new node;
    inputDataMhs(nmr);
    if (head== NULL)
    {
        head=temp;
        head->next=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void tambah_tengah_list(int nmr, int posisi_sisip)
 {
     node *temp, *bantu;
     bantu=head;
     temp =new node;
     for(int i=1;i<posisi_sisip-1;i++)
     {
        if(bantu->next != NULL)
            bantu=bantu->next;
        else
            break;
     }
    cout << "Masukkan NPM                    : ";   cin >> temp->npm;
    cout << "Masukkan Nama                   : ";   cin >> temp->nama;
    cout << "Masukkan Tempat Tanggal Lahir   : ";   cin >> temp->ttl;
    cout << "Masukkan Jenis Kelamin          : ";   cin >> temp->jeniskelamin;
    cout << "Masukkan Jurusan                : ";   cin >> temp->jurusan;
    cout << "Masukkan Alamat                 : ";   cin >> temp->alamat;
    temp->npm=nmr;
    temp->next=bantu->next;
    bantu->next=temp;
}
void tambah_simpul_awal(int nmr)
{
  node *temp;
  temp = new node;
  inputDataMhs(nmr);
  temp->next = NULL;

  temp->next = head;
  head = temp;

}
void tambah_simpul_akhir(int nmr)
 {
    node *temp, *temp2;
    temp=new node;
    inputDataMhs(nmr);
    temp->next=NULL;

    temp2=head;
     while(temp2->next != NULL)
       {
          temp2 = temp2->next;
       }
       temp2->next=temp;
 }
void InputData(int nmr)
{
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        tambah(nmr);
        system("cls");
        cout<<"DATA BERHASIL DISIMPAN.\nTEKAN ENTER UNTUK MELANJUTKAN";
        getch();
    }
    else
    {
        if(cekData(nmr) == false)
        {
            system("cls");
            cout<<"NPM sudah pernah di inputkan";
            getch();
        }
        else
        {
            while(temp!=NULL)
            {
                if(temp->npm<nmr)
                   c++;
                temp=temp->next;
            }
            if(c==0)
                tambah_simpul_awal(nmr);
            else if(c<count())
            {
                tambah_tengah_list(nmr,++c);
            }
            else
            {
                tambah_simpul_akhir(nmr);
            }
            system("cls");
            cout<<"DATA BERHASIL DISIMPAN.\nTEKAN ENTER UNTUK MELANJUTKAN";
            getch();
        }
    }
}
//akhir fungsi tambah data

 //fungsi hapus data
 int Hapus(int npm)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->npm==npm)
        {
            if(temp==head)
            {
                head=temp->next;
                return 1;
            }
            else
            {
                prev->next=temp->next;
                return 1;
            }
        }
        else
        {
            prev=temp;
            temp= temp->next;
        }
    }
    return 0;
}
//akhir fungsi hapus data

//fungsi tampil data
 void tampil_senarai()
 {
    node *temp;
    temp = head;
    if(temp == NULL)
       cout<<"List kosong"<<endl;
    else
    {
        int i=1;
        cout<<endl;
        cetak_tengah(1,"DATA BERAT BADAN MAHASISWA MENURUT RUMUS  BODY MASS INDEX");
        cout<<"\n=====================================================================";
        gotoxy(2,4);cout<<"No.";
        gotoxy(7,4);cout<<"NPM";
        gotoxy(11,4);cout<<"NAMA";
        gotoxy(36,4);cout<<"TEMPAT TANGGAL LAHIR";
        gotoxy(66,4);cout<<"JENIS KELAMIN"<<endl;
        gotoxy(82,4);cout<<"JURUSAN"<<endl;
        gotoxy(102,4);cout<<"ALAMAT"<<endl;
        cout<<"====================================================================="<<endl;
       while(temp != NULL)
       {
        gotoxy(2,i+5);cout<<i;
        gotoxy(7,i+5);cout<<temp->npm;
        gotoxy(11,i+5);cout<<temp->nama;
        gotoxy(36,i+5);cout<<temp->ttl;
        gotoxy(66,i+5);cout<<temp->jeniskelamin;
        gotoxy(82,i+5);cout<<temp->jurusan;
        gotoxy(102,i+5);cout<<temp->alamat;
        temp=temp->next;
        i++;
       }
       cout<<"\n\n====================================================================="<<endl;
    }
}
//akhir fungsi tampil

//fungsi edit data
void EditData(int nmr)
{
    bool ketemu=false;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->npm == nmr){
            ketemu = true;
            system("cls");
            cout<<"EDIT DATA BERIKUT INI"<<endl;
            cout<<"NPM                  : "<<temp->npm<<"  "<<endl;
            cout<<"NAMA                 : "<<temp->nama<<"  "<<endl;
            cout<<"TEMPAT/TANGGAL LAHIR : "<<temp->ttl<<"  "<<endl;
            cout<<"JENIS KELAMIN        : "<<temp->jeniskelamin<<" "<<endl;
            cout<<"JURUSAN              : "<<temp->jurusan<<" "<<endl;
            cout<<"ALAMAT               : "<<temp->alamat<<" "<<endl<<endl;
            cout<<"PROSES EDIT DATA"<<endl;
            cout<<"NAMA                : ";cin>>temp->nama;
            cout<<"TEMPAT/TANGAL LAHIR : ";cin>>temp->ttl;
            cout<<"JENIS KELAMIN       : ";cin>>temp->jeniskelamin;
            cout<<"JURUSAN             : ";cin>>temp->jurusan;
            cout<<"ALAMAT              : ";cin>>temp->alamat;
            system("cls");
            cout<<"DATA BERHASIL DI EDIT.\nTEKAN ENTER UNTUK MELANJUTKAN";
            getch();
        }
    temp=temp->next;
    }
    if(ketemu == false)
    {
        system("cls");
        cout<<"MAAF DATA DENGAN NIM  "<<nmr<<" TIDAK DI TEMUKAN\nTEKAN ENTER UNTUK MELANJUTKAN"<<endl;
        getch();
    }
}
//akhir fungsi editdata
int main()
{
    head=NULL;
    do
    {
      system("cls");
      tampil_senarai();
      cout<<endl<<endl<<"======================"<<endl;
      cout<<"Menu Pilihan"<<endl;
      cout<<"1. Input"<<endl;
      cout<<"2. Cari"<<endl;
      cout<<"3. Hapus"<<endl;
      cout<<"4. Edit"<<endl;
      cout<<"5. Urutkan"<<endl;
     cout<<"6. Exit"<<endl;
      cout<<"Pilihan >> ";cin>>pil;
      if(pil==1){
          cout<<"Masukkan NPM      : ";
          cin>>nmr;
          InputData(nmr);
      }
      else if(pil==2){
          cout<<"Masukkan NPM      : ";
          cin>>nmr;
          CariData(nmr);
      }
      else if(pil==3){
          cout<<"Masukkan NPM      : ";
          cin>>nmr;
          if(Hapus(nmr)){
              system("cls");
              cout<<"DATA BERHASIL DIHAPUS.\nTEKAN ENTER UNTUK MELANJUTKAN PROSES";
              getch();
              }
          else{
              system("cls");
              cout<<"DATA GAGAL DIHAPUS.\nTEKAN ENTER UNTUK MELANJUTKAN PROSES";
              getch();
              }
      }
      else if(pil==4){
          cout<<"Masukkan NPM      : ";
          cin>>nmr;
          EditData(nmr);
      }
      else{
            cout<<"Pilihan yang anda masukkan salah, \ntekan enter untuk melanjutkan ";
      }
    }
  while(pil!=6);
}