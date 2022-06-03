#include <fstream>
#include "File.h"
#include "Menu.h"

int main(){

    File file;
    Graph<int> graphCap;
    Graph<int> graphDur;
    file.buildGraphCap(graphCap);
    //file.buildGraphDur(graphDur);


    Menu menu;
    menu.showMenu();
    menu.takeInput(graphCap, graphDur);

    //graph.printGraph();

    /*int capacity = */
    //cout << capacity;

    return 0;
}