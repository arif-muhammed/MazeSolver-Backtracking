#include "Labirent.hpp"
#include <iostream>

int main() {
    Labirent* labirent = new Labirent(Konum(0, 19), Konum(19, 6));
    
    labirent->konumYigiti->ekle(Konum(labirent->x, labirent->y, Yon::ASAGI));
    labirent->ayarla(Konum(labirent->x, labirent->y, Yon::ASAGI).Asagi(), Yon::ASAGI);
    
    while (!labirent->CikisaGeldimi()) {
        int denemeYonSayisi = 1;
        Konum oncekiKonum = labirent->konumYigiti->ust();
        Konum mevcutKonum = labirent->mevcutKonum();
        
        Konum ileri = mevcutKonum.AyniYon();
        
        if (!labirent->adimAt(mevcutKonum, ileri)) {
            int i = 0;
            bool sonuc = false;
            Konum yeni = mevcutKonum;
            while (!sonuc && denemeYonSayisi < 5) {    
                yeni = mevcutKonum.SaatYonu(static_cast<Yon>((static_cast<int>(mevcutKonum.yon) + i) % 4));        
                                
                i++;
                denemeYonSayisi++;
                if (yeni.yon == mevcutKonum.TersYon()) {
                    sonuc = false;
                } else {
                    sonuc = labirent->adimAt(mevcutKonum, yeni);
                }
            }
            if (denemeYonSayisi == 5) {
                labirent->konumYigiti->cikar();
                labirent->ayarla(oncekiKonum, oncekiKonum.TersYon());
            }
        }
    }
    
    std::cout << "CIKISA GELDI" << std::endl;
    
    getchar();
    
    delete labirent;
    return 0;
}
