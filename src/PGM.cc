#include "PGM.h"
#include <fstream>

PGM::PGM() : PortableMap()
{
}

PGM::PGM(PPM &ppm) : PortableMap(ppm.getLines(), ppm.getColumns(), ppm.getMaxValue())
{
}
/**
 * @brief Calcula o tom de cinza da imagem.
 *      𝑌 = (49/255) *(0.30R + 0.59G + 0.11B)
 * @return ** double
 */
double calculateGrayTons(double r, double g, double b)
{
    return (49 / 255) * ((0.3 * r) + (0.59 * g) + (0.11 * b));
}

void PGM::generatePGM(const PPM &ppm)
{
    for (int i = 0; i < m_lines; i++)
        for (int j = 0; j < m_columns; j++)
            m_matrix[i][j] = calculateGrayTons(0,0,0);
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
        myfile << m_maxValue << std::endl;
    }

    myfile.close();
}