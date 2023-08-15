
#include "GridManager.hpp"

GridManager::GridManager(AssetManager& assetManager, sf::RenderWindow& window, Grid& grid) :  
    assetManager(assetManager), window(window), grid(grid), placingStart(false), placingObjective(false), 
    placingObstacle(false), placingEmpty(false), clickRun(false), clickReset(false), hasStart(false), hasObjective(false){

    assetManager.LoadFont("font1", "assets/fonts/playfair/PlayfairDisplay-VariableFont_wght.ttf");

    startButton = sf::RectangleShape(sf::Vector2f(19.f, 19.f));
    startColour = sf::Color(41, 179, 55);
    startButton.setFillColor(startColour);
    startButton.setPosition(550.f, 161.f);

    objectiveButton = sf::RectangleShape(sf::Vector2f(19.f, 19.f));
    objectiveColour = sf::Color(219, 70, 44);
    objectiveButton.setFillColor(objectiveColour);
    objectiveButton.setPosition(550.f, 241.f);

    obstacleButton = sf::RectangleShape(sf::Vector2f(19.f, 19.f));
    obstacleColour = sf::Color(20, 26, 20);
    obstacleButton.setFillColor(obstacleColour);
    obstacleButton.setPosition(550.f, 321.f);

    emptyButton = sf::RectangleShape(sf::Vector2f(19.f, 19.f));
    emptyColour = sf::Color(176, 176, 176);
    emptyButton.setFillColor(emptyColour);
    emptyButton.setPosition(550.f, 401.f);


    startSquare = sf::RectangleShape(sf::Vector2f(19.f, 19.f));
    startColour = sf::Color(41, 179, 55);
    startSquare.setFillColor(startColour);
    

    objectiveSquare = sf::RectangleShape(sf::Vector2f(19.f, 19.f));
    objectiveColour = sf::Color(219, 70, 44);
    objectiveSquare.setFillColor(objectiveColour);
    

    obstacleSquare = sf::RectangleShape(sf::Vector2f(19.f, 19.f));
    obstacleColour = sf::Color(20, 26, 20);
    obstacleSquare.setFillColor(obstacleColour);

    pathSquare = sf::RectangleShape(sf::Vector2f(19.f, 19.f));
    pathColour = sf::Color(113, 240, 225);
    pathSquare.setFillColor(pathColour);


    
    runButton= sf::RectangleShape(sf::Vector2f(110.f, 40.f));
    runColour = sf::Color(213, 222, 235);
    runButton.setFillColor(runColour);
    runButton.setPosition(460.f, 490.f);

    resetButton= sf::RectangleShape(sf::Vector2f(110.f, 40.f));
    resetButton.setFillColor(runColour);
    resetButton.setPosition(460.f, 565.f);

    startText.setFont(assetManager.GetFont("font1"));
    startText.setString("Start");
    startText.setCharacterSize(16);   
    startText.setFillColor(sf::Color::Black);
    startText.setPosition(460.0f, 161.0f);

    objectiveText.setFont(assetManager.GetFont("font1"));
    objectiveText.setString("Goal");
    objectiveText.setCharacterSize(16);   
    objectiveText.setFillColor(sf::Color::Black);
    objectiveText.setPosition(460.0f, 241.0f);

    obstacleText.setFont(assetManager.GetFont("font1"));
    obstacleText.setString("Obstacle");
    obstacleText.setCharacterSize(16);   
    obstacleText.setFillColor(sf::Color::Black);
    obstacleText.setPosition(460.0f, 321.0f);

    emptyText.setFont(assetManager.GetFont("font1"));
    emptyText.setString("Empty");
    emptyText.setCharacterSize(16);   
    emptyText.setFillColor(sf::Color::Black);
    emptyText.setPosition(460.0f, 401.0f);

    runText.setFont(assetManager.GetFont("font1"));
    runText.setString("Run");
    runText.setCharacterSize(16);   
    runText.setFillColor(sf::Color::Black);
    runText.setPosition(500.0f, 500.0f);

    resetText.setFont(assetManager.GetFont("font1"));
    resetText.setString("Reset");
    resetText.setCharacterSize(16);   
    resetText.setFillColor(sf::Color::Black);
    resetText.setPosition(495.0f, 575.0f);

    warnText.setFont(assetManager.GetFont("font1"));
    warnText.setString("Only 1 start and 1 objective");
    warnText.setCharacterSize(20);   
    warnText.setFillColor(sf::Color::White);
    warnText.setPosition(10.0f, 70.0f);

    squareStateText.setFont(assetManager.GetFont("font1"));
    squareStateText.setCharacterSize(20);   
    squareStateText.setFillColor(sf::Color::White);
    squareStateText.setPosition(10.0f, 90.0f);

    checkVectorText.setFont(assetManager.GetFont("font1"));
    checkVectorText.setCharacterSize(20);   
    checkVectorText.setFillColor(sf::Color::White);
    checkVectorText.setPosition(10.0f, 105.0f);


    selectBar= sf::RectangleShape(sf::Vector2f(130.f, 40.f));
    selectColour = sf::Color(207, 207, 207);
    selectBar.setFillColor(selectColour);



}

