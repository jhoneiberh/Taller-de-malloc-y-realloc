#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#define RESERVAR_MAS 1
#define TAM_INICIAL 5

void solo_realloc();
void realloc_y_memset();

int main()
{
   //declaración de un el arreglo dinámico de enteros:
   int *edades;
   
    //tamaño inicial
   int incremento = 0;   

   //reserve un espacio en memoria inicial para 5 enteros:
   edades = (int *) malloc(TAM_INICIAL * sizeof(int));
     
   int sel = RESERVAR_MAS;

   if(edades == NULL)
   {
      printf("Memoria no asignada\n");
      exit(0);
   }
   else
   {
      printf("\tAsignacion de memoria exitosa\n");

      /*
         Escoger procedimiento a llevar a cabo
      */
      //solo_realloc();
      realloc_y_memset();
   }

   return 0;
}

/*
   Funcion que solo se encarga de aumentar o disminuir memoria sin rellenar datos
*/
void solo_realloc(int sel, int incremento, int *edades)
{
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

/*
   Funcion que permite aumentar la memoria ademas de rellenar el arreglo con datos usando memset
*/
void realloc_y_memset(int sel, int incremento, int *edades)
{
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

         // Asignacion de valores
         wmemset(edades, 1, incremento);

         // Imprimiendo valores
         printf("\tLos nuevos numeros del arreglo son: \n");
         for(int i = 0; i < incremento; i++)
         {
            printf("El numero %i es: %i\n", i, edades[i]);
         }

      }

   }while(sel == RESERVAR_MAS);

}