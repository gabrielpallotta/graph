#include <stdlib.h>
#include <iostream>

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
    cout << graph << endl;

    cout << "1 - Inserir vertice" << endl;
    cout << "2 - Remover vertice" << endl;
    cout << "3 - Inserir aresta" << endl;
    cout << "4 - Remover aresta" << endl << endl;

    cout << "Digite uma opcao: ";

    int option;
    cin >> option;

    int weight;
    string name;
    string other_name;

    cout << endl;
    switch (option) {
      case 1:
        cout << "Digite o nome do vertice que deseja inserir: ";
        cin >> name;
        cout << endl;
        try {
          graph.add_node(name);
          cout << "Vertice inserido com sucesso" ;
        } catch (invalid_argument e) {
          cout << "Vertice ja existe no grafo";
        } catch (length_error e) {
          cout << "Numero de vertices limite excedido";
        }
        break;
      case 2:
        cout << "Digite o nome do vertice que deseja remover: ";
        cin >> name;
        cout << endl;
        try {
          graph.remove_node(name);
          cout << "Vertice removido com sucesso";
        } catch (invalid_argument e) {
          cout << "Vertice nao existe no grafo";
        }
        break;
      case 3:
        cout << "Digite o nome do primeiro vertice: ";
        cin >> name;
        cout << "Digite o nome do segundo vertice: ";
        cin >> other_name;
        cout << "Digite o peso da aresta: ";
        cin >> weight;
        cout << endl;
        try {
          graph.add_edge(name, other_name, weight);
          cout << "Aresta inserida com sucesso";
        } catch (invalid_argument e) {
          cout << "Erro ao inserir aresta";
        }
        break;
      case 4:
        cout << "Digite o nome do primeiro vertice: ";
        cin >> name;
        cout << "Digite o nome do segundo vertice: ";
        cin >> other_name;
        cout << endl;
        try {
          graph.remove_edge(name, other_name);
          cout << "Aresta removida com sucesso";
        } catch (invalid_argument e) {
          cout << "Erro ao remover aresta";
        }
        break;
    }
    cout << endl << endl;
    cout << "Pressione qualquer tecla para continuar...";
    cin.sync();
    cin.ignore();
  }
}
