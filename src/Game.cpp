#include "Game.hpp"


// 37 x 35

Game::Game() : grid(assetManager, window, 700, 740, 20, 600, 40, sf::Color::Black, sf::Color::White, sf::Color(222,220,220)), gridManager(assetManager, window, grid), 
            window(sf::VideoMode(1400, 800), "SFML Game", sf::Style::Titlebar | sf::Style::Close), aStar(window, gridManager, grid),isRunning(true){
    Init();
    
    
}

Game::~Game() {
    
}


void Game::Init() {
    
    backgroundColour =  sf::Color(200, 200, 200);
    
    
    fpsText.setFont(assetManager.GetFont("font1"));
    fpsText.setCharacterSize(20);   
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition(10.0f, 10.0f);

    mousePosText.setFont(assetManager.GetFont("font1"));
    mousePosText.setCharacterSize(20);
    mousePosText.setFillColor(sf::Color::White);
    mousePosText.setPosition(10.f, 35.f);


    
}


void Game::Run() {
    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;
    unsigned int frameCount = 0;
    
    while (isRunning) {
        sf::Time deltaTime = clock.restart();
        elapsedTime += deltaTime;
        
        ProcessEvents();
        
        
        while (elapsedTime >= timePerFrame) {
            float fps = static_cast<float>(frameCount) / elapsedTime.asSeconds();
            fpsText.setString("FPS: " + std::to_string(static_cast<int>(fps)));

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            std::string mousePositionString = "(" + std::to_string(mousePosition.x) + ", " + std::to_string(mousePosition.y) + ")";
            mousePosText.setString(mousePositionString);
            frameCount = 0;
            frameCount++;
            
            
            elapsedTime -= timePerFrame;

            Update(timePerFrame);
            Render();
            
        }

        
    }
}

void Game::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            isRunning = false;

        gridManager.HandleInput(window, event);
        gridManager.PlaceSquare(window, event);
        if(!gridManager.RunPressed() && !gridManager.GetSquareStateCoordinates(SquareState::Start).empty() && !gridManager.GetSquareStateCoordinates(SquareState::Objective).empty() ){
            aStar.InitialDirection();
        }
        if(gridManager.ResetPressed()){
            gridManager.Reset();
        }
        
    }
    
}

void Game::Update(sf::Time deltaTime) {
    gridManager.SquareStateText(window);
    gridManager.VectorStateText();

    if(gridManager.RunPressed() && !gridManager.GetSquareStateCoordinates(SquareState::Start).empty() && !gridManager.GetSquareStateCoordinates(SquareState::Objective).empty() ){
        aStar.TestAlgorithm(); 
        
    }
    

    
}

void Game::Render() {
    window.clear(backgroundColour);
    window.draw(fpsText);
    window.draw(mousePosText);

    sf::Text test;
    test.setFont(assetManager.GetFont("font1"));
    test.setCharacterSize(16);   
    test.setFillColor(sf::Color::White);
    test.setPosition(200.f, 10.0f);
    // std::string it = std::to_string(gridManager.GetSquareStateCoordinates(SquareState::Path).size());
    std::string it = std::to_string(aStar.GetCurrentCellCoordinates());
    test.setString(it);

    window.draw(test);

    grid.Draw(window);
    gridManager.Draw(window);
    
    window.display();
}