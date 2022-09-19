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
#include "memlog.h"

#include "PPM.h"
#include "PGM.h"

/**
 * @brief Le as opcoes da linha de comando e inicializa variaveis
 *
 * @param argv Argumentos passados na execução.
 * @param argc Quantidade de argumentos.
 */
void parse_args(char **argv, int argc, std::string *inputFilename, std::string *outputFilename, std::string *logFilename, bool *accessPattern)
{
    for (int i = 0; i < argc; i++)
    {
        std::string arg(argv[i]);

        if (arg.compare("-i") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
            std::string arg(argv[i + 1]);
            *inputFilename = arg;
            i++;
        }
        else if (arg.compare("-o") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
            std::string arg(argv[i + 1]);
            *outputFilename = arg;
            i++;
        }
        else if (arg.compare("-p") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
            std::string arg(argv[i + 1]);
            *logFilename = arg;
            i++;
        }
        else if (arg.compare("-l") == 0)
        {
            *accessPattern = true;
        }
    }
}

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
    // erroAssert(argc > 4, "Numero de argumentos minimo para execução não atingido.");

    // Processa os argumentos de entrada.
    std::string inputFilename;
    std::string outputFilename;
    std::string logFilename;
    bool accessPattern;

    // Le os argumentos de entrada do programa.
    parse_args(argv, argc, &inputFilename, &outputFilename, &logFilename, &accessPattern);

    // Trata possiveis erros com as entradas.
    erroAssert(!inputFilename.empty(), "O arquivo de entrada não é válido.");
    erroAssert(!outputFilename.empty(), "O arquivo de saida não é válido.");
    erroAssert(!logFilename.empty(), "O arquivo de log não é válido.");

    // Inicia o mem log.
    iniciaMemLog(logFilename.c_str());

    // Define o memlog de acordo com o padrão de acesso.
    if (accessPattern)
        ativaMemLog();
    else
        desativaMemLog();

    // Cria uma imagem vazia
    PPM ppm = PPM();

    // Lê o arquivo de entrada e preenche a imagem.
    ppm.readFile(inputFilename);

    // Cria uma imagem em tons de cinza a partir da imagem colorida.
    PGM pgm = PGM(ppm);

    // Escreve o resultado da conversão no arquivo desaida.
    pgm.writeFile(outputFilename);

    // conclui registro de acesso
    finalizaMemLog();

    return 0;
}