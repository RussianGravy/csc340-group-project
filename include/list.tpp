#include "list.h"

template<typename T>
list<T>::list()
{
}

template<typename T>
list<T>::~list()
{
    for (Node *ptr = head; ptr;)
    {
        Node *next = ptr->next;
        delete ptr;
        ptr = next;
    }
    list_size = 0;
}

template<typename T>
bool list<T>::search(const T &p_value)
{
    for (Node *current = head; current; current = current->next)
    {
        if (current->data == p_value)
        {
            return true;
        }
    }

    return false;
}

// insert at end
template<typename T>
void list<T>::push_back(const T &newVal)
{
    if (!list_size or !head or !tail)
    {
        head = tail = new Node(newVal);
    }
    // Case #2: At least 1 item in here
    else
    {
        Node *newGuy = new Node(newVal);
        tail->next = newGuy;
        newGuy->prev = tail;
        tail = newGuy;
    }
    list_size++;
}

// insert at front
template<typename T>
void list<T>::push_front(const T &newVal)
{
    // Case #1: Am I empty?
    if (!list_size or !head or !tail)
    {
        head = tail = new Node(newVal);
    }
    // Case #2: At least 1 item in here
    else
    {
        Node *newGuy = new Node(newVal);
        head->prev = newGuy;
        newGuy->next = head;
        head = newGuy;
    }
    list_size++;
}

// Insert value val before index index
template<typename T>
void list<T>::insert_at(int index, const T &val)
{
    if (index > list_size or index < 0)
        throw runtime_error("No you're out of bounds!");
    // Case #1 - list is empty
    // Case #2 - inserting at front
    if (!list_size or !index)
        push_front(val);
    // Case #3 - inserting at end
    else if (index == list_size)
        push_back(val);
    // Case #4 - inserting in middle
    else
    {
        Node *newGuy = new Node(val);
        Node *after = head;
        for (int i = 0; i < index; i++)
        {
            after = after->next;
        }
        Node *previous = after->prev;
        // Four pointers have to update
        // When you insert in the middle
        newGuy->next = after;
        newGuy->prev = previous;
        after->prev = newGuy;
        previous->next = newGuy;
        list_size++;
    }
}

//! @note Remove operation at specific index position

template<typename T>
void list<T>::remove_at(int index)
{
    Node *current = head;
    //
    for (int i = 0; i < index; i++)
    {
        if (current != nullptr)
        {
            current = current->next;
        }
    }

    // If the position is out of range
    if (current == nullptr)
    {
        return;
    }

    // Update the previous node's next pointer
    if (current->prev != nullptr)
    {
        current->prev->next = current->next;
    }

    // Update the next node's prev pointer
    if (current->next != nullptr)
    {
        current->next->prev = current->prev;
    }

    // If the node to be deleted is the head node
    if (head == current)
    {
        head = current->next;
    }

    // Deallocate memory for the deleted node
    delete current;

    list_size--;
}

template<typename T>
void list<T>::pop_back()
{
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    list_size--;
}

template<typename T>
void list<T>::pop_front()
{
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }

    list_size--;
}

template<typename T>
void list<T>::print()
{
    for (Node *curNode = head; curNode; curNode = curNode->next)
    {
        cout << curNode->data << '\n';
    }
}

template<typename T>
void list<T>::reverse_print()
{
    for (Node *curNode = tail; curNode; curNode = curNode->prev)
    {
        // At compile-time checks if the type being passed is a pointer of some type if it is then we dereference that object
        if(std::is_pointer_v<T>) {
            cout << *curNode->data << '\n';
        }
        else {
            cout << curNode->data << '\n';
        }
    }
}