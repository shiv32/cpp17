#include "ObjectPool.hpp"

ObjectPool* ObjectPool::instance = 0;

ObjectPool *ObjectPool::getInstance()
{
    if (instance == 0)
    {
        instance = new ObjectPool;
    }
    return instance;
}

Resource *ObjectPool::getResource()
{
    if (resources.empty())
    {
        std::cout << "Creating new." << std::endl;
        return new Resource;
    }
    else
    {
        std::cout << "Reusing existing." << std::endl;
        Resource *resource = resources.front();
        resources.pop_front();
        return resource;
    }
}

void ObjectPool::returnResource(Resource *object)
{
    object->reset();
    resources.push_back(object);
}