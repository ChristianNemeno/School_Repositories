#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <cstdlib>
using namespace std;

class Vertex {
    char name;         // Name of the vertex
    int* out_edges;    // Array to store outgoing edges
    int* in_edges;     // Array to store incoming edges
    int out_count;     // Count of outgoing edges
    int in_count;      // Count of incoming edges

public:
    // Constructor
    Vertex(char name) {
        this->name = name;
        out_edges = (int*)malloc(10 * sizeof(int)); // Initial capacity of 10
        in_edges = (int*)malloc(10 * sizeof(int));  // Initial capacity of 10
        out_count = 0;
        in_count = 0;
    }

    // Getters
    char getName() { return name; }
    int* getOutEdges() { return out_edges; }
    int* getInEdges() { return in_edges; }
    int getOutCount() { return out_count; }
    int getInCount() { return in_count; }

    // Add an outgoing edge
    void addOutEdge(int e) {
        out_edges[out_count] = e;
        out_count++;
    }

    // Add an incoming edge
    void addInEdge(int e) {
        in_edges[in_count] = e;
        in_count++;
    }
};

#endif
