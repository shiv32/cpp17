#include <iostream>
#include <vector>
#include <deque>

template <template <typename> class Out_container, template <typename> class In_container, typename T>
Out_container<T> resequence(const In_container<T>& in_container) 
{
    Out_container<T> out_container;
    
    for (auto x : in_container) {
            out_container.push_back(x);
        }
    
    return out_container;
}

int main()
{
   std::vector<int> v { 1, 2, 3, 4, 5};

   auto d = resequence<std::deque>(v); // deque with 1, 2, 3, 4, 5

   for(const auto de : d)
   {
     std::cout<<de<<std::endl;
   }

    return 0;
}