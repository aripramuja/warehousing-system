#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
/// Laporan max
void laporan_pendingin();
void laporan_kimia();
void laporan_lemari();
void menuLaporan();
/// DATA BARANG
void DataDingin();
void DataLemari ();
void DataChemist ();
void menu_DataBarang ();

///DATA TRANSAKSI PENDINGNIN
void penerimaan_AreaDingin();
void pengeluaran_AreaDingin();
void menuPendingin();
int Penghitung_SisaPendingin(int capacity);
void Laporan_AreaDingin();
string pembuat_kode(string tanggalmasuk,string kodelokasi);
void menuPendingin()
{
int a;
    cout<<"\n\n\t\t\t\t\t\t<==================>";
    cout<<"\n\n\t\t\t\t\t\t   1. Data keluar";
    cout<<"\n\n\t\t\t\t\t\t   2. Data masuk";
    cout<<"\n\n\t\t\t\t\t\t<==================>\n";
    cout<<"\t\t\t\t\t\t\t>>>";cin >> a;
   switch (a){
   case 1: pengeluaran_AreaDingin();break;
   case 2: penerimaan_AreaDingin();break;
   }
   menuPendingin();

}

void pengeluaran_AreaDingin()
{
int kuotaDingin=500;
ifstream keluarDingin;
   int Jum_bar[100];
   int i=0,jum;
   string Nam_bar[100];
   string kirim;
    keluarDingin.open("Area_pendingin.txt");
    while (!keluarDingin.eof()){
        keluarDingin >> Nam_bar[i];
        keluarDingin >> Jum_bar[i];

        i++;

    }
    ifstream Code;
    string TAnggal[1000];
    int q=0;
    Code.open("dinginkode.txt");
    while(!Code.eof()){
        Code>>TAnggal[q];
        q++;
    }


     cout << "================Data Barang================\n";
     cout <<"| No | Nama Barang |Kode Barang| Jumlah Barang |\n";
     for (int j=0;j<i-1;j++){
        cout <<"  "<<j+1<<".    "<< Nam_bar[j]<<"           "<<TAnggal[j]<< "          "<<Jum_bar[j]<<endl;

     }
     cout << "================>>>>><<<<<=================\n";
     cout << "Nama Barang yang ingin dikirim   : " ;cin >> kirim;
     int temu;
     bool tampung=false;
     for (int g=0;g<i-1;g++){
        if (kirim == Nam_bar[g]){
                tampung=true;
                temu = g;
        }else{
                cout <<"";
        }
     }

     if (tampung==true){
        cout << "Jumlah Barang yang ingin dikirim : " ;cin >> jum;
        if(Jum_bar[temu]>=jum)
            {
                 Jum_bar[temu]=Jum_bar[temu]-jum;
                 cout<<Jum_bar[temu];
            }
                else
                {
                    cout << "jumlah barang tidak cukup"<<endl;
                }
        }
        else
            {
                cout << "================================"<<endl;
                cout << "        Barang tidak ada!!!";
                cout << "\n================================\n"<<endl;
                system("pause");
                system("cls");
                menuPendingin();
            }
            ofstream Updatedingin;
            Updatedingin.open("Area_pendingin.txt");
            for (int j=0;j<i-1;j++){
                Updatedingin<<Nam_bar[j]<<"       "<<Jum_bar[j]<<endl;
             }
      system("cls");
     string tanya;
     cout << "================================"<<endl;
     cout << "|Do you want to see the update?|"<<endl;
     cout << "================================"<<endl;
     cout << "         |Y|     |N|        "<<endl;
     cin >> tanya;

     if (tanya=="Y"){

        cout << "-----------Update Barang------------"<<endl;
        cout <<"| No | Nama Barang |Kode Barang| Jumlah Barang |\n";
             for (int j=0;j<i-1;j++){
                cout <<"  "<<j+1<<".    "<< Nam_bar[j]<<"   "<<TAnggal[j]<< "          "<<Jum_bar[j]<<endl;

             }
             cout << "Kapasitas area pendingin yang kosong adalah "<<Penghitung_SisaPendingin(kuotaDingin)<<" dari "<<kuotaDingin<<endl;
     }else
        {
            system("cls");
            menuPendingin();

        }

    system("pause");
    system("cls");
    keluarDingin.close();
    Code.close();
}

