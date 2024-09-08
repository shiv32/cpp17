/**
 * @file Build_array.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <array>
#include <type_traits>

class Build_array
{
public:
    Build_array() = default;
    ~Build_array() = default;

    template <typename... Args>
    auto build_array(Args &&...args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
    {
        using commonType = typename std::common_type<Args...>::type;

        return {std::forward<commonType>(args)...};
    }
};
