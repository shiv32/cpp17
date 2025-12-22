#include "cableCompany.hpp"

void CableCompany::addPackage(std::string_view packageName, const std::bitset<kNumChannels> &channels)
{
    mPackages.emplace(packageName, channels);
}

void CableCompany::removePackage(std::string_view packageName)
{
    mPackages.erase(packageName.data());
}

const std::bitset<kNumChannels> &CableCompany::getPackage(std::string_view packageName) const
{
    // Get a reference to the specified package.
    auto it = mPackages.find(packageName.data());

    if (it == end(mPackages))
    {
        // That package doesn't exist. Throw an exception.
        throw std::out_of_range("Invalid package");
    }

    return it->second;
}

void CableCompany::newCustomer(std::string_view name, std::string_view package)
{
    // Get the channels for the given package.
    auto &packageChannels = getPackage(package);

    // Create the account with the bitset representing that package.
    newCustomer(name, packageChannels);
}

void CableCompany::newCustomer(std::string_view name, const std::bitset<kNumChannels> &channels)
{
    // Add customer to the customers map.
    auto result = mCustomers.emplace(name, channels);

    if (!result.second)
    {
        // Customer was already in the database. Nothing changed.
        throw std::invalid_argument("Duplicate customer");
    }
}

void CableCompany::addChannel(std::string_view name, int channel)
{
    // Get the current channels for the customer.
    auto &customerChannels = getCustomerChannelsHelper(name);

    // We found the customer; set the channel.
    customerChannels.set(channel);
}

void CableCompany::removeChannel(std::string_view name, int channel)
{
    // Get the current channels for the customer.
    auto &customerChannels = getCustomerChannelsHelper(name);

    // We found this customer; remove the channel.
    customerChannels.reset(channel);
}

void CableCompany::addPackageToCustomer(std::string_view name, std::string_view package)
{
    // Get the channels for the given package.
    auto &packageChannels = getPackage(package);

    // Get the current channels for the customer.
    auto &customerChannels = getCustomerChannelsHelper(name);

    // Or-in the package to the customer's existing channels.
    customerChannels |= packageChannels;
}

void CableCompany::deleteCustomer(std::string_view name)
{
    mCustomers.erase(name.data());
}

const std::bitset<kNumChannels> &CableCompany::getCustomerChannels(std::string_view name) const
{
    // Use const_cast() to forward to getCustomerChannelsHelper()
    // to avoid code duplication.
    return const_cast<CableCompany *>(this)->getCustomerChannelsHelper(name);
}

std::bitset<kNumChannels> &CableCompany::getCustomerChannelsHelper(std::string_view name)
{
    // Find a reference to the customer.
    auto it = mCustomers.find(name.data());

    if (it == end(mCustomers))
    {
        throw std::invalid_argument("Unknown customer");
    }

    // Found it.
    // Note that 'it' is a reference to a name/bitset pair.
    // The bitset is the second field.
    return it->second;
}
