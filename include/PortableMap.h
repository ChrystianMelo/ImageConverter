/**
 * @file PortableMap.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief  Abstração base para armazenar dados de arquivos graficos do tipo Portable Format (PGM).
 *         Read more : https://en.wikipedia.org/wiki/Netpbm#File_formats
 * @version 0.1
 * @date 2022-09-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef PORTABLE_MAP_H
#define PORTABLE_MAP_H

class PortableMap
{
protected:
    int **m_matrix;
    int m_lines;
    int m_columns;
    int m_maxValue;

public:
    /**
     * @brief Contrutor da classe.
     */
    PortableMap();

    /**
     * @brief Contrutor da classe.
     */
    PortableMap(int lines, int columns, int maxValue);

    /**
     * @brief Destrutor da classe.
     */
    ~PortableMap();

    const int getLines();

    const int getColumns();

    const int getMaxValue();
};

#endif