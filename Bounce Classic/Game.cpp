#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int main()
{
	int Width = 1280;
	int Height = 720;
	int rect_W = 90;
	int rect_H = 90;
	const int s = 113;
	const int e = 6;



	RenderWindow Window(VideoMode(Width, Height), "Bounce Classic");
	Window.setFramerateLimit(60);

	Vector2f size(rect_W, rect_H);
	RectangleShape block1(size);
	RectangleShape block2(size);
	block1.setOutlineThickness(1);
	block1.setOutlineColor(Color(0, 0, 0));
	block2.setOutlineThickness(1);
	block2.setOutlineColor(Color(0, 0, 0));


	RectangleShape top_array[s];
	RectangleShape bottom_array[s];
	RectangleShape left_array[e];
	RectangleShape right_array[e];

	CircleShape ball(40);
	ball.setFillColor(Color(255, 50, 50));
	ball.setPosition((Width / static_cast<float>(2)) - ball.getRadius(), (Height / static_cast<float>(2)) - ball.getRadius());


	for (int i = 0; i < s; i++)
	{
		top_array[i].setSize(size);
		top_array[i].setOutlineThickness(1);
		top_array[i].setOutlineColor(Color(0, 0, 0));
		if (i == 0)
			top_array[i].setPosition(0, 0);
		else
			top_array[i].setPosition(top_array[i - 1].getPosition().x + rect_W, top_array[i - 1].getPosition().y);
	}
	for (int i = 0; i < s; i++)
	{
		bottom_array[i].setSize(size);
		bottom_array[i].setOutlineThickness(1);
		bottom_array[i].setOutlineColor(Color(0, 0, 0));
		if (i == 0)
			bottom_array[i].setPosition(0, Height - rect_W);
		else
			bottom_array[i].setPosition(bottom_array[i - 1].getPosition().x + rect_W, bottom_array[i - 1].getPosition().y);
	}
	for (int i = 0; i < e; i++)
	{
		left_array[i].setSize(size);
		left_array[i].setOutlineThickness(1);
		left_array[i].setOutlineColor(Color(0, 0, 0));
		
	}

	for (int i = 0; i < e; i++)
	{
		right_array[i].setSize(size);
		right_array[i].setOutlineThickness(1);
		right_array[i].setOutlineColor(Color(0, 0, 0));
		
	}
	while (Window.isOpen()) {
		sf::Event event;
		while (Window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				Window.close();

		}
		for (int i = 0; i < e; i++)
		{
		
			if (i == 0)
				left_array[i].setPosition(top_array[0].getPosition().x, top_array[0].getPosition().y + rect_H);
			else
				left_array[i].setPosition(left_array[i - 1].getPosition().x, left_array[i - 1].getPosition().y + rect_H);
		}

		for (int i = 0; i < e; i++)
		{
			if (i == 0)
				right_array[i].setPosition(top_array[s - 1].getPosition().x, top_array[s - 1].getPosition().y + rect_H);
			else
				right_array[i].setPosition(right_array[i - 1].getPosition().x, right_array[i - 1].getPosition().y + rect_H);
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			for (int i = 0; i < s; i++)
			{

				top_array[i].setPosition(top_array[i].getPosition().x - 30, top_array[i].getPosition().y);

			}
			for (int i = 0; i < s; i++)
			{

				bottom_array[i].setPosition(bottom_array[i].getPosition().x - 30, bottom_array[i].getPosition().y);
			}

		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			for (int i = 0; i < s; i++)
			{
				
				top_array[i].setPosition(top_array[i].getPosition().x + 30, top_array[i].getPosition().y);

			}
			for (int i = 0; i < s; i++)
			{

				bottom_array[i].setPosition(bottom_array[i].getPosition().x + 30, bottom_array[i].getPosition().y);

			}
		}

		Window.clear();
			for (int i = 0; i < s; i++)
			{
				
				if (top_array[i].getPosition().x < -rect_W - 10)
					continue;
				Window.draw(top_array[i]);
				if (top_array[i + 1].getPosition().x > Width)
					break;
			}
			for (int i = 0; i < s; i++)
			{

				if (bottom_array[i].getPosition().x < -rect_W - 10)
					continue;
				Window.draw(bottom_array[i]);
				if (bottom_array[i + 1].getPosition().x > Width)
					break;
			}
			for (int i = 0; i < e; i++)
			{
				
				if (left_array[i].getPosition().x < -10)
					break;
				Window.draw(left_array[i]);
			}
			for (int i = 0; i < e; i++)
			{
				if (right_array[i].getPosition().x > Width)
					break;
				Window.draw(right_array[i]);
			}
		
		Window.draw(ball);

		Window.display();
	}
}

	
