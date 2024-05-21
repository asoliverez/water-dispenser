# Water Dispenser

Sirve para probar en Arduino un dispensador de agua

## Para probarlo

## Paso 1: Descargar e instalar Arduino IDE
- Descargar Arduino IDE:
  - Ve a la página oficial de Arduino: https://www.arduino.cc/en/software
  - Haz clic en el botón "Windows Win 7 and newer" para descargar el instalador
- Instalar Arduino IDE:
  - Una vez completada la descarga, ejecuta el archivo de instalación (.exe)
  - Sigue las instrucciones del instalador. Asegúrate de marcar todas las opciones durante la instalación, incluyendo los controladores
## Paso 2: Preparar el archivo water-dispenser.ino
- Obtener el archivo water-dispenser.ino:
  - Descarga [water-dispenser.ino](water-dispenser.ino)

- Abrir el archivo en Arduino IDE:
  - Abre Arduino IDE desde el menú de inicio o el acceso directo en el escritorio
  - Haz clic en File > Open y navega hasta la ubicación donde guardaste water-dispenser.ino
  - Selecciona el archivo y ábrelo

## Paso 3: Conectar y configurar la placa Arduino Uno
- Conectar la placa Arduino:
  - Conecta tu placa Arduino Uno a tu computadora usando un cable USB.
- Seleccionar la placa y el puerto:
  - En Arduino IDE, ve a Tools > Board y selecciona Arduino Uno.
  - Ve a Tools > Port y selecciona el puerto COM correspondiente a tu placa Arduino Uno (por ejemplo, COM3). Si no estás seguro, desconecta y vuelve a conectar la placa para ver cuál aparece.

## Paso 4: Actualizar el firmware
- Verificar el código:
  - En Arduino IDE, haz clic en el botón de Check (icono de ✔) para verificar que el código no tiene errores.
- Subir el código a la placa:
  - Haz clic en el botón Upload (icono de una flecha derecha) para subir el código a la placa Arduino Uno.
  - Arduino IDE compilará el código y lo subirá a la placa. Verás un mensaje en la parte inferior de la ventana indicando que la subida fue exitosa.

## Paso 5: Verificar el funcionamiento
- Monitorear la salida:
  - Abre el Serial Monitor desde Tools > Serial Monitor o presionando Ctrl+Shift+M.
  -  Configura la velocidad del baud rate a la misma que se usa en el código (por defecto 9600).
- Probar el dispositivo:
  - Sigue las instrucciones del proyecto y verifica que el dispositivo funcione como se espera.
  
