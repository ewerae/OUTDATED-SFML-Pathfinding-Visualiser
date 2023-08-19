#pragma once
#include <cmath>
#include <queue>
#include <unordered_set>

#include "Grid.hpp"
#include "GridManager.hpp"

struct Node {
    int x, y;     
    double g, h, f;  
    Node* parent; 

    Node(int x, int y) : x(x), y(y), g(0), h(0), f(0), parent(nullptr) {}
};

struct NodeComparator {
    bool operator()(Node* a, Node* b) const {
        return a->f > b->f;
    }
};

class AStar {
private: 
    sf::RenderWindow& window;
    GridManager& gridManager;
    Grid& grid;

    sf::Vector2i startCoordinates;
    sf::Vector2i objectiveCoordinates;
    sf::Vector2i pathCoordinates;

    sf::Vector2i nullCoordinates;

    sf::Vector2i currentCellCoordinates;

    

    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> openSet;
    std::unordered_set<Node*> closedSet;

    bool isInit;
    bool isFinished;

    Node* goalNode;
    std::vector<Node*> path;

public:
    AStar(sf::RenderWindow& window, GridManager& gridManager, Grid& grid);
    ~AStar();
        
    const sf::Vector2i GetStart() const;
    const sf::Vector2i GetObjective() const;
    
    void SetPathCompleted(bool pathCompleted) { pathCompleted = pathCompleted; }
    int GetCurrentCellCoordinates() const { return currentCellCoordinates.x; }

    Node* CreateStartNode();
    Node* CreateObjectiveNode();

    void AStarInit();
    int GetOpenSetTop();  

    double OctileHeuristic(int x1, int y1, int x2, int y2);
    void AStarSearch();

    std::priority_queue<Node*, std::vector<Node*>, NodeComparator>& GetOpenSet() { return openSet; }
    bool IsInit(){return isInit;}
    bool IsFinished() { return isFinished; }
    void Reset();
    

    // void InitialDirection();
    // void TestAlgorithm();
};
