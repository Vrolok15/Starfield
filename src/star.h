#pragma once

class Star
{
public:
    Star();
    void Update();
    void Draw() const;

private:
    float x;
    float y;
    float speed;
    float radius;
};