//Librerias
#include <stdio.h>
#include <string.h>

//Fuentes de texto

#define ROJO_T "\x1b[31m"
#define AZUL_T "\x1b[34m"
#define VERDE_T "\x1b[32m"
#define AMARILLO_T "\x1b[33m"
#define RESET_T "\x1b[0m"

//Eestructura Alumno y subcategorias
struct Alumno           
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};

//Define estructuras
void getAlumno(struct Alumno *alumno);      
void putAlumno(const struct Alumno *alumno);

//Inicia el programa
int main()
{
    //Se define n como le numero de alumnos a ingresar
    int n;
    printf(RESET_T "Ingrese numero de alumnos: " RESET_T);
    scanf("%d", &n);
    while (getchar() != '\n')
        ; // Limpiar el búfer de entrada

    //Se agrega una arreglo de estructuras, un indice acumulador y la opcion a elegir
    struct Alumno alumnos[n];
    int indice = 0;

    int opcion;
    //Se agrega una secuencia repetititiva para el menu de opciones
    do
    {
        //Se imprimen las opciones del menu para escoger e ingresar opcion
        printf("\n%s----- Menu de Opciones -----\n", VERDE_T);
        printf("1. Ingresar datos de alumnos\n");
        printf("2. Mostrar datos de alumnos\n");
        printf("3. Salir\n");
        printf("Ingrese su opcion: "RESET_T);
        scanf("%d", &opcion);
        while (getchar() != '\n')
            ; // Limpiar el búfer de entrada
        //Se agrega un switch para selecion de opciones
        switch (opcion)
        {
        case 1:
        //Se agrega una secuencia repetitiva en la opcion 1 y se llama la estructura de ingreso de datos 
            if (indice < n)
            {        
                //Se intenta mandars los datos al archivo        
                FILE *archivo = fopen("Evaluacion.txt", "r+");
                printf("\nIngresar datos del alumno %d:\n" RESET_T, indice + 1);
                getAlumno(&alumnos[indice]);
                indice++;
                fputs(getAlumno, archivo);
                fclose(archivo);
            }
            else //Se agrega un else para tomar en cuenta una posible contradiccion a la condicion del if
            {
                printf("\n%sNo hay espacio para más alumnos.\n", ROJO_T);
            }
            break;

        case 2:
            //Se agrega una secuencia repetitiva en la opcion 2 y se llama la funcion de salida de datos
            if (indice > 0)
            {                
                //Se intenta acoger los datos del archivo para mostrarlos 
                FILE *archivo = fopen("Evaluacion.txt", "a+");
                printf(RESET_T "\n\tDatos de los alumnos:\n");
                //Se agrega una secuencia for dentro de la condicion if positiva para que vaya marcando los alumnos continuos y sus respuestas
                for (int i = 0; i < indice; i++)
                {
                    printf(AMARILLO_T "\n \t Alumno %d:\n", i + 1);
                    putAlumno(&alumnos[i]);                     
                    fputws(putAlumno, archivo);
                    fclose(archivo);                 
                }
            }
            else //Se agrega un else para tomar en cuenta una posible contradiccion a la condicion del if
            {
                printf("\n%sNo hay alumnos para mostrar.\n", ROJO_T);
            }
            break;

        case 3:
            //Se agrega una opcion de salida
            printf("\n%sSaliendo del programa. Hasta luego!\n\n", RESET_T);
            break;
        //Se agrega un mensaje para una opcion invalida
        default:
            printf("\n%sOpcion no valida. Inténtelo de nuevo.\n\n", ROJO_T);
        }
    } while (opcion != 3);   //Se agrega la condicion de salida

    return 0;
}

//Se define la estructura de entrada de datos 
void getAlumno(struct Alumno *alumno)
{
    printf(ROJO_T "Matricula: " AZUL_T);
    scanf("%d", &alumno->matricula);
    while (getchar() != '\n')
        ; // Limpiar el búfer de entrada

    printf(ROJO_T "Nombre: " AZUL_T);
    fgets(alumno->nombre, sizeof(alumno->nombre), stdin);
    printf(ROJO_T "Direccion: " AZUL_T);
    fgets(alumno->direccion, sizeof(alumno->direccion), stdin);
    printf(ROJO_T "Carrera: " AZUL_T);
    fgets(alumno->carrera, sizeof(alumno->carrera), stdin);
    printf(ROJO_T "Promedio: " AZUL_T);
    scanf("%f", &alumno->promedio);
    while (getchar() != '\n')
        ; // Limpiar el búfer de entrada
}

//Se agrega la estructura para salida de datos
void putAlumno(const struct Alumno *alumno)
{
    printf(ROJO_T "Matricula: " AZUL_T "%d\n", alumno->matricula);
    printf(ROJO_T "Nombre: " AZUL_T "%s", alumno->nombre);
    printf(ROJO_T "Direccion: " AZUL_T "%s", alumno->direccion);
    printf(ROJO_T "Carrera: " AZUL_T "%s", alumno->carrera);
    printf(ROJO_T "Promedio: " AZUL_T "%.2f\n" RESET_T, alumno->promedio);
}
