#pragma once

#include "Obserwator.h"

#include <iostream>

class ObserwatorLicznik : public Obserwator {
public:
	void dodajDane(int x) override;
	int suma();
private:
};

void ObserwatorLicznik::dodajDane(int x) {
	m_dane.push_back(x);
}

int ObserwatorLicznik::suma() {
	int sum = 0;
	for(int i : m_dane) {
		sum += i;
	}
	return sum;
}
