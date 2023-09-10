#include <iostream>
#include <string>
#include <cstdlib>  // for rand()
#include <cmath>

using namespace std;

class Items
{
    public:
    virtual ~Items() {}
    virtual void getDetails() const = 0;
};
class Weapon : public Items
{   
    private:
    string name;
    int dmg,health,spell_power;

    public:
    Weapon();
    Weapon(string name, int dmg, int health, int spell_power) 
    :name(name),dmg(dmg),health(health),spell_power(spell_power){}
    ~Weapon()
    {
        cout<<"<GameSystem> ||| Weapon was deleted"<<endl;
    }
    void getDetails() const override
    {
        cout<<"Item: "<<this->name<<endl;
        cout<<"Bonus damage: "<<this->dmg<<"     Bonus health: "<<this->health<<"     Bonus spell power: "<<this->spell_power<<endl;
    }
    int getWeaponDmg()
    {
        return this->dmg;
    }
    int getWeaponHealth()
    {
        return this->health;
    }
    int getWeaponSpellpower()
    {
        return this->spell_power;
    }
};
class Ring : public Items
{   
    private:

    string name;
    int dmg,health,spell_power;

    public:

    Ring();
    Ring(string name, int dmg, int health, int spell_power) 
    :name(name),dmg(dmg),health(health),spell_power(spell_power){} 
     ~Ring()
    {
        cout<<"<GameSystem> ||| Ring was deleted"<<endl;
    }

      void getDetails() const override
    {
        cout<<"Item: "<<this->name<<endl;
        cout<<"Bonus damage: "<<this->dmg<<"     Bonus health: "<<this->health<<"     Bonus spell power: "<<this->spell_power<<endl;
    }
     int getRingDmg()
    {
        return this->dmg;
    }
    int getRingHealth()
    {
        return this->health;
    }
    int getRingSpellpower()
    {
        return this->spell_power;
    }
};
class Armor : public Items
{   
    private:
    string name;
    int dmg,health,spell_power;
    public:

    Armor();
    Armor(string name, int dmg, int health, int spell_power) 
    :name(name),dmg(dmg),health(health),spell_power(spell_power){}
     ~Armor()
    {
        cout<<"<GameSystem> ||| Armor was deleted"<<endl;
    }

      void getDetails() const override
    {
        cout<<"Item: "<<this->name<<endl;
        cout<<"Bonus damage: "<<this->dmg<<"     Bonus health: "<<this->health<<"     Bonus spell power: "<<this->spell_power<<endl;
    }
     int getArmorDmg()
    {
        return this->dmg;
    }
    int getArmorHealth()
    {
        return this->health;
    }
    int getArmorSpellpower()
    {
        return this->spell_power;
    }
};

