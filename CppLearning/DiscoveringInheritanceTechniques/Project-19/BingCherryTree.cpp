#include "BingCherryTree.hpp"
#include "BingCherry.hpp"

// Cherry *BingCherryTree::pick()
// {
//     auto theCherry = std::make_unique<BingCherry>();
//     theCherry->polish();
//     return theCherry.release();
// }

BingCherry *BingCherryTree::pick()
{
    auto theCherry = std::make_unique<BingCherry>();
    theCherry->polish();
    return theCherry.release();
}