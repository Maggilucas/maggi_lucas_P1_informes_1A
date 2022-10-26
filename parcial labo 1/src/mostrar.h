

#ifndef MOSTRAR_H_
#define MOSTRAR_H_

/// @brief muestra el menu de opciones y retorna la opcion
///
/// @return
int mostrarMenu();
/// @brief muestra todos los autos cargados
///
/// @param vec pasa el vector de estructura auto y lo recorre
/// @param tam es el tamaño de la estructura auto
/// @param limpiar se le pasa 1 o 0 dependiendo si se desea o no limpiar la pantalla
/// @param marcas pasa el vector de estructura marca y lo recorre
/// @param colores pasa el vector de estructura color y lo recorre
/// @param tam_m es el tamaño de la estructura marca
/// @param tam_c es el tamaño de la estructura color
/// @return
int mostrarAutos(eAuto vec[], int tam, int limpiar,eMarca marcas[],eColor colores[],int tam_m,int tam_c);

/// @brief muestra el auto en la posicion elegida por el usuario
///
/// @param autos pasa el vector de estructura auto y lo recorre
/// @param marcas pasa el vector de estructura marca y lo recorre
/// @param colores pasa el vector de estructura color y lo recorre
/// @param tam_m es el tamaño de la estructura marca
/// @param tam_c es el tamaño de la estructura color
/// @return
int mostrarAuto(eAuto autos,eMarca marcas[],eColor colores[],int tam_m,int tam_c);

/// @brief muestra todas las marcas cargados
///
/// @param vec pasa el vector de estructura y lo recorre
/// @param tam es el tamaño de la estructura
/// @return
int mostrarMarcas(eMarca vec[], int tam);

/// @brief muestra todos los servicios cargados
///
/// @param vec pasa el vector de estructura y lo recorre
/// @param tam es el tamaño de la estructura
/// @return
int mostrarServicios(eServicio vec[], int tam);

/// @brief muestra todos los colores cargados
///
/// @param vec pasa el vector de estructura y lo recorre
/// @param tam es el tamaño de la estructura
/// @return
int mostrarColores(eColor vec[], int tam);

/// @brief  muestra el submenu del modificar
///
/// @return
int subMenuModificarAutos();

/// @brief muestra la marca en la posicion del id que se ingreso
///
/// @param marca muestra los datos de la estructura
/// @return
int mostrarMarca(eMarca marca);

/// @brief muestra el color en la posicion del id que se ingreso
///
/// @param color muestra los datos de la estructura
/// @return
int mostrarColor(eColor color);

/// @brief muestra el servicio en la posicion del id que se ingreso
///
/// @param servicio muestra los datos de la estructura
/// @return
int mostrarServicio(eServicio servicio);

/// @brief muestra el trabajo en la posicion del id que se ingreso
///
/// @param trabajo
/// @return
int mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tam_s);

/// @brief muestra todos los trabajos cargados
///
/// @param vec pasa la estructura y la recorre
/// @param tam es el tamaño de la estructura
/// @param limpiar limpia o no la pantalla segun el nmero que le pase
/// @return
int mostrarTrabajos(eTrabajo vec[], int tam, int limpiar,eServicio servicios[],int tam_s);

/// @brief muestra el sub menu de informes
///
/// @return
int mostrarMenuInformes();
#endif /* MOSTRAR_H_ */
