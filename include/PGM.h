/**
 * @file PGM.h
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief  Abstração para armazenar dados de arquivos graficos do tipo Portable Graymap Format (PGM).
 *         Read more : https://en.wikipedia.org/wiki/Netpbm#File_formats
 * @version 0.1
 * @date 2022-09-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef PGM_H
#define PGM_H

#include "PPM.h"

/**
 * @brief Definicação da classe para armazenar dados de arquivos graficos do tipo PGM.
 *
 */
class PGM
{
private:
    /**
     * @brief Matriz com os dados da imagem.
     */
    int **m_matrix;

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

public:
    /**
     * @brief Contrutor da classe.
     */
    PGM();

    /**
     * @brief Contrutor da classe.
     */
    PGM(PPM &ppm);

    /**
     * @brief Destrutor da classe.
     */
    ~PGM();

    static std::string getDefaultExtension() { return ".pgm"; }

    /**
     * @brief Cria a imagem PGM a partir de uma PPM.
     *
     *
     * @param ppm Imagem do tipo PPM, usada como base.
     */
    void generatePGM(PPM &ppm);

    /**
     * @brief Escreve no arquivo as informações graficas armazenadas.
     *
     * @param file Arquivo especificados.
     */
    void writeFile(const fs::path &file);
};

#endif