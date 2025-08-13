# MODULO_00

## ex00 Megaphone

Debes crear un programa llamado `megaphone` que:

Tome los argumentos de la línea de comandos.

Los convierta a mayúsculas.

Los imprima todos juntos en una sola línea.

Si no se pasa ningún argumento, el programa debe imprimir: `* LOUD AND UNBEARABLE FEEDBACK NOISE *`
```shell
./megaphone Hello word
HELLO WORD

./megaphone `Happy 2025!!!`
HAPPY 2025!!!

./megaphone 
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

## ex01 PhoneBook (Agenda Telefónica)

Bienvenido al proyecto de agenda telefónica al estilo de los años 80. Se debe crear un programa en C++ que simule un software de agenda básica, capaz de almacenar contactos, buscarlos y mostrarlos.

### Requisitos

Debes implementar dos clases:

### 1. Contact
- Representa un contacto de la agenda.
- Campos obligatorios:
  - Nombre (First Name)
  - Apellido (Last Name)
  - Apodo (Nickname)
  - Número de teléfono (Phone Number)
  - Secreto más oscuro (Darkest Secret)
- Ningún campo puede quedar vacío.

### 2. PhoneBook
- Contiene un array de 8 contactos como máximo.
- Si se intenta añadir un 9º contacto, debe reemplazar el más antiguo.
- No se permite la asignación dinámica de memoria.

### Comandos

Al iniciar, el programa aceptará los siguientes comandos:

### ADD
- Pide al usuario que introduzca la información de un nuevo contacto, campo por campo.
- Añade el contacto a la agenda.
- No se puede guardar contactos con campos vacíos.

### SEARCH
- Muestra la lista de contactos en una tabla con columnas:
  - Índice | Nombre | Apellido | Apodo
- Cada columna debe tener un ancho de 10 caracteres, alineado a la derecha, separado por `|`.
- Si un dato es más largo, debe truncarse con un punto (`.`).
- Luego, solicita al usuario el índice del contacto a mostrar:
  - Si el índice es inválido, debe manejarse correctamente.
  - Si es válido, muestra toda la información del contacto (un campo por línea).

### EXIT
- Cierra el programa.
- Los contactos no se guardan (se pierden al salir).

### Otros comandos
- Se ignorarán.

### Reglas importantes
- La agenda debe ser una instancia de la clase PhoneBook.
- Los contactos deben ser instancias de la clase Contact.
- Diseña las clases correctamente:
  - Lo que siempre se use dentro de la clase → private
  - Lo que deba accederse desde fuera → public

### Ejecución
Dale un nombre relevante al ejecutable, por ejemplo:
```bash
$> ./phonebook
```

# ex02 dream_job

Tu primer día en GlobalBanksters United como desarrollador comienza con un reto: recrear un archivo fuente que fue eliminado accidentalmente. Tus compañeros no usan Git y comparten el código mediante USB, lo que ha causado la pérdida del archivo `Account.cpp`.

## Objetivo
- **Recrear el archivo `Account.cpp`** a partir de:
  - El archivo de cabecera `Account.hpp` (que sí fue salvado).
  - Un archivo de **log** que muestra cómo debe ser el resultado de la ejecución.
  - El archivo de pruebas `tests.cpp`.

## Condiciones
- Tu implementación de la clase `Account` debe ser coherente con la información dada en `Account.hpp`.
- El programa debe compilar correctamente junto con `tests.cpp`.
- La salida del programa debe coincidir exactamente con la del archivo de log, **excepto los timestamps**, que obviamente variarán.

## Instrucciones
1. Lee y analiza el archivo `Account.hpp` para entender la estructura de la clase.
2. Revisa el archivo de log para deducir el comportamiento y la salida esperada de cada método.
3. Implementa la clase en el archivo `Account.cpp`.
4. Compila el proyecto junto con `tests.cpp`:
    ```bash
    $> c++ -Wall -Wextra -Werror tests.cpp Account.cpp -o account_test
    ```
5. Ejecuta y verifica que la salida sea igual al archivo de log (ignorando las marcas de tiempo).

## Objetivo final
El proyecto estará completo cuando el programa:
- Compile sin errores ni warnings.
- Produzca la salida esperada.

---

¡Buena suerte, desarrollador!
