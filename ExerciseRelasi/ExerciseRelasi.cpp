#include<iostream>
#include<vector>
using namespace std;


class Pengarang;
class Penerbit;
class Buku {
public:
    string judul;
    Pengarang* pengarang;

    Buku(string pJudul, Pengarang* pPengarang) : judul(pJudul), pengarang(pPengarang) {}

    string getJudul() const {
        return judul;
    }
};

class Pengarang {
public:
    string nama;
    Penerbit* penerbit;
    vector<Buku*> daftar_buku;

    Pengarang(string pNama, Penerbit* pPenerbit) : nama(pNama), penerbit(pPenerbit) {}

    void tambahBuku(Buku* buku) {
        daftar_buku.push_back(buku);
    }

    void cetakDaftarBuku() {
        cout << "Daftar buku yang dikarang \"" << nama << "\":\n";
        for (auto& buku : daftar_buku) {
            cout << buku->getJudul() << endl;
        }
        cout << endl;
    }
};

class Penerbit {
public:
    string nama;
    vector<Pengarang*> daftar_pengarang;

    Penerbit(string pNama) : nama(pNama) {}

    void tambahPengarang(Pengarang* pengarang) {
        daftar_pengarang.push_back(pengarang);
    }

    void cetakDaftarPengarang() {
        cout << "Daftar pengarang pada penerbit \"" << nama << "\":\n";
        for (auto& pengarang : daftar_pengarang) {
            cout << pengarang->nama << endl;
        }
        cout << endl;
    }
};

int main() {
    Penerbit* gamaPress = new Penerbit("Gama Press");
    Penerbit* intanPariwara = new Penerbit("Intan Pariwara");

    Pengarang* joko = new Pengarang("Joko", gamaPress);
    Pengarang* Lia = new Pengarang("Lia", gamaPress);
    Pengarang* Giga = new Pengarang("Giga", gamaPress);
    Pengarang* Asroni = new Pengarang("Asroni", intanPariwara);
    Pengarang* Giga = new Pengarang("Giga", intanPariwara);

    Buku* buku1 = new Buku("Fisika", joko);
    Buku* buku2 = new Buku("Algoritma", joko);
    Buku* buku3 = new Buku("Basisdata", Lia);
    Buku* buku4 = new Buku("Dasar Pemrograman", Asroni);
    Buku* buku5 = new Buku("Matematika", Giga);
    Buku* buku6 = new Buku("Multimedia 1", Giga);

    joko->tambahBuku(buku1);
    joko->tambahBuku(buku2);
    Lia->tambahBuku(buku3);
    Asroni->tambahBuku(buku4);
    Giga->tambahBuku(buku5);
    Giga->tambahBuku(buku6);

    gamaPress->tambahPengarang(joko);
    gamaPress->tambahPengarang(Lia);
    gamaPress->tambahPengarang(Giga);
    intanPariwara->tambahPengarang(Asroni);
    intanPariwara->tambahPengarang(Giga);

    gamaPress->cetakDaftarPengarang();
    intanPariwara->cetakDaftarPengarang();

    cout << "daftar penerbit yang diikuti \"" << Giga->nama << "\":";
    cout << Giga->penerbit->nama << endl;
    cout << endl;

    joko->cetakDaftarBuku();
    Lia->cetakDaftarBuku();
    Giga->cetakDaftarBuku();
    Asroni->cetakDaftarBuku();

    delete buku1;
    delete buku2;
    delete buku3;
    delete buku4;
    delete buku5;
    delete buku6;
    delete joko;
    delete Lia;
    delete Asroni;
    delete Giga;
    delete gamaPress;
    delete intanPariwara;

    return 0;

}