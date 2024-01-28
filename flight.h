#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <iostream>
#define firstP(L) L.firstP
#define firstR(L) L.firstR
#define firstC(L) L.firstC
#define lastP(L) L.lastP
#define lastC(L) L.lastC
#define next(P) P->next
#define prevP(P) P->prevP
#define prevC(P) P->prevC
#define info(P) P->info
#define infoP(P) P->infoP
#define infoC(P) P->infoC
#define nextP(P) P->nextP
#define nextC(P) P->nextC
#define nextR(P) P->nextR
#define prevP(P) P->prevP
#define prevC(P) P->prevC
#define up(P) P->up
#define down(P) P->down
using namespace std;

struct penerbangan {
    string asal, tujuan, tanggal;
    int hargaTiket;
};

struct dataDiri {
    string nama, tanggal, asal, tujuan, nik;
    int saldo;
};

typedef dataDiri infotypeParrents;
typedef penerbangan infotypeChild;
typedef struct elementParrent *adrP;
typedef struct elementChild *adrC;
typedef struct elementRelasi *adrR;

//list Parrent
struct elementParrent {
    adrP prevP;
    infotypeParrents infoP;
    adrP nextP;
};
struct parrents {
    adrP  firstP;
    adrP lastP;
};

//list child
struct elementChild {
    adrC prevC;
    infotypeChild infoC;
    adrC nextC;
};
struct child {
    adrC  firstC;
    adrC lastC;
};

//list relasi
struct elementRelasi {
    adrR nextR;
    adrP up;
    adrC down;
};

struct relasi {
    adrR  firstR;
};

//Buat list Parrent Child Relasi
void CreatelistParent(parrents &LP);
void CreatelistChild(child &LC);
void CreatelistRelasi(relasi &LR);

//Buat elemen Parrent Child Relasi
adrP newParent(infotypeParrents dataPenumpang);
adrC newChild(infotypeChild dataPenerbangan);
adrR newRelasi();

//insert 3 list
void insertParent(parrents &LP, adrP newP);
void insertChild(child &LC, adrC newC);
void insertRelasi(relasi &LR, adrR newR);

//delete 3 list
void deleteChild(child &LC, string dari, string ke);
void deleteParent(parrents &LP, string dari, string ke);
void deleteRelasi(parrents &LP, adrP newP);

//find data child & parrents
adrC findDataChild(child LC, string dari, string ke, string tanggal);
adrP findDataParrent(parrents LP, string nama, string asal, string tujuan);

//show per list
void showDataParrent(parrents &LP);
void showDataChild(child &LC);
void showDataChildToParrent(child &LC, parrents &LP);

//count data yang berelasi
int countDataParrentToChild(child LC, relasi LR, parrents LP);


void editRelasi(relasi &LR, parrents &LP, child &LC, string namaPenumpang, string tujuanPenerbangan, int jenisEdit);
int hitungPenumpangTanpaPenerbangan(parrents LP, relasi LR);
int hitungPenerbanganTanpaPenumpang(child LC, relasi LR);
int hitungJumlahPenumpang(child LC, parrents LP, relasi LR, string tanggalPenerbangan);
void hitungJumlahPenerbanganDariPenumpang(parrents LP, relasi LR, string namaPenumpang);
void tampilkanPenerbanganDariPenumpang(parrents LP, child LC, relasi LR, string namaPenumpang);
void showDataChildToParrent(child &LC, parrents &LP, relasi &LR, string tujuanPenerbangan);
void tampilkanPenumpangDanPenerbangan(parrents LP, child LC, relasi LR);
void tampilkanPenerbanganDanPenumpang(parrents LP, child LC, relasi LR);
void cekRelasiPenumpangPenerbangan(parrents LP, child LC, relasi LR, string namaPenumpang, string tujuanPenerbangan);
void hapusElemenRelasi(relasi &LR, parrents LP, child LC, string namaPenumpang, string tujuanPenerbangan);
void deleteChild(child &LC, string dari, string ke);
void beliTiketPenerbangan(parrents &LP, child &LC, relasi &LR, string namaPenumpang, string asalPenerbangan, string tujuanPenerbangan, string tanggalPenerbangan, int hargaTiket);
int menu();

#endif // FLIGHT_H_INCLUDED
