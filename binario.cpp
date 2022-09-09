    //Definições das funções
#include "binario.h"
#define OneByte 8

using namespace std;
//Recebe um valor e a posição de um bit e muda o estado para 1
//As alteraçoes binárias são feitas comecando com os bits de alta ordem
unsigned short set_bit_true(unsigned short valor, unsigned short posicao){
                                    // caso hipotético
    unsigned short mascara = 32768; //:= 1000.0000.0000.0000 mascara = (32768)DECIMAL
    mascara = mascara >> posicao;   // O 0001.0000.0000.0000 (se posição := 3 )
    valor = valor | mascara;        // R 1110.1111.1111.1111 valor = (61439)DECIMAL

    return valor;                   //:= 1111.1111.1111.1111 (65535)DECIMAL
}

//Recebe um valor e a posição de um bit e muda o estado para 0
unsigned short set_bit_false(unsigned short valor, unsigned short posicao){
                                     // caso hipotético
    unsigned short mascara = 32768;  //:= 1000.0000.0000.0000 mascara = (32768)DECIMAL
    mascara = ~(mascara >> posicao); // A 1110.1111.1111.1111 (se posição := 3 )
    valor = valor & mascara;         // N 1111.1111.1111.1111 valor = (65535)DECIMAL
                                     // D 1110.1111.1111.1111 valor = (61439)DECIMAL
    return valor;                    
}

//Recebe um valor e a posição de um bit e retorna o estado se 0 ou 1
unsigned short get_bit_state(unsigned short valor, unsigned short posicao){
                                    // caso hipotético
    unsigned short mascara = 32768; //:= 1000.0000.0000.0000 mascara = (32768)DECIMAL
    mascara = mascara >> posicao;   // A 0001.0000.0000.0000 (se posição := 3 )
                                    // N 1111.1111.1111.1111 valor = (65535)DECIMAL
    if (mascara & valor)            // D 0001.0000.0000.0000 valor = (4096)DECIMAL
        return true;
    else                
        return false;
    
    return false;
}

//Recebe 2 valores e faz uma operação AND entre os bits e retorna 
unsigned short And_bin(unsigned short valor1, unsigned short valor2){
   
    return valor1 & valor2;
    
}

//Recebe 2 valores e faz uma operação OR entre os bits e retorna 
unsigned short Or_bin(unsigned short valor1, unsigned short valor2){
    
    return valor1 | valor2;
}

//Recebe um número e retorna os bits de baixa ordem desse número
unsigned short Low_bits(unsigned short valor){
//caso hipotético para valor1A se:= 1111.1111.1111.1111
    valor = valor << OneByte; // := 1111.1111.0000.0000
    valor = valor >> OneByte; // := 0000.0000.1111.1111
    return valor;
}
//Recebe um número e retorna os bits de alta ordem desse número
unsigned short High_bits(unsigned short valor){
//caso hipotético para valor1A se:= 1111.1111.1111.1111   
    valor = valor >> OneByte; // := 0000.0000.1111.1111
    valor = valor << OneByte; // := 1111.1111.0000.0000
    return valor;
}
