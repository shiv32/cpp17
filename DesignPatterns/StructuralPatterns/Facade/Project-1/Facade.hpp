#pragma once

#include <string>

class Subsystem1;
class Subsystem2;

class Facade
{
protected:
    Subsystem1 *subsystem1_;
    Subsystem2 *subsystem2_;
    
    /**
     * Depending on your application's needs, you can provide the Facade with
     * existing subsystem objects or force the Facade to create them on its own.
     */
public:
    /**
     * In this case we will delegate the memory ownership to Facade Class
     */
    Facade(Subsystem1 *subsystem1 = nullptr,
           Subsystem2 *subsystem2 = nullptr);
 

    ~Facade();
   

    /**
     * The Facade's methods are convenient shortcuts to the sophisticated
     * functionality of the subsystems. However, clients get only to a fraction of
     * a subsystem's capabilities.
     */
    std::string Operation();
    
};