void penerimaan_AreaDingin()
{
    ofstream dingin;
   int jumlah_Barang,diminta;
   string Nama_Barang,Tanggal[1000];
   dingin.open("Area_pendingin.txt",ios::app);
   cout << "Berapa jenis barang : " ;cin>> diminta;
  for (int i=0;i<diminta;i++){
        cout << "---- Barang ke - "<<i+1<< "----\n";
            cout << "Nama Barang : " ;cin>>Nama_Barang;
            cout << "Jumlah Barang : "; cin>>jumlah_Barang;
            cout << "Tanggal dan Bulan Transaksi(tanggal,bulan) : "; cin>>Tanggal[i];
        dingin << Nama_Barang<< "       ";
        dingin <<jumlah_Barang<<endl;
    }
   dingin.close();
   ofstream dinginKode;
   dinginKode.open("dinginkode.txt",ios::app);
   for (int j=0;j<diminta;j++){
        dinginKode<<pembuat_kode(Tanggal[j],"AP")<<endl;
   }

   dinginKode.close();
   system("pause");
   system("cls");
}

int Penghitung_SisaPendingin(int capacity)
{
    ifstream rekareh;
    string apa;
    int jumlahBarang[1000];
    int Total_barang=0;
    int sisa;
    rekareh.open("Area_pendingin.txt");
    int i=0;
    while (!rekareh.eof()){
        rekareh >> apa;
        rekareh >> jumlahBarang[i];
        i++;
    }

    for (int j=0;j<i-1;j++){
        Total_barang=Total_barang+jumlahBarang[j];
    }

    sisa=capacity-Total_barang;
    return sisa;
    rekareh.close();
}

string pembuat_kode(string tanggalmasuk,string kodelokasi)
{
    string gabung;
    gabung=kodelokasi+tanggalmasuk;
    return gabung;
}
///DATA TRANSAKSI KIMIA
void penerimaan_AreaKimia();
void pengeluaran_AreaKimia();
void menuKimia();
int Penghitung_SisaKimia(int capacity);
void Laporan_AreaKimia();
string pembuat_kode(string tanggalmasuk,string kodelokasi);

///DATA LEMARI
void penerimaan_AreaLemari();
void pengeluaran_AreaLemari();
void menuLemari();
int Penghitung_SisaLemari(int capacity);
void Laporan_AreaLemari();

///LAPORAN
struct dataBarang
{
    string Nambar;
    int JumBar;
};


