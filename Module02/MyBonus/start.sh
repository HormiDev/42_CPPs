#!/bin/bash

# Compilar si es necesario
make

# Iniciar el servidor de Python en segundo plano
echo "Iniciando servidor en http://localhost:8000..."
python3 server.py &
SERVER_PID=$!

# Esperar un momento para que el servidor arranque
sleep 1

# Abrir el navegador (intentará usar el navegador por defecto del sistema)
if command -v xdg-open > /dev/null; then
  xdg-open "http://localhost:8000/visualizer.html"
elif command -v open > /dev/null; then
  open "http://localhost:8000/visualizer.html"
else
  echo "Abre http://localhost:8000/visualizer.html en tu navegador."
fi

# Mantener el script corriendo para poder cerrarlo con Ctrl+C
echo "Presiona Ctrl+C para detener el servidor."
wait $SERVER_PID
