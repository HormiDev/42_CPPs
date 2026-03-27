# MÓDULO_04

## Polimorfismo de Subtipo, Clases Abstractas e Interfaces

---

## Resumen

Este documento contiene los ejercicios del Módulo 04 de los módulos de C++.

---

# ex00 – Polymorphism

Para cada ejercicio, debes proporcionar **las pruebas más completas posibles**.  

Los **constructores y destructores** de cada clase deben mostrar mensajes específicos.  
⚠️ No uses el mismo mensaje para todas las clases.

---

## Clase base

Comienza implementando una clase base simple llamada **Animal**.

Esta clase tendrá:

- Un atributo protegido:
  - `std::string type;`

---

## Clases derivadas

Implementa las siguientes clases que heredan de **Animal**:

- **Dog**
- **Cat**

Estas clases deben inicializar su atributo `type` de la siguiente manera:

- Dog → `"Dog"`  
- Cat → `"Cat"`  

El atributo `type` de **Animal** puede dejarse vacío o con un valor de tu elección.

---

## Funciones miembro

Todos los animales deben poder usar la función:

```````cpp
makeSound()
```````

- Esta función imprimirá un sonido apropiado.  
- ⚠️ Por ejemplo, **los gatos no ladran**.

Para que el polimorfismo funcione correctamente:

- `makeSound()` debe ser **virtual** en la clase base.  
- Debe ser **sobrescrita** en **Dog** y **Cat**.

---

## Comportamiento esperado

Al ejecutar el siguiente código:

```````cpp
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound(); // debe mostrar el sonido del gato
    j->makeSound(); // debe mostrar el sonido del perro
    meta->makeSound();

    return 0;
}
```````

Debe imprimirse:

- El tipo correcto de cada objeto  
- El sonido específico de cada clase derivada  
- ⚠️ No debe usarse la implementación de **Animal** cuando se llama desde un puntero a Animal que apunta a Dog o Cat  

---

## Clase incorrecta (Wrong)

Para asegurarte de que entiendes cómo funciona el polimorfismo, implementa:

- **WrongAnimal**
- **WrongCat** (hereda de WrongAnimal)

⚠️ En este caso:

- **NO** debes usar funciones virtuales correctamente  
- Si reemplazas Animal y Cat por WrongAnimal y WrongCat en el `main`, entonces **WrongCat debe mostrar el sonido de WrongAnimal**

Esto demuestra qué ocurre cuando **no se usa polimorfismo correctamente**.

---

## Pruebas

Debes añadir más pruebas además de las proporcionadas para comprobar:

- Que los **constructores y destructores** se llaman en el orden correcto  
- Que `makeSound()` funciona correctamente con polimorfismo  
- Que el comportamiento incorrecto de **WrongAnimal/WrongCat** es evidente  
- Que `getType()` devuelve el valor adecuado

---

# ex01 – I don’t want to set the world on fire

Los **constructores y destructores** de cada clase deben mostrar mensajes específicos.  

---

## Clase Brain

Implementa una clase llamada **Brain**.

Esta clase tendrá:

- Un atributo privado:
  - `std::string ideas[100];`

---

## Modificaciones en Dog y Cat

Las clases **Dog** y **Cat** deberán contener:

- Un atributo privado:
  - `Brain* brain;`

---

## Gestión de memoria

Debes gestionar correctamente la memoria dinámica:

- En el **constructor** de Dog y Cat:
  - Inicializar `brain` usando:
  
```cpp
brain = new Brain();
```

- En el **destructor**:
  - Liberar la memoria correctamente:

```cpp
delete brain;
```

⚠️ Es fundamental evitar **memory leaks**.

---

## Creación de animales

En tu función `main`, debes:

- Crear un array de objetos tipo **Animal**  
- La mitad deben ser **Dog**  
- La otra mitad deben ser **Cat**

Al final del programa:

- Recorrer el array  
- Eliminar cada elemento usando punteros a **Animal**

---

## Comportamiento esperado

- Debes eliminar los objetos como **Animal**, no como Dog o Cat  
- Los **destructores correctos** deben llamarse en el orden adecuado  
- No debe haber **fugas de memoria**

---

## Copias profundas (Deep Copy)

Una copia de **Dog** o **Cat** **NO debe ser superficial**.

Esto significa que:

- Cada objeto debe tener su **propio Brain independiente**  
- No deben compartir el mismo puntero  

Debes implementar correctamente:

- Constructor de copia  
- Operador de asignación  

Y comprobar que:

- Modificar el `Brain` de una copia **no afecta al original**

---

## Ejemplo

```cpp
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; // no debe generar fugas de memoria
    delete i;

    return 0;
}
```

---

## Pruebas

Debes añadir más pruebas además de las proporcionadas para comprobar:

- Que los **constructores y destructores** se ejecutan correctamente  
- Que no existen **memory leaks**  
- Que la **deep copy** funciona correctamente  
- Que cada objeto tiene su propio **Brain independiente**  

---

# ex02 – Abstract class

