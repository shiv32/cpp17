#include "Drone.h"

#include <chrono>
#include <thread>

using namespace mavsdk;

Drone::Drone(QObject *parent)
    : QObject(parent),
    m_mavsdk(
        Mavsdk::Configuration{
            ComponentType::GroundStation
        })
{
    const auto result =
        m_mavsdk.add_any_connection("udp://:14540");

    if (result != ConnectionResult::Success) {
        return;
    }

    std::thread([this]() {

        auto system = m_mavsdk.first_autopilot(10.0);

        if (system.has_value()) {
            m_connected = true;
            emit connectedChanged();
        }

    }).detach();
}

bool Drone::connected() const
{
    return m_connected;
}
