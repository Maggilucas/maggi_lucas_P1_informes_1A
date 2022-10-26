
#ifndef HARDCODEO_H_
#define HARDCODEO_H_

/// @brief hardcodea los valores de la estructura marca
///
/// @param pId guarda el numero de id hardcodeado
/// @param vec pasa la estructura marca y la recorre
/// @param tam es el tamaño maximo de la estructura
/// @param cant es la cantidad de elementos de la estructura que quiero hardcodea
/// @return
int hardcodearMarcas(int* pId ,eMarca vec[], int tam, int cant);

/// @brief hardcodea los valores de la estructura color
///
/// @param pId guarda el numero de id hardcodeado
/// @param vec pasa la estructura color y la recorre
/// @param tam es el tamaño maximo de la estructura
/// @param cant es la cantidad de elementos de la estructura que quiero hardcodea
/// @return
int hardcodearColores(int* pId ,eColor vec[], int tam, int cant);

/// @brief hardcodea los valores de la estructura servicio
///
/// @param pId guarda el numero de id hardcodeado
/// @param vec pasa la estructura servicio y la recorre
/// @param tam es el tamaño maximo de la estructura
/// @param cant es la cantidad de elementos de la estructura que quiero hardcodear
/// @return
int hardcodearServicios(int* pId ,eServicio vec[], int tam, int cant);

int hardcodearTrabajos(int* pId ,eTrabajo vec[], int tam, int cant);

#endif /* HARDCODEO_H_ */
