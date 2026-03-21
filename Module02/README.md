# MODULO_02

## Polimorfismo ad-hoc, sobrecarga de operadores  
## y la Forma Canónica Ortodoxa

---

## Reglas generales

### Compilación
- Compila tu código con `c++` y las banderas `-Wall -Wextra -Werror`  
- Tu código debe compilar también si agregas la bandera `-std=c++98`  

---

### Formato y convencenciones de nombres
- Los directorios de los ejercicios se nombrarán así: `ex00`, `ex01`, ..., `exn`  
- Nombra tus archivos, clases, funciones, funciones miembro y atributos como se indica en las guías.  
- Escribe los nombres de las clases en formato **UpperCamelCase**.  

Los archivos que contienen código de clases deben nombrarse según el nombre de la clase:

ClassName.hpp
ClassName.cpp


- Cada mensaje mostrado por pantalla debe terminar con un salto de línea y enviarse a la salida estándar.  
- No se aplica Norminette en C++. Aun así, escribe código limpio, legible y comprensible para tus evaluadores.

---

### Permitido / Prohibido

- Puedes usar casi todo de la biblioteca estándar de C++.  
- Está prohibido usar bibliotecas externas (incluyendo C++11 y superiores, o Boost).  
- Las funciones `printf()`, `malloc()` y `free()` están prohibidas.  
- Salvo indicación contraria, están prohibidas:
  - `using namespace`
  - `friend`

- Solo puedes usar la STL en los Módulos 08 y 09.  
  No puedes usar contenedores (`vector`, `map`, etc.) ni `<algorithm>` en este módulo.

---

## Nuevas reglas (desde este módulo)

Desde ahora, todas tus clases deben implementarse en **Forma Canónica Ortodoxa**, salvo que se indique lo contrario.

Cada clase debe contener obligatoriamente:

- Constructor por defecto  
- Constructor de copia  
- Operador de asignación por copia  
- Destructor  

Además:

- El código debe dividirse en:
  - Archivo de cabecera (`.hpp`)
  - Archivo de implementación (`.cpp`)

- Ninguna función (excepto plantillas) debe implementarse en el header.  
- Debes proteger tus headers con `include guards`.  
- No debe haber fugas de memoria.

---

# ex00 – My First Class in Orthodox Canonical Form

## Objetivo

Crear una clase `Fixed` que represente un número en **punto fijo**.

Crees que conoces los números enteros y los números de coma flotante. Qué tierno.
Por favor, lee este artículo de 3 páginas (1, 2, 3) para descubrir que no es así. Adelante, léelo.

Hasta hoy, todos los números que has utilizado en tu código eran básicamente enteros o números de coma flotante, o alguna de sus variantes (short, char, long, double, etc.).

Después de leer el artículo anterior, es razonable asumir que los números enteros y los de coma flotante tienen características opuestas.

Pero hoy, las cosas van a cambiar. Vas a descubrir un nuevo y asombroso tipo de número: los números de punto fijo. Ausentes desde siempre en los tipos escalares de la mayoría de los lenguajes, los números de punto fijo ofrecen un valioso equilibrio entre rendimiento, exactitud, rango y precisión. Esto explica por qué son especialmente útiles en gráficos por computadora, procesamiento de sonido o programación científica, por mencionar algunos ejemplos.

Dado que C++ carece de números de punto fijo, vas a añadirlos. Este artículo de Berkeley es un buen punto de partida. Si no tienes idea de qué es la Universidad de Berkeley, lee esta sección de su página de Wikipedia.

## Requisitos

### Miembros privados
- Un entero que almacene el valor del número en punto fijo.  
- Un entero estático constante que represente la cantidad de bits fraccionarios (valor fijo: 8).

### Miembros públicos
- Constructor por defecto (inicializa el valor en 0).  
- Constructor de copia.  
- Operador de asignación.  
- Destructor.  
- `int getRawBits(void) const;`  
- `void setRawBits(int const raw);`

## Objetivo pedagógico

- Comprender la Forma Canónica Ortodoxa.  
- Entender constructor de copia y operador de asignación.  
- Introducción a números en punto fijo.

### ejecuta este codigo:
```c++
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}
```
### La salida deveria verse similar a esta:
```bash
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
```

---

# ex01 – Towards a more useful fixed-point number class

Ahora la clase `Fixed` debe ser más completa.

