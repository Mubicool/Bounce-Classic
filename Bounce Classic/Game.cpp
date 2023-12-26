#include <SFML/Graphics.hpp>
#include <iostream>
#include<cstdlib>
#include<cmath>
#include <fstream>


#define PI 3.1415926535898
const int w = 113;
const int h = 8;
const int li = 3;
sf::RectangleShape Move_Arr[w][h];
sf::RectangleShape Wall_Arr[w][h];
sf::RectangleShape grass1_Arr[w];
sf::RectangleShape grass2_Arr[w];
sf::RectangleShape grass3_Arr[w];
sf::RectangleShape grass4_Arr[w];
sf::RectangleShape grass5_Arr[w];
sf::RectangleShape grass6_Arr[w];
sf::RectangleShape grass7_Arr[w];
sf::RectangleShape grass8_Arr[w];
sf::RectangleShape grass9_Arr[w];
sf::RectangleShape grass10_Arr[w];
sf::RectangleShape grass11_Arr[w];
sf::CircleShape life_Arr[li];



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
    sf::Vector2f wallSpeed(0, 0);
    bool ground = false;
    int B_i = 0;
    int B_j = 0;
    float x = 0;
    int t = 0;
    int top = 0;
    int fps = 60;
    int loc = 0;
    int loc2 = 0;
    int rings = 0;
    int life = li;
    bool col = false;
    bool E_col = false;
    bool L_col = false;
    bool R_col = false;
    bool LE_col = false;

    sf::RenderWindow Window(sf::VideoMode(Width, Height), "Bounce Classic");
    Window.setFramerateLimit(fps);


    sf::Texture ballT;
    if (!ballT.loadFromFile("ball.png"))
        std::cout << "SMALL BRUH" << std::endl;
    ballT.setSmooth(true);
    ballT.setRepeated(true);


    for (int i = 0; i < li; i++)
    {
        
        life_Arr[i].setRadius(20);
        life_Arr[i].setFillColor(sf::Color(255, 255, 255));
        life_Arr[i].setPosition(45 * i + 45, 20);
        life_Arr[i].setTexture(&ballT);
    }

    sf::RectangleShape enemy1(sf::Vector2f(rect_W / 3, rect_H));
    enemy1.setFillColor(sf::Color(0, 0, 0));
    enemy1.setOrigin(enemy1.getSize().x / 2, enemy1.getSize().y / 2);
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


    sf::RectangleShape enemyTR(sf::Vector2f(60, 135));
    sf::Texture enemyT;
    if (!enemyT.loadFromFile("enemy.png"))
        std::cout << "enemyT BRUH 4" << std::endl;
    enemyT.setSmooth(true);
    enemyTR.setTexture(&enemyT);
    enemyT.setRepeated(true);

    sf::RectangleShape Gback1(sf::Vector2f(1080, 720));
    sf::Texture Gback;
    if (!Gback.loadFromFile("Gback1.png"))
        std::cout << "Gback1BRUH 4" << std::endl;
    Gback.setSmooth(true);
    Gback1.setTexture(&Gback);
    Gback.setRepeated(true);
    Gback1.setFillColor(sf::Color(255, 255, 255, 150));

   
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

    sf::Texture brick1;
    if (!brick1.loadFromFile("brick.png"))
        std::cout << "BIG BRUH1" << std::endl;
    brick1.setSmooth(true);
    brick1.setRepeated(true);

    sf::Texture brick2;
    if (!brick2.loadFromFile("brick2.png"))
        std::cout << "BIG BRUH2" << std::endl;
    brick2.setSmooth(true);
    brick2.setRepeated(true);

    sf::Texture grass1;
    if (!grass1.loadFromFile("grass1.png"))
        std::cout << "grass BRUH1" << std::endl;
    grass1.setSmooth(true);
    grass1.setRepeated(true);

    sf::Texture grass2;
    if (!grass2.loadFromFile("grass2.png"))
        std::cout << "grass BRUH2" << std::endl;
    grass2.setSmooth(true);
    grass2.setRepeated(true);

    sf::Texture grass3;
    if (!grass3.loadFromFile("grass3.png"))
        std::cout << "grass BRUH3" << std::endl;
    grass3.setSmooth(true);
    grass3.setRepeated(true);

    sf::Texture grass4;
    if (!grass4.loadFromFile("grass4.png"))
        std::cout << "grass BRUH4" << std::endl;
    grass4.setSmooth(true);
    grass4.setRepeated(true);

    sf::Texture grass5;
    if (!grass5.loadFromFile("grass5.png"))
        std::cout << "grass BRUH5" << std::endl;
    grass5.setSmooth(true);
    grass5.setRepeated(true);

    sf::Texture grass6;
    if (!grass6.loadFromFile("grass6.png"))
        std::cout << "grass BRUH6" << std::endl;
    grass6.setSmooth(true);
    grass6.setRepeated(true);

    sf::Texture grass7;
    if (!grass7.loadFromFile("grass7.png"))
        std::cout << "grass BRUH7" << std::endl;
    grass7.setSmooth(true);
    grass7.setRepeated(true);

    sf::Texture grass8;
    if (!grass8.loadFromFile("grass8.png"))
        std::cout << "grass BRUH8" << std::endl;
    grass8.setSmooth(true);
    grass8.setRepeated(true);

    sf::Texture grass9;
    if (!grass9.loadFromFile("grass9.png"))
        std::cout << "grass BRUH9" << std::endl;
    grass9.setSmooth(true);
    grass9.setRepeated(true);

    sf::Texture grass10;
    if (!grass10.loadFromFile("grass10.png"))
        std::cout << "grass BRUH10" << std::endl;
    grass10.setSmooth(true);
    grass10.setRepeated(true);

    sf::Texture grass11;
    if (!grass11.loadFromFile("grass11.png"))
        std::cout << "grass BRUH11" << std::endl;
    grass11.setSmooth(true);
    grass11.setRepeated(true);

    sf::RectangleShape ring1(sf::Vector2f(10, 10));
    sf::RectangleShape ring2(sf::Vector2f(10, 10));
    sf::RectangleShape ring3(sf::Vector2f(10, 10));
    sf::RectangleShape ring4(sf::Vector2f(10, 10));
    sf::RectangleShape ring5(sf::Vector2f(10, 10));
    sf::RectangleShape ring6(sf::Vector2f(10, 10));


    sf::RectangleShape ringR1(sf::Vector2f(180, 180));
    sf::Texture ringRT;
    if (!ringRT.loadFromFile("ring.png"))
        std::cout << "RING BRUH" << std::endl;
    ringRT.setSmooth(true);
    ringR1.setTexture(&ringRT);

    sf::RectangleShape ringR2(sf::Vector2f(180, 180));
    ringR2.setTexture(&ringRT);

    sf::RectangleShape ringR3(sf::Vector2f(180, 180));
    ringR3.setTexture(&ringRT);

    sf::RectangleShape ringR4(sf::Vector2f(180, 180));
    ringR4.setTexture(&ringRT);

    sf::RectangleShape ringR5(sf::Vector2f(180, 180));
    ringR5.setTexture(&ringRT);



    sf::CircleShape ball(rect_W / 2);
    ball.setPosition(rect_W * 2, rect_H);
    
    ball.setTexture(&ballT);
    ball.setFillColor(sf::Color(250, 255, 255));
    ball.setOrigin(45, 45);

    sf::CircleShape ballL(rect_W * 2);
    ballL.setPosition(ball.getPosition().x, ball.getPosition().y);
    sf::Texture balll;
    if (!balll.loadFromFile("ballL.png"))
        std::cout << "SMALL L BRUH" << std::endl;
    balll.setSmooth(true);
    balll.setRepeated(true);
    ballL.setTexture(&balll);
    ballL.setFillColor(sf::Color(250, 255, 150, 85));




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
                Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + (74 * i) + rect_W / 2, Wall_Arr[i][j].getPosition().y + (74 * j) + rect_W / 2);

            Wall_Arr[i][j].setSize(size);
            //int r = rand() % 10;
            // Wall_Arr[i][j].setTexture(&grass1);
            //Wall_Arr[i][j].setOutlineThickness(1);
            Wall_Arr[i][j].setTexture(&brick1);
            if (j != 7 && j != 0)
                Wall_Arr[i][j].setTexture(&brick2);
            //Wall_Arr[i][j].setRotation(90);
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
                Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + (74 * i) + rect_W / 2, Move_Arr[i][j].getPosition().y + rect_W / 2 + (74 * j));

            Move_Arr[i][j].setSize(size);
            Move_Arr[i][j].setFillColor(sf::Color(200, 70, 70));
            Move_Arr[i][j].setOrigin(rect_W / 2, rect_H / 2);
            /* Move_Arr[i][j].setOutlineThickness(1);
             Move_Arr[i][j].setOutlineColor(sf::Color(0, 0, 0));*/
            if (j == 7)
            {
                grass1_Arr[i].setSize(sf::Vector2f(90, 180));
                // grass1_Arr[i].setOrigin(grass1_Arr[i].getSize().x / 2, grass1_Arr[i].getSize().y / 2);
                 //grass1_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x , Wall_Arr[i][j].getPosition().y - 90);
                grass1_Arr[i].setTexture(&grass1);
            }
            if (j == 0)
            {
                grass2_Arr[i].setSize(sf::Vector2f(90, 180));
                //grass2_Arr[i].setOrigin(grass1_Arr[i].getSize().x / 2, grass1_Arr[i].getSize().y / 2);
                grass2_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 45, Wall_Arr[i][j].getPosition().y);
                grass2_Arr[i].setTexture(&grass2);
            }

            grass3_Arr[i].setSize(sf::Vector2f(180, 90));
            grass3_Arr[i].setTexture(&grass3);

            grass4_Arr[i].setSize(sf::Vector2f(180, 90));
            grass4_Arr[i].setTexture(&grass4);

            grass5_Arr[i].setSize(sf::Vector2f(180, 180));
            grass5_Arr[i].setTexture(&grass5);

            grass6_Arr[i].setSize(sf::Vector2f(180, 180));
            grass6_Arr[i].setTexture(&grass6);

            grass7_Arr[i].setSize(sf::Vector2f(90, 90));
            grass7_Arr[i].setTexture(&grass7);

            grass8_Arr[i].setSize(sf::Vector2f(180, 180));
            grass8_Arr[i].setTexture(&grass8);

            grass9_Arr[i].setSize(sf::Vector2f(180, 180));
            grass9_Arr[i].setTexture(&grass9);

            grass10_Arr[i].setSize(sf::Vector2f(180, 270));
            grass10_Arr[i].setTexture(&grass10);

            grass11_Arr[i].setSize(sf::Vector2f(180, 270));
            grass11_Arr[i].setTexture(&grass11);

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
        if (ballSpeed.y > 50 || ballSpeed.y < -50) {

            ballSpeed.y = 50;

        }

        B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
        B_j = ball.getPosition().y / rect_H;


        //KEYPRESS CHECK

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && it - temp_it > 10)
        {
            B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
            B_j = ball.getPosition().y / rect_H;
            std::cout << B_i << " ; " << B_j << std::endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            ballSpeed.x = -rect_W * 0.20; //0.25
            r = it;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            ballSpeed.x = rect_W * 0.20; //0.25
            l = it;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && col != false)
        {


            if (ball.getPosition().y > 20)
            {
                ground = false;
                ballSpeed.y = -(rect_W / 2.8);
                col = false;
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
        std::cout << std::endl << "  Test Location 1 : " << B_i << "  ;  " << B_j;


        //TOP CHECKER

        if (Wall_Arr[B_i][B_j - 1].getPosition().x > -5000)
        {

            if (ball.getPosition().y < Move_Arr[B_i][B_j].getPosition().y)
            {

                //std::cout << " ; top collision : " << B_i << " ; " << B_j;
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
                //std::cout << " ; Left collision : " << B_i << " ; " << B_j;// << " ; WX = " << Wall_Arr[B_i][B_j].getPosition().x << " ; WY = " << Wall_Arr[B_i][B_j].getPosition().y << " ; ";
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
                //std::cout << " ; Right collision : " << B_i + 1 << " ; " << B_j << " ; ";
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
                //std::cout << " ; top collision right : " << B_i << " ; " << B_j << " ; ";
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
            if (B_i == 84 && B_j == 4)
            {
                ground = false;
            }
            else
            {
                if (ball.getPosition().y > Move_Arr[B_i][B_j].getPosition().y)
                {
                    col = true;
                    //std::cout << " ; bottom collision : " << B_i << " ; " << B_j + 1 << " ; ";
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
        }

        //BOTTOM RIGHT CHECKER

        if (Wall_Arr[B_i + 1][B_j + 1].getPosition().x > -5000 && Wall_Arr[B_i][B_j + 1].getPosition().x <= -5000)
        {
            if (B_i == 96 && B_j == 4)
            {
                std::cout << std::endl << "Hello";
                if (ball.getGlobalBounds().intersects(enemy9.getGlobalBounds()) != true)
                    ball.setPosition(ball.getPosition().x, Move_Arr[96][3].getPosition().y + rect_H);
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
            }
            else
            {

                if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x && ballSpeed.y > 0)
                {
                    col = true;
                    //std::cout << " ; bottom collision right : " << B_i + 1 << " ; " << B_j + 1 << " ; ";
                    ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                    ballSpeed.y = -ballSpeed.y * 0.75;
                    if (ballSpeed.y > -6)
                    {
                        ballSpeed.y = 0;
                        ground = true;
                    }
                    B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                    B_j = ball.getPosition().y / rect_H;
                    ball.setRotation(ball.getRotation() - ballSpeed.x);
                }
            }



        }
        //MOVE AGAIN

        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
            {


                Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + ballSpeed.x /*+ loc*/, Wall_Arr[i][j].getPosition().y);
                Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + ballSpeed.x /*+ loc*/, Move_Arr[i][j].getPosition().y);

            }


        B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
        B_j = ball.getPosition().y / rect_H;
        // std::cout << std::endl << "Test Location 2 : " << B_i << "  ;  " << B_j ;





         //TOP CHECKER

        if (Wall_Arr[B_i][B_j - 1].getPosition().x > -5000)
        {

            if (ball.getPosition().y < Move_Arr[B_i][B_j].getPosition().y)
            {

                //std::cout << " ; top collision: " << B_i << " ; " << B_j;
                ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                ballSpeed.y = -ballSpeed.y * 0;
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
                ball.setRotation(ball.getRotation() - ballSpeed.x);
            }
        }
        //LEFT CHECKER

        if (Wall_Arr[B_i][B_j].getPosition().x > -5000)
        {

            if (ball.getPosition().x < Move_Arr[B_i + 1][B_j].getPosition().x)
            {

                LE_col = true;
                //std::cout << " ; Left collision : " << B_i << " ; " << B_j;// << " ; WX = " << Wall_Arr[B_i][B_j].getPosition().x << " ; WY = " << Wall_Arr[B_i][B_j].getPosition().y << " ; ";
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

                R_col = true;
                //std::cout << " ; Right collision : " << B_i + 1 << " ; " << B_j << " ; ";
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

            if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x)// && ballSpeed.y < 0)
            {

                //std::cout << " ; top collision right : " << B_i << " ; " << B_j << " ; ";
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
            if (B_i == 84 && B_j == 4)
            {
                ground = false;
            }
            else
            {
                if (ball.getPosition().y > Move_Arr[B_i][B_j].getPosition().y)
                {
                    col = true;
                    //std::cout << " ; bottom collision : " << B_i << " ; " << B_j + 1 << " ; ";
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
        }

        //BOTTOM RIGHT CHECKER

        if (Wall_Arr[B_i + 1][B_j + 1].getPosition().x > -5000 && Wall_Arr[B_i][B_j + 1].getPosition().x <= -5000)
        {
            if (B_i == 96 && B_j == 4)
            {
                std::cout << std::endl << "Hello";
                if (ball.getGlobalBounds().intersects(enemy9.getGlobalBounds()) != true)
                    ball.setPosition(ball.getPosition().x, Move_Arr[96][3].getPosition().y + rect_H);
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
            }
            else
            {

                if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x && ballSpeed.y > 0)
                {
                    col = true;
                    //std::cout << " ; bottom collision right : " << B_i + 1 << " ; " << B_j + 1 << " ; ";
                    ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                    ballSpeed.y = -ballSpeed.y * 0.75;
                    if (ballSpeed.y > -6)
                    {
                        ballSpeed.y = 0;
                        ground = true;
                    }
                    B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                    B_j = ball.getPosition().y / rect_H;
                    ball.setRotation(ball.getRotation() - ballSpeed.x);
                }
            }

        }



        //END LEVEL

        if (B_i == 101 && B_j == 6)
            break;

        if (ringR1.getPosition().x + 90 < ball.getPosition().x)
        {
            ringR1.setFillColor(sf::Color(255, 255, 255));
            rings = 1;
            if (ringR2.getPosition().x + 90 < ball.getPosition().x)
            {
                ringR2.setFillColor(sf::Color(255, 255, 255));
                rings = 2;
                if (ringR3.getPosition().x + 90 < ball.getPosition().x)
                {
                    ringR3.setFillColor(sf::Color(255, 255, 255));
                    rings = 3;
                    if (ringR4.getPosition().x + 90 < ball.getPosition().x)
                    {
                        ringR4.setFillColor(sf::Color(255, 255, 255));
                        rings = 4;
                        if (ringR5.getPosition().x + 90 < ball.getPosition().x)
                        {
                            ringR5.setFillColor(sf::Color(255, 255, 255));
                            rings = 5;
                        }
                        else
                        {
                            ringR5.setFillColor(sf::Color(100, 100, 100));
                            rings = 4;
                        }
                    }
                    else
                    {
                        ringR4.setFillColor(sf::Color(100, 100, 100));
                        rings = 3;
                    }
                }
                else
                {
                    ringR3.setFillColor(sf::Color(100, 100, 100));
                    rings = 2;
                }

            }
            else
            {
                ringR2.setFillColor(sf::Color(100, 100, 100));
                rings = 1;
            }


        }
        else
        {
            ringR1.setFillColor(sf::Color(100, 100, 100));
            rings = 0;
        }




        //Enemy Checker
        int temp_Rotation = ball.getRotation();
        ball.setRotation(0);
        if (ball.getGlobalBounds().intersects(enemy1.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy2.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy3.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy4.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy5.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy6.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy7.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy8.getGlobalBounds()) || ball.getGlobalBounds().intersects(enemy9.getGlobalBounds()))
        {
            life--;
            life_Arr[life].setPosition(-100,-100);
            if (life == 0)
                break;

            col = false;
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

                    if (Wall_Arr[i][j].getPosition().x == -200)
                    {
                        Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x - Wall_Arr[i][j].getPosition().x - 10000, 0);
                    }
                    else
                        Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + (74 * i) + rect_W / 2, Wall_Arr[i][j].getPosition().y + (74 * j) + rect_W / 2);

                    MoveReadArray2 >> x1;
                    //std::cout << " Move["<< i << " ][" << j << "] =  X : " << x1;
                    if (MoveReadArray2.eof())
                        break;
                    Move_Arr[i][j].setPosition(x1, Move_Arr[i][j].getPosition().y);
                    MoveReadArray2 >> x1;
                    //std::cout << " :  Y : " << x1 << std::endl;
                    if (MoveReadArray2.eof())
                        break;
                    Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x, x1);

                    if (Move_Arr[i][j].getPosition().x == -200 || Move_Arr[i][j].getPosition().y > 112)
                    {
                        Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x - Move_Arr[i][j].getPosition().x - 10000, 0);
                    }
                    else
                        Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + (74 * i) + rect_W / 2, Move_Arr[i][j].getPosition().y + rect_W / 2 + (74 * j));



                }
            }

            ball.setPosition(ball.getPosition().x, 92);
            ballSpeed.x = 0;
            ballSpeed.y = 0;
            WallReadArray2.close();
            MoveReadArray2.close();
        }
        ball.setRotation(temp_Rotation);


        if (top != 0)
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
            std::cout << "!!!!!!!!! TUNNEL DETECTED !!!!!!!!!!!" << std::endl;
            ground == true;
            ballSpeed.y = 0;
        }

        if (Wall_Arr[B_i][B_j + 1].getPosition().x <= -10000)
            ground = false;


        //std::cout << std::endl << " Wall_Arr[102][0] Position X : " << Wall_Arr[102][0].getPosition().x << std::endl;

        //std::cout << " ; Iteration = " << it <<" ; Ball Position X = " << ball.getPosition().x << " ; Ball Position Y = " << ball.getPosition().y << " ; BallSpeed X= " << ballSpeed.x << " ; BallSpeed Y= " << ballSpeed.y << " ; " << "B_i = " << B_i << " ; B_j= " << B_j << " ; " << std::endl;

        std::cout << rings << std::endl;

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



        Window.clear();// sf::Color(0, 0, 0, 255));

        /* Window.draw(back1);
         Window.draw(back2);
         Window.draw(back3);
         Window.draw(back4);
  */

        Window.draw(Gback1);

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

        enemyTR.setPosition(enemy1.getPosition().x - 30, enemy1.getPosition().y - 135);
        //Window.draw(enemyTR);


        //SET AND DRAW TEXTURES

       // ring1.setPosition(Wall_Arr[8][7].getPosition().x, Wall_Arr[8][7].getPosition().y - 190);
        ringR1.setPosition(Wall_Arr[8][7].getPosition().x - 90, Wall_Arr[8][7].getPosition().y - 210);
        ringR2.setPosition(Wall_Arr[31][4].getPosition().x, Wall_Arr[31][4].getPosition().y - 230);
        ringR3.setPosition(Wall_Arr[72][7].getPosition().x - 45, Wall_Arr[72][7].getPosition().y - 230);
        ringR4.setPosition(Wall_Arr[88][7].getPosition().x + 45, Wall_Arr[88][7].getPosition().y - 230);
        ringR5.setPosition(Wall_Arr[92][7].getPosition().x - 135, Wall_Arr[92][7].getPosition().y - 230);

        Window.draw(ringR1);
        Window.draw(ringR2);
        Window.draw(ringR3);
        Window.draw(ringR4);
        Window.draw(ringR5);

        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
            {

                if (Wall_Arr[i][j].getPosition().x > -rect_W && Wall_Arr[i][j].getPosition().x < Width + rect_W)
                {


                    if (Wall_Arr[i][j].getPosition().x > -5000)
                    {
                        grass7_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 45, Wall_Arr[i][j].getPosition().y - 45);
                        Window.draw(grass7_Arr[i]);
                    }
                    //if(j!=0 && Move_Arr[i][j-1].getGlobalBounds().intersects(enemy1.getGlobalBounds()) != true && Move_Arr[i][j - 1].getGlobalBounds().intersects(enemy2.getGlobalBounds()) != true && Move_Arr[i][j - 1].getGlobalBounds().intersects(enemy3.getGlobalBounds()) != true && Move_Arr[i][j - 1].getGlobalBounds().intersects(enemy4.getGlobalBounds()) != true && Move_Arr[i][j - 1].getGlobalBounds().intersects(enemy5.getGlobalBounds()) != true && Move_Arr[i][j - 1].getGlobalBounds().intersects(enemy6.getGlobalBounds()) != true && Move_Arr[i][j - 1].getGlobalBounds().intersects(enemy7.getGlobalBounds()) != true && Move_Arr[i][j - 1].getGlobalBounds().intersects(enemy8.getGlobalBounds()) != true)
                    //{ 
                    if (j == 7)
                    {

                        grass1_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 45, Wall_Arr[i][j].getPosition().y - 135);
                        Window.draw(grass1_Arr[i]);

                    }
                    if (j == 0 && Wall_Arr[i][j + 1].getPosition().x <= -5000)
                    {
                        grass2_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 45, Wall_Arr[i][j].getPosition().y - 45);
                        Window.draw(grass2_Arr[i]);
                    }

                    if (i != 0 && j != 7 && j != 0)
                    {

                        if (Wall_Arr[i][j].getPosition().x > -5000 && Wall_Arr[i - 1][j].getPosition().x <= -5000 && Wall_Arr[i][j + 1].getPosition().x > -5000)
                        {
                            grass3_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 135, Wall_Arr[i][j].getPosition().y - 45);
                            if (grass3_Arr[i].getGlobalBounds().intersects(enemy8.getGlobalBounds()) != true && grass3_Arr[i].getGlobalBounds().intersects(enemy9.getGlobalBounds()) != true)
                                Window.draw(grass3_Arr[i]);
                        }

                        if (Wall_Arr[i][j].getPosition().x > -5000 && Wall_Arr[i + 1][j].getPosition().x <= -5000 && Wall_Arr[i][j + 1].getPosition().x > -5000)
                        {
                            grass4_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 45, Wall_Arr[i][j].getPosition().y - 45);
                            if (grass4_Arr[i].getGlobalBounds().intersects(enemy9.getGlobalBounds()) != true && grass4_Arr[i].getGlobalBounds().intersects(enemy8.getGlobalBounds()) != true)
                                Window.draw(grass4_Arr[i]);
                        }

                        if (Wall_Arr[i][j].getPosition().x > -5000 && Wall_Arr[i - 1][j].getPosition().x <= -5000 && Wall_Arr[i][j + 1].getPosition().x > -5000 && Wall_Arr[i][j - 1].getPosition().x <= -5000)
                        {

                            grass5_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 135, Wall_Arr[i][j].getPosition().y - 135);
                            if (grass5_Arr[i].getGlobalBounds().intersects(enemy8.getGlobalBounds()) != true && grass5_Arr[i].getGlobalBounds().intersects(enemy9.getGlobalBounds()) != true)
                                Window.draw(grass5_Arr[i]);
                        }

                        if (Wall_Arr[i][j].getPosition().x > -5000 && Wall_Arr[i + 1][j].getPosition().x <= -5000 && Wall_Arr[i][j + 1].getPosition().x > -5000 && Wall_Arr[i][j - 1].getPosition().x <= -5000)
                        {

                            grass6_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 45, Wall_Arr[i][j].getPosition().y - 135);
                            if (grass6_Arr[i].getGlobalBounds().intersects(enemy8.getGlobalBounds()) != true && grass6_Arr[i].getGlobalBounds().intersects(enemy9.getGlobalBounds()) != true)
                                Window.draw(grass6_Arr[i]);
                        }

                        if (Wall_Arr[i][j].getPosition().x > -5000 && Wall_Arr[i - 1][j].getPosition().x <= -5000 && Wall_Arr[i][j - 1].getPosition().x > -5000 && Wall_Arr[i][j + 1].getPosition().x <= -5000)
                        {

                            grass8_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 130, Wall_Arr[i][j].getPosition().y - 60);
                            Window.draw(grass8_Arr[i]);
                        }

                        if (Wall_Arr[i][j].getPosition().x > -5000 && Wall_Arr[i + 1][j].getPosition().x <= -5000 && Wall_Arr[i][j - 1].getPosition().x > -5000 && Wall_Arr[i][j + 1].getPosition().x <= -5000)
                        {
                            grass9_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 45, Wall_Arr[i][j].getPosition().y - 60);
                            Window.draw(grass9_Arr[i]);
                        }

                        if (Wall_Arr[i][j].getPosition().x > -5000 && Wall_Arr[i + 1][j].getPosition().x <= -5000 && Wall_Arr[i - 1][j].getPosition().x > -5000 && Wall_Arr[i][j + 1].getPosition().x <= -5000 && Wall_Arr[i][j - 1].getPosition().x <= -5000)
                        {
                            grass10_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 45, Wall_Arr[i][j].getPosition().y - 145);
                            Window.draw(grass10_Arr[i]);
                        }

                        if (Wall_Arr[i][j].getPosition().x > -5000 && Wall_Arr[i + 1][j].getPosition().x > -5000 && Wall_Arr[i - 1][j].getPosition().x <= -5000 && Wall_Arr[i][j + 1].getPosition().x <= -5000 && Wall_Arr[i][j - 1].getPosition().x <= -5000)
                        {
                            grass11_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 135, Wall_Arr[i][j].getPosition().y - 145);
                            Window.draw(grass11_Arr[i]);
                        }

                        if (Wall_Arr[i][j].getPosition().x > -5000 && Wall_Arr[i - 1][j].getPosition().x > -5000 && Wall_Arr[i + 1][j].getPosition().x > -5000 && Wall_Arr[i][j - 1].getPosition().x <= -5000)
                        {

                            grass1_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 45, Wall_Arr[i][j].getPosition().y - 135);
                            Window.draw(grass1_Arr[i]);

                        }

                        if (Wall_Arr[i][j].getPosition().x > -5000 && Wall_Arr[i - 1][j].getPosition().x > -5000 && Wall_Arr[i + 1][j].getPosition().x > -5000 && Wall_Arr[i][j + 1].getPosition().x <= -5000)
                        {
                            grass2_Arr[i].setPosition(Wall_Arr[i][j].getPosition().x - 45, Wall_Arr[i][j].getPosition().y - 45);
                            Window.draw(grass2_Arr[i]);
                        }

                    }
                    //}

                }
                /* if (Move_Arr[i][j].getPosition().x > -rect_W && Move_Arr[i][j].getPosition().x < Width + rect_W)
                    Window.draw(Move_Arr[i][j]);*/

                    /*if (Wall_Arr[i][j].getPosition().x > -rect_W && Wall_Arr[i][j].getPosition().x < Width + rect_W)
                    Window.draw(Wall_Arr[i][j]);*/




            }

           
        ballL.setPosition(ball.getPosition().x - 180, ball.getPosition().y - 180);
        Window.draw(ballL);

        for (int i = 0; i < li; i++)
            Window.draw(life_Arr[i]);




        // Window.draw(ball);

    /*

    Window.draw(enemy1);
    Window.draw(enemy2);
    Window.draw(enemy3);
    Window.draw(enemy4);
    Window.draw(enemy5);
    Window.draw(enemy6);
    Window.draw(enemy7);
    Window.draw(enemy8);
    Window.draw(enemy9);
*/


//ring12.setPosition(Wall_Arr[8][7].getPosition().x, Wall_Arr[8][7].getPosition().y - 55);


// Window.draw(ring1);
        
        Window.display();


    }
    return 0;
}


