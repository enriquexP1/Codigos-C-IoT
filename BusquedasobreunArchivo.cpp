#include <stdio.h>
#include <algorithm>
//El programa a resolver es este https://omegaup.com/arena/problem/Busqueda-sobre-un-archivo-v2/#problems
// se utilizan las bibliotecas stdio y algorithm 
int B[4096];
int bloque[1024];
int posicionIni, posicionfinal;
int Q, N;
int cantidadDeBloques, cuantos;
int lineal(int* inicio, int* final, int valor){
 
    for(int* i = inicio; i != final; i++){
        if(*i == valor){
            return 1; 
        }
        
    }
    return 0 ;
}
int multibusqueda(int ai, int af, int *bi, int *bf)
{
   if (ai == af || bi == bf)
   {
      return 0;
   }
   else
   {
      int cantidad=0;
      int am = ai + (af - ai) / 2; //Aqui tenemos que delimitar los bloques 1
      int posicionlectura = (am * 4096);
      int res = 0;
     
     fseek(stdin, posicionIni + posicionlectura, SEEK_SET);

     cantidad=fread(&bloque[0], sizeof(int), 1024, stdin);

      
      //af = ftell(stdin) / 4;

      int primero = bloque[0];
      int ultimo = bloque[cantidad-1];
      int *izq = std::lower_bound(bi, bf, primero); //Esto nos delimita lo que vamos a buscar en B
      int *der = std::upper_bound(bi, bf, ultimo);
     int contador=der-izq;
     for (int i = 0; i < contador; i++)
     {
        //fwrite(&bloque[i], sizeof(int), 1 , stdout);
        int valor = *(izq+i);
        res += lineal(&bloque[0], &bloque[0] + cantidad, valor);
     }
     
      

      //bloque[0] = 0;
      
      res += multibusqueda(ai, am, bi, izq);
      
      res += multibusqueda(am +1, af, der, bf);
      //printf("llegamos banda");
      return res;
   }
}

int main()
{
   scanf("%d", &Q);
   getchar();
   scanf("%d", &N);
   getchar();
   fread(&B[0], sizeof(int), Q, stdin);
   getchar();
   posicionIni = ftell(stdin);
   cantidadDeBloques = (N / 1024);
   if((N%1024) == 0)
   {
      cantidadDeBloques= cantidadDeBloques;
   }
   else
   {
      cantidadDeBloques=cantidadDeBloques+1;
   }
   //printf("la cantidad de bloques es: %d \n", cantidadDeBloques);
   int ai = 0;
   int af = cantidadDeBloques;
   
   printf("%d",multibusqueda(ai, af, &B[0], &B[0] + Q ) );
}