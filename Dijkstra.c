#include <stdio.h>
#include <math.h>
#define Max 64
#define Inf 1.0E12

double grafica[Max][Max];
double costo[Max];
int origen[Max];
short int visitado[Max];
FILE *archivo;


void captura(int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	   for (j = 0; j < n; j++)
	   {
	   	   fscanf(archivo,"%lf", &grafica[i][j]);
	   }
	
}

int minimo(int n)
{  int i,k;
   double min = Inf;
   
   for (i = 0; i < n; i++)
      if (visitado[i]==0 && costo[i] < min)
      {   min = costo[i];
          k = i;
      }
   return k;
}
     
void dijkstra(int v, int n)
{    int i,j,u;
     
     for (i = 0; i < n; i++)
     {   costo[i] = grafica[v][i];
         visitado[i] = 0;
         origen[i] = v;
     }
     costo[v] = 0.0;   visitado[v] = 1;    origen[v] = -1;
     
     for (i = 1; i < n; i++)
     {    u = minimo(n);
          visitado[u] = 1;
          for (j = 0; j < n; j++)
              if (visitado[j]==0 && costo[u]+grafica[u][j]<costo[j])
              {   origen[j] = u;
                  costo[j] = costo[u]+grafica[u][j];
              }
     }
}
          
main ()
{   int i,n,raiz;
    char nombre[80];
    
    printf("Archivo de datos: ");
    scanf("%s",nombre);
    archivo = fopen(nombre,"r");

    fscanf(archivo,"%d",&n);
    captura(n);
    fclose(archivo);
    printf("Vertice de raiz: ");   scanf("%d",&raiz); 
    
    dijkstra(raiz,n);
    for (i = 0; i < n; i++)
    if (i != raiz)
        printf("%d -> %d\t costo = %f\n",origen[i],i,costo[i]);
    else 
        printf("raiz->%d\n",i);    
     
}
                

