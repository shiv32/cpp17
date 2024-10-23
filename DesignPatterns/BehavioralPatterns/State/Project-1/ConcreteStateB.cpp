// #include "ConcreteStateB.hpp"
// #include "ConcreteStateA.hpp"

// void ConcreteStateB::Handle1() 
// {
//     std::cout << "ConcreteStateB handles request1.\n";
// }
// void ConcreteStateB::Handle2() 
// {
//     std::cout << "ConcreteStateB handles request2.\n";
//     std::cout << "ConcreteStateB wants to change the state of the context.\n";
//     this->context_->TransitionTo(new ConcreteStateA);
// }