#include "gameboard.hpp"

GameBoard::GameBoard(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;

    mCells.resize(mWidth);

    for (auto &column : mCells)
    {
        column.resize(mHeight);
    }
}

GameBoard::GameBoard(const GameBoard &src)
    : GameBoard(src.mWidth, src.mHeight)
{
    // The ctor-initializer of this constructor delegates first to the
    // non-copy constructor to allocate the proper amount of memory.
    // The next step is to copy the data.
    for (size_t i = 0; i < mWidth; i++)
    {
        for (size_t j = 0; j < mHeight; j++)
        {
            if (src.mCells[i][j])
                mCells[i][j] = src.mCells[i][j]->clone();
        }
    }
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight)
    {
        throw std::out_of_range("");
    }
}

void swap(GameBoard &first, GameBoard &second) noexcept
{
    using std::swap;
    swap(first.mWidth, second.mWidth);
    swap(first.mHeight, second.mHeight);
    swap(first.mCells, second.mCells);
}

GameBoard &GameBoard::operator=(const GameBoard &rhs)
{
    // Check for self-assignment
    if (this == &rhs)
    {
        return *this;
    }
    
    // Copy-and-swap idiom
    GameBoard temp(rhs); // Do all the work in a temporary instance

    swap(*this, temp);   // Commit the work with only non-throwing operations

    return *this;
}

const std::unique_ptr<GamePiece> &GameBoard::at(size_t x, size_t y) const
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;

    verifyCoordinate(x, y);
    return mCells[x][y];
}

std::unique_ptr<GamePiece> &GameBoard::at(size_t x, size_t y)
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;

    return const_cast<std::unique_ptr<GamePiece> &>(std::as_const(*this).at(x, y));
}