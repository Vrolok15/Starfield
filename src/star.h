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
    int speed;
    int radius;
};