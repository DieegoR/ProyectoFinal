#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <limits>
#include <time.h>
#include <stdlib.h>
#include <algorithm>


using namespace std;

class Computadora
{
private:
    string marca;
    string modelo;
    int numSerie;
    int memoriaRAM;
    int espacioMemoria;
    string procesador;
    int capacidadPila;
    int precio;
    string sistema;
    vector<string> ProgramasInstalados;

public:
    Computadora(string marca, string modelo, int numSerie, int memoriaRAM,
                int espacioMemoria, string procesador, int capacidadPila, int precio, string sistema, const vector<string> &ProgramasInstalados)
    {
        this->marca = marca;
        this->modelo = modelo;
        this->numSerie = numSerie;
        this->memoriaRAM = memoriaRAM;
        this->espacioMemoria = espacioMemoria;
        this->procesador = procesador;
        this->capacidadPila = capacidadPila;
        this->precio = precio;
        this->sistema = sistema;
        this->ProgramasInstalados = ProgramasInstalados;
    }
     vector<string> &getProgramasInstalados()
    {
        return ProgramasInstalados;
    }

    string getMarca()
    {
        return this->marca;
    }

    string getModelo()
    {
        return this->modelo;
    }

    int getNumSerie()
    {
        return this->numSerie;
    }
    int getMemoriaRAM()
    {
        return this->memoriaRAM;
    }

    int getEspacioMemoria()
    {
        return this->espacioMemoria;
    }

    string getProcesador()
    {
        return this->procesador;
    }

    int getCapacidadPila()
    {
        return this->capacidadPila;
    }

    int getPrecio()
    {
        return this->precio;
    }

    string getSistema()
    {
        return this->sistema;
    }


    void setMarca(string marcaNueva)
    {
        this->marca = marcaNueva;
    }

    void setModelo(string modeloNuevo)
    {
        this->modelo = modeloNuevo;
    }

    void setNumSerie(int numSerieNuevo)
    {
        this->numSerie = numSerieNuevo;
    }

    void setMemoriaRam(int ramNueva)
    {
        this->memoriaRAM = ramNueva;
    }

    void setEspacioMemoria(int espacioNuevo)
    {
        this->espacioMemoria = espacioNuevo;
    }

    void setProcesador(string procesadorNuevo)
    {
        this->procesador = procesadorNuevo;
    }

    void setCapacidadPila(int capacidadPilaNueva)
    {
        this->capacidadPila = capacidadPilaNueva;
    }

    void setPrecio(int precioNuevo)
    {
        this->precio = precioNuevo;
    }

    void setSistema(string sistemaNuevo)
    {
        this->sistema = sistemaNuevo;
    }

    void setProgramasInstalados(const vector<string> &nuevosProgramas)
    {
        ProgramasInstalados = nuevosProgramas;
    }
};

