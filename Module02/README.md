# MODULO_02

## Polimorfismo ad-hoc, sobrecarga de operadores  
## y la Forma Canónica Ortodoxa

---

## Reglas generales

### Compilación
• Compila tu código con `c++` y las banderas `-Wall -Wextra -Werror`  
• Tu código debe compilar también si agregas la bandera `-std=c++98`  

---

### Formato y convencenciones de nombres
• Los directorios de los ejercicios se nombrarán así: `ex00`, `ex01`, ..., `exn`  
• Nombra tus archivos, clases, funciones, funciones miembro y atributos como se indica en las guías.  
• Escribe los nombres de las clases en formato **UpperCamelCase**.  

Los archivos que contienen código de clases deben nombrarse según el nombre de la clase:

ClassName.hpp
ClassName.cpp


• Cada mensaje mostrado por pantalla debe terminar con un salto de línea y enviarse a la salida estándar.  
• No se aplica Norminette en C++. Aun así, escribe código limpio, legible y comprensible para tus evaluadores.

---

### Permitido / Prohibido

• Puedes usar casi todo de la biblioteca estándar de C++.  
• Está prohibido usar bibliotecas externas (incluyendo C++11 y superiores, o Boost).  
• Las funciones `printf()`, `malloc()` y `free()` están prohibidas.  
• Salvo indicación contraria, están prohibidas:
  - `using namespace`
  - `friend`

• Solo puedes usar la STL en los Módulos 08 y 09.  
  No puedes usar contenedores (`vector`, `map`, etc.) ni `<algorithm>` en este módulo.

---

## Nuevas reglas (desde este módulo)

Desde ahora, todas tus clases deben implementarse en **Forma Canónica Ortodoxa**, salvo que se indique lo contrario.

Cada clase debe contener obligatoriamente:

• Constructor por defecto  
• Constructor de copia  
• Operador de asignación por copia  
• Destructor  

Además:

• El código debe dividirse en:
  - Archivo de cabecera (`.hpp`)
  - Archivo de implementación (`.cpp`)

• Ninguna función (excepto plantillas) debe implementarse en el header.  
• Debes proteger tus headers con `include guards`.  
• No debe haber fugas de memoria.

---

# ex00 – My First Class in Orthodox Canonical Form

## Objetivo

Crear una clase `Fixed` que represente un número en **punto fijo**.

## Requisitos

### Miembros privados
• Un entero que almacene el valor del número en punto fijo.  
• Un entero estático constante que represente la cantidad de bits fraccionarios (valor fijo: 8).

### Miembros públicos
• Constructor por defecto (inicializa el valor en 0).  
• Constructor de copia.  
• Operador de asignación.  
• Destructor.  
• `int getRawBits(void) const;`  
• `void setRawBits(int const raw);`

## Objetivo pedagógico

• Comprender la Forma Canónica Ortodoxa.  
• Entender constructor de copia y operador de asignación.  
• Introducción a números en punto fijo.

---

# ex01 – Towards a more useful fixed-point number class

Ahora la clase `Fixed` debe ser más completa.

## Agregar

• Constructor que reciba un `int`.  
• Constructor que reciba un `float`.  
• `float toFloat(void) const;`  
• `int toInt(void) const;`  
• Sobrecarga del operador `<<` para mostrar el número como `float`.

## Autorizado
• `roundf()` de `<cmath>`

## Objetivo pedagógico

• Conversiones entre representaciones numéricas.  
• Sobrecarga de operadores externos.  
• Comprender precisión y redondeo.

---

# ex02 – Now we're talking

## Sobrecargar operadores

### Operadores de comparación
`>`, `<`, `>=`, `<=`, `==`, `!=`

### Operadores aritméticos
`+`, `-`, `*`, `/`

### Incremento y decremento
• Pre-incremento  
• Post-incremento  
• Pre-decremento  
• Post-decremento  

Estos deben modificar el valor por la unidad mínima representable (ϵ).

## Funciones estáticas

• `min(Fixed&, Fixed&)`  
• `min(const Fixed&, const Fixed&)`  
• `max(Fixed&, Fixed&)`  
• `max(const Fixed&, const Fixed&)`

## Objetivo pedagógico

• Polimorfismo ad-hoc.  
• Sobrecarga de operadores.  
• Diferencia entre pre y post incremento.  
• Diseño correcto de clases numéricas.

---

# ex03 – BSP

BSP significa **Binary Space Partitioning**.

## Objetivo

Determinar si un punto está dentro de un triángulo.

## Clase `Point`

Debe implementarse en Forma Canónica Ortodoxa.

### Miembros privados
• `Fixed const x;`  
• `Fixed const y;`

### Miembros públicos
• Constructor por defecto (0,0).  
• Constructor con dos `float`.  
• Constructor de copia.  
• Operador de asignación.  
• Destructor.

## Función a implementar

```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);