void judul(){
    cout<<"\n\n\n\n\n\n";
    cout<<"\t\t\t\t________________________________________________________"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\tWelcome to our system (SISTEM PERGUDANGAN)"<<endl;
    cout<<"\t\t\t\t________________________________________________________"<<endl;
}
void menu_utama()
{
    int menu;
    cout<<"\n\n";
    cout<<"\t\tMAIN MENU"<<endl;
    cout<<"\t\t=========";
    cout<<"\n\n\t\t1. Data Barang";
    cout<<"\n\n\t\t2. Data Transaksi";
    cout<<"\n\n\t\t3. Laporan";
    cout<<"\n\n\t\t4. Lokasi penyimpanan";
    cout<<"\n\n\n";
    cout<<"masukan nomor : ";
}
void barang()
{
        cout<<"\n\n\t1. Data Penyimpanan";
        cout<<"\n\n\t2. Data barang";
//        cout<<"\n\n\t3. UPDATE";
        cout<<endl;
        int menu_barang;
        cin>>menu_barang;


        switch (menu_barang)
        {
        case 1:
            {
            string nama_barang,jenis_barang,lokasi_barang;
            ofstream penyimpanan_barang;
            penyimpanan_barang.open("barang.txt",ios::app);
            cout<<"masukan nama barang: ";
            cin>>nama_barang;
            penyimpanan_barang<<nama_barang+"\n";
            cout<<"masukan jenis barang: ";
            cin>>jenis_barang;
            penyimpanan_barang<<jenis_barang+"\n";
            cout<<"lokasi barang: ";
            cin>>lokasi_barang;
            penyimpanan_barang<<lokasi_barang+"\n";
            penyimpanan_barang.close();
            break;
        }

        case 2:
            {
            char data_barang [1000];
            fstream penyimpanan_barang;
            penyimpanan_barang.open("barang.txt");
            int counter = 0;
       //     cout<<"Nama |"<<"Jenis |"<<"Lokasi |\n";
            while (!penyimpanan_barang.eof())
            {
                if(counter!=3){
                penyimpanan_barang.getline(data_barang,1000);
                cout<<data_barang<<""<< " ";    //"|";
                counter++;
                }else{
                counter = 0;
                cout<<endl;
                }
            }
            penyimpanan_barang.close();
            break;
        }
        }
}
void transaksi()
{
        cout<<"\n\n\t1. Area pendingin";
        cout<<"\n\n\t2. Rak dan lemari";
        cout<<"\n\n\t3. Area kimia";
        cout<<"\n\n\t4. kembali";
        cout<<"\n\n\n\t Masukan pilihan : ";
}
void laporan()
{
        cout<<"\n\n\t1. Barang terbanyak";

}
void lokasipenyimpanan()
{
        cout<<"\n\n\t1. Area pendingin";
        cout<<"\n\n\t2. Rak dan lemari";
        cout<<"\n\n\t3. Area bahan kimia";

}
int main()
{
    string nama, nim;
    int menu;
    int menu_trans;
    int menu_bar;
    judul();
    cout<<"\n\n";
    cout<<"\t\t\t\t\tName : ";
    cin>>nama;
    cout<<"\t\t\t\t\tNim  : ";
    cin>>nim;
//
//    if (nama!="ari" && nim!="105218000")
//    {
//        system("cls");
//        judul();
//        cout<<"\n\n";
//        cout<<"\t\t\t\t\tName : ";
//        cin>>nama;
//        cout<<"\t\t\t\t\tNim  : ";
//        cin>>nim;
//    }
//
//    system("cls");

    menu_utama();
    cin>>menu;

    if (menu==1)
    {
        system("cls");
        menu_DataBarang();
        system("pause");
        system("cls");
       // main();
    }
    if (menu==2)
    {
        system("cls");
        transaksi();
        cin>>menu_trans;
        if(menu_trans==4)
        {
            system("cls");
            menu_utama();
            cin>>menu;
        }
        if (menu_trans==1)
        {
            system("cls");
            menuPendingin();
        }
        if (menu_trans==3)
        {
            system("cls");
            menuKimia();
        }
        if (menu_trans==2)
        {
            system("cls");
            menuLemari();
        }
        system("pause");
        system("cls");
       // main();

    }
    if (menu==3)
    {
        system("cls");
            menuLaporan();
            system("pause");
        system("cls");
       // main();
    }


    if (menu==4)
    {
        system("cls");
        lokasipenyimpanan();

        cout<<endl<<"\n\n";
        cout << "cek kapasitaas tersisa:\n";
        cout<<"masukan pilihan: ";
        cin>>menu;
        switch(menu)
        {
        case 1:
            cout << "Sisa ruang yang dapat diisi : "<<Penghitung_SisaPendingin(500)<<endl;break;
        case 2:
            cout << "Sisa ruang yang dapat diisi : "<<Penghitung_SisaLemari(500)<<endl;break;
        case 3:
            cout << "Sisa ruang yang dapat diisi : "<<Penghitung_SisaKimia(500)<<endl;break;
        default : cout <<"\n";

        }
        system("pause");
        system("cls");
      //  main();
    }
}
///DATA BARANG
void DataDingin()
{
    ifstream dataDingin;
    int SumBarang[100];
    int i=0,sum;
    string NameBarang[100];
    string send;
    dataDingin.open("Data_pendingin.txt");
        while (!dataDingin.eof()){
            dataDingin >> NameBarang[i];
            dataDingin >> SumBarang[i];
            i++;
        }
    ifstream dataKodeDingin;
    string gal[1000];
    int gr=0;
    dataKodeDingin.open("DataKodeDingin.txt");
    while (!dataKodeDingin.eof()){
            dataKodeDingin >> gal[gr];
            gr++;
        }
     cout << "==================Data Barang==================\n";
      cout <<"| No | Nama Barang |Kode Barang| Jumlah Barang |\n";
     for (int j=0;j<-1;j++){
        cout <<"  "<<j+1<<".    "<< NameBarang[j] <<"           "<<gal[j]<< "          "<<SumBarang[j]<<endl;

     }
     cout << "==================>>>>><<<<<===================\n";
     dataDingin.close();
     dataKodeDingin.close();
}
void DataLemari ()
{
    ifstream dataLemari;
    int SumBarang[100];
    int i=0,sum;
    string NameBarang[100];
    string send;
    dataLemari.open("Data_lemari.txt");
        while (!dataLemari.eof()){
            dataLemari >> NameBarang[i];
            dataLemari >> SumBarang[i];
            i++;
        }
    ifstream dataKodeLemari;
    string gal[1000];
    int gr=0;
    dataKodeLemari.open("DataKodeLemari.txt");
    while (!dataKodeLemari.eof()){
            dataKodeLemari >> gal[gr];
            gr++;
        }
     cout << "==================Data Barang==================\n";
      cout <<"| No | Nama Barang |Kode Barang| Jumlah Barang |\n";
     for (int j=0;j<i-1;j++){
        cout <<"  "<<j+1<<".    "<< NameBarang[j] <<"           "<<gal[j]<< "          "<<SumBarang[j]<<endl;

     }
     cout << "==================>>>>><<<<<===================\n";
     dataLemari.close();
     dataKodeLemari.close();

}
void DataChemist ()
{
    ifstream dataChemist;
    int SumBarang[100];
    int i=0,sum;
    string NameBarang[100];
    string send;
    dataChemist.open("Data_chemist.txt");
        while (!dataChemist.eof()){
            dataChemist >> NameBarang[i];
            dataChemist >> SumBarang[i];
            i++;
        }
    ifstream dataKodeChemist;
    string gal[1000];
    int gr=0;
    dataKodeChemist.open("DataKodeChemist.txt");
    while (!dataKodeChemist.eof()){
            dataKodeChemist >> gal[gr];
            gr++;
        }
     cout << "==================Data Barang==================\n";
      cout <<"| No | Nama Barang |Kode Barang| Jumlah Barang |\n";
     for (int j=0;j<i-1;j++){
        cout <<"  "<<j+1<<".    "<< NameBarang[j] <<"           "<<gal[j]<< "          "<<SumBarang[j]<<endl;

     }
     cout << "==================>>>>><<<<<===================\n";
     dataChemist.close();
     dataKodeChemist.close();

}
void menu_DataBarang ()
{
    int kitaSemua;
    cout << "============================================================= \n";
    cout << "Berikut Adalah Lokasi Penyimpanan Barang Yang Ada : \n";
    cout << "1. Data Area Lemari dan Rak \n";
    cout << "2. Data Area Kimia \n";
    cout << "3. Data Area Pendingin \n";
    cout << "_____________________________________________________________ \n";
    cout << "Silahkan Pilih Lokasi Yang Ingin Anda Cek Terlebih Dahulu : ";
    cin >> kitaSemua;
    cout << "_____________________________________________________________ \n";
    switch (kitaSemua)
    {
        case 1 : DataLemari();break;
        case 2 : DataChemist();break;
        case 3 : DataDingin();break;
        default : menu_DataBarang();
    }
}

