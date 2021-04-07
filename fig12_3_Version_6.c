#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct estuctura{
    char *nombre;
    char *grupo;
    long numero;

}contacto;

typedef struct{
    contacto registro;
    struct Nodo* ptrNext;
}Nodo;
  
Nodo* anterior = NULL;  
Nodo* header = NULL;
Nodo* footer = NULL;

//FUNCION PARA INSERTAR Y CREAR EL NODO
void insertar(Nodo* *nodo, char* nombre, char*grupo,long numero){ 

    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->registro.nombre=malloc(strlen(nombre)+1); //Resevo Memoria para el nombre
    nuevo->registro.grupo=malloc(strlen(grupo)+1); //Resevo Memoria para el Grupo
    
    
    
    if (nuevo != NULL){     //espacio disponible
        strcpy(nuevo->registro.nombre,nombre); //Coloca el nombre
        strcpy(nuevo->registro.grupo,grupo);//Coloca el grupo
        nuevo->registro.numero = numero;    //Coloca el numero
        nuevo->ptrNext = NULL;              //El nodo no se une a otro
        *nodo = nuevo;
      //  strcpy((*nodo)->registro.nombre,nuevo->registro.nombre); //Coloca el nombre
      //  strcpy((*nodo)->registro.grupo,nuevo->registro.grupo);//Coloca el grupo
        
        /*Insertar nodo al principio de la lista */
        if (header == NULL){
             header = *nodo;
             footer = *nodo;   
        } else { /*Insertar entre el ptrptranteriorerior y el footer*/
                anterior=footer;
                anterior->ptrNext = footer;
                footer->ptrNext=*nodo;
                footer=*nodo;
            }
        
    }    
    
}
//FUNCION PARA ELIMINAR NODO
void removeNodo(char* nombre){
    Nodo* aux;
    Nodo* ptranterior = NULL;
    Nodo* ptractual = NULL;
   int igualdad=-1;
    
    if (header == NULL){
        printf("Lista Vacia \r\n");
        return;
    }/*fin del if*/  
          /*Elimina el primer elemento con el nombre de la persona*/
    for(int k=0; k<15; k++){
          if(header->registro.nombre[k] != nombre[k]){
                igualdad=-1; // No son iguales
                break;
          }else{
               igualdad=-2;  // Igual
           }
        }
     
      if(igualdad==-2){
            aux = header;
            header = header->ptrNext;
            free(aux);
           return;
        } 

        /*Eliminar los nodos siguientes*/
        else { 
            ptranterior = header;
            ptractual = header->ptrNext;
            while (ptractual != NULL && igualdad !=-2){
                for(int k=0; k<15; k++){
                    //printf("actual[%c]\tnombre[%c]\r\n",ptractual->registro.nombre[k],nombre[k]);
                   if(ptractual->registro.nombre[k] != nombre[k]){
                        ptranterior = ptractual; //Guarda el puntero aqui
                        ptractual = ptractual->ptrNext; //pasa al proximo puntero y verifica si es ese
                        igualdad=-1;
                        break;
                    }   else{
                            igualdad=-2; // encontro el nombre
                        }
                }/*fin del for*/
                
            }/*fin del while*/
            if( igualdad != -1){
                aux = ptractual;
                ptranterior->ptrNext = ptractual->ptrNext; //ptranterior Apunta al que esta mas alante del puntero actual
                free(aux);
                return;
            }/*fin del if*/
       }/*fin del else*/
             
}     
//RECORRER LA LISTA
void walkList(){
    printf("Lista: \r\n");
    Nodo* i;
    i = (Nodo*)malloc(sizeof(Nodo));
    i = header;
    if(i == NULL){
        printf("Lista Vacia\r\n");
        return;
    }
    while (i != NULL)
    {
        printf("\r\n");
        printf("Nombre: %s\r\n",i->registro.nombre);
        printf("Grupo: %s\r\n",i->registro.grupo);
        printf("Numero: %ld\r\n",i->registro.numero);
        i = i->ptrNext;
    }
    printf("\r\n");
    
}
//LIBERAR MEMORIA
void free_memory(){
  Nodo* i=header;
  if(i == NULL){
    printf("Lista Vacia");
    return;
  }
  while (i != NULL) {
     header=i->ptrNext;
     free(i);
     i = header; 
  }
  header = NULL;
  footer = NULL;
  printf("Memoria Liberada\r\n");
}
//BUSCAR ELEMENTO EN LA LISTA POR NOMBRE
void search(char* nombre){
    int contador=0;
    Nodo* i = header;
    int igualdad =0;
    int position = 1;
    if(i == NULL){
        printf("Lista Vacia \r\n");
        return;
    }
    while (i != NULL)
    {  

      for(int k=0; k<15; k++){
          if(i->registro.nombre[k] != nombre[k]){
                igualdad=-1;
                i = i->ptrNext;
                position++;
                break;
          }else{
               igualdad=-2;
           }
        }
     
      if(igualdad==-2){
           printf("El Nombre es: %s   posicion [%d]  de lista\r\n",i->registro.nombre,position);
           return;
        }
        
    }
    printf("El nombre: %s  no se encuentra en la lista\r\n",nombre);
    printf("\r\n");   
}
//MENU DE ELECION
void menu(){
    printf("        Elija una opcion        \r\n\r\n");
    printf("   1.  Insertar Elemnto a la Lista\r\n");
    printf("   2.  Eliminar Elemento de la Lista\r\n");
    printf("   3.  Buscar Elemento en la Lista\r\n");
    printf("   4.  Ver la LIsta Completa\r\n");
    printf("   5.  Eliminar toda la Lista\r\n");
    printf("   6.  salir\r\n");
    printf("? : ");
}
//LIMPIA EL STRING
void clearchar(char v[15]){
    int i;
    for ( i = 0; i < 15; i++)
    {
        v[i] = '\0';
    }
    
}
int main(){
    char Nombre[15]={'\0'};
     char Nombre1[15]={'\0'}; 
    char Grupo[15];
    int i=0;
    Nodo* *nodo = NULL;
    long numero=1;
    unsigned char eleccion;
    menu();
    fflush(stdin);
    scanf("%u",&eleccion);

    while (eleccion<6)
    {
        switch (eleccion)
        {
          case 1:
            printf("Ingrese NOmbre:\r\n");   
            scanf("%s",Nombre);
            printf("Ingrese Grupo:\r\n"); 
            scanf("%s",Grupo); 
            printf("Numero: ");
            scanf("%ld",&numero);
            insertar(&nodo,Nombre,Grupo,numero);
            clearchar(Nombre);
            clearchar(Grupo);
         break;
         case 2:
            printf("Ingrese el Nombre a remover: ");
            scanf("%s",Nombre1);
            removeNodo(Nombre1);
            clearchar(Nombre1);
         break; 
           case 3:
              printf("ingrese nombre a buscar: ");
              scanf("%s",Nombre1);
              search(Nombre1);
              clearchar(Nombre1);
             break;  
            case 4:
              walkList();
              break;
              case 5:
                free_memory();
                break;     
         default:
            return;
         break;
        }/*Fin del switch*/
        menu();
        scanf("%u",&eleccion);
    }/*Fin del while*/
    
   

   return 0;
}