/**
 * @file Main.cc
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe principal do projeto.
 * @version 0.1
 * @date 2022-09-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

#include "msgassert.h"

#include "PPM.h"
#include "PGM.h"

/**
 * @brief Main
 *
 * @param argc
 * @param argv
 *      -i "nome do arquivo de entrada" (entrada em formato .ppm)
 *      -o "nome do arquivo de saída" (saída em formato .pgm)
 *      -p log.out (registro de desempenho)
 *      -l (padrão de acesso e localidade)
 * @return ** int
 */
int main(int argc, char *argv[])
{
    // Por padrão, se espera 4 entradas.
    erroAssert(argc > 2, "Numero de argumentos minimo para execução não atingido.");

    fs::path inputFilename(argv[1]);
    erroAssert(fs::exists(inputFilename), "O arquivo de entrada não é válido.");

    PPM ppm = PPM();
    ppm.readFile(inputFilename);

    fs::path outputFilename(argv[2]);
    erroAssert(!outputFilename.empty(), "O arquivo de entrada não é válido.");

    PGM pgm = PGM(ppm);
    pgm.writeFile(outputFilename);

    std::string logFilename(argv[3]);

    std::string accessPattern(argv[4]);

    return 0;
}