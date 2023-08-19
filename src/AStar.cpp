#include "AStar.hpp"

AStar::AStar(sf::RenderWindow& window, GridManager& gridManager, Grid& grid) 
    : window(window), gridManager(gridManager), grid(grid), isInit(false), isFinished(false){


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

Node* AStar::CreateStartNode(){
    Node* start = new Node(GetStart().x, GetStart().y);
    return start;
}

Node* AStar::CreateObjectiveNode(){
    Node* goal = new Node(GetObjective().x, GetObjective().y);
    return goal;
}

// octile heuristic helps for diagonal movement, more accurate than other manhattan stuff
double AStar::OctileHeuristic(int x1, int y1, int x2, int y2) {
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    return dx + dy + (std::sqrt(2)  - 2) * std::min(dx, dy);
}
// // returns true if f value of a is bigger than f value of b

void AStar::AStarInit(){
    if (!isInit) { // Check if already initialized
        openSet.push(CreateStartNode());
        goalNode = CreateObjectiveNode();
        isInit = true; // Set the initialization state
    }
}

int AStar::GetOpenSetTop() {
    if (!openSet.empty()) {
        return openSet.top()->x;
    } else {
        return -1; // Return nullptr or handle the case when the openSet is empty
    }
}

void AStar::Reset() {
    while (!openSet.empty()) {
        openSet.pop();
    }
    closedSet.clear();
    path.clear();
    isInit = false;
    isFinished = false;
    
}

void AStar::AStarSearch(){
    if(!openSet.empty()){
        Node* current = openSet.top();
        openSet.pop();
        
        if(current->x == goalNode->x && current->y == goalNode->y){
            while(current){
                path.push_back(current);
                
                sf::Vector2i coords = sf::Vector2i(current->x, current->y);
                if (grid.GetGrid()[coords.y][coords.x] != SquareState::Start && grid.GetGrid()[coords.y][coords.x] != SquareState::Objective){
                    grid.SetGrid(coords.y,coords.x, SquareState::Path);
                }
                    
                current= current->parent;
            }
            isFinished = true;

        }

        if(!isFinished){
            closedSet.insert(current);
            if (grid.GetGrid()[current->y][current->x] != SquareState::Start && grid.GetGrid()[current->y][current->x] != SquareState::Objective){
                grid.SetGrid(current->y, current->x, SquareState::Visited);
            }
            

            int neighbors[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

            for (const auto& neighbor : neighbors) {
                int nx = current->x + neighbor[0]; // starts from -1,0 from the current cell and iterates through
                int ny = current->y + neighbor[1];

                if (nx >= 0 && nx < 37 && ny >= 0 && ny < 35 && grid.GetGrid()[ny][nx] != SquareState::Obstacle) { //if the square is within the grid and not an obstacle
                    
                    bool inClosedSet = false; // check if its in the closedSet
                    for (auto it = closedSet.begin(); it != closedSet.end(); ++it) {
                        if ((*it)->x == nx && (*it)->y == ny) {
                            inClosedSet = true;
                            break;
                        }
                    }
                    
                    if (!inClosedSet) {
                        Node* neighborNode = new Node(nx, ny);
                        neighborNode->g = current->g + 1;
                        neighborNode->h = OctileHeuristic(nx, ny, goalNode->x, goalNode->y);
                        neighborNode->f = neighborNode->g + neighborNode->h;
                        neighborNode->parent = current;
                        openSet.push(neighborNode);
                    }
                }
            }
            

        }
    }
}





// void AStar::InitialDirection(){
//     if(GetStart().x < GetObjective().x){
//         currentCellCoordinates = sf::Vector2i(GetStart().x, GetStart().y);
//     } else if(GetStart().x > GetObjective().x){
//         currentCellCoordinates = sf::Vector2i(GetStart().x, GetStart().y);
//     }
// }


// void AStar::TestAlgorithm() {
//     if(currentCellCoordinates.x != GetObjective().x){
//         if(currentCellCoordinates.x < GetObjective().x - 1){
//             currentCellCoordinates.x++;
//             grid.SetGrid(currentCellCoordinates.y, currentCellCoordinates.x, SquareState::Path);
//             gridManager.StoreCoordinates(sf::Vector2i(currentCellCoordinates.x,currentCellCoordinates.y), SquareState::Path);
//         } else if(currentCellCoordinates.x > GetObjective().x + 1){
//             currentCellCoordinates.x--;
//             grid.SetGrid(currentCellCoordinates.y, currentCellCoordinates.x, SquareState::Path);
//             gridManager.StoreCoordinates(sf::Vector2i(currentCellCoordinates.x,currentCellCoordinates.y), SquareState::Path);
            
//         }
//     }
//     if(currentCellCoordinates.y != GetObjective().y){
//         if(currentCellCoordinates.y < GetObjective().y - 1){
//             currentCellCoordinates.y++;
//             grid.SetGrid(currentCellCoordinates.y, currentCellCoordinates.x, SquareState::Path);
//             gridManager.StoreCoordinates(sf::Vector2i(currentCellCoordinates.x,currentCellCoordinates.y), SquareState::Path);
//         } else if(currentCellCoordinates.y > GetObjective().y + 1){
//             currentCellCoordinates.y--;
//             grid.SetGrid(currentCellCoordinates.y, currentCellCoordinates.x, SquareState::Path);
//             gridManager.StoreCoordinates(sf::Vector2i(currentCellCoordinates.x,currentCellCoordinates.y), SquareState::Path);
            
//         }
//     }
// }



