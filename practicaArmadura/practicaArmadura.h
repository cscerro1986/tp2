#ifndef ARMADURA_H_INCLUDED
#define ARMADURA_H_INCLUDED

#define TEXT_SIZE 20


typedef struct
{
    int idEmpleado;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;


#endif

int init_empleado(Employee array[],int size);
int employee_SearchEmpty( Employee array[], int size, int* posicion)   ;
int findEmployeeById(Employee array[], int size, int valorBuscado, int* posicion);
int findEmployeeById2(Employee array[], int size, int valorBuscado);
int addEmployee1(Employee array[], int size, int* contadorID);
int removeEmployee( Employee array[], int sizeArray);
int employee_modificar(Employee array[], int sizeArray);
int printEmployee(Employee array[], int size);