El ejercicio anterior fue un buen comienzo, pero nuestra clase es bastante inútil. Solo puede representar el valor 0.0.

Añade los siguientes constructores públicos y funciones miembro públicas a tu clase:

- Un constructor que reciba un entero constante como parámetro.
Debe convertirlo al valor correspondiente de punto fijo. El número de bits fraccionales debe inicializarse a 8, como en el ejercicio 00.

- Un constructor que reciba un número de coma flotante constante como parámetro.
Debe convertirlo al valor correspondiente de punto fijo. El número de bits fraccionales debe inicializarse a 8, como en el ejercicio 00.

- Una función miembro float toFloat(void) const;
que convierta el valor de punto fijo a un número de coma flotante.

- Una función miembro int toInt(void) const;
que convierta el valor de punto fijo a un número entero.

Y añade también la siguiente función a los archivos de la clase Fixed:

- Una sobrecarga del operador de inserción («) que inserte una representación en coma flotante del número de punto fijo en el objeto de flujo de salida pasado como parámetro.

## Agregar

- Constructor que reciba un `int`.  
- Constructor que reciba un `float`.  
- `float toFloat(void) const;`  
- `int toInt(void) const;`  
- Sobrecarga del operador `<<` para mostrar el número como `float`.

## Autorizado
- `roundf()` de `<cmath>`

## Objetivo pedagógico

- Conversiones entre representaciones numéricas.  
- Sobrecarga de operadores externos.  
- Comprender precisión y redondeo.

### Running this code:
```c++
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
```

### La salida deveria verse similar a esta:
```bash
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```

---

# ex02 – Now we're talking

### Sobrecargar operadores

Agrega funciones miembro públicas a tu clase para sobrecargar los siguientes operadores:

- Los 6 operadores de comparación: >, <, >=, <=, == y !=.
- Los 4 operadores aritméticos: +, -, * y /.
- Los 4 operadores de incremento/decremento (pre-incremento y post-incremento, pre-decremento y post-decremento), que aumentarán o disminuirán el valor de punto fijo en la menor cantidad representable ϵ, tal que 1 + ϵ > 1.

Agrega estas cuatro funciones miembro públicas sobrecargadas a tu clase:
- Una función miembro estática min que tome dos referencias a números de punto fijo como parámetros y devuelva una referencia al menor de ellos.
- Una función miembro estática min que tome dos referencias a números de punto fijo constantes como parámetros y devuelva una referencia al menor de ellos.
- Una función miembro estática max que tome dos referencias a números de punto fijo como parámetros y devuelva una referencia al mayor de ellos.
- Una función miembro estática max que tome dos referencias a números de punto fijo constantes como parámetros y devuelva una referencia al mayor de ellos.

### Depende de ti probar cada característica de tu clase. Sin embargo, al ejecutar el siguiente código:
```c++
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

```

### Debería producir una salida similar a la siguiente (para mayor claridad, los mensajes del constructor/destructor se han eliminado en el ejemplo a continuación):
```bash
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```

### Si en algún momento realizas una división entre 0, es aceptable que el programa se bloquee.

### Operadores de comparación
`>`, `<`, `>=`, `<=`, `==`, `!=`

### Operadores aritméticos
`+`, `-`, `*`, `/`

### Incremento y decremento
- Pre-incremento  
- Post-incremento  
- Pre-decremento  
- Post-decremento  

Estos deben modificar el valor por la unidad mínima representable (ϵ).

## Funciones estáticas

- `min(Fixed&, Fixed&)`  
- `min(const Fixed&, const Fixed&)`  
- `max(Fixed&, Fixed&)`  
- `max(const Fixed&, const Fixed&)`

## Objetivo pedagógico

- Polimorfismo ad-hoc.  
- Sobrecarga de operadores.  
- Diferencia entre pre y post incremento.  
- Diseño correcto de clases numéricas.

---

# ex03 – BSP

BSP significa **Binary Space Partitioning**.

## Objetivo

Determinar si un punto está dentro de un triángulo.

## Clase `Point`

Debe implementarse en Forma Canónica Ortodoxa.

### Miembros privados
- `Fixed const x;`  
- `Fixed const y;`

### Miembros públicos
- Constructor por defecto (0,0).  
- Constructor con dos `float`.  
- Constructor de copia.  
- Operador de asignación.  
- Destructor.

## Función a implementar

```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);

