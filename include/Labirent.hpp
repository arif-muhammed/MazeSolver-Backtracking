#ifndef LABIRENT_HPP
#define LABIRENT_HPP

#include "Konum.hpp"
#include "Stack.hpp"
#include <string>

#define YUKSEKLIK 20
#define GENISLIK 50

class Labirent {
public:
    char harita[YUKSEKLIK][GENISLIK];
    int x, y;
    Yon yon;
    Konum bitis;
    Stack<Konum> *konumYigiti;
    
    Labirent(Konum baslangic, Konum bitis);
    Konum mevcutKonum() const;
    bool adimAt(Konum mevcut, Konum ileri);
    void ayarla(Konum konum, Yon yon);
    bool CikisaGeldimi() const;
    bool EngelVarmi(Konum konum) const;
    std::string yaz() const;
};

#endif
