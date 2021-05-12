#pragma once

#include <vector>

class Wrapper {
public:
	virtual ~Wrapper() = default;
};

template <typename T>
class ObjectWrapper : public Wrapper {
private:
	T m_object;
public:
	explicit ObjectWrapper(T object) : m_object(object) {}
	T access() { return m_object; }
	void set(T obj) { m_object = obj; }
};

class ClonesF {

private:
	std::vector<Wrapper*> m_wrappedObjects;

public:
	~ClonesF() {
		for (auto* wrappedObject : m_wrappedObjects) {
			delete wrappedObject;
		}
	}

	template <typename T>
	void add(const T& obj) {
		m_wrappedObjects.push_back(new ObjectWrapper<T>(obj));
	}

	template <typename T>
	T clone() const {
		for (auto* wrappedObject : m_wrappedObjects)
		if (ObjectWrapper<T>* wo = dynamic_cast<ObjectWrapper<T>*>(wrappedObject)) {
			return wo->access();
		}
		throw perror;
	}

	template <typename T>
	void replace(T object) {
		for (auto* wrappedObject : m_wrappedObjects)
		if (ObjectWrapper<T>* wo = dynamic_cast<ObjectWrapper<T>*>(wrappedObject)) {
			wo->set(object);
			return;
		}
	}
};
