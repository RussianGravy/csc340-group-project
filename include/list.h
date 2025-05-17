#pragma once

#include <iostream>
#include <stdexcept>
#include <type_traits>
using namespace std;

template <typename T>
class list
{
public:
	struct Node
	{
		T data{};
		Node *next = nullptr;
		Node *prev = nullptr;

		// added a cpstuctro
		Node(const T &val)
		{
			data = val;
			next = nullptr;
			prev = nullptr;
		}
	};

public:
	list();

	~list();

	int size() const { return list_size; }

	bool search(const T &p_value);

	// insert at end
	void push_back(const T &newVal);

	// insert at front
	void push_front(const T &newVal);

	// Insert value val before index index
	void insert_at(int index, const T &val);

	//! @note Remove operation at specific index position
	void remove_at(int index);

	void pop_back();

	void pop_front();

	void print();

	void reverse_print();

    Node* get_head() const {
        return head;
    }

    Node* get_tail() const {
        return tail;
    }

private:
	int list_size = 0;
	Node *head = nullptr;
	Node *tail = nullptr;
};

#include "list.tpp"