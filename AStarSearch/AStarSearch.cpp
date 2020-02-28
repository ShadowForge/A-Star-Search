//
// Created by Nicholas Tatman on 2/14/20.
//

#include "AStarSearch.h"

AStarSearch::AStarSearch(std::vector<int> startVector): maxQueueSize(1), totalStates(1) {
    //Copies goal vector and sorts it.
    std::vector<int> goalVector;
    goalVector = startVector;
    std::sort(goalVector.begin(), goalVector.end());
    this->goal = goalVector;

    //Adds startNode to the priority queue
    Node * startNode = new Node(startVector,calculateHValue(startVector));
    priQueue.push(startNode);

}

//Does the search using the priority queue
Node * AStarSearch::search() {
    while (!priQueue.empty()) {
        if (priQueue.top()->getData()== goal)
            return priQueue.top();
        Node * curNode = priQueue.top();
        priQueue.pop();
        std::vector<Node*> vectorOfChildren = generateChildren(curNode);
        for (int i = 0; i< vectorOfChildren.size(); i++ ) {
            priQueue.push(vectorOfChildren[i]);
            totalStates++;
        }
        if (maxQueueSize < priQueue.size())
            maxQueueSize = priQueue.size();
    }
    return nullptr;
}

//Creates a vector of child Nodes from the parent
std::vector<Node*> AStarSearch::generateChildren(Node * parentOfChildren) {
    std::vector<Node*> childNodeVector;
    for (int i =0; i < parentOfChildren->getDataSize()-1; i++) {
        for (int j =i+1; j < parentOfChildren->getDataSize(); j++) {
            std::vector<int> childData = reverse(i,j,parentOfChildren->getData());
                Node *childNode = new Node(childData, parentOfChildren, calculateHValue(childData));
                childNodeVector.push_back(childNode);
        }
    }
    return childNodeVector;
}

//Reverse a block in the vector based on the low and high variables
std::vector<int> AStarSearch::reverse(int low, int high, std::vector<int> parentData) {
    while (low < high) {
        int temp = parentData[low];
        parentData[low] = parentData[high];
        parentData[high] = temp;
        low++;
        high--;
    }
    return parentData;
}

//Calculates the h(n) value based on the number of breakpoints/2
//Breakpoints are when the absolute value of the difference between two adjacent numbers in the vector is greater than 1
int AStarSearch::calculateHValue(std::vector<int> dataVector) {
    int numberOfBreakPoints = 0;
    for (int i = 0; i < dataVector.size()-1; i++) {
        if (abs(dataVector.at(i) - dataVector.at(i+1)) != 1)
            numberOfBreakPoints++;
    }
    return numberOfBreakPoints/2;
}

int AStarSearch::getTotalStates() {
    return totalStates;
}

int AStarSearch::getMaxQueueSize() {
    return maxQueueSize;
}
