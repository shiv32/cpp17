/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief INTERESTING AND OBSCURE INHERITANCE ISSUES
            Extending a class opens up a variety of issues. 
                What characteristics of the class can and cannot be changed? 
                What is non-public inheritance? 
                What are virtual base classes? 
                etc.

        Changing the Overridden Method’s Characteristics
            The reason you override a method is to change its implementation. 
            You may want to change other characteristics of the method.

            Changing the Method Return Type
                A good rule of thumb is to override a method with the exact method declaration,
                or method prototype, that the base class uses. 
                The implementation can change, but the prototype stays the same.

                In C++, an overriding method can change the return type as long as the original return type is
                a pointer or reference to a class, and the new return type is a pointer or reference to a 
                descendent class. 
                Such types are called covariant return types. 

                This feature sometimes comes in handy when the base class and derived class work with objects in 
                a parallel hierarchy—that is, another group of classes that is tangential, but related, 
                to the first class hierarchy.

                    eg. cherry orchard simulator

                            You might have two hierarchies of classes that model different real-world objects
                            but are obviously related. 
                            The first is the Cherry chain. The base class, Cherry, has a derived class called BingCherry. 
                            Similarly, there is another chain of classes with a base class called CherryTree
                            and a derived class called BingCherryTree.

                                Cherry <-- BingCherry
                            
                            CherryTree <-- BingCherryTree

                            Now assume that the CherryTree class has a virtual method called pick() 
                            that retrieves a single cherry from the tree:

                                    Cherry* CherryTree::pick()
                                    {
                                        return new Cherry();
                                    }
 
                            In the BingCherryTree-derived class, you may want to override this method.
                            Because a BingCherry is a Cherry, you could leave the method prototype as is 
                            and override the method.
                            The BingCherry pointer is automatically cast to a Cherry pointer. 

                                    Cherry* BingCherryTree::pick()
                                    {
                                        auto theCherry = std::make_unique<BingCherry>();
                                        theCherry->polish();
                                        return theCherry.release();
                                    }

                            You know that the BingCherryTree will always return BingCherry objects, you 
                            could indicate this fact to potential users of this class by changing the return type. 

                                    BingCherry* BingCherryTree::pick()
                                    {
                                        auto theCherry = std::make_unique<BingCherry>();
                                        theCherry->polish();
                                        return theCherry.release();
                                    }

                            You can use the BingCherryTree::pick() method

                                    BingCherryTree theTree;
                                    std::unique_ptr<Cherry> theCherry(theTree.pick());
                                    theCherry->printType();

                            A good way to figure out whether you can change the return type of an overridden method
                            is to consider whether existing code would still work;
                            this is called the Liskov substitution principle (LSP).

                            In the preceding example, changing the return type was fine because any code that assumed
                            that the pick() method would always return a Cherry* would still compile and work correctly.

                            Becausea BingCherry is a Cherry, any methods that were called on the result of CherryTree’s 
                            version of pick() could still be called on the result of BingCherryTree’s version of pick().

                            You could not, for example, change the return type to something completely unrelated,
                            such as void*. 
                            The following code does not compile:

                                    void* BingCherryTree::pick() // Error!
                                    {
                                        auto theCherry = std::make_unique<BingCherry>();
                                        theCherry->polish();
                                        return theCherry.release();
                                    }

                            This generates a compilation error

                                    'BingCherryTree::pick': overriding virtual function return type differs 
                                    and is not covariant from 'CherryTree::pick'.

                            This example is using raw pointers instead of smart pointers. 
                            It does not work for example when using std::unique_ptr as return type.

                            Suppose the CherryTree::pick() method returns a unique_ptr<Cherry> as follows:

                                    std::unique_ptr<Cherry> CherryTree::pick()
                                    {
                                        return std::make_unique<Cherry>();
                                    }

                            
                            Now, you cannot change the return type for the BingCherryTree::pick() method to
                            unique_ ptr<BingCherry>. 
                            That is, the following does not compile:

                                    class BingCherryTree : public CherryTree
                                    {
                                        public:
                                        virtual std::unique_ptr<BingCherry> pick() override;
                                    };

                            The reason is that std::unique_ptr is a class template. 
                            Two instantiations of the unique_ptr class template are created,
                            unique_ptr<Cherry> and unique_ptr<BingCherry>. 
                            Both these instantiations are completely different types and are in
                            no way related to each other.
                            You cannot change the return type of an overridden method to return
                            a completely different type.


 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    return 0;
}