class Player
{
    private:
    int health,damage,spell_power,xp,lvl,max_health,monsters_killed;
    string name,type,basic_spell,empowered_spell,ultimate_spell;
    Weapon *player_weapon;
    Ring *player_ring;
    Armor *player_armor;
    public:
    Player(string playerName, string playerType)
    {
        this->name=playerName;
        this->type=playerType;
        this->xp=0;
        this->lvl=1;
        this->monsters_killed=0;
        this->player_weapon = new Weapon("Basic weapon",10,0,0);
        this->player_armor = new Armor("Basic armor",0,10,0);
        this->player_ring = new Ring("Basic ring",0,0,10);
        if(playerType=="Warrior")
        {
            this->max_health = 500;
            this->damage = 100;
            this->spell_power = 10;
            this->basic_spell="Dark hit"; // Increased dmg
            this->empowered_spell="Medidate"; // Heal
            this->ultimate_spell="Sharp edge"; //Huge dmg
        }
        else if(playerType=="Mage")
        {
            this->max_health = 250;
            this->damage = 30;
            this->spell_power = 100;
            this->basic_spell="Channeled hit";  // Increased dmg
            this->empowered_spell="Biggest fear"; // Increased spellpower
            this->ultimate_spell="World's Chakra"; // Huge increased spellPower
        }
        else if(playerType=="Healer")
        {
            this->max_health = 300;
            this->damage = 50;
            this->spell_power = 50;
            this->basic_spell="Wind help"; // Dmeag incrsed 
            this->empowered_spell="Healing spirit"; // Heal 
            this->ultimate_spell="Not today"; // More heal
        }

        this->health = this-> max_health ;
        cout<<"Welcome! The character has been created! Have fun and good luck!"<<endl;                   
    } 
    ~Player()
    {
        cout<<"You died!"<<endl;
        showPlayerStats();
    }
    void showPlayerStats() const
    {
        cout<<"Your stats:"<<endl;
        cout<<"Name: "<<this->name<<"   Class: "<<this->type<<endl;
        cout<<"Level: "<<this->lvl<<endl<<"Health: "<<this->max_health<<"   Damage: "<<this->damage<<"   Spell Power: "<<this->spell_power<<" Monsters killed: "<<this->monsters_killed<<endl;
    }
    void receiveXp(int xpoints)
    {
        if(this->lvl<5)
        {
          this->xp = this->xp + xpoints; 
          cout<<"You received "<<xpoints<<" experience points!"<<endl;
          if((this->xp) >= pow(2,this->lvl)*100)
          {
            cout<<"LEVEL UP! =========>  LEVEL: "<<this->lvl+1<<endl;
            this->lvl = this->lvl + 1;
            if(this->type == "Warrior")
            {
                this->max_health = 500 + 0.3*this->max_health;
                this->damage= 100 + 0.3*this->damage;
                this->spell_power = 10 + 0.5*this->spell_power;
            }
            else if(this->type == "Mage")
            {
                this->max_health = 250 + 0.2*this->max_health;
                this->damage= 30 + 0.5*this->damage;
                this->spell_power = 100 + 0.5*this->spell_power;
            }
            else if(this->type == "Healer")
            {
                this->max_health = 300 + 0.2*this->max_health;
                this->damage= 50 + 0.3*this->damage;
                this->spell_power = 50 + 0.5*this->spell_power;   
            }

            this->health = this->max_health;
            this->xp = 0;

          }
           cout<<"Total xp: "<<this->xp<<" / "<<pow(2,this->lvl)*100<<endl;
        }
        else
            cout<<"You reached the biggest level!"<<endl; 
        
    } 
    int getPlayerMaxHealth() const
    {
        return this->max_health;
    }
    int getPlayerDmg() const
    {
        return this->damage;
    }
    void setPlayerDamage(int newValue)
    {
        this->damage = newValue;
    }
    int getPlayerHealth() const
    {
        return this->health;
    }
    void setPlayerHealth(int newValue) 
    {
        this->health = newValue;
    }
    int getPlayerSpellpower() const
    {
        return this->spell_power;
    }
    void setPlayerSpellpower(int newValue)
    {
        this->spell_power = newValue;
    } 
    int getPlayerLevel() const
    {
        return this->lvl;
    }
    Weapon* getPlayerWeapon() const
    {
        return this->player_weapon;
    }
     Ring* getPlayerRing() const
    {
        return this->player_ring;
    }
     Armor* getPlayerArmor() const
    {
        return this->player_armor;
    }
    void equipWeapon(Weapon* weaponAdress)
    {
        this->player_weapon = weaponAdress;
        this->health =this->health + this->player_weapon->getWeaponHealth();
        this->damage = this->damage + this->player_weapon->getWeaponDmg();
        this->spell_power = this->spell_power + this->player_weapon->getWeaponSpellpower();
        cout << "New weapon equipped!" << endl;
    }
    void equipRing(Ring* ringAddress)
    {
        this->player_ring = ringAddress;
        this->health =this->health + this->player_ring->getRingHealth();
        this->damage = this->damage + this->player_ring->getRingDmg();
        this->spell_power = this->spell_power + this->player_ring->getRingSpellpower();
        cout << "New ring equipped!" << endl; 
    }
    void equipArmor(Armor* armorAdress)
    {
        this->player_armor = armorAdress;
        this->health =this->health + this->player_armor->getArmorHealth();
        this->damage = this->damage + this->player_armor->getArmorDmg();
        this->spell_power = this->spell_power + this->player_armor->getArmorSpellpower();
        cout << "New armor equipped!" << endl;
    }
    void increasePlayerMonstersKilled()
    {
        this->monsters_killed++;
    }
    string getType() const
    {
        return this->type;
    }
    string getBasicSpell() const
    {
        return this->basic_spell;
    }
    string getEmpoweredSpell() const
    {
        return this->empowered_spell;
    }
    string getUltimateSpell() const
    {
        return this->ultimate_spell;
    }
    void die()
    {
        delete this;
    }
};

