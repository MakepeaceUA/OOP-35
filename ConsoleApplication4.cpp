#include <iostream>
#include <string>
using namespace std;

class Boss 
{
private:
    static Boss* s;
    string BossName;
    int health;
    int armor;
    int damage;

    Boss(string name,int hp,int ar,int dam) 
    {
        BossName = name;
        health = hp;
        armor = ar;
        damage = dam;
    }
    ~Boss()
    {
        cout << BossName << " has been defeted.\n";
    }
public:

    static Boss* getReference() 
    {
        return s;
    }
    void Move() 
    {
        cout << BossName << " move.\n";
    }
    void Attack() 
    {
        cout << BossName << " attacks and deals "<< damage <<" damage.\n";
    }
    void Defence() 
    {
        cout << BossName << " defending himself.\n";
    }

    void TakeDamage(int dam) 
    {
        health -= dam;
        cout << BossName << " takes " << dam << " damage, " << health << " HP remaining.\n";
        if (health <= 0) 
        {
            delete s; 
            s = nullptr; 
        }
    }
};

Boss* Boss::s = new Boss("Boss", 1000, 100, 200);
int main() 
{

    Boss* p = Boss::getReference();
    p->Move();
    p->Attack();
    p->Defence();
    p->TakeDamage(1000);
}


