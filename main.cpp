#include <iostream>
#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 800), "Todo",Style::Default);
	Event event;

	/////////////////////////////////
	///////////////////////////////// background

	Texture T;
	T.loadFromFile("T.png");
	Sprite S;
	S.setScale(Vector2f(2.f, 2.7f));
	S.setTexture(T);

	/////////////////////////////////
	///////////////////////////////// add icon
	Texture add;
	add.loadFromFile("add.png");
	Sprite spr;
	spr.setTexture(add);
	spr.setPosition(Vector2f(window.getSize().x - 80, window.getSize().y / 2 - 188));
	spr.setScale(0.6f, 0.6f);

	Font F;
	F.loadFromFile("Frizon.ttf");
	Text TXT;
	TXT.setString("Add Task");
	TXT.setFont(F);
	TXT.setFillColor(Color::Black);
	TXT.setPosition(window.getSize().x / 2 + 40, window.getSize().y / 2 - 170);


	////////////////////////////////
	//////////////////////////////// delete icon


	Texture del;
	del.loadFromFile("delete.png");
	Sprite Delete;
	Delete.setTexture(del);
	Delete.setPosition(Vector2f(window.getSize().x - 80, window.getSize().y / 2 - 100));
	Delete.setScale(0.6f, 0.6f);

	Font F1;
	F1.loadFromFile("Frizon.ttf");
	Text TXT1;
	TXT1.setString("Delete Task");
	TXT1.setFont(F1);
	TXT1.setFillColor(Color::Black);
	TXT1.setPosition(window.getSize().x / 2 + 40, window.getSize().y / 2 - 90);



	////////////////////////////////
	//////////////////////////////// Complete icon
	Texture complete;
	complete.loadFromFile("complete.png");
	Sprite comp;
	comp.setTexture(complete);
	comp.setPosition(Vector2f(window.getSize().x - 80, window.getSize().y / 2 - 20));
	comp.setScale(0.6f, 0.6f);

	Font F2;
	F2.loadFromFile("Frizon.ttf");
	Text TXT2;
	TXT2.setString("Complete Task");
	TXT2.setFont(F2);
	TXT2.setFillColor(Color::Black);
	TXT2.setPosition(window.getSize().x / 2 + 30, window.getSize().y / 2 );


	////////////////////////////////
	//////////////////////////////// Favorite

	Texture favorite;
	favorite.loadFromFile("favorite.png");
	Sprite unf;
	unf.setTexture(favorite);
	unf.setPosition(Vector2f(window.getSize().x - 80, window.getSize().y / 2 + 70));
	unf.setScale(Vector2f(0.6f, 0.6f));

	Text TXT3;
	TXT3.setString("Favorite Task");
	TXT3.setFont(F);
	TXT3.setFillColor(Color::Black);
	TXT3.setPosition(window.getSize().x / 2 + 40, window.getSize().y / 2 + 80);

	
	////////////////////////////////
	//////////////////////////////// edit

	Texture edit;
	edit.loadFromFile("edit.png");
	Sprite ed;
	ed.setTexture(edit);
	ed.setPosition(Vector2f(window.getSize().x - 80, window.getSize().y / 2 + 155));
	ed.setScale(0.6f, 0.6f);
	
	Text TXT4;
	TXT4.setString("Edit Task");
	TXT4.setFont(F);
	TXT4.setFillColor(Color::Black);
	TXT4.setPosition(window.getSize().x / 2 + 40, window.getSize().y / 2 + 165);



	////////////////////////////////
	//////////////////////////////// showlist icon

	Texture list;
	list.loadFromFile("list.png");
	Sprite lst;
	lst.setTexture(list);
	lst.setPosition(Vector2f(window.getSize().x - 80, window.getSize().y / 2 + 235));
	lst.setScale(0.6f, 0.6f);

	Text TXT5;
	TXT5.setString("Show List");
	TXT5.setFont(F);
	TXT5.setFillColor(Color::Black);
	TXT5.setPosition(window.getSize().x / 2 + 40, window.getSize().y / 2 + 245);

	////////////////////////////////
	////////////////////////////////

	Texture exit;
	exit.loadFromFile("exit.png");
	Sprite EX;
	EX.setTexture(exit);
	EX.setPosition(Vector2f(window.getSize().x - 80, window.getSize().y / 2 + 322));
	EX.setScale(0.6f, 0.6f);

	Text TXT6;
	TXT6.setString("EXIT APP");
	TXT6.setFont(F);
	TXT6.setFillColor(Color::Black);
	TXT6.setPosition(window.getSize().x / 2 + 40, window.getSize().y / 2 + 335);
	

	////////////////////////////////
	////////////////////////////////



	////////////////////////////////
	////////////////////////////////


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
				window.close();
		}
		
		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////

		if (TXT.getGlobalBounds().contains(static_cast <Vector2f> (Mouse::getPosition(window))))
		{
			TXT.setFillColor(Color::Green);
		}
		else
		{
			TXT.setFillColor(Color::Black);
		}
		/////////////////////////////////////////////////////////
		if (TXT1.getGlobalBounds().contains(static_cast <Vector2f> (Mouse::getPosition(window))))
		{
			TXT1.setFillColor(Color::Green);
		}
		else
		{
			TXT1.setFillColor(Color::Black);
		}

		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////
		if (TXT2.getGlobalBounds().contains(static_cast <Vector2f> (Mouse::getPosition(window))))
		{
			TXT2.setFillColor(Color::Green);
		}
		else
		{
			TXT2.setFillColor(Color::Black);
		}

		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////
		if (TXT3.getGlobalBounds().contains(static_cast <Vector2f> (Mouse::getPosition(window))))
		{
			TXT3.setFillColor(Color::Green);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				cout << "Button pressed" << endl;
			}
		}
		else
		{
			TXT3.setFillColor(Color::Black);
		}

		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////
		if (TXT4.getGlobalBounds().contains(static_cast <Vector2f> (Mouse::getPosition(window))))
		{
			TXT4.setFillColor(Color::Green);
		}
		else
		{
			TXT4.setFillColor(Color::Black);
		}

		/////////////////////////////////////////////////////////

		/////////////////////////////////////////////////////////
		if (TXT5.getGlobalBounds().contains(static_cast <Vector2f> (Mouse::getPosition(window))))
		{
			TXT5.setFillColor(Color::Green);
		}
		else
		{
			TXT5.setFillColor(Color::Black);
		}

		/////////////////////////////////////////////////////////

		/////////////////////////////////////////////////////////
		if (TXT6.getGlobalBounds().contains(static_cast <Vector2f> (Mouse::getPosition(window))))
		{
			TXT6.setFillColor(Color::Green);
		}
		else
		{
			TXT6.setFillColor(Color::Black);
		}

		/////////////////////////////////////////////////////////


		


		/////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////

		window.clear(Color::Black);
		window.draw(S);
		window.draw(spr);
		window.draw(Delete);
		window.draw(comp);
		window.draw(unf);
		window.draw(ed);
		window.draw(lst);
		window.draw(EX);
		window.draw(TXT);
		window.draw(TXT1);
		window.draw(TXT2);
		window.draw(TXT3);
		window.draw(TXT4);
		window.draw(TXT5);
		window.draw(TXT6);
		window.display();
	}


	return 0;
}