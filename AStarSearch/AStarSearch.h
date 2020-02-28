//
// Created by Nicholas Tatman on 2/14/20.
//

#ifndef PROJECT02_ASTARSEARCH_H
#define PROJECT02_ASTARSEARCH_H

#include <vector>
#include <queue>
#include "Node.h"
#include <algorithm>

struct compareFValue{ //Says how the priority queue is ordered. Makes it a min heap
    bool operator()(Node* const &n1, Node* const &n2) {
        return n1->getfValue() > n2->getfValue();
    }
};

class AStarSearch {
public:
    AStarSearch(std::vector<int> start);
    Node * search();
    std::vector<Node*> generateChildren(Node * parentOfChildren);
    std::vector<int> reverse(int low, int high, std::vector<int> parentData);
    int calculateHValue(std::vector<int> dataVector);
    int getTotalStates();
    int getMaxQueueSize();
private:
    std::vector<int> goal;
    int totalStates;
    int maxQueueSize;
    std::priority_queue<Node*, std::vector<Node*>, compareFValue> priQueue;
};


#endif //PROJECT02_ASTARSEARCH_H
