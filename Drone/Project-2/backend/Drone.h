#pragma once

#include <QObject>
#include <mavsdk/mavsdk.h>

class Drone : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool connected
                   READ connected
                       NOTIFY connectedChanged)

public:
    explicit Drone(QObject *parent = nullptr);

    bool connected() const;

signals:
    void connectedChanged();

private:
    bool m_connected{false};

    mavsdk::Mavsdk m_mavsdk;
};