GridManager::~GridManager() {

}


void GridManager::HandleInput(sf::RenderWindow& window, sf::Event& event) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (startButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            placingStart = true;
            placingObjective = false;
            placingObstacle = false;
            placingEmpty = false;
            clickRun = false;
            clickReset = false;

            selectBar.setPosition(450.0f, 155.0f);

        } else if (objectiveButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            placingObjective = true;
            placingStart = false;
            placingObstacle = false;
            placingEmpty = false;
            clickRun = false;
            clickReset = false;

            selectBar.setPosition(450.0f, 235.0f);

        } else if (obstacleButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            placingObstacle = true;
            placingStart = false;
            placingObjective = false;
            placingEmpty = false;
            clickRun = false;
            clickReset = false;

            selectBar.setPosition(450.0f, 315.0f);
            
        } else if (emptyButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            placingEmpty = true;
            placingStart = false;
            placingObjective = false;
            placingObstacle = false;
            clickRun = false;
            clickReset = false;

            selectBar.setPosition(450.0f, 395.0f);

        } else if (runButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            clickRun = true;
            clickReset = false;
            placingStart = false;
            placingObjective = false;
            placingObstacle = false;
            placingEmpty = false;
            

            selectBar.setPosition(450.0f, 490.0f);

        } else if (resetButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            clickReset = true;
            clickRun = false;
            placingStart = false;
            placingObjective = false;
            placingObstacle = false;
            placingEmpty = false;

            selectBar.setPosition(450.0f, 565.0f);

        }
    }
}

void GridManager::PlaceSquare(sf::RenderWindow& window, sf::Event& event) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if(ResetPressed()){
        hasStart =false;
        hasObjective = false;
    }

    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 37; j++) {
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (mousePosition.x > 600 + j * 20 && mousePosition.x < 620 + j * 20 &&
                    mousePosition.y > 40 + i * 20 && mousePosition.y < 60 + i * 20) {
                    
                    if (placingStart && !hasStart) {
                        if(grid.GetGrid()[i][j] == SquareState::Objective){
                            RemoveCoordinates(sf::Vector2i(j,i),SquareState::Objective);
                            grid.SetGrid(i, j, SquareState::Start);
                            hasObjective = false;
                        }
                        grid.SetGrid(i, j, SquareState::Start);
                        StoreCoordinates(sf::Vector2i(j,i), SquareState::Start);
                        hasStart = true;
                        

                    } else if (placingObjective && !hasObjective) {
                        if(grid.GetGrid()[i][j] == SquareState::Start){
                            RemoveCoordinates(sf::Vector2i(j,i),SquareState::Start);
                            grid.SetGrid(i, j, SquareState::Start);
                            hasStart = false;
                        }
                        grid.SetGrid(i, j, SquareState::Objective);
                        StoreCoordinates(sf::Vector2i(j,i), SquareState::Objective);
                        hasObjective = true;

                        
                        
                    } else if (placingObstacle) {
                        if (grid.GetGrid()[i][j] == SquareState::Start) {
                            RemoveCoordinates(sf::Vector2i(j,i),SquareState::Start);
                            hasStart = false;
                        } else if (grid.GetGrid()[i][j] == SquareState::Objective) {
                            RemoveCoordinates(sf::Vector2i(j,i),SquareState::Objective);
                            hasObjective = false;
                        }
                        grid.SetGrid(i, j, SquareState::Obstacle);
                        StoreCoordinates(sf::Vector2i(j,i), SquareState::Obstacle);

                    } else if (placingEmpty) {
                        if (grid.GetGrid()[i][j] == SquareState::Start) {
                            hasStart = false;
                        } else if (grid.GetGrid()[i][j] == SquareState::Objective) {
                            hasObjective = false;
                        } else if(grid.GetGrid()[i][j] == SquareState::Obstacle){
                            RemoveCoordinates(sf::Vector2i(j,i),SquareState::Obstacle);
                        }
                        grid.SetGrid(i, j, SquareState::Empty);
                        
                    }
                }
            }
        }
    }
}


void GridManager::RemoveCoordinates(sf::Vector2i cell, SquareState squareState) {
    switch (squareState) {
        case SquareState::Start:
            RemovePosition(squareCoordinates.start, cell);
            break;
        case SquareState::Objective:
            RemovePosition(squareCoordinates.objective, cell);
            break;
        case SquareState::Obstacle:
            RemovePosition(squareCoordinates.obstacle, cell);
            break;
        default:
            break;
    }
}

void GridManager::RemovePosition(std::vector<sf::Vector2i>& vec, const sf::Vector2i& value) {
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        vec.erase(it);
    }
}

