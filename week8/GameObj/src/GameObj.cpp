#include "GameObj.h"

// hp

HP::HP(int value) : m_value(value) {}

std::string HP::getHP() const {
	return "[" + std::to_string(m_value) + " HP]";
}

// game object

std::ostream& operator<< (std::ostream& os, const GameObj& gameObj) {
	return os << gameObj.to_string();
}

GameObj::GameObj(std::string id) : m_id(id) {}

std::string GameObj::id() const {
	return m_id;
}

// character

Character::Character(HP hp, std::string name) : m_hp(hp), m_name(name) {}

std::string Character::to_string() const {
	return m_name + ", ma: " + m_hp.getHP();
}

std::string Character::hp() const {
	return m_hp.getHP();
}

// player

Player::Player(HP hp, std::string name, std::string id) : GameObj(id), Character(hp, name) {}

std::string Player::to_string() const {
	return "Player " + Character::to_string();
}

// hurting

Hurting::Hurting(HP dmg) : m_dmg(dmg) {}

std::string Hurting::to_string() const {
	return "Jego uderzenie odbiera: " + m_dmg.getHP();
}

std::string Hurting::hp() const {
	return m_dmg.getHP();
}

// bomb

Bomb::Bomb(HP dmg, std::string id) : GameObj(id), Hurting(dmg) {}

// boss

Boss::Boss(HP hp, std::string name, HP dmg, std::string id) : GameObj(id), Character(hp, name), Hurting(dmg) {}

std::string Boss::to_string() const {
	return "Bad guy: " + Character::to_string() + "\n" + Hurting::to_string();
}
