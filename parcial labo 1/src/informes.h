
#ifndef INFORMES_H_
#define INFORMES_H_

/// @brief muestra todos los autos de un color seleccionado
///
/// @param idColor es el id que tiene cada color
/// @param tam_c es el tamaño de la estructura color
/// @param vec pasa la estructura autos y la recorre
/// @param tam es el tamaño de la estructura autos
/// @param colores pasa la estructura color y la recorre
/// @param marcas pasa la estructura marca y la recorre
/// @param tam_m es el tamaño de la estructura marca
/// @return
int mostrarAutosDeColor(int* idColor,int tam_c,eAuto vec[],int tam,eColor colores[],eMarca marcas[],int tam_m);

/// @brief muestra todos los autos de una marca seleccionada
///
/// @param idMarcas  es el id que tiene cada marca
/// @param tam_c es el tamaño de la estructura color
/// @param vec pasa la estructura autos y la recorre
/// @param tam es el tamaño de la estructura autos
/// @param colores pasa la estructura color y la recorre
/// @param marcas pasa la estructura marca y la recorre
/// @param tam_m es el tamaño de la estructura marca
/// @return
int mostrarAutosMarca(int* idMarcas,int tam_c,eAuto vec[],int tam,eColor colores[],eMarca marcas[],int tam_m);

/// @brief informa el porcentaje de autos por cada tipo de caja
///
/// @param vec pasa la estructura autos y la recorre
/// @param tam es el tamaño de la estructura autos
/// @param contadorAutos es la cantidad total de autos cargados
/// @return
int informarPorcentajePorCaja(eAuto vec[],int tam,int* contadorAutos);

/// @brief muestra los autos separados por el tipo de caja
///
/// @param vec pasa la estructura autos y la recorre
/// @param marcas pasa la estructura marca y la recorre
/// @param colores pasa la estructura color y la recorre
/// @param tam es el tamaño de la estructura autos
/// @param tam_m es el tamaño de la estructura marca
/// @param tam_c es el tamaño de la estructura color
/// @return
int informarAutosPorCaja(eAuto vec[],eMarca marcas[],eColor colores[],int tam,int tam_m,int tam_c);

/// @brief muestra la cantidad de autos de una marca y color seleccionados
///
/// @param idColor es el id que tiene cada color
/// @param idMarcas es el id que tiene cada marca
/// @param tam_c es el tamaño de la estructura color
/// @param vec pasa la estructura autos y la recorre
/// @param tam es el tamaño de la estructura autos
/// @param colores pasa la estructura color y la recorre
/// @param marcas pasa la estructura marca y la recorre
/// @param tam_m es el tamaño de la estructura marca
/// @param contadorMarcaYColor es la cantidad total de autos de un mismo color y marca cargados
/// @return
int mostrarAutosDeColorYMarca(int* idColor,int* idMarcas,int tam_c,eAuto vec[],int tam,eColor colores[],eMarca marcas[],int tam_m,int* contadorMarcaYColor);

/// @brief muestra cual es la marca mas elegida osea con mas autos
///
/// @param autos pasa la estructura autos y la recorre
/// @param marcas pasa la estructura marca y la recorre
/// @param tam es el tamaño de la estructura autos
/// @param tam_m es el tamaño de la estructura marca
/// @return
int informarMarcaMasElegida(eAuto* autos, eMarca* marcas, int tam,int tam_m);

/// @brief contabiliza la cantidad de autos de cada marca
///
/// @param autos pasa la estructura autos y la recorre
/// @param indice va a ser la posicion del array de marcas que se recorre permitiendo reconocer cada marca y sumarle la cantidad de autos a cada una
/// @param tam es el tamaño de la estructura autos
/// @param contador variable que contabiliza la cantidad de autos de una marca
/// @return
int contadorAutosMarca(eAuto* autos,int indice,int tam,int* contador);

/// @brief muestra los trabajos realizados a un auto elegido
///
/// @param idAuto es el id que tiene cada auto
/// @param pTrabajo pasa la estructura trabajo y la recorre
/// @param autos pasa la estructura autos y la recorre
/// @param servicios pasa la estructura servicio y la recorre
/// @param tam es el tamaño de la estructura autos
/// @param tam_s es el tamaño de la estructura servicio
/// @param marca pasa la estructura marca y la recorre
/// @param tam_m es el tamaño de la estructura marca
/// @param colores pasa la estructura colores y la recorre
/// @param tam_c es el tamaño de la estructura color
/// @param tam_t es el tamaño de la estructura trabajo
/// @return
int mostrarTrabajosEnAuto(int* idAuto,eTrabajo pTrabajo[],eAuto autos[],eServicio servicios[],int tam,int tam_s,eMarca marca[],int tam_m,eColor colores[],int tam_c,int tam_t);

/// @brief acumula el valor de los importes realizados a un auto auto
///
/// @param idAuto es el id que tiene cada auto
/// @param pTrabajo pasa la estructura trabajo y la recorre
/// @param autos pasa la estructura autos y la recorre
/// @param servicios pasa la estructura servicio y la recorre
/// @param tam es el tamaño de la estructura autos
/// @param tam_s es el tamaño de la estructura servicio
/// @param marca pasa la estructura marca y la recorre
/// @param tam_m es el tamaño de la estructura marca
/// @param colores pasa la estructura colores y la recorre
/// @param tam_c es el tamaño de la estructura color
/// @param tam_t es el tamaño de la estructura trabajo
/// @return
int acumularImportes(int* idAuto,eTrabajo pTrabajo[],eAuto autos[],eServicio servicios[],int tam,int tam_s,eMarca marca[],int tam_m,eColor colores[],int tam_c,int tam_t);

/// @brief muestra los autos a los que se les realizo el servicio solicitado
///
/// @param pTrabajo pasa la estructura trabajo y la recorre
/// @param autos pasa la estructura autos y la recorre
/// @param servicios pasa la estructura servicio y la recorre
/// @param tam es el tamaño de la estructura autos
/// @param tam_s es el tamaño de la estructura servicio
/// @param marca pasa la estructura marca y la recorre
/// @param tam_m es el tamaño de la estructura marca
/// @param colores pasa la estructura colores y la recorre
/// @param tam_c es el tamaño de la estructura color
/// @param tam_t es el tamaño de la estructura trabajo
/// @return
int informarServiciosEnAutos(eTrabajo pTrabajo[],eAuto autos[],eServicio servicios[],int tam,int tam_s,eMarca marca[],int tam_m,eColor colores[],int tam_c,int tam_t);

/// @brief muestra todos los trabajos y sevicios realizados en una fecha especifica
///
/// @param pTrabajo pasa la estructura trabajo y la recorre
/// @param servicios pasa la estructura servicio y la recorre
/// @param tam_s es el tamaño de la estructura servicio
/// @param tam_t es el tamaño de la estructura trabajo
/// @param tam es el tamaño de la estructura autos
/// @return
int informarServiciosEnFecha(eTrabajo pTrabajo[],eServicio servicios[],int tam_s,int tam_t,int tam);
#endif /* INFORMES_H_ */
