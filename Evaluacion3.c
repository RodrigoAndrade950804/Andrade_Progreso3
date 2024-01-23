#include <stdio.h>

#define ROJO_T "\x1b[31m"
#define AZUL_T "\x1b[34m"
#define VERDE_T "\x1b[32m"
#define AMARILLO_T "\x1b[33m"
#define RESET_T "\x1b[0m"

struct Alumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};

void getAlumno(struct Alumno *alumno);
void putAlumno(const struct Alumno *alumno);

int main()
{
    
    int n;
    printf(RESET_T "Ingrese numero de alumnos: " RESET_T);
    scanf("%d", &n);
    while (getchar() != '\n')
        ; // Limpiar el búfer de entrada

    struct Alumno alumnos[n];
    int indice = 0;

    int opcion;
    do
    {
        printf("\n%s----- Menu de Opciones -----\n", VERDE_T);
        printf("1. Ingresar datos de alumnos\n");
        printf("2. Mostrar datos de alumnos\n");
        printf("3. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n')
            ; // Limpiar el búfer de entrada

        switch (opcion)
        {
        case 1:
            if (indice < n)
            {
                FILE *archivo = fopen("Evaluacion.txt", "w");
                printf("\nIngresar datos del alumno %d:\n" RESET_T, indice + 1);
                getAlumno(&alumnos[indice]);
                indice++;
                fputs(getAlumno, archivo);
                fclose(archivo);
            }
            else
            {
                printf("\n%sNo hay espacio para más alumnos.\n", ROJO_T);
            }
            break;

        case 2:
            if (indice > 0)
            {                
                
                printf(RESET_T "\n\tDatos de los alumnos:\n");
                for (int i = 0; i < indice; i++)
                {
                    printf(AMARILLO_T "\n \t Alumno %d:\n", i + 1);
                    putAlumno(&alumnos[i]);                   
                }
            }
            else
            {
                printf("\n%sNo hay alumnos para mostrar.\n", ROJO_T);
            }
            break;

        case 3:
            printf("\n%sSaliendo del programa. Hasta luego!\n\n", ROJO_T);
            break;

        default:
            printf("\n%sOpcion no valida. Inténtelo de nuevo.\n\n", ROJO_T);
        }
    } while (opcion != 3);   

    return 0;
}

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

void putAlumno(const struct Alumno *alumno)
{
    printf(ROJO_T "Matricula: " AZUL_T "%d\n", alumno->matricula);
    printf(ROJO_T "Nombre: " AZUL_T "%s", alumno->nombre);
    printf(ROJO_T "Direccion: " AZUL_T "%s", alumno->direccion);
    printf(ROJO_T "Carrera: " AZUL_T "%s", alumno->carrera);
    printf(ROJO_T "Promedio: " AZUL_T "%.2f\n" RESET_T, alumno->promedio);
}