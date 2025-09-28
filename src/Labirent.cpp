#include "Labirent.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h> // للـ Sleep

Labirent::Labirent(Konum baslangic, Konum bitis) {
    FILE* fp = fopen("Harita.txt", "r");
    if (fp == nullptr) {
        std::cerr << "Could not open Harita.txt" << std::endl;
        exit(1);
    }
    unsigned char karakter = 0;
    int satir = 0, sutun = 0;
    x = baslangic.x;
    y = baslangic.y;
    this->bitis = bitis;
    yon = ASAGI;
    konumYigiti = new Stack<Konum>();
    konumYigiti->ekle(Konum(-1, -1, yon));
    while (!feof(fp)) {
        karakter = getc(fp);
        if (karakter == 255) break;
        if (karakter == 10) {
            satir++;
            sutun = 0;
        } else {
            harita[satir][sutun] = karakter;
            sutun++;
        }
    }
    fclose(fp);
}

Konum Labirent::mevcutKonum() const {
    return Konum(x, y, yon);
}

bool Labirent::adimAt(Konum mevcut, Konum ileri) {
    if (!EngelVarmi(ileri)) {
        konumYigiti->ekle(mevcut);
        ayarla(ileri, ileri.yon);
        return true;
    }
    return false;
}

void Labirent::ayarla(Konum konum, Yon yon) {
    system("cls");
    this->x = konum.x;
    this->y = konum.y;
    this->yon = yon;
    harita[konum.x][konum.y] = '-';
    std::cout << yaz();
    Sleep(30);
}

bool Labirent::CikisaGeldimi() const {
    return x == bitis.x && y == bitis.y;
}

bool Labirent::EngelVarmi(Konum konum) const {
    if (konum.x >= YUKSEKLIK || konum.x < 0 || konum.y >= GENISLIK || konum.y < 0) return false;
    return harita[konum.x][konum.y] == '#' || harita[konum.x][konum.y] == '-';
}

std::string Labirent::yaz() const {
    char YonChr[] = {31, 17, 30, 16};
    std::stringstream ss;
    for (int satir = 0; satir < YUKSEKLIK; satir++) {
        ss << std::setw(10);
        for (int sutun = 0; sutun < GENISLIK; sutun++) {
            if (satir == x && sutun == y) {
                ss << YonChr[static_cast<int>(yon)];
            } else {
                if (harita[satir][sutun] == '-') ss << ' ';
                else ss << harita[satir][sutun];
            }
        }
        ss << std::endl;
    }
    return ss.str();
}