///DATA KIMIA

void menuKimia()
{
int a;
    cout<<"\n\n\t\t\t\t\t\t<==================>";
    cout<<"\n\n\t\t\t\t\t\t   1. Data keluar";
    cout<<"\n\n\t\t\t\t\t\t   2. Data masuk";
    cout<<"\n\n\t\t\t\t\t\t<==================>\n";
    cout<<"\t\t\t\t\t\t\t>>>";cin >> a;
   switch (a){
   case 1: pengeluaran_AreaKimia();break;
   case 2: penerimaan_AreaKimia();break;
   default : main();
   }
   main();

}

void pengeluaran_AreaKimia()
{
int kuotaDingin=500;
ifstream keluarDingin;
   int Jum_bar[100];
   int i=0,jum;
   string Nam_bar[100];
   string kirim;
    keluarDingin.open("Data_chemist.txt");
    while (!keluarDingin.eof()){
        keluarDingin >> Nam_bar[i];
        keluarDingin >> Jum_bar[i];

        i++;

    }
    ifstream Code;
    string TAnggal[1000];
    int q=0;
    Code.open("DataKodechemist.txt");
    while(!Code.eof()){
        Code>>TAnggal[q];
        q++;
    }


     cout << "================Data Barang================\n";
     cout <<"| No | Nama Barang |Kode Barang| Jumlah Barang |\n";
     for (int j=0;j<i-1;j++){
        cout <<"  "<<j+1<<".    "<< Nam_bar[j]<<"           "<<TAnggal[j]<< "          "<<Jum_bar[j]<<endl;

     }
     cout << "================>>>>><<<<<=================\n";
     cout << "Nama Barang yang ingin dikirim   : " ;cin >> kirim;
     int temu;
     bool tampung=false;
     for (int g=0;g<i-1;g++){
        if (kirim == Nam_bar[g]){
                tampung=true;
                temu = g;
        }else{
                cout <<"";
        }
     }

     if (tampung==true){
        cout << "Jumlah Barang yang ingin dikirim : " ;cin >> jum;
        if(Jum_bar[temu]>=jum)
            {
                 Jum_bar[temu]=Jum_bar[temu]-jum;
            }
                else
                {
                    cout << "jumlah barang tidak cukup"<<endl;
                }
        }
        else
            {
                cout << "================================"<<endl;
                cout << "        Barang tidak ada!!!";
                cout << "\n================================\n"<<endl;
                system("pause");
                system("cls");
                menuKimia();
            }
            ofstream Updatedingin;
            Updatedingin.open("Data_chemist.txt");
            for (int j=0;j<i-1;j++){
                Updatedingin<<Nam_bar[j]<<"       "<<Jum_bar[j]<<endl;
             }
      system("cls");
     string tanya;
     cout << "================================"<<endl;
     cout << "|Do you want to see the update?|"<<endl;
     cout << "================================"<<endl;
     cout << "         |Y|     |N|        "<<endl;
     cin >> tanya;

     if (tanya=="Y"){

        cout << "-----------Update Barang------------"<<endl;
        cout <<"| No | Nama Barang |Kode Barang| Jumlah Barang |\n";
             for (int j=0;j<i-1;j++){
                cout <<"  "<<j+1<<".    "<< Nam_bar[j]<<"   "<<TAnggal[j]<< "          "<<Jum_bar[j]<<endl;

             }
             cout << "Kapasitas area pendingin yang kosong adalah "<<Penghitung_SisaKimia(kuotaDingin)<<" dari "<<kuotaDingin<<endl;
     }else
        {
            system("cls");
            main();

        }

    system("pause");
    system("cls");
    keluarDingin.close();
    Code.close();
}

