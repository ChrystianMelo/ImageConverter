
#include <cassert>
#include <fstream>

#include "PPM.h"

namespace
{
    void printMatrix(int **matrix, int lines, int columns)
    {
        for (int i = 0; i < lines; i++)
            for (int j = 0; j < columns; j++)
            {
                std::cout << "Matrix[" << i << "][" << j << "]" << matrix[i][j] << std::endl;
            }
    }
}

PPM::PPM() : PortableMap()
{
}

void PPM::readFile(const fs::path &file)
{
    assert(fs::exists(file));

    // Lê o arquivo.
    std::ifstream myfile(file);
    assert(myfile.is_open());

    // Lê o formato do arquivo de entrada.
    std::string format("");
    getline(myfile, format);
    assert(format.compare("P3") == 0);

    // Lê as configurações da matrix.
    std::string matrixConfigration("");
    getline(myfile, matrixConfigration);
    std::size_t pos = matrixConfigration.find(" ");
    m_columns = stoi(matrixConfigration.substr(0, pos));
    m_lines = stoi(matrixConfigration.substr(pos + 1));

    // Lê o valor maximo para cada cor.
    std::string maxValue("");
    getline(myfile, maxValue);
    m_maxValue = stoi(maxValue);

    // Cria a matrix.
    m_matrix = (int **)malloc(m_lines * sizeof(int *));
    for (int i = 0; i < m_lines; i++)
        m_matrix[i] = (int *)malloc(m_columns * sizeof(int));

    // Lê a matrix.
    std::string lines[m_lines];
    for (int i = 0; i < m_lines; i++)
        getline(myfile, lines[i]);

    // Preenche a matrix
    fillMatrix(lines);

    printMatrix(m_matrix, m_lines, m_columns);

    // Finaliza a leitura do arquivo.
    myfile.close();
}
void PPM::fillMatrix(std::string lines[])
{
    for (int i = 0; i < m_lines; i++)
    {
        std::string lineN(lines[i]);

        for (int j = 0; j < m_columns; j++)
        {
            std::size_t pos = lineN.find(" ");
            m_matrix[i][j] = stoi(lineN.substr(0, pos));
            lineN = lineN.substr(pos + 1);
        }
    }
}
