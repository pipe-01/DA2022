#include <vector>
#include <list>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int capacity; // An integer capacity
        int duration;
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int capacity, int duration);

    // Depth-First Search: example implementation
    int dfs(int v);

    // Breadth-First Search: example implementation
    void bfs(int v);

    // ----- Functions to implement in this class -----
    int outDegree(int v);
    int connectedComponents();
    int giantComponent();
    void dfshelper(int v, list<int>& order);
    list<int> topologicalSorting();
    vector<int> bfshelper(int a);
    int distance(int a, int b);
    int diameter();
    bool hasCycle();
    void printGraph();
};

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int capacity, int duration) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, capacity, duration});
    if (!hasDir) nodes[dest].adj.push_back({src, capacity, duration});
}

// Depth-First Search: example implementation
int Graph::dfs(int v) {
    int size = 1;
    //cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            size += dfs(w);
    }
    return size;
}

// Depth-First Search: example implementation
void Graph::bfs(int v) {
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Contando diferentes somas de pares
// TODO
int Graph::outDegree(int v) {
    if(v>(int) nodes.size()-1 || v<1) return -1;
    return nodes.at(v).adj.size();
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO
int Graph::connectedComponents() {
    int result=0;
    for(unsigned int i=1; i<nodes.size(); i++){
        if(!nodes[i].visited) {
            dfs(i);
            result++;
        }
    }
    return result;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    int max=0;
    for(unsigned int i=1; i<nodes.size(); i++){
        if(!nodes[i].visited) {
            int search = dfs(i);
            if(search>max) max = search;
        }
    }
    return max;
}


// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
void Graph::dfshelper(int v, list<int>& order) {
    nodes[v].visited=true;
    for(auto node: nodes[v].adj){
        if(!nodes[node.dest].visited){
            dfshelper(node.dest, order);
        }
    }
    order.push_front(v);
}

list<int> Graph::topologicalSorting() {
    list<int> order;

    for(unsigned int i=1; i<nodes.size(); i++){
        if(!nodes[i].visited){
            dfshelper(i, order);
        }
    }
    return order;
}

// ----------------------------------------------------------
// Exercicio 4: Distancias em grafos nao pesados
// ----------------------------------------------------------

// ..............................
// a) Distancia entre dois nos
// TODO
vector<int> Graph::bfshelper(int a) {
    vector<int> distances(nodes.size(), -1);
    distances[a] = 0;
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(a);
    nodes[a]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                distances[w] = distances[u] + 1;
            }
        }
    }
    return distances;
}

int Graph::distance(int a, int b) {
    return bfshelper(a)[b];
}

// ..............................
// b) Diametro
// TODO
int Graph::diameter() {
    if(this->connectedComponents()>1) return -1;
    int diameter = 0;
    for(unsigned int i=1; i<nodes.size(); i++){
        vector<int> tmp = bfshelper(i);
        for(unsigned int j=0; j<tmp.size(); j++){
            if(tmp[j]>diameter) diameter=tmp[j];
        };
    }
    return diameter;
}

void Graph::printGraph(){
    for(unsigned int i = 1; i < nodes.size(); i++){
        std::cout << i;
        for(auto edge : nodes[i].adj){
            cout << " -> " << edge.dest;
        }
        std::cout << std::endl;
    }
}