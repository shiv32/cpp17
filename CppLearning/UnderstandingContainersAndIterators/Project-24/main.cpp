/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief queue Example: A Network Packet Buffer
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <queue>

//----------------------------------------------------------------------------------------
template <typename T>
class PacketBuffer
{
public:
    // If maxSize is 0, the size is unlimited, because creating
    // a buffer of size 0 makes little sense. Otherwise only
    // maxSize packets are allowed in the buffer at any one time.
    PacketBuffer(size_t maxSize = 0);

    virtual ~PacketBuffer() = default;

    // Stores a packet in the buffer.
    // Returns false if the packet has been discarded because
    // there is no more space in the buffer, true otherwise.
    bool bufferPacket(const T &packet);

    // Returns the next packet. Throws out_of_range
    // if the buffer is empty.
    T getNextPacket();

private:
    std::queue<T> mPackets;
    size_t mMaxSize;
};

template <typename T>
PacketBuffer<T>::PacketBuffer(size_t maxSize /*= 0*/) : mMaxSize(maxSize)
{
}

template <typename T>
bool PacketBuffer<T>::bufferPacket(const T &packet)
{
    if (mMaxSize > 0 && mPackets.size() == mMaxSize)
    {
        // No more space. Drop the packet.
        return false;
    }

    mPackets.push(packet);
    
    return true;
}

template <typename T>
T PacketBuffer<T>::getNextPacket()
{
    if (mPackets.empty())
    {
        throw std::out_of_range("Buffer is empty");
    }

    // Retrieve the head element
    T temp = mPackets.front();
    
    // Pop the head element
    mPackets.pop();
    
    // Return the head element
    return temp;
}
//------------------------------------------------------------------------------------------------

class IPPacket final
{
public:
    IPPacket(int id) : mID(id) {}
    int getID() const { return mID; }

private:
    int mID;
};

//--------------------------------------------------------------------------------------------------

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    PacketBuffer<IPPacket> ipPackets(3);

    // Add 4 packets
    for (int i = 1; i <= 4; ++i)
    {
        if (!ipPackets.bufferPacket(IPPacket(i)))
        {
            std::cout << "Packet " << i << " dropped (queue is full)." << std::endl;
        }
    }

    while (true)
    {
        try
        {
            IPPacket packet = ipPackets.getNextPacket();
            std::cout << "Processing packet " << packet.getID() << std::endl;
        }
        catch (const std::out_of_range &)
        {
            std::cout << "Queue is empty." << std::endl;
            break;
        }
    }

    return 0;
}