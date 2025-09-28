#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename Nesne>
class Dugum {
public:
    Nesne veri;
    Dugum<Nesne>* sonraki;

    Dugum(const Nesne& veri, Dugum<Nesne>* sonraki = nullptr) {
        this->veri = veri;
        this->sonraki = sonraki;
    }
};

template <typename Nesne>
class Stack {
private:
    Dugum<Nesne>* yiginUst;

public:
    Stack() {
        yiginUst = nullptr;
    }
    bool bosMu() const {
        return yiginUst == nullptr;
    }
    void ekle(const Nesne& veri) {
        yiginUst = new Dugum<Nesne>(veri, yiginUst);
    }
    void cikar() {
        if (bosMu()) throw "Yığın Boş";
        Dugum<Nesne>* gecici = yiginUst;
        yiginUst = yiginUst->sonraki;
        delete gecici;
    }
    const Nesne& ust() const {
        if (bosMu()) throw "Yığın Boş";
        return yiginUst->veri;
    }
    void bosalt() {
        while (!bosMu()) cikar();
    }
    ~Stack() {
        bosalt();
    }
};

#endif
