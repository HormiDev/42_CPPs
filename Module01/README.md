# MODULO_01

## Reglas generales

### Compilación
• Compila tu código con c++ y las banderas -Wall -Wextra -Werror  
• Tu código aún debe compilar si agregas la bandera -std=c++98  

### Formato y convenciones de nombres
• Los directorios de los ejercicios se nombrarán así: ex00, ex01, ..., exn  
• Nombra tus archivos, clases, funciones, funciones miembro y atributos según se indica en las guías.  
• Escribe los nombres de las clases en formato UpperCamelCase.  
  Los archivos que contienen código de clases siempre se nombrarán según el nombre de la clase. Por ejemplo:  
  ClassName.hpp/ClassName.h, ClassName.cpp o ClassName.tpp.  
  Entonces, si tienes un archivo de encabezado que contiene la definición de una clase `BrickWall` que representa un muro de ladrillos, su nombre será BrickWall.hpp.  
• A menos que se indique lo contrario, cada mensaje de salida debe terminar con un carácter de nueva línea y mostrarse en la salida estándar.  
• ¡Adiós Norminette! No se aplica un estilo de codificación en los módulos de C++.  
  Puedes seguir tu favorito. Pero recuerda que el código que tus evaluadores no puedan entender es código que no pueden calificar. Haz tu mejor esfuerzo por escribir código limpio y legible.  

### Permitido/Prohibido
Ya no estás programando en C. ¡Es hora de C++! Por lo tanto:  
• Se permite usar casi todo de la biblioteca estándar. Por lo tanto, en lugar de apegarte a lo que ya conoces, sería inteligente usar las versiones en C++ de las funciones de C que ya conoces tanto como sea posible.  
• Sin embargo, no puedes usar ninguna otra biblioteca externa. Esto significa que C++11 (y formas derivadas) y las bibliotecas Boost están prohibidas.  
  Las siguientes funciones también están prohibidas: *printf(), *alloc() y free().  
  Si las usas, tu nota será 0 y nada más.  
• Ten en cuenta que, a menos que se indique explícitamente lo contrario, las palabras clave `using namespace <ns_name>` y `friend` están prohibidas.  
  De lo contrario, tu nota será -42.  
• Solo puedes usar la STL en los Módulos 08 y 09. Esto significa:  
  no Containers (vector/list/map, etc.) y no Algorithms (cualquier cosa que requiera incluir el encabezado <algorithm>) hasta entonces.  
  De lo contrario, tu nota será -42.  

### Algunos requisitos de diseño
• Las fugas de memoria también ocurren en C++. Cuando asignes memoria (usando la palabra clave `new`), debes evitar fugas de memoria.  
• Desde el Módulo 02 hasta el Módulo 09, tus clases deben estar diseñadas en la Forma Canónica Ortodoxa, excepto cuando se indique explícitamente lo contrario.  
• Cualquier implementación de función en un archivo de encabezado (excepto plantillas de función) significa 0 en el ejercicio.  
• Debes poder usar cada uno de tus encabezados de manera independiente de los demás. Por lo tanto, deben incluir todas las dependencias que necesiten.  
  Sin embargo, debes evitar el problema de doble inclusión agregando `include guards`. De lo contrario, tu nota será 0.  

### Lectura recomendada
• Puedes agregar algunos archivos adicionales si lo necesitas (por ejemplo, para dividir tu código).  
  Como estas tareas no son verificadas por un programa, siéntete libre de hacerlo siempre que entregues los archivos obligatorios.  
• A veces, las guías de un ejercicio parecen cortas, pero los ejemplos pueden mostrar requisitos que no están explícitamente escritos en las instrucciones.  
• Lee cada módulo completamente antes de empezar. ¡De verdad, hazlo!  
• ¡Por Odín, por Thor! ¡Usa tu cerebro!

