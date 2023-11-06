#include "Lista.h"
#include "Lista.cpp"
#include <locale>

int main()
{
    Lista MiLista;
    int opcion;

    do
    {
        setlocale(LC_ALL,"");
        std::cout << "\nMENÚ - LISTA (ORDENAMIENTOS)\n" << std::endl;
        std::cout << "1.- Dar de alta una solicitud" << std::endl;
        std::cout << "2.- Buscar una solicitud (quicksort)" << std::endl;
        std::cout << "3.- Buscar una solicitud (burbuja)" << std::endl;
        std::cout << "4.- Salir" << std::endl;
        std::cout << "\nIngresa una opción: ";
        std::cin >> opcion;

        if (opcion == 1)
        {
            alumno nuevoAlumno;
            std::cin >> nuevoAlumno;
            MiLista.darDeAltaSolicitud(nuevoAlumno);
        }
        else if (opcion == 2) //ordenamiento quicksort
        {
            alumno alumnoBuscar;
            std::cin >> alumnoBuscar;
            MiLista.buscarSolicitud(alumnoBuscar, 2);
        }
        else if (opcion == 3) //ordenamiento burbuja
        {
            alumno alumnoBuscar;
            std::cin >> alumnoBuscar;
            MiLista.buscarSolicitud(alumnoBuscar, 3);
        }
        else if (opcion == 4)
        {
            std::cout << "\nSaliendo..." << std::endl;
        }
    }
    while (opcion != 4);
}
