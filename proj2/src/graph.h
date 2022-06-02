#ifndef PROJETODA3_GRAPH_H
#define PROJETODA3_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <stack>
#include "MutablePriorityQueue.h"

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<int>::max()

/************************* Vertex  **************************/

template <class T>
class Vertex {
    T info;                // contents
    std::vector<Edge<T> > adj;  // outgoing edges
    bool visited;          // auxiliary field
    double dist = 0;
    Vertex<T> *path = nullptr;
    int queueIndex = 0; 		// required by MutablePriorityQueue
    int grau = 0;
    int earliestStart = 0;


    void addEdge(Vertex<T> *dest, double w);

public:
    Vertex(T in);
    bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
    T getInfo() const;
    double getDist() const;
    Vertex *getPath() const;
    friend class Graph<T>;
    friend class MutablePriorityQueue<Vertex<T>>;
};


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
    adj.push_back(Edge<T>(d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
    return this->dist > vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
    return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
    return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
    return this->path;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
    Vertex<T> * dest;      // destination vertex
    double weight;         // edge weight
    int flux;
    double resCap;
public:
    Edge(Vertex<T> *d, double w, int flux = 0);
    friend class Graph<T>;
    friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w, int flux): dest(d), weight(w), resCap(w), flux(flux) {}


/*************************** Graph  **************************/

template <class T>
class Graph {
    std::vector<Vertex<T> *> vertexSet;    // vertex set

    //Fp05
    Vertex<T> * initSingleSource(const T &orig);
    bool relax(Vertex<T> *v, Vertex<T> *w, double weight);
    double ** W = nullptr;   // dist
    int **P = nullptr;   // path
    int findVertexIdx(const T &in) const;

public:
    ~Graph();
    Vertex<T> *findVertex(const T &in) const;
    bool addVertex(const T &in);
    bool addEdge(const T &sourc, const T &dest, double w);
    int getNumVertex() const;
    std::vector<Vertex<T> *> getVertexSet() const;

    // Single-source shortest path - Greedy
    void dijkstraShortestPath(const T &s);
    void unweightedShortestPath(const T &s);

    // FP03B - Single-shource shortest path - Dynamic Programming - Bellman-Ford
    void bellmanFordShortestPath(const T &s); //TODO...
    std::vector<T> getPath(const T &origin, const T &dest) const; //TODO...

    // FP03B - All-pair shortest path -  Dynamic Programming - Floyd-Warshall
    void floydWarshallShortestPath(); //TODO...
    std::vector<T> getfloydWarshallPath(const T &origin, const T &dest) const; //TODO...

    /**
    * este método recebe input do utilizador, o que lhe permite escolher uma opção do menu
    * @param src conteúdo do vértice de partida
    * @param destin conteúdo do vértice de chegada
    * @return void
    */
    void widestPath(T &src, T &destin);
    /**
    * este método permite atualizar o atributo dist de cada vértice
    * @param *v apontador para um vértice
    * @param *w apontador para outro vértice
    * @param weight peso da aresta entre os dois vértices
    * @return TRUE if the target vertex (w) was relaxed
    * @return FALSE otherwise
    */
    bool relaxWidestPath(Vertex<T> *v, Vertex<T> *w, double weight);
    /**
    * este método permite calcular o caminho mais curto (em termos de número de nós) desde um nó até outro do grafo
    * @param src conteúdo do vértice de partida
    * @param destin conteúdo do vértice de chegada
    * @return void
    */
    void bfs(T &src, T &destin);
    /**
    * este método permite calcular o peso do caminho crítico do grafo
    * @return int que representa o peso do caminho crítico
    */
    int cpmES();

    int edmondKarpFlux(T &src, T &destin);
    Graph<T> residGraph();
    void setFlux(const T &sourc, const T &dest, int f);
    void setResCap(const T &sourc, const T &dest, double cap);

};


template <class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template <class T>
std::vector<Vertex<T> *> Graph<T>::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
template <class T>
int Graph<T>::findVertexIdx(const T &in) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->info == in)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
    if (findVertex(in) != nullptr)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}


/**************** Single Source Shortest Path algorithms ************/

/**
 * Initializes single source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
 */
template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
    for(auto v : vertexSet) {
        v->dist = INF;
        v->path = nullptr;
    }
    auto s = findVertex(origin);
    s->dist = 0;
    return s;
}

/**
 * Analyzes an edge in single source shortest path algorithm.
 * Returns true if the target vertex was relaxed (dist, path).
 * Used by all single-source shortest path algorithms.
 */
