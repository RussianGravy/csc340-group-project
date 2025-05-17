#include "system_test.h"

void printMenu()
{
    std::cout << "------------------------------\n";
    std::cout << "(1) input drivers from file\n";
    std::cout << "(2) input riders from file\n";
    std::cout << "Press 0 to quit\n";
    std::cout << "------------------------------\n";
}

void Test::start()
{
    int userInput = 1;
    while (userInput != 0)
    {
        printMenu();
        std::cin >> userInput;
        if (userInput == 1)
        {
            this->test_input_drivers_from_file();
        }
        else if (userInput == 2)
        {
            this->test_input_riders_from_file();
        }
    }
}

int Test::test_input_drivers_from_file()
{
    vector<Driver> drivers;

    int lines = 3;

    std::string filename = "drivers.txt";

    std::cout << "Loading Drivers from " << filename << "\n";

    std::ifstream ins(filename);

    if (!ins)
    {
        std::cout << "FAILED - Could not open filename = " << filename << '\n';
        return 1;
    }

    while (true)
    {
        if (ins.eof())
        {
            break;
        }

        // Read the line of our drivers information
        std::string line = readline(ins);

        // Parse that line and assign them into various properties
        std::stringstream ss(line);

        std::string driver_name = "", driver_license = "";
        int driver_status_available = 0;
        int latitude = 0; // Val's addition to include a spawn location
        int longitude = 0;
        std::string address = "";
        ss >> driver_name >> driver_license >> driver_status_available >> longitude >> latitude >> address;

        // Skip adding this driver if the name's empty
        if (driver_name.empty())
        {
            continue;
        }

        cout << "Added Driver Name = " << driver_name << '\n';
        Driver driver = Driver(driver_name, driver_license);
        driver.setAvailable(driver_status_available);
        driver.add_location(latitude, longitude, address);
        drivers.push_back(driver);
    }
    if (drivers.size() != lines)
    {
        std::cout << "FAILED - did not add all drivers\n";
        return 1;
    }
    else
    {
        std::cout << "SUCCESS - added " << lines << " drivers\n";
    }
    return 0;
}

int Test::test_input_riders_from_file()
{
    vector<Rider> riders;

    int lines = 2;

    std::string filename = "riders.txt";

    std::cout << "Loading Rider from " << filename << "\n";
    std::ifstream ins(filename);

    if (!ins)
    {
        std::cout << "FAILED - Could not open filename = " << filename << '\n';
        return 1;
    }

    while (true)
    {
        if (ins.eof())
        {
            break;
        }

        // Read our line until we reached the , character
        // To retrieve the name of the rider
        std::string line = readline(ins, ',');

        // Then we parse the line afterwards to get our longitude, latitude, and address
        // Rider File Format Data = <rider_name>, <longitude> <latitude> <address>
        std::stringstream ss(line);
        std::string rider_name = read(ss);
        std::string id = read(ins);
        if (rider_name.empty())
        {
            continue;
        }
        Location new_loc = read<Location>(ins);

        Rider new_rider = Rider(id, rider_name);
        new_rider.set_start_location(new_loc);
        riders.push_back(new_rider);
    }
    if (riders.size() != lines)
    {
        std::cout << "FAILED - did not add all riders\n";
        return 1;
    }
    else
    {
        std::cout << "SUCCESS - added " << lines << " riders\n";
    }
    return 0;
}

int Test::test_assign_driver() { return 0; }