#include "Lista.h"

alumno::alumno() : nombre("juanito"), nombreCarrera("inco"), nombrePrepa("univer"), promedioGeneral(0.0) {}

alumno::alumno(std::string n, std::string nC, std::string nP, float pG)
       : nombre(n), nombreCarrera(nC), nombrePrepa(nP), promedioGeneral(pG) {}

bool alumno::operator==(const alumno& otro) const
{
    return nombre == otro.nombre && nombreCarrera == otro.nombreCarrera && nombrePrepa == otro.nombrePrepa && promedioGeneral == otro.promedioGeneral;
}


alumno& alumno::operator=(const alumno& x)
{
    if (this != &x)
    {
        nombre = x.nombre;
        nombreCarrera = x.nombreCarrera;
        nombrePrepa = x.nombrePrepa;
        promedioGeneral = x.promedioGeneral;
    }
    return *this;
}

float alumno::getPromedioGeneral() const
{
    return promedioGeneral;
}

std::ostream& operator<<(std::ostream& o, const alumno& p)
{
    o << "nombre: " << p.nombre << "\tnombre carrera: " << p.nombreCarrera << "\tnombre preparatoria: " << p.nombrePrepa << "\tpromedio general: " << p.promedioGeneral << std::endl;
    return o;
}

std::istream& operator>>(std::istream& o, alumno& p)
{
    std::cout << "\nIngresa nombre: ";
    o >> p.nombre;
    std::cout << "Ingresa nombre carrera: ";
    o >> p.nombreCarrera;
    std::cout << "Ingresa nombre preparatoria: ";
    o >> p.nombrePrepa;
    std::cin.ignore();
    std::cout << "Ingresa promedio general: ";
    o >> p.promedioGeneral;
    std::cin.ignore();
    return o;
}

Lista::Lista() : size(0)
{

}

bool Lista::vacia() const
{
    return size == 0;
}

void Lista::darDeAltaSolicitud(const alumno& x)
{
    if (size < TAM)
    {
        datos[size] = x;
        size++;
        std::cout << "\n¡Solicitud dada de alta exitosamente!." << std::endl;
    }
    else
    {
        std::cout << "\nLa lista de solicitudes está llena. No se puede dar de alta la solicitud." << std::endl;
    }
}

void Lista::buscarSolicitud(const alumno& x)
{
    if (vacia())
    {
        std::cout << "\nNo hay solicitudes en la lista. Debe dar de alta una solicitud primero." << std::endl;
        return;
    }


    quicksort(0, size - 1);


    int posicion = busquedaBinaria(x);

    if (posicion == -1)
    {
        std::cout << "\nEse alumno no ha generado una constancia. Debe dar de alta una solicitud primero." << std::endl;
    }
    else
    {
        std::cout << "\nDatos del alumno encontrado" << std::endl;
        std::cout << datos[posicion];
        std::cout << "\nLugar que se tiene entre todas las solicitudes: " << posicion + 1 << std::endl;
    }
}

void Lista::quicksort(int inicio, int fin)
{
    if (inicio < fin)
    {
        int pivot = particion(inicio, fin);
        quicksort(inicio, pivot - 1);
        quicksort(pivot + 1, fin);
    }
}

int Lista::particion(int inicio, int fin)
{
    float pivot = datos[fin].getPromedioGeneral();
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++)
    {
        if (datos[j].getPromedioGeneral() < pivot)
        {
            i++;
            std::swap(datos[i], datos[j]);
        }
    }

    std::swap(datos[i + 1], datos[fin]);
    return i + 1;
}

int Lista::busquedaBinaria(const alumno& elem)
{
    int izquierda = 0;
    int derecha = size - 1;

    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (datos[medio].getPromedioGeneral() == elem.getPromedioGeneral())
        {
            return medio;
        }
        if (datos[medio].getPromedioGeneral() < elem.getPromedioGeneral())
        {
            izquierda = medio + 1;
        }
        else
        {
            derecha = medio - 1;
        }
    }

    return -1;
}

void Lista::buscarSolicitud(const alumno& x, int ordenamiento)
{
    if (vacia())
    {
        std::cout << "\nNo hay solicitudes en la lista. Debe dar de alta una solicitud primero." << std::endl;
        return;
    }

    if (ordenamiento == 2)
    {
        quicksort(0, size - 1);  //quicksort
    }
    else if (ordenamiento == 3)
    {
        burbuja();  //burbuja
    }
    else
    {
        std::cout << "\nOpción de ordenamiento no válida." << std::endl;
        return;
    }

    int posicion = -1;

    for (int i = 0; i < size; i++)
    {
        if (datos[i] == x)
        {
            posicion = i;
            break;
        }
    }

    if (posicion == -1)
    {
        std::cout << "\nEse alumno no ha generado una constancia. Debe dar de alta una solicitud primero." << std::endl;
    }
    else
    {
        std::cout << "\nDatos del alumno encontrado" << std::endl;
        std::cout << "-------------------------------------------------------------------------------------" << std::endl;
        std::cout << datos[posicion];
        std::cout << "\nLugar que se tiene entre todas las solicitudes: " << posicion + 1 << std::endl;
    }
}
void Lista::burbuja()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (datos[j].getPromedioGeneral() < datos[j + 1].getPromedioGeneral())
            {
                std::swap(datos[j], datos[j + 1]);
            }
        }
    }
}
