#ifndef NINO_H
#define NINO_H
#include <iostream>

using namespace std;

class Nino
{
    public:
        Nino();
        virtual ~Nino();
        // metodos publicos de la clase Nino
        void setEdad(int val);
        int getEdad();
        void setNombre(string val);
        string getNombre();
        void setRegistroCivil(int val);
        int getRegistroCivil();
        void setAltura(float val);
        float getAltura();
        void setPeso(int val);
        int getPeso();
        void setIdPadre(int val);
        int getIdPadre();
        void setNombrePadre(string val);
        string getNombrePadre();
        void setMunicipio(int val);
        int getMunicipio();
        void setSiguiente(Nino *val);
        Nino *getSiguiente();
        void setAnterior(Nino *val);
        Nino *getAnterior();
        void copiar(Nino *nd);

    protected:

    private:
        // atributos privados de la clase Nino
        int edad;
        string nombre;
        int registro_civil;
        float altura;
        int peso;
        int id_padre;
        string nombre_padre;
        int municipio;
        Nino *siguiente;
        Nino *anterior;
};

#endif // NINO_H
