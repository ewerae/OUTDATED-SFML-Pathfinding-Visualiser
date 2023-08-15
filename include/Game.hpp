#pragma once

#include "AssetManager.hpp"
#include "Grid.hpp"
#include "GridManager.hpp"
#include "AStar.hpp"
#include <SFML/Graphics/RenderWindow.hpp>




class Game {
    private:
        AssetManager assetManager;
        Grid grid;
        GridManager gridManager;
        sf::RenderWindow window;
        AStar aStar;


        

        bool isRunning;
        const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f); 

        
        sf::Color backgroundColour;

        sf::Text fpsText;
        sf::Text mousePosText;



        void Init();
        void ProcessEvents();
        void Update(sf::Time deltaTime);
        void Render();


        

    public:
        Game();
        ~Game();

        void Run();

    
};