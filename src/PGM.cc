#include "PGM.h"
#include <fstream>
#include <cassert>

PGM::PGM() : m_lines(0), m_columns(0), m_maxValue(0)
{
    // Cria a matrix.
    m_matrix = (int **)malloc(m_lines * sizeof(int *));
    for (int i = 0; i < m_lines; i++)
        m_matrix[i] = (int *)malloc(m_columns * sizeof(int));
}

PGM::PGM(PPM &ppm) : m_lines(ppm.getLines()), m_columns(ppm.getColumns()), m_maxValue(ppm.getMaxValue())
{
    // Cria a matrix.
    m_matrix = (int **)malloc(m_lines * sizeof(int *));
    for (int i = 0; i < m_lines; i++)
        m_matrix[i] = (int *)malloc(m_columns * sizeof(int));

    generatePGM(ppm);
}

PGM::~PGM()
{
    for (int i = 0; i < m_lines; i++)
        delete m_matrix[i];
    delete m_matrix;

    std::cout << "Mem is free" << std::endl;
}

/**
 * @brief Calcula o tom de cinza da imagem.
 *      𝑌 = (49/255) *(0.30R + 0.59G + 0.11B)
 * @return ** double
 */
float calculateGrayTons(double r, double g, double b)
{
    return float(49.0f / 255.0f) * ((0.3f * r) + (0.59f * g) + (0.11f * b));
}

void PGM::generatePGM(PPM &ppm)
{
    for (int i = 0; i < m_lines; i++)
        for (int j = 0; j < m_columns; j++)
        {
            RGB rgb = ppm.getRGB(i, j);

            m_matrix[i][j] = calculateGrayTons(rgb.red, rgb.green, rgb.blue);
        }
}

void PGM::writeFile(const fs::path &file)
{
    std::ofstream myfile;
    myfile.open(file);

    // Formato do arquivo de saída.
    myfile << "P2" << std::endl;

    // Formato da matrix.
    myfile << m_columns << " " << m_lines << std::endl;

    // Escreve o valor maximo.
    myfile << m_maxValue << std::endl;

    // Escreve a matrix.
    for (int i = 0; i < m_lines; i++)
    {
        for (int j = 0; j < m_columns; j++)
        {
            myfile << m_matrix[i][j];

            // Se não for o último valor, adiciona um espaço entre os valores.
            if (j + 1 < m_columns)
                myfile << " ";
        }

        // Fim da linha.
        myfile << std::endl;
    }

    myfile.close();
}
