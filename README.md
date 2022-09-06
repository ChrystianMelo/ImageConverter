# ImageConverter

Estrutura de Dados - DCC/UFMG

Este trabalho prático tem por objetivo recordar alguns conceitos fundamentais do
desenvolvimento de programas em linguagem C/C++, além de introduzir outros conceitos em
termos de tipos abstratos de dados, em particular a sua abstração, desempenho e robustez.
Você implementará um programa para conversão de uma imagem colorida para tons de cinza.
Uma imagem digital em tons de cinza é uma imagem na qual o valor de cada pixel é uma
amostra de um espaço de cores. Imagens desse tipo são tipicamente compostas por diversos tons
de cinza, variando entre o preto como a menor intensidade e o branco como maior intensidade.
Imagens em tons de cinza são geralmente resultado de um cálculo da intensidade da luz em cada
pixel em cada faixa do espectro electromagnético (como, por exemplo, o espectro visível).

A formula usada para conversão de valores RGB para tons de cinza foi 
𝑌 = (49 / 255) * (0.30R + 0.59G + 0.11B)
