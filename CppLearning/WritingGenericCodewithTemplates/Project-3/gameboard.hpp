#pragma once

#include "gamepiece.hpp"
#include <memory>
#include <vector>
#include <iostream>

class GameBoard
{
public:
    explicit GameBoard(size_t width = kDefaultWidth,
                       size_t height = kDefaultHeight);

    GameBoard(const GameBoard &src);            // copy constructor
    GameBoard &operator=(const GameBoard &rhs); // assignment operator

    // Explicitly default a move constructor and assignment operator.
    GameBoard(GameBoard &&src) = default;
    GameBoard &operator=(GameBoard &&src) = default;

    virtual ~GameBoard() = default; // virtual defaulted destructor

    std::unique_ptr<GamePiece> &at(size_t x, size_t y);
    const std::unique_ptr<GamePiece> &at(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

    friend void swap(GameBoard &first, GameBoard &second) noexcept;

private:
    void verifyCoordinate(size_t x, size_t y) const;
    std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
    size_t mWidth, mHeight;
};