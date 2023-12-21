#include <SFML/Graphics.hpp>
#include <iostream>
#include<cstdlib>
//#include <fstream>

int main()
{
    int Width = 1080;
    int Height = 720;
    int rect_W = 90;
    int rect_H = 90;
    const int w = 113;
    const int h = 8;
    int it = 0;
    int temp_it = 0;
    int r = 0;
    int l = 0;
    int q = 0;
    int k = 0;
    int j = 0;
    int g = 0;
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
    bool col = false;
    //std::ofstream outfile1;
    //std::ofstream outfile2;
    ///*outfile.open("Arrays");*/
    //outfile1.open("Wall_Arr.txt");
    //outfile2.open("Move_Arr.txt");

    sf::RenderWindow Window(sf::VideoMode(Width, Height), "Bounce Classic");
    Window.setFramerateLimit(fps);

    sf::Vector2f size(rect_W, rect_H);
    sf::RectangleShape block(size);
    block.setOutlineThickness(1);
    block.setOutlineColor(sf::Color(100, 0, 0));
    block.setPosition(0, 0);

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

    sf::Texture brick;
    if (!brick.loadFromFile("brick.png"))
        std::cout << "BIG BRUH" << std::endl;
    brick.setSmooth(true);
    brick.setRepeated(true);

    sf::Texture brick2;
    if (!brick2.loadFromFile("brick2.png"))
        std::cout << "BIG BRUH2" << std::endl;
    brick2.setSmooth(true);
    brick2.setRepeated(true);

    sf::Texture brick3;
    if (!brick3.loadFromFile("brick3.png"))
        std::cout << "BIG BRUH3" << std::endl;
    brick3.setSmooth(true);
    brick3.setRepeated(true);

    sf::Texture brick4;
    if (!brick4.loadFromFile("brick4.png"))
        std::cout << "BIG BRUH4" << std::endl;
    brick4.setSmooth(true);
    brick4.setRepeated(true);

    sf::Texture brick5;
    if (!brick5.loadFromFile("brick5.png"))
        std::cout << "BIG BRUH5" << std::endl;
    brick5.setSmooth(true);
    brick5.setRepeated(true);

    sf::Texture gras;
    if (!gras.loadFromFile("grass.png"))
        std::cout << "BIG BRUH grassss" << std::endl;
    gras.setSmooth(true);
    gras.setRepeated(true);

    sf::RectangleShape ghass(sf::Vector2f(2500, 200));
    ghass.setPosition(0, 520);
    sf::Texture Lgrass;
    if (!Lgrass.loadFromFile("Lgrass.png"))
        std::cout << "BIG LONG BRUH grassss" << std::endl;
    Lgrass.setSmooth(true);
    Lgrass.setRepeated(true);
    ghass.setTexture(&Lgrass);

    //sf::RectangleShape ghass2(sf::Vector2f(2500, 200));
    //ghass2.setPosition(2500, 520);
    //sf::Texture Lgrass2;
    //if (!Lgrass2.loadFromFile("Lgrass.png"))
    //    std::cout << "BIG LONG BRUH grassss2" << std::endl;
    //Lgrass2.setSmooth(true);
    //Lgrass2.setRepeated(true);
    //ghass2.setTexture(&Lgrass2);

    //sf::RectangleShape ghass3(sf::Vector2f(2500, 200));
    //ghass3.setPosition(5000, 520);
    //sf::Texture Lgrass3;
    //if (!Lgrass3.loadFromFile("Lgrass.png"))
    //    std::cout << "BIG LONG BRUH grassss2" << std::endl;
    //Lgrass3.setSmooth(true);
    //Lgrass3.setRepeated(true);
    //ghass3.setTexture(&Lgrass3);

    //sf::RectangleShape ghass4(sf::Vector2f(2500, 200));
    //ghass4.setPosition(7500, 520);
    //sf::Texture Lgrass4;
    //if (!Lgrass4.loadFromFile("Lgrass.png"))
    //    std::cout << "BIG LONG BRUH grassss" << std::endl;
    //Lgrass4.setSmooth(true);
    //Lgrass4.setRepeated(true);
    //ghass4.setTexture(&Lgrass);

    //sf::RectangleShape ghass5(sf::Vector2f(1080, 200));
    //ghass5.setPosition(4320, 520);
    //sf::Texture Lgrass5;
    //if (!Lgrass5.loadFromFile("Lgrass.png"))
    //    std::cout << "BIG LONG BRUH grassss2" << std::endl;
    //Lgrass5.setSmooth(true);
    //Lgrass5.setRepeated(true);
    //ghass5.setTexture(&Lgrass2);

    //sf::RectangleShape ghass6(sf::Vector2f(1080, 200));
    //ghass6.setPosition(5400, 520);
    //sf::Texture Lgrass6;
    //if (!Lgrass6.loadFromFile("Lgrass.png"))
    //    std::cout << "BIG LONG BRUH grassss2" << std::endl;
    //Lgrass6.setSmooth(true);
    //Lgrass6.setRepeated(true);
    //ghass6.setTexture(&Lgrass3);



    sf::RectangleShape Move_Arr[w][h];
    sf::RectangleShape Wall_Arr[w][h];

    sf::CircleShape ball(rect_W/2);
    ball.setFillColor(sf::Color(0, 0, 0));
    ball.setPosition(rect_W*2, rect_H *1);
    sf::Texture ballT;
    if (!ballT.loadFromFile("ball.png"))
        std::cout << "SMALL BRUH" << std::endl;
    ballT.setSmooth(true);
    ballT.setRepeated(true);
    ball.setTexture(&ballT);
    
    Wall_Arr[0][0].setPosition(0, 0);
    Wall_Arr[0][1].setPosition(0, 16);
    Wall_Arr[0][2].setPosition(0, 32);
    Wall_Arr[0][3].setPosition(0, 48);
    Wall_Arr[0][4].setPosition(0, 64);
    Wall_Arr[0][5].setPosition(0, 80);
    Wall_Arr[0][6].setPosition(0, 96);
    Wall_Arr[0][7].setPosition(0, 112);
    Wall_Arr[1][0].setPosition(16, 0);
    Wall_Arr[1][1].setPosition(16, 16);
    Wall_Arr[1][2].setPosition(16, 32);
    Wall_Arr[1][3].setPosition(16, 48);
    Wall_Arr[1][4].setPosition(16, 64);
    Wall_Arr[1][5].setPosition(16, 80);
    Wall_Arr[1][6].setPosition(16, 96);
    Wall_Arr[1][7].setPosition(16, 112);
    Wall_Arr[2][0].setPosition(32, 0);
    Wall_Arr[2][1].setPosition(-200, 0);
    Wall_Arr[2][2].setPosition(-200, 0);
    Wall_Arr[2][3].setPosition(-200, 0);
    Wall_Arr[2][4].setPosition(-200, 0);
    Wall_Arr[2][5].setPosition(-200, 0);
    Wall_Arr[2][6].setPosition(-200, 0);
    Wall_Arr[2][7].setPosition(32, 112);
    Wall_Arr[3][0].setPosition(48, 0);
    Wall_Arr[3][1].setPosition(-200, 0);
    Wall_Arr[3][2].setPosition(-200, 0);
    Wall_Arr[3][3].setPosition(-200, 0);
    Wall_Arr[3][4].setPosition(-200, 0);
    Wall_Arr[3][5].setPosition(-200, 0);
    Wall_Arr[3][6].setPosition(-200, 0);
    Wall_Arr[3][7].setPosition(48, 112);
    Wall_Arr[4][0].setPosition(64, 0);
    Wall_Arr[4][1].setPosition(-200, 0);
    Wall_Arr[4][2].setPosition(-200, 0);
    Wall_Arr[4][3].setPosition(-200, 0);
    Wall_Arr[4][4].setPosition(-200, 0);
    Wall_Arr[4][5].setPosition(-200, 0);
    Wall_Arr[4][6].setPosition(-200, 0);
    Wall_Arr[4][7].setPosition(64, 112);
    Wall_Arr[5][0].setPosition(80, 0);
    Wall_Arr[5][1].setPosition(80, 16);
    Wall_Arr[5][2].setPosition(80, 32);
    Wall_Arr[5][3].setPosition(80, 48);
    Wall_Arr[5][4].setPosition(80, 64);
    Wall_Arr[5][5].setPosition(-200, 0);
    Wall_Arr[5][6].setPosition(-200, 0);
    Wall_Arr[5][7].setPosition(80, 112);
    Wall_Arr[6][0].setPosition(96, 0);
    Wall_Arr[6][1].setPosition(96, 16);
    Wall_Arr[6][2].setPosition(96, 32);
    Wall_Arr[6][3].setPosition(96, 48);
    Wall_Arr[6][4].setPosition(96, 64);
    Wall_Arr[6][5].setPosition(-200, 0);
    Wall_Arr[6][6].setPosition(-200, 0);
    Wall_Arr[6][7].setPosition(96, 112);
    Wall_Arr[7][0].setPosition(112, 0);
    Wall_Arr[7][1].setPosition(112, 16);
    Wall_Arr[7][2].setPosition(112, 32);
    Wall_Arr[7][3].setPosition(112, 48);
    Wall_Arr[7][4].setPosition(112, 64);
    Wall_Arr[7][5].setPosition(-200, 0);
    Wall_Arr[7][6].setPosition(-200, 0);
    Wall_Arr[7][7].setPosition(112, 112);
    Wall_Arr[8][0].setPosition(128, 0);
    Wall_Arr[8][1].setPosition(128, 16);
    Wall_Arr[8][2].setPosition(128, 32);
    Wall_Arr[8][3].setPosition(128, 48);
    Wall_Arr[8][4].setPosition(128, 64);
    Wall_Arr[8][5].setPosition(-200, 0);
    Wall_Arr[8][6].setPosition(-200, 0);
    Wall_Arr[8][7].setPosition(128, 112);
    Wall_Arr[9][0].setPosition(144, 0);
    Wall_Arr[9][1].setPosition(144, 16);
    Wall_Arr[9][2].setPosition(144, 32);
    Wall_Arr[9][3].setPosition(144, 48);
    Wall_Arr[9][4].setPosition(144, 64);
    Wall_Arr[9][5].setPosition(-200, 0);
    Wall_Arr[9][6].setPosition(-200, 0);
    Wall_Arr[9][7].setPosition(144, 112);
    Wall_Arr[10][0].setPosition(160, 0);
    Wall_Arr[10][1].setPosition(-200, 0);
    Wall_Arr[10][2].setPosition(-200, 0);
    Wall_Arr[10][3].setPosition(-200, 0);
    Wall_Arr[10][4].setPosition(-200, 0);
    Wall_Arr[10][5].setPosition(-200, 0);
    Wall_Arr[10][6].setPosition(-200, 0);
    Wall_Arr[10][7].setPosition(160, 112);
    Wall_Arr[11][0].setPosition(176, 0);
    Wall_Arr[11][1].setPosition(-200, 0);
    Wall_Arr[11][2].setPosition(-200, 0);
    Wall_Arr[11][3].setPosition(-200, 0);
    Wall_Arr[11][4].setPosition(-200, 0);
    Wall_Arr[11][5].setPosition(-200, 0);
    Wall_Arr[11][6].setPosition(-200, 0);
    Wall_Arr[11][7].setPosition(176, 112);
    Wall_Arr[12][0].setPosition(192, 0);
    Wall_Arr[12][1].setPosition(-200, 0);
    Wall_Arr[12][2].setPosition(-200, 0);
    Wall_Arr[12][3].setPosition(-200, 0);
    Wall_Arr[12][4].setPosition(-200, 0);
    Wall_Arr[12][5].setPosition(-200, 0);
    Wall_Arr[12][6].setPosition(-200, 0);
    Wall_Arr[12][7].setPosition(192, 112);
    Wall_Arr[13][0].setPosition(208, 0);
    Wall_Arr[13][1].setPosition(-200, 0);
    Wall_Arr[13][2].setPosition(-200, 0);
    Wall_Arr[13][3].setPosition(208, 48);
    Wall_Arr[13][4].setPosition(208, 64);
    Wall_Arr[13][5].setPosition(208, 80);
    Wall_Arr[13][6].setPosition(208, 96);
    Wall_Arr[13][7].setPosition(208, 112);
    Wall_Arr[14][0].setPosition(224, 0);
    Wall_Arr[14][1].setPosition(-200, 0);
    Wall_Arr[14][2].setPosition(-200, 0);
    Wall_Arr[14][3].setPosition(224, 48);
    Wall_Arr[14][4].setPosition(224, 64);
    Wall_Arr[14][5].setPosition(224, 80);
    Wall_Arr[14][6].setPosition(224, 96);
    Wall_Arr[14][7].setPosition(224, 112);
    Wall_Arr[15][0].setPosition(240, 0);
    Wall_Arr[15][1].setPosition(-200, 0);
    Wall_Arr[15][2].setPosition(-200, 0);
    Wall_Arr[15][3].setPosition(-200, 0);
    Wall_Arr[15][4].setPosition(-200, 0);
    Wall_Arr[15][5].setPosition(-200, 0);
    Wall_Arr[15][6].setPosition(-200, 0);
    Wall_Arr[15][7].setPosition(240, 112);
    Wall_Arr[16][0].setPosition(256, 0);
    Wall_Arr[16][1].setPosition(-200, 0);
    Wall_Arr[16][2].setPosition(-200, 0);
    Wall_Arr[16][3].setPosition(-200, 0);
    Wall_Arr[16][4].setPosition(-200, 0);
    Wall_Arr[16][5].setPosition(-200, 0);
    Wall_Arr[16][6].setPosition(-200, 0);
    Wall_Arr[16][7].setPosition(256, 112);
    Wall_Arr[17][0].setPosition(272, 0);
    Wall_Arr[17][1].setPosition(-200, 0);
    Wall_Arr[17][2].setPosition(-200, 0);
    Wall_Arr[17][3].setPosition(-200, 0);
    Wall_Arr[17][4].setPosition(-200, 0);
    Wall_Arr[17][5].setPosition(-200, 0);
    Wall_Arr[17][6].setPosition(-200, 0);
    Wall_Arr[17][7].setPosition(272, 112);
    Wall_Arr[18][0].setPosition(288, 0);
    Wall_Arr[18][1].setPosition(-200, 0);
    Wall_Arr[18][2].setPosition(-200, 0);
    Wall_Arr[18][3].setPosition(-200, 0);
    Wall_Arr[18][4].setPosition(-200, 0);
    Wall_Arr[18][5].setPosition(-200, 0);
    Wall_Arr[18][6].setPosition(-200, 0);
    Wall_Arr[18][7].setPosition(288, 112);
    Wall_Arr[19][0].setPosition(304, 0);
    Wall_Arr[19][1].setPosition(-200, 0);
    Wall_Arr[19][2].setPosition(-200, 0);
    Wall_Arr[19][3].setPosition(-200, 0);
    Wall_Arr[19][4].setPosition(-200, 0);
    Wall_Arr[19][5].setPosition(-200, 0);
    Wall_Arr[19][6].setPosition(-200, 0);
    Wall_Arr[19][7].setPosition(304, 112);
    Wall_Arr[20][0].setPosition(320, 0);
    Wall_Arr[20][1].setPosition(320, 16);
    Wall_Arr[20][2].setPosition(320, 32);
    Wall_Arr[20][3].setPosition(320, 48);
    Wall_Arr[20][4].setPosition(320, 64);
    Wall_Arr[20][5].setPosition(-200, 0);
    Wall_Arr[20][6].setPosition(-200, 0);
    Wall_Arr[20][7].setPosition(320, 112);
    Wall_Arr[21][0].setPosition(336, 0);
    Wall_Arr[21][1].setPosition(336, 16);
    Wall_Arr[21][2].setPosition(336, 32);
    Wall_Arr[21][3].setPosition(336, 48);
    Wall_Arr[21][4].setPosition(336, 64);
    Wall_Arr[21][5].setPosition(-200, 0);
    Wall_Arr[21][6].setPosition(-200, 0);
    Wall_Arr[21][7].setPosition(336, 112);
    Wall_Arr[22][0].setPosition(352, 0);
    Wall_Arr[22][1].setPosition(352, 16);
    Wall_Arr[22][2].setPosition(352, 32);
    Wall_Arr[22][3].setPosition(352, 48);
    Wall_Arr[22][4].setPosition(352, 64);
    Wall_Arr[22][5].setPosition(-200, 0);
    Wall_Arr[22][6].setPosition(-200, 0);
    Wall_Arr[22][7].setPosition(352, 112);
    Wall_Arr[23][0].setPosition(368, 0);
    Wall_Arr[23][1].setPosition(-200, 0);
    Wall_Arr[23][2].setPosition(-200, 0);
    Wall_Arr[23][3].setPosition(-200, 0);
    Wall_Arr[23][4].setPosition(-200, 0);
    Wall_Arr[23][5].setPosition(-200, 0);
    Wall_Arr[23][6].setPosition(-200, 0);
    Wall_Arr[23][7].setPosition(368, 112);
    Wall_Arr[24][0].setPosition(384, 0);
    Wall_Arr[24][1].setPosition(-200, 0);
    Wall_Arr[24][2].setPosition(-200, 0);
    Wall_Arr[24][3].setPosition(-200, 0);
    Wall_Arr[24][4].setPosition(-200, 0);
    Wall_Arr[24][5].setPosition(-200, 0);
    Wall_Arr[24][6].setPosition(-200, 0);
    Wall_Arr[24][7].setPosition(384, 112);
    Wall_Arr[25][0].setPosition(400, 0);
    Wall_Arr[25][1].setPosition(-200, 0);
    Wall_Arr[25][2].setPosition(-200, 0);
    Wall_Arr[25][3].setPosition(-200, 0);
    Wall_Arr[25][4].setPosition(400, 64);
    Wall_Arr[25][5].setPosition(400, 80);
    Wall_Arr[25][6].setPosition(400, 96);
    Wall_Arr[25][7].setPosition(400, 112);
    Wall_Arr[26][0].setPosition(416, 0);
    Wall_Arr[26][1].setPosition(-200, 0);
    Wall_Arr[26][2].setPosition(-200, 0);
    Wall_Arr[26][3].setPosition(-200, 0);
    Wall_Arr[26][4].setPosition(416, 64);
    Wall_Arr[26][5].setPosition(416, 80);
    Wall_Arr[26][6].setPosition(416, 96);
    Wall_Arr[26][7].setPosition(416, 112);
    Wall_Arr[27][0].setPosition(432, 0);
    Wall_Arr[27][1].setPosition(-200, 0);
    Wall_Arr[27][2].setPosition(-200, 0);
    Wall_Arr[27][3].setPosition(-200, 0);
    Wall_Arr[27][4].setPosition(432, 64);
    Wall_Arr[27][5].setPosition(-200, 0);
    Wall_Arr[27][6].setPosition(-200, 0);
    Wall_Arr[27][7].setPosition(432, 112);
    Wall_Arr[28][0].setPosition(448, 0);
    Wall_Arr[28][1].setPosition(-200, 0);
    Wall_Arr[28][2].setPosition(-200, 0);
    Wall_Arr[28][3].setPosition(-200, 0);
    Wall_Arr[28][4].setPosition(448, 64);
    Wall_Arr[28][5].setPosition(-200, 0);
    Wall_Arr[28][6].setPosition(-200, 0);
    Wall_Arr[28][7].setPosition(448, 112);
    Wall_Arr[29][0].setPosition(464, 0);
    Wall_Arr[29][1].setPosition(-200, 0);
    Wall_Arr[29][2].setPosition(-200, 0);
    Wall_Arr[29][3].setPosition(-200, 0);
    Wall_Arr[29][4].setPosition(-200, 0);
    Wall_Arr[29][5].setPosition(-200, 0);
    Wall_Arr[29][6].setPosition(-200, 0);
    Wall_Arr[29][7].setPosition(464, 112);
    Wall_Arr[30][0].setPosition(480, 0);
    Wall_Arr[30][1].setPosition(-200, 0);
    Wall_Arr[30][2].setPosition(-200, 0);
    Wall_Arr[30][3].setPosition(-200, 0);
    Wall_Arr[30][4].setPosition(-200, 0);
    Wall_Arr[30][5].setPosition(-200, 0);
    Wall_Arr[30][6].setPosition(-200, 0);
    Wall_Arr[30][7].setPosition(480, 112);
    Wall_Arr[31][0].setPosition(496, 0);
    Wall_Arr[31][1].setPosition(-200, 0);
    Wall_Arr[31][2].setPosition(-200, 0);
    Wall_Arr[31][3].setPosition(-200, 0);
    Wall_Arr[31][4].setPosition(496, 64);
    Wall_Arr[31][5].setPosition(-200, 0);
    Wall_Arr[31][6].setPosition(-200, 0);
    Wall_Arr[31][7].setPosition(496, 112);
    Wall_Arr[32][0].setPosition(512, 0);
    Wall_Arr[32][1].setPosition(512, 16);
    Wall_Arr[32][2].setPosition(-200, 0);
    Wall_Arr[32][3].setPosition(-200, 0);
    Wall_Arr[32][4].setPosition(512, 64);
    Wall_Arr[32][5].setPosition(512, 80);
    Wall_Arr[32][6].setPosition(-200, 0);
    Wall_Arr[32][7].setPosition(512, 112);
    Wall_Arr[33][0].setPosition(528, 0);
    Wall_Arr[33][1].setPosition(528, 16);
    Wall_Arr[33][2].setPosition(-200, 0);
    Wall_Arr[33][3].setPosition(-200, 0);
    Wall_Arr[33][4].setPosition(528, 64);
    Wall_Arr[33][5].setPosition(528, 80);
    Wall_Arr[33][6].setPosition(-200, 0);
    Wall_Arr[33][7].setPosition(528, 112);
    Wall_Arr[34][0].setPosition(544, 0);
    Wall_Arr[34][1].setPosition(-200, 0);
    Wall_Arr[34][2].setPosition(-200, 0);
    Wall_Arr[34][3].setPosition(-200, 0);
    Wall_Arr[34][4].setPosition(544, 64);
    Wall_Arr[34][5].setPosition(-200, 0);
    Wall_Arr[34][6].setPosition(-200, 0);
    Wall_Arr[34][7].setPosition(544, 112);
    Wall_Arr[35][0].setPosition(560, 0);
    Wall_Arr[35][1].setPosition(-200, 0);
    Wall_Arr[35][2].setPosition(-200, 0);
    Wall_Arr[35][3].setPosition(-200, 0);
    Wall_Arr[35][4].setPosition(-200, 0);
    Wall_Arr[35][5].setPosition(-200, 0);
    Wall_Arr[35][6].setPosition(-200, 0);
    Wall_Arr[35][7].setPosition(560, 112);
    Wall_Arr[36][0].setPosition(576, 0);
    Wall_Arr[36][1].setPosition(-200, 0);
    Wall_Arr[36][2].setPosition(-200, 0);
    Wall_Arr[36][3].setPosition(-200, 0);
    Wall_Arr[36][4].setPosition(-200, 0);
    Wall_Arr[36][5].setPosition(-200, 0);
    Wall_Arr[36][6].setPosition(-200, 0);
    Wall_Arr[36][7].setPosition(576, 112);
    Wall_Arr[37][0].setPosition(592, 0);
    Wall_Arr[37][1].setPosition(-200, 0);
    Wall_Arr[37][2].setPosition(-200, 0);
    Wall_Arr[37][3].setPosition(-200, 0);
    Wall_Arr[37][4].setPosition(592, 64);
    Wall_Arr[37][5].setPosition(-200, 0);
    Wall_Arr[37][6].setPosition(-200, 0);
    Wall_Arr[37][7].setPosition(592, 112);
    Wall_Arr[38][0].setPosition(608, 0);
    Wall_Arr[38][1].setPosition(-200, 0);
    Wall_Arr[38][2].setPosition(-200, 0);
    Wall_Arr[38][3].setPosition(-200, 0);
    Wall_Arr[38][4].setPosition(608, 64);
    Wall_Arr[38][5].setPosition(-200, 0);
    Wall_Arr[38][6].setPosition(-200, 0);
    Wall_Arr[38][7].setPosition(608, 112);
    Wall_Arr[39][0].setPosition(624, 0);
    Wall_Arr[39][1].setPosition(-200, 0);
    Wall_Arr[39][2].setPosition(-200, 0);
    Wall_Arr[39][3].setPosition(-200, 0);
    Wall_Arr[39][4].setPosition(624, 64);
    Wall_Arr[39][5].setPosition(624, 80);
    Wall_Arr[39][6].setPosition(624, 96);
    Wall_Arr[39][7].setPosition(624, 112);
    Wall_Arr[40][0].setPosition(640, 0);
    Wall_Arr[40][1].setPosition(-200, 0);
    Wall_Arr[40][2].setPosition(-200, 0);
    Wall_Arr[40][3].setPosition(-200, 0);
    Wall_Arr[40][4].setPosition(640, 64);
    Wall_Arr[40][5].setPosition(640, 80);
    Wall_Arr[40][6].setPosition(640, 96);
    Wall_Arr[40][7].setPosition(640, 112);
    Wall_Arr[41][0].setPosition(656, 0);
    Wall_Arr[41][1].setPosition(-200, 0);
    Wall_Arr[41][2].setPosition(-200, 0);
    Wall_Arr[41][3].setPosition(-200, 0);
    Wall_Arr[41][4].setPosition(-200, 0);
    Wall_Arr[41][5].setPosition(-200, 0);
    Wall_Arr[41][6].setPosition(-200, 0);
    Wall_Arr[41][7].setPosition(656, 112);
    Wall_Arr[42][0].setPosition(672, 0);
    Wall_Arr[42][1].setPosition(-200, 0);
    Wall_Arr[42][2].setPosition(-200, 0);
    Wall_Arr[42][3].setPosition(-200, 0);
    Wall_Arr[42][4].setPosition(-200, 0);
    Wall_Arr[42][5].setPosition(-200, 0);
    Wall_Arr[42][6].setPosition(-200, 0);
    Wall_Arr[42][7].setPosition(672, 112);
    Wall_Arr[43][0].setPosition(688, 0);
    Wall_Arr[43][1].setPosition(688, 16);
    Wall_Arr[43][2].setPosition(688, 32);
    Wall_Arr[43][3].setPosition(688, 48);
    Wall_Arr[43][4].setPosition(688, 64);
    Wall_Arr[43][5].setPosition(-200, 0);
    Wall_Arr[43][6].setPosition(-200, 0);
    Wall_Arr[43][7].setPosition(688, 112);
    Wall_Arr[44][0].setPosition(704, 0);
    Wall_Arr[44][1].setPosition(704, 16);
    Wall_Arr[44][2].setPosition(704, 32);
    Wall_Arr[44][3].setPosition(704, 48);
    Wall_Arr[44][4].setPosition(704, 64);
    Wall_Arr[44][5].setPosition(-200, 0);
    Wall_Arr[44][6].setPosition(-200, 0);
    Wall_Arr[44][7].setPosition(704, 112);
    Wall_Arr[45][0].setPosition(720, 0);
    Wall_Arr[45][1].setPosition(720, 16);
    Wall_Arr[45][2].setPosition(-200, 0);
    Wall_Arr[45][3].setPosition(-200, 0);
    Wall_Arr[45][4].setPosition(-200, 0);
    Wall_Arr[45][5].setPosition(-200, 0);
    Wall_Arr[45][6].setPosition(-200, 0);
    Wall_Arr[45][7].setPosition(720, 112);
    Wall_Arr[46][0].setPosition(736, 0);
    Wall_Arr[46][1].setPosition(-200, 0);
    Wall_Arr[46][2].setPosition(-200, 0);
    Wall_Arr[46][3].setPosition(-200, 0);
    Wall_Arr[46][4].setPosition(-200, 0);
    Wall_Arr[46][5].setPosition(-200, 0);
    Wall_Arr[46][6].setPosition(-200, 0);
    Wall_Arr[46][7].setPosition(736, 112);
    Wall_Arr[47][0].setPosition(752, 0);
    Wall_Arr[47][1].setPosition(-200, 0);
    Wall_Arr[47][2].setPosition(-200, 0);
    Wall_Arr[47][3].setPosition(-200, 0);
    Wall_Arr[47][4].setPosition(-200, 0);
    Wall_Arr[47][5].setPosition(-200, 0);
    Wall_Arr[47][6].setPosition(-200, 0);
    Wall_Arr[47][7].setPosition(752, 112);
    Wall_Arr[48][0].setPosition(768, 0);
    Wall_Arr[48][1].setPosition(-200, 0);
    Wall_Arr[48][2].setPosition(-200, 0);
    Wall_Arr[48][3].setPosition(-200, 0);
    Wall_Arr[48][4].setPosition(-200, 0);
    Wall_Arr[48][5].setPosition(-200, 0);
    Wall_Arr[48][6].setPosition(-200, 0);
    Wall_Arr[48][7].setPosition(768, 112);
    Wall_Arr[49][0].setPosition(784, 0);
    Wall_Arr[49][1].setPosition(-200, 0);
    Wall_Arr[49][2].setPosition(-200, 0);
    Wall_Arr[49][3].setPosition(-200, 0);
    Wall_Arr[49][4].setPosition(-200, 0);
    Wall_Arr[49][5].setPosition(-200, 0);
    Wall_Arr[49][6].setPosition(-200, 0);
    Wall_Arr[49][7].setPosition(784, 112);
    Wall_Arr[50][0].setPosition(800, 0);
    Wall_Arr[50][1].setPosition(-200, 0);
    Wall_Arr[50][2].setPosition(-200, 0);
    Wall_Arr[50][3].setPosition(-200, 0);
    Wall_Arr[50][4].setPosition(-200, 0);
    Wall_Arr[50][5].setPosition(-200, 0);
    Wall_Arr[50][6].setPosition(-200, 0);
    Wall_Arr[50][7].setPosition(800, 112);
    Wall_Arr[51][0].setPosition(816, 0);
    Wall_Arr[51][1].setPosition(-200, 0);
    Wall_Arr[51][2].setPosition(-200, 0);
    Wall_Arr[51][3].setPosition(-200, 0);
    Wall_Arr[51][4].setPosition(-200, 0);
    Wall_Arr[51][5].setPosition(-200, 0);
    Wall_Arr[51][6].setPosition(-200, 0);
    Wall_Arr[51][7].setPosition(816, 112);
    Wall_Arr[52][0].setPosition(832, 0);
    Wall_Arr[52][1].setPosition(-200, 0);
    Wall_Arr[52][2].setPosition(-200, 0);
    Wall_Arr[52][3].setPosition(-200, 0);
    Wall_Arr[52][4].setPosition(-200, 0);
    Wall_Arr[52][5].setPosition(-200, 0);
    Wall_Arr[52][6].setPosition(-200, 0);
    Wall_Arr[52][7].setPosition(832, 112);
    Wall_Arr[53][0].setPosition(848, 0);
    Wall_Arr[53][1].setPosition(-200, 0);
    Wall_Arr[53][2].setPosition(-200, 0);
    Wall_Arr[53][3].setPosition(-200, 0);
    Wall_Arr[53][4].setPosition(-200, 0);
    Wall_Arr[53][5].setPosition(-200, 0);
    Wall_Arr[53][6].setPosition(-200, 0);
    Wall_Arr[53][7].setPosition(848, 112);
    Wall_Arr[54][0].setPosition(864, 0);
    Wall_Arr[54][1].setPosition(-200, 0);
    Wall_Arr[54][2].setPosition(-200, 0);
    Wall_Arr[54][3].setPosition(-200, 0);
    Wall_Arr[54][4].setPosition(-200, 0);
    Wall_Arr[54][5].setPosition(-200, 0);
    Wall_Arr[54][6].setPosition(-200, 0);
    Wall_Arr[54][7].setPosition(864, 112);
    Wall_Arr[55][0].setPosition(880, 0);
    Wall_Arr[55][1].setPosition(-200, 0);
    Wall_Arr[55][2].setPosition(-200, 0);
    Wall_Arr[55][3].setPosition(-200, 0);
    Wall_Arr[55][4].setPosition(-200, 0);
    Wall_Arr[55][5].setPosition(-200, 0);
    Wall_Arr[55][6].setPosition(-200, 0);
    Wall_Arr[55][7].setPosition(880, 112);
    Wall_Arr[56][0].setPosition(896, 0);
    Wall_Arr[56][1].setPosition(-200, 0);
    Wall_Arr[56][2].setPosition(-200, 0);
    Wall_Arr[56][3].setPosition(-200, 0);
    Wall_Arr[56][4].setPosition(-200, 0);
    Wall_Arr[56][5].setPosition(-200, 0);
    Wall_Arr[56][6].setPosition(-200, 0);
    Wall_Arr[56][7].setPosition(896, 112);
    Wall_Arr[57][0].setPosition(912, 0);
    Wall_Arr[57][1].setPosition(-200, 0);
    Wall_Arr[57][2].setPosition(-200, 0);
    Wall_Arr[57][3].setPosition(-200, 0);
    Wall_Arr[57][4].setPosition(-200, 0);
    Wall_Arr[57][5].setPosition(-200, 0);
    Wall_Arr[57][6].setPosition(-200, 0);
    Wall_Arr[57][7].setPosition(912, 112);
    Wall_Arr[58][0].setPosition(928, 0);
    Wall_Arr[58][1].setPosition(-200, 0);
    Wall_Arr[58][2].setPosition(-200, 0);
    Wall_Arr[58][3].setPosition(-200, 0);
    Wall_Arr[58][4].setPosition(-200, 0);
    Wall_Arr[58][5].setPosition(-200, 0);
    Wall_Arr[58][6].setPosition(-200, 0);
    Wall_Arr[58][7].setPosition(928, 112);
    Wall_Arr[59][0].setPosition(944, 0);
    Wall_Arr[59][1].setPosition(-200, 0);
    Wall_Arr[59][2].setPosition(-200, 0);
    Wall_Arr[59][3].setPosition(-200, 0);
    Wall_Arr[59][4].setPosition(-200, 0);
    Wall_Arr[59][5].setPosition(-200, 0);
    Wall_Arr[59][6].setPosition(-200, 0);
    Wall_Arr[59][7].setPosition(944, 112);
    Wall_Arr[60][0].setPosition(960, 0);
    Wall_Arr[60][1].setPosition(-200, 0);
    Wall_Arr[60][2].setPosition(-200, 0);
    Wall_Arr[60][3].setPosition(-200, 0);
    Wall_Arr[60][4].setPosition(-200, 0);
    Wall_Arr[60][5].setPosition(-200, 0);
    Wall_Arr[60][6].setPosition(-200, 0);
    Wall_Arr[60][7].setPosition(960, 112);
    Wall_Arr[61][0].setPosition(976, 0);
    Wall_Arr[61][1].setPosition(-200, 0);
    Wall_Arr[61][2].setPosition(-200, 0);
    Wall_Arr[61][3].setPosition(-200, 0);
    Wall_Arr[61][4].setPosition(-200, 0);
    Wall_Arr[61][5].setPosition(-200, 0);
    Wall_Arr[61][6].setPosition(-200, 0);
    Wall_Arr[61][7].setPosition(976, 112);
    Wall_Arr[62][0].setPosition(992, 0);
    Wall_Arr[62][1].setPosition(-200, 0);
    Wall_Arr[62][2].setPosition(-200, 0);
    Wall_Arr[62][3].setPosition(-200, 0);
    Wall_Arr[62][4].setPosition(-200, 0);
    Wall_Arr[62][5].setPosition(-200, 0);
    Wall_Arr[62][6].setPosition(-200, 0);
    Wall_Arr[62][7].setPosition(992, 112);
    Wall_Arr[63][0].setPosition(1008, 0);
    Wall_Arr[63][1].setPosition(-200, 0);
    Wall_Arr[63][2].setPosition(-200, 0);
    Wall_Arr[63][3].setPosition(-200, 0);
    Wall_Arr[63][4].setPosition(-200, 0);
    Wall_Arr[63][5].setPosition(-200, 0);
    Wall_Arr[63][6].setPosition(-200, 0);
    Wall_Arr[63][7].setPosition(1008, 112);
    Wall_Arr[64][0].setPosition(1024, 0);
    Wall_Arr[64][1].setPosition(1024, 16);
    Wall_Arr[64][2].setPosition(-200, 0);
    Wall_Arr[64][3].setPosition(-200, 0);
    Wall_Arr[64][4].setPosition(-200, 0);
    Wall_Arr[64][5].setPosition(-200, 0);
    Wall_Arr[64][6].setPosition(-200, 0);
    Wall_Arr[64][7].setPosition(1024, 112);
    Wall_Arr[65][0].setPosition(1040, 0);
    Wall_Arr[65][1].setPosition(1040, 16);
    Wall_Arr[65][2].setPosition(1040, 32);
    Wall_Arr[65][3].setPosition(1040, 48);
    Wall_Arr[65][4].setPosition(1040, 64);
    Wall_Arr[65][5].setPosition(-200, 0);
    Wall_Arr[65][6].setPosition(-200, 0);
    Wall_Arr[65][7].setPosition(1040, 112);
    Wall_Arr[66][0].setPosition(1056, 0);
    Wall_Arr[66][1].setPosition(1056, 16);
    Wall_Arr[66][2].setPosition(1056, 32);
    Wall_Arr[66][3].setPosition(1056, 48);
    Wall_Arr[66][4].setPosition(1056, 64);
    Wall_Arr[66][5].setPosition(-200, 0);
    Wall_Arr[66][6].setPosition(-200, 0);
    Wall_Arr[66][7].setPosition(1056, 112);
    Wall_Arr[67][0].setPosition(1072, 0);
    Wall_Arr[67][1].setPosition(-200, 0);
    Wall_Arr[67][2].setPosition(-200, 0);
    Wall_Arr[67][3].setPosition(-200, 0);
    Wall_Arr[67][4].setPosition(-200, 0);
    Wall_Arr[67][5].setPosition(-200, 0);
    Wall_Arr[67][6].setPosition(-200, 0);
    Wall_Arr[67][7].setPosition(1072, 112);
    Wall_Arr[68][0].setPosition(1088, 0);
    Wall_Arr[68][1].setPosition(-200, 0);
    Wall_Arr[68][2].setPosition(-200, 0);
    Wall_Arr[68][3].setPosition(-200, 0);
    Wall_Arr[68][4].setPosition(-200, 0);
    Wall_Arr[68][5].setPosition(-200, 0);
    Wall_Arr[68][6].setPosition(-200, 0);
    Wall_Arr[68][7].setPosition(1088, 112);
    Wall_Arr[69][0].setPosition(1104, 0);
    Wall_Arr[69][1].setPosition(-200, 0);
    Wall_Arr[69][2].setPosition(-200, 0);
    Wall_Arr[69][3].setPosition(1104, 48);
    Wall_Arr[69][4].setPosition(1104, 64);
    Wall_Arr[69][5].setPosition(1104, 80);
    Wall_Arr[69][6].setPosition(1104, 96);
    Wall_Arr[69][7].setPosition(1104, 112);
    Wall_Arr[70][0].setPosition(1120, 0);
    Wall_Arr[70][1].setPosition(-200, 0);
    Wall_Arr[70][2].setPosition(-200, 0);
    Wall_Arr[70][3].setPosition(1120, 48);
    Wall_Arr[70][4].setPosition(1120, 64);
    Wall_Arr[70][5].setPosition(1120, 80);
    Wall_Arr[70][6].setPosition(1120, 96);
    Wall_Arr[70][7].setPosition(1120, 112);
    Wall_Arr[71][0].setPosition(1136, 0);
    Wall_Arr[71][1].setPosition(-200, 0);
    Wall_Arr[71][2].setPosition(-200, 0);
    Wall_Arr[71][3].setPosition(-200, 0);
    Wall_Arr[71][4].setPosition(-200, 0);
    Wall_Arr[71][5].setPosition(-200, 0);
    Wall_Arr[71][6].setPosition(-200, 0);
    Wall_Arr[71][7].setPosition(1136, 112);
    Wall_Arr[72][0].setPosition(1152, 0);
    Wall_Arr[72][1].setPosition(-200, 0);
    Wall_Arr[72][2].setPosition(-200, 0);
    Wall_Arr[72][3].setPosition(-200, 0);
    Wall_Arr[72][4].setPosition(-200, 0);
    Wall_Arr[72][5].setPosition(-200, 0);
    Wall_Arr[72][6].setPosition(-200, 0);
    Wall_Arr[72][7].setPosition(1152, 112);
    Wall_Arr[73][0].setPosition(1168, 0);
    Wall_Arr[73][1].setPosition(1168, 16);
    Wall_Arr[73][2].setPosition(1168, 32);
    Wall_Arr[73][3].setPosition(1168, 48);
    Wall_Arr[73][4].setPosition(1168, 64);
    Wall_Arr[73][5].setPosition(-200, 0);
    Wall_Arr[73][6].setPosition(-200, 0);
    Wall_Arr[73][7].setPosition(1168, 112);
    Wall_Arr[74][0].setPosition(1184, 0);
    Wall_Arr[74][1].setPosition(1184, 16);
    Wall_Arr[74][2].setPosition(1184, 32);
    Wall_Arr[74][3].setPosition(1184, 48);
    Wall_Arr[74][4].setPosition(1184, 64);
    Wall_Arr[74][5].setPosition(-200, 0);
    Wall_Arr[74][6].setPosition(-200, 0);
    Wall_Arr[74][7].setPosition(1184, 112);
    Wall_Arr[75][0].setPosition(1200, 0);
    Wall_Arr[75][1].setPosition(-200, 0);
    Wall_Arr[75][2].setPosition(-200, 0);
    Wall_Arr[75][3].setPosition(-200, 0);
    Wall_Arr[75][4].setPosition(-200, 0);
    Wall_Arr[75][5].setPosition(-200, 0);
    Wall_Arr[75][6].setPosition(-200, 0);
    Wall_Arr[75][7].setPosition(1200, 112);
    Wall_Arr[76][0].setPosition(1216, 0);
    Wall_Arr[76][1].setPosition(-200, 0);
    Wall_Arr[76][2].setPosition(-200, 0);
    Wall_Arr[76][3].setPosition(-200, 0);
    Wall_Arr[76][4].setPosition(-200, 0);
    Wall_Arr[76][5].setPosition(-200, 0);
    Wall_Arr[76][6].setPosition(-200, 0);
    Wall_Arr[76][7].setPosition(1216, 112);
    Wall_Arr[77][0].setPosition(1232, 0);
    Wall_Arr[77][1].setPosition(-200, 0);
    Wall_Arr[77][2].setPosition(-200, 0);
    Wall_Arr[77][3].setPosition(1232, 48);
    Wall_Arr[77][4].setPosition(1232, 64);
    Wall_Arr[77][5].setPosition(1232, 80);
    Wall_Arr[77][6].setPosition(1232, 96);
    Wall_Arr[77][7].setPosition(1232, 112);
    Wall_Arr[78][0].setPosition(1248, 0);
    Wall_Arr[78][1].setPosition(-200, 0);
    Wall_Arr[78][2].setPosition(-200, 0);
    Wall_Arr[78][3].setPosition(1248, 48);
    Wall_Arr[78][4].setPosition(1248, 64);
    Wall_Arr[78][5].setPosition(1248, 80);
    Wall_Arr[78][6].setPosition(1248, 96);
    Wall_Arr[78][7].setPosition(1248, 112);
    Wall_Arr[79][0].setPosition(1264, 0);
    Wall_Arr[79][1].setPosition(-200, 0);
    Wall_Arr[79][2].setPosition(-200, 0);
    Wall_Arr[79][3].setPosition(-200, 0);
    Wall_Arr[79][4].setPosition(-200, 0);
    Wall_Arr[79][5].setPosition(-200, 0);
    Wall_Arr[79][6].setPosition(-200, 0);
    Wall_Arr[79][7].setPosition(1264, 112);
    Wall_Arr[80][0].setPosition(1280, 0);
    Wall_Arr[80][1].setPosition(-200, 0);
    Wall_Arr[80][2].setPosition(-200, 0);
    Wall_Arr[80][3].setPosition(-200, 0);
    Wall_Arr[80][4].setPosition(-200, 0);
    Wall_Arr[80][5].setPosition(-200, 0);
    Wall_Arr[80][6].setPosition(-200, 0);
    Wall_Arr[80][7].setPosition(1280, 112);
    Wall_Arr[81][0].setPosition(1296, 0);
    Wall_Arr[81][1].setPosition(-200, 0);
    Wall_Arr[81][2].setPosition(-200, 0);
    Wall_Arr[81][3].setPosition(-200, 0);
    Wall_Arr[81][4].setPosition(-200, 0);
    Wall_Arr[81][5].setPosition(-200, 0);
    Wall_Arr[81][6].setPosition(-200, 0);
    Wall_Arr[81][7].setPosition(1296, 112);
    Wall_Arr[82][0].setPosition(1312, 0);
    Wall_Arr[82][1].setPosition(-200, 0);
    Wall_Arr[82][2].setPosition(-200, 0);
    Wall_Arr[82][3].setPosition(-200, 0);
    Wall_Arr[82][4].setPosition(-200, 0);
    Wall_Arr[82][5].setPosition(-200, 0);
    Wall_Arr[82][6].setPosition(-200, 0);
    Wall_Arr[82][7].setPosition(1312, 112);
    Wall_Arr[83][0].setPosition(1328, 0);
    Wall_Arr[83][1].setPosition(-200, 0);
    Wall_Arr[83][2].setPosition(-200, 0);
    Wall_Arr[83][3].setPosition(-200, 0);
    Wall_Arr[83][4].setPosition(-200, 0);
    Wall_Arr[83][5].setPosition(1328, 80);
    Wall_Arr[83][6].setPosition(1328, 96);
    Wall_Arr[83][7].setPosition(1328, 112);
    Wall_Arr[84][0].setPosition(1344, 0);
    Wall_Arr[84][1].setPosition(-200, 0);
    Wall_Arr[84][2].setPosition(-200, 0);
    Wall_Arr[84][3].setPosition(-200, 0);
    Wall_Arr[84][4].setPosition(-200, 0);
    Wall_Arr[84][5].setPosition(1344, 80);
    Wall_Arr[84][6].setPosition(1344, 96);
    Wall_Arr[84][7].setPosition(1344, 112);
    Wall_Arr[85][0].setPosition(1360, 0);
    Wall_Arr[85][1].setPosition(-200, 0);
    Wall_Arr[85][2].setPosition(-200, 0);
    Wall_Arr[85][3].setPosition(-200, 0);
    Wall_Arr[85][4].setPosition(-200, 0);
    Wall_Arr[85][5].setPosition(1360, 80);
    Wall_Arr[85][6].setPosition(1360, 96);
    Wall_Arr[85][7].setPosition(1360, 112);
    Wall_Arr[86][0].setPosition(1376, 0);
    Wall_Arr[86][1].setPosition(-200, 0);
    Wall_Arr[86][2].setPosition(-200, 0);
    Wall_Arr[86][3].setPosition(-200, 0);
    Wall_Arr[86][4].setPosition(1376, 64);
    Wall_Arr[86][5].setPosition(1376, 80);
    Wall_Arr[86][6].setPosition(1376, 96);
    Wall_Arr[86][7].setPosition(1376, 112);
    Wall_Arr[87][0].setPosition(1392, 0);
    Wall_Arr[87][1].setPosition(-200, 0);
    Wall_Arr[87][2].setPosition(-200, 0);
    Wall_Arr[87][3].setPosition(-200, 0);
    Wall_Arr[87][4].setPosition(1392, 64);
    Wall_Arr[87][5].setPosition(1392, 80);
    Wall_Arr[87][6].setPosition(1392, 96);
    Wall_Arr[87][7].setPosition(1392, 112);
    Wall_Arr[88][0].setPosition(1408, 0);
    Wall_Arr[88][1].setPosition(-200, 0);
    Wall_Arr[88][2].setPosition(-200, 0);
    Wall_Arr[88][3].setPosition(-200, 0);
    Wall_Arr[88][4].setPosition(-200, 0);
    Wall_Arr[88][5].setPosition(-200, 0);
    Wall_Arr[88][6].setPosition(-200, 0);
    Wall_Arr[88][7].setPosition(1408, 112);
    Wall_Arr[89][0].setPosition(1424, 0);
    Wall_Arr[89][1].setPosition(-200, 0);
    Wall_Arr[89][2].setPosition(-200, 0);
    Wall_Arr[89][3].setPosition(-200, 0);
    Wall_Arr[89][4].setPosition(-200, 0);
    Wall_Arr[89][5].setPosition(-200, 0);
    Wall_Arr[89][6].setPosition(-200, 0);
    Wall_Arr[89][7].setPosition(1424, 112);
    Wall_Arr[90][0].setPosition(1440, 0);
    Wall_Arr[90][1].setPosition(1440, 16);
    Wall_Arr[90][2].setPosition(1440, 32);
    Wall_Arr[90][3].setPosition(1440, 48);
    Wall_Arr[90][4].setPosition(1440, 64);
    Wall_Arr[90][5].setPosition(1440, 80);
    Wall_Arr[90][6].setPosition(-200, 0);
    Wall_Arr[90][7].setPosition(1440, 112);
    Wall_Arr[91][0].setPosition(1456, 0);
    Wall_Arr[91][1].setPosition(1456, 16);
    Wall_Arr[91][2].setPosition(1456, 32);
    Wall_Arr[91][3].setPosition(1456, 48);
    Wall_Arr[91][4].setPosition(1456, 64);
    Wall_Arr[91][5].setPosition(1456, 80);
    Wall_Arr[91][6].setPosition(-200, 0);
    Wall_Arr[91][7].setPosition(1456, 112);
    Wall_Arr[92][0].setPosition(1472, 0);
    Wall_Arr[92][1].setPosition(-200, 0);
    Wall_Arr[92][2].setPosition(-200, 0);
    Wall_Arr[92][3].setPosition(-200, 0);
    Wall_Arr[92][4].setPosition(-200, 0);
    Wall_Arr[92][5].setPosition(-200, 0);
    Wall_Arr[92][6].setPosition(-200, 0);
    Wall_Arr[92][7].setPosition(1472, 112);
    Wall_Arr[93][0].setPosition(1488, 0);
    Wall_Arr[93][1].setPosition(-200, 0);
    Wall_Arr[93][2].setPosition(-200, 0);
    Wall_Arr[93][3].setPosition(-200, 0);
    Wall_Arr[93][4].setPosition(-200, 0);
    Wall_Arr[93][5].setPosition(-200, 0);
    Wall_Arr[93][6].setPosition(-200, 0);
    Wall_Arr[93][7].setPosition(1488, 112);
    Wall_Arr[94][0].setPosition(1504, 0);
    Wall_Arr[94][1].setPosition(-200, 0);
    Wall_Arr[94][2].setPosition(-200, 0);
    Wall_Arr[94][3].setPosition(-200, 0);
    Wall_Arr[94][4].setPosition(1504, 64);
    Wall_Arr[94][5].setPosition(1504, 80);
    Wall_Arr[94][6].setPosition(1504, 96);
    Wall_Arr[94][7].setPosition(1504, 112);
    Wall_Arr[95][0].setPosition(1520, 0);
    Wall_Arr[95][1].setPosition(-200, 0);
    Wall_Arr[95][2].setPosition(-200, 0);
    Wall_Arr[95][3].setPosition(-200, 0);
    Wall_Arr[95][4].setPosition(1520, 64);
    Wall_Arr[95][5].setPosition(1520, 80);
    Wall_Arr[95][6].setPosition(1520, 96);
    Wall_Arr[95][7].setPosition(1520, 112);
    Wall_Arr[96][0].setPosition(1536, 0);
    Wall_Arr[96][1].setPosition(-200, 0);
    Wall_Arr[96][2].setPosition(-200, 0);
    Wall_Arr[96][3].setPosition(-200, 0);
    Wall_Arr[96][4].setPosition(-200, 0);
    Wall_Arr[96][5].setPosition(-200, 0);
    Wall_Arr[96][6].setPosition(1536, 96);
    Wall_Arr[96][7].setPosition(1536, 112);
    Wall_Arr[97][0].setPosition(1552, 0);
    Wall_Arr[97][1].setPosition(-200, 0);
    Wall_Arr[97][2].setPosition(-200, 0);
    Wall_Arr[97][3].setPosition(-200, 0);
    Wall_Arr[97][4].setPosition(-200, 0);
    Wall_Arr[97][5].setPosition(1552, 80);
    Wall_Arr[97][6].setPosition(1552, 96);
    Wall_Arr[97][7].setPosition(1552, 112);
    Wall_Arr[98][0].setPosition(1568, 0);
    Wall_Arr[98][1].setPosition(-200, 0);
    Wall_Arr[98][2].setPosition(-200, 0);
    Wall_Arr[98][3].setPosition(-200, 0);
    Wall_Arr[98][4].setPosition(-200, 0);
    Wall_Arr[98][5].setPosition(1568, 80);
    Wall_Arr[98][6].setPosition(1568, 96);
    Wall_Arr[98][7].setPosition(1568, 112);
    Wall_Arr[99][0].setPosition(1584, 0);
    Wall_Arr[99][1].setPosition(-200, 0);
    Wall_Arr[99][2].setPosition(-200, 0);
    Wall_Arr[99][3].setPosition(-200, 0);
    Wall_Arr[99][4].setPosition(-200, 0);
    Wall_Arr[99][5].setPosition(-200, 0);
    Wall_Arr[99][6].setPosition(-200, 0);
    Wall_Arr[99][7].setPosition(1584, 112);
    Wall_Arr[100][0].setPosition(1600, 0);
    Wall_Arr[100][1].setPosition(-200, 0);
    Wall_Arr[100][2].setPosition(-200, 0);
    Wall_Arr[100][3].setPosition(-200, 0);
    Wall_Arr[100][4].setPosition(-200, 0);
    Wall_Arr[100][5].setPosition(-200, 0);
    Wall_Arr[100][6].setPosition(-200, 0);
    Wall_Arr[100][7].setPosition(1600, 112);
    Wall_Arr[101][0].setPosition(1616, 0);
    Wall_Arr[101][1].setPosition(1616, 16);
    Wall_Arr[101][2].setPosition(1616, 32);
    Wall_Arr[101][3].setPosition(1616, 48);
    Wall_Arr[101][4].setPosition(1616, 64);
    Wall_Arr[101][5].setPosition(-200, 0);
    Wall_Arr[101][6].setPosition(-200, 0);
    Wall_Arr[101][7].setPosition(1616, 112);
    Wall_Arr[102][0].setPosition(1632, 0);
    Wall_Arr[102][1].setPosition(1632, 16);
    Wall_Arr[102][2].setPosition(1632, 32);
    Wall_Arr[102][3].setPosition(1632, 48);
    Wall_Arr[102][4].setPosition(1632, 64);
    Wall_Arr[102][5].setPosition(-200, 0);
    Wall_Arr[102][6].setPosition(-200, 0);
    Wall_Arr[102][7].setPosition(1632, 112);
    Wall_Arr[103][0].setPosition(1648, 0);
    Wall_Arr[103][1].setPosition(1648, 16);
    Wall_Arr[103][2].setPosition(1648, 32);
    Wall_Arr[103][3].setPosition(1648, 48);
    Wall_Arr[103][4].setPosition(1648, 64);
    Wall_Arr[103][5].setPosition(1648, 80);
    Wall_Arr[103][6].setPosition(1648, 96);
    Wall_Arr[103][7].setPosition(1648, 112);
    Wall_Arr[104][0].setPosition(1664, 0);
    Wall_Arr[104][1].setPosition(1664, 16);
    Wall_Arr[104][2].setPosition(1664, 32);
    Wall_Arr[104][3].setPosition(1664, 48);
    Wall_Arr[104][4].setPosition(1664, 64);
    Wall_Arr[104][5].setPosition(1664, 80);
    Wall_Arr[104][6].setPosition(1664, 96);
    Wall_Arr[104][7].setPosition(1664, 112);
    Wall_Arr[105][0].setPosition(1680, 0);
    Wall_Arr[105][1].setPosition(1680, 16);
    Wall_Arr[105][2].setPosition(1680, 32);
    Wall_Arr[105][3].setPosition(1680, 48);
    Wall_Arr[105][4].setPosition(1680, 64);
    Wall_Arr[105][5].setPosition(1680, 80);
    Wall_Arr[105][6].setPosition(1680, 96);
    Wall_Arr[105][7].setPosition(1680, 112);
    Wall_Arr[106][0].setPosition(1696, 0);
    Wall_Arr[106][1].setPosition(1696, 16);
    Wall_Arr[106][2].setPosition(1696, 32);
    Wall_Arr[106][3].setPosition(1696, 48);
    Wall_Arr[106][4].setPosition(1696, 64);
    Wall_Arr[106][5].setPosition(1696, 80);
    Wall_Arr[106][6].setPosition(1696, 96);
    Wall_Arr[106][7].setPosition(1696, 112);
    Wall_Arr[107][0].setPosition(1712, 0);
    Wall_Arr[107][1].setPosition(1712, 16);
    Wall_Arr[107][2].setPosition(1712, 32);
    Wall_Arr[107][3].setPosition(1712, 48);
    Wall_Arr[107][4].setPosition(1712, 64);
    Wall_Arr[107][5].setPosition(1712, 80);
    Wall_Arr[107][6].setPosition(1712, 96);
    Wall_Arr[107][7].setPosition(1712, 112);
    Wall_Arr[108][0].setPosition(1728, 0);
    Wall_Arr[108][1].setPosition(1728, 16);
    Wall_Arr[108][2].setPosition(1728, 32);
    Wall_Arr[108][3].setPosition(1728, 48);
    Wall_Arr[108][4].setPosition(1728, 64);
    Wall_Arr[108][5].setPosition(1728, 80);
    Wall_Arr[108][6].setPosition(1728, 96);
    Wall_Arr[108][7].setPosition(1728, 112);
    Wall_Arr[109][0].setPosition(1744, 0);
    Wall_Arr[109][1].setPosition(1744, 16);
    Wall_Arr[109][2].setPosition(1744, 32);
    Wall_Arr[109][3].setPosition(1744, 48);
    Wall_Arr[109][4].setPosition(1744, 64);
    Wall_Arr[109][5].setPosition(1744, 80);
    Wall_Arr[109][6].setPosition(1744, 96);
    Wall_Arr[109][7].setPosition(1744, 112);
    Wall_Arr[110][0].setPosition(1760, 0);
    Wall_Arr[110][1].setPosition(1760, 16);
    Wall_Arr[110][2].setPosition(1760, 32);
    Wall_Arr[110][3].setPosition(1760, 48);
    Wall_Arr[110][4].setPosition(1760, 64);
    Wall_Arr[110][5].setPosition(1760, 80);
    Wall_Arr[110][6].setPosition(1760, 96);
    Wall_Arr[110][7].setPosition(1760, 112);
    Wall_Arr[111][0].setPosition(1776, 0);
    Wall_Arr[111][1].setPosition(1776, 16);
    Wall_Arr[111][2].setPosition(1776, 32);
    Wall_Arr[111][3].setPosition(1776, 48);
    Wall_Arr[111][4].setPosition(1776, 64);
    Wall_Arr[111][5].setPosition(1776, 80);
    Wall_Arr[111][6].setPosition(1776, 96);
    Wall_Arr[111][7].setPosition(1776, 112);
    Wall_Arr[112][0].setPosition(1792, 0);
    Wall_Arr[112][1].setPosition(1792, 16);
    Wall_Arr[112][2].setPosition(1792, 32);
    Wall_Arr[112][3].setPosition(1792, 48);
    Wall_Arr[112][4].setPosition(1792, 64);
    Wall_Arr[112][5].setPosition(1792, 80);
    Wall_Arr[112][6].setPosition(1792, 96);
    Wall_Arr[112][7].setPosition(1792, 112);
    Move_Arr[0][0].setPosition(0, 500);
    Move_Arr[0][1].setPosition(0, 516);
    Move_Arr[0][2].setPosition(0, 532);
    Move_Arr[0][3].setPosition(0, 548);
    Move_Arr[0][4].setPosition(0, 564);
    Move_Arr[0][5].setPosition(0, 580);
    Move_Arr[0][6].setPosition(0, 596);
    Move_Arr[0][7].setPosition(0, 612);
    Move_Arr[1][0].setPosition(16, 500);
    Move_Arr[1][1].setPosition(16, 516);
    Move_Arr[1][2].setPosition(16, 532);
    Move_Arr[1][3].setPosition(16, 548);
    Move_Arr[1][4].setPosition(16, 564);
    Move_Arr[1][5].setPosition(16, 580);
    Move_Arr[1][6].setPosition(16, 596);
    Move_Arr[1][7].setPosition(16, 612);
    Move_Arr[2][0].setPosition(32, 500);
    Move_Arr[2][1].setPosition(32, 16);
    Move_Arr[2][2].setPosition(32, 32);
    Move_Arr[2][3].setPosition(32, 48);
    Move_Arr[2][4].setPosition(32, 64);
    Move_Arr[2][5].setPosition(32, 80);
    Move_Arr[2][6].setPosition(32, 96);
    Move_Arr[2][7].setPosition(32, 612);
    Move_Arr[3][0].setPosition(48, 500);
    Move_Arr[3][1].setPosition(48, 16);
    Move_Arr[3][2].setPosition(48, 32);
    Move_Arr[3][3].setPosition(48, 48);
    Move_Arr[3][4].setPosition(48, 64);
    Move_Arr[3][5].setPosition(48, 80);
    Move_Arr[3][6].setPosition(48, 96);
    Move_Arr[3][7].setPosition(48, 612);
    Move_Arr[4][0].setPosition(64, 500);
    Move_Arr[4][1].setPosition(64, 16);
    Move_Arr[4][2].setPosition(64, 32);
    Move_Arr[4][3].setPosition(64, 48);
    Move_Arr[4][4].setPosition(64, 64);
    Move_Arr[4][5].setPosition(64, 80);
    Move_Arr[4][6].setPosition(64, 96);
    Move_Arr[4][7].setPosition(64, 612);
    Move_Arr[5][0].setPosition(80, 500);
    Move_Arr[5][1].setPosition(80, 516);
    Move_Arr[5][2].setPosition(80, 532);
    Move_Arr[5][3].setPosition(80, 548);
    Move_Arr[5][4].setPosition(80, 564);
    Move_Arr[5][5].setPosition(80, 80);
    Move_Arr[5][6].setPosition(80, 96);
    Move_Arr[5][7].setPosition(80, 612);
    Move_Arr[6][0].setPosition(96, 500);
    Move_Arr[6][1].setPosition(96, 516);
    Move_Arr[6][2].setPosition(96, 532);
    Move_Arr[6][3].setPosition(96, 548);
    Move_Arr[6][4].setPosition(96, 564);
    Move_Arr[6][5].setPosition(96, 80);
    Move_Arr[6][6].setPosition(96, 96);
    Move_Arr[6][7].setPosition(96, 612);
    Move_Arr[7][0].setPosition(112, 500);
    Move_Arr[7][1].setPosition(112, 516);
    Move_Arr[7][2].setPosition(112, 532);
    Move_Arr[7][3].setPosition(112, 548);
    Move_Arr[7][4].setPosition(112, 564);
    Move_Arr[7][5].setPosition(112, 80);
    Move_Arr[7][6].setPosition(112, 96);
    Move_Arr[7][7].setPosition(112, 612);
    Move_Arr[8][0].setPosition(128, 500);
    Move_Arr[8][1].setPosition(128, 516);
    Move_Arr[8][2].setPosition(128, 532);
    Move_Arr[8][3].setPosition(128, 548);
    Move_Arr[8][4].setPosition(128, 564);
    Move_Arr[8][5].setPosition(128, 80);
    Move_Arr[8][6].setPosition(128, 96);
    Move_Arr[8][7].setPosition(128, 612);
    Move_Arr[9][0].setPosition(144, 500);
    Move_Arr[9][1].setPosition(144, 516);
    Move_Arr[9][2].setPosition(144, 532);
    Move_Arr[9][3].setPosition(144, 548);
    Move_Arr[9][4].setPosition(144, 564);
    Move_Arr[9][5].setPosition(144, 80);
    Move_Arr[9][6].setPosition(144, 96);
    Move_Arr[9][7].setPosition(144, 612);
    Move_Arr[10][0].setPosition(160, 500);
    Move_Arr[10][1].setPosition(160, 16);
    Move_Arr[10][2].setPosition(160, 32);
    Move_Arr[10][3].setPosition(160, 48);
    Move_Arr[10][4].setPosition(160, 64);
    Move_Arr[10][5].setPosition(160, 80);
    Move_Arr[10][6].setPosition(160, 96);
    Move_Arr[10][7].setPosition(160, 612);
    Move_Arr[11][0].setPosition(176, 500);
    Move_Arr[11][1].setPosition(176, 16);
    Move_Arr[11][2].setPosition(176, 32);
    Move_Arr[11][3].setPosition(176, 48);
    Move_Arr[11][4].setPosition(176, 64);
    Move_Arr[11][5].setPosition(176, 80);
    Move_Arr[11][6].setPosition(176, 96);
    Move_Arr[11][7].setPosition(176, 612);
    Move_Arr[12][0].setPosition(192, 500);
    Move_Arr[12][1].setPosition(192, 16);
    Move_Arr[12][2].setPosition(192, 32);
    Move_Arr[12][3].setPosition(192, 48);
    Move_Arr[12][4].setPosition(192, 64);
    Move_Arr[12][5].setPosition(192, 80);
    Move_Arr[12][6].setPosition(192, 96);
    Move_Arr[12][7].setPosition(192, 612);
    Move_Arr[13][0].setPosition(208, 500);
    Move_Arr[13][1].setPosition(208, 16);
    Move_Arr[13][2].setPosition(208, 32);
    Move_Arr[13][3].setPosition(208, 548);
    Move_Arr[13][4].setPosition(208, 564);
    Move_Arr[13][5].setPosition(208, 580);
    Move_Arr[13][6].setPosition(208, 596);
    Move_Arr[13][7].setPosition(208, 612);
    Move_Arr[14][0].setPosition(224, 500);
    Move_Arr[14][1].setPosition(224, 16);
    Move_Arr[14][2].setPosition(224, 32);
    Move_Arr[14][3].setPosition(224, 548);
    Move_Arr[14][4].setPosition(224, 564);
    Move_Arr[14][5].setPosition(224, 580);
    Move_Arr[14][6].setPosition(224, 596);
    Move_Arr[14][7].setPosition(224, 612);
    Move_Arr[15][0].setPosition(240, 500);
    Move_Arr[15][1].setPosition(240, 16);
    Move_Arr[15][2].setPosition(240, 32);
    Move_Arr[15][3].setPosition(240, 48);
    Move_Arr[15][4].setPosition(240, 64);
    Move_Arr[15][5].setPosition(240, 80);
    Move_Arr[15][6].setPosition(240, 96);
    Move_Arr[15][7].setPosition(240, 612);
    Move_Arr[16][0].setPosition(256, 500);
    Move_Arr[16][1].setPosition(256, 16);
    Move_Arr[16][2].setPosition(256, 32);
    Move_Arr[16][3].setPosition(256, 48);
    Move_Arr[16][4].setPosition(256, 64);
    Move_Arr[16][5].setPosition(256, 80);
    Move_Arr[16][6].setPosition(256, 96);
    Move_Arr[16][7].setPosition(256, 612);
    Move_Arr[17][0].setPosition(272, 500);
    Move_Arr[17][1].setPosition(272, 16);
    Move_Arr[17][2].setPosition(272, 32);
    Move_Arr[17][3].setPosition(272, 48);
    Move_Arr[17][4].setPosition(272, 64);
    Move_Arr[17][5].setPosition(272, 80);
    Move_Arr[17][6].setPosition(272, 96);
    Move_Arr[17][7].setPosition(272, 612);
    Move_Arr[18][0].setPosition(288, 500);
    Move_Arr[18][1].setPosition(288, 16);
    Move_Arr[18][2].setPosition(288, 32);
    Move_Arr[18][3].setPosition(288, 48);
    Move_Arr[18][4].setPosition(288, 64);
    Move_Arr[18][5].setPosition(288, 80);
    Move_Arr[18][6].setPosition(288, 96);
    Move_Arr[18][7].setPosition(288, 612);
    Move_Arr[19][0].setPosition(304, 500);
    Move_Arr[19][1].setPosition(304, 16);
    Move_Arr[19][2].setPosition(304, 32);
    Move_Arr[19][3].setPosition(304, 48);
    Move_Arr[19][4].setPosition(304, 64);
    Move_Arr[19][5].setPosition(304, 80);
    Move_Arr[19][6].setPosition(304, 96);
    Move_Arr[19][7].setPosition(304, 612);
    Move_Arr[20][0].setPosition(320, 500);
    Move_Arr[20][1].setPosition(320, 516);
    Move_Arr[20][2].setPosition(320, 532);
    Move_Arr[20][3].setPosition(320, 548);
    Move_Arr[20][4].setPosition(320, 564);
    Move_Arr[20][5].setPosition(320, 80);
    Move_Arr[20][6].setPosition(320, 96);
    Move_Arr[20][7].setPosition(320, 612);
    Move_Arr[21][0].setPosition(336, 500);
    Move_Arr[21][1].setPosition(336, 516);
    Move_Arr[21][2].setPosition(336, 532);
    Move_Arr[21][3].setPosition(336, 548);
    Move_Arr[21][4].setPosition(336, 564);
    Move_Arr[21][5].setPosition(336, 80);
    Move_Arr[21][6].setPosition(336, 96);
    Move_Arr[21][7].setPosition(336, 612);
    Move_Arr[22][0].setPosition(352, 500);
    Move_Arr[22][1].setPosition(352, 516);
    Move_Arr[22][2].setPosition(352, 532);
    Move_Arr[22][3].setPosition(352, 548);
    Move_Arr[22][4].setPosition(352, 564);
    Move_Arr[22][5].setPosition(352, 80);
    Move_Arr[22][6].setPosition(352, 96);
    Move_Arr[22][7].setPosition(352, 612);
    Move_Arr[23][0].setPosition(368, 500);
    Move_Arr[23][1].setPosition(368, 16);
    Move_Arr[23][2].setPosition(368, 32);
    Move_Arr[23][3].setPosition(368, 48);
    Move_Arr[23][4].setPosition(368, 64);
    Move_Arr[23][5].setPosition(368, 80);
    Move_Arr[23][6].setPosition(368, 96);
    Move_Arr[23][7].setPosition(368, 612);
    Move_Arr[24][0].setPosition(384, 500);
    Move_Arr[24][1].setPosition(384, 16);
    Move_Arr[24][2].setPosition(384, 32);
    Move_Arr[24][3].setPosition(384, 48);
    Move_Arr[24][4].setPosition(384, 64);
    Move_Arr[24][5].setPosition(384, 80);
    Move_Arr[24][6].setPosition(384, 96);
    Move_Arr[24][7].setPosition(384, 612);
    Move_Arr[25][0].setPosition(400, 500);
    Move_Arr[25][1].setPosition(400, 16);
    Move_Arr[25][2].setPosition(400, 32);
    Move_Arr[25][3].setPosition(400, 48);
    Move_Arr[25][4].setPosition(400, 564);
    Move_Arr[25][5].setPosition(400, 580);
    Move_Arr[25][6].setPosition(400, 596);
    Move_Arr[25][7].setPosition(400, 612);
    Move_Arr[26][0].setPosition(416, 500);
    Move_Arr[26][1].setPosition(416, 16);
    Move_Arr[26][2].setPosition(416, 32);
    Move_Arr[26][3].setPosition(416, 48);
    Move_Arr[26][4].setPosition(416, 564);
    Move_Arr[26][5].setPosition(416, 580);
    Move_Arr[26][6].setPosition(416, 596);
    Move_Arr[26][7].setPosition(416, 612);
    Move_Arr[27][0].setPosition(432, 500);
    Move_Arr[27][1].setPosition(432, 16);
    Move_Arr[27][2].setPosition(432, 32);
    Move_Arr[27][3].setPosition(432, 48);
    Move_Arr[27][4].setPosition(432, 564);
    Move_Arr[27][5].setPosition(432, 80);
    Move_Arr[27][6].setPosition(432, 96);
    Move_Arr[27][7].setPosition(432, 612);
    Move_Arr[28][0].setPosition(448, 500);
    Move_Arr[28][1].setPosition(448, 16);
    Move_Arr[28][2].setPosition(448, 32);
    Move_Arr[28][3].setPosition(448, 48);
    Move_Arr[28][4].setPosition(448, 564);
    Move_Arr[28][5].setPosition(448, 80);
    Move_Arr[28][6].setPosition(448, 96);
    Move_Arr[28][7].setPosition(448, 612);
    Move_Arr[29][0].setPosition(464, 500);
    Move_Arr[29][1].setPosition(464, 16);
    Move_Arr[29][2].setPosition(464, 32);
    Move_Arr[29][3].setPosition(464, 48);
    Move_Arr[29][4].setPosition(464, 64);
    Move_Arr[29][5].setPosition(464, 80);
    Move_Arr[29][6].setPosition(464, 96);
    Move_Arr[29][7].setPosition(464, 612);
    Move_Arr[30][0].setPosition(480, 500);
    Move_Arr[30][1].setPosition(480, 16);
    Move_Arr[30][2].setPosition(480, 32);
    Move_Arr[30][3].setPosition(480, 48);
    Move_Arr[30][4].setPosition(480, 64);
    Move_Arr[30][5].setPosition(480, 80);
    Move_Arr[30][6].setPosition(480, 96);
    Move_Arr[30][7].setPosition(480, 612);
    Move_Arr[31][0].setPosition(496, 500);
    Move_Arr[31][1].setPosition(496, 16);
    Move_Arr[31][2].setPosition(496, 32);
    Move_Arr[31][3].setPosition(496, 48);
    Move_Arr[31][4].setPosition(496, 564);
    Move_Arr[31][5].setPosition(496, 80);
    Move_Arr[31][6].setPosition(496, 96);
    Move_Arr[31][7].setPosition(496, 612);
    Move_Arr[32][0].setPosition(512, 500);
    Move_Arr[32][1].setPosition(512, 516);
    Move_Arr[32][2].setPosition(512, 32);
    Move_Arr[32][3].setPosition(512, 48);
    Move_Arr[32][4].setPosition(512, 564);
    Move_Arr[32][5].setPosition(512, 580);
    Move_Arr[32][6].setPosition(512, 96);
    Move_Arr[32][7].setPosition(512, 612);
    Move_Arr[33][0].setPosition(528, 500);
    Move_Arr[33][1].setPosition(-200, 0);
    Move_Arr[33][2].setPosition(528, 32);
    Move_Arr[33][3].setPosition(528, 48);
    Move_Arr[33][4].setPosition(528, 564);
    Move_Arr[33][5].setPosition(528, 580);
    Move_Arr[33][6].setPosition(528, 96);
    Move_Arr[33][7].setPosition(528, 612);
    Move_Arr[34][0].setPosition(544, 500);
    Move_Arr[34][1].setPosition(544, 16);
    Move_Arr[34][2].setPosition(544, 32);
    Move_Arr[34][3].setPosition(544, 48);
    Move_Arr[34][4].setPosition(544, 564);
    Move_Arr[34][5].setPosition(544, 80);
    Move_Arr[34][6].setPosition(544, 96);
    Move_Arr[34][7].setPosition(544, 612);
    Move_Arr[35][0].setPosition(560, 500);
    Move_Arr[35][1].setPosition(560, 16);
    Move_Arr[35][2].setPosition(560, 32);
    Move_Arr[35][3].setPosition(560, 48);
    Move_Arr[35][4].setPosition(560, 64);
    Move_Arr[35][5].setPosition(560, 80);
    Move_Arr[35][6].setPosition(560, 96);
    Move_Arr[35][7].setPosition(560, 612);
    Move_Arr[36][0].setPosition(576, 500);
    Move_Arr[36][1].setPosition(576, 16);
    Move_Arr[36][2].setPosition(576, 32);
    Move_Arr[36][3].setPosition(576, 48);
    Move_Arr[36][4].setPosition(576, 64);
    Move_Arr[36][5].setPosition(576, 80);
    Move_Arr[36][6].setPosition(576, 96);
    Move_Arr[36][7].setPosition(576, 612);
    Move_Arr[37][0].setPosition(592, 500);
    Move_Arr[37][1].setPosition(592, 16);
    Move_Arr[37][2].setPosition(592, 32);
    Move_Arr[37][3].setPosition(592, 48);
    Move_Arr[37][4].setPosition(-200, 0);
    Move_Arr[37][5].setPosition(592, 80);
    Move_Arr[37][6].setPosition(592, 96);
    Move_Arr[37][7].setPosition(592, 612);
    Move_Arr[38][0].setPosition(608, 500);
    Move_Arr[38][1].setPosition(608, 16);
    Move_Arr[38][2].setPosition(608, 32);
    Move_Arr[38][3].setPosition(608, 48);
    Move_Arr[38][4].setPosition(608, 564);
    Move_Arr[38][5].setPosition(608, 80);
    Move_Arr[38][6].setPosition(608, 96);
    Move_Arr[38][7].setPosition(608, 612);
    Move_Arr[39][0].setPosition(624, 500);
    Move_Arr[39][1].setPosition(624, 16);
    Move_Arr[39][2].setPosition(624, 32);
    Move_Arr[39][3].setPosition(624, 48);
    Move_Arr[39][4].setPosition(624, 564);
    Move_Arr[39][5].setPosition(-200, 0);
    Move_Arr[39][6].setPosition(624, 596);
    Move_Arr[39][7].setPosition(624, 612);
    Move_Arr[40][0].setPosition(640, 500);
    Move_Arr[40][1].setPosition(640, 16);
    Move_Arr[40][2].setPosition(640, 32);
    Move_Arr[40][3].setPosition(640, 48);
    Move_Arr[40][4].setPosition(640, 564);
    Move_Arr[40][5].setPosition(640, 580);
    Move_Arr[40][6].setPosition(640, 596);
    Move_Arr[40][7].setPosition(640, 612);
    Move_Arr[41][0].setPosition(656, 500);
    Move_Arr[41][1].setPosition(656, 16);
    Move_Arr[41][2].setPosition(656, 32);
    Move_Arr[41][3].setPosition(656, 48);
    Move_Arr[41][4].setPosition(656, 64);
    Move_Arr[41][5].setPosition(656, 80);
    Move_Arr[41][6].setPosition(656, 96);
    Move_Arr[41][7].setPosition(656, 612);
    Move_Arr[42][0].setPosition(672, 500);
    Move_Arr[42][1].setPosition(672, 16);
    Move_Arr[42][2].setPosition(672, 32);
    Move_Arr[42][3].setPosition(672, 48);
    Move_Arr[42][4].setPosition(672, 64);
    Move_Arr[42][5].setPosition(672, 80);
    Move_Arr[42][6].setPosition(672, 96);
    Move_Arr[42][7].setPosition(672, 612);
    Move_Arr[43][0].setPosition(688, 500);
    Move_Arr[43][1].setPosition(688, 516);
    Move_Arr[43][2].setPosition(688, 532);
    Move_Arr[43][3].setPosition(688, 548);
    Move_Arr[43][4].setPosition(688, 564);
    Move_Arr[43][5].setPosition(688, 80);
    Move_Arr[43][6].setPosition(688, 96);
    Move_Arr[43][7].setPosition(688, 612);
    Move_Arr[44][0].setPosition(704, 500);
    Move_Arr[44][1].setPosition(704, 516);
    Move_Arr[44][2].setPosition(704, 532);
    Move_Arr[44][3].setPosition(704, 548);
    Move_Arr[44][4].setPosition(704, 564);
    Move_Arr[44][5].setPosition(704, 80);
    Move_Arr[44][6].setPosition(704, 96);
    Move_Arr[44][7].setPosition(704, 612);
    Move_Arr[45][0].setPosition(720, 500);
    Move_Arr[45][1].setPosition(720, 516);
    Move_Arr[45][2].setPosition(720, 32);
    Move_Arr[45][3].setPosition(720, 48);
    Move_Arr[45][4].setPosition(720, 64);
    Move_Arr[45][5].setPosition(720, 80);
    Move_Arr[45][6].setPosition(720, 96);
    Move_Arr[45][7].setPosition(720, 612);
    Move_Arr[46][0].setPosition(736, 500);
    Move_Arr[46][1].setPosition(736, 16);
    Move_Arr[46][2].setPosition(736, 32);
    Move_Arr[46][3].setPosition(736, 48);
    Move_Arr[46][4].setPosition(736, 64);
    Move_Arr[46][5].setPosition(736, 80);
    Move_Arr[46][6].setPosition(736, 96);
    Move_Arr[46][7].setPosition(736, 612);
    Move_Arr[47][0].setPosition(752, 500);
    Move_Arr[47][1].setPosition(752, 16);
    Move_Arr[47][2].setPosition(752, 32);
    Move_Arr[47][3].setPosition(752, 48);
    Move_Arr[47][4].setPosition(752, 64);
    Move_Arr[47][5].setPosition(752, 80);
    Move_Arr[47][6].setPosition(752, 96);
    Move_Arr[47][7].setPosition(752, 612);
    Move_Arr[48][0].setPosition(768, 500);
    Move_Arr[48][1].setPosition(768, 16);
    Move_Arr[48][2].setPosition(768, 32);
    Move_Arr[48][3].setPosition(768, 48);
    Move_Arr[48][4].setPosition(768, 64);
    Move_Arr[48][5].setPosition(768, 80);
    Move_Arr[48][6].setPosition(768, 96);
    Move_Arr[48][7].setPosition(768, 612);
    Move_Arr[49][0].setPosition(784, 500);
    Move_Arr[49][1].setPosition(784, 16);
    Move_Arr[49][2].setPosition(784, 32);
    Move_Arr[49][3].setPosition(784, 48);
    Move_Arr[49][4].setPosition(784, 64);
    Move_Arr[49][5].setPosition(784, 80);
    Move_Arr[49][6].setPosition(784, 96);
    Move_Arr[49][7].setPosition(784, 612);
    Move_Arr[50][0].setPosition(800, 500);
    Move_Arr[50][1].setPosition(800, 16);
    Move_Arr[50][2].setPosition(800, 32);
    Move_Arr[50][3].setPosition(800, 48);
    Move_Arr[50][4].setPosition(800, 64);
    Move_Arr[50][5].setPosition(800, 80);
    Move_Arr[50][6].setPosition(800, 96);
    Move_Arr[50][7].setPosition(800, 612);
    Move_Arr[51][0].setPosition(816, 500);
    Move_Arr[51][1].setPosition(816, 16);
    Move_Arr[51][2].setPosition(816, 32);
    Move_Arr[51][3].setPosition(816, 48);
    Move_Arr[51][4].setPosition(816, 64);
    Move_Arr[51][5].setPosition(816, 80);
    Move_Arr[51][6].setPosition(816, 96);
    Move_Arr[51][7].setPosition(816, 612);
    Move_Arr[52][0].setPosition(832, 500);
    Move_Arr[52][1].setPosition(832, 16);
    Move_Arr[52][2].setPosition(832, 32);
    Move_Arr[52][3].setPosition(832, 48);
    Move_Arr[52][4].setPosition(832, 64);
    Move_Arr[52][5].setPosition(832, 80);
    Move_Arr[52][6].setPosition(832, 96);
    Move_Arr[52][7].setPosition(832, 612);
    Move_Arr[53][0].setPosition(848, 500);
    Move_Arr[53][1].setPosition(848, 16);
    Move_Arr[53][2].setPosition(848, 32);
    Move_Arr[53][3].setPosition(848, 48);
    Move_Arr[53][4].setPosition(848, 64);
    Move_Arr[53][5].setPosition(848, 80);
    Move_Arr[53][6].setPosition(848, 96);
    Move_Arr[53][7].setPosition(848, 612);
    Move_Arr[54][0].setPosition(864, 500);
    Move_Arr[54][1].setPosition(864, 16);
    Move_Arr[54][2].setPosition(864, 32);
    Move_Arr[54][3].setPosition(864, 48);
    Move_Arr[54][4].setPosition(864, 64);
    Move_Arr[54][5].setPosition(864, 80);
    Move_Arr[54][6].setPosition(864, 96);
    Move_Arr[54][7].setPosition(864, 612);
    Move_Arr[55][0].setPosition(880, 500);
    Move_Arr[55][1].setPosition(880, 16);
    Move_Arr[55][2].setPosition(880, 32);
    Move_Arr[55][3].setPosition(880, 48);
    Move_Arr[55][4].setPosition(880, 64);
    Move_Arr[55][5].setPosition(880, 80);
    Move_Arr[55][6].setPosition(880, 96);
    Move_Arr[55][7].setPosition(880, 612);
    Move_Arr[56][0].setPosition(896, 500);
    Move_Arr[56][1].setPosition(896, 16);
    Move_Arr[56][2].setPosition(896, 32);
    Move_Arr[56][3].setPosition(896, 48);
    Move_Arr[56][4].setPosition(896, 64);
    Move_Arr[56][5].setPosition(896, 80);
    Move_Arr[56][6].setPosition(896, 96);
    Move_Arr[56][7].setPosition(896, 612);
    Move_Arr[57][0].setPosition(912, 500);
    Move_Arr[57][1].setPosition(912, 16);
    Move_Arr[57][2].setPosition(912, 32);
    Move_Arr[57][3].setPosition(912, 48);
    Move_Arr[57][4].setPosition(912, 64);
    Move_Arr[57][5].setPosition(912, 80);
    Move_Arr[57][6].setPosition(912, 96);
    Move_Arr[57][7].setPosition(912, 612);
    Move_Arr[58][0].setPosition(928, 500);
    Move_Arr[58][1].setPosition(928, 16);
    Move_Arr[58][2].setPosition(928, 32);
    Move_Arr[58][3].setPosition(928, 48);
    Move_Arr[58][4].setPosition(928, 64);
    Move_Arr[58][5].setPosition(928, 80);
    Move_Arr[58][6].setPosition(928, 96);
    Move_Arr[58][7].setPosition(928, 612);
    Move_Arr[59][0].setPosition(944, 500);
    Move_Arr[59][1].setPosition(944, 16);
    Move_Arr[59][2].setPosition(944, 32);
    Move_Arr[59][3].setPosition(944, 48);
    Move_Arr[59][4].setPosition(944, 64);
    Move_Arr[59][5].setPosition(944, 80);
    Move_Arr[59][6].setPosition(944, 96);
    Move_Arr[59][7].setPosition(944, 612);
    Move_Arr[60][0].setPosition(960, 500);
    Move_Arr[60][1].setPosition(960, 16);
    Move_Arr[60][2].setPosition(960, 32);
    Move_Arr[60][3].setPosition(960, 48);
    Move_Arr[60][4].setPosition(960, 64);
    Move_Arr[60][5].setPosition(960, 80);
    Move_Arr[60][6].setPosition(960, 96);
    Move_Arr[60][7].setPosition(960, 612);
    Move_Arr[61][0].setPosition(976, 500);
    Move_Arr[61][1].setPosition(976, 16);
    Move_Arr[61][2].setPosition(976, 32);
    Move_Arr[61][3].setPosition(976, 48);
    Move_Arr[61][4].setPosition(976, 64);
    Move_Arr[61][5].setPosition(976, 80);
    Move_Arr[61][6].setPosition(976, 96);
    Move_Arr[61][7].setPosition(976, 612);
    Move_Arr[62][0].setPosition(992, 500);
    Move_Arr[62][1].setPosition(992, 16);
    Move_Arr[62][2].setPosition(992, 32);
    Move_Arr[62][3].setPosition(992, 48);
    Move_Arr[62][4].setPosition(992, 64);
    Move_Arr[62][5].setPosition(992, 80);
    Move_Arr[62][6].setPosition(992, 96);
    Move_Arr[62][7].setPosition(992, 612);
    Move_Arr[63][0].setPosition(1008, 500);
    Move_Arr[63][1].setPosition(1008, 16);
    Move_Arr[63][2].setPosition(1008, 32);
    Move_Arr[63][3].setPosition(1008, 48);
    Move_Arr[63][4].setPosition(1008, 64);
    Move_Arr[63][5].setPosition(1008, 80);
    Move_Arr[63][6].setPosition(1008, 96);
    Move_Arr[63][7].setPosition(1008, 612);
    Move_Arr[64][0].setPosition(1024, 500);
    Move_Arr[64][1].setPosition(1024, 516);
    Move_Arr[64][2].setPosition(1024, 32);
    Move_Arr[64][3].setPosition(1024, 48);
    Move_Arr[64][4].setPosition(1024, 64);
    Move_Arr[64][5].setPosition(1024, 80);
    Move_Arr[64][6].setPosition(1024, 96);
    Move_Arr[64][7].setPosition(1024, 612);
    Move_Arr[65][0].setPosition(1040, 500);
    Move_Arr[65][1].setPosition(1040, 516);
    Move_Arr[65][2].setPosition(1040, 532);
    Move_Arr[65][3].setPosition(1040, 548);
    Move_Arr[65][4].setPosition(1040, 564);
    Move_Arr[65][5].setPosition(1040, 80);
    Move_Arr[65][6].setPosition(1040, 96);
    Move_Arr[65][7].setPosition(1040, 612);
    Move_Arr[66][0].setPosition(1056, 500);
    Move_Arr[66][1].setPosition(1056, 516);
    Move_Arr[66][2].setPosition(1056, 532);
    Move_Arr[66][3].setPosition(1056, 548);
    Move_Arr[66][4].setPosition(1056, 564);
    Move_Arr[66][5].setPosition(1056, 80);
    Move_Arr[66][6].setPosition(1056, 96);
    Move_Arr[66][7].setPosition(1056, 612);
    Move_Arr[67][0].setPosition(1072, 500);
    Move_Arr[67][1].setPosition(1072, 16);
    Move_Arr[67][2].setPosition(1072, 32);
    Move_Arr[67][3].setPosition(1072, 48);
    Move_Arr[67][4].setPosition(1072, 64);
    Move_Arr[67][5].setPosition(1072, 80);
    Move_Arr[67][6].setPosition(1072, 96);
    Move_Arr[67][7].setPosition(1072, 612);
    Move_Arr[68][0].setPosition(1088, 500);
    Move_Arr[68][1].setPosition(1088, 16);
    Move_Arr[68][2].setPosition(1088, 32);
    Move_Arr[68][3].setPosition(1088, 48);
    Move_Arr[68][4].setPosition(1088, 64);
    Move_Arr[68][5].setPosition(1088, 80);
    Move_Arr[68][6].setPosition(1088, 96);
    Move_Arr[68][7].setPosition(1088, 612);
    Move_Arr[69][0].setPosition(1104, 500);
    Move_Arr[69][1].setPosition(1104, 16);
    Move_Arr[69][2].setPosition(1104, 32);
    Move_Arr[69][3].setPosition(1104, 548);
    Move_Arr[69][4].setPosition(1104, 564);
    Move_Arr[69][5].setPosition(1104, 580);
    Move_Arr[69][6].setPosition(1104, 596);
    Move_Arr[69][7].setPosition(1104, 612);
    Move_Arr[70][0].setPosition(1120, 500);
    Move_Arr[70][1].setPosition(1120, 16);
    Move_Arr[70][2].setPosition(1120, 32);
    Move_Arr[70][3].setPosition(1120, 548);
    Move_Arr[70][4].setPosition(1120, 564);
    Move_Arr[70][5].setPosition(1120, 580);
    Move_Arr[70][6].setPosition(1120, 596);
    Move_Arr[70][7].setPosition(1120, 612);
    Move_Arr[71][0].setPosition(1136, 500);
    Move_Arr[71][1].setPosition(1136, 16);
    Move_Arr[71][2].setPosition(1136, 32);
    Move_Arr[71][3].setPosition(1136, 48);
    Move_Arr[71][4].setPosition(1136, 64);
    Move_Arr[71][5].setPosition(1136, 80);
    Move_Arr[71][6].setPosition(1136, 96);
    Move_Arr[71][7].setPosition(1136, 612);
    Move_Arr[72][0].setPosition(1152, 500);
    Move_Arr[72][1].setPosition(1152, 16);
    Move_Arr[72][2].setPosition(1152, 32);
    Move_Arr[72][3].setPosition(1152, 48);
    Move_Arr[72][4].setPosition(1152, 64);
    Move_Arr[72][5].setPosition(1152, 80);
    Move_Arr[72][6].setPosition(1152, 96);
    Move_Arr[72][7].setPosition(1152, 612);
    Move_Arr[73][0].setPosition(1168, 500);
    Move_Arr[73][1].setPosition(1168, 516);
    Move_Arr[73][2].setPosition(1168, 532);
    Move_Arr[73][3].setPosition(1168, 548);
    Move_Arr[73][4].setPosition(1168, 564);
    Move_Arr[73][5].setPosition(1168, 80);
    Move_Arr[73][6].setPosition(1168, 96);
    Move_Arr[73][7].setPosition(1168, 612);
    Move_Arr[74][0].setPosition(1184, 500);
    Move_Arr[74][1].setPosition(1184, 516);
    Move_Arr[74][2].setPosition(1184, 532);
    Move_Arr[74][3].setPosition(1184, 548);
    Move_Arr[74][4].setPosition(1184, 564);
    Move_Arr[74][5].setPosition(1184, 80);
    Move_Arr[74][6].setPosition(1184, 96);
    Move_Arr[74][7].setPosition(1184, 612);
    Move_Arr[75][0].setPosition(1200, 500);
    Move_Arr[75][1].setPosition(1200, 16);
    Move_Arr[75][2].setPosition(1200, 32);
    Move_Arr[75][3].setPosition(1200, 48);
    Move_Arr[75][4].setPosition(1200, 64);
    Move_Arr[75][5].setPosition(1200, 80);
    Move_Arr[75][6].setPosition(1200, 96);
    Move_Arr[75][7].setPosition(1200, 612);
    Move_Arr[76][0].setPosition(1216, 500);
    Move_Arr[76][1].setPosition(1216, 16);
    Move_Arr[76][2].setPosition(1216, 32);
    Move_Arr[76][3].setPosition(1216, 48);
    Move_Arr[76][4].setPosition(1216, 64);
    Move_Arr[76][5].setPosition(1216, 80);
    Move_Arr[76][6].setPosition(1216, 96);
    Move_Arr[76][7].setPosition(1216, 612);
    Move_Arr[77][0].setPosition(1232, 500);
    Move_Arr[77][1].setPosition(1232, 16);
    Move_Arr[77][2].setPosition(1232, 32);
    Move_Arr[77][3].setPosition(1232, 548);
    Move_Arr[77][4].setPosition(1232, 564);
    Move_Arr[77][5].setPosition(1232, 580);
    Move_Arr[77][6].setPosition(1232, 596);
    Move_Arr[77][7].setPosition(1232, 612);
    Move_Arr[78][0].setPosition(1248, 500);
    Move_Arr[78][1].setPosition(1248, 16);
    Move_Arr[78][2].setPosition(1248, 32);
    Move_Arr[78][3].setPosition(1248, 548);
    Move_Arr[78][4].setPosition(1248, 564);
    Move_Arr[78][5].setPosition(1248, 580);
    Move_Arr[78][6].setPosition(1248, 596);
    Move_Arr[78][7].setPosition(1248, 612);
    Move_Arr[79][0].setPosition(1264, 500);
    Move_Arr[79][1].setPosition(1264, 16);
    Move_Arr[79][2].setPosition(1264, 32);
    Move_Arr[79][3].setPosition(1264, 48);
    Move_Arr[79][4].setPosition(1264, 64);
    Move_Arr[79][5].setPosition(1264, 80);
    Move_Arr[79][6].setPosition(1264, 96);
    Move_Arr[79][7].setPosition(1264, 612);
    Move_Arr[80][0].setPosition(1280, 500);
    Move_Arr[80][1].setPosition(1280, 16);
    Move_Arr[80][2].setPosition(1280, 32);
    Move_Arr[80][3].setPosition(1280, 48);
    Move_Arr[80][4].setPosition(1280, 64);
    Move_Arr[80][5].setPosition(1280, 80);
    Move_Arr[80][6].setPosition(1280, 96);
    Move_Arr[80][7].setPosition(1280, 612);
    Move_Arr[81][0].setPosition(1296, 500);
    Move_Arr[81][1].setPosition(1296, 16);
    Move_Arr[81][2].setPosition(1296, 32);
    Move_Arr[81][3].setPosition(1296, 48);
    Move_Arr[81][4].setPosition(1296, 64);
    Move_Arr[81][5].setPosition(1296, 80);
    Move_Arr[81][6].setPosition(1296, 96);
    Move_Arr[81][7].setPosition(1296, 612);
    Move_Arr[82][0].setPosition(1312, 500);
    Move_Arr[82][1].setPosition(1312, 16);
    Move_Arr[82][2].setPosition(1312, 32);
    Move_Arr[82][3].setPosition(1312, 48);
    Move_Arr[82][4].setPosition(1312, 64);
    Move_Arr[82][5].setPosition(1312, 80);
    Move_Arr[82][6].setPosition(1312, 96);
    Move_Arr[82][7].setPosition(1312, 612);
    Move_Arr[83][0].setPosition(1328, 500);
    Move_Arr[83][1].setPosition(1328, 16);
    Move_Arr[83][2].setPosition(1328, 32);
    Move_Arr[83][3].setPosition(1328, 48);
    Move_Arr[83][4].setPosition(1328, 64);
    Move_Arr[83][5].setPosition(1328, 580);
    Move_Arr[83][6].setPosition(1328, 596);
    Move_Arr[83][7].setPosition(1328, 612);
    Move_Arr[84][0].setPosition(1344, 500);
    Move_Arr[84][1].setPosition(1344, 16);
    Move_Arr[84][2].setPosition(1344, 32);
    Move_Arr[84][3].setPosition(1344, 48);
    Move_Arr[84][4].setPosition(1344, 64);
    Move_Arr[84][5].setPosition(1344, 580);
    Move_Arr[84][6].setPosition(1344, 596);
    Move_Arr[84][7].setPosition(1344, 612);
    Move_Arr[85][0].setPosition(1360, 500);
    Move_Arr[85][1].setPosition(1360, 16);
    Move_Arr[85][2].setPosition(1360, 32);
    Move_Arr[85][3].setPosition(1360, 48);
    Move_Arr[85][4].setPosition(1360, 64);
    Move_Arr[85][5].setPosition(1360, 580);
    Move_Arr[85][6].setPosition(1360, 596);
    Move_Arr[85][7].setPosition(1360, 612);
    Move_Arr[86][0].setPosition(1376, 500);
    Move_Arr[86][1].setPosition(1376, 16);
    Move_Arr[86][2].setPosition(1376, 32);
    Move_Arr[86][3].setPosition(1376, 48);
    Move_Arr[86][4].setPosition(1376, 564);
    Move_Arr[86][5].setPosition(1376, 580);
    Move_Arr[86][6].setPosition(1376, 596);
    Move_Arr[86][7].setPosition(1376, 612);
    Move_Arr[87][0].setPosition(1392, 500);
    Move_Arr[87][1].setPosition(1392, 16);
    Move_Arr[87][2].setPosition(1392, 32);
    Move_Arr[87][3].setPosition(1392, 48);
    Move_Arr[87][4].setPosition(1392, 564);
    Move_Arr[87][5].setPosition(1392, 580);
    Move_Arr[87][6].setPosition(1392, 596);
    Move_Arr[87][7].setPosition(1392, 612);
    Move_Arr[88][0].setPosition(1408, 500);
    Move_Arr[88][1].setPosition(1408, 16);
    Move_Arr[88][2].setPosition(1408, 32);
    Move_Arr[88][3].setPosition(1408, 48);
    Move_Arr[88][4].setPosition(1408, 64);
    Move_Arr[88][5].setPosition(1408, 80);
    Move_Arr[88][6].setPosition(1408, 96);
    Move_Arr[88][7].setPosition(1408, 612);
    Move_Arr[89][0].setPosition(1424, 500);
    Move_Arr[89][1].setPosition(1424, 16);
    Move_Arr[89][2].setPosition(1424, 32);
    Move_Arr[89][3].setPosition(1424, 48);
    Move_Arr[89][4].setPosition(1424, 64);
    Move_Arr[89][5].setPosition(1424, 80);
    Move_Arr[89][6].setPosition(1424, 96);
    Move_Arr[89][7].setPosition(-200, 0);
    Move_Arr[90][0].setPosition(1440, 500);
    Move_Arr[90][1].setPosition(1440, 516);
    Move_Arr[90][2].setPosition(1440, 532);
    Move_Arr[90][3].setPosition(1440, 548);
    Move_Arr[90][4].setPosition(1440, 564);
    Move_Arr[90][5].setPosition(1440, 580);
    Move_Arr[90][6].setPosition(1440, 96);
    Move_Arr[90][7].setPosition(1440, 612);
    Move_Arr[91][0].setPosition(1456, 500);
    Move_Arr[91][1].setPosition(1456, 516);
    Move_Arr[91][2].setPosition(1456, 532);
    Move_Arr[91][3].setPosition(1456, 548);
    Move_Arr[91][4].setPosition(1456, 564);
    Move_Arr[91][5].setPosition(1456, 580);
    Move_Arr[91][6].setPosition(1456, 96);
    Move_Arr[91][7].setPosition(1456, 612);
    Move_Arr[92][0].setPosition(1472, 500);
    Move_Arr[92][1].setPosition(1472, 16);
    Move_Arr[92][2].setPosition(1472, 32);
    Move_Arr[92][3].setPosition(1472, 48);
    Move_Arr[92][4].setPosition(1472, 64);
    Move_Arr[92][5].setPosition(1472, 80);
    Move_Arr[92][6].setPosition(1472, 96);
    Move_Arr[92][7].setPosition(1472, 612);
    Move_Arr[93][0].setPosition(1488, 500);
    Move_Arr[93][1].setPosition(1488, 16);
    Move_Arr[93][2].setPosition(1488, 32);
    Move_Arr[93][3].setPosition(1488, 48);
    Move_Arr[93][4].setPosition(1488, 64);
    Move_Arr[93][5].setPosition(1488, 80);
    Move_Arr[93][6].setPosition(1488, 96);
    Move_Arr[93][7].setPosition(1488, 612);
    Move_Arr[94][0].setPosition(1504, 500);
    Move_Arr[94][1].setPosition(1504, 16);
    Move_Arr[94][2].setPosition(1504, 32);
    Move_Arr[94][3].setPosition(1504, 48);
    Move_Arr[94][4].setPosition(1504, 564);
    Move_Arr[94][5].setPosition(1504, 580);
    Move_Arr[94][6].setPosition(1504, 596);
    Move_Arr[94][7].setPosition(1504, 612);
    Move_Arr[95][0].setPosition(1520, 500);
    Move_Arr[95][1].setPosition(1520, 16);
    Move_Arr[95][2].setPosition(1520, 32);
    Move_Arr[95][3].setPosition(1520, 48);
    Move_Arr[95][4].setPosition(1520, 564);
    Move_Arr[95][5].setPosition(1520, 580);
    Move_Arr[95][6].setPosition(1520, 596);
    Move_Arr[95][7].setPosition(1520, 612);
    Move_Arr[96][0].setPosition(1536, 500);
    Move_Arr[96][1].setPosition(1536, 16);
    Move_Arr[96][2].setPosition(1536, 32);
    Move_Arr[96][3].setPosition(1536, 48);
    Move_Arr[96][4].setPosition(1536, 64);
    Move_Arr[96][5].setPosition(1536, 80);
    Move_Arr[96][6].setPosition(1536, 596);
    Move_Arr[96][7].setPosition(1536, 612);
    Move_Arr[97][0].setPosition(1552, 500);
    Move_Arr[97][1].setPosition(1552, 16);
    Move_Arr[97][2].setPosition(1552, 32);
    Move_Arr[97][3].setPosition(1552, 48);
    Move_Arr[97][4].setPosition(1552, 64);
    Move_Arr[97][5].setPosition(1552, 580);
    Move_Arr[97][6].setPosition(1552, 596);
    Move_Arr[97][7].setPosition(1552, 612);
    Move_Arr[98][0].setPosition(1568, 500);
    Move_Arr[98][1].setPosition(1568, 16);
    Move_Arr[98][2].setPosition(1568, 32);
    Move_Arr[98][3].setPosition(1568, 48);
    Move_Arr[98][4].setPosition(1568, 64);
    Move_Arr[98][5].setPosition(1568, 580);
    Move_Arr[98][6].setPosition(1568, 596);
    Move_Arr[98][7].setPosition(1568, 612);
    Move_Arr[99][0].setPosition(1584, 500);
    Move_Arr[99][1].setPosition(1584, 16);
    Move_Arr[99][2].setPosition(1584, 32);
    Move_Arr[99][3].setPosition(1584, 48);
    Move_Arr[99][4].setPosition(1584, 64);
    Move_Arr[99][5].setPosition(1584, 80);
    Move_Arr[99][6].setPosition(1584, 96);
    Move_Arr[99][7].setPosition(1584, 612);
    Move_Arr[100][0].setPosition(1600, 500);
    Move_Arr[100][1].setPosition(1600, 16);
    Move_Arr[100][2].setPosition(1600, 32);
    Move_Arr[100][3].setPosition(1600, 48);
    Move_Arr[100][4].setPosition(1600, 64);
    Move_Arr[100][5].setPosition(1600, 80);
    Move_Arr[100][6].setPosition(1600, 96);
    Move_Arr[100][7].setPosition(1600, 612);
    Move_Arr[101][0].setPosition(1616, 500);
    Move_Arr[101][1].setPosition(1616, 516);
    Move_Arr[101][2].setPosition(1616, 532);
    Move_Arr[101][3].setPosition(1616, 548);
    Move_Arr[101][4].setPosition(1616, 564);
    Move_Arr[101][5].setPosition(1616, 80);
    Move_Arr[101][6].setPosition(1616, 96);
    Move_Arr[101][7].setPosition(1616, 612);
    Move_Arr[102][0].setPosition(1632, 500);
    Move_Arr[102][1].setPosition(1632, 516);
    Move_Arr[102][2].setPosition(1632, 532);
    Move_Arr[102][3].setPosition(1632, 548);
    Move_Arr[102][4].setPosition(1632, 564);
    Move_Arr[102][5].setPosition(1632, 80);
    Move_Arr[102][6].setPosition(1632, 96);
    Move_Arr[102][7].setPosition(1632, 612);
    Move_Arr[103][0].setPosition(1648, 500);
    Move_Arr[103][1].setPosition(1648, 516);
    Move_Arr[103][2].setPosition(1648, 532);
    Move_Arr[103][3].setPosition(1648, 548);
    Move_Arr[103][4].setPosition(1648, 564);
    Move_Arr[103][5].setPosition(1648, 580);
    Move_Arr[103][6].setPosition(1648, 596);
    Move_Arr[103][7].setPosition(1648, 612);
    Move_Arr[104][0].setPosition(1664, 500);
    Move_Arr[104][1].setPosition(1664, 516);
    Move_Arr[104][2].setPosition(1664, 532);
    Move_Arr[104][3].setPosition(1664, 548);
    Move_Arr[104][4].setPosition(1664, 564);
    Move_Arr[104][5].setPosition(1664, 580);
    Move_Arr[104][6].setPosition(1664, 596);
    Move_Arr[104][7].setPosition(1664, 612);
    Move_Arr[105][0].setPosition(1680, 500);
    Move_Arr[105][1].setPosition(1680, 516);
    Move_Arr[105][2].setPosition(1680, 532);
    Move_Arr[105][3].setPosition(1680, 548);
    Move_Arr[105][4].setPosition(1680, 564);
    Move_Arr[105][5].setPosition(1680, 580);
    Move_Arr[105][6].setPosition(1680, 596);
    Move_Arr[105][7].setPosition(1680, 612);
    Move_Arr[106][0].setPosition(1696, 500);
    Move_Arr[106][1].setPosition(1696, 516);
    Move_Arr[106][2].setPosition(1696, 532);
    Move_Arr[106][3].setPosition(1696, 548);
    Move_Arr[106][4].setPosition(1696, 564);
    Move_Arr[106][5].setPosition(1696, 580);
    Move_Arr[106][6].setPosition(1696, 596);
    Move_Arr[106][7].setPosition(1696, 612);
    Move_Arr[107][0].setPosition(1712, 500);
    Move_Arr[107][1].setPosition(1712, 516);
    Move_Arr[107][2].setPosition(1712, 532);
    Move_Arr[107][3].setPosition(1712, 548);
    Move_Arr[107][4].setPosition(1712, 564);
    Move_Arr[107][5].setPosition(1712, 580);
    Move_Arr[107][6].setPosition(1712, 596);
    Move_Arr[107][7].setPosition(1712, 612);
    Move_Arr[108][0].setPosition(1728, 500);
    Move_Arr[108][1].setPosition(1728, 516);
    Move_Arr[108][2].setPosition(1728, 532);
    Move_Arr[108][3].setPosition(1728, 548);
    Move_Arr[108][4].setPosition(1728, 564);
    Move_Arr[108][5].setPosition(1728, 580);
    Move_Arr[108][6].setPosition(1728, 596);
    Move_Arr[108][7].setPosition(1728, 612);
    Move_Arr[109][0].setPosition(1744, 500);
    Move_Arr[109][1].setPosition(1744, 516);
    Move_Arr[109][2].setPosition(1744, 532);
    Move_Arr[109][3].setPosition(1744, 548);
    Move_Arr[109][4].setPosition(1744, 564);
    Move_Arr[109][5].setPosition(1744, 580);
    Move_Arr[109][6].setPosition(1744, 596);
    Move_Arr[109][7].setPosition(1744, 612);
    Move_Arr[110][0].setPosition(1760, 500);
    Move_Arr[110][1].setPosition(1760, 516);
    Move_Arr[110][2].setPosition(1760, 532);
    Move_Arr[110][3].setPosition(1760, 548);
    Move_Arr[110][4].setPosition(1760, 564);
    Move_Arr[110][5].setPosition(1760, 580);
    Move_Arr[110][6].setPosition(1760, 596);
    Move_Arr[110][7].setPosition(1760, 612);
    Move_Arr[111][0].setPosition(1776, 500);
    Move_Arr[111][1].setPosition(1776, 516);
    Move_Arr[111][2].setPosition(1776, 532);
    Move_Arr[111][3].setPosition(1776, 548);
    Move_Arr[111][4].setPosition(1776, 564);
    Move_Arr[111][5].setPosition(1776, 580);
    Move_Arr[111][6].setPosition(1776, 596);
    Move_Arr[111][7].setPosition(1776, 612);
    Move_Arr[112][0].setPosition(1792, 500);
    Move_Arr[112][1].setPosition(1792, 516);
    Move_Arr[112][2].setPosition(1792, 532);
    Move_Arr[112][3].setPosition(1792, 548);
    Move_Arr[112][4].setPosition(1792, 564);
    Move_Arr[112][5].setPosition(1792, 580);
    Move_Arr[112][6].setPosition(1792, 596);
    Move_Arr[112][7].setPosition(1792, 612);
    srand((unsigned)time(NULL));
    for (int i = 0; i < w; ++i) {


        for (int j = 0; j < h; ++j)
        {
            if (Wall_Arr[i][j].getPosition().x == -200)
            {
                Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x - Wall_Arr[i][j].getPosition().x - 10000, 0);
            }
            else
            Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + (74 * i), Wall_Arr[i][j].getPosition().y + (74 * j));
            Wall_Arr[i][j].setSize(size);
            
            int r = rand() % 10;
            if (r < 2)
            {
                Wall_Arr[i][j].setTexture(&brick4);
                Wall_Arr[i][j].setFillColor(sf::Color(100, 100, 100));
            }
            else if (r < 4)
            {
                Wall_Arr[i][j].setTexture(&brick2);
                Wall_Arr[i][j].setFillColor(sf::Color(150, 130, 30));
            }
            else if (r < 6)
            {
                Wall_Arr[i][j].setTexture(&brick3);
                Wall_Arr[i][j].setFillColor(sf::Color(150, 150, 130));
            }
            else if(r < 8)
            {
                Wall_Arr[i][j].setTexture(&brick);

                
            }
            else
            {
                Wall_Arr[i][j].setTexture(&brick5);
                Wall_Arr[i][j].setFillColor(sf::Color(150, 150, 130));
            }
            //Wall_Arr[i][j].setOutlineThickness(1);
            Wall_Arr[i][j].setOutlineColor(sf::Color(0, 0, 0));
  
            //if (j == 7)
            //{
            //    Wall_Arr[i][j].setTexture(&gras);
            //   // Wall_Arr[i][j].setFillColor(sf::Color(100, 100, 100));
            //}



            if (Move_Arr[i][j].getPosition().x == -200 || Move_Arr[i][j].getPosition().y > 112)
            {
                Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x - Move_Arr[i][j].getPosition().x - 10000, 0);
            }
            else
            Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + (74 * i), Move_Arr[i][j].getPosition().y + (74 * j) );
            Move_Arr[i][j].setSize(size);
            Move_Arr[i][j].setFillColor(sf::Color(200, 70, 70));
           /* Move_Arr[i][j].setOutlineThickness(1);
            Move_Arr[i][j].setOutlineColor(sf::Color(0, 0, 0));*/
        }
    }
    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                Window.close();
                /*for (int i = 0; i < w; ++i) {
                    for (int j = 0; j < h; ++j) {
                        outfile << "Wall_Arr[" << i << "][" << j << "].setPosition(" << Wall_Arr[i][j].getPosition().x << " , " << Wall_Arr[i][j].getPosition().y << ");" << std::endl;
                    }
                }
                for (int i = 0; i < w; ++i) {
                    for (int j = 0; j < h; ++j) {
                        outfile << "Move_Arr[" << i << "][" << j << "].setPosition(" << Move_Arr[i][j].getPosition().x << " , " << Move_Arr[i][j].getPosition().y << ");" << std::endl;
                    }
                }*/
            }
            //          }	

        }
        /* B_i = (ball.getPosition().x + x) / rect_W ;
         B_j = ball.getPosition().y / rect_H;*/

        
        ballSpeed.x = ballSpeed.x * 0.25;
        if (ballSpeed.y < 50 && ground != true)
        {

            ballSpeed.y += rect_W * 0.015;

        }
        if (ballSpeed.y > 30 || ballSpeed.y < -30) {

            ballSpeed.y = 30;

        }/*
        if (wallSpeed.x < 2 && wallSpeed.x > -2)
            wallSpeed.x = 0;
        /*if (wallSpeed.x =! 0)
        {
            wallSpeed.x = wallSpeed.x * 0.75;
        }*/
        //if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && it - temp_it > 10)
        //{
        //    B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
        //    B_j = ball.getPosition().y / rect_H;
        //        int i = ((event.mouseButton.x + x) / rect_W);
        //        int j = event.mouseButton.x / rect_H;
        //        if (i > 114 || i < 0)
        //            continue;
        //        if (j > 9 || j < 0)
        //            continue;
        //        std::cout << std::endl << i << " ; " << j;
        //        //array[i][j].setFillColor(Color(255, 0, 0));

        //        if (Wall_Arr[i][j].getPosition().x > -10000 && Wall_Arr[i][j].getPosition().y >0)
        //        {
        //            Move_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x, Wall_Arr[i][j].getPosition().y);
        //            Wall_Arr[i][j].setPosition(-10000, 0);
        //        }
        //        else if (Move_Arr[i][j].getPosition().x > -10000 && Move_Arr[i][j].getPosition().y > 0)
        //        {
        //            Wall_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x, Move_Arr[i][j].getPosition().y);
        //            Move_Arr[i][j].setPosition(-10000, 0);

        //        }
        //        temp_it = it;
        //}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))// && it - r > 5)
        {
            ballSpeed.x = -rect_W * 0.25;
            r = it;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))// && it - l > 5)
        {
            ballSpeed.x = rect_W * 0.25;
            l = it;
        }
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) )
        {



            for (int i = 0; i < w; i++)
                for (int j = 0; j < h; j++)
                {
                    Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x - rect_W * 0.25, Wall_Arr[i][j].getPosition().y);
                    Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x - rect_W * 0.25, Move_Arr[i][j].getPosition().y);
                }
            r++;
            temp_it = it;
        }*/
        /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
         {
             for (int i = 0; i < w; i++)
                 for (int j = 0; j < h; j++)
                 {
                     Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + rect_W * 0.25, Wall_Arr[i][j].getPosition().y);
                     Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + rect_W * 0.25, Move_Arr[i][j].getPosition().y);

                 }
             l++;
             temp_it = it;
         }*/

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))// && it - q > 1)
        {

            //ballSpeed.y = (ballSpeed.y - rect_H)*0.25;
            if (ball.getPosition().y > 20)// && it - q > 10)
            {
                ground = false;
                ballSpeed.y = -(rect_W / 5);
                q = it;
            }
            // q = it;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && it - q > 1)
        {
            ballSpeed.y = (ballSpeed.y + rect_H) * 0.25;
            q = it;
        }
        /*if (ground != true)*/

        if (ball.getPosition().y <= 0)
        {
            if (it - j == 1)
                continue;



            ballSpeed.y = -ballSpeed.y + ballSpeed.y * 0.6;
            j = it;
            ball.setPosition(ball.getPosition().x, 0);
            //std::cout << "top !!" << std::endl;


        }
        if (ball.getPosition().y >= Height - (ball.getRadius() * 2))
        {
            if (ground != true) {
                if (it - k - 1 == 0)
                    continue;


                //std::cout << "Ball speed = " << ballSpeed.y * 2.83 << " ; time = " << time << std::endl;
                ballSpeed.y = -ballSpeed.y * 0.6;
                /*ballSpeed.x = ballSpeed.x + ballSpeed.x * (-0.10);*/
                ground = false;
                //std::cout << "Bounce Speed  " << ballSpeed.y << std::endl;
                k = it;

            }
            if (ballSpeed.y > -7)
            {
                ground = true;
                ball.setPosition(ball.getPosition().x, Height - ball.getRadius() * 2);
                ballSpeed.y = 0;



            }
        }

        /*  for (int i = 0; i < (w - 10); i++)
          {
              for (int j = 0; j < h; j++)
              {

                  if (ball.getPosition().y < (Wall_Arr[i][j].getPosition().y))
                      ballSpeed.y *= -1;

              }

          }*/


        x = x - ballSpeed.x;
        ball.setPosition(ball.getPosition().x, ball.getPosition().y + ballSpeed.y);
        //ballSpeed.y = 0;
       // ball.setPosition(ball.getPosition().x + ballSpeed.x, ball.getPosition().y);
        /*for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
            {
                Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + ballSpeed.x, Wall_Arr[i][j].getPosition().y);
                Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + ballSpeed.x, Move_Arr[i][j].getPosition().y);
            }*/
            /*  x = x - ballSpeed.x;
              ball.setPosition(ball.getPosition().x, ball.getPosition().y + ballSpeed.y);*/
              //ballSpeed.y = 0;
              // ball.setPosition(ball.getPosition().x + ballSpeed.x, ball.getPosition().y);
       
        if (ballSpeed.x < 3 && ballSpeed.x > -3)
            ballSpeed.x = 0;
       /* if (ball.getGlobalBounds().intersects(Wall_Arr[B_i][B_j].getGlobalBounds()) || ball.getGlobalBounds().intersects(Wall_Arr[B_i][B_j + 1].getGlobalBounds()) || ball.getGlobalBounds().intersects(Wall_Arr[B_i + 1][B_j].getGlobalBounds()) || ball.getGlobalBounds().intersects(Wall_Arr[B_i][B_j - 1].getGlobalBounds()) || ball.getGlobalBounds().intersects(Wall_Arr[B_i - 1][B_j].getGlobalBounds()))
            goto checker;*/
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
            {
                Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + ballSpeed.x, Wall_Arr[i][j].getPosition().y);
                Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + ballSpeed.x, Move_Arr[i][j].getPosition().y);
                
            }
       


        B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
        B_j = ball.getPosition().y / rect_H;
        std::cout << "  Test Location : " << B_i << "  ;  " << B_j << std::endl;

        /* B_i = ((ball.getPosition().x + x )/ rect_W);
         B_j = ball.getPosition().y / rect_H;*/
        /*bool L_col = false;
        bool R_col = false;*/



        //if (Wall_Arr[B_i][B_j].getPosition().x > -10000)
        //{
        //    std::cout << "collision : ";
        //    if (Move_Arr[B_i][B_j-1].getPosition().x > -10000 && ball.getPosition().y < Move_Arr[B_i][B_j-1].getPosition().y)
        //    {
        //        std::cout << "top collision : ";
        //        ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j-1].getPosition().y);
        //        //ballSpeed.y = -ballSpeed.y*0.5;
        //    }
        //}


        //TOP CHECKER
        //if (Wall_Arr[B_i][B_j - 1].getPosition().x > -10000) 
        //{
        //    //B_j = ball.getPosition().y / rect_H + 0.5;
        //    if (ball.getPosition().y < Move_Arr[B_i][B_j].getPosition().y)
        //    {
        //        std::cout << "top collision 1: ";
        //        ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
        //        //ballSpeed.y = -ballSpeed.y*0.5;
        //    }
        //    
        //}
        

        loc = ball.getPosition().x;
        
         

        
    checker:


        //LEFT CHECKER

        if (Wall_Arr[B_i][B_j].getPosition().x > -5000)
        {

            if (ball.getPosition().x < Move_Arr[B_i + 1][B_j].getPosition().x && ballSpeed.x > 0)
            {
                col = true;
                //L_col = true;
                std::cout << " Left collision : " << B_i << " ; " << B_j << " ; WX = " << Wall_Arr[B_i][B_j].getPosition().x << " ; WY = " << Wall_Arr[B_i][B_j].getPosition().y << " ; ";
                //ball.setPosition(Move_Arr[B_i + 1][B_j].getPosition().x, ball.getPosition().y);
                loc = 180 - Move_Arr[B_i + 1][B_j].getPosition().x;

                for (int i = 0; i < w; i++)
                    for (int j = 0; j < h; j++)
                    {
                        Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + loc, Wall_Arr[i][j].getPosition().y);
                        Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + loc, Move_Arr[i][j].getPosition().y);

                    }
           //     ballSpeed.x = -ballSpeed.x;
                /*for (int i = 0; i < w; i++)
                    for (int j = 0; j < h; j++)
                    {
                        Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + (180 - ball.getPosition().x), Wall_Arr[i][j].getPosition().y);
                        Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + (180 - ball.getPosition().x), Move_Arr[i][j].getPosition().y);

                    }*/
                /* B_i = ((ball.getPosition().x + x) / rect_W);
                 B_j = ball.getPosition().y / rect_H;*/
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;

            }

        }
        //TOP CHECKER

        if (Wall_Arr[B_i][B_j].getPosition().x > -5000)
        {

            if (ball.getPosition().y < Move_Arr[B_i][B_j + 1].getPosition().y && ballSpeed.y < 0)
            {

                std::cout << "top collision: " << B_i << " ; " << B_j;
                ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j + 1].getPosition().y);
             //   ballSpeed.y = -ballSpeed.y * 0.85;
                /* B_i = ((ball.getPosition().x + x) / rect_W);
                 B_j = ball.getPosition().y / rect_H;*/
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
                top = 5;
            }
        }
        //RIGHT CHECKER
        if (Wall_Arr[B_i + 1][B_j].getPosition().x > -5000 && Wall_Arr[B_i + 1][B_j].getPosition().y != 0)
        {

            if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x && ballSpeed.x < 0)
            {
                col = true;
                //R_col = true;
                std::cout << " Right collision : " << B_i + 1 << " ; " << B_j << " ; ";
                //ball.setPosition(Move_Arr[B_i][B_j].getPosition().x, ball.getPosition().y);
                loc = 180 - Move_Arr[B_i][B_j].getPosition().x + 2;

                for (int i = 0; i < w; i++)
                    for (int j = 0; j < h; j++)
                    {
                        Wall_Arr[i][j].setPosition(Wall_Arr[i][j].getPosition().x + loc, Wall_Arr[i][j].getPosition().y);
                        Move_Arr[i][j].setPosition(Move_Arr[i][j].getPosition().x + loc, Move_Arr[i][j].getPosition().y);

                    }
               // ballSpeed.x = -ballSpeed.x;
                /*B_i = ((ball.getPosition().x + x) / rect_W);
                B_j = ball.getPosition().y / rect_H;*/
                B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                B_j = ball.getPosition().y / rect_H;
            }

        }

                //TOP RIGHT CHECKER

                if (Wall_Arr[B_i + 1][B_j].getPosition().x > -5000 && Wall_Arr[B_i - 1][B_j].getPosition().x <= -5000 )
                {
                   
                    if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x && ballSpeed.y < 0)
                    {

                        std::cout << "top collision right : " << B_i << " ; " << B_j << " ; ";
                        ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j + 1].getPosition().y);
                 //       ballSpeed.y = -ballSpeed.y * 0.85;
                       /* B_i = ((ball.getPosition().x + x) / rect_W);
                        B_j = ball.getPosition().y / rect_H;*/
                        B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                        B_j = ball.getPosition().y / rect_H;
                    }
                }
                //BOTTOM CHECKER

                if (top == 0  && Wall_Arr[B_i][B_j + 1].getPosition().x > -5000)// && Wall_Arr[B_i][B_j + 1].getPosition().x > -10000)
                {
                    

                    if (ball.getPosition().y > Move_Arr[B_i][B_j].getPosition().y && ballSpeed.y > 0)
                    {

                        std::cout << "bottom collision : " << B_i << " ; " << B_j + 1 << " ; ";
                        ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                   //     ballSpeed.y = -ballSpeed.y * 0.75;
                        /*B_i = ((ball.getPosition().x + x) / rect_W);
                        B_j = ball.getPosition().y / rect_H;*/
                        B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                        B_j = ball.getPosition().y / rect_H;
                        g = it;
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
                    
                    if (ball.getPosition().x > Move_Arr[B_i][B_j].getPosition().x && ballSpeed.y > 0)
                    {

                        std::cout << "bottom collision right : " << B_i + 1 << " ; " << B_j + 1 << " ; ";
                        ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
                      //    ballSpeed.y = -ballSpeed.y * 0.75;
                        /*B_i = ((ball.getPosition().x + x) / rect_W);
                        B_j = ball.getPosition().y / rect_H;*/
                          B_i = (102 - ((Wall_Arr[102][0].getPosition().x - ball.getPosition().x)) / rect_W);
                          B_j = ball.getPosition().y / rect_H;
                    }
                }
                
                if(top != 0)
                    top = top - 1;
            /*L_col= false;
            R_col = false;*/
            
                /*loc2 = ball.getPosition().x;
            if (col == true)
                std::cout << std::endl << " Difference on X = " << loc << " - " << loc2 << "=  " << loc2 - loc << " ;   ";
            col = false;*/

           

           // std::cout << std::endl << " i = " << B_i << " ; j = " << B_j << " ;";
            
            if (Wall_Arr[B_i][B_j - 1].getPosition().x > -10000 && Wall_Arr[B_i][B_j + 1].getPosition().x > -10000)
            {
                ground == true;
                ballSpeed.y = 0;
            }
            if (Wall_Arr[B_i][B_j + 1].getPosition().x <= -10000)
                ground = false;
            //if (Wall_Arr[B_i][B_j].getPosition().x > -10000 || Wall_Arr[B_i - 1][B_j].getPosition().x > -10000)
            //{
            //   
            //    
            //        if (ball.getPosition().x >= Move_Arr[B_i][B_j].getPosition().x || ball.getPosition().x <= Move_Arr[B_i][B_j].getPosition().x)
            //            if (it - t > 5)
            //            {

            //                ballSpeed.x = -ballSpeed.x*0.8;
            //                t = it;
            //                
            //            }
            //}

            //if (Wall_Arr[B_i][B_j + 1].getPosition().x > -10000)
            //{
            //    //std::cout << std::endl << Wall_Arr[B_i][B_j + 1].getPosition().x << std::endl;
            //    if (ball.getPosition().y > Move_Arr[B_i][B_j].getPosition().y&& it - g > 5 && ground != true)
            //    {
            //        
            //        
            //            ballSpeed.y = -ballSpeed.y * 0.75;
            //            ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j].getPosition().y);
            //            // std::cout << std::endl << "collision bottom" << std::endl;

            //            g = it;
            //            if (ballSpeed.y > -6)
            //            {
            //                ballSpeed.y = 0;
            //                ground = true;
            //            }
            //        
            //    }
            //}
            //if (ballSpeed.y < 0 && Wall_Arr[B_i][B_j - 1].getPosition().x > -10000)
            //{
            //   // std::cout << std::endl << "check" << std::endl;
            //    if (ball.getPosition().y < Move_Arr[B_i][B_j].getPosition().y)
            //    {
            //        
            //        ballSpeed.y = -ballSpeed.y*0.25;
            //        ball.setPosition(ball.getPosition().x, Move_Arr[B_i][B_j+1].getPosition().y);
            //        //std::cout << std::endl << "collision top" << std::endl;

            //       
            //    }
            //}
           
            std::cout << "Ball Position X = " << ball.getPosition().x << " ; Ball Position Y = " << ball.getPosition().y << " ; BallSpeed X= " << ballSpeed.x << " ; BallSpeed Y= " << ballSpeed.y << " ; " << "B_i = " << B_i << " ; B_j= " << B_j << " ; " << std::endl;
            
            
           // std::cout << std::endl << "B_i = " << B_i << " ; B_j= " << B_j << " ; " << std::endl;
            it++;

            ghass.setPosition(ghass.getPosition().x + ballSpeed.x, 0);
        /*    ghass2.setPosition(ghass2.getPosition().x + ballSpeed.x, 0);
            ghass3.setPosition(ghass3.getPosition().x + ballSpeed.x, 0);
            ghass4.setPosition(ghass4.getPosition().x + ballSpeed.x, 0);
            ghass5.setPosition(ghass5.getPosition().x + ballSpeed.x, 0);
            ghass6.setPosition(ghass6.getPosition().x + ballSpeed.x, 0);*/
             
   
            
            //back1.setPosition(back1.getPosition().x + ballSpeed.x, 0);
            //back2.setPosition(back2.getPosition().x + ballSpeed.x, 0);
            //back3.setPosition(back3.getPosition().x + ballSpeed.x, 0);
            //back4.setPosition(back4.getPosition().x + ballSpeed.x, 0);

            Window.clear();//sf::Color(200,70,70));
           
            Window.draw(back1);
            Window.draw(back2);
            Window.draw(back3);
            Window.draw(back4);
    
            for (int i = 0; i < (w - 10); i++)
                for (int j = 0; j < h; j++)
                {
                    /*if (Move_Arr[i][j].getPosition().x > -rect_W && Move_Arr[i][j].getPosition().x < Width + rect_W)
                        Window.draw(Move_Arr[i][j]);*/
                    if (Wall_Arr[i][j].getPosition().x > -rect_W && Wall_Arr[i][j].getPosition().x < Width + rect_W)
                        Window.draw(Wall_Arr[i][j]);
                }
            //Window.draw(block);

            Window.draw(ball);
           
         // Window.draw(ghass);
          /*  /*  Window.draw(ghass2);
            Window.draw(ghass3);
            Window.draw(ghass4);
            Window.draw(ghass5);
            Window.draw(ghass6);*/

            Window.display();

        /* for (int i = 0; i < w; ++i) {
             delete[] Move_Arr[i];
             delete[] Wall_Arr[i];
         }
         delete[] Move_Arr;
         delete[] Wall_Arr;*/

    }
    return 0;
}