#include <iostream>
#include <string>

using namespace std;

bool Huruf_Vokal(char vokal){
    return ( vokal == 'a' || vokal == 'i' || vokal == 'u' || vokal == 'e' || vokal == 'o' 
          || vokal == 'A' || vokal == 'E' || vokal == 'I' || vokal == 'O' || vokal == 'U');
}

string Membalik_Urutan_Konsonan(string kata){
    string hasil = "";
    for (int i = kata.size()-1; i >= 0; i--){
        hasil += kata[i];
    }
    return hasil;
}

string Membuat_Password(string kataMasuk){ 
    string konsonan = ""; 
    for (char vokal : kataMasuk ){ 
        if (!Huruf_Vokal(vokal)) konsonan += vokal; 
    }

    string dibalik = Membalik_Urutan_Konsonan(konsonan); 

    int nilaiAscii = (int)kataMasuk[0]; 
    string ASCII = to_string(nilaiAscii); 

    int tengah = dibalik.size()/2; 
    string sandi = dibalik.substr(0, tengah) + ASCII + dibalik.substr(tengah); 
    return sandi;
}

string decode_Kata_Sandi(string sandi){
    int awal = -1, akhir = -1;
    string angka = "";


    for (int i = 0; i < sandi.size(); i++) {
        if (isdigit(sandi[i])) {
            if (awal == -1) awal = i; 
            akhir = i; 
            angka += sandi[i];
        }
    }

    int konversiAngka = stoi(angka); 
    char hurufAwal = (char)konversiAngka; 

    string tanpaAngka = sandi.substr(0, awal) + sandi.substr(akhir+1); 
    string konsonanAsli = Membalik_Urutan_Konsonan(tanpaAngka); 

    string hasil = string(1, hurufAwal) + konsonanAsli;
    return hasil;
}

int main(){
    cout << "Selamat Datang di Program : Membentuk Sebuah Kata Sandi" << endl;
    cout << "Silahkan pilih salah satu pilihan dibawah ini" << endl;
    cout << "1. Buat kata sandi \n";
    cout << "2. Decode kata sandi \n";
    cout << endl;
    
    int z;
    cin >> z;

    switch(z){
        case 1: {
            string kata;
            cout << "Masukkan sebuah kata untuk diubah menjadi sebuah kata sandi :    ";
            cin >> kata;
            string hasilSandi = Membuat_Password(kata);
            cout << "Kata: " << kata << " --> Sandi: " << hasilSandi << endl;
            break;
        }

        case 2: {
            string sandi;
            cout << "Masukkan kata sandi untuk di decode:   ";
            cin >> sandi;
            string hasilDecode = decode_Kata_Sandi(sandi);
            cout << "Sandi: " << sandi << " --> Kata asli: " << hasilDecode << endl;
            break;
        }
    }

    return 0;
}