class MonstersPrototype 
{
    private:
    public:
    virtual ~MonstersPrototype(){cout<<"<GameSystem> MonsterPrototype object deleted!"<<endl;}
    virtual MonstersPrototype* clone() const = 0;
    virtual string getMonsterName() const = 0;
    virtual int getMonsterHealth() const = 0;
    virtual void setMonsterHealth(int)  = 0;
    virtual int getMonsterDmg() const = 0;
    virtual void setMonsterDmg(int)  = 0;
    virtual Weapon* getMonsterWeapon() const = 0;
    virtual Ring* getMonsterRing() const = 0;
    virtual Armor* getMonsterArmor() const = 0;
    virtual void setMonsterWeapon(Weapon*) = 0;
    virtual void setMonsterRing(Ring*) = 0;
    virtual void setMonsterArmor(Armor*) = 0;
};
class MonstersLvl1 : public MonstersPrototype
{
    private:
    string name;
    int health,dmg;
    Weapon * loot_weapon;
    Armor * loot_armor;
    Ring * loot_ring;
    public:

    MonstersLvl1() 
    :name("Wild pig"),health(250),dmg(10),loot_weapon(new Weapon("Stick",25,10,5)),loot_armor(new Armor("WoodArmor",5,50,5)),loot_ring(new Ring("IronRing",5,5,35)){}

    MonstersLvl1(const MonstersLvl1& other)
    :name(other.name),health(other.health),dmg(other.dmg),loot_weapon(new Weapon("Stick",25,10,5)),loot_armor(new Armor("WoodArmor",5,50,5)),loot_ring(new Ring("IronRing",5,5,35)){}

    ~MonstersLvl1()
    {
        cout<<"<GameSystem> MonstersLvl1 object deleted"<<endl;
            delete this->loot_weapon;
            delete this->loot_armor;
            delete this->loot_ring;
    }

    string getMonsterName() const override
    {
        return this->name;
    }
    int getMonsterHealth() const override
    {
        return this-> health;
    }
    void setMonsterHealth(int newValue) override
    {
        this->health = newValue;
    }
    int getMonsterDmg() const override
    {
        return this-> dmg;
    }
    void setMonsterDmg(int newValue) override
    {
        this->dmg = newValue;
    }
    Weapon* getMonsterWeapon() const override
    {
        return this->loot_weapon;
    }
    Ring* getMonsterRing() const override
    {
        return this->loot_ring;
    }
    Armor* getMonsterArmor() const override
    {
        return this->loot_armor;
    }
    void setMonsterWeapon(Weapon* newWeapon) override
    {
        this->loot_weapon = newWeapon;
    }
    void setMonsterRing(Ring* newRing) override
    {
        this->loot_ring = newRing;
    }
    void setMonsterArmor(Armor* newArmor) override
    {
        this->loot_armor = newArmor;
    }
    MonstersPrototype* clone() const override
    {
        return new MonstersLvl1(*this);
    }
};
class MonstersLvl2 : public MonstersPrototype
{
    private:
    string name;
    int health,dmg;
    Weapon * loot_weapon;
    Armor * loot_armor;
    Ring * loot_ring;
    
    public:

    MonstersLvl2() 
    :name("Angry bear"),health(500),dmg(45),loot_weapon(new Weapon("Claw",50,30,10)),loot_armor(new Armor("Bear fur",15,150,5)),loot_ring(new Ring("GoldRing",15,30,60)){}

    MonstersLvl2(const MonstersLvl2& other)
    :name(other.name),health(other.health),dmg(other.dmg),loot_weapon(new Weapon("Claw",50,30,10)),loot_armor(new Armor("Bear fur",15,150,5)),loot_ring(new Ring("GoldRing",15,30,60)){}

