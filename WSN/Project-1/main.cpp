#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Node
{
    int id;
    double x, y;   // Coordinates
    double energy; // Remaining energy
    double range;  // Communication range

    // Check if the node can communicate with another node
    bool canCommunicate(const Node &other) const
    {
        double distance = std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
        return distance <= range;
    }

    // Simulate energy consumption for transmission
    void transmit(double energyCost)
    {
        energy -= energyCost;
        if (energy < 0)
            energy = 0; // Prevent negative energy
    }
};

class WSN
{
private:
    std::vector<Node> nodes;
    double transmissionCost; // Energy cost per transmission
    double receiveCost;      // Energy cost per reception

public:
    WSN(int numNodes, double areaSize, double nodeRange, double initialEnergy,
        double txCost, double rxCost)
    {
        transmissionCost = txCost;
        receiveCost = rxCost;
        srand(static_cast<unsigned>(time(0))); // Seed random number generator

        // Initialize nodes
        for (int i = 0; i < numNodes; ++i)
        {
            nodes.push_back(Node{
                i,
                rand() % static_cast<int>(areaSize), // Random x-coordinate
                rand() % static_cast<int>(areaSize), // Random y-coordinate
                initialEnergy,
                nodeRange});
        }
    }

    // Simulate data transmission from one node to another
    void transmitData(int senderID, int receiverID)
    {
        if (senderID >= nodes.size() || receiverID >= nodes.size())
        {
            std::cout << "Invalid node IDs.\n";
            return;
        }

        Node &sender = nodes[senderID];
        Node &receiver = nodes[receiverID];

        if (!sender.canCommunicate(receiver))
        {
            std::cout << "Nodes are out of range.\n";
            return;
        }

        if (sender.energy <= 0)
        {
            std::cout << "Sender node is out of energy.\n";
            return;
        }

        // Energy consumption
        sender.transmit(transmissionCost);
        receiver.transmit(receiveCost);

        std::cout << "Data transmitted from Node " << senderID
                  << " to Node " << receiverID << ".\n";
    }

    // Print the status of all nodes
    void printStatus() const
    {
        for (const auto &node : nodes)
        {
            std::cout << "Node " << node.id
                      << " [x: " << node.x << ", y: " << node.y
                      << ", energy: " << node.energy << "]\n";
        }
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int numNodes = 10;
    double areaSize = 100.0;      // 100x100 grid
    double nodeRange = 20.0;      // Communication range
    double initialEnergy = 100.0; // Initial energy per node
    double transmissionCost = 1.0;
    double receiveCost = 0.5;

    // Create the WSN
    WSN network(numNodes, areaSize, nodeRange, initialEnergy, transmissionCost, receiveCost);

    network.printStatus();

    // Simulate some data transmissions
    network.transmitData(0, 1);
    network.transmitData(2, 3);
    network.transmitData(0, 9); // Example with out-of-range or invalid case

    network.printStatus(); // Check updated energy levels
    return 0;
}
