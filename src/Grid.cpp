#include "Grid.hpp"

Grid::Grid(AssetManager& assetManager, sf::RenderWindow& window, int GRID_HEIGHT, int GRID_WIDTH, int SQUARE_SIZE, int START_X, int START_Y, sf::Color GRID_COLOUR, sf::Color GRID_BACKGROUND_COLOUR, sf::Color GRID_BACKGROUND_COLOUR2) 

    : assetManager(assetManager), window(window), GRID_HEIGHT(GRID_HEIGHT), GRID_WIDTH(GRID_WIDTH), SQUARE_SIZE(SQUARE_SIZE), START_X(START_X), START_Y(START_Y), 
    GRID_COLOUR(GRID_COLOUR), GRID_BACKGROUND_COLOUR(GRID_BACKGROUND_COLOUR), GRID_BACKGROUND_COLOUR2(GRID_BACKGROUND_COLOUR2), grid(GRID_HEIGHT / SQUARE_SIZE, std::vector<SquareState>(GRID_WIDTH / SQUARE_SIZE, SquareState::Empty))  {

    GRID_BACKGROUND = sf::RectangleShape(sf::Vector2f(925.f, 740.f));
    GRID_BACKGROUND.setFillColor(GRID_BACKGROUND_COLOUR);
    GRID_BACKGROUND.setPosition(450.f, 20.f);

    GRID_BACKGROUND2 = sf::RectangleShape(sf::Vector2f(780.f, 720.f));
    GRID_BACKGROUND2.setFillColor(GRID_BACKGROUND_COLOUR2);
    GRID_BACKGROUND2.setPosition(580.f, 30.f);

    
}

Grid::~Grid() {

}

void Grid::DrawGridLines(sf::RenderWindow& window) const {
    for (int y = START_Y; y <= GRID_HEIGHT + START_Y; y += SQUARE_SIZE) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(static_cast<float>(START_X - 1 ), static_cast<float>(y)), GRID_COLOUR),
            sf::Vertex(sf::Vector2f(static_cast<float>(GRID_WIDTH + START_X), static_cast<float>(y)), GRID_COLOUR)
        };
        window.draw(line, 2, sf::Lines);
    }

        
    for (int x = START_X; x <= GRID_WIDTH + START_X; x += SQUARE_SIZE) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(static_cast<float>(x), static_cast<float>(START_Y)), GRID_COLOUR),
            sf::Vertex(sf::Vector2f(static_cast<float>(x), static_cast<float>(GRID_HEIGHT + START_Y)), GRID_COLOUR)
        };
        window.draw(line, 2, sf::Lines);
    }
}

void Grid::DrawGridBackground(sf::RenderWindow& window) const{
    window.draw(GRID_BACKGROUND);
}


void Grid::DrawGridBackground2(sf::RenderWindow& window) const{
    window.draw(GRID_BACKGROUND2);
}

void Grid::Draw(sf::RenderWindow& window) const{
    DrawGridBackground(window);
    DrawGridBackground2(window);
    DrawGridLines(window);

}