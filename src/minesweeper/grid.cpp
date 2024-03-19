#include "grid.hpp"
#include <algorithm>
#include <cassert>
#include <ctime>
#include <cstdlib>

Grid::Grid(unsigned rows, unsigned cols, float bomb_percentage)
    : m_bomb_matrix{rows, cols}, m_revealed_matrix{rows, cols}, m_bomb_percentage{bomb_percentage}
{
    assert(bomb_percentage >= 10.0);
    assert(bomb_percentage <= 90.0);
}

void Grid::generate(unsigned row, unsigned col)
{
    assert(!m_generated);

    srand(time(NULL));
    unsigned number_of_cells = m_bomb_matrix.cols() * m_bomb_matrix.rows();
    unsigned number_of_bombs = std::clamp(unsigned(number_of_cells * m_bomb_percentage / 100.0f), 1u, number_of_cells - 1);

    unsigned remaining_cells = number_of_cells - 1;
    unsigned remaining_bombs = number_of_bombs;

    for (unsigned i = 0; i < m_bomb_matrix.rows(); i++)
    {
        for (unsigned j = 0; j < m_bomb_matrix.cols(); j++)
        {
            if (i == row && j == col)
                continue;

            float prob_bomb = float(remaining_bombs) / remaining_cells;
            float random_float = float(rand()) / RAND_MAX;

            if (random_float < prob_bomb)
            {
                m_bomb_matrix.set(i, j, CellType::bomb);
                remaining_bombs--;
            }

            remaining_cells--;
        }
    }

    m_generated = true;
}

unsigned Grid::bomb_count() const noexcept
{
    unsigned bomb_counter = 0;
    for (unsigned i = 0; i < m_bomb_matrix.rows(); i++)
    {
        for (unsigned j = 0; j < m_bomb_matrix.cols(); j++)
        {
            if (m_bomb_matrix.get(i, j) == CellType::bomb)
            {
                bomb_counter++;
            }
        }
    }
    return bomb_counter;
}
