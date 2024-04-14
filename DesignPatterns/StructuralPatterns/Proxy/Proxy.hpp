#pragma once

#include "Subject.hpp"
#include "RealSubject.hpp"

/**
 * The Proxy has an interface identical to the RealSubject.
 */
class Proxy : public Subject
{
    /**
     * @var RealSubject
     */
private:
    RealSubject *real_subject_;

    bool CheckAccess() const;
    void LogAccess() const;

    /**
     * The Proxy maintains a reference to an object of the RealSubject class. It
     * can be either lazy-loaded or passed to the Proxy by the client.
     */
public:
    Proxy(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject))
    {
    }

    ~Proxy()
    {
        delete real_subject_;
    }
    /**
     * The most common applications of the Proxy pattern are lazy loading,
     * caching, controlling the access, logging, etc. A Proxy can perform one of
     * these things and then, depending on the result, pass the execution to the
     * same method in a linked RealSubject object.
     */
    void Request() const override;
};