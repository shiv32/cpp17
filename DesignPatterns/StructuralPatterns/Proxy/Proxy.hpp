/**
 * @file Proxy.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include "Subject.hpp"
#include "RealSubject.hpp"
#include <memory>

/**
 * The Proxy has an interface identical to the RealSubject.
 */
class Proxy : public Subject
{
    /**
     * @var RealSubject
     */
private:
    //RealSubject *real_subject_;
    std::shared_ptr<RealSubject> real_subject_{};  //smart pointer

    bool CheckAccess() const;
    void LogAccess() const;

    /**
     * The Proxy maintains a reference to an object of the RealSubject class. It
     * can be either lazy-loaded or passed to the Proxy by the client.
     */
public:
    // Proxy(RealSubject *real_subject);
    Proxy(std::shared_ptr<RealSubject> real_subject); //smart pointer
    ~Proxy();

    /**
     * The most common applications of the Proxy pattern are lazy loading,
     * caching, controlling the access, logging, etc. A Proxy can perform one of
     * these things and then, depending on the result, pass the execution to the
     * same method in a linked RealSubject object.
     */
    void Request() const override;
};