    ~MonstersLvl2()
    {
        cout<<"<GameSystem> MonstersLvl2 object deleted"<<endl;
            delete this->loot_weapon;
            delete this->loot_armor;
            delete this->loot_ring;
    }

    string getMonsterName() const override
    {
        return this->name;
    }
    int getMonsterHealth() const override
    {
        return this-> health;
    }
    void setMonsterHealth(int newValue) override
    {
        this->health = newValue;
    }
    int getMonsterDmg() const override
    {
        return this-> dmg;
    }
    void setMonsterDmg(int newValue) override
    {
        this->dmg = newValue;
    }
    Weapon* getMonsterWeapon() const override
    {
        return this->loot_weapon;
    }
    Ring* getMonsterRing() const override
    {
        return this->loot_ring;
    }
    Armor* getMonsterArmor() const override
    {
        return this->loot_armor;
    }
    void setMonsterWeapon(Weapon* newWeapon) override
    {
        this->loot_weapon = newWeapon;
    }
    void setMonsterRing(Ring* newRing) override
    {
        this->loot_ring = newRing;
    }
    void setMonsterArmor(Armor* newArmor) override
    {
        this->loot_armor = newArmor;
    }
    MonstersPrototype* clone() const override
    {
        return new MonstersLvl2(*this);
    }
};
class MonstersLvl3 : public MonstersPrototype
{
    private:
    string name;
    int health,dmg;
    Weapon * loot_weapon;
    Armor * loot_armor;
    Ring * loot_ring;
    public:

    MonstersLvl3() 
    :name("Fire dragon"),health(5000),dmg(500),loot_weapon(new Weapon("Dragon tooth",130,66,50)),loot_armor(new Armor("Fire protection",90,5000,40)),loot_ring(new Ring("ScaleRing",30,100,9999)){}

    MonstersLvl3(const MonstersLvl3& other)
    :name(other.name),health(other.health),dmg(other.dmg),loot_weapon(new Weapon("Dragon tooth",130,66,50)),loot_armor(new Armor("Fire protection",90,5000,40)),loot_ring(new Ring("ScaleRing",30,100,9999)){}

    ~MonstersLvl3()
    {
        cout<<"<GameSystem> MonstersLvl3 object deleted"<<endl;
            delete this->loot_weapon;
            delete this->loot_armor;
            delete this->loot_ring;
    }

    string getMonsterName() const override
    {
        return this->name;
    }
    int getMonsterHealth() const override
    {
        return this-> health;
    }
    void setMonsterHealth(int newValue) override
    {
        this->health = newValue;
    }
    int getMonsterDmg() const override
    {
        return this-> dmg;
    }
    void setMonsterDmg(int newValue) override
    {
        this->dmg = newValue;
    }
    Weapon* getMonsterWeapon() const override
    {
        return this->loot_weapon;
    }
    Ring* getMonsterRing() const override
    {
        return this->loot_ring;
    }
    Armor* getMonsterArmor() const override
    {
        return this->loot_armor;
    }
    void setMonsterWeapon(Weapon* newWeapon) override
    {
        this->loot_weapon = newWeapon;
    }
    void setMonsterRing(Ring* newRing) override
    {
        this->loot_ring = newRing;
    }
    void setMonsterArmor(Armor* newArmor) override
    {
        this->loot_armor = newArmor;
    }
    MonstersPrototype* clone() const override
    {
        return new MonstersLvl3(*this);
    }
};


class Weather 
{
    private:

    string weatherStatus;
    static Weather* instance;
    Weather(){}

    public:

    Weather(const Weather& obj) = delete; //deleting copy constructor

    static Weather* getWeather()
    {
        if(instance == nullptr)
        instance = new Weather();

        return instance;
    }

    void setWeather(string value)
    {
    this->weatherStatus=value;
    cout<<"<GameSystem> The weather was changed to "<<value<<endl;
    }

    string getWeatherStatus()
    {
        return this->weatherStatus;
    }
};
    Weather* Weather::instance = NULL;

