#pragma once
#include <vector>
#include <algorithm>

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetManager.hpp"
#include "Grid.hpp"

struct SquareCoordinates {
    std::vector<sf::Vector2i> start;
    std::vector<sf::Vector2i> objective;
    std::vector<sf::Vector2i> obstacle;
    std::vector<sf::Vector2i> path;
};

class GridManager {
    private:
        AssetManager& assetManager;
        sf::RenderWindow& window;
        Grid& grid;


        sf::RectangleShape startButton;
        sf::RectangleShape objectiveButton;
        sf::RectangleShape emptyButton;
        sf::RectangleShape obstacleButton; 
        sf::RectangleShape runButton; 
        sf::RectangleShape resetButton; 
        
        sf::RectangleShape startSquare;
        sf::RectangleShape objectiveSquare;
        sf::RectangleShape obstacleSquare; 
        sf::RectangleShape pathSquare; 
        

        sf::RectangleShape selectBar; 

        sf::Color startColour;
        sf::Color objectiveColour;
        sf::Color emptyColour;
        sf::Color obstacleColour;
        sf::Color pathColour;
        sf::Color runColour;
        sf::Color selectColour;
        
        sf::Text startText;
        sf::Text objectiveText;
        sf::Text emptyText;
        sf::Text obstacleText;
        sf::Text runText;
        sf::Text resetText;
        sf::Text warnText;
        sf::Text squareStateText;
        sf::Text checkVectorText;
        
        bool placingStart;
        bool placingObjective;
        bool placingObstacle;
        bool placingEmpty;
        bool clickRun;
        bool clickReset;
        
        bool hasStart;
        bool hasObjective;

        SquareCoordinates squareCoordinates;

        std::vector<sf::Vector2i> default1;

    public:
        GridManager(AssetManager& assetManager, sf::RenderWindow& window, Grid& grid);
        ~GridManager();
        
        bool RunPressed(){return clickRun;}
        bool ResetPressed(){return clickReset;}

        void HandleInput(sf::RenderWindow& window, sf::Event& event);
        void PlaceSquare(sf::RenderWindow& window, sf::Event& event);
        

        void StoreCoordinates(const sf::Vector2i cell, const SquareState squareState);
        void RemoveCoordinates(const sf::Vector2i cell, const SquareState squareState);
        void RemovePosition(std::vector<sf::Vector2i>& vec, const sf::Vector2i& value);
        void Reset();

        std::vector<sf::Vector2i>& GetSquareStateCoordinates(SquareState squareState);

        void VectorStateText();
        void SquareStateText(sf::RenderWindow& window);
        void DrawButtons(sf::RenderWindow& window);
        void DrawGrid(sf::RenderWindow& window);
        void Draw(sf::RenderWindow& window);
        



};