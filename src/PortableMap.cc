
#include <iostream>

#include "PortableMap.h"

PortableMap::PortableMap() : m_lines(0), m_columns(0), m_maxValue(0)
{
    // Cria a matrix.
    m_matrix = (int **)malloc(m_lines * sizeof(int *));
    for (int i = 0; i < m_lines; i++)
        m_matrix[i] = (int *)malloc(m_columns * sizeof(int));
}

PortableMap::PortableMap(int lines, int columns, int maxValue)
{
    m_lines = lines;
    m_columns = columns;
    m_maxValue = maxValue;

    m_matrix = (int **)malloc(m_lines * sizeof(int *));
    for (int i = 0; i < m_lines; i++)
        m_matrix[i] = (int *)malloc(m_columns * sizeof(int));
}

PortableMap::~PortableMap()
{
    for (int i = 0; i < m_lines; i++)
        delete m_matrix[i];
    delete m_matrix;

    std::cout << "Mem is free" << std::endl;
}

const int PortableMap::getLines() { return m_lines; }

const int PortableMap::getColumns() { return m_columns; }

const int PortableMap::getMaxValue() { return m_maxValue; }