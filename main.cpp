#include <iostream>
#include "flight.h"
using namespace std;

int main()
{
    cout << "Selamat datang di app penerbangan" << endl;

    parrents LP;
    child LC;
    relasi LR;
    CreatelistChild(LC);
    CreatelistParent(LP);
    CreatelistRelasi(LR);
    int x;
    do {
        x = menu();

        switch (x) {
            case 1: {
                int p;
                cout << "\n Mau input berapa penerbangan? " << endl;
                cin >> p;
                infotypeChild q;
                for (int i = 0; i < p; i++) {
                    cout << "==================" << endl;
                    cout << "ASAL: ";
                    cin >> q.asal;
                    cout << "TUJUAN: ";
                    cin >> q.tujuan;
                    cout << "TANGGAL: ";
                    cin >> q.tanggal;
                    cout << "HARGA: ";
                    cin >> q.hargaTiket;
                    insertChild(LC, newChild(q));
                }
                cout << "\n===============================" << endl;
                cout << "Penerbangan berhasil ditambahkan" << endl;
                cout << "=================================\n" << endl;

                break;
            }
            case 2: {
                cout << "==========================================" << endl;
                cout << "Masukkan identitas Anda untuk penerbangan" << endl;
                cout << "==========================================" << endl;
                infotypeParrents q;
                cout << "NAMA: ";
                cin >> q.nama;
                cout << "NIK: ";
                cin >> q.nik;
                cout << "ASAL: ";
                cin >> q.asal;
                cout << "TUJUAN: ";
                cin >> q.tujuan;
                cout << "TANGGAL: ";
                cin >> q.tanggal;
                cout << "SALDO ANDA: ";
                cin >> q.saldo;
                if (findDataParrent(LP, q.nama, q.asal, q.tujuan) == NULL) {
                    insertParent(LP, newParent(q));
                    beliTiketPenerbangan(LP, LC, LR, q.nama, q.asal, q.tujuan, q.tanggal, q.saldo);
                } else {
                    cout << "Penumpang sudah memiliki tiket untuk penerbangan ini" << endl;
                }
                break;
            }
            case 3: {
                string asal, tujuan;
                cout << "MASUKAN ASAL & TUJUAN PENERBANGAN YANG INGIN DIHAPUS" << endl;
                cout << "ASAL: ";
                cin >> asal;
                cout << "TUJUAN: ";
                cin >> tujuan;
                deleteChild(LC, asal, tujuan);
                cout << "Penerbangan berhasil dihapus" << endl;
                break;
            }
            case 4: {
                string asal, tujuan, nama;
                cout << "MASUKAN ASAL & TUJUAN PENUMPANG YANG INGIN DIHAPUS" << endl;
                cout << "NAMA: ";
                cin >> nama;
                cout << "ASAL: ";
                cin >> asal;
                cout << "TUJUAN: ";
                cin >> tujuan;
                deleteParent(LP, asal, tujuan);
                //hapusElemenRelasi(LR, LP, LC, nama, tujuan);
                cout << "Penumpang berhasil dihapus" << endl;
                break;
            }
            case 5: {
                tampilkanPenumpangDanPenerbangan(LP, LC, LR);
                break;
            }
            case 6: {
                showDataChild(LC);
                break;
            }
            case 7: {
                showDataParrent(LP);
                break;
            }
            case 8: {
                cout << "siapa penumpang yang ingi dicari list penerbangannya?" << endl;
                string x;
                cin >> x;
                tampilkanPenerbanganDariPenumpang(LP, LC, LR, x);
                break;
            }
            case 9: {
                string nama;
                cout << "Masukan nama penumpang yang mau di lihat jumlah penerbangannya: ";
                cin >> nama;
                hitungJumlahPenerbanganDariPenumpang(LP, LR, nama);
                break;
            }
            case 10: {
                cout << "Total Penerbangan tanpa penumpang" << endl;
                cout << "Terdapat " << hitungPenerbanganTanpaPenumpang(LC, LR) << " Penerbangan" << endl;
                break;
            }
            case 11: {
                cout << "Nama Penumpang: ";
                string nama, tujuan;
                int jenisedit;
                cin >> nama;
                cout << "Tujuan Penerbangan: ";
                cin >> tujuan;
                cout << "Ganti Penerbangan Dari Penumpang/Ganti Penumpang Dari Penerbangan. 1/0: ";
                cin >> jenisedit;
                editRelasi(LR, LP, LC, nama, tujuan, jenisedit);
                cout << "===========================" << endl;
                cout << "Edit Relasi Selesai" << endl;
                cout << "===========================" << endl;
                break;
            }
            case 0: {
                cout << "Terima kasih, program selesai." << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                break;
            }
        }
    } while (x != 0);

    return 0;
}
