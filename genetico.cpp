//Definições das funções
#include <iostream> 
#include <iomanip>
#include "genetico.h"
#include "binario.h"

using namespace std;

//Recebe dois números, separa os 8 bits de alta ordem do primeiro
//e separa os 8 bits de baixa ordem do segundo e os uni criando um novo valor
//e retorna.
unsigned short cruzamento_pt_unico(unsigned short num_gen1, unsigned short num_gen2){
    
    return Or_bin(High_bits(num_gen1), Low_bits(num_gen2));
    
    return num_gen1;
}

//Recebe dois números faz uma operaçao AND binário com os números e retorna
//um novo número.
unsigned short cruzamento_aritmetico(unsigned short num_gen1, unsigned short num_gen2){

    return And_bin(num_gen1, num_gen2);

}

//Recebe um número e uma posição ao qual deve ser aplicado a mudança do bit se
// 0 para 1 e se for 1 para 0.
unsigned short mutacao_simples(unsigned short num_gen1, unsigned short posicao_mutacao){

    return (get_bit_state(num_gen1,posicao_mutacao)) ? set_bit_false(num_gen1 ,posicao_mutacao) : set_bit_true(num_gen1, posicao_mutacao); 

}

//Recebe um número e duas posições de bits e faz as alteraçoes binárias nas posições indicadas 
unsigned short mutacao_dupla(unsigned short num_gen1, unsigned short posicao_mutacao1,unsigned short posicao_mutacao2){
   
    //primeira mutacao sendo aplicada
    if (get_bit_state(num_gen1,posicao_mutacao1))
        num_gen1 = set_bit_false(num_gen1,posicao_mutacao1);
    else
        num_gen1 = set_bit_true(num_gen1,posicao_mutacao1);

    //seugunda mutacao sendo aplicada
    if (get_bit_state(num_gen1,posicao_mutacao2))
        num_gen1 = set_bit_false(num_gen1,posicao_mutacao2);
    else
        num_gen1 = set_bit_true(num_gen1,posicao_mutacao2);
    
return num_gen1;

}

//avalia o resultado das manipulaçoes binárias

bool avaliacao(unsigned short num){

unsigned short valor=0, peso=0;

    if (get_bit_state(num,0)){
        peso += 12;
        valor += 4;
        
    };
    
    if (get_bit_state(num,1)){
        peso += 3;
        valor += 4;
        
    };

    if (get_bit_state(num,2)){
        peso += 5;
        valor += 8;
        
    };

    if (get_bit_state(num,3)){
        peso += 4;
        valor += 10;
        
    };

    if (get_bit_state(num,4)){
        peso += 9;
        valor += 15;
        
    };

    if (get_bit_state(num,5)){
        peso += 1;
        valor += 3;
        
    };

    if (get_bit_state(num,6)){
        peso += 2;
        valor += 1;
        
    };

    if (get_bit_state(num,7)){
        peso += 3;
        valor += 1;
        
    };

    if (get_bit_state(num,8)){
        peso += 4;
        valor += 2;
        
    };

    if (get_bit_state(num,9)){
        peso += 1;
        valor += 10;
        
    };

    if (get_bit_state(num,10)){
        peso += 2;
        valor += 20;
        
    };

    if (get_bit_state(num,11)){
        peso += 4;
        valor += 15;
        
    };

    if (get_bit_state(num,12)){
        peso += 5;
        valor += 10;
        
    };


    if (get_bit_state(num,13)){
        peso += 2;
        valor += 3;
        
    };


    if (get_bit_state(num,14)){
        peso += 4;
        valor += 4;
        
    };

    if (get_bit_state(num,15)){
        peso += 1;
        valor += 12;
    };
       
    cout << setw(5) << right << num << " - " << "$" << setw(3) << left << valor << " - " << setw(2) << right << peso << "Kg - ";

    if (peso <= 20)
        return true;


return false;

}
