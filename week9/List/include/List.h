#pragma once

#include <iostream>

template <typename T>
class List;

template <typename T>
std::ostream& operator<<(std::ostream&, const List<T>&);

template<typename T> struct Node {

	T m_element;
	Node* m_next;

	Node(T element, Node* next = nullptr);
};

template<typename T> class List {
	
friend std::ostream& operator<< <>(std::ostream&, const List<T>&);

private:
	Node<T>* m_head;
public:
	List();
	List(const List& other);
	List(List&& other);
	~List();

	List& add(T element);
	bool contains(T element) const;
};

/* Node */

template<typename T>
Node<T>::Node(T element, Node* next) : m_element(element), m_next(next) {}

/* List */

template <typename T>
std::ostream& operator<< (std::ostream& os, const List<T>& list) {
	if (list.m_head != nullptr) {
		Node<T>* current = list.m_head;
		while (current != nullptr) {
			os << current->m_element << " ";
			current = current->m_next;
		}
	}
	return os;
}

template<typename T>
List<T>::List() : m_head(nullptr) {}

template<typename T>
List<T>::List(const List<T>& other) : m_head(nullptr) {
	if (other.m_head != nullptr) {
		Node<T>* currentOther = other.m_head;
		m_head = new Node(*currentOther);
		Node<T>* current = m_head;
		while (currentOther->m_next != nullptr) {
			currentOther = currentOther->m_next;
			current->m_next = new Node(*currentOther);
			current = current->m_next;
		}
	}
}

template<typename T>
List<T>::List(List<T>&& other) : m_head(nullptr) {
	m_head = std::exchange(other.m_head, nullptr);
}

template <typename T>
List<T>::~List() {
	Node<T>* current = m_head;
	Node<T>* next;
	while(current != nullptr) {
		next = current->m_next;
		delete current;
		current = next;
	}
}

template<typename T>
List<T>& List<T>::add(T element) {
	if (m_head != nullptr) {
		Node<T>* current = m_head;
		while(current->m_next != nullptr) {
			current = current->m_next;
		}
		current->m_next = new Node(element);
	} else {
		m_head = new Node(element);
	}
	return *this;
}

template<typename T>
bool List<T>::contains(T element) const {
	Node<T>* current = m_head;
	while(current != nullptr) {
		if (current->m_element == element) {
			return true;
		}
		current = current->m_next;
	}
	return false;
}
