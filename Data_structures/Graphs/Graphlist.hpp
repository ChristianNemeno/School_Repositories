#ifndef GRAPHLIST_HPP
#define GRAPHLIST_HPP

#include <iostream>
#include <cstdlib>
#include "Vertex.hpp"
using namespace std;

class GraphList {
    Vertex** s_vertices; // Array of pointers to Vertex objects
    int s_edges[100];    // Array to store edges (optional, for additional info)
    int num_vert;        // Number of vertices
    int num_edge;        // Number of edges

public:
    // Constructor
    GraphList() {
        s_vertices = (Vertex**)malloc(10 * sizeof(Vertex*)); // Initial capacity of 10
        num_vert = 0;
        num_edge = 0;
    }

    // Insert a new vertex
    void insertVertex(char name) {
        if (num_vert >= 10) {
            cout << "Vertex limit reached!" << endl;
            return;
        }
        Vertex* newVertex = new Vertex(name);
        s_vertices[num_vert] = newVertex;
        num_vert++;
    }

    // Insert a new edge
    void insertEdge(char u, char v, int edgeValue) {
        int uIndex = -1, vIndex = -1;
        for (int i = 0; i < num_vert; i++) {
            if (s_vertices[i]->getName() == u) uIndex = i;
            if (s_vertices[i]->getName() == v) vIndex = i;
        }

        if (uIndex == -1 || vIndex == -1) {
            cout << "One or both vertices do not exist!" << endl;
            return;
        }

        for (int i = 0; i < s_vertices[uIndex]->getOutCount(); i++) {
            if (s_vertices[uIndex]->getOutEdges()[i] == vIndex) {
                cout << "Not Null" << endl;
                return;
            }
        }

        s_vertices[uIndex]->addOutEdge(vIndex);
        s_vertices[vIndex]->addInEdge(uIndex);
        s_edges[num_edge] = edgeValue;
        num_edge++;
    }

    // Get the number of vertices
    int numVertices() { return num_vert; }

    // Get the number of edges
    int numEdges() { return num_edge; }

    // Get all vertices
    char* vertices() {
        char* vertexNames = (char*)malloc(num_vert * sizeof(char));
        for (int i = 0; i < num_vert; i++) {
            vertexNames[i] = s_vertices[i]->getName();
        }
        return vertexNames;
    }
    char* endVertices(int e) {
    // Returns the two endpoints of edge e as a char array
    char* endpoints = (char*)malloc(2 * sizeof(char));
    for (int i = 0; i < num_vert; i++) {
        Vertex* vertex = s_vertices[i];
        int* outEdges = vertex->getOutEdges();
        for (int j = 0; j < vertex->getOutCount(); j++) {
            if (outEdges[j] == e) {
                endpoints[0] = vertex->getName();
                endpoints[1] = s_vertices[e]->getName();
                return endpoints;
            }
        }
    }
    return NULL; // Return NULL if the edge does not exist
}

char opposite(char v, int e) {
    // For edge incident to vertex v, return the other vertex of the edge
    for (int i = 0; i < num_vert; i++) {
        if (s_vertices[i]->getName() == v) {
            int* outEdges = s_vertices[i]->getOutEdges();
            for (int j = 0; j < s_vertices[i]->getOutCount(); j++) {
                if (outEdges[j] == e) {
                    return s_vertices[e]->getName();
                }
            }
        }
    }
    return '-'; // Return '-' if the edge or vertex does not exist
}

int outDegree(char v) {
    // Returns the number of outgoing edges from vertex v
    for (int i = 0; i < num_vert; i++) {
        if (s_vertices[i]->getName() == v) {
            return s_vertices[i]->getOutCount();
        }
    }
    return 0; // Return 0 if vertex does not exist
}

int inDegree(char v) {
    // Returns the number of incoming edges to vertex v
    for (int i = 0; i < num_vert; i++) {
        if (s_vertices[i]->getName() == v) {
            return s_vertices[i]->getInCount();
        }
    }
    return 0; // Return 0 if vertex does not exist
}

int* outgoingEdges(char v) {
    // Returns an array of all outgoing edges from vertex v
    for (int i = 0; i < num_vert; i++) {
        if (s_vertices[i]->getName() == v) {
            return s_vertices[i]->getOutEdges();
        }
    }
    return NULL; // Return NULL if vertex does not exist
}

int* incomingEdges(char v) {
    // Returns an array of all incoming edges to vertex v
    for (int i = 0; i < num_vert; i++) {
        if (s_vertices[i]->getName() == v) {
            return s_vertices[i]->getInEdges();
        }
    }
    return NULL; // Return NULL if vertex does not exist
}

int removeVertex(char v) {
    // Removes vertex v and all its incident edges
    int vIndex = -1;
    for (int i = 0; i < num_vert; i++) {
        if (s_vertices[i]->getName() == v) {
            vIndex = i;
            break;
        }
    }
    if (vIndex == -1) return 0; // Vertex does not exist

    int removedEdges = 0;

    // Remove all outgoing edges
    for (int i = 0; i < s_vertices[vIndex]->getOutCount(); i++) {
        int target = s_vertices[vIndex]->getOutEdges()[i];
        for (int j = 0; j < s_vertices[target]->getInCount(); j++) {
            if (s_vertices[target]->getInEdges()[j] == vIndex) {
                s_vertices[target]->getInEdges()[j] = -1; // Mark edge as removed
                removedEdges++;
                break;
            }
        }
    }

    // Remove all incoming edges
    for (int i = 0; i < s_vertices[vIndex]->getInCount(); i++) {
        int source = s_vertices[vIndex]->getInEdges()[i];
        for (int j = 0; j < s_vertices[source]->getOutCount(); j++) {
            if (s_vertices[source]->getOutEdges()[j] == vIndex) {
                s_vertices[source]->getOutEdges()[j] = -1; // Mark edge as removed
                removedEdges++;
                break;
            }
        }
    }

    // Remove vertex
    delete s_vertices[vIndex];
    for (int i = vIndex; i < num_vert - 1; i++) {
        s_vertices[i] = s_vertices[i + 1];
    }
    num_vert--;

    return removedEdges; // Return number of removed edges
}

bool removeEdge(int e) {
    // Removes edge e from the graph
    for (int i = 0; i < num_vert; i++) {
        int* outEdges = s_vertices[i]->getOutEdges();
        for (int j = 0; j < s_vertices[i]->getOutCount(); j++) {
            if (outEdges[j] == e) {
                outEdges[j] = -1; // Mark edge as removed
                num_edge--;
                return true; // Edge removed
            }
        }
    }
    return false; // Edge not found
}

};

#endif
