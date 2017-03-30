#ifndef PROGRAMADEPARTAMENTAL_H
#define PROGRAMADEPARTAMENTAL_H
#include <iostream>
#include "Nino.h"

using namespace std;

class ProgramaDepartamental
{
    public:
        ProgramaDepartamental();
        virtual ~ProgramaDepartamental();
        // metodos publicos de la clase ProgramaDepartamental
        void setCabeza(Nino *val);
        Nino *getCabeza();
        Nino *ultimo();
        void agregarFinal(Nino *nuevo);
        void agregarEntreNodos(Nino *nd, Nino *nuevo);
        void agregarInicio(Nino *nuevo);
        void eliminarNodo(Nino *nd);
        Nino *buscar(int num_r);
        int contarNodos();
        int contarNinosMunicipio(int mun);
        int contarNinosMunicipioPeso(int mun);
        int contarNinosPorAltura(int mun);
        void ordenarIntercambio(Nino *n);
        void cambiar(Nino *p1, Nino *p2);
    protected:

    private:
        // atributo privado de la clase ProgramaDepartamental
        Nino *cabeza;
};

#endif // PROGRAMADEPARTAMENTAL_H
