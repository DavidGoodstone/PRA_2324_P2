#include <iostream>
#include <vector>

using namespace std;
/*La función toma tres parámetros: la capacidad de la mochila, un vector de valores
 asociados a los elementos y un vector de pesos correspondientes a los elementos.
 Devuelve un entero, que es el valor máximo que se puede obtener.*/
int mochila(int capacidad, const vector<int>& valor, const vector<int>& peso) {
  //Obtiene la cantidad de elementos en los vectores valor y peso.
  int n = valor.size();
  // Crea una tabla MEM (programación dinámica) para almacenar los resultados de subproblemas. Inicializa la tabla con todos los valores en 0.
  // Crear la tabla de memorización utilizando un puntero doble
  int** MEM = new int*[n + 1];
  for (int i = 0; i <= n; ++i) {
    MEM[i] = new int[capacidad + 1];
  }
  
  // Inicializar la tabla con valores predeterminados
  for (int i = 0; i <= n; ++i) {
    for (int w = 0; w <= capacidad; ++w) {
      MEM[i][w] = 0;
    }
  }
  //El bucle anidado for itera a través de todos los elementos y capacidades posibles, llenando la tabla MEM basándose
  // en la relación de recurrencia del problema de la mochila.
  for (int i = 1; i <= n; ++i) {
    for (int w = 0; w <= capacidad; ++w) {
      if (peso[i - 1] <= w) {
        /* valor[i - 1]: Es el valor del elemento actual (el i-ésimo elemento) que estamos considerando. */
        /*MEM[i - 1][w - peso[i - 1]]: Representa el valor máximo que se puede obtener considerando los primeros i - 1 elementos
         y una capacidad de mochila reducida por el peso del elemento actual.
         Es decir, estamos simulando colocar el elemento actual en la mochila
         y obtenemos el valor máximo que se puede obtener con la capacidad restante.*/
        //  MEM[i - 1][w]: Representa el valor máximo que se puede obtener sin incluir el elemento actual en la mochila.
        MEM[i][w] = max(valor[i - 1] + MEM[i - 1][w - peso[i - 1]], MEM[i - 1][w]);
      } else {
        MEM[i][w] = MEM[i - 1][w];
      }
    }
  }
  // Devuelve el valor máximo que se puede obtener, que se encuentra en la esquina inferior derecha de la tabla
  return MEM[n][capacidad];
}

vector<int> mochilaVector(int capacidad, const vector<int>& valor, const vector<int>& peso) {
  int n = valor.size();
  
  // Crear la tabla MEM (programación dinámica) para almacenar los resultados de subproblemas.
  int** MEM = new int*[n + 1];
  for (int i = 0; i <= n; ++i) {
    MEM[i] = new int[capacidad + 1];
  }
  
  // Inicializar la tabla con valores predeterminados
  for (int i = 0; i <= n; ++i) {
    for (int w = 0; w <= capacidad; ++w) {
      MEM[i][w] = 0;
    }
  }
  
  // El bucle anidado for itera a través de todos los elementos y capacidades posibles,
  // llenando la tabla MEM basándose en la relación de recurrencia del problema de la mochila.
  for (int i = 1; i <= n; ++i) {
    for (int w = 0; w <= capacidad; ++w) {
      if (peso[i - 1] <= w) {
        MEM[i][w] = max(valor[i - 1] + MEM[i - 1][w - peso[i - 1]], MEM[i - 1][w]);
      } else {
        MEM[i][w] = MEM[i - 1][w];
      }
    }
  }
  
  // Construir el vector de solución
  vector<int> solucion(n, 0);  //Vector que almacena la solución
  int i = n;  // Índice del último elemento del vector valor
  int w = capacidad;
  while (i > 0 && w > 0) {
    if (MEM[i][w] != MEM[i - 1][w]) {
      solucion[i - 1] = 1; // El elemento i fue seleccionado
      w -= peso[i - 1];
    }
    --i;
  }
  return solucion;
}


int main() {
  vector<int> valor ={10,20,15,20};
  vector<int> peso ={1,3,2,4};
  int capacidad = 5;
  
  int resultado = mochila(capacidad, valor, peso);
  
  cout << "El valor máximo que se puede obtener es: " << resultado << endl;
  
  // Llamada a la función mochila para obtener el vector de decisiones (solución)
  vector<int> vector = mochilaVector(capacidad, valor, peso);
  
  // Imprime la solución
  cout << "Vector de soluciones (1 si se selecciona, 0 si se descarta): { ";
  for (int i : vector) {
    cout << i << " ";
  }
  cout << "}" << endl;
  
  return 0;
}