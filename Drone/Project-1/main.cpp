#include <iostream>
#include <thread>
#include <chrono>

#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/telemetry/telemetry.h>

using namespace mavsdk;

int main()
{
    Mavsdk mavsdk{Mavsdk::Configuration{ComponentType::GroundStation}};

    auto result = mavsdk.add_any_connection("udpin://0.0.0.0:14540");

    if (result != ConnectionResult::Success)
    {
        std::cout << "Connection failed\n";
        return 1;
    }

    std::cout << "Waiting for PX4...\n";

    while (mavsdk.systems().empty())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    auto system = mavsdk.systems().front();

    std::cout << "System found, waiting for connection...\n";

    while (!system->is_connected())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Connected!\n";

    Telemetry telemetry(system);

    while (!telemetry.health_all_ok())
    {
        // std::cout << "Waiting for GPS/Sensors...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Vehicle Ready\n";

    while (true)
    {
        auto pos = telemetry.position();
        auto battery = telemetry.battery();

        std::cout
            << "Latitude  : " << pos.latitude_deg << '\n'
            << "Longitude : " << pos.longitude_deg << '\n'
            << "Altitude  : " << pos.relative_altitude_m << " m\n"
            << "Battery   : " << battery.remaining_percent * 100 << "%\n"
            << "-----------------------------\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}