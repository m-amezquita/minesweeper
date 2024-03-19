#pragma once

#include <util/dynamic_matrix.hpp>
#include <minesweeper/cell_type.hpp>

struct Grid
{
public:

    /// @param rows number of rows of the grid
    /// @param cols number of columns of the grid
    /// @param bomb_percentage percentage of bomb [10%, 90%]
    Grid(unsigned rows, unsigned cols, float bomb_percentage);

    /// @brief generate the bombs in the matrix
    /// @param row first player's touch row
    /// @param col first player's touch col
    void generate(unsigned row, unsigned col);

    /// @brief Returns true if generate method was called previously
    bool generated() const noexcept { return m_generated; };

    /// @brief Returns the real bomb count
    unsigned bomb_count() const noexcept;

    /// @brief Returns an specific cell
    CellType cell(unsigned row, unsigned col) const noexcept { return m_bomb_matrix[row][col]; }

private:
    DynamicMatrix<CellType> m_bomb_matrix;
    DynamicMatrix<bool> m_revealed_matrix;
    float m_bomb_percentage;
    bool m_generated { false };
};
