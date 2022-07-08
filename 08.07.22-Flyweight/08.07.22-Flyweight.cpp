#include <iostream>
#include <ctime>

class Common;
class Factory;

class Bullet
{
    friend Factory;
private:
    float xPosition;
    float yPosition;
    Common* common = nullptr;
public:
    ~Bullet()
    {
        delete common;
    }
};

class Common
{
    friend Factory;
private:
    std::string pathTexture;
    std::string color;
    float height;
    float width;
    float weight;
    int poligonCount;
    int damage;
    int density;
};

class Factory
{
private:
    Common* common = nullptr;
public:
    Factory(std::string pathTexture, std::string color, float height, float width, int poligonCount, int damage, int density)
    {
        common = new Common;
        common->pathTexture = pathTexture;
        common->color = color;
        common->height = height;
        common->width = width;
        common->poligonCount = poligonCount;
        common->damage = damage;
        common->density = density;
    }
    Bullet& create (float xPosition, float yPosition)
    {
        Bullet* bul = new Bullet;
        bul->xPosition = xPosition;
        bul->yPosition = yPosition;
        bul->common = this->common;
        return *bul;
    }
};

int main()
{
    //srand(time(NULL));
    //Bullet* bullet = new Bullet[1000000];
    //for (int i = 0; i < 1000000; i++)
    //{
    //    Bullet buf;
    //    buf.pathTexture = "Desktop//texture.png";
    //    buf.color = "red";
    //    buf.xPosition = 1 + rand() % 99;
    //    buf.yPosition = 1 + rand() % 99;
    //    buf.height = 25.f;
    //    buf.width = 25.f;
    //    buf.weight = 10.5f;
    //    buf.poligonCount = 200;
    //    buf.damage = 10;
    //    buf.density = 9;
    //    bullet[i] = buf;
    //}
    ////std::cout << float((sizeof(obj[0])*1000000)/1048576);
    //std::cout << sizeof(bullet);

    Factory bul1("123", "123", 123, 123, 123, 123, 123);
    Bullet* bullet = new Bullet[1000000];
    for (int i = 0; i < 1000000; i++)
    {
        bullet[i] = bul1.create(5, 2);
    }
    std::cout << sizeof(bullet[0])*1000000 / 1024 / 1024;
}