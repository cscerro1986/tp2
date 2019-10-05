#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "practicaArmadura.h"



//Ordenar
/** \brief Ordena por campo lastname los elementos de un array
* \param array array es un array de Employee
* \param size Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/



int employee_ordenarPorString2(Employee array[],int size) //es el que quiero modificar yo
{
    int retorno=-1;
    int i, j;

    int bufferIdEmpleado;
    int bufferIsEmpty;
    int bufferSector;
    char bufferName[TEXT_SIZE];
    char bufferLastName[TEXT_SIZE];
    float bufferSalary;
    char sector[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 0; i < size-1; i++)
        {
            for(j=i+1;j<size;j++)
                {

                            if(strcmp(array[i].lastName,array[j].lastName)>0)
                                {
                                        strcpy(bufferName,array[i].name);
                                        strcpy(bufferLastName,array[i].lastName);
                                        bufferIsEmpty=array[i].isEmpty;
                                        bufferIdEmpleado=array[i].idEmpleado;
                                        bufferSalary=array[i].salary;
                                        bufferSector=array[i].sector;

                                        strcpy(array[i].name,array[j].name);
                                        strcpy(array[i].lastName,array[j].lastName);
                                        array[i].idEmpleado=array[j].idEmpleado;
                                        array[i].isEmpty=array[j].isEmpty;
                                        array[i].salary=array[j].salary;
                                        array[i].sector=array[j].sector;

                                        strcpy(array[j].name,bufferName);
                                        strcpy(array[j].lastName,bufferLastName);
                                        array[j].idEmpleado=bufferIdEmpleado;
                                        array[j].isEmpty=bufferIsEmpty;
                                        array[j].salary=bufferSalary;
                                        array[j].sector=bufferSector;

                                }

                            if(strcmp(array[i].lastName,array[j].lastName)==0)
                            {
                                if (array[i].sector<array[j].sector)
                                {
                                        strcpy(bufferName,array[i].name);
                                        strcpy(bufferLastName,array[i].lastName);
                                        bufferIsEmpty=array[i].isEmpty;
                                        bufferIdEmpleado=array[i].idEmpleado;
                                        bufferSalary=array[i].salary;
                                        bufferSector=array[i].sector;

                                        strcpy(array[i].name,array[j].name);
                                        strcpy(array[i].lastName,array[j].lastName);
                                        array[i].idEmpleado=array[j].idEmpleado;
                                        array[i].isEmpty=array[j].isEmpty;
                                        array[i].salary=array[j].salary;
                                        array[i].sector=array[j].sector;

                                        strcpy(array[j].name,bufferName);
                                        strcpy(array[j].lastName,bufferLastName);
                                        array[j].idEmpleado=bufferIdEmpleado;
                                        array[j].isEmpty=bufferIsEmpty;
                                        array[j].salary=bufferSalary;
                                        array[j].sector=bufferSector;

                                }

                            }

                    }

        }

        printf("\nEl listado actualizado de los empleados es el siguiente:");

        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==0)
                {
                    if(array[i].sector==1)
                        {
                            strcpy(sector,"Software Developer");
                        }
                    if (array[i].sector==2)
                        {
                            strcpy(sector,"IT Engineer");
                        }

                    printf("\nEmpleado: %s, sector: %s",array[i].lastName,sector);
                }

        }


        retorno=0;
    }
    return retorno;
}



//Ordenar
/** \brief Recorre un array de Employee, suma los salarios, calcula promedios, indica cuantos superan el promedio, imprime por pantalla
* \param array array es un array de Employee
* \param size Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0)
*
*/


int calcularTotalidadSalarios(Employee array[], int size)
{
    int retorno=-1;
    int posicion;
    float sumaSalarios=0;
    int contadorEmpleados=0;
    int contadorEmpleadosSuperanElPromedio=0;
    float promedioDeSalarios;
    if(array!=NULL && size>=0)
    {
        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;

            else
               contadorEmpleados++;
               sumaSalarios=sumaSalarios+array[posicion].salary;

        }

        promedioDeSalarios=sumaSalarios/contadorEmpleados;

        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;

            else if(array[posicion].salary>promedioDeSalarios)
                {
                    contadorEmpleadosSuperanElPromedio++;
                }

        }

        printf("\n\nLa totalidad de los salarios es de %.2f, y el promedio es de %.2f \n superan este valor %d de un total de %d empleados",
               sumaSalarios,
               promedioDeSalarios,
               contadorEmpleadosSuperanElPromedio,
               contadorEmpleados);

        retorno=0;
    }
    return retorno;
}

