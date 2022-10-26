/*
 * validaciones.h
 *
 *  Created on: 19 oct. 2022
 *      Author: PC
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
/// @brief valida la salida del programa, s seria para si  lo que confirma la salida, y n para no,lo que lo devuelve al menu.
///
/// @param pVariable: es el caracter que ingresa el usuario.
/// @param confirma: si el caracter ingresado es s,finalizara el programa.
/// @param rechaza: si el caracter ingresado es n, se regresa al menu.
/// @return retorna todook,si es 1 salio bien,si es 0 hubo un error.
int confirmarSalida(char* pVariable, char confirma, char rechaza);

/// @brief valida el ingreso de una id existente en el vector de estructura  marca
///
/// @param id es el id ingresado por el usuario
/// @param marcas pasa la estructura marcas para recorrerla
/// @param tam es el tamaño de la estructura
/// @return
int validarIdMarcas(int id,eMarca marcas[],int tam);

/// @brief valida el ingreso de una id existente en el vector de estructura color
///
/// @param id es el id ingresado por el usuario
/// @param colores pasa la estructura color para recorrerla
/// @param tam es el tamaño de la estructura
/// @return
int validarIdColores(int id,eColor colores[],int tam);

/// @brief valida el ingreso de una id existente en el vector de estructura servicio
///
/// @param id es el id ingresado por el usuario
/// @param servicios pasa la estructura servicio para recorrerla
/// @param tam es el tamaño de la estructura
/// @return
int validarIdServicios(int id,eServicio servicios[],int tam);

/// @brief valida el ingreso de una id existente en el vector de estructura autos
///
/// @param id es el id ingresado por el usuario
/// @param autos pasa la estructura auto para recorrerla
/// @param tam es el tamaño de la estructura
/// @return
int validarIdAutos(int id,eAuto autos[],int tam);

/// @brief carga la descripcion cargada en la estrutura marca en un auxiliar que se usa previamente
/// para mostrarlo en el listado de autos
///
/// @param id es el id en la posicion del vector de la estructura
/// @param descripcion es la descripcion que uso como auxiliar para copiar la de la estructura y pasarla a la otra
/// @param marcas pasa la estructura marca y la recorre
/// @param tam_m es el tamaño de la estructura marca
/// @return
int cargarDescripcionMarcas(int id, char descripcion[], eMarca marcas[], int tam_m);
/// @brief carga la descripcion cargada en la estrutura color en un auxiliar que se usa previamente
/// para mostrarlo en el listado de autos
///
/// @param id es el id en la posicion del vector de la estructura
/// @param descripcion es la descripcion que uso como auxiliar para copiar la de la estructura y pasarla a la otra
/// @param colores pasa la estructura color y la recorre
/// @param tam_c es el tamaño de la estructura color
/// @return
int cargarDescripcionColores(int id, char descripcion[], eColor colores[], int tam_c);

/// @brief carga la descripcion cargada en la estrutura servicios en un auxiliar que se usa previamente
/// para mostrarlo en el listado de trabajos
///
/// @param id es el id en la posicion del vector de la estructura
/// @param descripcion es la descripcion que uso como auxiliar para copiar la de la estructura y pasarla a la otra
/// @param servicios pasa la estructura servicio y la recorre
/// @param tam_s es el tamaño de la estructura servicio
/// @return
int cargarDescripcionServicios(int id, char descripcion[], eServicio servicios[], int tam_s);


#endif /* VALIDACIONES_H_ */
