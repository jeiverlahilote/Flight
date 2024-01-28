#include <iostream>
#include "flight.h"
using namespace std;

// MEMBUAT LIST
void CreatelistParent(parrents &LP){
    firstP(LP) = NULL;
    lastP(LP) = NULL;
}

void CreatelistChild(child &LC){
    firstC(LC) = NULL;
    lastC(LC) = NULL;
}

void CreatelistRelasi(relasi &LR){
    firstR(LR) = NULL;
}

// MEMBUAT ELEMEN
adrP newParent(infotypeParrents dataPenumpang){
    adrP newp = new elementParrent;
    infoP(newp).nama = dataPenumpang.nama;
    infoP(newp).nik = dataPenumpang.nik;
    infoP(newp).asal = dataPenumpang.asal;
    infoP(newp).tujuan = dataPenumpang.tujuan;
    infoP(newp).tanggal = dataPenumpang.tanggal;
    infoP(newp).saldo = dataPenumpang.saldo;
    nextP(newp) = NULL;
    prevP(newp) = NULL;
    return newp;
}

adrC newChild(infotypeChild dataPenerbangan) {
    adrC newC = new elementChild;
    infoC(newC).asal = dataPenerbangan.asal;
    infoC(newC).tujuan = dataPenerbangan.tujuan;
    infoC(newC).tanggal = dataPenerbangan.tanggal;
    infoC(newC).hargaTiket = dataPenerbangan.hargaTiket;
    nextC(newC) = NULL;
    prevC(newC) = NULL;
    return newC;
}

adrR newRelasi() {
    adrR newR = new elementRelasi;
    nextR(newR) = NULL;
    up(newR) = NULL;
    down(newR) = NULL;
    return newR;
}

//INSERT(memakai insert last)
void insertParent(parrents &LP, adrP newP) {
    if (firstP(LP) == NULL) {
        firstP(LP) = newP;
        lastP(LP) = newP;
    } else {
        prevP(newP) = lastP(LP);
        nextP(lastP(LP)) = newP;
        lastP(LP) = newP;
        nextP(lastP(LP)) = NULL;
    }
}

void insertChild(child &LC, adrC newC) {
    if (firstC(LC) == NULL) {
        firstC(LC) = newC;
        lastC(LC) = newC;
    } else {
        prevC(newC) = lastC(LC);
        nextC(lastC(LC)) = newC;
        lastC(LC) = newC;
        nextC(lastC(LC)) = NULL;
    }
}

void insertRelasi(relasi &LR, adrR newR) {
    if (firstR(LR) == NULL) {
        firstR(LR) = newR;
        nextR(firstR(LR)) = firstR(LR);
    } else {
        nextR(newR) = firstR(LR);
        adrR x = firstR(LR);
       while(nextR(x) != firstR(LR)) {
            x = nextR(x);
        }
        nextR(x) = newR;
    }
}

// SHOW DATA PARRENT & CHILD
void showDataParrent(parrents &LP) {
    cout << "===========================" << endl;
    cout << "LIST PENUMPANG" << endl;
    cout << "===========================" << endl;
    adrP x = firstP(LP);
    while (x != NULL) {
        cout << "===========================" << endl;
        cout << "Nama: " << infoP(x).nama << endl;
        cout << "Tanggal: " << infoP(x).tanggal << endl;
        cout << "Asal: " << infoP(x).asal << endl;
        cout << "Tujuan: " << infoP(x).tujuan << endl;
        cout << "===========================" << endl;
        x = nextP(x);
    }
}

void showDataChild(child &LC) {
    cout << "===========================" << endl;
    cout << "LIST PENERBANGAN" << endl;
    cout << "===========================" << endl;
    adrC x = firstC(LC);
    while (x != NULL) {
        cout << "Asal: " << infoC(x).asal << endl;
        cout << "Tujuan: " << infoC(x).tujuan << endl;
        cout << "Harga Tiket: " << infoC(x).hargaTiket << endl;
        cout << "Tanggal: " << infoC(x).tanggal << endl;
        cout << "===========================" << endl;
        x = nextC(x);
    }
}

// FIND DATA PARENT & CHILD
adrP findDataParrent(parrents LP, string nama, string asal, string tujuan) {
    adrP x = firstP(LP);
    while (x != NULL) {
        if (infoP(x).nama == nama && infoP(x).asal == asal && infoP(x).tujuan == tujuan) {
            return x;
        }
        x = nextP(x);
    }
    return NULL;  // Return NULL if not found
}

