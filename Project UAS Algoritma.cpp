#include <iostream>

using namespace std;

struct Pasien {
    string nama;
    int umur;
    string penyakit;
    string idPasien;
    bool sudahBayar;
    double biaya;
};

void tampilkanMenu() {
    cout << "==================================================" << endl;
    cout << "       Selamat Datang di Rumah Sakit ICIKIWIR       " << endl;
    cout << "==================================================" << endl;
    cout << "1. Registrasi Pasien Baru" << endl;
    cout << "2. Tampilkan Daftar Pasien" << endl;
    cout << "3. Cari Pasien Berdasarkan Nama" << endl;
    cout << "4. Administrasi dan Pembayaran" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pick you'r choice: ";
}

string buatIDPasien(int urutan) {
    return "RS" + to_string(urutan + 1);
}

void registrasiPasien(Pasien pasien[], int &jumlahPasien) {
    cout << "Masukkan nama pasien: ";
    cin.ignore();
    getline(cin, pasien[jumlahPasien].nama);
    cout << "Masukkan umur pasien: ";
    cin >> pasien[jumlahPasien].umur;
    cout << "Masukkan penyakit pasien: ";
    cin.ignore();
    getline(cin, pasien[jumlahPasien].penyakit);

    pasien[jumlahPasien].idPasien = buatIDPasien(jumlahPasien);

    pasien[jumlahPasien].biaya = ((rand() % 110) * 1000)+ 50000;
    pasien[jumlahPasien].sudahBayar = false;

    cout << "Registrasi berhasil! ID Pasien: " << pasien[jumlahPasien].idPasien << endl;
    cout << "Biaya yang harus dibayar: Rp " << pasien[jumlahPasien].biaya << endl;

    jumlahPasien++;
}

void tampilkanPasien(const Pasien pasien[], int jumlahPasien) {
    if (jumlahPasien == 0) {
        cout << "Belum ada pasien yang terdaftar.\n";
    } else {
        for (int i = 0; i < jumlahPasien; i++) {
            cout << "Pasien ke-" << i + 1 << ":" << endl;
            cout << "Nama: " << pasien[i].nama << endl;
            cout << "ID Pasien: " << pasien[i].idPasien << endl;
            cout << "Umur: " << pasien[i].umur << endl;
            cout << "Penyakit: " << pasien[i].penyakit << endl;
            cout << "Biaya: Rp " << pasien[i].biaya << endl;
            cout << "Status Pembayaran: " << (pasien[i].sudahBayar ? "Sudah dibayar" : "Belum dibayar") << endl;
            cout << "---------------------------\n";
        }
    }
}

void cariPasien(const Pasien pasien[], int jumlahPasien) {
    string namaDicari;
    cout << "Masukkan nama pasien yang dicari: ";
    cin.ignore();
    getline(cin, namaDicari);

    bool ditemukan = false;
    for (int i = 0; i < jumlahPasien; i++) {
        if (pasien[i].nama == namaDicari) {
            cout << "Pasien ditemukan!" << endl;
            cout << "Nama: " << pasien[i].nama << endl;
            cout << "ID Pasien: " << pasien[i].idPasien << endl;
            cout << "Umur: " << pasien[i].umur << endl;
            cout << "Penyakit: " << pasien[i].penyakit << endl;
            cout << "Biaya: Rp " << pasien[i].biaya << endl;
            cout << "Status Pembayaran: " << (pasien[i].sudahBayar ? "Sudah dibayar" : "Belum dibayar") << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Pasien dengan nama " << namaDicari << " tidak ditemukan.\n";
    }
}

void administrasiPembayaran(Pasien pasien[], int jumlahPasien) {
    string idDicari;
    cout << "Masukkan ID Pasien: ";
    cin.ignore();
    getline(cin, idDicari);

    bool ditemukan = false;
    for (int i = 0; i < jumlahPasien; i++) {
        if (pasien[i].idPasien == idDicari) {
            cout << "Pasien ditemukan!" << endl;
            cout << "Nama: " << pasien[i].nama << endl;
            cout << "Biaya: Rp " << pasien[i].biaya << endl;
            if (pasien[i].sudahBayar) {
                cout << "Pasien sudah melakukan pembayaran.\n";
            } else {
                double pembayaran;
                cout << "Masukkan jumlah pembayaran: Rp ";
                cin >> pembayaran;

                if (pembayaran >= pasien[i].biaya) {
                    pasien[i].sudahBayar = true;
                    cout << "Pembayaran berhasil. Kembalian: Rp " << pembayaran - pasien[i].biaya << endl;
                } else {
                    cout << "Pembayaran gagal. Jumlah tidak mencukupi.\n";
                }
            }
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Pasien dengan ID " << idDicari << " tidak ditemukan.\n";
    }
}

int main() {
    const int MAX_PASIEN = 100;
    Pasien pasien[MAX_PASIEN];
    int jumlahPasien = 0;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        if (pilihan == 1) {
            if (jumlahPasien < MAX_PASIEN) {
                registrasiPasien(pasien, jumlahPasien);
            } else {
                cout << "Kapasitas pasien penuh.\n";
            }
        } else if (pilihan == 2) {
            tampilkanPasien(pasien, jumlahPasien);
        } else if (pilihan == 3) {
            cariPasien(pasien, jumlahPasien);
        } else if (pilihan == 4) {
            administrasiPembayaran(pasien, jumlahPasien);
        } else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan program ini!\n";
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }

        cout << endl;
    } while (pilihan != 5);

    return 0;
}