void penerimaan_AreaKimia()
{
    ofstream dingin;
   int jumlah_Barang,diminta;
   string Nama_Barang,Tanggal[1000];
   dingin.open("Data_chemist.txt",ios::app);
   cout << "Berapa jenis barang : " ;cin>> diminta;
  for (int i=0;i<diminta;i++){
        cout << "---- Barang ke - "<<i+1<< "----\n";
            cout << "Nama Barang : " ;cin>>Nama_Barang;
            cout << "Jumlah Barang : "; cin>>jumlah_Barang;
            cout << "Tanggal dan Bulan Transaksi(tanggal,bulan) : "; cin>>Tanggal[i];
        dingin << Nama_Barang<< "       ";
        dingin <<jumlah_Barang<<endl;
    }
   dingin.close();
   ofstream dinginKode;
   dinginKode.open("DataKodechemist.txt",ios::app);
   for (int j=0;j<diminta;j++){
        dinginKode<<pembuat_kode(Tanggal[j],"AK")<<endl;
   }

   dinginKode.close();
   system("pause");
   system("cls");
}

int Penghitung_SisaKimia(int capacity)
{
    ifstream rekareh;
    string apa;
    int jumlahBarang[1000];
    int Total_barang=0;
    int sisa;
    rekareh.open("Data_chemist.txt");
    int i=0;
    while (!rekareh.eof()){
        rekareh >> apa;
        rekareh >> jumlahBarang[i];
        i++;
    }

    for (int j=0;j<i-1;j++){
        Total_barang=Total_barang+jumlahBarang[j];
    }

    sisa=capacity-Total_barang;
    return sisa;
    rekareh.close();
}

