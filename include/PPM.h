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

#include "PortableMap.h"

namespace fs = std::filesystem;

class PPM : public PortableMap
{
private:
    void fillMatrix(std::string lines[]);

public:
    /**
     * @brief Construtor da classe
     */
    PPM();

    /**
     * @brief Desstrutor da classe
     */
    ~PPM() = default;

    /**
     * @brief Lê o arquivo com as informações graficas e armazena.
     *
     * @param file Arquivo com os dados especificados.
     */
    void readFile(const fs::path &file);
};

#endif