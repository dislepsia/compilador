#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura de la SymbolTable
typedef struct symbol {
    char nombre[50];
    char tipo[10];
    char valor[100];
    char alias[50];
    int longitud;
    int limite;
} symbol;

void SymbolTableToExcel(symbol table[],char * ruta)
{
//Declaracion de variables
int i = 0;
//Definicion del archivo de salida y su cabecera
FILE  *ptr = fopen(ruta, "w");
fprintf (ptr,"nombre,tipo,valor,alias,longitud,limite\n");
//Recorrido de la symbol table, corta con el caracter @
while(strncmp(table[i].nombre,"@",1)!=0)
{
    fprintf(ptr, "%s,%s,%s,%s,%d,%d\n",table[i].nombre,table[i].tipo,table[i].valor,table[i].alias,table[i].longitud,table[i].limite);    
    i++;
}
//Fin
fclose(ptr);
}

//Test
int main()
{
symbol symbolTable[10] = {
                        {"uno","b","c","d",5,6}, 
                        {"dos","f","g","h",5,6},
                        {"(","b","c","d",5,6}, 
                        {"{","b","c","d",5,6}, 
                        {"2","f","g","h",5,6},
                        {"@","b","c","d",5,6}, 
                        {"$%^&*","f","g","h",5,6},
                        {":","b","c","d",5,6}, 
                        {"<8","f","g","h",5,6},
                        {".","b","c","d",5,6}
                        };

SymbolTableToExcel(symbolTable,"C:\\salida.csv");
}
