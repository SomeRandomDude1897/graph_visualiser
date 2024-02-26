#include <iostream>
#include "GraphBuilder.h"
using namespace std;

int main()
{
    Graph* mygraph = new Graph();
    mygraph -> Load("infile.txt");
    return 0;
}