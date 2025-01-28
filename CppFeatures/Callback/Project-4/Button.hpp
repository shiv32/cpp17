/**
 * @file Button.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-01-28
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

template <typename Handler>
using PtrMem = void (Handler::*)();

template <typename Handler>
class Button
{
    // void (Handler::*m_pMem)();
    PtrMem<Handler> m_pMem;

    Handler *m_pObj;

public:
    Button(Handler *pObj, PtrMem<Handler> pMem) : m_pObj{pObj}, m_pMem{pMem}
    {
    }
    void GenerateEvent()
    {
        (m_pObj->*m_pMem)();
    }
};