adrC findDataChild(child LC, string dari, string ke, string tanggal) {
    adrC x = firstC(LC);
    while (x != NULL) {
        if (infoC(x).asal == dari && infoC(x).tujuan == ke && infoC(x).tanggal == tanggal) {
            return x;
        }
        x = nextC(x);
    }
    return NULL;  // Return NULL if not found
}

void deleteParent(parrents &LP, string dari, string ke) {
    adrP p = firstP(LP);

    while (p != NULL && infoP(p).asal != dari && infoP(p).tujuan != ke) {
        p = nextP(p);
    }

    if (p == NULL){
        cout << "data tidak ditemukan" << endl;
        return;
    }

    if (p == firstP(LP) && p == lastP(LP)) {

        firstP(LP) = NULL;
        lastP(LP) = NULL;
    } else if (p == firstP(LP)) {

        firstP(LP) = nextP(p);
        prevP(nextP(p)) = NULL;
    } else if (p == lastP(LP)) {

        lastP(LP) = prevP(p);
        nextP(prevP(p)) = NULL;
    } else {

        nextP(prevP(p)) = nextP(p);
        prevP(nextP(p)) = prevP(p);
    }

    delete p;
}

void deleteChild(child &LC, string dari, string ke) {
    adrC c = firstC(LC);
    while (c != NULL && infoC(c).asal!= dari && infoC(c).tujuan !=ke) {
        c = nextC(c);
    }
    if (c == NULL) {
        cout << "data tidak ditemukan" << endl;
        return;
    }
    if (c == firstC(LC) && c == lastC(LC)) {
        firstC(LC) = NULL;
        lastC(LC) = NULL;
    } else if (c == firstC(LC)) {
        firstC(LC) = nextC(c);
        prevC(nextC(c)) = NULL;
    } else if (c == lastC(LC)) {
        lastC(LC) = prevC(c);
        nextC(prevC(c)) = NULL;
    } else {
        nextC(prevC(c)) = nextC(c);
        prevC(nextC(c)) = prevC(c);
    }
    delete c;
}

void hapusElemenRelasi(relasi &LR, parrents LP, child LC, string namaPenumpang, string tujuanPenerbangan) {
    // Mencari penumpang dan penerbangan
    adrP P = firstP(LP);
    while (P != NULL && infoP(P).nama != namaPenumpang) {
        P = nextP(P);
    }

    adrC C = firstC(LC);
    while (C != NULL && infoC(C).tujuan != tujuanPenerbangan) {
        C = nextC(C);
    }

    if (P == NULL || C == NULL) {
        cout << "Penumpang atau penerbangan tidak ditemukan." << endl;
        return;
    }

    // Mencari dan menghapus relasi
    adrR R = firstR(LR), prevR = NULL;
    bool found = false;
    while (R != NULL) {
        if (up(R) == P && down(R) == C) {
            found = true;
            if (prevR == NULL) {
                firstR(LR) = nextR(R);
            } else {
                nextR(prevR) = nextR(R);
            }
            delete R;
            break;
        }
        prevR = R;
        R = nextR(R);
    }

    if (!found) {
        cout << "Relasi antara penumpang dan penerbangan tidak ditemukan." << endl;
    } else {
        cout << "Relasi berhasil dihapus." << endl;
    }
}

void cekRelasiPenumpangPenerbangan(parrents LP, child LC, relasi LR, string namaPenumpang, string tujuanPenerbangan) {
    // Mencari penumpang
    adrP P = firstP(LP);
    while (P != NULL && infoP(P).nama != namaPenumpang) {
        P = nextP(P);
    }

    // Mencari penerbangan
    adrC C = firstC(LC);
    while (C != NULL && infoC(C).tujuan != tujuanPenerbangan) {
        C = nextC(C);
    }

    // Jika penumpang dan penerbangan ditemukan
    if (P != NULL && C != NULL) {
        // Mencari relasi
        adrR R = firstR(LR);
        while (R != NULL) {
            if (up(R) == P && down(R) == C) {
                cout << "Penumpang " << namaPenumpang << " memiliki relasi dengan penerbangan ke " << tujuanPenerbangan << "." << endl;
                return;
            }
            R = nextR(R);
        }
        cout << "Penumpang " << namaPenumpang << " tidak memiliki relasi dengan penerbangan ke " << tujuanPenerbangan << "." << endl;
    } else {
        cout << "Penumpang atau penerbangan tidak ditemukan." << endl;
    }
}

