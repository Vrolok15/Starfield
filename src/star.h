#pragma once
#include <raylib.h>

class Star
{
public:
    Star();
    void Init();
    void Update();
    void Draw() const;

private:
    Vector3 position;
    Vector3 prevPos;
    int speed;
    int radius;
};