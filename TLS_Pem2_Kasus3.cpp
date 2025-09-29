#include <iostream>
using namespace std;

int main () {
    int t;
    int cycle = 103;
    cout << "Selamat Datang di Program : Menentukan Warna Lampu APILL pada Detik ke-(t)" << endl;
    cout << "Silahkan Masukan selang waktu = " << endl;
    cin >> t;
    int x = (t - 25) % cycle;


    if (x <= 19){
        cout << "Lampu APILL berwarna Hijau" << endl;

    }

    else if (x >= 20 && x<= 22){
        cout << "Lampu APILL berwarna Kuning " << endl;
    }

    else {
        cout << "Lampu APILL berwarna Merah" << endl;
    }
    return 0;

}
