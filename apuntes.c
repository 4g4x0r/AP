#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define    AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define    AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"
//--------------------------------------------------------- ayuda
int    ayuda(char *menu)
{
  if (strcmp(menu,"ayuda") == 0)
  {
    char    *list_colores[]={VERDE_T, AMARILLO_T, AZUL_T, ROJO_T};
    char        *list_secciones[]={"Pentest", "Arch", "C", "Un ejemplo"};
    int recorrer = sizeof(list_secciones) / sizeof(char *);
    int numero = 1;
    system("clear");
    //printf("\n1:"VERDE_T " Fuzzing"RESET_COLOR"\n2: "AMARILLO_T "Ajustes Arch\n"RESET_COLOR"3: "AZUL_T "Hydra\n"RESET_COLOR "4: "ROJO_T "VPN"RESET_COLOR);
    for (size_t i = 0; i < recorrer; i++){
      printf(MAGENTA_T "%i: " "%s" "%s\n" RESET_COLOR, numero, list_colores[i], list_secciones[i]);
      numero++;
    }
    printf("\n\n           Comandos útiles:\n-------------------------------------\nayuda        comandos        ejemplo\n-------------------------------------\n");
    return (0);
  }
  else {
    return (1);
  }
}
//--------------------------------------------------------- 1
int    uno(char *menu)
{
  if (strcmp(menu, "1") == 0)
  {  
    system("clear");
    printf("\nEl"ROJO_T " Fuzzing " RESET_COLOR "consiste en enviar datos aleatorios, inválidos y no esperados mediante los formularios de entrada de una aplicación buscando alguna vulnerabilidad en ella.\n");
    return (0);
  }
  else {
    return (1);
  }
}
//--------------------------------------------------------- ejemplo 1
int    ejemplo(char *menu)
{
  if (strcmp(menu,"ejemplo") == 0)
  { 
    system("clear");
    printf("\nwfuzz -c -t 400 --hc=404 -w primer/diccionario -w segundo/diccionario https://10.10.20.4/FUZZ.FUZ2Z\n");
    return (0);
  }
  else {
    return (1);
  }
}
//--------------------------------------------------------- comandos
int    comandos(char *menu)
{
  if (strcmp(menu,"comandos") == 0)
  {
    char        *list_comandos[]={ "ayuda", "comandos", "ejemplo" };
    int recorrer = sizeof(list_comandos) / sizeof(char *);
    system("clear");
    //printf("\nComandos disponibles\n"AMARILLO_T "\nAyuda\nComandos\nEjemplo\n" RESET_COLOR);
    printf("\n");
    for (size_t i = 0; i < recorrer; i++) {
      printf(AMARILLO_T "· %s\n" RESET_COLOR, list_comandos[i]);
    }                                                   
    return (0);  
  }
  else {
  return (1);
  }
}
//--------------------------------------------------------- main
int main(void)
{
  char  menu[20];
  printf(NEGRO_T "Bienvenido a mis apuntes, ejecuta <" MAGENTA_T "ayuda" NEGRO_T ">\n"RESET_COLOR);
  //fgets(menu, 20, stdin);
  while(strcmp(menu,"salir") != 0)
  { 
    scanf("%[^\n]", menu); 
    if (ayuda(menu) == 1 && uno(menu) == 1 && ejemplo(menu) == 1 && comandos(menu) == 1)
    {
      printf("\nComando no reconocido.\n");
      while (getchar() != '\n');
      printf("\nElige: ");
      scanf("%[^\n]", menu);
    }
    ayuda(menu);
    uno(menu);
    ejemplo(menu);
    comandos(menu);
    if (strcmp(menu, "salir") != 0)
      printf("\nElige: ");
      while (getchar() != '\n');
  }
  return (0);
}
