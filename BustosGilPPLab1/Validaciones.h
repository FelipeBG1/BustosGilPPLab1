#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED
int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max);
int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max);
int getCadena(char* pAux,int limite);
int getInt(int* pAux);
int isInt(char *pAux);
int isFloat(char* pAux);
int getFloat(float*pAux);
int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);
int isLetras(char*pAux);
int validateFlag(int* flag, char* msgError);
