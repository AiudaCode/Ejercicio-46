#include "ProgramaDepartamental.h"

ProgramaDepartamental::ProgramaDepartamental()
{
    // se le asigna un valor por defecto en el contructor al atributo de la clase ProgramaDepartamental
    cabeza = NULL;
}

ProgramaDepartamental::~ProgramaDepartamental()
{
    //dtor
}

// metodo set y get del atributo de la clase
void ProgramaDepartamental::setCabeza(Nino *val)
{
    cabeza = val;
}
Nino* ProgramaDepartamental::getCabeza()
{
    return cabeza;
}
// método para retornar el ultimo nodo de la lista
Nino* ProgramaDepartamental::ultimo()
{
    // se inicializa una variable de tipo Nino en la cabeza
    Nino *temp = cabeza;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // entonces, si el siguiente nodo de temp es igual a null
        if (temp->getSiguiente() == NULL)
        {
            // entonces, se rompe el ciclo
            break;
        }
        else
        {
            // sino, se salta al siguiente nodo del temp
            temp = temp->getSiguiente();
        }
    }
    // se retorna el nodo temp
    return temp;
}
// método para agregar por el final
void ProgramaDepartamental::agregarFinal(Nino *nuevo)
{
    // se inicializa una variable de tipo Nino en el valor que retorne el metodo ultimo
    Nino *temp = ultimo();
    // si la cabeza es diferente a null (si hay un nodo en la lista)
    if (cabeza != NULL)
    {
        // entonces, el siguiente nodo de temp ahora sera el nuevo nodo
        temp->setSiguiente(nuevo);
        // el nodo anterior de nuevo ahora sera el nodo temp
        nuevo->setAnterior(temp);
        // y el siguiente de nodo ahora sera null
        nuevo->setSiguiente(NULL);
    }
    else
    {
        // sino, entonces la cabeza apuntara al nuevo nuevo
        cabeza = nuevo;
        // y el siguiente de nodo ahora sera null
        nuevo->setAnterior(NULL);
    }
}
// método para agregar entre nodos
void ProgramaDepartamental::agregarEntreNodos(Nino *nd, Nino *nuevo)
{
    // el siguiente nodo del nuevo sera el siguiente nodo de nd
    nuevo->setSiguiente(nd->getSiguiente());
    // si el siguiente nodo de nd es diferente a null
    if (nd->getSiguiente() != NULL)
    {
        // entonces el nodo anterior del siguiente nodo de nd ahora sera el nuevo nodo
        nd->getSiguiente()->setAnterior(nuevo);
    }
    // el siguiente nodo de nd sera el nuevo nodo
    nd->setSiguiente(nuevo);
    // el nodo anterior del nuevo nodo ahora sera el nodo nd
    nuevo->setAnterior(nd);
}

// método para agregar desde el inicio
void ProgramaDepartamental::agregarInicio(Nino *nuevo)
{
    // si la cabeza es diferente a null
    if (cabeza != NULL)
    {
        // entonces, el siguiente nodo del nuevo ahora sera la cabeza
        nuevo->setSiguiente(cabeza);
        // el nodo anterior de la cabeza sera el nuevo nodo
        cabeza->setAnterior(nuevo);
        // el nodo anterior del nuevo nodo sera null
        nuevo->setAnterior(NULL);
        // la cabeza sera el nuevo nodo
        setCabeza(nuevo);
    }
    else
    {
        // sino, la cabeza sera el nuevo nodo
        cabeza = nuevo;
        // el nodo anterior del nuevo nodo apuntara a null
        nuevo->setAnterior(NULL);
    }
}
// método para eliminar nodo
void ProgramaDepartamental::eliminarNodo(Nino *nd)
{
    // se declara una variable de tipo Nino llamada anterior
    Nino *anterior;
    // si el nodo nd es igual a la cabeza
    if (nd == cabeza)
    {
        // entonces, la cabeza saltara a su siguiente (saltaria a null)
        cabeza = cabeza->getSiguiente();
    }
    else
    {
        // sino, el nodo anterior tendra el valor de la cabeza
        anterior = cabeza;
        // mientras el siguiente nodo del anterior sea difente al nodo nd
        while (anterior->getSiguiente() != nd)
        {
            // entonces se salta al siguiente nodo del anterior
            anterior = anterior->getSiguiente();
        }
        // el siguiente del anterior ahora sera el siguiente nodo de nd
        anterior->setSiguiente(nd->getSiguiente());
        // el anterior del siguiente nodo de nd ahora sera el nodo anterior
        nd->getSiguiente()->setAnterior(anterior);
    }
    // el siguiente de nd sera null
    nd->setSiguiente(NULL);
    // el anterior de nd sera null
    nd->setAnterior(NULL);
}
// método para buscar mediante el numero de registro
Nino* ProgramaDepartamental::buscar(int num_r)
{
    // se declara una variable de tipo Nino
    Nino *temp;
    // se le asigna a temp el valor de la cabeza
    temp = cabeza;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // entonces, si el registro civil del nodo temp es igual al valor de la variable num_r
        if (temp->getRegistroCivil() == num_r)
        {
            // se rompe el ciclo
            break;
        }
        else
        {
            // sino, se salta al siguiente nodo de temp
            temp = temp->getSiguiente();
        }
    }
    // se retorna el nodo temp
    return temp;
}
// método para contar los nodos de la lista
int ProgramaDepartamental::contarNodos()
{
    // se inicializa la variable de tipo Nino temp en la cabeza
    Nino *temp = cabeza;
    // se inicializa la variable de tipo entero contador en 0
    int contador = 0;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // se incrementara la variable contador
        contador++;
        // y se salta al siguiente nodo de temp
        temp = temp->getSiguiente();
    }
    // se retorna el valor de la variable contador
    return contador;
}

