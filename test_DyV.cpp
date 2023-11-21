#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include "DyV.h"

using namespace std;

int main(){
  std::vector<int> a(20);
  Inicializar(a, 1);
  int x = 5;
  
  std::vector<char> b(20);
  Inicializar(b, 2);
  char y = 'D';
  
  std::vector<float> c(20);
  Inicializar(c, 3);
  float z = 3.3;
  
  auto starta = std::chrono::system_clock::now();
  
  std::cout << "\nEl vector GENERADO es: ";
  printVector(a);
  QuickSort(a, 0, a.size());
  std::cout << "\nEl vector ORDENADO es: ";
  printVector(a);
  int resulta = BusquedaBinaria(x, a, 0, a.size() - 1);
  if (resulta == -1) {
    std::cout << "\nEl elemento " << x << " no se encuentra en el vector.";
  } else {
    std::cout << "\nEl elemento " << x << " se encuentra en la posición " << resulta << " del vector.";
  }
  
  auto enda = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> durationa = enda - starta;
  std::cout <<"\nTiempo para vector tipo int = " << durationa.count() << "s" << std::endl;
  
  auto startb = std::chrono::system_clock::now();
  
  
  std::cout << "\nEl vector GENERADO es: ";
  printVector(b);
  QuickSort(b, 0, b.size());
  std::cout << "\nEl vector ORDENADO es: ";
  printVector(b);
  int resultb = BusquedaBinaria(y, b, 0, b.size() - 1);
  if (resultb == -1) {
    std::cout << "\nEl elemento " << y << " no se encuentra en el vector.";
  } else {
    std::cout << "\nEl elemento " << y << " se encuentra en la posición " << resultb << " del vector.";
  }
  
  auto endb = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> durationb = endb - startb;
  std::cout << "\nTiempo para vector tipo char = " << durationb.count() << "s" << std::endl;
  
  auto startc = std::chrono::system_clock::now();
  
  std::cout << "\nEl vector GENERADO es: ";
  printVector(c);
  QuickSort(c, 0, c.size());
  std::cout << "\nEl vector ORDENADO es: ";
  printVector(c);
  int resultc = BusquedaBinaria(z, c, 0, c.size() - 1);
  if (resultc == -1) {
    std::cout << "\nEl elemento " << z << " no se encuentra en el vector.";
  } else {
    std::cout << "\nEl elemento " << z << " se encuentra en la posición " << resultc << " del vector.";
  }
  
  auto endc = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> durationc = endc - startc;
  std::cout << "\nTiempo para vector tipo float = " << durationc.count() << "s" << std::endl;
  
  return 0;
}