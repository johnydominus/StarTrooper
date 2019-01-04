#pragma once
#include "Player.h"
#include "Map.h"
#include "Reticle.h"
#include "Monster.h"
#include "Bullet.h"
#include <ctime>
#include <sstream>
#include "SFML/Graphics.hpp"

class Engine
{
private:
	sf::RenderWindow mWindow;

	Player thePlayer;
	Map theMap;
	Reticle theReticle;
	Monster* allMonsters;
	Bullet* bullets;

	sf::Sprite** mapSprites;
	sf::Sprite* fenceSpritesX;
	sf::Sprite* fenceSpritesY;
	sf::Texture theFenceTexture;
	sf::Text hud;
	sf::Font theFont;

	int enemiesAlive;
	float secureZone = 250, angle, spriteSizeX, spriteSizeY;

	int i, j, a, b, c, d, windowX, windowY, mapX, mapY, ammoNumber, enemiesNumber;
	int mapXstart=0, mapYstart=0, ammoNumberStart=0, enemiesNumberStart=0;

	void input();
	void update(float timeInSeconds);
	void draw();

	void killMonster(Monster* aMonster, Bullet* aBullet);
	void killPlayer(Monster*);
	void shoot(Bullet* aBullet);
	Bullet* getBullet(int i);

	void setWindowSize(int mapX, int mapY);
	void setMapSize(float mapWidth, float mapHeight);
	void setAmmoNumber(int ammoN);
	void setEnemiesNumber(int enemiesN);
	void setEnemiesRandomSpeed();
	void setMonsterRandomPosition();

	bool mouseButtonPressed;
	time_t previous_shot;
	time_t current_shot;

	POINT* enemiesNextSteps;
	bool* monstersCollide;

public:
	Engine(int widthWindow = 0, int heightWindow = 0, int mapWidth = 0, int mapHeight = 0, int ammoN = 0, int enemiesN = 0);
	~Engine();

	void start();
};
