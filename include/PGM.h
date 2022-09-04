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

#include "PortableMap.h"
#include "PPM.h"

class PGM : public PortableMap
{
public:
    /**
     * @brief Contrutor da classe.
     */
    PGM();

    /**
     * @brief Contrutor da classe.
     */
    PGM(PPM& ppm);

    /**
     * @brief Destrutor da classe.
     */
    ~PGM() = default;

    /**
     * @brief Cria a imagem PGM a partir de uma PPM.
     *
     *
     * @param ppm Imagem do tipo PPM, usada como base.
     */
    void generatePGM(const PPM &ppm);

    /**
     * @brief Escreve no arquivo as informações graficas armazenadas.
     *
     * @param file Arquivo especificados.
     */
    void writeFile(const fs::path &file);
};

#endif