void tampilkanPenerbanganDanPenumpang(parrents LP, child LC, relasi LR) {
    cout << "=======================================" << endl;
    cout << "DATA PENERBANGAN DAN PENUMPANG" << endl;
    cout << "=======================================" << endl;

    adrC penerbangan = firstC(LC);
    while (penerbangan != NULL) {
        cout << "Penerbangan dari " << infoC(penerbangan).asal << " ke " << infoC(penerbangan).tujuan << " pada tanggal " << infoC(penerbangan).tanggal << endl;
        cout << "Daftar Penumpang:" << endl;

        // Mencari penumpang yang terkait dengan penerbangan ini
        adrR relasi = firstR(LR);
        bool adaPenumpang = false;

        while (nextR(relasi) != firstR(LR)){
            if (down(relasi) == penerbangan) {
                // Penumpang ditemukan, tampilkan informasinya
                adrP penumpang = up(relasi);
                cout << "- " << infoP(penumpang).nama << " dari " << infoP(penumpang).asal << " ke " << infoP(penumpang).tujuan << endl;
                adaPenumpang = true;
            }
            relasi = nextR(relasi);
        }

        if (!adaPenumpang) {
            cout << "- Tidak ada penumpang untuk penerbangan ini." << endl;
        }

        cout << "=======================================" << endl;

        penerbangan = nextC(penerbangan);
    }
}

void beliTiketPenerbangan(parrents &LP, child &LC, relasi &LR, string namaPenumpang, string asalPenerbangan, string tujuanPenerbangan, string tanggalPenerbangan, int hargaTiket) {
    // Mencari penumpang
    adrP penumpang = findDataParrent(LP, namaPenumpang, asalPenerbangan, tujuanPenerbangan);
    if (penumpang == NULL) {
        cout << "Penumpang tidak ditemukan." << endl;
        return;
    }
    //cout << "TESTER 1" << endl;
    // Mencari penerbangan
    adrC penerbangan = findDataChild(LC, asalPenerbangan, tujuanPenerbangan, tanggalPenerbangan);
    if (penerbangan == NULL) {
        cout << "Penerbangan tidak ditemukan." << endl;
        return;
    }
    //cout << "TESTER 2" << endl;
    // Cek apakah penumpang sudah memiliki relasi dengan penerbangan
    adrR relasi = firstR(LR);

    if (relasi != NULL) {
        do {
            if (up(relasi) == penumpang && down(relasi) == penerbangan) {
                cout << "Penumpang sudah memiliki tiket untuk penerbangan ini." << endl;
                return;
            }
            relasi = nextR(relasi);
            //cout << "TESTER 3" << endl;
        } while (nextR(relasi) != firstR(LR));

        // Buat relasi baru
        adrR newrelasi = newRelasi();
        up(newrelasi) = penumpang;
        down(newrelasi) = penerbangan;
        //cout << "TESTER 4" << endl;
        // Masukkan relasi ke dalam list relasi
        insertRelasi(LR, newrelasi);
        //cout << "TESTER 5" << endl;
        // Kurangi saldo penumpang sesuai harga tiket
        infoP(penumpang).saldo -= hargaTiket;
    } else {
        adrR newrelasi = newRelasi();
        up(newrelasi) = penumpang;
        down(newrelasi) = penerbangan;
        //cout << "TESTER 4" << endl;
        // Masukkan relasi ke dalam list relasi
        insertRelasi(LR, newrelasi);
    }

    cout << "Pembelian tiket berhasil.\n" << endl;
}