class GameSystem 
{
    private:
    static GameSystem* instance;
    MonstersPrototype *monster_Lvl1;
    MonstersPrototype *monster_Lvl2;
    MonstersPrototype *monster_Lvl3;
    GameSystem()
    {
        monster_Lvl1 = new MonstersLvl1();
        monster_Lvl2 = new MonstersLvl2();
        monster_Lvl3 = new MonstersLvl3();
    }
    public:
    static GameSystem* getGameSystem()
    {
        if(instance == nullptr)
        instance = new GameSystem();

        return instance;
    }
    MonstersPrototype* getMonsterClone(int monster_lvl)
    {
        if(monster_lvl == 1)
        return monster_Lvl1->clone();
        else if(monster_lvl == 2)
        return monster_Lvl2->clone();
        else if(monster_lvl == 3)
        return monster_Lvl3->clone();
        else
        {
            cout<<"WRONG MONSTER LVL!";
            return nullptr;
        }
        
    }
    void randWeather()
    {
        if(rand()%10 < 7)
        Weather::getWeather()->setWeather("Sunny");
        else
        Weather::getWeather()->setWeather("Storm");
    }

};
    GameSystem* GameSystem::instance = NULL;

int main()
{
    string insertedVar;
    string insertedName,insertedType="default";

    cout<<"=====================Create new player====================="<<endl; 
    cout<<"Insert name:";
    cin>>insertedName;
    cout<<"==========================================================="<<endl;

    while(insertedType != "Warrior" && insertedType != "Mage" && insertedType != "Healer")
    {
        if(insertedType != "default")
        cout<<"<  WRONG TYPE NAME!  >"<<endl;
        cout<<"Choose the class:"<<endl<<"Warrior   Mage   Healer"<<endl;
        cout<<"Insert class: ";
        cin>>insertedType;
        cout<<"==========================================================="<<endl;
    }

    Player* thePlayer = new Player(insertedName,insertedType);
    
    while(1)
    {
        cout<<"Press x to continue"<<endl;
        cin>>insertedVar;
        if(insertedVar == "x")
        {
            system("cls");
            break;
        }
    }

    while(1)
    {
        system("cls");
        cout<<"========== MENU =========="<<endl;
        cout<<"1. Player stats"<<endl;
        cout<<"2. Show your items"<<endl;
        cout<<"3. Abilities and details"<<endl;
        cout<<"4. Join a fight"<<endl;
        cout<<"5. Take the easy way out!"<<endl;

        cout<<"Insert your option: "<<endl;
        cin>>insertedVar;

        if(insertedVar == "1")
        {
            system("cls");
            thePlayer->showPlayerStats();
            do
            {
                cout<<"Enter x to continue"<<endl;
                cin>>insertedVar;
            } while (insertedVar != "x");
        }
        else if(insertedVar == "2")
        {
            system("cls");
            cout<<"Your items are:"<<endl;
            thePlayer->getPlayerWeapon()->getDetails();
            thePlayer->getPlayerArmor()->getDetails();
            thePlayer->getPlayerRing()->getDetails();
            do
            {
                cout<<"Enter x to continue"<<endl;
                cin>>insertedVar;
            } while (insertedVar != "x");
        }
        else if(insertedVar == "3")
        {
            system("cls");
            if(thePlayer->getType() == "Warrior")
            {
                
                cout<<"The Warrior class"<<endl<<endl;
                cout<<"Abilities:"<<endl;
                cout<<"Basic spell ---------- Dark hit : Deal increased damage to enemy"<<endl;
                cout<<"Ability damage: "<<thePlayer->getPlayerDmg()+15<<endl<<endl; 
                cout<<"Empowered spell ---------- Meditate : The warrior can heal his minor wounds"<<endl;
                cout<<"Ability heal: "<<thePlayer->getPlayerLevel()*50<<endl<<endl; 
                cout<<"Ultimate spell ---------- Sharp edge : Deal huge damage to enemy"<<endl;
                cout<<"Ability damage: "<<thePlayer->getPlayerDmg()+100<<endl<<endl; 
            }
            else if(thePlayer->getType() == "Mage")
            {
                
                cout<<"The Mage class"<<endl<<endl;
                cout<<"Abilities:"<<endl;
                cout<<"Basic spell ---------- Channeled hit : Deal increased damage to enemy"<<endl;
                cout<<"Ability damage: "<<thePlayer->getPlayerDmg()+thePlayer->getPlayerSpellpower()+5<<endl<<endl; 
                cout<<"Empowered spell ---------- Biggest fear : Increased spellpower"<<endl;
                cout<<"Ability damage: "<<thePlayer->getPlayerDmg()+thePlayer->getPlayerSpellpower()+15<<endl<<endl; 
                cout<<"Ultimate spell ---------- World's Chakra : Huge increased spellpower"<<endl;
                cout<<"Ability damage: "<<thePlayer->getPlayerDmg()+thePlayer->getPlayerSpellpower()+35<<endl<<endl;
            }
            else if(thePlayer->getType() == "Healer")
            {
            
                cout<<"The Healer class"<<endl<<endl;
                cout<<"Abilities:"<<endl;
                cout<<"Basic spell ---------- Wind help : Deal increased damage to enemy"<<endl;
                cout<<"Ability damage: "<<thePlayer->getPlayerDmg()+10<<endl<<endl; 
                cout<<"Empowered spell ---------- Healing spirit : A healing spirit is spawned"<<endl;
                cout<<"Ability heal: "<<thePlayer->getPlayerLevel()*100<<endl<<endl; 
                cout<<"Ultimate spell ---------- Not today : Huge heal"<<endl;
                cout<<"Ability heal: "<<thePlayer->getPlayerSpellpower()+500<<endl<<endl; 
            }
            do
            {
                cout<<"Enter x to continue"<<endl;
                cin>>insertedVar;
            } while (insertedVar != "x");
        }
        else if(insertedVar == "4")
        {
            system("cls");
            MonstersPrototype *monster;
            cout<<"What monster do you want to fight?"<<endl<<"Insert the monster lvl (1-3): "<<endl;
            int mob_lvl=0;
            do
            {
                cout<<"Monster lvl:";
                cin>>mob_lvl;
            } while (mob_lvl<1 || mob_lvl>3);
            system("cls");
            monster = GameSystem::getGameSystem()->getMonsterClone(mob_lvl);
            cout<<"You will fight "<<monster->getMonsterName()<<endl;
            cout<<"Monster damage: "<<monster->getMonsterDmg()<<"   Monster health: "<<monster->getMonsterHealth()<<endl;
            GameSystem::getGameSystem()->randWeather();
            if(Weather::getWeather()->getWeatherStatus() == "Sunny")
                cout<<"It's sunny outside!"<<endl;
            else if(Weather::getWeather()->getWeatherStatus() == "Storm")
            {
                cout<<"A storm is coming! Monsters deal more damage!"<<endl;
                cout<<"<GameSystem> Monster damage increased from "<<monster->getMonsterDmg()<<" to "<<monster->getMonsterDmg() + (monster->getMonsterDmg()*10)/100<<endl;
                monster->setMonsterDmg(monster->getMonsterDmg() + (monster->getMonsterDmg()*10)/100); 
            }

            bool battleStatus = true ;
            
            while(battleStatus == true)
            {
                cout<<endl;
                cout<<"Attack the enemy! What spell do you want to use?"<<endl;
                cout<<"1. "<<thePlayer->getBasicSpell()<<endl;
                cout<<"2. "<<thePlayer->getEmpoweredSpell()<<endl;
                cout<<"3. "<<thePlayer->getUltimateSpell()<<endl;

                cin>>insertedVar;

                if(insertedVar == "1")
                {
                    if(thePlayer->getType() == "Warrior")
                    {
                        monster->setMonsterHealth(monster->getMonsterHealth()-(thePlayer->getPlayerDmg()+15));
                        cout<<"You dealt "<<thePlayer->getPlayerDmg()+15<<" damage!"<<endl;
                    }
                    else if(thePlayer->getType() == "Mage")
                    {
                        monster->setMonsterHealth(monster->getMonsterHealth()-(thePlayer->getPlayerDmg()+thePlayer->getPlayerSpellpower()+5));
                        cout<<"You dealt "<<thePlayer->getPlayerDmg()+thePlayer->getPlayerSpellpower()+5<<" damage!"<<endl;
                    }
                    else if(thePlayer->getType() == "Healer")
                    {
                        monster->setMonsterHealth(monster->getMonsterHealth()-(thePlayer->getPlayerDmg()+10));
                        cout<<"You dealt "<<thePlayer->getPlayerDmg()+10<<" damage!"<<endl;
                    }
                    
                }
                else if(insertedVar == "2")
                {
                    if(thePlayer->getType() == "Warrior")
                    {
                        if(thePlayer->getPlayerHealth() + thePlayer->getPlayerLevel()*50 > thePlayer->getPlayerMaxHealth())
                        {
                            thePlayer->setPlayerHealth(thePlayer->getPlayerMaxHealth());
                            cout<<"You are healed at 100%"<<endl;
                        }
                        else
                        {
                            thePlayer->setPlayerHealth(thePlayer->getPlayerHealth() + thePlayer->getPlayerLevel()*50);
                            cout<<"Heal receive "<<thePlayer->getPlayerLevel()*50<<" hp!"<<endl;
                        }
                    }
                    else if(thePlayer->getType() == "Mage")
                    {
                        monster->setMonsterHealth(monster->getMonsterHealth()-(thePlayer->getPlayerDmg()+thePlayer->getPlayerSpellpower()+15));
                        cout<<"You dealt "<<thePlayer->getPlayerDmg()+thePlayer->getPlayerSpellpower()+15<<" damage!"<<endl;
                    }
                    else if(thePlayer->getType() == "Healer")
                    {
                        if(thePlayer->getPlayerHealth() + thePlayer->getPlayerLevel()*100 > thePlayer->getPlayerMaxHealth())
                        {
                            thePlayer->setPlayerHealth(thePlayer->getPlayerMaxHealth());
                            cout<<"You are healed at 100%"<<endl;
                        }
                        else
                        {
                            thePlayer->setPlayerHealth(thePlayer->getPlayerHealth() + thePlayer->getPlayerLevel()*100);
                            cout<<"Heal receive "<<thePlayer->getPlayerLevel()*100<<" hp!"<<endl;
                        }
                    }
                    
                }
                else if(insertedVar == "3")
                {
                    if(thePlayer->getType() == "Warrior")
                    {
                        monster->setMonsterHealth(monster->getMonsterHealth()-(thePlayer->getPlayerDmg()+100));
                        cout<<"You dealt "<<thePlayer->getPlayerDmg()+100<<" damage!"<<endl;
                    }
                    else if(thePlayer->getType() == "Mage")
                    {
                        monster->setMonsterHealth(monster->getMonsterHealth()-(thePlayer->getPlayerDmg()+thePlayer->getPlayerSpellpower()+35));
                        cout<<"You dealt "<<thePlayer->getPlayerDmg()+thePlayer->getPlayerSpellpower()+35<<" damage!"<<endl;
                    }
                    else if(thePlayer->getType() == "Healer")
                    {
                        if(thePlayer->getPlayerHealth()+ thePlayer->getPlayerSpellpower()+500 > thePlayer->getPlayerMaxHealth())
                        {
                            thePlayer->setPlayerHealth(thePlayer->getPlayerMaxHealth());
                            cout<<"You are healed at 100%"<<endl;
                        }
                        else
                        {
                            thePlayer->setPlayerHealth(thePlayer->getPlayerHealth() + thePlayer->getPlayerSpellpower()+500);
                            cout<<"Heal receive "<<thePlayer->getPlayerSpellpower()+500<<" hp!"<<endl;
                        }
                    }
                }
                else
                {
                    cout<<"WRONG MOVE!"<<endl;
                    continue;
                }

                if(monster->getMonsterHealth()<=0)
                {
                    cout<<endl;
                    cout<<"YOU WON!"<<endl;
                    battleStatus = false;
                    thePlayer->increasePlayerMonstersKilled();
                    thePlayer->setPlayerHealth(thePlayer->getPlayerMaxHealth());
                    thePlayer->receiveXp(250*mob_lvl);
                    int ran = rand()%10;
                    if(ran == 0)
                    {
                        cout<<endl;
                        cout<<"The monster dropped an item!"<<endl;
                        monster->getMonsterWeapon()->getDetails();
                        cout<<endl;
                        cout<<"Your's is: "<<endl;
                        thePlayer->getPlayerWeapon()->getDetails();
                        cout<<endl;
                        cout<<"Do you want to switch the items?"<<endl;
                        cout<<"Yes       No"<<endl;
                        cin>>insertedVar;
                        if(insertedVar == "Yes")
                        {
                            Weapon* old = thePlayer->getPlayerWeapon();
                            thePlayer->equipWeapon(monster->getMonsterWeapon());
                            monster->setMonsterWeapon(old);
                            cout<<"The new weapon was equipped!"<<endl;
                        }
                        else
                        cout<<"You keep your current weapon!"<<endl;
                    }
                    else if(ran == 1)
                    {
                        cout<<endl;
                        cout<<"The monster dropped an item!"<<endl;
                        monster->getMonsterArmor()->getDetails();
                        cout<<"Your's is: ";
                        thePlayer->getPlayerArmor()->getDetails();
                        cout<<"Do you want to switch the items?"<<endl;
                        cout<<"Yes       No"<<endl;
                        cin>>insertedVar;
                        if(insertedVar == "Yes")
                        {
                            Armor *old = thePlayer->getPlayerArmor();
                            thePlayer->equipArmor(monster->getMonsterArmor());
                            monster->setMonsterArmor(old);
                            cout<<"The new armor was equipped!"<<endl;
                        }
                        else
                        cout<<"You keep your current armor!"<<endl;
                    }
                    else if(ran == 2)
                    {
                        cout<<endl;
                        cout<<"The monster dropped an item!"<<endl;
                        monster->getMonsterRing()->getDetails();
                        cout<<"Your's is: ";
                        thePlayer->getPlayerRing()->getDetails();
                        cout<<"Do you want to switch the items?"<<endl;
                        cout<<"Yes       No"<<endl;
                        cin>>insertedVar;
                        if(insertedVar == "Yes")
                        {
                            Ring* old = thePlayer->getPlayerRing();
                            thePlayer->equipRing(monster->getMonsterRing());
                            monster->setMonsterRing(old);
                            cout<<"The new ring was equipped!"<<endl;
                        }
                        else
                        cout<<"You keep your current ring!"<<endl;
                    }
                    else
                    {
                        cout<<endl<<"No item was dropped!"<<endl;
                        do
                        {
                            cout<<"Enter x to continue"<<endl;
                            cin>>insertedVar;
                        } while (insertedVar != "x");
                    }
                        
                    delete monster;
                }
                else
                {
                    cout<<"Monster health: "<<monster->getMonsterHealth()<<endl;
                    cout<<endl;
                    cout<<"It's monster turn!"<<endl;
                    thePlayer->setPlayerHealth(thePlayer->getPlayerHealth() - monster->getMonsterDmg());
                    if(thePlayer->getPlayerHealth() > 0)
                        cout<<"Monster damage done: "<<monster->getMonsterDmg()<<" ,your current health: "<<thePlayer->getPlayerHealth()<<"/"<<thePlayer->getPlayerMaxHealth()<<endl;
                    else
                    {
                        cout<<"Monster damage done: "<<monster->getMonsterDmg()<<" ,your health had reach 0!"<<endl;
                        thePlayer->die();
                        battleStatus = false;
                        return 0;
                    }
                }
            }



        }
        else if(insertedVar == "5")
        {
            system("cls");
            cout<<"Danger! Are you sure you want to escape this world?"<<endl;
            cout<<"1. Yes, get me out of there"<<endl;
            cout<<"2. No, I will fight till the end!"<<endl;
            cin>>insertedVar;

            if(insertedVar == "1")
            {
                system("cls");
                thePlayer->die();
                return 0;
            }
            
        }
    }
}