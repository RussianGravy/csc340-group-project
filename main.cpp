#include "list.h"
#include "system.h"
#include "driver.h"
#include "location.h"
#include "request.h"
#include "rider.h"
#include "vehicle.h"
#include "person.h"
#include "assignment.h"
#include "controller.h"

int main()
{
    list<Driver*> ll;
    ll.push_front(new Driver("Bob", nullptr, "8YHH264"));
    ll.push_front(new Driver("Alex", nullptr, "8YHH264"));
    ll.push_back(new Driver("Alice", nullptr, "8YHH264"));

    cout << "Size = " << ll.size() << '\n';
    ll.print();

    // ll.pop_back();
    // ll.pop_front();

    // ll.remove_at(0);

    cout << "Size = " << ll.size() << '\n';

    ll.print();

    return 0;
}