template<class T>
inline bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
    if (v->dist + weight < w->dist) {
        w->dist = v->dist + weight;
        w->path = v;
        return true;
    }
    else
        return false;
}

template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex<T>> q;
    q.insert(s);
    while( ! q.empty() ) {
        auto v = q.extractMin();
        for(auto e : v->adj) {
            auto oldDist = e.dest->dist;
            if (relax(v, e.dest, e.weight)) {
                if (oldDist == INF)
                    q.insert(e.dest);
                else
                    q.decreaseKey(e.dest);
            }
        }
    }
}

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
    auto s = initSingleSource(orig);
    std::queue< Vertex<T>* > q;
    q.push(s);
    while( ! q.empty() ) {
        auto v = q.front();
        q.pop();
        for(auto e: v->adj)
            if (relax(v, e.dest, 1))
                q.push(e.dest);
    }
}


template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
    // TODO implement this
}

template<class T>
std::vector<T> Graph<T>::getPath(const T &origin, const T &dest) const{
    std::vector<T> res;
    Vertex<T> *a = findVertex(dest);
    while (a != nullptr){
        res.push_back(a->info);
        a = a->path;
    }
    std::reverse(res.begin(), res.end());
    return res;
}


/**************** All Pairs Shortest Path  ***************/

template <class T>
void deleteMatrix(T **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

template <class T>
Graph<T>::~Graph() {
    deleteMatrix(W, vertexSet.size());
    deleteMatrix(P, vertexSet.size());
}

template<class T>
void Graph<T>::floydWarshallShortestPath() {
    // TODO implement this
}


template<class T>
std::vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{
    std::vector<T> res;
    // TODO implement this
    return res;
}

template<class T>
void Graph<T>::widestPath(T &src, T &destin) {
    for (auto v: vertexSet){
        v->dist = -1;
        v->path = nullptr;
    }
    auto srcVertex = findVertex(src);
    srcVertex->dist = INF;

    MutablePriorityQueue<Vertex<T>> q;
    q.insert(srcVertex);
    while (!q.empty()){
        auto vertex = q.extractMin();
        for (auto e: vertex->adj){
            auto oldDist = e.dest->dist;
            if (relaxWidestPath(vertex, e.dest, e.weight)){
                if (oldDist == -1) {
                    q.insert(e.dest);
                }
                else {
                    q.decreaseKey(e.dest);
                }
            }
        }
    }

    std::vector<T> path = getPath(src, destin);

    for (int i = 0; i < path.size(); i++){
        std::cout << path[i] << std::endl;
    }
}

template <class T>
bool Graph<T>::relaxWidestPath(Vertex<T> *v, Vertex<T> *w, double weight){
    if (std::min(v->dist, weight) > w->dist){
        w->dist = std::min(v->dist, weight);
        w->path = v;
        return true;
    }
    else{
        return false;
    }
}


template <class T>
void Graph<T>::bfs(T &src, T &destin){
    for (auto v: vertexSet){
        v->visited = false;
        v->dist = INF;
        v->path = nullptr;
    }

    auto srcVertex = findVertex(src);
    srcVertex->visited = true;
    srcVertex->dist = 0;
    int cap = 0;

    MutablePriorityQueue<Vertex<T>> q;
    q.insert(srcVertex);

    while (!q.empty()){
        Vertex<T> *vertex = q.remove();
        for (auto &e: vertex->adj){
            if (!e.dest->visited){
                q.insert(e.dest);
                e.dest->visited = true;
                e.dest->path = vertex;
            }
        }
    }

    std::vector<T> path = getPath(src, destin);

    for (int i = 0; i < path.size(); i++){
        std::cout << path[i] << std::endl;
    }

}

template <class T>
int Graph<T>::cpmES(){

    int durMin;
    MutablePriorityQueue<Vertex<T>> q;

    for (auto v: vertexSet){
        v->grau = 0;
        v->earliestStart = 0;
        v->path = nullptr;

        for (auto e: v->adj){
            e.dest->grau++;
        }
    }

    for (auto v: vertexSet){
        if (v->grau == 0){
            q.insert(v);
        }
    }

    durMin = -1;

    while (!q.empty()){
        Vertex<T> *v = q.remove();
        if (durMin < v->earliestStart){
            durMin = v->earliestStart;
        }

        for (auto e: v->adj){
            if (e.dest->earliestStart < v->earliestStart + e.weight){
                e.dest->earliestStart = v->earliestStart + e.weight;
                e.dest->path = v;
            }
            e.dest->grau--;

            if (e.dest->grau == 0){
                q.insert(e.dest);
            }
        }
    }



    std::cout << durMin;
    return durMin;

}

template <class T>
int Graph<T>::edmondKarpFlux(T &src, T &destin) {
    int maxFlux = 0;
    Vertex<T> origin(src);
    std::vector<T> path;
    int resCap = INF;
    Graph<T> residualGraph;

    //set fluxes to 0
    for (auto v: vertexSet){
        for(auto &edge: v->adj){
            edge.flux = 0;
        }
    }

    //initialize residual graph
    residualGraph = residGraph();
    residualGraph.bfs(src, destin);
    path = residualGraph.getPath(src, destin);
    Vertex<T> dest = *residualGraph.findVertex(destin);

    while(dest.visited){
        std::cout << "TESTE\n" << std::endl;
        for (unsigned int i = 0; i < path.size() - 1; i++){
            for(auto edge : residualGraph.findVertex(path[i])->adj){
                if (edge.dest->info == residualGraph.findVertex(path[i+1])->info){
                    resCap = std::min(resCap, (int)edge.resCap);
                }
            }
        }

        for (unsigned int i = 0; i < path.size() - 1; i++){
            for(auto &edge : findVertex(path[i])->adj){
                if (edge.dest->info == findVertex(path[i+1])->info){
                    edge.flux += resCap;
                    //std::cout << edge.flux << std::endl;
                }
            }
        }

        residualGraph = residGraph();
        residualGraph.bfs(src, destin);
        path = residualGraph.getPath(src, destin);
        dest = *residualGraph.findVertex(destin);

    }

    origin = *findVertex(src);

    for(auto edge: origin.adj){
        maxFlux += edge.flux;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << maxFlux << std::endl;
    return maxFlux;
}

template<class T>
Graph<T> Graph<T>::residGraph() {
    Graph<T> residualGraph;
    //add vertices
    for (auto v: vertexSet){
        residualGraph.addVertex(v->info);
    }
    //add edges
    for (auto v: vertexSet){
        for (auto &edge: v->adj){
            if (edge.flux == 0){
                residualGraph.addEdge(v->info, edge.dest->info, edge.weight);
            }
            else if(edge.resCap - edge.flux > 0){
                residualGraph.addEdge(v->info, edge.dest->info, edge.weight);
                residualGraph.setResCap(v->info, edge.dest->info, edge.resCap);
                residualGraph.setFlux(v->info, edge.dest->info, edge.flux);
                residualGraph.setResCap(v->info, edge.dest->info, edge.weight - edge.flux);
            }
        }
    }

    for (auto v: vertexSet){
        for (auto &edge: v->adj){
            if(edge.flux > 0){
                residualGraph.addEdge(edge.dest->info, v->info, edge.weight);
                residualGraph.setResCap(edge.dest->info, v->info, edge.flux);
                residualGraph.setFlux(edge.dest->info, v->info, edge.weight - edge.flux);
            }
        }
    }

    return residualGraph;
}

template <class T>
void Graph<T>::setFlux(const T &sourc, const T &dest, int f){
    auto src = findVertex(sourc);
    for(auto &e : src->adj){
        if(e.dest->info == dest){
            e.flux = f;
        }
    }
}

template <class T>
void Graph<T>::setResCap(const T &sourc, const T &dest, double cap){
    auto src = findVertex(sourc);
    for(auto &e : src->adj){
        if(e.dest->info == dest){
            e.resCap = cap;
        }
    }
}


#endif //PROJETODA3_GRAPH_H


/*
int cap[nodes.size()];
bool pai[nodes.size()];

for (int i = 1; i < nodes.size(); i++){
cap[i] = -1;
pai[i] = false;
}

cap[src] = INT_MAX;

MinHeap<int, int> heap(nodes.size(), - 1);

heap.insert(src, -cap[src]);

while (heap.getSize() > 0){
pair<int, int> pair = heap.removeMin();
int vertex = pair.first;
if (cap[vertex] == -1){
break;
}

for (auto edge: nodes[vertex].adj){
if (min(cap[vertex], edge.capacity) > cap[edge.dest]){
cap[edge.dest] = min(cap[vertex], edge.capacity);
pai[edge.dest] = vertex;
heap.decreaseKey(edge.dest, -cap[edge.dest]);
}
}
}*/