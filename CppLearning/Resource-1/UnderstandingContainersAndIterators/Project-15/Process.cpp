#include "Process.hpp"

Process::Process(std::string_view name) : mName(name)
{
}

void Process::doWorkDuringTimeSlice()
{
    std::cout << "Process " << mName
              << " performing work during time slice." << std::endl;
}

bool Process::operator==(const Process &rhs)
{
    return mName == rhs.mName;
}