```
⚠️ ​Con respecto al Makefile para proyectos en C++, se aplican las mismas reglas que en C (ver el capítulo de la Norm sobre el Makefile).
```
```
💡 ​Tendrás que implementar muchas clases. Esto puede parecer tedioso, a menos que seas capaz de automatizar tareas en tu editor de texto favorito.
```
```
​ℹ️ Se te da un cierto grado de libertad para completar los ejercicios. Sin embargo, sigue las reglas obligatorias y no seas perezoso. ¡Podrías perderte mucha información útil! No dudes en leer sobre conceptos teóricos.
```

## ex00 BraiiiiiiinnnzzzZ

Primero, implementa una clase `Zombie` con un atributo privado `std::string name`.  
Agrega una función miembro `void announce(void);` a la clase `Zombie`.  
Los zombis se anuncian de la siguiente manera:  

`<nombre>: BraiiiiiiinnnzzzZ...`

(No imprimas los signos `<` y `>`).  
Por ejemplo, para un zombi llamado Foo, el mensaje sería:  

`Foo: BraiiiiiiinnnzzzZ...`

### Funciones a implementar

1. **`Zombie* newZombie(std::string name);`**  
   - Crea un zombi, le asigna un nombre y lo devuelve para que pueda usarse fuera del alcance de la función.

2. **`void randomChump(std::string name);`**  
   - Crea un zombi, le asigna un nombre y hace que se anuncie a sí mismo.

### Objetivo del ejercicio

Determinar en qué caso es mejor asignar zombis en **stack** o en **heap**.  

Los zombis deben destruirse cuando ya no se necesiten.  
El **destructor** debe imprimir un mensaje con el nombre del zombi para propósitos de depuración.

---

## ex01 Moar brainz!

¡Hora de crear una horda de zombis!  
Implementa la siguiente función en el archivo correspondiente:  

`Zombie* zombieHorde(int N, std::string name);`  

Debe asignar `N` objetos `Zombie` en una sola reserva de memoria.  
Luego, debe inicializar a los zombis, dándoles a todos el nombre pasado como parámetro.  
La función debe devolver un puntero al primer zombi.

### Pruebas

Implementa tus propias pruebas para asegurarte de que tu función `zombieHorde()` funciona como se espera.  
Intenta llamar a `announce()` para cada uno de los zombis.

### Liberación de memoria

No olvides usar `delete` para liberar todos los zombis y comprobar que no haya fugas de memoria.

---

## ex02 HI THIS IS BRAIN

Escribe un programa que contenga:  
• Una variable `string` inicializada con el valor `HI THIS IS BRAIN`.  
• `stringPTR`: un puntero a la cadena.  
• `stringREF`: una referencia a la cadena.  

Tu programa debe imprimir:  
• La dirección de memoria de la variable `string`.  
• La dirección de memoria almacenada en `stringPTR`.  
• La dirección de memoria almacenada en `stringREF`.  

Y luego:  
• El valor de la variable `string`.  
• El valor apuntado por `stringPTR`.  
• El valor apuntado por `stringREF`.  

El objetivo de este ejercicio es desmitificar las referencias, que pueden parecer completamente nuevas.  
Aunque existen algunas pequeñas diferencias, esto es simplemente otra sintaxis para algo que ya haces: la manipulación de direcciones.

---

## ex03 Unnecessary violence

Implementa una clase `Weapon` que tenga:  
• Un atributo privado `type`, que es una cadena (`string`).  
• Una función miembro `getType()` que devuelva una referencia constante a `type`.  
• Una función miembro `setType()` que asigne a `type` el nuevo valor pasado como parámetro.  

Ahora, crea dos clases: `HumanA` y `HumanB`. Ambas tienen un `Weapon` y un nombre.  
También tienen una función miembro `attack()` que muestre (sin los signos `<` y `>`):  

<nombre> attacks with their <weapon type>  

