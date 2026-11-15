#include "GameManager.h"

GameManager::GameManager() {
    b2Vec2 gravity(0.0f, -9.81f);
    world = new b2World(gravity);
    slingshotAnchor = b2Vec2(-5.0f, -2.0f);
    totalScore = 0;
}

GameManager::~GameManager() {
    delete world;
}

void GameManager::updatePhysics(float timeStep) {
    int velocityIterations = 6;
    int positionIterations = 2;
    world->Step(timeStep, velocityIterations, positionIterations);
}

void GameManager::launchActiveBird(Bird* bird, b2Vec2 touchDragDelta) {
    b2Body* body = bird->getBody();
    body->SetType(b2_dynamicBody);
    
    float powerScale = 14.0f;
    b2Vec2 impulse(-touchDragDelta.x * powerScale, -touchDragDelta.y * powerScale);
    body->ApplyLinearImpulseToCenter(impulse, true);
}

long GameManager::getScore() const {
    return totalScore;
}
