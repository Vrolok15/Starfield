#pragma once

class Star
{
public:
    Star();
    void Init();
    void Update();
    void Draw() const;

private:
    int x;
    int y;
    int z;
    int speed;
    int radius;
};