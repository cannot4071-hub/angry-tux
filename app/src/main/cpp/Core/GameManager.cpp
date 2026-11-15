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
    GameManager() {
        b2Vec2 gravity(0.0f, -9.81f);
        world = new b2World(gravity);
        slingshotAnchor = b2Vec2(-5.0f, -2.0f);
        totalScore = 0;
    }

    ~GameManager() {
        delete world;
    }

    void updatePhysics(float timeStep) {
        int velocityIterations = 6;
        int positionIterations = 2;
        world->Step(timeStep, velocityIterations, positionIterations);
    }

    void launchActiveBird(Bird* bird, b2Vec2 touchDragDelta) {
        b2Body* body = bird->getBody();
        body->SetType(b2_dynamicBody); // Release from slingshot static hold
        
        float powerScale = 14.0f;
        b2Vec2 impulse(-touchDragDelta.x * powerScale, -touchDragDelta.y * powerScale);
        body->ApplyLinearImpulseToCenter(impulse, true);
    }

    long getScore() const { return totalScore; }
};
