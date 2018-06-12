#pragma once
#include <iostream>
#include <vector>

/* Método de impresión que resalta los cambios*/
    template <class T>
    void imprimirVector (std::vector<T> v_){
        for (int indice = 0; indice < v_.size(); indice++)
          std::cout << v_[indice] << " ";
          std::cout << "\n";
    }
/* Método de impresión que resalta los cambios*/
    template <class T>
    void imprimirVector (std::vector<T> v_, int i, int j, T x){
        for (int indice = 0; indice < v_.size(); indice++){
          if (indice == i){
            std::cout << "\033[1;31m" << v_[i] << "\033[0m" << " ";
          }else if (indice == j){
            std::cout << "\033[1;31m" << x << "\033[0m" << " ";
          }else
            std::cout << v_[indice] << " ";
        }
        std::cout << "\n";
    }
/* Método de impresión que resalta los cambios*/
    template <class T>
    void imprimirVector (std::vector<T> v_, int i, int j){
      for (int indice = 0; indice < v_.size(); indice++){
        if (indice == i){
          std::cout << "\033[1;31m" << v_[i] << "\033[0m" << " ";
        }else if (indice == j){
          std::cout << "\033[1;31m" << v_[j] << "\033[0m" << " ";
        }else
          std::cout << v_[indice] << " ";
      }
      std::cout << "\n";
    }

/* Insertion Sort*/

template <class T>
int insertionSort(std::vector<T>& v_, bool imprimir){
  int numeroComparaciones = 0;
  int i = 1;
  while (i < v_.size()){
    T elementoObjetivo = v_[i];
    int j = i-1;

    numeroComparaciones++; // Esto produce una comparación adicional.
    while (j >= 0 && v_[j] > elementoObjetivo){
      v_[j+1] = v_[j];
      if(imprimir)
      imprimirVector(v_,j,j+1,elementoObjetivo);
      j--;
      numeroComparaciones++;
    }

    v_[j+1] = elementoObjetivo;
    i++;

    if (imprimir)
        imprimirVector(v_);

  }

  return numeroComparaciones-1;
}


/* Método swap común*/

template <class T>
void swap (int posA, int posB, std::vector<T>& v_){
  T aux = v_[posA];
  v_[posA] = v_[posB];
  v_[posB] = aux;
}

/* Método bubblesort*/

template <class T>
int bubbleSort(std::vector<T>& v_, bool imprimir){

  int numeroComparaciones = 0;

  bool estaOrdenado = false;
  while (!estaOrdenado){

    estaOrdenado = true;
    for (int indice = 0; indice < v_.size() - 1; indice++){
      numeroComparaciones++;
      if (v_[indice] > v_[indice+1]){
        if (imprimir)
            imprimirVector(v_, indice, indice+1);
        swap(indice,indice+1,v_);
        estaOrdenado = false;
        if(imprimir)
        imprimirVector(v_);
      }
    }

  }

  return numeroComparaciones;
}

/* Método partición para el algoritmo quicksort*/
template <class T>
int particion(std::vector<T>& v_, int lo, int hi, int& contador, bool imprimir){

  T pivote = v_[lo];
  int izq = lo;
  int dch = hi;


  while (izq < dch){
    while (v_[dch] > pivote){
      contador++;
      dch--;
    }

    while ((v_[izq] < pivote) && (izq < dch)){
      izq++;
      contador++;
    }

    if (izq < dch){
      swap(izq, dch, v_);
    }

    if(imprimir)
    imprimirVector(v_,izq,dch);

  }

  if(imprimir)
  imprimirVector(v_,izq,dch);

  swap(izq, dch, v_);

  return dch;

}

/* Algoritmo quicksort*/

template <class T>
void quick_sort(std::vector<T>& v_, int lo, int hi, int& contador, bool imprimir){

  if (lo < hi){
    int pivote = particion(v_,lo,hi,contador,imprimir);
    quick_sort(v_, lo, pivote - 1,contador,imprimir);
    quick_sort(v_, pivote + 1, hi,contador,imprimir);
  }

}

/* Método para establecer el contador del quicksort*/

template <class T>
int quickSort(std::vector<T>& v_, int lo, int hi, bool imprimir){
    int contador = 0;
    quick_sort(v_,lo,hi,contador,imprimir);
    return contador;
}

/* Método para el algoritmo Shellsort*/

template <class T>
void shell_sort(int gap, std::vector<T>& v_, int& contador, bool imprimir){

  for (int indice = gap + 1; indice < v_.size(); indice++){

    T temp = v_[indice];
    int j = indice;

    if(imprimir)
    imprimirVector(v_, j-gap, j, temp);

    contador++;
    while((j >= gap) && (temp < v_[j - gap])){
      if ((j != indice)&&(imprimir))
      imprimirVector(v_, j-gap, j, temp);
      v_[j] = v_[j-gap];
      j = j - gap;
      contador++;
    }

    if (j != indice)
        contador--;

    v_[j] = temp;

  }
}

/* Algoritmo shellsort*/

template <class T>
int shellSort(std::vector<T>& v_, int alpha, bool imprimir){

    int gap = v_.size();
    int nFase = 0;
    int contador = 0;
    while (gap > 1){

      gap = gap / alpha;

      if(imprimir)
      std::cout << "\nFase: " << nFase << "\n";

      shell_sort(gap, v_, contador, imprimir);

      nFase++;
    }

    return contador;
}

/* Método heapify del heapsort */
template <class T>
void heapify(std::vector<T>& v_, int size, int root, bool imprimir, int& contador){

  int largest = root;
  int left = 2*root + 1;
  int right = 2*root + 2;

  contador++;
  if (left < size && v_[left] > v_[largest]){
    largest = left;
  }

  contador++;
  if (right < size && v_[right] > v_[largest]){
    largest = right;
  }


  contador++;
  if (largest != root){
    if(imprimir)
    imprimirVector(v_,largest,root);
    swap(largest,root,v_);
    heapify(v_,size,largest, imprimir, contador);
  }


}

/* Heapsort */
template <class T>
int heapSort(std::vector<T>& v_, bool imprimir){

  int contador = 0;

  for (int elemento = (v_.size() -  1 ) / 2; elemento >= 0; elemento--){
    heapify(v_, v_.size(), elemento, imprimir, contador);
  }

  for (int elemento = (v_.size() - 1); elemento >= 0; elemento--){
    if(imprimir)
    imprimirVector(v_,0,elemento);
    swap(0,elemento,v_);
    heapify(v_, elemento, 0, imprimir, contador);
  }

  return contador;
}
