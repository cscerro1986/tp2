#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "practicaArmadura.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array llamado array, Array of Employee
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int init_empleado(Employee array[],int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>0)
        {
            for(i=0;i<size;i++)
                {
                    array[i].isEmpty=1;

                }

        }


    return retorno;
}

//*****************************************
//SearchEmpty

/** \brief Busca el primer lugar vacio en un array
* \param array array Array de Employee
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/

int employee_SearchEmpty( Employee array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array array Array de Employee
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

int findEmployeeById(Employee array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idEmpleado==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int findEmployeeById2(Employee array[], int size, int valorBuscado)
{

    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idEmpleado==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


//*****************************************
//Add employee
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array array Array de Employee
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/


int addEmployee1(Employee array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;

    if(array!=NULL && size>0 && contadorID!=NULL)

    {
        if(employee_SearchEmpty(array,size,&posicion)==-1)
        {
            printf("\nThere is not empty places to add another Employee");
        }
        else
        {
            (*contadorID)++;

            array[posicion].idEmpleado=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getTexto("\nNAME: ","\nError",1,TEXT_SIZE,1,array[posicion].name);                 //mensaje + cambiar campo varLongString
            utn_getTexto("\nLASTNAME: ","\nError",1,TEXT_SIZE,1,array[posicion].lastName);
            utn_getFloat("\nSALARY: ","Error",1,8,1,150000,2,&array[posicion].salary);
            utn_getUnsignedInt("\nSECTOR: (choose a nunmber) \n   1-Software Developer\n   2-IT Engineer","Error",1,sizeof(int),0,3,2,&array[posicion].sector);


             retorno=0;
        }
    }
    return retorno;
}



//*****************************************
//Remove employee
/** \brief remueve un elemento del array por ID
* \param array array, Array de Employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int removeEmployee( Employee array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char letra;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(findEmployeeById(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nThe ID does not exist");
        }
        else
        {

            utn_getChar("Comfirm permanent changes? y-n","Error",'a','z',3,&letra);
            if(letra=='y')
                {

                    array[posicion].isEmpty=1;
                    array[posicion].idEmpleado=0;
                    array[posicion].salary=0;
                    array[posicion].sector=0;
                    strcpy(array[posicion].name,"");
                    strcpy(array[posicion].lastName,"");
                }

            retorno=0;


        }
    }
    return retorno;
}

//*****************************************
//Change employee
/** \brief Busca un elemento por ID y modifica sus campos
* \param array array, Array de Employee
* \param size int Tamaño del array
* \return    int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/

int employee_modificar(Employee array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(findEmployeeById(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nThe ID does not exist");
        }
        else
        {
            do
            {       //copiar printf de alta
                utn_getChar("\nModificar: \nA-Nanme \nB-Lastname \nC-Salary \nD-Area \nS-(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {


                    case 'A':
                        utn_getTexto("\nNAME: ","\nError",1,TEXT_SIZE,1,array[posicion].name);
                        break;
                    case 'B':
                        utn_getTexto("\nLastname: ","\nError",1,TEXT_SIZE,1,array[posicion].lastName);
                        break;
                    case 'C':
                        utn_getFloat("SALARY: ","Error",1,8,1,150000,2,&array[posicion].salary);
                        break;
                    case 'D':
                        utn_getUnsignedInt("\nSECTOR: (choose a nunmber) \n   1-Software Developer\n   2-IT Engineer","Error",1,sizeof(int),0,3,2,&array[posicion].sector);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");


                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}


//*****************************************
//List employee
/** \brief Lista los elementos del array "array"
* \param array array, Array de Employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/

int printEmployee(Employee array[], int size)
{
    int retorno=-1;
    int posicion;
    char elSector[TEXT_SIZE];
    if(array!=NULL && size>=0)
    {
        for(posicion=0;posicion<size;posicion++)
        {
            if(array[posicion].isEmpty==1)
                continue;

            else
            if(array[posicion].sector==1)
            {
                strcpy(elSector,"Software Developer");
            }
            else if(array[posicion].sector==2)
            {
                strcpy(elSector,"IT Engineer");
            }
                printf("\n\nPosicion: %d \n ID: %d \n Name: %s \n Lastname: %s \n Salary: %.2f \n Sector: %s",
                       posicion,
                       array[posicion].idEmpleado,
                       array[posicion].name,
                       array[posicion].lastName,
                       array[posicion].salary,
                       elSector);
        }
        retorno=0;
    }
    return retorno;
}




