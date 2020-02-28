#include <iostream>
#include <vector>
#include "Node.h"
#include "AStarSearch.h"
#include <stack>
#include <ctime>
#include <sstream>


int main() {
    std::cout << "Enter an input permutation: " << std::endl;
    std::string input;
    std::getline(std::cin,input);
    std::stringstream inputStream(input);
    std::vector<int>  inputVect;
    while (!inputStream.eof()) { //input
        int n;
        inputStream >> n;
        inputVect.push_back(n);
    }

    std::stack<Node*> myAnswer;
    int total = 0;

// do the A* search
    std::clock_t aStar_startTime = std::clock();
    AStarSearch* aSearch = new AStarSearch(inputVect);
    Node* aSearch_node = aSearch->search();
    if (aSearch_node == nullptr) {
        std::cout << "No possible answer" << std::endl;
        return 1;
    }

    std::clock_t aStar_endTime = std::clock();
    double aStar_elapsedTime = (aStar_endTime-aStar_startTime) / double(CLOCKS_PER_SEC);

    while (aSearch_node->hasParent()) { //Gets Parents of result
        myAnswer.push(aSearch_node);
        aSearch_node = aSearch_node->getParent();
    }

    myAnswer.push(aSearch_node);
    std::cout << "Steps: " << std::endl;
    while (!myAnswer.empty()) { //Prints each step
        myAnswer.top()->printVector();
        myAnswer.pop();
        total++;
    }
    std::cout << "Total Steps Taken: " << total-1 << std::endl;
    std::cout << "Time elapsed in seconds: " << aStar_elapsedTime << std::endl;
    std::cout << "Total number of States: " << aSearch->getTotalStates() << std::endl;
    std::cout << "Max queue size: " << aSearch->getMaxQueueSize() << std::endl;

    return 0;
}