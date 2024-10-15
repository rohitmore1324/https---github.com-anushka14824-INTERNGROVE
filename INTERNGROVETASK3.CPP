#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GameObject {
   public:
    string name;
    float x, y;                  
    float velocityX, velocityY;  

    GameObject(string n, float posX, float posY)
        : name(n), x(posX), y(posY), velocityX(0), velocityY(0) {}

    void update() {
       
        x += velocityX;
        y += velocityY;
    }

    void printPosition() const {
        cout << name << " Position: (" << x << ", " << y << ")" << endl;
    }
};

class GameEngine {
   private:
    vector<GameObject> objects;

   public:
    void addObject(const GameObject& obj) {
        objects.push_back(obj);
    }

    void update() {
        for (auto& obj : objects) {
            obj.update();
        }
    }

    void render() {
        for (const auto& obj : objects) {
            obj.printPosition();
        }
    }
};

int main() {
    GameEngine engine;

    
    GameObject player("Player", 0, 0);
    player.velocityX = 1.0;  

    GameObject enemy("Enemy", 5, 5);
    enemy.velocityY = -0.5;  

    // Add objects to the engine
    engine.addObject(player);
    engine.addObject(enemy);

    // Game loop (simplified)
    for (int i = 0; i < 10; ++i) {
        engine.update();
        engine.render();
        cout << "------" << endl;
    }

    return 0;
}
