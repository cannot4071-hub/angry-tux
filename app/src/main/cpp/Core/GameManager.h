#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <box2d/box2d.h>
#include <vector>
#include "Bird.h"

class GameManager {
private:
    b2World* world;
    std::vector<Bird*> activeBirds;
    b2Vec2 slingshotAnchor;
    long totalScore;

public:
    GameManager();
    ~GameManager();

    void updatePhysics(float timeStep);
    void launchActiveBird(Bird* bird, b2Vec2 touchDragDelta);
    long getScore() const;
};

#endif
