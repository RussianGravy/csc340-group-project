#include "include/list.h"

int main() {
    list<std::string> ll;
    ll.push_front("Bob");
    ll.push_front("Alex");
    ll.push_back("Alice");
    
    cout << "Size = " << ll.size() << '\n';
    // ll.print();

    // ll.pop_back();
    // ll.pop_front();

    ll.remove_at(0);

    cout << "Size = " << ll.size() << '\n';

    ll.print();


    return 0;
}