void tampilkanPenumpangDanPenerbangan(parrents LP, child LC, relasi LR) {
    cout << "============================================" << endl;
    cout << "DATA PENUMPANG DAN PENERBANGAN YANG DIPILIH" << endl;
    cout << "============================================" << endl;
    // Menelusuri semua penumpang
    adrP P = firstP(LP);
    while (P != NULL) {
        cout << "Penumpang: " << infoP(P).nama << endl;
        cout << "Penerbangan yang berelasi:" << endl;

        // Menelusuri semua relasi
        adrR R = firstR(LR);
        do {
            // Cek jika penumpang dalam relasi ini
            if (up(R) == P) {
                // Menampilkan info penerbangan yang berelasi
                adrC C = down(R);
                cout << " - Asal: " << infoC(C).asal
                     << ", Tujuan: " << infoC(C).tujuan
                     << ", Tanggal: " << infoC(C).tanggal
                     << ", Harga Tiket: " << infoC(C).hargaTiket << endl;
            }
            R = nextR(R);
        }while (R != firstR(LR));

        P = nextP(P);
        cout << endl;
    }
}

void showDataChildToParrent(child &LC, parrents &LP, relasi &LR, string tujuanPenerbangan) {

    adrC C = firstC(LC);
    while (C != NULL) {
        if (infoC(C).tujuan == tujuanPenerbangan) {

            cout << "Penumopang dengan tujuan penerbangan : " << tujuanPenerbangan << ":" << endl;

            adrR R = firstR(LR);
            while (R != NULL) {
                if (down(R) == C) {
                    adrP P = up(R);
                    cout << "Nama: " << infoP(P).nama << ", tanggal: " << infoP(P).tanggal
                         << ", Asal: " << infoP(P).asal << ", tujuan: " << infoP(P).tujuan
                         << ", Saldo: " << infoP(P).saldo << endl;
                }
                R = nextR(R);
            }
            break;
        }
        C = nextC(C);
    }
    if (C == NULL) {
        cout << "tidak ditemukan " << tujuanPenerbangan << endl;
    }
}

void tampilkanPenerbanganDariPenumpang(parrents LP, child LC, relasi LR, string namaPenumpang) {
    // Mencari penumpang
    adrP P = firstP(LP);
    while (P != NULL) {

        if (P == NULL) {
            cout << "Penumpang " << namaPenumpang << " tidak ditemukan." << endl;
            return;
        }

        if (infoP(P).nama == namaPenumpang) {

            cout << "Data Penerbangan untuk Penumpang " << namaPenumpang << ":" << endl;

            // Menelusuri relasi untuk menemukan semua penerbangan yang berelasi dengan penumpang
            adrR R = firstR(LR);
            bool found = false;
            do {
                if (up(R) == P) {
                    adrC C = down(R);
                    cout << " - Asal: " << infoC(C).asal
                         << ", Tujuan: " << infoC(C).tujuan
                         << ", Tanggal: " << infoC(C).tanggal
                         << ", Harga Tiket: " << infoC(C).hargaTiket << endl;
                    found = true;
                }
                R = nextR(R);
            }while (R != firstR(LR));

            if (!found) {
                cout << "Tidak ada data penerbangan yang berelasi dengan penumpang ini." << endl;
            }
        }
        P = nextP(P);
    }
}

void hitungJumlahPenerbanganDariPenumpang(parrents LP, relasi LR, string namaPenumpang) {
    // Mencari penumpang
    adrP P = firstP(LP);
    int jumlahPenerbangan = 0;
    while (P != NULL){

        if (P == NULL) {
            cout << "Penumpang " << namaPenumpang << " tidak ditemukan." << endl;
            return;
        }
        if (infoP(P).nama == namaPenumpang){

            // Menghitung jumlah penerbangan yang berelasi dengan penumpang
            adrR R = firstR(LR);
            do {
                if (up(R) == P) {
                    jumlahPenerbangan++;
                }
                R = nextR(R);
            }while (R != firstR(LR));
        }
        P = nextP(P);
    }

    cout << "Jumlah penerbangan untuk penumpang " << namaPenumpang << ": " << jumlahPenerbangan << endl;
}

int hitungJumlahPenumpang(child LC, parrents LP, relasi LR, string tanggalPenerbangan) {
    int jumlahPenumpang = 0;

    // Menelusuri list penerbangan untuk mencari penerbangan pada tanggal tertentu
    adrC C = firstC(LC);
    while (C != NULL) {
        if (infoC(C).tanggal == tanggalPenerbangan) {
            // Penerbangan ditemukan, sekarang cari semua penumpang yang terkait dengan penerbangan ini
            adrR R = firstR(LR);
           do {
                // Cek jika pointer 'down' dari relasi mengarah ke penerbangan kita
                if (down(R) == C) {
                    // Terdapat kecocokan, tambahkan ke jumlah penumpang
                    jumlahPenumpang++;
                }
                R = nextR(R);
            }  while (R != firstR(LR));
            break;
        }
        C = nextC(C);
    }

    if (C == NULL) {
        cout << "Tidak ada penerbangan yang ditemukan pada tanggal " << tanggalPenerbangan << endl;
    }

    return jumlahPenumpang;
}

