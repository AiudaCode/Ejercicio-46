#include <iostream>
#include "Nino.h"
#include "ProgramaDepartamental.h"
// se incluye la clase stdlib para utilizar el metodo system y poder utilizar los comando de la consola
// para asi limpiarla, pasandole el comando cls
#include "stdlib.h"

using namespace std;

// método para llenar la lista
void llenar(Nino *nod)
{
    int e, n_r, p, id, m;
    string n, n_p;
    float a;
    // con el ciclo do while comprobare que la edad este entre el rango de 1 y 6 años
    do
    {
        cout << "Ingrese edad del nino" << endl;
        cout << ">> ";
        cin >> e;
    }
    while (e < 1 || e > 6);
    // encapsulo la variable e
    nod->setEdad(e);
    // se pide el nombre del niño
    cout << "Ingrese nombre del nino" << endl;
    cout << ">> ";
    cin >> n;
    // encapsulo la variable n
    nod->setNombre(n);
    // se pide el registro civil del niño
    cout << "Ingrese numero de registro civil del nino" << endl;
    cout << ">> ";
    cin >> n_r;
    // encapsulo la variable n_r
    nod->setRegistroCivil(n_r);
    // se pide la altura del niño
    cout << "Ingrese altura del nino" << endl;
    cout << ">> ";
    cin >> a;
    // se encapsula la variable a
    nod->setAltura(a);
    // se pide el peso del niño
    cout << "Ingrese peso del nino:" << endl;
    cout << ">> ";
    cin >> p;
    // se encapsula la variable p
    nod->setPeso(p);
    // se pide el numero de identificacion del padre
    cout << "Ingrese numero de identificacion del padre/madre del nino" << endl;
    cout << ">> ";
    cin >> id;
    // se encapsula la variable id
    nod->setIdPadre(id);
    // se pide el nombre del padre o la madre del niño
    cout << "Ingrese nombre del padre/madre del nino" << endl;
    cout << ">> ";
    cin >> n_p;
    // se encapsula la variable n_p
    nod->setNombrePadre(n_p);
    // con el ciclo do while comprobare que se ingrese el municipio correcto
    do
    {
        cout << "Ingrese municipio donde vive el nino" << endl;
        cout << "1. Sahagun" << endl;
        cout << "2. Monteria" << endl;
        cout << "3. Lorica" << endl;
        cout << ">> ";
        cin >> m;
        system("cls");
    }
    while (m < 1 || m > 3);
    // se encapsula la variable m
    nod->setMunicipio(m);
}

// método para mostrar el municipio
string mostrarMunicipio(int opc)
{
    // mediante el valor que se pase como parametro opc, el switch escore el caso
    switch (opc)
    {
        case 1:
            return "Sahagun";
        case 2:
            return "Monteria";
        default:
            return "Lorica";
    }
}

// método para mostrar la informacion del niño
void mostrar(Nino *nod)
{
    cout << "Nombre: " << nod->getNombre() << endl;
    cout << "Edad: " << nod->getEdad() << endl;
    cout << "Registro Civil: " << nod->getRegistroCivil() << endl;
    cout << "Altura: " << nod->getAltura() << endl;
    cout << "Peso: " << nod->getPeso() << endl;
    cout << "Nombre representante: " << nod->getNombrePadre() << endl;
    cout << "ID representante: " << nod->getIdPadre() << endl;
    cout << "Municipio: " << mostrarMunicipio(nod->getMunicipio()) << endl << endl;
}

// método para listar todos la lista
void listar(ProgramaDepartamental *obj)
{
    // declaro e inicializo la variable temp en el valor que tenga la cabeza
    Nino *temp = obj->getCabeza();
    // mientras haya un nodo en la lista
    while (temp != NULL)
    {
        // entonces mostrara la informacion del nodo temp
        mostrar(temp);
        // y se salta al siguiente nodo temp
        temp = temp->getSiguiente();
    }
}

// método para listar los niños por municipio
void listarPorMunicipio(ProgramaDepartamental *obj)
{
    // como son 3 municipios, entonces recorrere con el ciclo for desde 1 hasta 3
    for (int i = 1; i <= 3; i++)
    {
        // muestro en un mensaje de dialogo, el municipio actual: mostrarMunicipio(i)
        cout << "[Ninos del municipio de " << mostrarMunicipio(i) << "]" << endl;
        // declaro e inicializo la variable temp con el valor de la cabeza
        Nino *temp = obj->getCabeza();
        // mientras haya un nodo en la lista
        while (temp != NULL)
        {
            // entonces, si el nodo temp pertenece al municipio i (i = 0: Sahagún, i = 1: Montería, i = 2: Lorica)
            if (temp->getMunicipio() == i)
            {
                // se muestra la información del nodo temp
                mostrar(temp);
            }
            // se salta al siguiente nodo temporal
            temp = temp->getSiguiente();
        }
        // muestro la cantidad de niños de cada municipio, llamando al metodo contarNiñosMunicipio y pasandole como parametro i
        cout << "Hay " << obj->contarNinosMunicipio(i) << " nino(s) en el municipio de " << mostrarMunicipio(i) << endl;
    }
}

