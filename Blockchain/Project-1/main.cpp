#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

class Block
{
public:
    int index;
    std::time_t timestamp;
    std::string data;
    std::string previousHash;
    std::string hash;
    int nonce;

    Block(int idx, std::string data, std::string prevHash)
        : index(idx), data(std::move(data)), previousHash(std::move(prevHash)), nonce(0)
    {
        timestamp = std::time(nullptr);
        hash = calculateHash();
    }

    std::string calculateHash() const
    {
        std::stringstream ss;
        ss << index << timestamp << data << previousHash << nonce;
        return sha256(ss.str());
    }

    void mineBlock(int difficulty)
    {
        std::string prefix(difficulty, '0');
        do
        {
            nonce++;
            hash = calculateHash();
        } while (hash.substr(0, difficulty) != prefix);

        std::cout << "Block mined: " << hash << "\n";
    }

private:
    static std::string sha256(const std::string &str)
    {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(reinterpret_cast<const unsigned char *>(str.c_str()), str.size(), hash);
        std::stringstream ss;
        for (unsigned char i : hash)
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)i;
        return ss.str();
    }
};

class Blockchain
{
public:
    Blockchain()
    {
        chain.emplace_back(createGenesisBlock());
        difficulty = 4;
    }

    void addBlock(const std::string &data)
    {
        const Block &prevBlock = chain.back();
        Block newBlock(chain.size(), data, prevBlock.hash);
        newBlock.mineBlock(difficulty);
        chain.push_back(newBlock);
    }

    bool isChainValid() const
    {
        for (size_t i = 1; i < chain.size(); ++i)
        {
            const Block &current = chain[i];
            const Block &previous = chain[i - 1];

            if (current.hash != current.calculateHash())
                return false;
            if (current.previousHash != previous.hash)
                return false;
        }
        return true;
    }

    void printChain() const
    {
        for (const auto &block : chain)
        {
            std::cout << "Index: " << block.index << "\n"
                      << "Timestamp: " << std::ctime(&block.timestamp)
                      << "Data: " << block.data << "\n"
                      << "Prev Hash: " << block.previousHash << "\n"
                      << "Hash: " << block.hash << "\n"
                      << "Nonce: " << block.nonce << "\n"
                      << "-----------------------------\n";
        }
    }

private:
    std::vector<Block> chain;
    int difficulty;

    static Block createGenesisBlock()
    {
        return Block(0, "Genesis Block", "0");
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Blockchain myBlockchain;

    myBlockchain.addBlock("First block after Genesis");
    myBlockchain.addBlock("Second block after Genesis");

    std::cout << "\nBlockchain valid? " << (myBlockchain.isChainValid() ? "Yes" : "No") << "\n\n";
    
    myBlockchain.printChain();

    return 0;
}
