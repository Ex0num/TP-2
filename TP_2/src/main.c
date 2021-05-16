/*
 ============================================================================
 Name        : TP_2.c
 Author      : Gabriel Lopez G
 Version     :
 Copyright   : GLG
 Description : Hello World in C, Ansi-style
 ============================================================================
Una empresa requiere un sistema para administrar su n�mina de empleados. Se sabe que
dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
Datos:

El sistema deber� tener el siguiente men� de opciones:

	1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
	de Id. El resto de los campos se le pedir� al usuario.
	2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
	o Salario o Sector
	3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
	4. INFORMAR:
	1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
	2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
	NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
	Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
	carga de alg�n empleado.

  ============================================================================
 */

	#include <stdio.h>
	#include <stdlib.h>
	#include "Employee.h"
	#include "FuncionesEstandar.h"

	#define QTY_EMPLOYEES 1000


	int main(void)
	{
		setbuf(stdout,NULL);
		Employee employees[QTY_EMPLOYEES];

		initEmployees (employees, QTY_EMPLOYEES);
		int idEmployees = 1;
		int ordenDeMenu;
		int ordenDeMenu2;

		do
		{
			print_menu1 ();
			utn_obtener_validar_Orden ("\n Ingrese la orden a realizar.\n", "\n Error en el ingreso de su orden. \n", &ordenDeMenu);

			switch (ordenDeMenu)
			{

			case 1:
				{
					//ALTA
					addEmployees (employees, QTY_EMPLOYEES, &idEmployees);
					break;
				}
			case 2:
				{
					//MODIFICACION
					modificateEmployee (employees, QTY_EMPLOYEES);
					break;
				}

			case 3:
				{
					//BAJA
					removeEmployee (employees, QTY_EMPLOYEES);
					break;
				}

			case 4:
				{
					//INFORMES

					print_menu2();
					utn_obtener_validar_Orden2 ("\n Ingrese la orden a realizar.\n", "\n Error en el ingreso de su orden. \n", &ordenDeMenu2);

					switch (ordenDeMenu2)
					{
					case 1:
						{
							// Listado de los empleados ordenados alfab�ticamente por Apellido y Sector. //FALTA
							sortEmployees (employees, QTY_EMPLOYEES, ordenDeMenu2);
							break;
						}

					case 2:
						{
							// Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
							sortEmployees (employees, QTY_EMPLOYEES, ordenDeMenu2);
							break;
						}

					case 3:
						{
							// SALIR.
							//No hago nada, salgo.
							break;
						}
					}



					break;
				}

			case 5:
				{
					// SALIR
					ordenDeMenu = 5;
					print_bye();
					break;
				}
			}

		}while( ordenDeMenu != 5 );

	}



/*
	void ordenarEmpleados(Empleado list[], int tam)
	{

	    Empleado auxEmpleado;

	    for(int i=0; i<tam -1; i++)
	    {
	        for(int j=i+1; j<tam; j++)
	        {
	            {
	                if(list[i].isEmpty==0 && list[i].sector>list[j].sector){

	                    auxEmpleado=list[i];
	                    list[i]=list[j];
	                    list[j]=auxEmpleado;

	                }else
	                    if(list[i].sector == list[j].sector && strcmp(list[i].apellido,list[j].apellido)>0){

	                    auxEmpleado=list[i];
	                    list[i]=list[j];
	                    list[j]=auxEmpleado;
	                }
	            }
	        }
	    }

	    mostrarEmpleados(list,tam);
	}
*/
