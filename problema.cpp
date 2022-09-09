/*Data 06/julho/2022
Sobre esta aplicação:
Problema da mochila: resolvendo com técnicas de algoritmos genéticos
Autor: Flebersom Bezerra.
Aluno da FATEC de Ribeirão Preto, 1* semestre, ADS.

Sobre este trabalho: acesse o link para a descrição completa.
https://github.com/JudsonSS/ProgComp/blob/master/Trabalhos/TP1.pdf

Trabalho prático I do curso de ciências da computação
Elaborado por: Prof. Judson Santos Santiago - UFERSA
https://github.com/JudsonSS

Disponibilizado no curso de programaçao de computadores (C++) no youtube: 
https://youtube.com/playlist?list=PLX6Nyaq0ebfgWfHqVHVAEPCDG54RLArJh
*/

#include <iostream>
#include "genetico.h"
#include "binario.h"

//definindo as cores para serem usadas na saída do texto
#define padrao "\033[m" //texto cinza fundo preto
#define verde cout << "\033[32m" << "OK\n" << padrao   // Ok verde
#define vermelho cout << "\033[31m" << "X\n" << padrao // X vermelho


using namespace std;

int main(){

//posições dos bits a serem alterados exigidas no exercício
//G para mutação simples | D e M para mutação dupla
const unsigned short G=6,D=3,M=12;

//variáveis das soluções recebidas do usuário
unsigned short sol1,sol2,sol3,sol4,sol5,sol6; 

    cout << "\nEntre com 6 Solucoes iniciais (numeros entre 0 e 65535):\n";
    
    cin >> sol1 >> sol2 >> sol3 >> sol4 >> sol5 >> sol6;

    cout << "Resultado da Avaliacao\n";
    cout << "-----------------------\n";
    
    if (avaliacao(sol1)) verde;
    else vermelho;

    if (avaliacao(sol2)) verde;
    else vermelho;

    if (avaliacao(sol3)) verde;
    else vermelho;

    if (avaliacao(sol4)) verde;
    else vermelho;

    if (avaliacao(sol5)) verde;
    else vermelho;

    if (avaliacao(sol6)) verde;
    else vermelho;

    //Gerando novas soluções a partir das recebidas pelo usuário
    cout << "-----------------------\n";

    if (avaliacao(cruzamento_pt_unico(sol1,sol2))) verde;
    else vermelho;

    if (avaliacao(cruzamento_aritmetico(sol3,sol4))) verde;
    else vermelho;

    if (avaliacao(mutacao_simples(sol5,G))) verde;
    else vermelho;

    if (avaliacao(mutacao_dupla(sol6,D,M))) verde;
    else vermelho;

    cout << "\n\n";

return 0;

}

