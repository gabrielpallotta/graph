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
      for (int i = 0; i < max_nodes; i++) {
        edges.put(index, i, NULL_WEIGHT_VALUE);
        edges.put(i, index, NULL_WEIGHT_VALUE);
      }
    }

    bool has_node(std::string node) {
      return get_node_iterator(node) != nodes.end();
    }

    void add_edge(std::string node1, std::string node2, int weight) {
      int index1 = get_node_index(node1);
      int index2 = get_node_index(node2);

      if (index1 == -1 || index2 == -1) {
        throw std::invalid_argument("Invalid node name");
      } 
      
      edges.put(index1, index2, weight);
    }

    void remove_edge(std::string node1, std::string node2) {
      int index1 = get_node_index(node1);
      int index2 = get_node_index(node2);
      
      if (index1 == -1 || index2 == -1) {
        throw std::invalid_argument("Invalid node name");
      }

      if (edges.get(index1, index2) == NULL_WEIGHT_VALUE) {
        throw std::invalid_argument("No connection exists between those 2 nodes");
      }

      edges.put(index1, index2, NULL_WEIGHT_VALUE);
    }
    
    friend ostream& operator<<(ostream& os, const Graph& graph);
  private:
    int NULL_WEIGHT_VALUE = -1;
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
  for (int i = 0; i < graph.max_nodes; i++) {
    if (!graph.nodes[i].empty()) {
      cout << graph.nodes[i] << " ";
    }
  }

  cout << endl << endl;

  for (int i = 0; i < graph.max_nodes; i++) {
    for (int j = 0; j < graph.max_nodes; j++) {
      int weight = graph.edges.get(i, j);
      if (weight != graph.NULL_WEIGHT_VALUE) {
        os << graph.nodes[i] << "  " << weight << "  " << graph.nodes[j] << endl; 
      }
    } 
  }

  cout << endl;

  return os;
}

#endif