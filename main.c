#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000

typedef struct
{
  int id;
  char name[51];
  char lastName[51];
  float salary;
  int sector;
  int isEmpty;
}Employee;

int menu();
int initEmployees(Employee list[], int tam);
int findFree (Employee list[], int tam);
int addEmployee (Employee list [], int tam, int id, char name[], char lastName [], float salary, int sector);
int findEmployeeById(Employee list[], int tam, int id);
int removeEmployee(Employee list[], int tam, int id);
int sortEmployees(Employee list[], int tam, int order);
int printEmployees(Employee list[], int tam);
Employee recuestData (int* id);

int main()
{
    char keepGoing = 's';
    Employee list[TAM];
    int id = 1;

    do
    {

        switch(menu())
        {
            case 1:
                addEmployee(list, TAM, id, list->name, list->lastName, list->salary, list->sector);
                printf("1");
                 system("pause");
            break;

            case 2:
                printf("2");
                 system("pause");
            break;

            case 3:
                printf("3");
                 system("pause");
            break;

            case 4:
                printf("4");
                 system("pause");
            break;

            case 5:
                keepGoing='n';
            break;

            default:
            system("cls");
            printf("Error.. Seleccione una opcion valida..");
            system("pause");
        }
    }while(keepGoing=='s');
}


int menu()
{
    int opcion;
    system("cls");
    printf("****ABM Employees**** \n\n");
    printf("1) Alta empleado\n");
    printf("2) Modificar empleado\n");
    printf("3) Baja empleado\n");
    printf("4) Informar\n");
    printf("5) Salir\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(Employee list[], int tam)
{
    int todoOk=0;
    if(list != NULL && tam > 0)
    {
        for(int i= 0; i < tam; i++)
        {
            list[i].isEmpty = 1;
        }
    }

    return todoOk;
}

int findFree (Employee list[], int tam)
{
    int position=-1;

    if(list != NULL && tam>0)
    {

        for(int i; i < tam; i++)
        {
            if(list[i].isEmpty)
            {
                position = i;
                break;
            }
        }
    }

    return position;
}


int addEmployee (Employee list [], int tam, int id, char name[], char lastName [], float salary, int sector)
{
    int todoOk = 0;
    Employee aux;
    int position;

    if(list != NULL && name != NULL && lastName!= NULL && tam>0)
    {
        system("cls");
        printf("***Alta persona***\n");
        position = findFree(list, tam);

        if(position != -1)
        {
            aux = recuestData(&id);
            list[position] = aux;
        }
        else
        {
            printf("No hay espacio para mas empleados.");
        }
        todoOk=1;
    }

    return todoOk;
}

Employee recuestData(int* id)
{
    Employee data;

    printf("Ingrese nombre del empleado");
    fflush(stdin);
    gets(data.name);

    printf("Ingrese apellido del empleado");
    fflush(stdin);
    gets(data.lastName);

    printf("Ingrese salario del empleado");
    scanf("%f", &data.salary);

    printf("Ingrese sector del empleado");
    scanf("%d", &data.sector);

    data.id = *id;
    (*id)++;

    return data;

}
