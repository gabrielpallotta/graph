#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <vector>

#include "sparse_matrix.hpp"

/**
 * Implementation of a Graph data structure in C++, using sparse matrix
 */
class Graph
{
  public:
    Graph (int max_nodes) {
      nodes = vector<std::string>(max_nodes, nullptr);
      edges = SparseMatrix<int>(0);
    }

    add_node(std::string node) {

    }

    remove_node(std::string node) {

    }

    add_edge(std::string node1, std::string node2) {

    }

    remove_edge(std::string node, std::string node2) {

    }
    
    friend ostream& operator<<(ostream& os, const Graph& graph);
  private:
    vector<std::string> nodes;
    SparseMatrix<int> edges;

    get_node_index(std::string node_name) {

    }

};

ostream& operator<<(ostream& os, const Graph& graph)
{
  os << "Grafo";
  return os;
}

#endif