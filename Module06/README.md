# CPP Module 06

## Regla general del módulo

La siguiente regla se aplica a todo el módulo y es obligatoria.

Para cada ejercicio, la conversión de tipos debe gestionarse utilizando un tipo específico de casting.

Tu elección será revisada durante la defensa.

---

# CPP Module 06 - Exercise 00

## Ejercicio: 00
**Conversión de tipos escalares**

### Directorio
`ex00/`

### Archivos a entregar
- `Makefile`
- `*.cpp`
- `*.{h, hpp}`

### Autorizado
- Cualquier función para convertir de un string a un `int`, un `float` o un `double`. Esto será de ayuda, pero no hará todo el trabajo.

---

## Descripción

Escribe una clase `ScalarConverter` que contenga únicamente un método estático `convert`, que reciba como parámetro la representación en forma de string de un literal de C++ en su forma más común y muestre su valor en la siguiente serie de tipos escalares:

- `char`
- `int`
- `float`
- `double`

Como esta clase no necesita almacenar absolutamente nada, no debe poder ser instanciada por los usuarios.

Excepto para los parámetros de tipo `char`, solo se utilizará la notación decimal.

Ejemplos de literales `char`: `'c'`, `'a'`, ...

Para simplificar las cosas, ten en cuenta que no se deben utilizar caracteres no imprimibles como entradas. Si una conversión a `char` no es imprimible, muestra un mensaje informativo.

Ejemplos de literales `int`: `0`, `-42`, `42`...

Ejemplos de literales `float`: `0.0f`, `-4.2f`, `4.2f`...

También tienes que gestionar estos pseudo-literales (ya sabes, por ciencia): `-inff`, `+inff` y `nanf`.

Ejemplos de literales `double`: `0.0`, `-4.2`, `4.2`...

También tienes que gestionar estos pseudo-literales (ya sabes, por diversión): `-inf`, `+inf` y `nan`.

Escribe un programa para probar que tu clase funciona como se espera.

Primero tienes que detectar el tipo del literal recibido como parámetro, convertirlo de string a su tipo real y, después, convertirlo explícitamente a los otros tres tipos de datos. Por último, muestra los resultados como se indica a continuación.

Si una conversión no tiene sentido o produce un desbordamiento, muestra un mensaje para informar al usuario de que la conversión de tipo es imposible. Incluye cualquier cabecera que necesites para gestionar los límites numéricos y los valores especiales.

```text
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
```

```text
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
```

```text
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

---

# CPP Module 06 - Exercise 01

## Ejercicio: 01
**Serialización**

### Directorio
`ex01/`

### Archivos a entregar
- `Makefile`
- `*.cpp`
- `*.{h, hpp}`

### Prohibido
- Ninguno.

---

## Descripción

Implementa una clase `Serializer` que no pueda ser inicializada por el usuario de ninguna manera, con los siguientes métodos estáticos:

```cpp
uintptr_t serialize(Data* ptr);
```

Recibe un puntero y lo convierte al tipo entero sin signo `uintptr_t`.

```cpp
Data* deserialize(uintptr_t raw);
```

Recibe un parámetro entero sin signo y lo convierte en un puntero a `Data`.

Escribe un programa para probar que tu clase funciona como se espera.

Debes crear una estructura `Data` no vacía (es decir, que tenga miembros de datos).

Utiliza `serialize()` sobre la dirección del objeto `Data` y pasa su valor de retorno a `deserialize()`. Después, asegúrate de que el valor de retorno de `deserialize()` se compare como igual al puntero original.

No olvides entregar los archivos de tu estructura `Data`.

---

# CPP Module 06 - Exercise 02

## Ejercicio: 02
**Identificar el tipo real**

### Directorio
`ex02/`

### Archivos a entregar
- `Makefile`
- `*.cpp`
- `*.{h, hpp}`

### Prohibido
- `std::typeinfo`

---

## Descripción

Implementa una clase `Base` que tenga únicamente un destructor virtual público.

Crea tres clases vacías, `A`, `B` y `C`, que hereden públicamente de `Base`.

Estas cuatro clases no tienen que estar diseñadas siguiendo la Forma Canónica Ortodoxa.

Implementa las siguientes funciones:

```cpp
Base* generate(void);
```

Instancia aleatoriamente `A`, `B` o `C` y devuelve la instancia como un puntero a `Base`. Siéntete libre de utilizar lo que quieras para implementar la elección aleatoria.

```cpp
void identify(Base* p);
```

Muestra el tipo real del objeto apuntado por `p`: `"A"`, `"B"` o `"C"`.

```cpp
void identify(Base& p);
```

Muestra el tipo real del objeto referenciado por `p`: `"A"`, `"B"` o `"C"`. Está prohibido utilizar un puntero dentro de esta función.

Está prohibido incluir la cabecera `typeinfo`.

Escribe un programa para probar que todo funciona como se espera.