// método para listar cada niño si cumple las condiciones de peso bajo
void listarPorCondicionesPeso(ProgramaDepartamental *obj)
{
    cout << "[Ninos de 2 y 3 o 4 y 6 años en condiciones de bajo peso]" << endl;
    // como son 3 municipios, entonces recorrere con el ciclo for desde 1 hasta 3
    for (int i = 1; i <= 3; i++)
    {
        // declaro e inicializo la variable temp con el valor de la cabeza
        Nino *temp = obj->getCabeza();
        // mientras haya un nodo en la lista
        while (temp != NULL)
        {
            // entonces, si el municipio es igual a i, y tiene una edad entre 2 y 3 años y pesa menos de 15 kg ó si tiene una edad entre 4 y 6 y pesa menos de 25 kg
            if (temp->getMunicipio() == i && ((temp->getEdad() >= 2 && temp->getEdad() <= 3) && temp->getPeso() < 15) || temp->getMunicipio() == i && ((temp->getEdad() >= 4 && temp->getEdad() <= 6) && temp->getPeso() < 25))
            {
                // se mostrara la informacion del nodo temp
                mostrar(temp);
            }
            // se salta al siguiente nodo temp
            temp = temp->getSiguiente();
        }
        // se muestra la cantidad de niños en condiciones de bajo peso por municipio
        cout << "Hay " << obj->contarNinosMunicipioPeso(i) << " nino(s) en el municipio de " << mostrarMunicipio(i) << " en condiciones de bajo peso." << endl;
    }
}

// método para listar cada niño si tiene una altura menor a 1 metro
void listarPorAltura(ProgramaDepartamental *obj)
{
    cout << "[Ninos entre 4 y 6 años que miden menos de 1 metro]" << endl;
    // como son 3 municipios, entonces recorrere con el ciclo for desde 1 hasta 3
    for (int i = 1; i <= 3; i++)
    {
        // declaro e inicializo la variable temp con el valor de la cabeza
        Nino *temp = obj->getCabeza();
        // mientras haya un nodo en la lista
        while (temp != NULL)
        {
            // si el niño esta en el municipio i y tiene una edad entre 4 y 6 años y tiene una altura menor a 1 m
            if (temp->getMunicipio() == i && ((temp->getEdad() >= 4 && temp->getEdad() <= 6) && temp->getAltura() < 1))
            {
                // entonces se mostrara la información del nodo temp
                mostrar(temp);
            }
            // se salta al siguiente nodo temp
            temp = temp->getSiguiente();
        }
        // se muestra la cantidad de niños con una estatura menor a 1m por municipio
        cout << "Hay " << obj->contarNinosPorAltura(i) << " nino(s) en el municipio de " << mostrarMunicipio(i) << " en condiciones de bajo peso." << endl;
    }
}

// método para mostrar el menu de opciones
int menu()
{
    int opc;
    do
    {
        cout << "1. Agregar informacion del nino y su representante por el final." << endl;
        cout << "2. Insertar entre dos nodos existentes." << endl;
        cout << "3. Agregar informacion del nino y su representante por el principio." << endl;
        cout << "4. Buscar por numero de registro civil." << endl;
        cout << "5. Ordenar la informacion, teniendo en cuenta el peso de los niños." << endl;
        cout << "6. Eliminar la informacion de un nino y su representante." << endl;
        cout << "7. Listado por municipios." << endl;
        cout << "8. Listado por condiciones bajos de peso." << endl;
        cout << "9. Listado por altura." << endl;
        cout << "10. Mostrar toda la lista." << endl;
        cout << "11. Salir" << endl;
        cout << ">> ";
        cin >> opc;
        system("cls");
    }
    while (opc < 0 || opc > 11);
    return opc;
}

int main(void)
{
    // creo un objeto de la clase ProgramaDepartamental (instanciación)
    ProgramaDepartamental *obj = new ProgramaDepartamental();
    // declaro una variable de tipo Nino
    Nino *aux;
    // declaro dos variables de tipo entero opcion y num_reg
    int opcion, num_reg;
    do
    {
       // se le asigna a la variable opcion el valor que retorne el metodo menu
       opcion = menu();
       // dependiendo del valor de la opcion se escogera un caso
       switch(opcion)
       {
            case 1:
                aux = new Nino();
                llenar(aux);
                obj->agregarFinal(aux);
                cout << "Se ha agregado correctamente la información" << endl;
                break;
            case 2:
                cout << "Ingrese número de registro del nodo anterior al que desea agregar" << endl;
                cout << ">> ";
                cin >> num_reg;
                aux = obj->buscar(num_reg);
                if(aux != NULL)
                {
                    aux = new Nino();
                    llenar(aux);
                    obj->agregarEntreNodos(obj->buscar(num_reg), aux);
                    cout << "Se ha agregado correctamente la información" << endl;
                }
                else
                {
                    cout << "No se ha encontrado el nodo!" << endl;
                }
                break;
            case 3:
                aux = new Nino();
                llenar(aux);
                obj->agregarInicio(aux);
                cout << "Se ha agregado correctamente la información" << endl;
                break;
            case 4:
                cout << "Ingrese número de registro del nodo anterior al que desea agregar" << endl;
                cout << ">> ";
                cin >> num_reg;
                aux = obj->buscar(num_reg);
                if(aux != NULL)
                {
                    mostrar(obj->buscar(num_reg));
                }
                else
                {
                    cout << "No se ha encontrado el nodo!" << endl;
                }
                break;
            case 5:
                aux = obj->getCabeza();
                if (aux != NULL)
                {
                    if(obj->contarNodos() > 1)
                    {
                        aux = obj->getCabeza();
                        obj->ordenarIntercambio(aux);
                        listar(obj);
                    }
                    else
                    {
                        cout << "Solo hay un nino, agregue por lo menos 1 niño mas para ordenar." << endl;
                    }
                }
                break;
            case 6:
                aux = obj->getCabeza();
                obj->eliminarNodo(aux);
                cout << "Se elimino correctamente." << endl;
                break;
            case 7:
                listarPorMunicipio(obj);
                break;
            case 8:
                listarPorCondicionesPeso(obj);
                break;
            case 9:
                listarPorAltura(obj);
                break;
            case 10:
                listar(obj);
                break;
            default:
                break;
       }
    }
    while (opcion != 11);
}