`HUmanA` y `HumanB` son casi idénticas excepto por estos dos pequeños detalles:  
• Mientras que `HumanA` recibe el `Weapon` en su constructor, `HumanB` no.  
• `HumanB` puede que no siempre tenga un arma, mientras que `HumanA` siempre estará armado.  

Si tu implementación es correcta, ejecutar el siguiente código imprimirá un ataque con `crude spiked club` seguido de un segundo ataque con `some other type of club` en ambos casos de prueba:  
```c++
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
```
No olvides comprobar que no haya fugas de memoria.

```
💡​ ¿En qué caso crees que sería mejor usar un puntero a Weapon? ¿Y una referencia a Weapon? ¿Por qué? Piénsalo antes de empezar este ejercicio.
```

---

## ex04 Sed is for losers

Crea un programa que reciba tres parámetros en el siguiente orden: un nombre de archivo y dos cadenas, s1 y s2.  

El programa debe abrir el archivo <filename> y copiar su contenido en un nuevo archivo <filename>.replace, reemplazando todas las ocurrencias de s1 por s2.  

Está prohibido usar funciones de manipulación de archivos de C; hacerlo se considerará trampa.  
Se permite usar todas las funciones miembro de la clase `std::string`, excepto `replace`. ¡Úsalas sabiamente!  

Por supuesto, debes manejar entradas inesperadas y errores.  
Debes crear y entregar tus propias pruebas para asegurarte de que tu programa funcione como se espera.

---

## ex05Harl 2.0

¿Conoces a Harl? Todos lo conocemos, ¿verdad? En caso de que no, a continuación se muestran los tipos de comentarios que Harl hace, clasificados por niveles:  

• Nivel `DEBUG`: Los mensajes de depuración contienen información contextual. Se usan principalmente para el diagnóstico de problemas.  
Ejemplo: `I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!`  

• Nivel `INFO`: Estos mensajes contienen información extensa. Son útiles para rastrear la ejecución del programa en un entorno de producción.  
Ejemplo: `I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!`  

• Nivel `WARNING`: Los mensajes de advertencia indican un posible problema en el sistema. Sin embargo, se puede manejar o ignorar.  
Ejemplo: `I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.`  

• Nivel `ERROR`: Estos mensajes indican que ocurrió un error irrecuperable.  
Generalmente es un problema crítico que requiere intervención manual.  
Ejemplo: `This is unacceptable! I want to speak to the manager now.`  

Vas a automatizar a Harl. No será difícil, ya que siempre dice lo mismo.  
Debes crear una clase `Harl` con las siguientes funciones miembro privadas:  

• void debug( void );  
• void info( void );  
• void warning( void );  
• void error( void );  

Harl también tiene una función miembro pública que llama a las cuatro funciones anteriores según el nivel pasado como parámetro:  

void complain( std::string level );  

El objetivo de este ejercicio es usar punteros a funciones miembro. Esto no es opcional.  
Harl debe quejarse sin usar un bosque de if/else if/else. ¡Él no lo piensa dos veces!  

Crea y entrega pruebas para mostrar que Harl se queja mucho. Puedes usar los ejemplos de comentarios listados arriba o elegir tus propios comentarios.

---

## ex05Harl 2.0

A veces no quieres prestar atención a todo lo que Harl dice.  
Implementa un sistema para filtrar lo que Harl dice dependiendo de los niveles de log que quieras escuchar.  

Crea un programa que reciba como parámetro uno de los cuatro niveles.  
Mostrará todos los mensajes de ese nivel y superiores. Por ejemplo:  

```
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.

[ ERROR ]
This is unacceptable! I want to speak to the manager now.

$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

Aunque hay varias formas de lidiar con Harl, una de las más efectivas es apagarlo.  

Nombra tu ejecutable `harlFilter`.  

Debes usar, y quizás descubrir, la instrucción `switch` en este ejercicio.

```
​ℹ️ Puedes aprobar este módulo sin hacer el ejercicio 06.
```