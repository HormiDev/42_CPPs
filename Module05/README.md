# CPP Module 05 - Exercise 00

## Ejercicio: 00
**Mamá, cuando sea mayor, ¡quiero ser un burócrata!**

### Directorio
`ex00/`

### Archivos a entregar
- `Makefile`
- `main.cpp`
- `Bureaucrat.{h, hpp}`
- `Bureaucrat.cpp`

### Prohibido
- Ninguno.

> Ten en cuenta que las clases de excepción no tienen que estar diseñadas siguiendo la Forma Canónica Ortodoxa. Sin embargo, cualquier otra clase sí debe seguirla.

---

## Descripción

Diseñemos una pesadilla artificial de oficinas, pasillos, formularios y colas de espera.

¿Suena divertido?

¿No?

Mala suerte.

Para empezar, comenzemos con el engranaje más pequeño de esta enorme máquina burocrática: el **Bureaucrat**.

Un **Bureaucrat** debe tener:

- Un **nombre constante**.
- Un **grado** que va desde **1** (el grado más alto posible) hasta **150** (el grado más bajo posible).

Cualquier intento de instanciar un `Bureaucrat` con un grado no válido debe lanzar una excepción:

- `Bureaucrat::GradeTooHighException`
- `Bureaucrat::GradeTooLowException`

---

## Getters

Debes proporcionar getters para ambos atributos:

- `getName()`
- `getGrade()`

---

## Modificación del grado

También debes implementar dos funciones miembro para incrementar o decrementar el grado del burócrata.

Si el grado se sale del rango permitido, ambas funciones deben lanzar las mismas excepciones que el constructor.

Recuerda que:

- El grado **1** es el más alto.
- El grado **150** es el más bajo.

Por lo tanto, incrementar un grado **3** debe dar como resultado un grado **2** para el burócrata.

---

## Excepciones

Las excepciones lanzadas deben poder capturarse utilizando bloques `try` y `catch`:

```cpp
try
{
    /* hacer cosas con burócratas */
}
catch (std::exception &e)
{
    /* manejar la excepción */
}
```

---

## Sobrecarga del operador <<

Debes implementar una sobrecarga del operador de inserción (`<<`) para imprimir la salida con el siguiente formato (sin los signos `<` y `>`):

```text
<nombre>, bureaucrat grade <grado>.
```

Ejemplo:

```text
Alice, bureaucrat grade 42.
```

---

## Pruebas

Como de costumbre, entrega algunas pruebas que demuestren que todo funciona como se espera.

# CPP Module 05 - Exercise 01

## Ejercicio: 01
**¡En formación, reclutas!**

### Directorio
`ex01/`

### Archivos a entregar
- Todos los archivos del ejercicio anterior.
- `Form.{h, hpp}`
- `Form.cpp`

### Prohibido
- Ninguno.

---

## Descripción

Ahora que ya tienes burócratas, vamos a darles algo que hacer.

¿Y qué mejor actividad que rellenar una pila de formularios?

Creemos una clase **Form**.

Una `Form` tiene:

- Un **nombre constante**.
- Un **booleano** que indica si está firmada (al construirse, no lo está).
- Un **grado constante** requerido para firmarla.
- Un **grado constante** requerido para ejecutarla.

Todos estos atributos son **privados**, no **protegidos**.

---

## Reglas de los grados

Los grados de la `Form` siguen las mismas reglas que los del `Bureaucrat`.

Por lo tanto, se lanzarán las siguientes excepciones si el grado de un formulario está fuera de los límites:

- `Form::GradeTooHighException`
- `Form::GradeTooLowException`

---

## Getters

Como antes, escribe getters para todos los atributos.

También debes sobrecargar el operador de inserción (`<<`) para imprimir toda la información del formulario.

---

## Función `beSigned()`

Añade una función miembro `beSigned()` a la clase `Form` que reciba un `Bureaucrat` como parámetro.

Esta función cambia el estado del formulario a **firmado** si el grado del burócrata es lo suficientemente alto (mayor o igual que el requerido).

Recuerda que:

- El grado **1** es superior al grado **2**.

Si el grado del burócrata es demasiado bajo, debe lanzar una excepción:

- `Form::GradeTooLowException`

---

## Función `signForm()`

Después, añade una función miembro `signForm()` a la clase `Bureaucrat`.

Esta función debe llamar a `Form::beSigned()` para intentar firmar el formulario.

Si el formulario se firma correctamente, imprimirá un mensaje similar a:

```text
<bureaucrat> signed <form>
```

En caso contrario, imprimirá un mensaje similar a:

```text
<bureaucrat> couldn't sign <form> because <reason>
```

---

## Pruebas

Implementa y entrega algunas pruebas para asegurarte de que todo funciona como se espera.

# CPP Module 05 - Exercise 02

## Ejercicio: 02
**No, necesitas el formulario 28B, no el 28C...**

### Directorio
`ex02/`