int hitungPenerbanganTanpaPenumpang(child LC, relasi LR) {
    int jumlahPenerbanganTanpaPenumpang = 0;

    // Menelusuri semua penerbangan
    //adrC C = firstC(LC);
    //while (C != NULL) {

        // Menelusuri semua relasi untuk mengecek apakah penerbangan ini memiliki penumpang
        adrR R = firstR(LR);
        do {
            if (down(R) != NULL && up(R) == NULL) {
                jumlahPenerbanganTanpaPenumpang++;
            }else {
            R = nextR(R);
            }
        }while (R != firstR(LR));
       // C = nextC(C);
   // }
    return jumlahPenerbanganTanpaPenumpang;
}

int hitungPenumpangTanpaPenerbangan(parrents LP, relasi LR) {
    int jumlahPenumpangTanpaPenerbangan = 0;

    // Menelusuri semua penumpang
    adrP P = firstP(LP);
    while (P != NULL) {

        // Menelusuri semua relasi untuk mengecek apakah penumpang ini memiliki penerbangan
        adrR R = firstR(LR);
        do {
            if (up(R) == P && down(R) == NULL) {
                jumlahPenumpangTanpaPenerbangan++;
            }
            R = nextR(R);
        }while (R != firstR(LR));
        P = nextP(P);
    }

    return jumlahPenumpangTanpaPenerbangan;
}

void editRelasi(relasi &LR, parrents &LP, child &LC, string namaPenumpang, string tujuanPenerbangan, int jenisEdit) {
    // Mencari penumpang
    adrP P = firstP(LP);
    while (P != NULL && infoP(P).nama != namaPenumpang) {
        P = nextP(P);
    }

    // Mencari penerbangan
    adrC C = firstC(LC);
    while (C != NULL && infoC(C).tujuan != tujuanPenerbangan) {
        C = nextC(C);
    }

    if (P == NULL || C == NULL) {
        cout << "Penumpang atau penerbangan tidak ditemukan." << endl;
        return;
    }

    // Mengedit relasi
    bool relasiDitemukan = false;
    adrR R = firstR(LR);
    while (R != NULL) {
        if (jenisEdit == 1 && up(R) == P) {
            down(R) = C; // Mengganti penerbangan untuk penumpang ini
            relasiDitemukan = true;
            break;
        } else if (jenisEdit == 0 && down(R) == C) {
            up(R) = P; // Mengganti penumpang untuk penerbangan ini
            relasiDitemukan = true;
            break;
        }
        R = nextR(R);
        if (R == firstR(LR)) break; // Jika list relasi siklik, hindari loop tak terbatas
    }

    if (!relasiDitemukan) {
        cout << "Relasi yang sesuai tidak ditemukan." << endl;
    } else {
        cout << "Relasi berhasil diedit." << endl;
    }
}

int  menu(){
    cout << "===========================================================" << endl;
    cout << "   1.     MENAMBAHKAN PENERBANGAN" << endl;
    cout << "   2.     MEMBELI TIKET PENERBANGAN" << endl;
    cout << "   3.     HAPUS DATA PENERBANGAN" << endl;
    cout << "   4.     HAPUS DATA PENUMPANG" << endl;
    cout << "   5.     SHOW DATA PENUMPANG DAN PENERBANGAN YANG DI PILIH" << endl;
    cout << "   6.     SHOW DATA PENERBANGAN" << endl;
    cout << "   7.     SHOW DATA PENUMPANG" << endl;
    cout << "   8.     SHOW DATA PENERBANGAN BERDASARAKAN PENUMPANG" << endl;
    cout << "   9.     TOTAL PENERBANGAN DARI PENUMPANG" << endl;
    cout << "   10.    TOTAL PENERBANGAN TANPA PENUMPANG" << endl;
    cout << "   11.    EDIT RELASI" << endl;
    cout << "   0.     KELUAR" << endl;
    cout << "===========================================================    " << endl;
    int x;
    cin >> x;
    return x;
}
