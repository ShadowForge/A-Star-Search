//
// Created by Nicholas Tatman on 2/14/20.
//

#ifndef PROJECT02_NODE_H
#define PROJECT02_NODE_H

#include <vector>
#include <iostream>

class Node {
public:
    Node(std::vector<int> data, int hValue); //hValue is calculated in AStarSearch
    Node(std::vector<int> data, Node* parent, int hValue);

    void printVector();

    std::vector<int> getData();
    int getDataSize();
    int getfValue(); //gValue + hValue
    int getgValue(); //distance from start node

    bool hasParent();
    Node * getParent();

private:
    std::vector<int> data;
    Node * parentNode;
    int gValue; //gValue + hValue
    int fValue; //distance from start node

};


#endif //PROJECT02_NODE_H
