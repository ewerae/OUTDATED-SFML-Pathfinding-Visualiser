#pragma once

#include "Grid.hpp"
#include "GridManager.hpp"


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

        bool pathCompleted;

    public:
        AStar(sf::RenderWindow& window, GridManager& gridManager, Grid& grid);
        ~AStar();
        
        const sf::Vector2i GetStart() const;
       const sf::Vector2i GetObjective() const;
       bool GetPathCompleted(){return pathCompleted;}
       void SetPathCompleted(bool pathCompleted){pathCompleted = pathCompleted;}
       int GetCurrentCellCoordinates() const{ return currentCellCoordinates.x;}
       void InitialDirection();
        void TestAlgorithm();
        // sf::Vector2i GetPathCoordinates();
        // void SetPathCoordinates(int row, int column);
       
};