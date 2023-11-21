#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void inicializar(int** matrix, vector<int> a, int m){
  for(int i = 0; i < a.size(); i++){
    matrix[i][0] = 0;
    for(int j = 1; j < m; j++){
      matrix[i][j] = -1;
    } 
  }  
}

void print(int** matrix, vector<int> a, int m){
  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < m; j++){
      cout << matrix[i][j] << "\t";
    } 
    cout << "\n" << endl;
  } 
}

int cambio(vector<int> a, int** &matrix, int tam, int m){
  if(m == 0){
    return 0;
  }
  
  if(matrix[tam][m] > 0){
    return matrix[tam][m];
  }
  
  int minM = numeric_limits<int>::max();
  
  for(int i = 0; i <= tam; i++){
    if(a[i] <= m){
      minM = min(minM, 1 + cambio(a, matrix, tam, m - a[i]));
      matrix[i][m] = minM;
    }
  }
  
  return minM;
}

int main(){
  vector<int> a = {1, 4, 6};
  int m;
  
  cout << "¿Con cuántas monedas quieres hacer el cambio?: ";
  cin >> m;
  
  int** matrix = new int*[a.size()];
  for(int i=0; i < a.size(); i++){
    matrix[i] = new int[m + 1];
  }
  
  inicializar(matrix, a, m + 1);
  cout << "\nMatriz ORIGINAL:" << endl;
  print(matrix, a, m + 1);
  
  int result = cambio(a, matrix, a.size() - 1, m);
  
  cout << "Matriz MODIFICADA:" << endl;
  print(matrix, a, m + 1);
  
  cout << "El valor mínimo de monedas a devolver es de "<< result << endl;

  return 0;
}