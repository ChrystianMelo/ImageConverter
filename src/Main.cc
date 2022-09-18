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

/*
void parse_args(int argc,char ** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optx, opty, regmem, lognome
{
     // variaveis externas do getopt
     extern char * optarg;
     extern int optind;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     opescolhida = -1;
     optx = -1;
     opty = -1;
     regmem = 0;
     lognome[0] = 0;
     outnome[0] = 0;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "smtc:p:x:y:lh")) != EOF)
       switch(c) {
         case 'm':
          avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
              opescolhida = OPMULTIPLICAR;
                  break;
         case 's':
          avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
              opescolhida = OPSOMAR;
                  break;
         case 't':
          avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
              opescolhida = OPTRANSPOR;
                  break;
         case 'c':
          avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
              opescolhida = OPCRIAR;
              strcpy(outnome,optarg);
                  break;
         case 'p':
              strcpy(lognome,optarg);
          break;
         case 'x':
              optx = atoi(optarg);
          break;
         case 'y':
              opty = atoi(optarg);
          break;
         case 'l':
              regmem = 1;
          break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
       // verificacao da consistencia das opcoes
       erroAssert(opescolhida>0,"matop - necessario escolher operacao");
       erroAssert(strlen(lognome)>0,
         "matop - nome de arquivo de registro de acesso tem que ser definido");
       erroAssert(optx>0,"matop - dimensao X da matriz tem que ser positiva");
       erroAssert(opty>0,"matop - dimensao Y da matriz tem que ser positiva");
       if (opescolhida==OPCRIAR){
         erroAssert(strlen(outnome)>0, "matop - nome de arquivo de saida tem que ser definido");
       }
}
*/

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
    erroAssert(argc > 5, "Numero de argumentos minimo para execução não atingido.");

    // Processa os argumentos de entrada.
    fs::path inputFilename(argv[1]);
    fs::path outputFilename(argv[2]);
    fs::path logFilename(argv[3]);
    std::string accessPattern(argv[4]);

    // Trata possiveis erros com as entradas.
    erroAssert(fs::exists(inputFilename) || inputFilename.extension() == PPM::getDefaultExtension(), "O arquivo de entrada não é válido.");
    erroAssert(!outputFilename.empty() || outputFilename.extension() == PGM::getDefaultExtension(), "O arquivo de entrada não é válido.");
    erroAssert(!logFilename.empty(), "O arquivo de log não é válido.");
    erroAssert(!accessPattern.empty(), "O padrão de memoria não foi informado.");

    // Inicia o mem log.
    iniciaMemLog(logFilename.c_str());

    // Define o memlog de acordo com o padrão de acesso.
    if (stoi(accessPattern) == 1)
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