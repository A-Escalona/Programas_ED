#include <stdio.h>
#define Max 64
#define Inf 1.0E12

double grafica[Max][Max];
int solucion[Max];
int camino[Max];
short int visitado[Max];
int N;
double L_min = Inf;
FILE *archivo;

void captura(int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
	   for (j = 0; j < n; j++)
	   {
	   	   fscanf(archivo,"%lf", &grafica[i][j]);
	   }
	   visitado[i] = 0;
	}
}

void copia(int a1[], int a2[])
{
	int i;
	for (i = 0; i < N; i++)
	    a1[i] = a2[i];
}

void imprime(int a[])
{
	int i;
	for (i = 0; i < N; i++)
	printf("%d ",a[i]);
}

void Viajero(int v, int i, double L)
{
	int u;
	double L1;
	
	visitado[v] = 1;    camino[i] = v;
	L1 = L + grafica[camino[i-1]][v];
	
	if (i == N-1)
	{
		L1 = L1 + grafica[v][camino[0]];
		imprime(camino);
		printf("Costo: %f\n",L1);
		if (L1 < L_min)
		{
			L_min = L1;
			copia(solucion,camino);
		}
	}
	else
	{
		for (u = 1;u < N; u++)
		   if (visitado[u] == 0)
		      Viajero(u, i+1, L1);
	}
	visitado[v] = 0;
}
	
int main()
{
	char nombre[15];
	int i;
	
	printf("Archivo: ");    scanf("%s",nombre);    
	archivo = fopen(nombre,"r");
	fscanf(archivo,"%d",&N);
	captura(N);
	
	camino[0] = 0;   visitado[0] = 1;
	for (i = 1; i < N; i++)
	    Viajero(i, 1, 0.0);
	printf("Solucion: ");
	imprime(solucion);
    printf("\n");
}