int main()
{
    srand(time(NULL));
    int numComputadoraBase1;
    int numComputadoraBase2;
    int limite_inferior = 1000;
    int limite_superior = 20000;
    numComputadoraBase1 = limite_inferior + rand() % (limite_superior +1 - limite_inferior);
    numComputadoraBase2 = limite_inferior + rand() % (limite_superior +1 - limite_inferior);
    vector<Computadora> computadoras;
    vector <string> Programas = {"lol", "minecaft", "geometry dash"};
    Computadora comptadoraBase1("Azus", "TufGaming", numComputadoraBase1, 8, 500, "i5", 4500, 12000, "Windows 10", Programas);
    Computadora comptadoraBase2("HP", "EliteBook", numComputadoraBase2, 16, 1000, "i4", 4500, 15000, "Windows 10", Programas);
    computadoras.push_back(comptadoraBase1);
    computadoras.push_back(comptadoraBase2);
    cout << " --- Computadoras ---" << endl;
    cout << "Numero de serie computadora base 1: "<<  numComputadoraBase1 << endl;
    cout << "Numero de serie computadora base 2: "<<  numComputadoraBase2 << endl;
    int operacion;
    do
    {
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        cout << "\nIngrese el numero correspondiente a la operacion que desea realizar\n";
        cout << "\n(1) -> Crear computadora\n(2) -> Imprimir computadora\n(3) -> Modificar computadora\n(4) -> Eliminar computadora\n(5) -> Opcion libre 1\n(6) -> Opcion libre 2\n(7) -> Salir\n";
        cout << "Numero: ";
        string input;
        cin >> input;
        if (isdigit(input[0]))
        {
            operacion = atoi(input.c_str());
            cout << endl;
            if (operacion >= 1 && operacion <= 7)
            {
                if (operacion == 1)
                {
                    cout << "Crear computadora" << endl;


                    string marca, modelo, procesador, sistema;
                    int numSerie, memoriaRAM, espacioMemoria, capacidadPila, precio;
                    vector<string> programasInstalados;

                    cout << "Marca: ";
                    cin >> marca;
                    cout << "Modelo: ";
                    cin >> modelo;
                    cout << "Numero de serie: ";
                    cin >> numSerie;
                    cout << "Memoria RAM (GB): ";
                    cin >> memoriaRAM;
                    cout << "Espacio de memoria (GB): ";
                    cin >> espacioMemoria;
                    cout << "Procesador: ";
                    cin >> procesador;
                    cout << "Capacidad de la pila (mAh): ";
                    cin >> capacidadPila;
                    cout << "Precio: ";
                    cin >> precio;

                    int numProgramas;
                    cout << "Numero de programas instalados: ";
                    cin >> numProgramas;

                    for (int i = 0; i < numProgramas; i++)
                    {
                        string programa;
                        cout << "Programa #" << (i + 1) << ": ";
                        cin >> programa;
                        programasInstalados.push_back(programa);
                    }

                    Computadora nuevaComputadora(marca, modelo, numSerie, memoriaRAM, espacioMemoria, procesador, capacidadPila, precio, sistema, programasInstalados);

                    computadoras.push_back(nuevaComputadora);

                    cout << "Computadora creada con exito." << endl;
                }
                else if (operacion == 2)
                {
                    cout << "Imprimir computadora" << endl;


                    int numSerieBuscar;
                    cout << "Ingrese el numero de serie de la computadora a imprimir: ";
                    cin >> numSerieBuscar;

                    bool encontrada = false;


                    for (Computadora &comp : computadoras)
                    {
                    if (comp.getNumSerie() == numSerieBuscar)
                    {
                    encontrada = true;
                    cout << "Marca: " << comp.getMarca() << endl;
                            cout << "Modelo: " << comp.getModelo() << endl;
                            cout << "Numero de serie: " << comp.getNumSerie() << endl;
                            cout << "Memoria RAM (GB): " << comp.getMemoriaRAM() << endl;
                            cout << "Espacio de memoria (GB): " << comp.getEspacioMemoria() << endl;
                            cout << "Procesador: " << comp.getProcesador() << endl;
                            cout << "Capacidad de la pila (mAh): " << comp.getCapacidadPila() << endl;
                            cout << "Precio: " << comp.getPrecio() << endl;
                            cout << "Sistema: " << comp.getSistema() << endl;


                            cout << "Programas instalados: ";
                            for (const string &programa : comp.getProgramasInstalados())
                            {
                                cout << programa << ", ";
                            }
                            cout << endl;

//

                            break;
                                }
                            }

                    if (!encontrada)
                    {
                        cout << "No se encontro una computadora con el numero de serie especificado." << endl;
                    }
                    }
                else if (operacion == 3)
                {
                    cout << "Editar computadora: " << endl;
                    int numSerieEditar;
                    cout << "Ingrese el numero de serie de la computadora a editar: ";
                    cin >> numSerieEditar;
                    bool encontrada = false;

                    for (Computadora &comp : computadoras)
                    {
                        if (comp.getNumSerie() == numSerieEditar)
                        {
                        encontrada = true;
                        string nuevaMarca, nuevoModelo, nuevoProcesador, nuevoSistema;
                        int nuevaMemoriaRAM, nuevoEspacioMemoria, nuevaCapacidadPila, nuevoPrecio;
                        int opcionEdicion;
                    do{
                        cout << "\nElija la propiedad a editar:\n";
                        cout << "(1) -> Marca\n(2) -> Modelo\n(3) -> Memoria RAM (GB)\n(4) -> Espacio de memoria (GB)\n(5) -> Procesador\n(6) -> Capacidad de la pila (mAh)\n(7) -> Precio\n(8) -> Sistema\n(9) -> Programas instalados\n(0) -> Salir\n";
                        cout << "Opcion: ";
                        cin >> opcionEdicion;

                        if (opcionEdicion == 1)
                        {
                            cout << "Nueva Marca: ";
                            cin >> nuevaMarca;
                            comp.setMarca(nuevaMarca);
                        }
                        else if (opcionEdicion == 2)
                        {
                            cout << "Nuevo Modelo: ";
                            cin >> nuevoModelo;
                            comp.setModelo(nuevoModelo);
                        }
                        else if (opcionEdicion == 3)
                        {
                            cout << "Nueva Memoria RAM (GB): ";
                            cin >> nuevaMemoriaRAM;
                            comp.setMemoriaRam(nuevaMemoriaRAM);
                        }
                        else if (opcionEdicion == 4)
                        {
                            cout << "Nuevo Espacio de memoria (GB): ";
                            cin >> nuevoEspacioMemoria;
                            comp.setEspacioMemoria(nuevoEspacioMemoria);
                        }
                        else if (opcionEdicion == 5)
                        {
                            cout << "Nuevo Procesador: ";
                            cin >> nuevoProcesador;
                            comp.setProcesador(nuevoProcesador);
                        }
                        else if (opcionEdicion == 6)
                        {
                            cout << "Nueva Capacidad de la pila (mAh): ";
                            cin >> nuevaCapacidadPila;
                            comp.setCapacidadPila(nuevaCapacidadPila);
                        }
                        else if (opcionEdicion == 7)
                        {
                            cout << "Nuevo Precio: ";
                            cin >> nuevoPrecio;
                            comp.setPrecio(nuevoPrecio);
                        }
                        else if (opcionEdicion == 8)
                        {
                            cout << "Nuevo Sistema: ";
                            cin >> nuevoSistema;
                            comp.setSistema(nuevoSistema);
                        }
                        else if (opcionEdicion == 9)
                        {
                            int numProgramas;
                            cout << "Numero de programas instalados: ";
                            cin >> numProgramas;
                            comp.getProgramasInstalados().clear();

                            vector<string> nuevosProgramas;
                            for (int i = 0; i < numProgramas; i++)
                            {
                                string programa;
                                cout << "Programa #" << (i + 1) << ": ";
                                cin >> programa;
                                nuevosProgramas.push_back(programa);
                            }
                            comp.setProgramasInstalados(nuevosProgramas);
                        }
                        else if (opcionEdicion == 0)
                        {
                            cout << "Edicion finalizada.\n";
                        }
                        else
                        {
                            cout << "Opcion no valida. Intente de nuevo.\n";
                        }

                    }while (opcionEdicion != 0);

                    cout << "Computadora editada con exito." << endl;

                    break;
            }
        }

                if (!encontrada)
                {
                    cout << "No se encontro una computadora con el numero de serie especificado." << endl;
                }


}
                else if (operacion == 4)
                {
                    int numSerieEliminar;
                    cout << "Ingrese el numero de serie de la computadora a eliminar: ";
                    cin >> numSerieEliminar;

                    auto it = remove_if(computadoras.begin(), computadoras.end(), [numSerieEliminar](Computadora &comp)
                    {
                        return comp.getNumSerie() == numSerieEliminar;
                    });

                    if (it != computadoras.end())
                    {
                        computadoras.erase(it, computadoras.end());
                        cout << "Computadora eliminada con exito." << endl;
                    }
                    else
                    {
                        cout << "No se encontro una computadora con el numero de serie especificado." << endl;
                    }
}


                else if (operacion == 5)
                {
                    int promedioPrecios;

                    if (!computadoras.empty()){
                        int totalPrecios = 0;
                        for (Computadora &comp : computadoras)
                        {
                            totalPrecios += comp.getPrecio();
                        }
                        promedioPrecios = totalPrecios / computadoras.size();
                    }
                    else
                    {
                        cout << "No hay computadoras para calcular el promedio de precios." << endl;
                    }

                    cout << "Promedio de precios de todas las computadoras: " << promedioPrecios << endl;

                }
                else if (operacion == 6)
                {
                    if (!computadoras.empty())
                    {
                        int numComputadorasSeleccionadas;
                        cout << "Ingrese el numero de computadoras para las que desea calcular el promedio de precios: ";
                        cin >> numComputadorasSeleccionadas;

                            vector<int> identificadoresSeleccionados;
                            cout << "Ingrese los identificadores de las computadoras separados por espacio: ";
                            for (int i = 0; i < numComputadorasSeleccionadas; i++)
                            {
                                int identificador;
                                cin >> identificador;
                                identificadoresSeleccionados.push_back(identificador);
                            }

                        int totalPrecios = 0;
                        int numComputadorasEncontradas = 0;

                        for (int identificador : identificadoresSeleccionados)
                        {
                        auto cb = find_if(computadoras.begin(), computadoras.end(), [identificador](Computadora &comp)
                              { return comp.getNumSerie() == identificador; });

                        if (cb != computadoras.end())
                        {
                        totalPrecios += cb->getPrecio();
                        numComputadorasEncontradas++;
                        }
                        }

                        if (numComputadorasEncontradas > 0)
                        {
                            int promedioPrecios = totalPrecios / numComputadorasEncontradas;
                            cout << "Promedio de precios de las computadoras seleccionadas: " << promedioPrecios << endl;
                        }
                        else
                        {
                            cout << "Ninguna de las computadoras seleccionadas fue encontrada en la lista." << endl;
                        }
                    }
                    else
                    {
                    cout << "No hay computadoras para calcular el promedio de precios." << endl;
                    }
                }
                else if (operacion == 7)
                {
                    cout << "Abandonando..." << endl;
                }
            }
            else
            {
                cout << "Opcion invalida" << endl;
            }
            }
            else
            {
            cout << "Entrada invalida. Por favor, ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            }

        }while (operacion != 7);

    return 0;
}
