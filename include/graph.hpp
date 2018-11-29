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
      this->max_nodes = max_nodes;
      nodes = vector<std::string>(max_nodes, "");
      edges = SparseMatrix<int>(NULL_WEIGHT_VALUE);
    }

    void add_node(std::string node) {
      if (node.empty()) {
        throw std::invalid_argument("Invalid node name.");
      }

      if (has_node(node)) {
        throw std::invalid_argument("Repeated node name.");
      }

      for (int i = 0; i < max_nodes; i++) {
        if (nodes[i] ==  "") {
          nodes[i] = node;
          return;
        }
      }
      
      throw std::length_error("Exceeded node limit.");
    }

    void remove_node(std::string node) {
      if (node.empty()) {
        throw std::invalid_argument("Invalid node name.");
      }
      
      int index = get_node_index(node);

      if (index == -1) {
        throw std::invalid_argument("Node not on graph.");
      } 
      
      nodes[index] = "";
    }

    bool has_node(std::string node) {
      return get_node_iterator(node) != nodes.end();
    }

    void add_edge(std::string node1, std::string node2, int weight) {

    }

    void remove_edge(std::string node, std::string node2) {

    }
    
    friend ostream& operator<<(ostream& os, const Graph& graph);
  private:
    int max_nodes;
    vector<std::string> nodes;
    SparseMatrix<int> edges;

    vector<std::string>::iterator get_node_iterator(std::string node) {
      return std::find(nodes.begin(), nodes.end(), node);
    }

    int get_node_index(std::string node) {
      vector<std::string>::iterator it = get_node_iterator(node);
      if (it == nodes.end()) {
         return -1;
      } else {
        std::distance(nodes.begin(), it);
      }
    }
};

ostream& operator<<(ostream& os, const Graph& graph)
{
  os << "Grafo";
  return os;
}

#endif