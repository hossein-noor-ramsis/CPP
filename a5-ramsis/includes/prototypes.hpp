#ifndef PROTOTYPES_HPP
#define PROTOTYPES_HPP

int view(System &system);
int controller(System &system, RenderWindow &window, Clock &updateTimer);
int dragHandler(System &system, RenderWindow &window);
int sideBarHandler(System &system);
int waveHandler(System &system, Clock &updateTimer);
int towerHandler(System &system);
int generateUniqueId();
int gameOverHandler(System &system, RenderWindow &window);
int winGameHandler(System &system, RenderWindow &window);
float getDistanceBetweenSprites(const sf::Sprite &sprite1, const sf::Sprite &sprite2);
float getCenterDistanceBetweenSprites(const sf::Sprite &sprite1, const sf::Sprite &sprite2);
float getRandomFloat(float min, float max);
map<int, shared_ptr<Enemy>> shuffleWave(const map<int, shared_ptr<Enemy>> &wave);

#endif
