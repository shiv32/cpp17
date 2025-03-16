/**
 * @file Component.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-03-16
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include <string>

/**
 * The base Component class declares common operations for both simple and
 * complex objects of a composition.
 */
class Component
{
    /**
     * @var Component
     */
protected:
    Component *parent_;
    /**
     * Optionally, the base Component can declare an interface for setting and
     * accessing a parent of the component in a tree structure. It can also
     * provide some default implementation for these methods.
     */
public:
    virtual ~Component();
    void SetParent(Component *parent);
    Component *GetParent() const;

    /**
     * In some cases, it would be beneficial to define the child-management
     * operations right in the base Component class. This way, you won't need to
     * expose any concrete component classes to the client code, even during the
     * object tree assembly. The downside is that these methods will be empty for
     * the leaf-level components.
     */
    virtual void Add(Component *component);
    virtual void Remove(Component *component);

    /**
     * You can provide a method that lets the client code figure out whether a
     * component can bear children.
     */
    virtual bool IsComposite() const;

    /**
     * The base Component may implement some default behavior or leave it to
     * concrete classes (by declaring the method containing the behavior as
     * "abstract").
     */
    virtual std::string Operation() const = 0;
};