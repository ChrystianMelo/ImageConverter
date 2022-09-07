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

/**
 * @brief Classe representando as propriedades de cor do pixel.
 */
class RGB
{
public:
    int red;
    int green;
    int blue;

    RGB(int r, int g, int b) : red(r), green(g), blue(b) {}
};

/**
 * @brief Definicação da classe para armazenar dados de arquivos graficos do tipo PPF.
 */
class PPM
{

private:
    /**
     * @brief Matriz com os dados da imagem.
     */
    RGB **m_matrix;

    /**
     * @brief Quantidade de linhas da matriz da imagem.
     */
    int m_lines;

    /**
     * @brief Quantidade de colunas da matriz da imagem.
     */
    int m_columns;

    /**
     * @brief Valor maximo presente na matrix. Os valores são sempre positivos e vairam entre 0 e m_maxValue
     */
    int m_maxValue;

    /**
     * @brief Preenche os valores da matriz com base nas linhas lidas do arquivo.
     *
     * @param lines Linhas do arquivo.
     */
    void fillMatrix(std::string lines[]);

public:
    /**
     * @brief Construtor da classe
     */
    PPM();

    /**
     * @brief Destrutor da classe
     */
    ~PPM();

    /**
     * @brief Lê o arquivo com as informações graficas e armazena.
     *
     * @param file Arquivo com os dados especificados.
     */
    void readFile(const fs::path &file);

    /**
     * @brief Recupera o valor RGB presente na posição especificada.
     *
     * @param i Indice da linha
     * @param j Indice da coluna
     *
     * @return Retorna o valor RGB presente na matrix.
     */
    const RGB &getRGB(int i, int j);

    /**
     * @brief Retorna a quantidade de linhas da matriz.
     */
    const int getLines();

    /**
     * @brief Retorna a quantidade de colunas da matriz.
     */
    const int getColumns();

    /**
     * @brief Retorna o valor máximo da matriz.
     */
    const int getMaxValue();
};
#endif