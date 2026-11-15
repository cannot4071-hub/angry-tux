#ifndef STRUCTURE_BLOCK_H
#define STRUCTURE_BLOCK_H

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
    StructureBlock(b2World* world, b2Vec2 position, BlockMaterial mat);
    void takeDamage(int amount);
    bool isDestroyed() const;
    int getScore() const;
};

#endif
