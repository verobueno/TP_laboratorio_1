#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
} EMovie;

#endif // MOVIES_H_INCLUDED
