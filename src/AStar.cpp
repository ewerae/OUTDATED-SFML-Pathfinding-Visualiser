#include "AStar.hpp"

AStar::AStar(sf::RenderWindow& window, GridManager& gridManager, Grid& grid) 
    : window(window), gridManager(gridManager), grid(grid), pathCompleted(false) {
}

AStar::~AStar() {

}

const sf::Vector2i AStar::GetStart()const {
    if(!gridManager.GetSquareStateCoordinates(SquareState::Start).empty()){
        return gridManager.GetSquareStateCoordinates(SquareState::Start)[0];
    }
    return nullCoordinates;
}

const sf::Vector2i AStar::GetObjective() const{
    if(!gridManager.GetSquareStateCoordinates(SquareState::Objective).empty()){
        return gridManager.GetSquareStateCoordinates(SquareState::Objective)[0];
    }
    return nullCoordinates;
}



void AStar::InitialDirection(){
    if(GetStart().x < GetObjective().x){
        currentCellCoordinates = sf::Vector2i(GetStart().x, GetStart().y);
    } else if(GetStart().x > GetObjective().x){
        currentCellCoordinates = sf::Vector2i(GetStart().x, GetStart().y);
    }
}


void AStar::TestAlgorithm() {
    if(currentCellCoordinates.x != GetObjective().x){
        if(currentCellCoordinates.x < GetObjective().x - 1){
            currentCellCoordinates.x++;
            grid.SetGrid(currentCellCoordinates.y, currentCellCoordinates.x, SquareState::Path);
            gridManager.StoreCoordinates(sf::Vector2i(currentCellCoordinates.x,currentCellCoordinates.y), SquareState::Path);
        } else if(currentCellCoordinates.x > GetObjective().x + 1){
            currentCellCoordinates.x--;
            grid.SetGrid(currentCellCoordinates.y, currentCellCoordinates.x, SquareState::Path);
            gridManager.StoreCoordinates(sf::Vector2i(currentCellCoordinates.x,currentCellCoordinates.y), SquareState::Path);
            
        }
    }
    if(currentCellCoordinates.y != GetObjective().y){
        if(currentCellCoordinates.y < GetObjective().y - 1){
            currentCellCoordinates.y++;
            grid.SetGrid(currentCellCoordinates.y, currentCellCoordinates.x, SquareState::Path);
            gridManager.StoreCoordinates(sf::Vector2i(currentCellCoordinates.x,currentCellCoordinates.y), SquareState::Path);
        } else if(currentCellCoordinates.y > GetObjective().y + 1){
            currentCellCoordinates.y--;
            grid.SetGrid(currentCellCoordinates.y, currentCellCoordinates.x, SquareState::Path);
            gridManager.StoreCoordinates(sf::Vector2i(currentCellCoordinates.x,currentCellCoordinates.y), SquareState::Path);
            
        }
    }
}



