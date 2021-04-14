#pragma once
#include <vector>

class Obserwator {
public:
	virtual void dodajDane(int x) = 0;
protected:
	std::vector<int> m_dane;
};

#include "ObserwatorLicznik.h"
#include "ObserwatorWypisywacz.h"
