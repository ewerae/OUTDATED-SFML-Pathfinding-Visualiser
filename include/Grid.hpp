#pragma once
#include <vector>

#include "AssetManager.hpp"
#include <SFML/Graphics.hpp>

enum class SquareState {
    Empty,
    Obstacle,
    Start,
    Objective,
    Path,
};


class Grid {

    private:
        AssetManager& assetManager;
        sf::RenderWindow& window;
        
        
        const int GRID_HEIGHT;
        const int GRID_WIDTH;
        const int SQUARE_SIZE;
        const int START_X;
        const int START_Y;
        const sf::Color GRID_COLOUR;
        const sf::Color GRID_BACKGROUND_COLOUR;
        const sf::Color GRID_BACKGROUND_COLOUR2;

        sf::RectangleShape GRID_BACKGROUND;
        sf::RectangleShape GRID_BACKGROUND2;

        

        std::vector<std::vector<SquareState>> grid;


    public:
        Grid(AssetManager& assetManager,sf::RenderWindow& window, int GRID_HEIGHT, int GRID_WIDTH, int SQUARE_SIZE, int START_X, int START_Y, sf::Color GRID_COLOUR, sf::Color GRID_BACKGROUND_COLOUR, sf::Color GRID_BACKGROUND_COLOUR2);
        ~Grid();

        const std::vector<std::vector<SquareState>>& GetGrid() const { return grid; }
        void SetGrid(int row, int column, SquareState state) { grid[row][column] = state;}

        void DrawGridLines(sf::RenderWindow& window) const; 
        void DrawGridBackground(sf::RenderWindow& window) const; 
        void DrawGridBackground2(sf::RenderWindow& window) const;
        void Draw(sf::RenderWindow& window) const;

        
};