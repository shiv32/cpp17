/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Composite
 * @version 0.1
 * @date 2024-08-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>
#include "Composite.hpp"
#include "Leaf.hpp"

/**
 * The client code works with all of the components via the base interface.
 */
void ClientCode(Component *component)
{

    std::cout << "RESULT: " << component->Operation();
}

/**
 * Thanks to the fact that the child-management operations are declared in the
 * base Component class, the client code can work with any component, simple or
 * complex, without depending on their concrete classes.
 */
void ClientCode2(Component *component1, Component *component2)
{

    if (component1->IsComposite())
    {
        component1->Add(component2);
    }
    std::cout << "RESULT: " << component1->Operation();
}

int main() // client
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Component *simple = new Leaf;
    // std::cout << "Client: I've got a simple component:\n";
    // ClientCode(simple);
    // std::cout << "\n\n";

    // /**
    //  * ...as well as the complex composites.
    //  */

    // Component *tree = new Composite;
    // Component *branch1 = new Composite;

    // Component *leaf_1 = new Leaf;
    // Component *leaf_2 = new Leaf;
    // Component *leaf_3 = new Leaf;

    // branch1->Add(leaf_1);
    // branch1->Add(leaf_2);

    // Component *branch2 = new Composite;
    // branch2->Add(leaf_3);

    // tree->Add(branch1);
    // tree->Add(branch2);

    // std::cout << "Client: Now I've got a composite tree:\n";
    // ClientCode(tree);
    // std::cout << "\n\n";

    // std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
    // ClientCode2(tree, simple);
    // std::cout << "\n";

    // delete simple;
    // delete tree;
    // delete branch1;
    // delete branch2;
    // delete leaf_1;
    // delete leaf_2;
    // delete leaf_3;

    // using smart pointer
    std::shared_ptr<Component> simple = std::make_shared<Leaf>();
    std::cout << "Client: I've got a simple component:\n";
    ClientCode(simple.get());

    std::cout << "\n\n";

    /**
     * ...as well as the complex composites.
     */

    std::shared_ptr<Component> tree = std::make_shared<Composite>();
    std::shared_ptr<Component> branch1 = std::make_shared<Composite>();

    std::shared_ptr<Component> leaf_1 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf_2 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf_3 = std::make_shared<Leaf>();

    branch1->Add(leaf_1.get());
    branch1->Add(leaf_2.get());

    std::shared_ptr<Component> branch2 = std::make_shared<Composite>();

    branch2->Add(leaf_3.get());

    tree->Add(branch1.get());
    tree->Add(branch2.get());

    std::cout << "Client: Now I've got a composite tree:\n";
    ClientCode(tree.get());

    std::cout << "\n\n";

    std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
    ClientCode2(tree.get(), simple.get());

    std::cout << "\n";

    return 0;
}