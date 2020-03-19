//universidad del valle de Guatemala
//Sistemas Operativos
//Alexis Fernando Hengstenberg Chocooj
//17699

//Librerias
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>


#include <unistd.h>

#include <fcntl.h>
#include <sys/types.h>


//definimos las finas y columnas
//sudocky 9*9
#define FILAS 9
#define COLUMNAS 9

//definimos la matris 
char sudoku[FILAS][COLUMNAS];

void  mapeado(int numero) 
{

    //variables
    int contador = 0;
    struct stat stat_s;
    int estado = fstat(numero, &stat_s); 
    int tama = stat_s.st_size;

    //leemos el archivo
    char *f = (char *) mmap(0, tama, LEER, MAPEADO, numero, 0);
    
    
    
    for(int x = 0; x < FILAS; x++)
    {

        for(int y = 0; y < COLUMNAS; y++)
        {
            
            sudoku[x][y] = f[contador];
            contador++;
        }
    }
}