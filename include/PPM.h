/**
 * @file PPM.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief  Abstração para armazenar dados de arquivos graficos do tipo Portable Pixmap Format (PPM).
 *         Read more : https://en.wikipedia.org/wiki/Netpbm#File_formats
 * @version 0.1
 * @date 2022-09-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef PPM_H
#define PPM_H

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class RGB
{
public:
    int red;
    int green;
    int blue;

    RGB(int r, int g, int b) : red(r), green(g), blue(b) {}
};

class PPM
{
private:
    RGB **m_matrix;
    int m_lines;
    int m_columns;
    int m_maxValue;

    void fillMatrix(std::string lines[]);

public:
    /**
     * @brief Construtor da classe
     */
    PPM();

    /**
     * @brief Desstrutor da classe
     */
    ~PPM();

    /**
     * @brief Lê o arquivo com as informações graficas e armazena.
     *
     * @param file Arquivo com os dados especificados.
     */
    void readFile(const fs::path &file);

    const RGB &getRGB(int i, int j);

    const int getLines();

    const int getColumns();

    const int getMaxValue();
};
#endif