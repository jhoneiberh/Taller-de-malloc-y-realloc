#include <stdlib.h>
#include <stdio.h>

#define RESERVAR_MAS 1


int main()
{
   // profe: int*  int_dyn_arr;
   //declaración de un el arreglo dinámico de enteros:
   int *edades = NULL;
   
   int tam_inicial = 5; //tamaño inicial
   int incremento;

   
   
   //incremento de memoria (entero):
   int entrada_numero;
   

   
   
   //reserve un espacio en memoria inicial para 5 enteros:
   edades = (int *) malloc(tam_inicial * sizeof(int));


     
   int sel = RESERVAR_MAS;
   int aumento_reserva = 0;
   do
   {
         printf("\nDesea reservar más espacio?");
		   scanf("%d",&sel);
		   if(sel == RESERVAR_MAS)
		   {
		      printf("\nCuantos elementos desea agregar?");
			   scanf("%d", &incremento);
		   }
		   
		   //reasignar memoria:
		   //int_mem_block = realloc(int_mem_block, nuevoTamanio); 
         edades = realloc(edades, incremento); 
		   
   
   }while(sel == RESERVAR_MAS);

   return 0;

}
