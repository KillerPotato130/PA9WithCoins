#pragma once


#include "MainMenu.h"

using std::cout;
using std::endl;

class Tests {

public:

	void testItemCollision(Item& item) {

		sf::Vector2i characterPosGrid = { 0,0 }, itemPosGrid = {0,0};
		
		item.spawn();
		cout << "Item pixel position: " << item.getPos().x << ", " << item.getPos().y << endl; 
		
		itemPosGrid = item.itemGridPos();
		cout << "Item grid position: " << itemPosGrid.x << ", " << itemPosGrid.y << endl; 

		while (itemPosGrid != characterPosGrid) {
			if (characterPosGrid.x < itemPosGrid.x) {
				characterPosGrid.x += 1;
			}
			if (characterPosGrid.x > itemPosGrid.x) {
				characterPosGrid.x -= 1;
			}
			if (characterPosGrid.y < itemPosGrid.y) {
				characterPosGrid.y += 1;
			}
			if (characterPosGrid.y > itemPosGrid.y) {
				characterPosGrid.y -= 1;
			}
			cout << "Character grid position: " << characterPosGrid.x << ", " << characterPosGrid.y << endl;
		}
		if (itemPosGrid == characterPosGrid) {
			//cout << "COLLISION" << endl;
			cout << "Collision Test Passed!" << endl;
		}
	}

	void testSpriteTextures(sf::Texture& texture) {
		bool passed = true;
		if (!texture.loadFromFile("purple_orbs.png")) {
			cout << "Load artifact texture failed!" << endl;
			passed = false;
		}
		if (!texture.loadFromFile("coinSprite.png")) {
			cout << "Load coin texture failed!" << endl;
			passed = false;
		}
		if (!texture.loadFromFile("professor_walk_cycle_no_hat.png")) {
			cout << "Load professor texture failed!" << endl;
			passed = false;
		}
		if (passed == true) {
			cout << "Loading sprite textures test passed!" << endl; 
		}
	}

	void runTests() {

		Item item;
		sf::Texture texture;

		testItemCollision(item);

		testSpriteTextures(texture); 

	}



};