Crear objetos de **Animal** ya no tiene sentido. Después de todo, ¡no hacen ningún sonido!

Para evitar errores, la clase base **Animal** no debe poder ser instanciada.

---

## Clase abstracta

Debes modificar la clase **Animal** para que sea una **clase abstracta**.

Esto implica:

- No se podrán crear instancias de Animal directamente  
- Solo se podrán crear objetos de clases derivadas como **Dog** o **Cat**

---

## Implementación

Para lograrlo:

- Convierte la función `makeSound()` en una **función virtual pura**

'''cpp
virtual void makeSound() const = 0;
'''

Esto hará que **Animal** sea abstracta automáticamente.

---

## Comportamiento esperado

- No debe ser posible hacer:

'''cpp
Animal a; // ❌ error de compilación
'''

- El resto del programa debe seguir funcionando igual que antes  
- **Dog** y **Cat** deben seguir implementando `makeSound()` correctamente  

---

## Notas

- Puedes, si lo deseas, cambiar el nombre de la clase a:
  - **AAnimal** (añadiendo un prefijo `A`)  

- Esto es opcional, pero ayuda a indicar que es una clase abstracta  

---

## Pruebas

Debes comprobar que:

- No se puede instanciar **Animal**  
- **Dog** y **Cat** funcionan correctamente  
- El polimorfismo sigue funcionando como en ejercicios anteriores  
- No hay errores de compilación relacionados con funciones puras no implementadas 

---

# ex03 – Interface & recap

Las interfaces no existen en C++98 (ni siquiera en C++20). Sin embargo, las **clases abstractas puras** suelen usarse como interfaces.

En este ejercicio, implementarás interfaces para consolidar lo aprendido en el módulo.

---

## Clase base: AMateria

Completa la definición de la clase **AMateria** e implementa las funciones necesarias:

'''cpp
class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const & type);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
'''

- `getType()` devuelve el tipo de la materia  
- `clone()` es **virtual pura**  
- `use()` puede ser redefinida por las clases derivadas  

---

## Clases concretas: Ice y Cure

Implementa las siguientes clases derivadas de **AMateria**:

- **Ice**
- **Cure**

### Reglas

- Sus tipos deben ser:
  - `"ice"` para Ice  
  - `"cure"` para Cure  

- La función `clone()` debe devolver:
  - Una **nueva instancia del mismo tipo**

---

## Comportamiento de use()

La función:

'''cpp
use(ICharacter& target)
'''

Debe mostrar:

- Ice:
  - `* shoots an ice bolt at <name> *`

- Cure:
  - `* heals <name>'s wounds *`

Donde `<name>` es el nombre del personaje objetivo (sin los símbolos `< >`).

---

## Interfaz ICharacter

Implementa la clase concreta **Character** basada en la interfaz:

'''cpp
class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
'''

---

## Clase Character

### Inventario

- Tiene un inventario de **4 slots**  
- Inicialmente vacío  
- Se rellena de izquierda a derecha (slot 0 → 3)

### Funciones

- `equip(AMateria* m)`
  - Añade la materia en el primer slot libre  
  - Si está lleno, no hace nada  

- `unequip(int idx)`
  - Elimina la materia del slot  
  - ⚠️ **NO debe hacer delete**  

- `use(int idx, ICharacter& target)`
  - Usa la materia del slot indicado  

---

## Gestión de memoria

- Debes evitar **memory leaks**  
- Guarda las direcciones antes de hacer `unequip()` si es necesario  
- Las materias deben liberarse correctamente cuando corresponda  

---

## Copia profunda

La clase **Character** debe implementar:

- Constructor de copia  
- Operador de asignación  

Reglas:

- La copia debe ser **profunda**  
- Las materias existentes deben eliminarse antes de copiar las nuevas  
- Cada Character debe tener sus propias instancias independientes  

---

## Interfaz IMateriaSource

Implementa la clase **MateriaSource** basada en:

'''cpp
class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};
'''

---

## Clase MateriaSource

### Funciones

- `learnMateria(AMateria*)`
  - Guarda una copia de la materia  
  - Máximo 4 materias almacenadas  

- `createMateria(std::string const & type)`
  - Devuelve una nueva materia del tipo solicitado  
  - Si no existe, devuelve `0`  

---

## Comportamiento esperado

MateriaSource debe poder:

- Aprender “plantillas” de materias  
- Crear nuevas instancias a partir de un string  

---

## Ejemplo

'''cpp
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}
'''

Salida esperada:

'''
* shoots an ice bolt at bob *
* heals bob's wounds *
'''

---

## Pruebas

Debes añadir más pruebas además de las proporcionadas para comprobar:

- Que `equip`, `unequip` y `use` funcionan correctamente  
- Que no hay **memory leaks**  
- Que la **deep copy** funciona correctamente  
- Que MateriaSource crea correctamente las materias  
- Que el sistema soporta distintos tipos de **AMateria**  

---

⚠️ Nota:

- Puedes aprobar el módulo sin completar este ejercicio  