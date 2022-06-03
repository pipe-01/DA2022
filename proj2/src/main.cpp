#include <fstream>
#include "File.h"
#include "Menu.h"

int main(){

    Graph<int> graphCap;
    Graph<int> graphDur;

    Menu menu;
    menu.showMenu();
    menu.takeInput(graphCap, graphDur);

    //graph.printGraph();

    /*int capacity = */
    //cout << capacity;

    return 0;
}