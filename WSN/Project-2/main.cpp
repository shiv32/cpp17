#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

struct Node
{
    int id;
    double x, y;        // Node coordinates
    double energy;      // Remaining energy
    bool isClusterHead; // Whether the node is a cluster head
    int clusterHeadId;  // The ID of the cluster head this node is connected to

    Node(int nodeId, double xCoord, double yCoord, double initialEnergy)
        : id(nodeId), x(xCoord), y(yCoord), energy(initialEnergy), isClusterHead(false), clusterHeadId(-1) {}
};

class WSN
{
private:
    std::vector<Node> nodes;
    int numNodes;
    double areaSize;
    double clusterHeadProb;            // Probability of a node becoming a cluster head
    double baseStationX, baseStationY; // Location of the base station

public:
    WSN(int num, double size, double chProb, double initEnergy)
        : numNodes(num), areaSize(size), clusterHeadProb(chProb), baseStationX(size / 2), baseStationY(size / 2)
    {
        srand(static_cast<unsigned>(time(0))); // Random seed
        initializeNodes(initEnergy);
    }

    void initializeNodes(double initEnergy)
    {
        for (int i = 0; i < numNodes; ++i)
        {
            double x = rand() % static_cast<int>(areaSize);
            double y = rand() % static_cast<int>(areaSize);
            nodes.emplace_back(i, x, y, initEnergy);
        }
    }

    void electClusterHeads()
    {
        for (auto &node : nodes)
        {
            if (node.energy > 0 && (static_cast<double>(rand()) / RAND_MAX) < clusterHeadProb)
            {
                node.isClusterHead = true;
                node.clusterHeadId = node.id; // Self-assign as cluster head
            }
            else
            {
                node.isClusterHead = false;
                node.clusterHeadId = -1;
            }
        }
    }

    void assignClusters()
    {
        for (auto &node : nodes)
        {
            if (!node.isClusterHead && node.energy > 0)
            {
                double minDistance = std::numeric_limits<double>::max();
                int nearestCH = -1;

                for (const auto &potentialCH : nodes)
                {
                    if (potentialCH.isClusterHead && potentialCH.energy > 0)
                    {
                        double distance = std::sqrt(std::pow(node.x - potentialCH.x, 2) +
                                                    std::pow(node.y - potentialCH.y, 2));
                        if (distance < minDistance)
                        {
                            minDistance = distance;
                            nearestCH = potentialCH.id;
                        }
                    }
                }

                node.clusterHeadId = nearestCH;
            }
        }
    }

    void simulateSteadyState()
    {
        for (auto &ch : nodes)
        {
            if (ch.isClusterHead && ch.energy > 0)
            {
                double aggregatedEnergyCost = 0.0;

                for (auto &node : nodes)
                {
                    if (node.clusterHeadId == ch.id && node.energy > 0)
                    {
                        double distance = std::sqrt(std::pow(node.x - ch.x, 2) + std::pow(node.y - ch.y, 2));
                        double energyCost = 0.1 * distance; // Example energy model
                        node.energy -= energyCost;
                        aggregatedEnergyCost += energyCost;

                        if (node.energy < 0)
                            node.energy = 0; // Prevent negative energy
                    }
                }

                double baseStationDistance = std::sqrt(std::pow(ch.x - baseStationX, 2) + std::pow(ch.y - baseStationY, 2));
                double chEnergyCost = 0.2 * baseStationDistance + aggregatedEnergyCost; // Example energy model
                ch.energy -= chEnergyCost;

                if (ch.energy < 0)
                    ch.energy = 0; // Prevent negative energy
            }
        }
    }

    void runLEACH(int rounds)
    {
        for (int round = 1; round <= rounds; ++round)
        {
            std::cout << "Round " << round << ":\n";
            electClusterHeads();
            assignClusters();
            simulateSteadyState();
            printStatus();
            std::cout << "-----------------------------\n";
        }
    }

    void printStatus() const
    {
        for (const auto &node : nodes)
        {
            std::cout << "Node " << node.id << " [x: " << node.x << ", y: " << node.y
                      << ", energy: " << node.energy
                      << ", clusterHeadId: " << node.clusterHeadId
                      << ", isClusterHead: " << (node.isClusterHead ? "Yes" : "No") << "]\n";
        }
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int numNodes = 20;
    double areaSize = 100.0;      // 100x100 area
    double clusterHeadProb = 0.2; // 20% chance of becoming a cluster head
    double initialEnergy = 10.0;  // Initial energy of each node
    int rounds = 10;              // Number of LEACH rounds

    WSN network(numNodes, areaSize, clusterHeadProb, initialEnergy);
    network.runLEACH(rounds);

    return 0;
}
