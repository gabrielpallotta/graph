#include <iostream>
#include <stdlib.h>

#ifdef _WIN32
  #define CLEAR_CMD "cls"
#elif _WIN64
  #define CLEAR_CMD "cls"
#elif __linux__
  #define CLEAR_CMD "clear"
#endif

#include "graph.hpp"

using namespace std;

int main()
{
  cout << "Digite o tamanho maximo do grafo: ";

  int n;
  cin >> n;

  Graph graph(n);

  while (true) {
    system(CLEAR_CMD);
    cout << "Grafo:" << endl;
    // graph.print(cout);
    cout << graph << endl;

    cout << "1 - Inserir vertice" << endl;
    cout << "2 - Remover vertice" << endl;
    cout << "3 - Inserir aresta" << endl;
    cout << "4 - Remover aresta" << endl;

    cout << "Digite uma opcao: ";

    int option;
    cin >> option;

    int value;
    switch (option) {
      case 1:
        // cout << "Digite o valor que deseja inserir: ";
        // cin >> value;
        // cout << endl;
        // try {
        //   graph.add(value, value);
        //   cout << "Valor inserido com sucesso" ;
        // } catch (invalid_argument e) {
        //   cout << "Valor ja existe na arvore";
        // }
        break;
      case 2:
        // cout << "Digite o valor que deseja remover: ";
        // cin >> value;
        // cout << endl;
        // try {
        //   graph.remove(value);
        //   cout << "Valor removido com sucesso";
        // } catch (invalid_argument e) {
        //   cout << "Valor nao existe na arvore";
        // }
        break;
      case 3:
        // cout << "Digite o valor que deseja consultar: ";
        // cin >> value;
        // cout << endl;
        // int graph_value = graph.get(value);
        // if (graph_value) {
        //   cout << "Valor encontrado: " << graph_value;
        // } else {
        //   cout << "Valor nao encontrado na arvore";
        // }
        break;
      case 4:
        break;
    }
    cout << endl << endl;
    cout << "Pressione qualquer tecla para continuar...";
    cin.sync();
    cin.ignore();
  }
}
