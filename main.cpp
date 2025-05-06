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
    System *system = new System();
    system->addDriver(new Driver("Bob", nullptr, "8YHH264"));
    system->addDriver(new Driver("Alex", nullptr, "123ABC!"));
    system->addDriver(new Driver("Alice", nullptr, "155HJ66"));
    system->start();
    return 0;
}