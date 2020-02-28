//
// Created by Nicholas Tatman on 2/14/20.
//

#include "Node.h"

Node::Node(std::vector<int> data, int hValue):
    data(data),
    gValue(0),
    parentNode(NULL),
    fValue(hValue+gValue) {
}

Node::Node (std::vector<int> data, Node * parentNode, int hValue):
    data(data),
    parentNode(parentNode),
    gValue(parentNode->getgValue()+1),
    fValue(hValue+gValue) {
}

//For readability in AStarSearch
int Node::getDataSize() {
    return data.size();
}

std::vector<int> Node::getData() {
    return data;
}

int Node::getfValue() {
    return fValue;
}

int Node::getgValue() {
    return gValue;
}

Node * Node::getParent() {
    return parentNode;
}

bool Node::hasParent() {
    if (parentNode==NULL)
        return false;
    return true;
}

void Node::printVector() {
    for (int i = 0; i < data.size(); i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}


