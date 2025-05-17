#ifndef SYSTEM_TEST
#define SYSTEM_TEST
#include "system.h"
#include <fstream>
#include <sstream>
#include "read.h"

class Test
{
public:
    Test() = default;
    void start();
    int test_input_drivers_from_file();
    int test_input_riders_from_file();
    int test_assign_driver();

private:
};

#endif