### Archivos a entregar
- `Makefile`
- `main.cpp`
- `Bureaucrat.[{h, hpp},cpp]`
- `AForm.[{h, hpp},cpp]`
- `ShrubberyCreationForm.[{h, hpp},cpp]`
- `RobotomyRequestForm.[{h, hpp},cpp]`
- `PresidentialPardonForm.[{h, hpp},cpp]`

### Prohibido
- Ninguno.

---

## Descripción

Ahora que ya tienes formularios básicos, es el momento de crear algunos más que realmente hagan algo.

En todos los casos, la clase base `Form` debe ser una **clase abstracta** y, por lo tanto, debe renombrarse a **`AForm`**.

Ten en cuenta que los atributos del formulario deben seguir siendo **privados** y que pertenecen a la clase base.

---

## Clases concretas

Añade las siguientes clases concretas.

### `ShrubberyCreationForm`

**Grados requeridos:**

- Firmar: **145**
- Ejecutar: **137**

Crea un archivo llamado:

```text
<target>_shrubbery
```

en el directorio de trabajo y escribe árboles en ASCII dentro del archivo.

---

### `RobotomyRequestForm`

**Grados requeridos:**

- Firmar: **72**
- Ejecutar: **45**

Hace algunos ruidos de taladro y, después, informa de que:

```text
<target> has been robotomized successfully.
```

el **50 % de las veces**.

En caso contrario, informa de que la robotomización ha fallado.

---

### `PresidentialPardonForm`

**Grados requeridos:**

- Firmar: **25**
- Ejecutar: **5**

Informa de que:

```text
<target> has been pardoned by Zaphod Beeblebrox.
```

---

## Constructor

Todas estas clases reciben **un único parámetro** en su constructor:

- El **objetivo** (*target*) del formulario.

Por ejemplo:

```cpp
"home"
```

si quieres plantar arbustos en casa.

---

## Función `execute()`

Ahora añade la siguiente función miembro a la clase base:

```cpp
execute(Bureaucrat const & executor) const
```

e implementa una función que ejecute la acción correspondiente del formulario en cada una de las clases concretas.

Debes comprobar que:

- El formulario está firmado.
- El grado del burócrata que intenta ejecutarlo es lo suficientemente alto.

En caso contrario, debes lanzar la excepción apropiada.

Puedes comprobar estos requisitos en cada clase concreta o hacerlo una sola vez en la clase base y, después, llamar a otra función que ejecute la acción del formulario.

Sin embargo, **una de las dos formas es más elegante que la otra.**

---

## Función `executeForm()`

Por último, añade la siguiente función miembro a la clase `Bureaucrat`:

```cpp
executeForm(AForm const & form) const
```

Esta función debe intentar ejecutar el formulario.

Si la ejecución tiene éxito, imprimirá un mensaje similar a:

```text
<bureaucrat> executed <form>
```

En caso contrario, imprimirá un mensaje de error explícito.

---

## Pruebas

Implementa y entrega algunas pruebas para asegurarte de que todo funciona como se espera.

# CPP Module 05 - Exercise 03

## Ejercicio: 03
**Al menos esto es mejor que preparar café**

### Directorio
`ex03/`

### Archivos a entregar
- Todos los archivos de los ejercicios anteriores.
- `Intern.{h, hpp}`
- `Intern.cpp`

### Prohibido
- Ninguno.

---

## Descripción

Como hacer que los burócratas rellenen formularios todo el día sería demasiado cruel, existen los **becarios (Interns)** para encargarse de esta tarea tan tediosa.

En este ejercicio debes implementar la clase **`Intern`**.

El becario:

- No tiene nombre.
- No tiene grado.
- No tiene ninguna característica especial.

Lo único que les importa a los burócratas es que hagan su trabajo.

Sin embargo, el becario tiene una habilidad clave: la función **`makeForm()`**.

---

## Función `makeForm()`

Esta función recibe **dos cadenas de texto** como parámetros:

1. La primera representa el **nombre del formulario**.
2. La segunda representa el **objetivo (target)** del formulario.

La función devuelve un puntero a un objeto `AForm` (correspondiente al nombre del formulario pasado como parámetro), con su objetivo inicializado con el segundo parámetro.

Si el formulario se crea correctamente, debe imprimir un mensaje similar a:

```text
Intern creates <form>
```

Si el nombre del formulario proporcionado no existe, debe imprimir un mensaje de error explícito.

---

## Restricciones

Debes evitar soluciones ilegibles y desordenadas, como utilizar una estructura excesiva de:

```cpp
if / else if / else
```

Este tipo de enfoque **no será aceptado** durante la evaluación.

**Ya no estás en la Piscine.**

---

## Ejemplo

El siguiente código crea un `RobotomyRequestForm` cuyo objetivo es `"Bender"`:

```cpp
{
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```

---

## Pruebas

Como de costumbre, debes probar todo para asegurarte de que funciona como se espera.