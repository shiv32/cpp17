/**
 * @file ObjectPool.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <list>
#include <iostream>
#include "Resource.hpp"

/* Note, that this class is a singleton. */
class ObjectPool
{
private:
    std::list<Resource *> resources;

    static ObjectPool *instance;
    ObjectPool() {}

public:
    /**
     * Static method for accessing class instance.
     * Part of Singleton design pattern.
     *
     * @return ObjectPool instance.
     */
    static ObjectPool *getInstance();

    /**
     * Returns instance of Resource.
     *
     * New resource will be created if all the resources
     * were used at the time of the request.
     *
     * @return Resource instance.
     */
    Resource *getResource();

    /**
     * Return resource back to the pool.
     *
     * The resource must be initialized back to
     * the default settings before someone else
     * attempts to use it.
     *
     * @param object Resource instance.
     * @return void
     */
    void returnResource(Resource *object);
};