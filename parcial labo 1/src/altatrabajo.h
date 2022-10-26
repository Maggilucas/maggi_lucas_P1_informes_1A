

#ifndef ALTATRABAJO_H_
#define ALTATRABAJO_H_

/// @brief da de alta un trabajo y lo carga con datos
///
/// @param pId se pasa por puntero el id que tendran los trabajos de manera autoincremental
/// @param vec pasa la estructura auto para recorrerla
/// @param tam es el tamaño de la estructura auto
/// @param trabajo pasa la estructura trabajo para recorrerla
/// @param tam_t es el tamaño de la estructura trabajo
/// @param servicio pasa la estructura servicio para recorrerla
/// @param tam_s es el tamaño de la estructura servicio
/// @param fecha pasa la estructura fecha para recorrerla
/// @param colores pasa la estructura color para recorrerla
/// @param tam_c es el tamaño de la estructura color
/// @param marca pasa la estructura marca para recorrerla
/// @param tam_m es el tamaño de la estructura marca
/// @return
int altaTrabajo(int* pId, eAuto vec[], int tam,eTrabajo trabajo[],int tam_t,eServicio servicio[],int tam_s,eFecha fecha,eColor colores[],int tam_c,eMarca marca[],int tam_m);

/// @brief busca un espacio libre en el vector de estructura trabajo
///
/// @param pIndice se usa para encontrar el espacio o tirar error en caso que no.
/// @param vec pasa la estructura para recorrerla
/// @param tam es el tamaño de la estructura
/// @return
int buscarLibreTrabajo(int* pIndice, eTrabajo vec[], int tam);

/// @brief inicializa el is empty para que no devuelva basura
///
/// @param vec pasa la estructura para recorrerla
/// @param tam es el tamaño de la estructura
/// @return
int inicializarTrabajo(eTrabajo vec[], int tam);

int buscarTrabajo(int* pIndice, int id, eTrabajo vec[], int tam);

/// @brief carga los valores de una posicion en el array de estructura trabajo
///
/// @param pTrabajo pasa la estructura trabajo para recorrerla
/// @param autos pasa la estructura autos para recorrerla
/// @param servicios pasa la estructura servicios para recorrerla
/// @param tam es el tamaño de la estructura auto
/// @param tam_s es el tamaño de la estructura servicio
/// @param marca pasa la estructura marca para recorrerla
/// @param tam_m es el tamaño de la estructura marca
/// @param colores pasa la estructura colores para recorrerla
/// @param tam_c es el tamaño de la estructura color
/// @param fecha pasa la estructura fecha para recorrerla y cargarle valores
/// @return
int cargarTrabajo(eTrabajo* pTrabajo,eAuto* autos,eServicio* servicios,int tam,int tam_s,eMarca marca[],int tam_m,eColor colores[],int tam_c,eFecha fecha);
#endif /* ALTATRABAJO_H_ */
