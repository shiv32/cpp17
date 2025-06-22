#pragma once
#include <string_view>

class ChessPiece
{
    std::string_view piece{};

public:
    ChessPiece(std::string_view pi) : piece(pi) {};
    std::string_view getValue() { return piece; };
};