#pragma once

#include <vector>

#include "Obserwator.h"

class Obserwowany {

protected: 
	std::vector<Obserwator*> m_observers;

public:
	~Obserwowany() = default;
	virtual void dodajObserwatora(Obserwator* observer);
	virtual void noweDaneNadeszly(int data) const;
};

void Obserwowany::dodajObserwatora(Obserwator* observer) {
	m_observers.push_back(observer);
}

void Obserwowany::noweDaneNadeszly(int data) const {
	for (auto& observer : m_observers) {
		observer->dodajDane(data);
	}
}
