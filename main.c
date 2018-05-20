#include <stdio.h>
#include <stdlib.h> // NULL

#define NOMBRE_ARCHIVO "/Users/tizianomartinhernando/Desktop/empleados.txt" // bin original

typedef struct Persona Persona;

struct Persona
{
    char *nombre; // char nombre[256]
    int edad;
    double salario;

};// No te olvides ";"


int escribeArchivo(Persona empleados[], int tam, const char *nombreArchivo);
int leeArchivo(Persona empleados[], int tam, const char *nombreArchivo);
void imprimeEmpleados(Persona empleados[], int tam);
void imprimePersona(Persona *persona);

int main(void)
{
    Persona empleados[] = { { "Juan", 25, 5000.0 },
                            { "Ana",  30, 6000.0 },
                            { "Luis", 40, 7000.0 },
                            { "Francisco", 50, 8000.0 } };

    const int tam = sizeof(empleados) / sizeof(Persona);

    Persona empleadosEntrada[tam];

    if (!escribeArchivo(empleados, tam, NOMBRE_ARCHIVO)){
        printf("Error de escritura\n");
        return 1;

    }
    if (!leeArchivo(empleadosEntrada, tam, NOMBRE_ARCHIVO)){
        printf("Error de lectura\n");
        return 2;
    }
    imprimeEmpleados(empleadosEntrada, tam);

    return 0;
}

int escribeArchivo(Persona empleados[], int tam, const char *nombreArchivo)
{
   FILE *F;
   F = fopen(nombreArchivo, "wb"); // wb == write y binario

   if (F == NULL){
       return 0;
   }
   int i;
   for (i = 0; i < tam; ++i){
       fwrite(&empleados[i], sizeof(Persona), 1, F); // fwrite == escribir
   }
   fflush(F);
   fclose(F);
   return 1;
}

int leeArchivo(Persona empleados[], int tam, const char *nombreArchivo)
{
    FILE *F;
    F = fopen(nombreArchivo, "rb"); // rb =leer binario

    if (F == NULL){
        return 0;
    }
    int i;
    for (i = 0; i < tam; ++i){
        fread(&empleados[i], sizeof(Persona), 1, F);

    }
    fclose(F);
    return 1;
}

void imprimeEmpleados(Persona empleados[], int tam)
{
     int i;
     for (i = 0; i < tam; ++i){
         imprimePersona(&empleados[i]);
         printf("\n");
     }
}

void imprimePersona(Persona *persona)
{
    printf("Nombre: %s\n", persona->nombre);
    printf("Edad: %d\n", persona->edad);
    printf("Salario %lf\n", persona->salario);

}

