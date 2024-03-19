#pragma once

#include <cstdlib>
#include <vector>

template <typename value_type>
struct DynamicMatrix
{
public:
    /// @brief Create a matrix in heap memory, in a continuous space
    DynamicMatrix(unsigned rows, unsigned cols);

    value_type get(unsigned row, unsigned col) const noexcept;
    
    void set(unsigned row, unsigned col, value_type const &new_value) noexcept;

    value_type *operator[](unsigned row) noexcept;
    value_type const *operator[](unsigned row) const noexcept;

    unsigned rows() const noexcept { return m_rows; }
    unsigned cols() const noexcept { return m_cols; }

private:
    unsigned m_rows;
    unsigned m_cols;
    std::vector<value_type> m_data;
};

#ifndef _omit_dynamic_matrix_implementation_

template <typename value_type>
inline DynamicMatrix<value_type>::DynamicMatrix(unsigned rows, unsigned cols)
    : m_rows{rows}, m_cols{cols}
{
    unsigned data_size = rows * cols;
    m_data.resize(data_size);
}

template <typename value_type>
inline value_type DynamicMatrix<value_type>::get(unsigned row, unsigned col) const noexcept
{
    return this->operator[](row)[col];
}

template <typename value_type>
inline void DynamicMatrix<value_type>::set(unsigned row, unsigned col, value_type const &new_value) noexcept
{
    this->operator[](row)[col] = new_value;
}

template <typename value_type>
inline value_type *DynamicMatrix<value_type>::operator[](unsigned row) noexcept
{
    const value_type *row_ptr = const_cast<DynamicMatrix const *>(this)->operator[](row);
    return const_cast<value_type *>(row_ptr);
}

template <typename value_type>
inline value_type const *DynamicMatrix<value_type>::operator[](unsigned row) const noexcept
{
    return &m_data[row * m_cols];
}

#endif