// método para contar los niños de cada municipio
int ProgramaDepartamental::contarNinosMunicipio(int mun)
{
    // se inicializa la variable de tipo Nino temp en la cabeza
    Nino *temp = cabeza;
    // se inicializa la variable de tipo entero contador en 0
    int contador = 0;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // si el municipio del nodo temp es igual al valor de la variable mun
        if (temp->getMunicipio() == mun)
        {
            // se incrementa el valor de la variable contador
            contador++;
        }
        // se salta al siguiente nodo de temp
        temp = temp->getSiguiente();
    }
    // se retorna el valor de la variable contador
    return contador;
}
// método para contar los niños de cada municipio en condiciones de bajo peso
int ProgramaDepartamental::contarNinosMunicipioPeso(int mun)
{
    // se inicializa la variable de tipo Nino temp en la cabeza
    Nino *temp = cabeza;
    // se inicializa la variable de tipo entero contador en 0
    int contador = 0;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // si el municipio del nodo temp es igual al valor de la variable mun y esta entre el rango de 2 a 3 años y tiene un peso menor a 15 kg
        // ó si el municipio del nodo temp es igual al valor de la variable num y esta tiene una edad entre 4 y 6 años y tiene un peso inferior a 25kg
        if (temp->getMunicipio() == mun && ((temp->getEdad() >= 2 && temp->getEdad() <= 3) && temp->getPeso() < 15) || temp->getMunicipio() == mun && ((temp->getEdad() >= 4 && temp->getEdad() <= 6) && temp->getPeso() < 25))
        {
            // se incrementa el valor de la variable contador
            contador++;
        }
        // se salta al siguiente nodo de temp
        temp = temp->getSiguiente();
    }
    // se retorna el valor de la variable contador
    return contador;
}
// método para contar la cantidad de niños que tienen una altura inferiro a 1m
int ProgramaDepartamental::contarNinosPorAltura(int mun)
{
    // se inicializa la variable de tipo Nino temp en la cabeza
    Nino *temp = cabeza;
    // se inicializa la variable de tipo entero contador en 0
    int contador = 0;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // si el municipio del nodo temp es igual al valor de la variable num y si tiene una edad entre 4 y 6 años
        // y si tiene una altura menor a 1
        if (temp->getMunicipio() == mun && ((temp->getEdad() >= 4 && temp->getEdad() <= 6) && temp->getAltura() < 1))
        {
            // se incrementa el valor de la variable contador
            contador++;
        }
        // se salta al siguiente nodo de temp
        temp = temp->getSiguiente();
    }
    // se retorna el valor de la variable contador
    return contador;
}
// método para ordenar por intercambio
void ProgramaDepartamental::ordenarIntercambio(Nino *n)
{
    // Se declaran dos variables de tipo Nino actual y siguiente
    Nino *actual;
    Nino *siguiente;
    // se le asigna al nodo actual el valor del nodo n
    actual = n;
    // mientras el siguiente nodo del actual sea diferente a null
    while(actual->getSiguiente() != NULL)
    {
        // entonces, se le asignara al nodo siguiente el valor del siguiente nodo del actual
        siguiente = actual->getSiguiente();
        // mientra el nodo siguiente sea diferente a null
        while(siguiente != NULL)
        {
            // entonces si el peso del nodo actual es mayor al peso del siguiente nodo
            if(actual->getPeso() > siguiente->getPeso())
            {
                // entonces se cambia el nodo actual por el siguiente
                cambiar(actual, siguiente);
            }
            // se salta al siguiente nodo de siguiente
            siguiente = siguiente->getSiguiente();
        }
        // se salta al siguiente nodo de actual
        actual = actual->getSiguiente();
    }
}
// método para cambiar los nodos
void ProgramaDepartamental::cambiar(Nino* p1, Nino* p2)
{
    // creo un nuevo nodo para poder realizar la copia
    Nino *temp = new Nino();
    // le asigno al nodo temp los datos del nodo actual (p1)
    temp->copiar(p1);
    // le asigno al nodo p1 los datos del nodo siguiente (p2)
    p1->copiar(p2);
    // le asigno al nodo p2 los datos del temp
    p2->copiar(temp);
}
