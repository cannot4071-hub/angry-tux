#include <box2d/box2d.h>

enum BlockMaterial {
    PANE_GLASS,
    BEAM_WOOD,
    BSOD_ORB_TARGET
};

class StructureBlock {
private:
    b2Body* body;
    BlockMaterial material;
    int health;
    int scoreValue;

public:
    StructureBlock(b2World* world, b2Vec2 position, BlockMaterial mat) {
        material = mat;

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position = position;
        body = world->CreateBody(&bodyDef);

        b2PolygonShape boxShape;
        b2CircleShape circleShape;
        b2FixtureDef fixtureDef;

        if (material == PANE_GLASS) {
            boxShape.SetAsBox(0.15f, 1.2f);
            fixtureDef.shape = &boxShape;
            fixtureDef.density = 0.5f;
            health = 15;
            scoreValue = 500;
        } else if (material == BEAM_WOOD) {
            boxShape.SetAsBox(0.3f, 1.8f);
            fixtureDef.shape = &boxShape;
            fixtureDef.density = 1.2f;
            health = 40;
            scoreValue = 1200;
        } else {
            circleShape.m_radius = 0.5f;
            fixtureDef.shape = &circleShape;
            fixtureDef.density = 2.0f;
            health = 75;
            scoreValue = 5000; // Defeating the BSOD orb yields massive points!
        }

        fixtureDef.friction = 0.4f;
        body->CreateFixture(&fixtureDef);
    }

    void takeDamage(int amount) {
        health -= amount;
    }

    bool isDestroyed() const {
        return health <= 0;
    }

    int getScore() const {
        return isDestroyed() ? scoreValue : 0;
    }
};
