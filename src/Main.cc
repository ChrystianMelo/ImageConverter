#include <iostream>
#include <cassert>
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
    assert(argc == 5);

    std::string inputFilename(argv[1]);
    assert(!inputFilename.empty());

    PPM ppm = PPM();
    ppm.readFile(inputFilename);

    std::string outputFilename(argv[2]);
    assert(!outputFilename.empty());

    PGM pgm = PGM(ppm);
    pgm.writeFile(outputFilename);

    std::string logFilename(argv[3]);
    assert(!logFilename.empty());

    std::string accessPattern(argv[4]);
    assert(!accessPattern.empty());

    return 0;
}