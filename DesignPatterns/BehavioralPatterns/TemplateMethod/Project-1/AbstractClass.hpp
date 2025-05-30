#pragma once

#pragma once

class AbstractClass
{
    /**
     * The template method defines the skeleton of an algorithm.
     */
public:
    void TemplateMethod() const;
    
protected:
    void BaseOperation1() const;
    void BaseOperation2() const;
    void BaseOperation3() const;
 
    /**
     * These operations have to be implemented in subclasses.
     */
    virtual void RequiredOperations1() const = 0;
    virtual void RequiredOperation2() const = 0;

    /**
     * These are "hooks." Subclasses may override them, but it's not mandatory
     * since the hooks already have default (but empty) implementation. Hooks
     * provide additional extension points in some crucial places of the
     * algorithm.
     */
    virtual void Hook1() const;
    virtual void Hook2() const;
};
