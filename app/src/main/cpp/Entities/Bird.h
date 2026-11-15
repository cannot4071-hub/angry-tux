#ifndef BIRD_H
#define BIRD_H

#include <box2d/box2d.h>

enum MascotType {
    TUX_LINUX,
    PUFFY_OPENBSD,
    BEASTIE_FREEBSD
};

class Bird {
protected:
    b2Body* body;
    MascotType type;
    bool abilityUsed;

public:
    Bird(b2Wrold* world, b2Vec2 pos, MascotType t) : type(t), abilityUsed(false) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position = pos;
        body = world->CreateBody(&bodyDef);

        b2CircleShape shape;
        shape.m_radius = 0.5f;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = 2.0f;
        fixtureDef.friction = 0.2f;
        fixtureDef.restitution = 0.4f; // Bounciness
        body->CreateFixture(&fixtureDef);
    }

    virtual ~Bird() {}

    MascotType getType() const { return type; }
    b2Body* getBody() const { return body; }

    // Virtual ability triggered when player taps screen mid-flight
    virtual void activateAbility() = 0;
};

// 1. Tux: Standard heavy aerodynamic dive (No special mid-air trigger, just pure mass)
class TuxBird : public Bird {
public:
    TuxBird(b2World* world, b2Vec2 pos) : Bird(world, pos, TUX_LINUX) {}
    void activateAbility() override {
        // Tux drops straight down with kernel panic speed
        if (!abilityUsed) {
            b2Vec2 vel = body->GetLinearVelocity();
            body->SetLinearVelocity(b2Vec2(vel.x * 0.5f, -15.0f));
            abilityUsed = true;
        }
    }
};

// 2. OpenBSD Bird (Puffy): Inflates like a blowfish, multiplying mass and crush radius
class PuffyOpenBSDBird : public Bird {
public:
    PuffyOpenBSDBird(b2World* world, b2Vec2 pos) : Bird(world, pos, PUFFY_OPENBSD) {}
    void activateAbility() override {
        if (!abilityUsed && body) {
            // Expand fixture radius securely for maximum destruction area
            b2Fixture* fixture = body->GetFixtureList();
            if (fixture) {
                b2Shape* shape = fixture->GetShape();
                if (shape->GetType() == b2Shape::e_circle) {
                    static_cast<b2CircleShape*>(shape)->m_radius = 1.2f; // Inflate!
                }
            }
            body->SetMassFromShapes(); // Update weight dynamically
            abilityUsed = true;
        }
    }
};

// 3. FreeBSD Bird (Beastie): Splits into a trident of 3 daemon vectors
class BeastieFreeBSDBird : public Bird {
public:
    BeastieFreeBSDBird(b2World* world, b2Vec2 pos) : Bird(world, pos, BEASTIE_FREEBSD) {}
    void activateAbility() override {
        if (!abilityUsed) {
            b2Vec2 currentVel = body->GetLinearVelocity();
            b2Vec2 pos = body->GetPosition();
            
            // Note: In a complete engine implementation, you would spawn 2 extra body instances 
            // angling upwards and downwards to simulate the FreeBSD trident fork split.
            body->SetLinearVelocity(b2Vec2(currentVel.x * 1.5f, currentVel.y)); // Speed boost
            abilityUsed = true;
        }
    }
};

#endif
