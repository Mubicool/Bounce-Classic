#include <SFML/Graphics.hpp>
#include <iostream>
#include<cstdlib>
#include<cmath>
#include <fstream>


#define PI 3.1415926535898
const int w = 113;
const int h = 8;
sf::RectangleShape Move_Arr[w][h];
sf::RectangleShape Wall_Arr[w][h];

int main()
{
    int Width = 1080;
    int Height = 720;
    int rect_W = 90;
    int rect_H = 90;
    int it = 0;
    int temp_it = 0;
    int r = 0;
    int l = 0;
    int q = 0;
    int k = 0;
    int j = 0;
    int g = 0;
    int gr = 0;
    int grt = 0;
    sf::Vector2f size(rect_W, rect_H);
    sf::Vector2f ballSpeed(0, 0);
    bool ground = false;
    int B_i = 0;
    int B_j = 0;
    float x = 0;
    int t = 0;
    int top = 0;
    int fps = 60;
    int loc = 0;
    int loc2 = 0;
    bool col = true;
    bool T_col = false;
    bool L_col = false;
    bool R_col = false;
    bool LE_col = false;

    sf::RenderWindow Window(sf::VideoMode(Width, Height), "Bounce Classic");
    Window.setFramerateLimit(fps);

    
    sf::RectangleShape enemy1(sf::Vector2f(rect_W / 3, rect_H));
    enemy1.setFillColor(sf::Color(0, 0, 0));
    enemy1.setOrigin(enemy1.getSize().x/2, enemy1.getSize().y/2);
    sf::RectangleShape enemy2(sf::Vector2f(rect_W / 3, rect_H));
    enemy2.setFillColor(sf::Color(0, 0, 0));
    enemy2.setOrigin(enemy2.getSize().x / 2, enemy2.getSize().y / 2);
    sf::RectangleShape enemy3(sf::Vector2f(rect_W / 3, rect_H));
    enemy3.setFillColor(sf::Color(0, 0, 0));
    enemy3.setOrigin(enemy3.getSize().x / 2, enemy3.getSize().y / 2);
    sf::RectangleShape enemy4(sf::Vector2f(rect_W / 3, rect_H));
    enemy4.setFillColor(sf::Color(0, 0, 0));
    enemy4.setOrigin(enemy4.getSize().x / 2, enemy4.getSize().y / 2);
    sf::RectangleShape enemy5(sf::Vector2f(rect_W / 3, rect_H));
    enemy5.setFillColor(sf::Color(0, 0, 0));
    enemy5.setOrigin(enemy5.getSize().x / 2, enemy5.getSize().y / 2);
    sf::RectangleShape enemy6(sf::Vector2f(rect_W / 3, rect_H));
    enemy6.setFillColor(sf::Color(0, 0, 0));
    enemy6.setOrigin(enemy6.getSize().x / 2, enemy6.getSize().y / 2);
    sf::RectangleShape enemy7(sf::Vector2f(rect_W / 3, rect_H));
    enemy7.setFillColor(sf::Color(0, 0, 0));
    enemy7.setOrigin(enemy7.getSize().x / 2, enemy7.getSize().y / 2);
    sf::RectangleShape enemy8(sf::Vector2f(rect_W / 3, rect_H));
    enemy8.setFillColor(sf::Color(0, 0, 0));
    enemy8.setOrigin(enemy8.getSize().x / 2, enemy8.getSize().y / 2);
    sf::RectangleShape enemy9(sf::Vector2f(rect_W / 3, rect_H));
    enemy9.setFillColor(sf::Color(0, 0, 0));
    enemy9.setOrigin(enemy9.getSize().x / 2, enemy9.getSize().y / 2);
    

    sf::RectangleShape back4(sf::Vector2f(1080, 720));
    sf::Texture texture4;
    if (!texture4.loadFromFile("4.png"))
        std::cout << "BRUH 4" << std::endl;
    texture4.setSmooth(true);
    back4.setTexture(&texture4);
    texture4.setRepeated(true);
   

    sf::RectangleShape back3(sf::Vector2f(1080, 720));
    sf::Texture texture3;
    if (!texture3.loadFromFile("3.png"))
        std::cout << "BRUH 3" << std::endl;
    texture3.setSmooth(true);
    back3.setTexture(&texture3);
    texture3.setRepeated(true);

    sf::RectangleShape back2(sf::Vector2f(1080, 720));
    sf::Texture texture2;
    if (!texture2.loadFromFile("2.png"))
        std::cout << "BRUH 2" << std::endl;
    texture2.setSmooth(true);
    back2.setTexture(&texture2);
    texture2.setRepeated(true);

    sf::RectangleShape back1(sf::Vector2f(1080, 720));
    sf::Texture texture1;
    if (!texture1.loadFromFile("1.png"))
        std::cout << "BRUH 1" << std::endl;
    texture1.setSmooth(true);
    back1.setTexture(&texture1);
    texture1.setRepeated(true);

    sf::Texture brick3;
    if (!brick3.loadFromFile("brick3.png"))
        std::cout << "BIG BRUH3" << std::endl;
    brick3.setSmooth(true);
    brick3.setRepeated(true);

    sf::CircleShape ball(rect_W / 2);
    ball.setPosition(rect_W*2, rect_H);
    sf::Texture ballT;
    if (!ballT.loadFromFile("ball.png"))
        std::cout << "SMALL BRUH" << std::endl;
    ballT.setSmooth(true);
    ballT.setRepeated(true);
    ball.setTexture(&ballT);
    ball.setFillColor(sf::Color(0, 0, 0));
    ball.setOrigin(45, 45);

    

    //srand((unsigned)time(NULL));

    /*std::fstream WallArray;
    WallArray.open("Move_Arr.txt", std::ios::out);

    if (!WallArray) {
        std::cout << " Error while creating the file ";
    }
    for (int i = 0; i < w; ++i)
    {


        for (int j = 0; j < h; ++j)
        {
            WallArray << Move_Arr[i][j].getPosition().x << std::endl << Move_Arr[i][j].getPosition().y << std::endl;
        }
    }
    WallArray.close();*/

    std::fstream WallReadArray;
    WallReadArray.open("Wall_Arr.txt", std::ios::in);
    if (!WallReadArray) {
       std::cout << "File doesn’t exist.";
    }
    std::fstream MoveReadArray;
    MoveReadArray.open("Move_Arr.txt", std::ios::in);
    if (!WallReadArray) {
        std::cout << "File doesn’t exist.";
    }

    
            int x1;
            /* 
            while (1) {
                WallReadArray >> x1;
                if (WallReadArray.eof())
                    break;
                std::cout << x1 << std::endl;
            }
   
            
            while (1) {
                MoveReadArray >> x1;
                if (MoveReadArray.eof())
                    break;
                std::cout << x1 << std::endl;
            }
     */
   

    for (int i = 0; i < w; ++i) 
    {


        for (int j = 0; j < h; ++j)
        {
            WallReadArray >> x1;
           // std::cout << " Wall["<< i << " ][" << j << "] =  X : " << x1;
            if (WallReadArray.eof())
                break;
            Wall_Arr[i][j].setPosition(x1, Wall_Arr[i][j].getPosition().y);
            WallReadArray >> x1;
            //std::cout << " :  Y : " << x1 << std::endl;
            if (WallReadArray.eof())
                break;
            Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x, x1);




            if (Wall_Arr[i][j].getPosition().x == -200)
            {
                Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x - Wall_Arr[i][j].getPosition().x - 10000, 0);
            }
            else
                Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + (74 * i) + rect_W/2, Wall_Arr[i][j].getPosition().y + (74 * j) + rect_W/2);
            
            Wall_Arr[i][j].setSize(size);
            //int r = rand() % 10;
            // Wall_Arr[i][j].setTexture(&grass1);
            //Wall_Arr[i][j].setOutlineThickness(1);
            Wall_Arr[i][j].setTexture(&brick3);
            if (j != 7 && j != 0)
                Wall_Arr[i][j].setRotation(90);
            Wall_Arr[i][j].setOutlineColor(sf::Color(0, 0, 0));
            Wall_Arr[i][j].setOrigin(rect_W / 2, rect_H / 2);



            MoveReadArray >> x1;
           // std::cout << " Move["<< i << " ][" << j << "] =  X : " << x1;
            if (MoveReadArray.eof())
                break;
            Move_Arr[i][j].setPosition(x1, Move_Arr[i][j].getPosition().y);
            MoveReadArray >> x1;
           // std::cout << " :  Y : " << x1 << std::endl;
            if (MoveReadArray.eof())
                break;
            Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x, x1);


            if (Move_Arr[i][j].getPosition().x == -200 || Move_Arr[i][j].getPosition().y > 112)
            {
                Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x - Move_Arr[i][j].getPosition().x - 10000, 0);
            }
            else
            Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + (74 * i) +rect_W/2, Move_Arr[i][j].getPosition().y + rect_W/2 + (74 * j) );
           
            Move_Arr[i][j].setSize(size);
            Move_Arr[i][j].setFillColor(sf::Color(200, 70, 70));
            Move_Arr[i][j].setOrigin(rect_W / 2, rect_H / 2);
           /* Move_Arr[i][j].setOutlineThickness(1);
            Move_Arr[i][j].setOutlineColor(sf::Color(0, 0, 0));*/
        }
    }
    
    
    WallReadArray.close();
    MoveReadArray.close();

    
    
    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                Window.close();
               
            }	

        }

        
        ballSpeed.x = ballSpeed.x * 0.25;
        if (ballSpeed.y < 50 && ground != true)
        {

            ballSpeed.y += rect_W * 0.015;

        }
        if (ballSpeed.y > 30 || ballSpeed.y < -30) {

            ballSpeed.y = 30;

        }

        B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
        B_j = ball.getPosition().y / rect_H;
        
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                ballSpeed.x = -rect_W * 0.25;
                r = it;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                ballSpeed.x = rect_W * 0.25;
                l = it;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {


                if (ball.getPosition().y > 20)
                {
                    ground = false;
                    ballSpeed.y = -(rect_W / 5);
                    q = it;
                }

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && it - q > 1)
            {
                ballSpeed.y = (ballSpeed.y + rect_H) * 0.25;
                q = it;
            }


        if (ball.getPosition().y <= 0)
        {
            if (it - j == 1)
                continue;



            ballSpeed.y = -ballSpeed.y + ballSpeed.y * 0.6;
            j = it;
            ball.setPosition(ball.getPosition().x, 0);


        }

        if (ball.getPosition().y >= Height - (ball.getRadius() * 2))
        {
            if (ground != true) {
                if (it - k - 1 == 0)
                    continue;
                ballSpeed.y = -ballSpeed.y * 0.6;
                ground = false;
                k = it;

            }
            if (ballSpeed.y > -7)
            {
                ground = true;
                ball.setPosition(ball.getPosition().x, Height - ball.getRadius() * 2);
                ballSpeed.y = 0;



            }
        }


        x = x - ballSpeed.x;
        ball.setPosition(ball.getPosition().x, ball.getPosition().y + ballSpeed.y);


        if (ballSpeed.x < 3 && ballSpeed.x > -3)
            ballSpeed.x = 0;

        //Positions 

        B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
        B_j = ball.getPosition().y / rect_H;
        //std::cout << "  Test Location : " << B_i << "  ;  " << B_j << std::endl;


        //TOP CHECKER

        if (Wall_Arr[B_i][B_j - 1].getPosition().x > -5000)
        {

            if (ball.getPosition().y < Move_Arr[B_i][B_j].getPosition().y)
            {
                T_col = true;
               // std::cout << "top collision: " << B_i << " ; " << B_j;
                ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                ballSpeed.y = -ballSpeed.y * 0;
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
                top = 5;
                ball.setRotation(ball.getRotation() - ballSpeed.x);
            }
        }

        //LEFT CHECKER

        if (Wall_Arr[B_i][B_j].getPosition().x > -5000)
        {

            if (ball.getPosition().x < Move_Arr[B_i + 1][B_j].getPosition().x)
            {
                //std::cout << " Left collision : " << B_i << " ; " << B_j << " ; WX = " << Wall_Arr[B_i][B_j].getPosition().x << " ; WY = " << Wall_Arr[B_i][B_j].getPosition().y << " ; ";
                loc = 180 - Move_Arr[B_i + 1][B_j].getPosition().x - 2;

                ball.setRotation(ball.getRotation() - ballSpeed.x);
                for (int i = 0; i < w; i++)
                    for (int j = 0; j < h; j++)
                    {
                        Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + loc, Wall_Arr[i][j].getPosition().y);
                        Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + loc, Move_Arr[i][j].getPosition().y);

                    }
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;

            }

        }

        //RIGHT CHECKER

        if (Wall_Arr[B_i + 1][B_j].getPosition().x > -5000 && Wall_Arr[B_i + 1][B_j].getPosition().y != 0)
        {

            if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x)
            {
                //std::cout << " Right collision : " << B_i + 1 << " ; " << B_j << " ; ";
                loc = 180 - Move_Arr[B_i][B_j].getPosition().x + 1;
                ball.setRotation(ball.getRotation() - ballSpeed.x);
                for (int i = 0; i < w; i++)
                    for (int j = 0; j < h; j++)
                    {
                        Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + loc, Wall_Arr[i][j].getPosition().y);
                        Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + loc, Move_Arr[i][j].getPosition().y);

                    }
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
            }

        }

        //TOP RIGHT CHECKER

        if (Wall_Arr[B_i + 1][B_j].getPosition().x > -5000 && Wall_Arr[B_i - 1][B_j].getPosition().x <= -5000)
        {

            if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x)
            {
                //std::cout << "top collision right : " << B_i << " ; " << B_j << " ; ";
                ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                ballSpeed.y = -ballSpeed.y * 0;
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
                ball.setRotation(ball.getRotation() - ballSpeed.x);
            }
        }

        //BOTTOM CHECKER

        if (Wall_Arr[B_i][B_j + 1].getPosition().x > -5000)
        {


            if (ball.getPosition().y > Move_Arr[B_i][B_j].getPosition().y)
            {
                //std::cout << "bottom collision : " << B_i << " ; " << B_j + 1 << " ; ";
                ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                ballSpeed.y = -ballSpeed.y * 0.25;
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
                g = it;
                ball.setRotation(ball.getRotation() - ballSpeed.x);
                if (ballSpeed.y > -6)
                {
                    ballSpeed.y = 0;
                    ground = true;
                }

            }
        }

        //BOTTOM RIGHT CHECKER

        if (Wall_Arr[B_i + 1][B_j + 1].getPosition().x > -5000 && Wall_Arr[B_i - 1][B_j + 1].getPosition().x <= -5000)
        {

            if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x)// && ballSpeed.y > 0)
            {
               // std::cout << "bottom collision right : " << B_i + 1 << " ; " << B_j + 1 << " ; ";
                ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                ballSpeed.y = -ballSpeed.y * 0.75;
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
                ball.setRotation(ball.getRotation() - ballSpeed.x);
            }
        }


        //Enemy Checker

        int temp_Rotation = ball.getRotation();
        ball.setRotation(0);
        if (ball.getGlobalBounds().intersects(enemy1.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy2.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy3.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy4.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy5.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy6.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy7.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy8.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy9.getGlobalBounds()))
        {
            ball.setPosition(rect_W * 2, rect_H);
            ballSpeed.x = 0;
            ballSpeed.y = 0;


            std::fstream WallReadArray2;
            WallReadArray2.open("Wall_Arr.txt", std::ios::in);
            if (!WallReadArray2) {
                std::cout << "File doesn’t exist.";
            }
            std::fstream MoveReadArray2;
            MoveReadArray2.open("Move_Arr.txt", std::ios::in);
            if (!WallReadArray2) {
                std::cout << "File doesn’t exist.";
            }


            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < h; j++)
                {
                    WallReadArray2 >> x1;
                    //std::cout << " Wall["<< i << " ][" << j << "] =  X : " << x1;
                    if (WallReadArray2.eof())
                        break;
                    Wall_Arr[i][j].setPosition(x1, Wall_Arr[i][j].getPosition().y);
                    WallReadArray2 >> x1;
                    //std::cout << " :  Y : " << x1 << std::endl;
                    if (WallReadArray2.eof())
                        break;
                    Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x, x1);

                    MoveReadArray2 >> x1;
                    // std::cout << " Move["<< i << " ][" << j << "] =  X : " << x1;
                    if (MoveReadArray2.eof())
                        break;
                    Move_Arr[i][j].setPosition(x1, Move_Arr[i][j].getPosition().y);
                    MoveReadArray2 >> x1;
                    // std::cout << " :  Y : " << x1 << std::endl;
                    if (MoveReadArray2.eof())
                        break;
                    Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x, x1);
                }
            }


            WallReadArray2.close();
            MoveReadArray2.close();
        }
        ball.setRotation(temp_Rotation);


        //MOVE AGAIN

        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
            {
                
                
                Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + ballSpeed.x /*+ loc*/, Wall_Arr[i][j].getPosition().y);
                Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + ballSpeed.x /*+ loc*/, Move_Arr[i][j].getPosition().y);
                
            }
        

        B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
        B_j = ball.getPosition().y / rect_H;
        //std::cout << "  Test Location : " << B_i << "  ;  " << B_j << std::endl;
        
         

        
   
        //TOP CHECKER

        if (Wall_Arr[B_i][B_j - 1].getPosition().x > -5000)
        {

            if (ball.getPosition().y < Move_Arr[B_i][B_j].getPosition().y)
            {
                T_col = true;
                //std::cout << "top collision: " << B_i << " ; " << B_j;
                ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                ballSpeed.y = -ballSpeed.y * 0;
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
                top = 5;
                ball.setRotation(ball.getRotation() - ballSpeed.x);
            }
        }
        //LEFT CHECKER

        if (Wall_Arr[B_i][B_j].getPosition().x > -5000)
        {

            if (ball.getPosition().x < Move_Arr[B_i + 1][B_j].getPosition().x)
            {
                col = true;
                LE_col = true;
                //std::cout << " Left collision : " << B_i << " ; " << B_j << " ; WX = " << Wall_Arr[B_i][B_j].getPosition().x << " ; WY = " << Wall_Arr[B_i][B_j].getPosition().y << " ; ";
                loc = 180 - Move_Arr[B_i + 1][B_j].getPosition().x - 2;

                ball.setRotation(ball.getRotation() - ballSpeed.x);
                for (int i = 0; i < w; i++)
                    for (int j = 0; j < h; j++)
                    {
                        Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + loc, Wall_Arr[i][j].getPosition().y);
                        Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + loc, Move_Arr[i][j].getPosition().y);

                    }
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;

            }

        }

        //RIGHT CHECKER
        
        if (Wall_Arr[B_i + 1][B_j].getPosition().x > -5000 && Wall_Arr[B_i + 1][B_j].getPosition().y != 0)
        {

            if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x)
            {
                col = true;
                R_col = true;
                //std::cout << " Right collision : " << B_i + 1 << " ; " << B_j << " ; ";
                loc = 180 - Move_Arr[B_i][B_j].getPosition().x + 1;
                ball.setRotation(ball.getRotation() - ballSpeed.x);
                for (int i = 0; i < w; i++)
                    for (int j = 0; j < h; j++)
                    {
                        Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + loc, Wall_Arr[i][j].getPosition().y);
                        Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + loc, Move_Arr[i][j].getPosition().y);

                    }
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
            }

        }

                //TOP RIGHT CHECKER

                if (Wall_Arr[B_i + 1][B_j].getPosition().x > -5000 && Wall_Arr[B_i - 1][B_j].getPosition().x <= -5000 )
                {
                   
                    if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x)// && ballSpeed.y < 0)
                    {
                        T_col = true;
                        //std::cout << "top collision right : " << B_i << " ; " << B_j << " ; ";
                        ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                        ballSpeed.y = -ballSpeed.y * 0;
                        B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                        B_j = ball.getPosition().y / rect_H;
                        ball.setRotation(ball.getRotation() - ballSpeed.x);
                    }
                }

                //BOTTOM CHECKER

                if (Wall_Arr[B_i][B_j + 1].getPosition().x > -5000)
                {
                    

                    if (ball.getPosition().y > Move_Arr[B_i][B_j].getPosition().y)
                    {
                        L_col = true;
                        //std::cout << "bottom collision : " << B_i << " ; " << B_j + 1 << " ; ";
                        ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                       ballSpeed.y = -ballSpeed.y * 0.25;
                        B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                        B_j = ball.getPosition().y / rect_H;
                        g = it;
                        ball.setRotation(ball.getRotation() - ballSpeed.x);
                               if (ballSpeed.y > -6)
                               {
                                        ballSpeed.y = 0;
                                        ground = true;
                               }
                       
                    }
                }

                //BOTTOM RIGHT CHECKER

                if (Wall_Arr[B_i + 1][B_j + 1].getPosition().x > -5000 && Wall_Arr[B_i - 1][B_j + 1].getPosition().x <= -5000)
                {
                    
                    if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x)
                    {
                        //std::cout << "bottom collision right : " << B_i + 1 << " ; " << B_j + 1 << " ; ";
                        ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                         ballSpeed.y = -ballSpeed.y * 0.75;
                          B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                          B_j = ball.getPosition().y / rect_H;
                          ball.setRotation(ball.getRotation() - ballSpeed.x);
                    }
                }


                //Enemy Checker
                temp_Rotation = ball.getRotation();
                ball.setRotation(0);
                if (ball.getGlobalBounds().intersects(enemy1.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy2.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy3.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy4.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy5.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy6.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy7.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy8.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy9.getGlobalBounds()))
                {
                    ball.setPosition(rect_W * 2, rect_H);
                    ballSpeed.x = 0;
                    ballSpeed.y = 0;


                    std::fstream WallReadArray2;
                    WallReadArray2.open("Wall_Arr.txt", std::ios::in);
                    if (!WallReadArray2) {
                        std::cout << "File doesn’t exist.";
                    }
                    std::fstream MoveReadArray2;
                    MoveReadArray2.open("Move_Arr.txt", std::ios::in);
                    if (!WallReadArray2) {
                        std::cout << "File doesn’t exist.";
                    }


                    for (int i = 0; i < w; i++)
                    {
                        for (int j = 0; j < h; j++)
                        {
                            WallReadArray2 >> x1;
                            //std::cout << " Wall["<< i << " ][" << j << "] =  X : " << x1;
                            if (WallReadArray2.eof())
                                break;
                            Wall_Arr[i][j].setPosition(x1, Wall_Arr[i][j].getPosition().y);
                            WallReadArray2 >> x1;
                            //std::cout << " :  Y : " << x1 << std::endl;
                            if (WallReadArray2.eof())
                                break;
                            Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x, x1);

                            MoveReadArray2 >> x1;
                            // std::cout << " Move["<< i << " ][" << j << "] =  X : " << x1;
                            if (MoveReadArray2.eof())
                                break;
                            Move_Arr[i][j].setPosition(x1, Move_Arr[i][j].getPosition().y);
                            MoveReadArray2 >> x1;
                            // std::cout << " :  Y : " << x1 << std::endl;
                            if (MoveReadArray2.eof())
                                break;
                            Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x, x1);
                        }
                    }
                    
                    
                    WallReadArray2.close();
                    MoveReadArray2.close();
                }
                ball.setRotation(temp_Rotation);


                if(top != 0)
                    top = top - 1;
                
                //Rotation

                if (ballSpeed.x != 0)
                {
                    ball.setRotation(ball.getRotation() - ballSpeed.x / 4);
                    if (ground == true)
                    {
                        ball.setRotation(ball.getRotation() - ballSpeed.x / 2);
                
                    }
                }
                
            
            if (Wall_Arr[B_i][B_j - 1].getPosition().x > -10000 && Wall_Arr[B_i][B_j + 1].getPosition().x > -10000)
            {
                ground == true;
                ballSpeed.y = 0;
            }

            if (Wall_Arr[B_i][B_j + 1].getPosition().x <= -10000)
                ground = false;
            

            //std::cout << std::endl << " Wall_Arr[102][0] Position X : " << Wall_Arr[102][0].getPosition().x << std::endl;

            //std::cout << "Iteration = " << it <<" ; Ball Position X = " << ball.getPosition().x << " ; Ball Position Y = " << ball.getPosition().y << " ; BallSpeed X= " << ballSpeed.x << " ; BallSpeed Y= " << ballSpeed.y << " ; " << "B_i = " << B_i << " ; B_j= " << B_j << " ; " << std::endl;
            

            it++;
            
           
            enemy1.setPosition(Move_Arr[16][6].getPosition().x, Move_Arr[16][6].getPosition().y);
            enemy2.setPosition(Move_Arr[29][6].getPosition().x, Move_Arr[35][6].getPosition().y);
            enemy3.setPosition(Move_Arr[35][6].getPosition().x, Move_Arr[29][6].getPosition().y);
            enemy4.setPosition(Move_Arr[50][6].getPosition().x, Move_Arr[50][6].getPosition().y);
            enemy5.setPosition(Move_Arr[52][6].getPosition().x, Move_Arr[52][6].getPosition().y);
            enemy6.setPosition(Move_Arr[55][6].getPosition().x, Move_Arr[55][6].getPosition().y);
            enemy7.setPosition(Move_Arr[58][6].getPosition().x, Move_Arr[58][6].getPosition().y);
            enemy8.setPosition(Move_Arr[85][5].getPosition().x, Move_Arr[85][5].getPosition().y);
            enemy9.setPosition(Move_Arr[96][5].getPosition().x, Move_Arr[96][5].getPosition().y);

            

            Window.clear();//sf::Color(200,70,70));
           
            Window.draw(back1);
            Window.draw(back2);
            Window.draw(back3);
            Window.draw(back4);
     
            for (int i = 0; i < (w - 10); i++)
                for (int j = 0; j < h; j++)
                {
                   /* if (Move_Arr[i][j].getPosition().x > -rect_W && Move_Arr[i][j].getPosition().x < Width + rect_W)
                        Window.draw(Move_Arr[i][j]);*/
                    if (Wall_Arr[i][j].getPosition().x > -rect_W && Wall_Arr[i][j].getPosition().x < Width + rect_W)
                        Window.draw(Wall_Arr[i][j]);
                    
                }
     

            Window.draw(ball);
           
            
            
            Window.draw(enemy1);
            Window.draw(enemy2);
            Window.draw(enemy3);
            Window.draw(enemy4);
            Window.draw(enemy5);
            Window.draw(enemy6);
            Window.draw(enemy7);
            Window.draw(enemy8);
            Window.draw(enemy9);


        

            Window.display();


    }
    return 0;
}


