#ifndef KONUM_HPP
#define KONUM_HPP

typedef enum { ASAGI, SOL, YUKARI, SAG } Yon;

struct Konum {
    int x, y;
    Yon yon;
    Konum(int x, int y, Yon yon = ASAGI);
    Konum();
    Konum AyniYon() const;
    Konum SaatYonu(Yon yon) const;
    Konum Asagi() const;
    Konum Yukari() const;
    Konum Sol() const;
    Konum Sag() const;
    Yon TersYon() const;
};

#endif
