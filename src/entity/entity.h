#ifndef ENTITY_H
#define ENTITY_H

#include "../math/vector2D.h"

class Entity {

    public:
        Entity(float x, float y);

        virtual void update() = 0;
        virtual void render(float delta) = 0;

        void setPos(Vector2D& v);
        void setPos(float[] v);
        void setPos(float x, float y);

        Vector2D getPos();
        
    protected:
        Vector2D pos;
        Vector2D vel;
        Vector2D acl;
};

#endif