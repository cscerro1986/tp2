#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "practicaArmadura.h"
#include "informes.h"
#define SIZE_CHAR 30
#define QTY_TIPO 3
#define CANT_EMPLE 1000


int main()
{

    int opcion;
    int flag=1;
    int contadorEmployee=0;
    Employee eEmployee[CANT_EMPLE];
    /*
                                    {{1,"Santiago","Cerro",450,1,0},
                                    {2,"Pedro","Caceres",355,1,0},
                                    {3,"Pedro","Orsi",670,2,0},
                                    {4,"Mariano","Tiralongo",135,1,0},
                                    {5,"Pedro","Lazzare",550,2,0}};

    */
    init_empleado(eEmployee,CANT_EMPLE);

    do
    {
        utn_getUnsignedInt("\n\n1) Add employee \n"
                                "2) Change employee \n"
                                "3) Remove employee \n"
                                "4) List employees \n"
                                "5) Inform \n"
                                "6) Exit",
                      "\nError",1,sizeof(int),1,6,1,&opcion);


        switch(opcion)
        {
            case 1: //ALTA

                addEmployee1(eEmployee,CANT_EMPLE,&contadorEmployee);
                flag=0;
                break;

            case 2: //MODIFICAR
                if(flag==1)
                    {
                        printf("First add a new Employee");
                        break;
                    }
                employee_modificar(eEmployee,CANT_EMPLE);
                break;

            case 3: //BAJA
                if(flag==1)
                    {
                        printf("First add a new Employee");
                        break;
                    }

                removeEmployee(eEmployee,CANT_EMPLE);
                break;

            case 4://LISTAR PANTALLAS
                if(flag==1)
                    {
                        printf("First add a new Employee");
                        break;
                    }



                printEmployee(eEmployee,CANT_EMPLE);
                break;

            case 5://CONSULTAR TOTALIDAD DE SALARIOS PROMEDIO Y CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO.
               if(flag==1)
                    {
                        printf("First add a new Employee");
                        break;
                    }
                employee_ordenarPorString2(eEmployee, CANT_EMPLE);
                calcularTotalidadSalarios(eEmployee,CANT_EMPLE);
                break;

            default:
                printf("\nYou choose an invalid option, try again");
        }
    }
    while(opcion!=6);
    return 0;
}

