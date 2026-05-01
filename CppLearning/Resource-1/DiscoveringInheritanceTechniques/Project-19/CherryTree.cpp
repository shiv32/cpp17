#include "CherryTree.hpp"
#include "Cherry.hpp"

Cherry *CherryTree::pick()
{
    return new Cherry();
}

// std::unique_ptr<Cherry> CherryTree::pick()
// {
//     return std::make_unique<Cherry>();
// }