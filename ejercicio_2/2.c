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
Nodo *crearLista();
Nodo *crearNodo(int duracion, char descripcion[], int *tareaID);
void InsertarNodo(Nodo **cabeza, Nodo *nodo);
void mostrar(Nodo *l);
Nodo *quitarNodo(Nodo **r, int dato);
int main()
{
    Nodo *listaPendiente = crearLista();
    Nodo *listaRealizada = crearLista();
    int nueva = 0, duracion, tareaID = 1000, dato = 0;
    char buff[60];
    while (nueva == 0)
    {
        printf("\nIngrese la tarea a realizar: ");
        gets(buff);

        duracion = 10 + rand() % 91;
        Nodo *aux = crearNodo(duracion, buff, &tareaID);
        InsertarNodo(&listaPendiente, aux);
        printf("\nPara ingresar una nueva tarea precione 0 para finalizar 1: ");
        scanf("%d", &nueva);
        getchar();
    }
    nueva = 0;
    while (nueva == 0)
    {
        mostrar(listaPendiente);
        printf("\nIngrese el id de la tarea que se completo:  ");
        scanf("%d", &dato);
        Nodo *r = quitarNodo(&listaPendiente, dato);
        InsertarNodo(&listaRealizada, r);
        if (r != NULL)
        {
            printf("\nTarea %s realizada", r->T.Descripcion);
        }
        else
        {
            printf("\nNo se encontro la tarea solicitada");
        }

        printf("\nPara marcar como realizada otra tarea precione 0 para finalizar 1: ");
        scanf("%d", &nueva);
    }
    printf("Lista de tareas realizadas");
    mostrar(listaRealizada);
    printf("\nLista de tareas aun no realizadas");
    mostrar(listaPendiente);
    nueva=0;
    
    return 0;
}
Nodo *quitarNodo(Nodo **r, int dato)
{
    Nodo *nodoAux = *r;
    Nodo *Auxant = NULL;
    while (nodoAux != NULL && dato != nodoAux->T.TareaID)
    {
        Auxant = nodoAux;
        nodoAux = nodoAux->Siguiente;
    }
    if (nodoAux != NULL)
    {
        if (nodoAux == *r)
        {
            *r = nodoAux->Siguiente;
        }
        else
        {
            Auxant->Siguiente = nodoAux->Siguiente;
        }
        nodoAux->Siguiente = NULL;
    }
    return nodoAux;
}
void mostrar(Nodo *l)
{
    Nodo *aux = l;
    int i = 1;
    while (aux != NULL)
    {
        printf("\nTarea numero: %d", i);
        printf("\nDescripcion de la tarea: %s", aux->T.Descripcion);
        printf("\nId de la tarea: %d", aux->T.TareaID);
        i++;
        aux = aux->Siguiente;
    }
}
Nodo *crearLista()
{
    return NULL;
}
Nodo *crearNodo(int duracion, char descripcion[], int *tareaID)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->T.Duracion = duracion;
    aux->T.Descripcion = (char *)malloc(sizeof(char) * (strlen(descripcion) + 1));
    strcpy(aux->T.Descripcion, descripcion);
    aux->T.TareaID = *tareaID;
    (*tareaID)++;
    return aux;
}
void InsertarNodo(Nodo **cabeza, Nodo *nodo)
{
    if (nodo != NULL)
    {
        nodo->Siguiente = *cabeza;
        *cabeza = nodo;
    }
}
