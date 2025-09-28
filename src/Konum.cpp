#include "Konum.hpp"

Konum::Konum(int x, int y, Yon yon) : x(x), y(y), yon(yon) {}

Konum::Konum() : x(0), y(0), yon(ASAGI) {}

Konum Konum::AyniYon() const {
    switch (yon) {
        case YUKARI: return Yukari();
        case SAG: return Sag();
        case ASAGI: return Asagi();
        default: return Sol();
    }
}

Konum Konum::SaatYonu(Yon yon) const {
    switch (yon) {
        case YUKARI: return Sag();
        case SAG: return Asagi();
        case ASAGI: return Sol();
        default: return Yukari();
    }
}

Konum Konum::Asagi() const { return Konum(x + 1, y, ASAGI); }

Konum Konum::Yukari() const { return Konum(x - 1, y, YUKARI); }

Konum Konum::Sol() const { return Konum(x, y - 1, SOL); }

Konum Konum::Sag() const { return Konum(x, y + 1, SAG); }

Yon Konum::TersYon() const {
    switch (yon) {
        case ASAGI: return YUKARI;
        case YUKARI: return ASAGI;
        case SOL: return SAG;
        case SAG: return SOL;
        default: return YUKARI;
    }
}
