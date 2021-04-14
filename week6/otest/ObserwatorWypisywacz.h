#pragma once

#include "Obserwator.h"

#include <iostream>

class ObserwatorWypisywacz : public Obserwator {
public:
	void dodajDane(int x) override;
private:
};

void ObserwatorWypisywacz::dodajDane(int x) {
	std::cout << " " << x;
	m_dane.push_back(x);
}
