
#ifndef ESTRUCTURA_H_
#define ESTRUCTURA_H_



typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char descripcion[20];

}eMarca;

typedef struct
{
	int id;
	char descripcion[20];

}eColor;

typedef struct
{
	int id;
	int idMarca;
	int idColor;
	char caja;
	int isEmpty;

}eAuto;

typedef struct
{
	int id;
	char descripcion[25];
	float precio;

}eServicio;

typedef struct
{
	int id;
	int idAuto;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajo;
/// @brief inicializa el is empty para que no devuelva basura
///
/// @param vec pasa la estructura para recorrerla
/// @param tam es el tamaño de la estructura
/// @return
int inicializarAuto(eAuto vec[], int tam);

/// @brief busca un espacio libre en el vector de estructura auto
///
/// @param pIndice se usa para encontrar el espacio o tirar error en caso que no.
/// @param vec pasa la estructura para recorrerla
/// @param tam es el tamaño de la estructura
/// @return
int buscarLibreAuto(int* pIndice, eAuto vec[], int tam);

/// @brief  carga un auto con datos
///
/// @param pId se pasa por puntero el id que tendran los autos de manera autoincremental
/// @param vec pasa la estructura auto para recorrerla
/// @param tam  es el tamaño de la estructura auto
/// @param marca pasa la estructura marca para recorrerla
/// @param tam_m es el tamaño de la estructura marca
/// @param colores pasa la estructura color para recorrerla
/// @param tam_c es el tamaño de la estructura color
/// @return
int altaAuto(int* pId, eAuto vec[], int tam,eMarca marca[],int tam_m,eColor colores[],int tam_c);

/// @brief busca un auto en el vector de estructura auto por id,segun el id ingresado por el usuario
///
/// @param pIndice es el id del auto
/// @param id es el id que ingresa el usuario para elegir un auto
/// @param vec pasa la estructura auto para recorrerla
/// @param tam es el tamaño de la estructura auto
/// @return
int buscarAuto(int* pIndice, int id, eAuto vec[], int tam);

/// @brief pide al usuario un id y si conside con el id de un auto le permite modificar 2 campos.
///
/// @param vec pasa la estructura auto para recorrerla
/// @param tam es el tamaño de la estructura auto
/// @param colores pasa la estructura color para recorrerla
/// @param tam_c es el tamaño de la estructura color
/// @param marcas pasa la estructura marca para recorrerla
/// @param tam_m es el tamaño de la estructura marca
/// @return
int modificarAuto( eAuto vec[], int tam,eColor colores[], int tam_c,eMarca marcas[],int tam_m);


/// @brief permite una baja logica de un auto mediante  el ingreso de id
///
/// @param vec pasa la estructura auto para recorrerla
/// @param tam es el tamaño de la estructura auto
/// @param marcas pasa la estructura marca para recorrerla
/// @param colores pasa la estructura color para recorrerla
/// @param tam_m es el tamaño de la estructura marca
/// @param tam_c es el tamaño de la estructura color
/// @return
int bajaAuto(eAuto vec[], int tam,eMarca marcas[],eColor colores[],int tam_m,int tam_c);

/// @brief carga los valores de una posicion en el array de estructura auto
///
/// @param pAuto pasa la estructura auto por puntero
/// @param marca pasa la estructura marca por puntero
/// @param colores pasa la estructura color por puntero
/// @param tam_m es el tamaño de la estructura marca
/// @param tam_c es el tamaño de la estructura color
/// @return
int cargarAuto(eAuto* pAuto,eMarca* marca,eColor* colores,int tam_m,int tam_c);

/// @brief ordena el array de estructura auto por id de marca y luego por tipo de caja
///
/// @param vec pasa la estructura auto para recorrerla
/// @param tam es el tamaño de la estructura auto
/// @param marca pasa la estructura marca para recorrerla
/// @param tam_m es el tamaño de la estructura marca
/// @return
int ordenarAutos(eAuto vec[], int tam,eMarca marca [],int tam_m);




#endif /* ESTRUCTURA_H_ */
