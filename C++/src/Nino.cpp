#include "Nino.h"

Nino::Nino()
{
    // se le asigna valores por defecto en el constructor a los atributos de la clase Nino
    edad = 0;
    nombre = "";
    registro_civil = 0;
    altura = 0;
    peso = 0;
    id_padre = 0;
    nombre_padre = "";
    municipio = 0;
    siguiente = NULL;
    anterior = NULL;
}

Nino::~Nino()
{
    //dtor
}

// metodos Setters y Getters de los atributos de la clase
void Nino::setEdad(int val)
{
    edad = val;
}
int Nino::getEdad()
{
    return edad;
}
void Nino::setNombre(string val)
{
    nombre = val;
}
string Nino::getNombre()
{
    return nombre;
}
void Nino::setRegistroCivil(int val)
{
    registro_civil = val;
}
int Nino::getRegistroCivil()
{
    return registro_civil;
}
void Nino::setAltura(float val)
{
    altura = val;
}
float Nino::getAltura()
{
    return altura;
}
void Nino::setPeso(int val)
{
    peso = val;
}
int Nino::getPeso()
{
    return peso;
}
void Nino::setIdPadre(int val)
{
    id_padre = val;
}
int Nino::getIdPadre()
{
    return id_padre;
}
void Nino::setNombrePadre(string val)
{
    nombre_padre = val;
}
string Nino::getNombrePadre()
{
    return nombre_padre;
}
void Nino::setMunicipio(int val)
{
    municipio = val;
}
int Nino::getMunicipio()
{
    return municipio;
}
void Nino::setSiguiente(Nino *val)
{
    siguiente = val;
}

Nino *Nino::getSiguiente()
{
    return siguiente;
}

void Nino::setAnterior(Nino *val)
{
    anterior = val;
}

Nino *Nino::getAnterior()
{
    return anterior;
}

// método para copiar toda la información de un nodo
void Nino::copiar(Nino *nd)
{
    edad = nd->getEdad();
    nombre = nd->getNombre();
    registro_civil = nd->getRegistroCivil();
    altura = nd->getAltura();
    peso = nd->getPeso();
    id_padre = nd->getIdPadre();
    nombre_padre = nd->getNombrePadre();
}
