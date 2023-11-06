#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include <string>

const int TAM = 100;

class alumno
{
private:
    std::string nombre;
    std::string nombreCarrera;
    std::string nombrePrepa;
    float promedioGeneral;

public:
    alumno();
    alumno(std::string n, std::string nC, std::string nP, float pG);
    bool operator==(const alumno& otro) const;
    alumno& operator=(const alumno& x);
    float getPromedioGeneral() const;

    friend std::ostream& operator<<(std::ostream& o, const alumno& p);
    friend std::istream& operator>>(std::istream& o, alumno& p);
};

class Lista
{
private:
    alumno datos[TAM];
    int size;

    void quicksort(int inicio, int fin);
    int particion(int inicio, int fin);
    int busquedaBinaria(const alumno& elem);

public:
    Lista();
    bool vacia() const;
    void darDeAltaSolicitud(const alumno& x);
    void buscarSolicitud(const alumno& x);
    void buscarSolicitud(const alumno& x, int ordenamiento);
    void burbuja();

};

#endif // LISTA_H_INCLUDED

