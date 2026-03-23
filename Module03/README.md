# MÓDULO_03

## Herencia

---

## Resumen

Este documento contiene los ejercicios del Módulo 03 de los módulos de C++.

---

# ex00 – Aaaaand... OPEN!

Primero, debes implementar una clase. ¡Qué original!  

Se llamará **ClapTrap** y tendrá los siguientes atributos privados, inicializados con los valores entre paréntesis:

- `Name`: se pasa como parámetro al constructor.  
- `Hit points` (10): representa la salud del ClapTrap.  
- `Energy points` (10)  
- `Attack damage` (0)

Agrega las siguientes funciones miembro públicas para que ClapTrap se comporte de forma realista:

- `void attack(const std::string& target);`  
- `void takeDamage(unsigned int amount);`  
- `void beRepaired(unsigned int amount);`  

- Cuando ClapTrap ataque, causará que su objetivo pierda `<attack damage>` puntos de vida.  
- Cuando ClapTrap se repare, recuperará `<amount>` puntos de vida.  
- Atacar y repararse cuesta 1 punto de energía cada acción.  
- Por supuesto, ClapTrap no puede hacer nada si no tiene puntos de vida o energía.  

⚠️ Dado que estos ejercicios son introductorios, las instancias de ClapTrap **no interactuarán entre sí**, y los parámetros **no se referirán a otra instancia de ClapTrap**.

---

### Mensajes

En todas las funciones miembro debes mostrar un mensaje describiendo lo que ocurre. Por ejemplo, la función `attack()` podría mostrar algo como (sin los corchetes angulares):

```c++
ClapTrap <name> attacks <target>, causing <damage> points of damage!
```

Los constructores y el destructor también deben mostrar un mensaje, para que los evaluadores puedan ver fácilmente que se han llamado.

Implementa tus propias pruebas para asegurarte de que tu código funcione como se espera.

# ex01 – Serena, my love!

Como nunca hay suficientes ClapTraps, ahora vas a crear un robot derivado.  

Se llamará **ScavTrap** y heredará los constructores y destructor de **ClapTrap**.  
Sin embargo, sus constructores, destructor y la función `attack()` **deben mostrar mensajes diferentes**, para reflejar que cada ClapTrap es consciente de su individualidad.  

⚠️ Nota: Debe mostrarse correctamente la cadena de construcción/destrucción en tus pruebas.  
- Cuando se crea un **ScavTrap**, primero se construye un **ClapTrap**.  
- La destrucción ocurre en orden inverso.  

---

### Atributos

**ScavTrap** usará los atributos de **ClapTrap** (asegúrate de actualizar ClapTrap si es necesario) y debe inicializarlos así:

- `Name`: se pasa como parámetro al constructor.  
- `Hit points`: 100, representa la salud del ScavTrap.  
- `Energy points`: 50  
- `Attack damage`: 20  

---

### Funciones miembro públicas

- `void attack(const std::string& target);`  
  - Debe mostrar un mensaje distinto al de ClapTrap.  
- `void guardGate();`  
  - Esta función mostrará un mensaje indicando que el **ScavTrap** está ahora en **modo Guardián de la Puerta**.  

---

### Pruebas

No olvides agregar más pruebas a tu programa para asegurarte de que:

- Los mensajes de construcción y destrucción se muestran en el orden correcto.  
- `attack()` funciona mostrando el mensaje adecuado.  
- `guardGate()` muestra correctamente el estado de ScavTrap.  

# ex02 – Repetitive work

Crear ClapTraps probablemente ya esté empezando a cansarte.  

Ahora, implementa una clase **FragTrap** que herede de **ClapTrap**.  
Es muy similar a **ScavTrap**, pero sus mensajes de construcción y destrucción deben ser diferentes.  

⚠️ Debe mostrarse correctamente la cadena de construcción/destrucción en tus pruebas:  
- Cuando se crea un **FragTrap**, primero se construye un **ClapTrap**.  
- La destrucción ocurre en orden inverso.  

---

### Atributos

**FragTrap** usará los atributos de **ClapTrap**, pero con estos valores iniciales:

- `Name`: se pasa como parámetro al constructor.  
- `Hit points`: 100, representa la salud del FragTrap.  
- `Energy points`: 100  
- `Attack damage`: 30  

---

### Funciones miembro públicas

- `void attack(const std::string& target);`  
  - Debe mostrar un mensaje distinto al de ClapTrap y ScavTrap.  
- `void highFivesGuys(void);`  
  - Esta función muestra un **mensaje positivo solicitando un high-five** en la salida estándar.  

---

### Pruebas

No olvides agregar más pruebas a tu programa para asegurarte de que:

- Los mensajes de construcción y destrucción se muestran en el orden correcto.  
- `attack()` funciona mostrando el mensaje adecuado.  
- `highFivesGuys()` muestra correctamente el mensaje de high-five. 

# ex03 – ¡Ahora sí que es raro!

En este ejercicio, vas a crear un monstruo: un **ClapTrap** que es mitad **FragTrap**, mitad **ScavTrap**.  
Se llamará **DiamondTrap** y heredará de **FragTrap** **y** **ScavTrap**. ¡Esto es muy arriesgado!  

---

### Atributos

**DiamondTrap** tendrá un atributo privado llamado `name`.  
Este atributo debe tener **exactamente el mismo nombre de variable que en la clase base ClapTrap**, sin referirse al nombre del robot directamente.  

Ejemplos:  
- Si la variable de ClapTrap es `name`, la variable de DiamondTrap será `name`.  
- Si la variable de ClapTrap es `_name`, la variable de DiamondTrap será `_name`.  

Sus atributos y funciones miembro se heredarán de las clases padre:  

- `Name`: se pasa como parámetro al constructor.  
- `ClapTrap::name`: se inicializa con el parámetro del constructor + sufijo `"_clap_name"`.  
- `Hit points`: de **FragTrap**  
- `Energy points`: de **ScavTrap**  
- `Attack damage`: de **FragTrap**  
- `attack()`: de **ScavTrap** 

---

### Funciones miembro públicas

Además de las funciones especiales heredadas de sus clases padre, **DiamondTrap** tendrá su propia habilidad especial:  

- `void whoAmI();`  
  - Esta función muestra tanto su propio `name` como el `name` de **ClapTrap**.  

⚠️ La instancia de ClapTrap dentro de DiamondTrap se **crea una sola vez**, y solo una vez. Hay un truco en esto.  

---

### Pruebas

No olvides agregar más pruebas a tu programa para asegurarte de que:  

- Los mensajes de construcción y destrucción se muestran correctamente.  
- `attack()` funciona como se espera (heredado de ScavTrap).  
- `whoAmI()` muestra correctamente ambos nombres.

⚠️ Nota: 
- Conoces las banderas de compilador `-Wshadow` y `-Wno-shadow`.  
- Puedes aprobar este módulo **sin completar el ejercicio 03**.  