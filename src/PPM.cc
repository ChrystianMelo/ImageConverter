
#include <cassert>
#include <fstream>

#include "PPM.h"

namespace
{
    void printMatrix(RGB **matrix, int lines, int columns)
    {
        for (int i = 0; i < lines; i++)
            for (int j = 0; j < columns; j++)
            {
                std::cout << "Matrix[" << i << "][" << j << "]" << matrix[i][j].red << matrix[i][j].green << matrix[i][j].blue << std::endl;
            }
    }
}

PPM::PPM() : m_lines(0), m_columns(0), m_maxValue(0)
{
    // Cria a matrix.
    m_matrix = (RGB **)malloc(m_lines * sizeof(RGB *));
    for (int i = 0; i < m_lines; i++)
        m_matrix[i] = (RGB *)malloc(m_columns * sizeof(RGB));
}

PPM::~PPM()
{
    for (int i = 0; i < m_lines; i++)
        delete m_matrix[i];
    delete m_matrix;

    std::cout << "Mem is free" << std::endl;
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
    m_matrix = (RGB **)malloc(m_lines * sizeof(RGB *));
    for (int i = 0; i < m_lines; i++)
        m_matrix[i] = (RGB *)malloc(m_columns * sizeof(RGB));

    // Lê a matrix.
    std::string lines[m_lines];
    for (int i = 0; i < m_lines; i++)
        getline(myfile, lines[i]);

    // Preenche a matrix
    fillMatrix(lines);

    //printMatrix(m_matrix, m_lines, m_columns);

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
            int r = stoi(lineN.substr(0, pos));
            lineN = lineN.substr(pos + 1);

            pos = lineN.find(" ");
            int g = stoi(lineN.substr(0, pos));
            lineN = lineN.substr(pos + 1);

            pos = lineN.find(" ");
            int b = stoi(lineN.substr(0, pos));
            lineN = lineN.substr(pos + 1);

            m_matrix[i][j] = RGB(r, g, b);
        }
    }
}

const RGB &PPM::getRGB(int i, int j) { return m_matrix[i][j]; }

const int PPM::getLines() { return m_lines; }

const int PPM::getColumns() { return m_columns; }

const int PPM::getMaxValue() { return m_maxValue; }