///DATA LEMARI
void menuLemari()
{
int a;
    cout<<"\n\n\t\t\t\t\t\t<==================>";
    cout<<"\n\n\t\t\t\t\t\t   1. Data keluar";
    cout<<"\n\n\t\t\t\t\t\t   2. Data masuk";
    cout<<"\n\n\t\t\t\t\t\t<==================>\n";
    cout<<"\t\t\t\t\t\t\t>>>";cin >> a;
   switch (a){
   case 1: pengeluaran_AreaLemari();break;
   case 2: penerimaan_AreaLemari();break;
   default : main();
   }
   main();

}

void pengeluaran_AreaLemari()
{
int kuotaDingin=500;
ifstream keluarDingin;
   int Jum_bar[100];
   int i=0,jum;
   string Nam_bar[100];
   string kirim;
    keluarDingin.open("Data_lemari.txt");
    while (!keluarDingin.eof()){
        keluarDingin >> Nam_bar[i];
        keluarDingin >> Jum_bar[i];

        i++;

    }
    ifstream Code;
    string TAnggal[1000];
    int q=0;
    Code.open("DataKodelemari.txt");
    while(!Code.eof()){
        Code>>TAnggal[q];
        q++;
    }


     cout << "================Data Barang================\n";
     cout <<"| No | Nama Barang |Kode Barang| Jumlah Barang |\n";
     for (int j=0;j<i-1;j++){
        cout <<"  "<<j+1<<".    "<< Nam_bar[j]<<"           "<<TAnggal[j]<< "          "<<Jum_bar[j]<<endl;

     }
     cout << "================>>>>><<<<<=================\n";
     cout << "Nama Barang yang ingin dikirim   : " ;cin >> kirim;
     int temu;
     bool tampung=false;
     for (int g=0;g<i-1;g++){
        if (kirim == Nam_bar[g]){
                tampung=true;
                temu = g;
        }else{
                cout <<"";
        }
     }

     if (tampung==true){
        cout << "Jumlah Barang yang ingin dikirim : " ;cin >> jum;
        if(Jum_bar[temu]>=jum)
            {
                 Jum_bar[temu]=Jum_bar[temu]-jum;
            }
                else
                {
                    cout << "jumlah barang tidak cukup"<<endl;
                }
        }
        else
            {
                cout << "================================"<<endl;
                cout << "        Barang tidak ada!!!";
                cout << "\n================================\n"<<endl;
                system("pause");
                system("cls");
                menuLemari();
            }
            ofstream Updatedingin;
            Updatedingin.open("Data_lemari.txt");
            for (int j=0;j<i-1;j++){
                Updatedingin<<Nam_bar[j]<<"       "<<Jum_bar[j]<<endl;
             }
      system("cls");
     string tanya;
     cout << "================================"<<endl;
     cout << "|Do you want to see the update?|"<<endl;
     cout << "================================"<<endl;
     cout << "         |Y|     |N|        "<<endl;
     cin >> tanya;

     if (tanya=="Y"){

        cout << "-----------Update Barang------------"<<endl;
        cout <<"| No | Nama Barang |Kode Barang| Jumlah Barang |\n";
             for (int j=0;j<i-1;j++){
                cout <<"  "<<j+1<<".    "<< Nam_bar[j]<<"   "<<TAnggal[j]<< "          "<<Jum_bar[j]<<endl;

             }
             cout << "Kapasitas area pendingin yang kosong adalah "<<Penghitung_SisaLemari(kuotaDingin)<<" dari "<<kuotaDingin<<endl;
     }else
        {
            system("cls");
            main();

        }

    system("pause");
    system("cls");
    keluarDingin.close();
    Code.close();
}

