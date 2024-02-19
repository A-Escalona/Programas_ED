#include <stdio.h>
#include <string.h>

struct alumno 
{    char matricula[10];
     char nombre[30];
     int calificacion;
};

void lee_alumno(struct alumno *a1)
{
     printf("Matricula ");   scanf("%s",a1->matricula);
     printf("Nombre ");   scanf("%s",a1->nombre);
     a1->calificacion = 0;
}

void escribe_alumno(struct alumno a1)
{
     printf("Matricula: %s ",a1.matricula);
     printf("Nombre: %s ",a1.nombre);
     printf("Calificacion: %d\n",a1.calificacion);
}

int busca(struct alumno L[], int n, char mat[])
{
    int i = 0;
    while ((strcmp(mat,L[i].matricula) != 0) && (i < n-1))
         i = i + 1;
    if (strcmp(mat,L[i].matricula) == 0)
       return i;
    else 
       return -1;
}     

main()
{
      struct alumno lista[30];
      int i,n, pos, resp;
      char mat[10];
      printf("Numero de alumnos: ");    scanf("%d",&n);
      for (i=0; i<n; i++)
          lee_alumno(&lista[i]);
      do     
      {    
           printf("Matricula a buscar: ");    scanf("%s",mat);    
           pos = busca(lista,n,mat);
           if (pos >= 0)
              escribe_alumno(lista[pos]);
           else 
              printf("Alumno no encontrado\n");
           printf("Tecle 0 para salir ");   scanf("%d",&resp);
      } while (resp != 0);
}
      
