#include "system_test.h"

void printMenu()
{
    std::cout << "------------------------------\n";
    std::cout << "(1) input drivers from file\n";
    std::cout << "(2) input riders from file\n";
    std::cout << "(3) request pick-up and drop-off\n";
    std::cout << "(4) assign driver to rider\n";
    std::cout << "Press 0 to quit\n";
    std::cout << "------------------------------\n";
}

void Test::start()
{
    Rider jolly("111", "Jolly");
    this->riders.push_back(jolly);
    Rider tilly("112", "Tilly");
    this->riders.push_back(tilly);
    Rider cricket("113", "Cricket");
    this->riders.push_back(cricket);

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
        else if (userInput == 3)
        {
            // this->test_make_requests();
        }
        else if (userInput == 4)
        {
            // this->test_assign_driver();
        }
    }
}

// test file IO for Riders
int Test::test_input_drivers_from_file()
{
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
        this->drivers.push_back(driver);
    }
    if (this->drivers.size() != lines)
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

// test file IO for Riders
int Test::test_input_riders_from_file()
{
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
        std::cout << new_rider << endl;
        this->riders.push_back(new_rider);
    }
    if (this->riders.size() != lines)
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

int Test::test_make_requests()
{
    for (Rider rider : this->riders)
    {
        Location *pickUp = new Location();
        // add test location
        Location *dropOff = new Location();
        // add test location
        this->requests.push(new Request(&rider, pickUp, dropOff));
    }
    if (this->requests.size() == this->riders.size())
    {
        std::cout << "SUCCESS - there are now " << this->requests.size() << " requests in queue.\n";
    }
    else
    {
        std::cout << "FAILED - not all requests were added.";
        return 1;
    }
    return 0;
}

int Test::test_assign_driver() { return 0; }

/*
std::cout << "Making a new request for pick up and drop off.\n";
std::cout << "Getting Pick Up Location... \n";
Location *pickUp = new Location();
*pickUp = read<Location>("");
std::cout << "Getting Drop Off Location... \n";
Location *dropOff = new Location();
*dropOff = read<Location>("");
userRequest = new Request(user, pickUp, dropOff);
addRequest(*userRequest);
*/