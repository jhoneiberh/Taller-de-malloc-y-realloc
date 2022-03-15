#include <stdlib.h>
#include <stdio.h>

#define RESERVAR_MAS 1

int main()
{
   //declaración de un el arreglo dinámico de enteros:
   int *edades;
   
   int tam_inicial = 5; //tamaño inicial
   int incremento = 0;

   
   //incremento de memoria (entero):
   

   //reserve un espacio en memoria inicial para 5 enteros:
   edades = (int *) malloc(tam_inicial * sizeof(int));
     
   int sel = RESERVAR_MAS;
   int aumento_reserva = 0;

   /**
   Codigo completo
   **/
   if(edades == NULL)
   {
      printf("Memoria no asignada\n");
      exit(0);
   }
   else
   {
      printf("\tAsignacion de memoria exitosa\n");

      /*
      Reasignacion de memoria
      */
      do
      {
         printf("\nDesea reservar más espacio?");
         scanf("%i",&sel);


         if(sel == RESERVAR_MAS)
         {
            printf("\nCuantos elementos desea agregar?");
            scanf("%i", &incremento);
         }
         else
         {
            exit(0);
         }

         // Reasignacion de memoria         
         edades = realloc(edades, incremento * sizeof(int));
         

         if(edades == NULL)
         {
            printf("\tNo se realizó la reasignacion de memoria\n");
            exit(0);
         }
         else
         {
            printf("\tReasignacion de memoria exitosa\n");
         }

      }while(sel == RESERVAR_MAS);
   }

   return 0;

}
