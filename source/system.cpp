#include "../include/system.h"
#include "../include/rider.h"
#include "read.h"
#include <fstream>
#include <sstream>

/*
 * Main Program Loop
 * If (Request queue has any Requests && any Drivers are available)
 *   pop the next request in queue and create Assignment for closest Driver
 *
 * progress each Driver through its Assignement (LinkedList?)
 */

void System::addRider(const Rider &rider)
{
    riders.push_back(rider);
    cout << "Rider added: " << rider.getName() << "\n";
}

const list<Rider> &System::getRiders() const
{
    return riders;
}

void print_menu()
{
    cout << "------------------------------\n";
    cout << "1. Add Driver\n"
         << "2. Add Rider\n"
         << "3. Load Drivers From File\n"
         << "4. Load Riders From File\n"
         << "~ App Controls ~\n"
         << "5. Check Available Drivers // gives number of available drivers\n"
         << "6. New Request // submit new request with pick-up and drop-off location\n"
         << "7. Check Status // give status of the user\n"
         << "8. Print drivers\n"
         << "9. Print riders\n"
         << "Press 0 to quit\n";
    cout << "------------------------------\n";
}

// starts system's main loop
void System::start()
{
    std::cout << "Add user to list of riders: \n";
    // aaron don't hate me - Val
    Rider *user;
    Request *userRequest;
    user = new Rider();
    *user = read<Rider>("");
    riders.push_back(*user);
    userRequest = nullptr;

    cout << "\nHello, " << *user << "!\n\n";

    while (true)
    {
        // assignDriver for next in queue
        if (!requests.empty())
        {
            if (assignDriver(requests.front()))
            {
                requests.pop();
            }
        }
        // user interaction loop
        print_menu();
        int x = read("");
        if (x == 0)
        {
            cout << "Exiting out of system::start!\n";
            break;
        }

        if (x == 1)
        {
            cout << "Adding a driver!\n";
            Driver new_driver = read<Driver>("");
            bool x = read("Enter status of the driver: ");
            new_driver.setAvailable(x);
            drivers.push_back(new_driver);
        }
        else if (x == 2)
        {
            cout << "Adding a Rider\n";
            Rider new_rider = read<Rider>("");
            riders.push_back(new_rider);
        }
        else if (x == 3)
        {
            cout << "Loading Driver from File\n";
            std::string filename = read("Enter filename: ");

            std::ifstream ins(filename);

            if (!ins)
            {
                cout << "Could not open filename = " << filename << '\n';
                continue;
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
        }
        else if (x == 4)
        {
            cout << "Loading Rider from File\n";
            std::string filename = read("Enter filename: ");
            std::ifstream ins(filename);

            if (!ins)
            {
                cout << "Could not load filename: " << filename << '\n';
                continue;
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
        }
        // App User Controls
        else if (x == 5)
        {
            cout << "Giving number of available drivers.\n";
            int number_of_available_drivers = 0;
            for (list<Driver>::Node *current = drivers.get_head(); current; current = current->next)
            {
                if (current->data.isAvailable())
                {
                    number_of_available_drivers++;
                }
            }

            cout << "Drivers Available Count: " << number_of_available_drivers << '\n';
            for (list<Driver>::Node *current = drivers.get_head(); current; current = current->next)
            {
                if (current->data.isAvailable())
                {
                    cout << current->data.getName() << " is available!\n";
                    cout << current->data << '\n';
                }
            }
        }
        else if (x == 6)
        {
            cout << *user << endl;
            if (userRequest == nullptr)
            {
                // I know the pointers are nasty but a regular variable would go out of scope
                std::cout << "Making a new request for pick up and drop off.\n";
                std::cout << "Getting Pick Up Location... \n";
                Location *pickUp = new Location();
                *pickUp = read<Location>("");
                std::cout << "Getting Drop Off Location... \n";
                Location *dropOff = new Location();
                *dropOff = read<Location>("");
                userRequest = new Request(user, pickUp, dropOff);
                addRequest(*userRequest);
            } 
            else
            {
                cout << "You are number still in queue.\n";
            }
        }
        else if (x == 7)
        {
            cout << "User " << *user << ", ";
            if (userRequest)
            {
                int placeNum = 1;
                std::cout << "You are still in queue.\n";
            }
            // else if (has driver) print driver
            else
                std::cout << "You have no active requests.\n";
        }
        else if (x == 8)
        {
            drivers.print();
        }
        else if (x == 9)
        {
            riders.print();
        }
    }
    delete user;
}
System::~System()
{
    /* for (list<Driver *>::Node *current = drivers.get_head(); current; current = current->next) */
    /* { */
    /*     delete current->data; */
    /* } */
    while (!requests.empty())
    {
        /* delete requests.front(); */
        requests.pop();
    }
}
// returns 1 if no available driver, 0 if otherwise successful
int System::assignDriver(const Request &request)
{
    // Using pointer to indicate if the object is valid whenever we make requests to available drivers.
    Driver *closestDriver = nullptr;
    double distanceToClosestDriver;
    for (list<Driver>::Node *current = drivers.get_head(); current; current = current->next)
    {
        if (current->data.isAvailable())
        {
            if (closestDriver)
            {
                double distanceToCurrent = current->data.getCurrentLocation().distanceTo(*request.getPickUp());
                if (distanceToCurrent < distanceToClosestDriver)
                {
                    closestDriver = &current->data;
                    distanceToClosestDriver = distanceToCurrent;
                }
            }
            else
            {
                closestDriver = &current->data;
                distanceToClosestDriver = current->data.getCurrentLocation().distanceTo(*request.getPickUp());
            }
        }
    }
    if (closestDriver)
    {
        closestDriver->setAvailable(false);
        closestDriver->setAssignment(*request.getRider(), *request.getPickUp(), *request.getDropOff());
        closestDriver->add_location(*request.getPickUp());
        requests.pop();
        return 0;
    }
    else
    {
        return 1;
    }
}
void System::addRequest(const Request &request)
{
    requests.push(request);
}
void System::addDriver(const Driver &driver)
{
    drivers.push_back(driver);
}
