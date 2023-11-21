
#ifndef DYV_H
#define DYV_H
#include <iostream>
#include <ostream>
#include <vector>
#include <ctime>

template <typename T>
int BusquedaBinaria(T x, std::vector<T>& a, int ini, int fin) {
    if (ini >= fin) {
        return -1;
    } else {
        int medio = (ini + fin) / 2;
        if (a[medio] == x) {
            return medio;
        } else if (a[medio] > x) {
            return BusquedaBinaria(x, a, ini, medio - 1);
        } else {
            return BusquedaBinaria(x, a, medio + 1, fin);
        }
    }
}

template <typename T>
int BusquedaBinariaINV(T x, std::vector<T>& a, int ini, int fin) {
    if (ini > fin) {
        return -1;
    } else {
        int medio = (ini + fin) / 2;
        if (a[medio] == x) {
            return medio;
        } else if (a[medio] > x) {
            return BusquedaBinariaInversa(x, a, medio + 1, fin);
        } else {
            return BusquedaBinariaInversa(x, a, ini, medio - 1);
        }
    }
}

template <typename T>
void Inicializar(std::vector<T>& a, int o) {
    srand(time(NULL));
    switch(o){
    	case(1):
		for (int i = 0; i < a.size(); i++) {
			a[i] = rand() % 20;
	    	}
	    	
	    	break;
    	case(2):
    		
		for (int i = 0; i < a.size(); i++) {
			a[i] = 'A' + rand() % 26;
	    	}

	    	break;
	 case(3):
	 	
		for (int i = 0; i < a.size(); i++) {
			a[i] = (rand() % 100) / 10.0;
	    	}

	    	break;
    }
}

template <typename T>
int Partition(std::vector<T>& a, int ini, int fin){
         T x = a[fin];
         int i = ini;
         for(int j = ini; j < fin; j++){
               if(a[j] <= x){
                     std::swap(a[i], a[j]);
                     i++;
               }
         }
         std::swap(a[i], a[fin]);
         return i;
}

template <typename T>
void QuickSort(std::vector<T>& a, int ini, int fin){
	if(ini < fin){
                 int pivot = Partition(a, ini, fin);
                 QuickSort(a, ini, pivot - 1);
                 QuickSort(a, pivot + 1, fin);
        }
}

template <typename T>
void printVector(std::vector<T> a){	
	for(int i = 0; i < a.size(); i++){
		std::cout << a[i] << " ";
	}
}

#endif
