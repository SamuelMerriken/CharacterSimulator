#include <iostream>
#include <cmath>

class Character {
private:
    double x, y; // position
    double vx, vy; // velocity
    double mass; // mass
    double gravity; // gravity constant

public:
    Character(double x, double y, double mass) {
        this->x = x;
        this->y = y;
        this->mass = mass;
        gravity = 9.8;
    }

    void update(double dt) {
        vy -= gravity * dt; // apply gravity
        x += vx * dt; // update position
        y += vy * dt;
    }

    void setVelocity(double vx, double vy) {
        this->vx = vx;
        this->vy = vy;
    }

    double getX() { return x; }
    double getY() { return y; }
};

int main() {
    Character c(0, 0, 1); // create character at (0, 0) with mass 1
    c.setVelocity(5, 10); // set initial velocity

    for (double t = 0; t <= 10; t += 0.1) {
        c.update(0.1); // update character's position
        std::cout << "Time: " << t << ", x: " << c.getX() << ", y: " << c.getY() << std::endl;
    }

    return 0;
}
