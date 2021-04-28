#pragma once

#include <ostream>
#include <string>

class HP {
private:
	int m_value;
public:
	explicit HP(int value);
	std::string getHP() const;
};

class GameObj {
friend std::ostream& operator<< (std::ostream& os, const GameObj& gameObj);
protected:
	std::string m_id;
public:
	explicit GameObj(std::string id = "");
	virtual ~GameObj() = default;
	virtual std::string to_string() const = 0;
	virtual std::string id() const final;
};

class Character : virtual public GameObj {
protected:
	HP m_hp;
	std::string m_name;
public:
	Character(HP hp, std::string name);
	virtual std::string to_string() const override;
	std::string hp() const;
};

class Player : public Character {
public:
	Player(HP hp, std::string name, std::string id);
	std::string to_string() const override; 
};

class Hurting : virtual public GameObj {
protected:
	HP m_dmg;
public:
	explicit Hurting(HP dmg);
	virtual std::string to_string() const override;
	std::string hp() const;
};

class Bomb : public Hurting {
public:
	Bomb(HP dmg, std::string id);
};

class Boss : public Character, public Hurting {
public:
	Boss(HP hp, std::string name, HP dmg, std::string id);
	std::string to_string() const override;
};
