#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Tarea
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} Tarea;
typedef struct Nodo
{
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;
int main()
{
    return 0;
}
Nodo *crearLista()
{
    return NULL;
}
Nodo *crearNodo(int tareaID, char descripcion[], int *duracion)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->T.TareaID = tareaID;
    aux->T.Descripcion = (char *)malloc(sizeof(char) * (strlen(descripcion) + 1));
    strcpy(aux->T.Descripcion, descripcion);
    aux->T.Duracion = *duracion;
    (*duracion)++;
    return aux;
}