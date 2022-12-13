# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"

int	main ()
{
	int buffer_size;
	int	fd;
	int	bytes_read;
	char	*buffer;
	int	i;
	
	buffer_size = 1024;
	buffer = (char *)malloc(buffer_size * sizeof(char));
	if (buffer == NULL) 
		return 0;
	fd = open("txt_to_read.txt", O_RDONLY);
	bytes_read = read(fd, buffer, buffer_size);
	i = 0;
	if (bytes_read == -1)
		return 0;
	while (i < bytes_read)
	{ 
		if (buffer[i] == '\n') 
		{ 
			buffer[i] = '\0';
			break; 
		}
		while (buffer[i] == '\0')
		{
			ft_putchar_fd(buffer[i], 1);
		}
		i++;
	}
}


/*

const int BUFFER_SIZE = 1024;
char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
if (buffer == NULL) 
	printf("Error al asignar memoria para el buffer\n"); return 1;

Utiliza la función read para leer la línea del archivo y almacenarla en el buffer:

int bytes_read = read(fileno(file), buffer, BUFFER_SIZE);
if (bytes_read == -1)
	rintf("Error al leer el archivo\n"); return 1;

Busca el salto de línea en el buffer y reemplázalo por un carácter de fin de cadena:

for (int i = 0; i < bytes_read; i++) 
{ 
	if (buffer[i] == '\n') 
		{ 
			buffer[i] = '\0';
			break; 
		} 
} 
Imprime la línea del archivo en el terminal:

printf("La línea del archivo es: %s\n", buffer); 

Cierra el archivo y libera la memoria asignada dinámicamente para el buffer:

fclose(file); 

free(buffer); 

A continuación se muestra un ejemplo completo del programa:

#include <stdio.h> #include <stdlib.h> 
int main() 
{
	 // Abre el archivo en modo de lectura 
	 FILE *file = fopen("nombre_del_archivo.txt", "r");
	if (file == NULL) 
	{
		printf("Error al abrir el archivo\n");
		return 1;
	}
		  // Asigna memoria dinámicamente para el buffer 

	char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));


Nombre de función

Prototipo char *get_next_line(int fd);

Parámetros fd: File descriptor del que leer
Valor devuelto Si todo va bien: la línea leída

En caso de fallo o si la lectura termina: NULL
Funciones autorizadas
read, malloc, free

Descripción Escribe una función que devuelva la línea leída de
un file descriptor

• Llamar a tu función get_next_line de manera repetida (por ejemplo, usando un
bucle) te permitirá leer el contenido del archivo hacia el que apunta el file descriptor,
línea a línea, hasta el final.
• Tu función deberá devolver la línea que se acaba de leer.
Si no hay nada más que leer o si ha ocurrido un error, deberá devolver NULL.
• Asegúrate de que tu función se comporta adecuadamente cuando lea de un archivo
y cuando lea de stdin.

• Ten en cuenta que la línea devuelta debe terminar con el caracter
n, excepto si se ha llegado al final del archivo y esté no termina con un caracter
n.


• Tu programa debe compilar con el flag -D BUFFER_SIZE=xx. 
Este flag se utilizará para determinar el tamaño del buffer de las lecturas de tu get_next_line()
Este parámetro será modificado por tus evaluadores y por Moulinette para probar tu
programa.
Debemos ser capaces de compilar este proyecto con y sin el flag -D BUFFER_SIZE, junto a los flags habituales. 
Puedes elegir el valor por defecto que prefieras.

• El programa se compilará de la siguiente forma (se utiliza como ejemplo un tamaño de buffer de 42):
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.

• Se considera que get_next_line() tiene un comportamiento indeterminado si el
archivo al que apunta el fd ha cambiado desde la última vez que se llamó, siempre
que read() no haya llegado al final del archivo.

• Se considera que get_next_line() tiene un comportamiento indeterminado cuando 
lo que se lee es un archivo binario. Sin embargo, puedes inmplementar alguna
manera lógica de sortear este problema, si quieres.

¿Funciona correctamente tu get_next_line si el BUFFER_SIZE es 9999?
¿Y si es 1? ¿Qué tal con 10000000? ¿Sabes por qué?

Intenta leer lo menos posible cada vez que se llame a get_next_line().

Si encuentras un salto de línea, deberás devolver la línea actual. 

No leas el archivo entero y luego proceses cada línea.
Prohibido
• No se permite la utilización de tu libft en este proyecto.
• Se prohibe la utilización de lseek
• Se prohibe la utilización de variables globales.

Aquí tienes los requisitos de la parte bonus:

• Desarrolla get_next_line() con una sola variable estática.
• Tu get_next_line tiene que ser capaz de gestionar múltiples fd a la vez. 

Es decir, si tienes tres fd disponibles para lectura (por ejemplo: 3, 4 y 5), debes poder utilizar
get_next_line una vez sobre el fd 3, otra vez sobre el fd 4, y otra vez sobre el fd 5 de forma alterna. 

Y sí, no debe perder el hilo de lectura de cada uno de los fd.

Añade el sufijo _bonus.[c\h] a los archivos de esta parte bonus. Esto quiere decir
que además de los archivos de la parte obligatoria, tienes que entregar los tres archivos
siguientes:
• get_next_line_bonus.c
• get_next_line_bonus.h
• get_next_line_utils_bonus.c

La parte bonus solo será evaluada si la parte obligatoria está PERFECTA. 

*/