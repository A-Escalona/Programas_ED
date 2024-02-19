#include <stdio.h>
#define Max 64
#define Inf 1000

int costo[Max], origen[Max];
int W[Max][Max];
short int visitado[Max];
FILE *archivo;

     

int Lectura()
{   int j,n, i=0;
    
    fscanf(archivo,"%d",&n);
	for (i = 0; i < n; i++)
    {   for (j = 0; j < n; j++)
        fscanf(archivo,"%d",&W[i][j]);
    }
    return n;
}

int minimo(int n)
{
	 
	int i,k, min;
    
	min = Inf;   
   for (i = 1; i < n; i++)
      if (visitado[i]==0 && costo[i] < min)
      {   min = costo[i];
          k = i;
      }
/*    printf("%d %d\n",k, costo[k]);   */

   return k;
}
     
void Prim(int n)
{    int i,j,u;

     for (i = 1; i < n; i++)
     {   costo[i] = W[0][i];
         /* printf("%d \n",costo[i]);*/
         visitado[i] = 0;
         origen[i] = 0;
     }
     
     costo[0] = 0;   visitado[0] = 1;    origen[0] = -1;
     
     for (i = 1; i < n; i++)
     {    u = minimo(n);
          visitado[u] = 1;
          for (j = 0; j < n; j++)
          {
              if (visitado[j]==0 && W[u][j]<costo[j])
              {   origen[j] = u;
                  costo[j] = W[u][j];
              }
          /*    printf("%d %d %d %d\n",u,j,origen[j],costo[j]);   */
          }
     }
}
          
main ()
{   int i,j,n;
    char nombre_d[80];
    
    printf("Archivo de datos: ");
    scanf("%s",nombre_d);
    archivo = fopen(nombre_d,"r");
    
	n = Lectura();   
    fclose(archivo);
    
    Prim(n);
    for (j = 1; j < n; j++)   
    {   
        printf("%d %d\n",j,origen[j]);
    }
}
