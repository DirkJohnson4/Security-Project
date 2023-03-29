/**
 * file: SnakeGame.cpp
 * Author: Dirk Johnson
 * Class: COP 2001 Summer 2022
 * Purpose: Draw a snake and have it move around the window
 * eating randomly placed food. Each time a food has been eaten, the snake grows,
 * the previous food disappears, and a new food randomly appears. The game ends if
 * the snake touches one of the walls or itself.
 ********************************************/

#include <iostream>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>
#include <Eagles/Bounds.h>
#include <cstdlib>

const int WIN_WIDTH = 1000;  //This sets a constant value for window width
const int WIN_HEIGHT = 1000;  //This sets a constant value for window height

const int SNAKE_SIZE = 30; //size of each snake segment

enum Direction {  //this sets up variables that coincide with the cardinal directions
    North,
    East,
    South,
    West
};


int SnakeGame();  //declaration of snake game function

bool goDirection(Direction direction, int &cellX, int &cellY, int rows, int columns);  //declaration of movement function

int main() {

    SnakeGame(); //call to SnakeGame function

    return 0;
}


int SnakeGame() {  //definition of SnakeGame function

    fgcu::AnimatedWindow window = fgcu::AnimatedWindow(WIN_WIDTH, WIN_HEIGHT, "Snake Game");
    window.setColor(sf::Color::Black);  //this sets up the animated window dimensions and color

    int rows = WIN_HEIGHT / SNAKE_SIZE;  //this sets up the intervals the snake will move along in the x direction
    int columns = WIN_WIDTH / SNAKE_SIZE;  //this sets up the intervals the snake will move along in the y direction

    fgcu::AnimatedRectangle body[1000];  //Allocates space in memory for a snake array of size 1000
    int snakeLength = 5;  //sets the base snake size to 5
    Direction snakeDirection = North;  //sets the starting direction of the snake
    int snakeXcell = columns / 2;  //
    int snakeYcell = rows / 2;

    int x = snakeXcell;
    int y = snakeYcell;

    srand(time(NULL));
    float foodXposition = rand() % 30 * SNAKE_SIZE + 30;  //sets a random starting x coordinate for the food
    float foodYposition = rand() % 30 * SNAKE_SIZE + 30;  //sets a random starting y coordinate for the food


    for (int i = 0; i < snakeLength; i++) {  //builds snake according to starting snake length (equals 5 currently)
        body[i] = fgcu::AnimatedRectangle(SNAKE_SIZE, SNAKE_SIZE);  //determines width and height of each snake segment
        body[i].setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);  //sets snake segment origin to middle of shape
        body[i].setPosition(x * SNAKE_SIZE, y * SNAKE_SIZE);  //sets starting position of snake pieces
        body[i].setFillColor(sf::Color::Green);  //sets snake color to green
        window.addShape(&body[i]);  //adds each snake piece to window
        y++;  //increments each pieces down the y-axis
    }

    fgcu::AnimatedRectangle food = fgcu::AnimatedRectangle(SNAKE_SIZE, SNAKE_SIZE);  //builds food width and height
    food.setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);  //sets food origin to middle of shape
    food.setPosition(foodXposition, foodYposition);  //sets food starting position to random x and y coord
    food.setFillColor(sf::Color::Red);  //sets food color to red
    window.addShape(&food);  //adds food shape to window

    auto startTime = std::chrono::high_resolution_clock::now();
    long elapsed_ms = 0;  //sets a clock to run in background


    while (window.nextFrame()) {  //while window is opem

        auto stopTime = std::chrono::high_resolution_clock::now();
        elapsed_ms += std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime).count();

        startTime = stopTime;

        if (elapsed_ms >= 60) {  //updates snake position every 60 ms
            elapsed_ms = 0;

            for (int i = snakeLength - 1; i > 0; i--) {
                body[i].setPosition(body[i - 1].getPosition()); //positions body incrementally behinds heads movement
            }

            //this whole switch statement determines what key was pressed and keeps the snake moving
            //in that direction until the direction input has been changed

            switch (snakeDirection) {
                case West:  //case for when the snakes direction is set to west

                    switch (window.getLastKey()) {
                        //if while the snake is moving west, the up arrow is pressed, the snake will start moving
                        //in the north direction and continue to go in that direction until a new direction has been input
                        case sf::Keyboard::Up:
                            goDirection(North, snakeXcell, snakeYcell, rows, columns);
                            snakeDirection = North;
                            break;
                            //if while the snake is moving west, the down arrow is pressed, the snake will start moving
                            //in the south direction and continue to go in that direction until a new direction has been input
                        case sf::Keyboard::Down:
                            goDirection(South, snakeXcell, snakeYcell, rows, columns);
                            snakeDirection = South;
                            break;
                            //if the key input isn't up arrow or down arrow, then it is an invalid input
                            //and the snake will continue moving west
                        default:
                            goDirection(West, snakeXcell, snakeYcell, rows, columns);
                    }
                    break;

                case North:

                    switch (window.getLastKey()) {
                        //if while the snake is moving North, the Right arrow is pressed, the snake will start moving
                        //in the East direction and continue to go in that direction until a new direction has been input
                        case sf::Keyboard::Right:
                            goDirection(East, snakeXcell, snakeYcell, rows, columns);
                            snakeDirection = East;
                            break;
                            //if while the snake is moving North, the Left arrow is pressed, the snake will start moving
                            //in the West direction and continue to go in that direction until a new direction has been input
                        case sf::Keyboard::Left:
                            goDirection(West, snakeXcell, snakeYcell, rows, columns);
                            snakeDirection = West;
                            break;
                            //if the key input isn't right arrow or left arrow, then it is an invalid input
                            //and the snake will continue moving north
                        default:
                            goDirection(North, snakeXcell, snakeYcell, rows, columns);
                    }
                    break;

                case East:

                    switch (window.getLastKey()) {
                        //if while the snake is moving East, the Up arrow is pressed, the snake will start moving
                        //in the North direction and continue to go in that direction until a new direction has been input
                        case sf::Keyboard::Up:
                            goDirection(North, snakeXcell, snakeYcell, rows, columns);
                            snakeDirection = North;
                            break;
                            //if while the snake is moving North, the Down arrow is pressed, the snake will start moving
                            //in the South direction and continue to go in that direction until a new direction has been input
                        case sf::Keyboard::Down:
                            goDirection(South, snakeXcell, snakeYcell, rows, columns);
                            snakeDirection = South;
                            break;
                            //if the key input isn't up arrow or down arrow, then it is an invalid input
                            //and the snake will continue moving east
                        default:
                            goDirection(East, snakeXcell, snakeYcell, rows, columns);
                    }
                    break;

                case South:

                    switch (window.getLastKey()) {
                        //if while the snake is moving South, the Right arrow is pressed, the snake will start moving
                        //in the East direction and continue to go in that direction until a new direction has been input
                        case sf::Keyboard::Right:
                            goDirection(East, snakeXcell, snakeYcell, rows, columns);
                            snakeDirection = East;
                            break;
                            //if while the snake is moving South, the Left arrow is pressed, the snake will start moving
                            //in the West direction and continue to go in that direction until a new direction has been input
                        case sf::Keyboard::Left:
                            goDirection(West, snakeXcell, snakeYcell, rows, columns);
                            snakeDirection = West;
                            break;
                            //if the key input isn't right arrow or left arrow, then it is an invalid input
                            //and the snake will continue moving South
                        default:
                            goDirection(South, snakeXcell, snakeYcell, rows, columns);
                    }
                    break;
            }
            body[0].setPosition(snakeXcell * SNAKE_SIZE, snakeYcell * SNAKE_SIZE);
            //this updates the position of the head each time the switch statement is run;
            srand(time(NULL));
            int randomFoodXPosition = rand() % 30 * SNAKE_SIZE + 30; //This sets up the new random x coord after the first food is eaten
            int randomFoodYPosition = rand() % 30 * SNAKE_SIZE + 30; //This sets up the new random y coord after the first food is eaten
            if (body[0].getGlobalBounds().intersects(food.getGlobalBounds())) {
                //this checks to see if the new food position would spawn the food on top of a space where the
                //snake body already exists
                for (int i = snakeLength; i < snakeLength + 1; i++) {
                    //this for loop adds a new segment onto the end of the snake
                    body[i] = fgcu::AnimatedRectangle(SNAKE_SIZE, SNAKE_SIZE);
                    body[i].setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
                    body[i].setFillColor(sf::Color::Green);
                    window.addShape(&body[i]);
                    y++;
                    food.setPosition(randomFoodXPosition,randomFoodYPosition);
                    while(food.getPosition() == body[i].getPosition()){
                        //this nested while loop checks each segment of the body
                        //and checks it against the potential position of the new food location
                        food.setPosition(randomFoodXPosition,randomFoodYPosition);
                    }
                    window.addShape(&food);
                }
                snakeLength ++;
            }

            for (int i = 0; i < snakeLength; i++) {
                //when the snake hits a wall it starts to crumple in on itself,
                //so this for loop checks to see if the head segment is in the same position
                //as the first body segment, which only happens when the snake hits a wall
                if (body[i].getPosition() == body[i - 1].getPosition()) {
                    std::cout << "You've Hit a Wall!!";
                    return 0;
                }

            }
            for (int i = 3; i < snakeLength; i++) {
                //this for loop checks to see if the head of the snake intersects with anywhere on the snake
                //body other than the first 3 segments because it is very unlikely that it will ever intersect there
                if (body[0].getGlobalBounds() == body[i].getGlobalBounds()) {
                    std::cout << "You've Eaten Yourself!!";
                    return 0;
                }
            }
        }
    }
    return 0;

}// end SnakeGame function

bool goDirection(Direction direction, int &cellX, int &cellY, int rows, int columns) {
    bool moved = false;

    switch (direction) {
        case North:  //this determines the movement for when the snake direction equals north
            if (cellY > 0) {
                cellY--;
                moved = true;
            }
            break;
        case East:  //this determines the movement for when the snake direction equals east
            if (cellX < columns - 1) {
                cellX++;
                moved = true;
            }
            break;
        case South:  //this determines the movement for when the snake direction equals south
            if (cellY < rows - 1) {
                cellY++;
                moved = true;
            }
            break;
        default: // //this determines the movement for when the snake direction equals west
            if (cellX > 0) {
                cellX--;
                moved = true;
            }
    }

    return moved;
}