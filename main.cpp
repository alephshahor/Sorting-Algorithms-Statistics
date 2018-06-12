#include <time.h>
#include <unistd.h>
#include <map>
#include "algoritmos.hpp"
#include "DNI.hpp"

#define MAX_NUMBER 9999999999
#define NUMERO_ALGORITMOS 5
const std::string listaClaves[5] = {"insertionSort", "bubbleSort", "shellSort", "heapSort", "quickSort"};

template <class T>
void modoDemostracion(std::vector<T> v_);

void modoEstadistica(int tamanioSecuencia);
void calcularEstadisticas(int tamanioSecuencia, std::map<std::string,int>& mapaAlgoritmos, int nPruebas, int numeroAlgoritmo);

template <class T>
int ejecutarAlgoritmo(std::vector<T> v_, int numeroAlgoritmo);

int main(){



  int opcion;
  bool stillBucle = true;
  bool modoDem = false;

  while (stillBucle){
  std::cout << "Elija el modo de ejecución del programa: \n";
  std::cout << "1.- Modo demostración\n";
  std::cout << "2.- Modo estadística\n";

  std::cin >> opcion;

  switch(opcion){
    case 1:
    modoDem = true;
    stillBucle = false;
    break;

    case 2:
    modoDem = false;
    stillBucle = false;
    break;

    default:
    std::cout << "Opción no válida\n";
    break;

    }
  }

  int tamanioSecuencia;
  std::cout << "Introduzca el tamaño de la secuencia a ordenar:\n";
  std::cin >> tamanioSecuencia;

  std::vector<DNI> v_;
  for (int indice = 0; indice < tamanioSecuencia; indice++)
  v_.push_back(DNI());

  if (modoDem){ // Modo demostración
    modoDemostracion(v_);
  }else if (!modoDem){ // Modo estadística
    modoEstadistica(tamanioSecuencia);
  }


}

/* Modo estadística*/
void modoEstadistica(int tamanioSecuencia){

  std::cout << "Introduzca el número de pruebas para cada algoritmo:\n";
  int nPruebas = 0;
  std::cin >> nPruebas;

  std::map<std::string,int> mapaAlgoritmos;
  for (int numeroAlgoritmo = 0; numeroAlgoritmo < NUMERO_ALGORITMOS; numeroAlgoritmo++){
    calcularEstadisticas(tamanioSecuencia, mapaAlgoritmos, nPruebas, numeroAlgoritmo);
  }

}

void calcularEstadisticas(int tamanioSecuencia, std::map<std::string,int>& mapaAlgoritmos, int nPruebas, int numeroAlgoritmo){

  int min = MAX_NUMBER; // Inicializamos a un valor grande, pues si inicializacemos a cero no estaríamos
                  // obteniendo el valor mínimo en muchos casos.
  int max = 0;
  long med = 0;

  for (int indice = 0; indice < nPruebas; indice++){  // Se ejec  uta para cada algorimo nPruebas veces.
    std::vector<DNI> v_; // Creación del vector con tamanioSecuencia
    for (int index = 0; index < tamanioSecuencia; index++){
      v_.push_back(DNI());
    }
    int numeroComparaciones = ejecutarAlgoritmo(v_, numeroAlgoritmo);

    if (numeroComparaciones < min){
      min = numeroComparaciones;
    }

    if (numeroComparaciones > max){
      max = numeroComparaciones;
    }

    med += numeroComparaciones;
  }

    med /= nPruebas; // Cálculo de la media.
    std::string nombreClave;
    nombreClave += listaClaves[numeroAlgoritmo];

    std::string claveAux = nombreClave;
    claveAux += "min";
    std::cout << claveAux << ": " << min << "\n";

    claveAux = nombreClave;
    claveAux += "max";
    std::cout << claveAux << ": " << max << "\n";

    claveAux = nombreClave;
    claveAux += "med";
    std::cout << claveAux << ": " << med << "\n\n";
}

template <class T>
int ejecutarAlgoritmo(std::vector<T> v_, int numeroAlgoritmo){

  switch(numeroAlgoritmo){

    case 0:
    return insertionSort(v_,false);
    break;

    case 1:
    return bubbleSort(v_,false);
    break;

    case 2:
    // ¿Valor alpha?
    return shellSort(v_,2,false);
    break;

    case 3:
    return heapSort(v_,false);
    break;

    case 4:
    return quickSort(v_,0,v_.size() - 1,false);
    break;

    default:
    std::cout << "Error al seleccionar el algoritmo\n";
    exit(0);
    break;

  }
}


/* Modo demostración*/

template <class T>
void modoDemostracion(std::vector<T> v_){

  bool stillBucle = true;

  while (stillBucle){
  std::cout << "Introduzca el algoritmo a ejecutar: \n";
  std::cout << "1.- Insertion Sort\n";
  std::cout << "2.- Bubble Sort\n";
  std::cout << "3.- Quick Sort\n";
  std::cout << "4.- Shell Sort\n";
  std::cout << "5.- Heap Sort\n";
  int opcion;
  std::cin >> opcion;


  int numeroComparaciones; // No se utiliza en este caso.

  switch(opcion){

    case 1:
    numeroComparaciones = insertionSort(v_,true);
    stillBucle = false;
    break;

    case 2:
    numeroComparaciones = bubbleSort(v_,true);
    stillBucle = false;
    break;

    case 3:
    numeroComparaciones = quickSort(v_,0,v_.size() - 1,true);
    stillBucle = false;
    break;

    case 4:
    std::cout << "Introduzca el valor alpha:\n";
    int alpha;
    std::cin >> alpha;
    numeroComparaciones = shellSort(v_,alpha,true);
    stillBucle = false;
    break;

    case 5:
    numeroComparaciones = heapSort(v_,true);
    stillBucle = false;
    break;

    default:
    std::cout << "Opción no válida\n";
    break;

    }
  }

}