void GridManager::StoreCoordinates(sf::Vector2i cell, SquareState squareState) {
    switch (squareState) {
        case SquareState::Start:
            squareCoordinates.start.push_back(cell);
            break;
        case SquareState::Objective:
            squareCoordinates.objective.push_back(cell);
            break;
        case SquareState::Obstacle:
            squareCoordinates.obstacle.push_back(cell);
            break;
        case SquareState::Path:
            squareCoordinates.path.push_back(cell);
            break;
        default:
            break;
    }
}

std::vector<sf::Vector2i>& GridManager::GetSquareStateCoordinates(SquareState squareState) {
        switch (squareState) {
            case SquareState::Start:
                return squareCoordinates.start;
            case SquareState::Objective:
                return squareCoordinates.objective;
            case SquareState::Obstacle:
                return squareCoordinates.obstacle;
            case SquareState::Path:
                return squareCoordinates.path;
            default:
                return default1;
        }
}

void GridManager::Reset(){
    GetSquareStateCoordinates(SquareState::Start).clear();
    GetSquareStateCoordinates(SquareState::Objective).clear();
    GetSquareStateCoordinates(SquareState::Obstacle).clear();
    GetSquareStateCoordinates(SquareState::Path).clear();
    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 37; j++) {
            grid.SetGrid(i,j,SquareState::Empty);
        }
    }

}

void GridManager::SquareStateText(sf::RenderWindow& window){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 37; j++) {
            if (mousePosition.x > 600 + j * 20 && mousePosition.x < 620 + j * 20 &&
                mousePosition.y > 40 + i * 20 && mousePosition.y < 60 + i * 20) {

                if(grid.GetGrid()[i][j] == SquareState::Start){
                    squareStateText.setString("Start");
                } else if(grid.GetGrid()[i][j] == SquareState::Objective){
                    squareStateText.setString("Goal");
                } else if(grid.GetGrid()[i][j] == SquareState::Obstacle){
                    squareStateText.setString("Obstacle");
                } else if(grid.GetGrid()[i][j] == SquareState::Empty){
                    squareStateText.setString("Empty");
                } else if(grid.GetGrid()[i][j] == SquareState::Path){
                    squareStateText.setString("Path");
                }
            }
            
        }
    }
}

void GridManager::VectorStateText(){
    std::vector<sf::Vector2i> start = squareCoordinates.start;
    std::vector<sf::Vector2i> objective = squareCoordinates.objective;
    std::vector<sf::Vector2i> path = squareCoordinates.path;

    if (start.empty()) {
        return; 
    }
    if (objective.empty()) {
        return; 
    }
    if (path.empty()) {
        return; 
    }
    std::string coordinatesStr = "Start Coordinates:\n";
    for (const sf::Vector2i& coord : start) {
        coordinatesStr += "(" + std::to_string(coord.x) + ", " + std::to_string(coord.y) + ")\n";
    }
    coordinatesStr += "Objective Coordinates:\n";
    for (const sf::Vector2i& coord : objective) {
        coordinatesStr += "(" + std::to_string(coord.x) + ", " + std::to_string(coord.y) + ")\n";
    }
    coordinatesStr += "Path Coordinates:\n";
    for (const sf::Vector2i& coord : path) {
        coordinatesStr += "(" + std::to_string(coord.x) + ", " + std::to_string(coord.y) + ")\n";
    }
        
    checkVectorText.setString(coordinatesStr);
}


void GridManager::DrawGrid(sf::RenderWindow& window) {
    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 37; j++) {
            if (grid.GetGrid()[i][j] == SquareState::Start) {
                startSquare.setPosition(600.f + j * 20.f, 40 + i * 20.f);
                window.draw(startSquare);
            } else if (grid.GetGrid()[i][j] == SquareState::Objective) {
                objectiveSquare.setPosition(600.f + j * 20.f, 40 + i * 20.f);
                window.draw(objectiveSquare);
            } else if (grid.GetGrid()[i][j] == SquareState::Obstacle) {
                obstacleSquare.setPosition(600.f + j * 20.f, 40 + i * 20.f);
                window.draw(obstacleSquare);
            } else if (grid.GetGrid()[i][j] == SquareState::Path) {
                pathSquare.setPosition(600.f + j * 20.f, 40 + i * 20.f);
                window.draw(pathSquare);
            } 

        }
    }
}

void GridManager::DrawButtons(sf::RenderWindow& window) {
    if (placingStart || placingObjective || placingObstacle || placingEmpty || clickRun || clickReset) {
        window.draw(selectBar);
    }


    window.draw(startButton);
    window.draw(startText);
    window.draw(objectiveButton);
    window.draw(objectiveText);
    window.draw(obstacleButton);
    window.draw(obstacleText);
    window.draw(emptyButton);
    window.draw(emptyText);
    window.draw(runButton);
    window.draw(runText);
    window.draw(resetButton);
    window.draw(resetText);

    window.draw(warnText);
    window.draw(squareStateText);
    window.draw(checkVectorText);
}


void GridManager::Draw(sf::RenderWindow& window) {
    DrawButtons(window);
    if(!ResetPressed()){
        
        DrawGrid(window);
    }
        
}