void penerimaan_AreaLemari()
{
    ofstream dingin;
   int jumlah_Barang,diminta;
   string Nama_Barang,Tanggal[1000];
   dingin.open("Data_lemari.txt",ios::app);
   cout << "Berapa jenis barang : " ;cin>> diminta;
  for (int i=0;i<diminta;i++){
        cout << "---- Barang ke - "<<i+1<< "----\n";
            cout << "Nama Barang : " ;cin>>Nama_Barang;
            cout << "Jumlah Barang : "; cin>>jumlah_Barang;
            cout << "Tanggal dan Bulan Transaksi(tanggal,bulan) : "; cin>>Tanggal[i];
        dingin << Nama_Barang<< "       ";
        dingin <<jumlah_Barang<<endl;
    }
   dingin.close();
   ofstream dinginKode;
   dinginKode.open("DataKodelemari.txt",ios::app);
   for (int j=0;j<diminta;j++){
        dinginKode<<pembuat_kode(Tanggal[j],"AL")<<endl;
   }

   dinginKode.close();
   system("pause");
   system("cls");
}

int Penghitung_SisaLemari(int capacity)
{
    ifstream rekareh;
    string apa;
    int jumlahBarang[1000];
    int Total_barang=0;
    int sisa;
    rekareh.open("Data_lemari.txt");
    int i=0;
    while (!rekareh.eof()){
        rekareh >> apa;
        rekareh >> jumlahBarang[i];
        i++;
    }

    for (int j=0;j<i-1;j++){
        Total_barang=Total_barang+jumlahBarang[j];
    }

    sisa=capacity-Total_barang;
    return sisa;
    rekareh.close();
    rekareh.open("Data_chemist.txt");

    while (!rekareh.eof()){
        rekareh >> apa;
        rekareh >> jumlahBarang[i];
        i++;
    }

    for (int j=0;j<i-1;j++){
        Total_barang=Total_barang+jumlahBarang[j];
    }

    sisa=capacity-Total_barang;
    return sisa;
    rekareh.close();
}

void laporan_kimia(){
    dataBarang DB[1000];
    ifstream maximum;
    int maxi,ngulang=0,index;
    maximum.open("Data_chemist.txt");

    while(!maximum.eof()){
        maximum>>DB[ngulang].Nambar;
        maximum>>DB[ngulang].JumBar;
        ngulang++;
    }
    maxi=0;
    for(int a=0;a<ngulang-1;a++){

        if(DB[a].JumBar>=maxi){
            maxi=DB[a].JumBar;
            index=a;
        }
    }
    cout << "Barang Terbanyaknya adalah "<<DB[index].Nambar<< " Sebanyak " << maxi<<" Item " <<endl;

    maximum.close();

}

void laporan_pendingin(){
    dataBarang DB[1000];
    ifstream maximum;
    int maxi,ngulang=0,index;
    maximum.open("Data_pendingin.txt");

    while(!maximum.eof()){
        maximum>>DB[ngulang].Nambar;
        maximum>>DB[ngulang].JumBar;
        ngulang++;
    }
    maxi=0;
    for(int a=0;a<ngulang-1;a++){

        if(DB[a].JumBar>=maxi){
            maxi=DB[a].JumBar;
            index=a;
        }
    }
    cout << "Barang Terbanyaknya adalah "<<DB[index].Nambar<< " Sebanyak " << maxi<<" Item " <<endl;

    maximum.close();
}

void laporan_lemari(){
    dataBarang DB[1000];
    ifstream maximum;
    int maxi,ngulang=0,index;
    maximum.open("Data_lemari.txt");

    while(!maximum.eof()){
        maximum>>DB[ngulang].Nambar;
        maximum>>DB[ngulang].JumBar;
        ngulang++;
    }
    maxi=0;
    for(int a=0;a<ngulang-1;a++){

        if(DB[a].JumBar>=maxi){
            maxi=DB[a].JumBar;
            index=a;
        }
    }
    cout << "Barang Terbanyaknya adalah "<<DB[index].Nambar<< " Sebanyak " << maxi<<" Item " <<endl;

    maximum.close();

}

void menuLaporan(){
    int w;
    cout <<"================================\n";
    cout <<"Pilih lokasi barang terbanyak\n";
    cout << "================================\n";
    cout << "1. Area kimia\n";
    cout << "2. Area pendingin\n";
    cout << "3. Area lemari\n";
    cout << "==================\n";
    cin >>w;
    switch(w){
    case 1:
        laporan_kimia();break;
    case 2:
        laporan_pendingin();break;
    case 3:
        laporan_lemari();break;
    default: menuLaporan();
    }
}
