# BSP Visualizer - Module 02 Bonus

Este directorio contiene un visualizador interactivo diseñado para probar y validar la implementación del algoritmo **BSP (Binary Space Partitioning)** de manera gráfica. El objetivo del ejercicio es verificar si un punto dado (las coordenadas del ratón) se encuentra dentro de un triángulo específico.

## 🛠️ ¿Cómo funciona?

El proyecto une el backend en C++ con un frontend en HTML5 a través de un pequeño servidor de Python:

1. **Binario de C++ (`a.out`)**: Toma 8 argumentos correspondientes a las posiciones `x` e `y` de los tres vértices del triángulo y un punto de prueba. Escribe `ok` en la salida estándar si el punto está dentro del triángulo, o `ko` si está fuera.
2. **Frontend Gráfico (`visualizer.html`)**: Permite al usuario hacer 3 clics para crear un triángulo en un Canvas de HTML5. El triángulo se puede animar rebotando por la pantalla. A cada fotograma, el frontend recoge las nuevas posiciones de los vértices y la posición del ratón.
3. **Servidor Puente (`server.py`)**: Un ligero servidor HTTP en Python que recibe la información del front mediante peticiones POST, ejecuta localmente el binario `a.out` con esos parámetros y devuelve la respuesta (`ok`/`ko`) al visualizador.
4. **Respuesta Visual**: Si la respuesta del programa de C++ es afirmativa (`ok`), el triángulo se pintará de verde (el ratón está dentro). Si no (`ko`), se pintará de rojo.

## 🚀 Cómo ejecutarlo

Hemos preparado un script ejecutable para arrancar el entorno completo con un solo comando:

```bash
./start.sh
```

El script se encargará automáticamente de:
- Compilar el código C++ a través de `make` (si es necesario).
- Desplegar el servidor puente de Python en el puerto `8000` en segundo plano.
- Abrir una pestaña en tu navegador predeterminado apuntando a `http://localhost:8000/visualizer.html`.

Para detener el entorno, simplemente presiona `Ctrl+C` en la terminal.

## 🕹️ Uso
- Haz **3 clics** en el recuadro negro del navegador para definir el triángulo.
- Una vez dibujado, pulsa **Play** para ver cómo el triángulo se mueve y rebota por el espacio de trabajo.
- Mueve el ratón por encima del triángulo: cambiará a color verde dinámicamente cada vez que tu programa de C++ detecte que el cursor está dentro de su área.
- Puedes utilizar el botón **Borrar** para reiniciar la posición y definir un nuevo triángulo.
