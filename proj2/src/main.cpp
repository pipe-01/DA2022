#include <fstream>
#include "File.h"
#include "Menu.h"

int main(){

    File file;
    Graph<int> graph;
    file.buildGraph(graph);


    Menu menu;
    menu.showMenu();
    menu.takeInput(graph);

    //graph.printGraph();

    /*int capacity = */
    //cout << capacity;

    return 0;
}