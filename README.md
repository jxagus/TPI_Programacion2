# Trabajo Practico Integrador - AutoPartes

Integrantes:  
- Acosta Ramón Agustin 
- Fernández Fernando Ariel
- Perez Salcedo Aldo
- Guillermo Hernandez.

## Tipo de proyecto: Gestión.

Descripción: Proveedora autopartes
## INTRODUCCIÓN
El sistema a desarrollar permitirá gestionar, principalmente, las entregas de autopartes a distintas empresas. Para esto contará con un menú principal y una serie de submenúes que serán la interfaz gráfica para la gestión de las empresas, las autopartes y las entregas realizadas.

### DESCRIPCIÓN DETALLADA DEL SISTEMA
El objetivo principal del programa es llevar el control de las autopartes que fabrica la proveedora, así como de las empresas a las que provee.
De las empresas se podrá registrar:
•	CUIT
•	Nombre
•	Nombre y apellido del responsable
•	Teléfono
•	Email
•	Dirección
De cada autoparte se registrará:
•	Número de autoparte (código único)
•	Nombre
•	Tipo de autoparte (1: motor; 2: carrocería; 3: chasis; 4: interior)
•	Cantidad de unidades en stock
La aplicación permitirá gestionar tanto la información básica de empresas y autopartes como también generar distintos reportes y consultas de interés para la proveedora.
Entre sus principales funcionalidades se incluyen:
•	Identificar qué componente fue entregado en cada operación.
•	Saber a qué empresa se le realizó la entrega correspondiente.
•	Registrar y consultar la fecha de la entrega, la cantidad de unidades entregadas y el importe total.
•	Generar un reporte con el producto más vendido y el menos vendido, permitiendo analizar el movimiento de stock.
•	Controlar el stock disponible de cada autoparte, incluyendo un sistema de gestión de stock crítico que alerta sobre piezas con pocas unidades.
•	Consultar el historial de entregas realizadas para un seguimiento detallado de las operaciones efectuadas.
De esta manera, la aplicación brinda por una parte, soluciona problemas reales de abastecimiento de stock. Por otra parte y mas importante, el sistema será una herramienta para  administrar tanto el registro de clientes y productos como la gestión de entregas, stock y reportes de la proveedora de autopartes.

### SALIDAS DEL SISTEMA
La aplicación elaborará tres tipos de salidas, categorizadas en:
•	Listados: de empresas, autopartes y entregas.
•	Consultas: específicas de stock, productos más/menos vendidos e historial de operaciones.
•	Informes: de gestión de stock crítico y de movimiento general de autopartes.






## CLASES

1.	Clase Clientes(empresas)
Representa a las empresas que reciben autopartes.
Propiedades:
•	CUIT
•	Nombre
•	Responsable (nombre y apellido)
•	Teléfono
•	Email


2.	Clase Stock(autopartes)
Representa los componentes fabricados por la proveedora.
Propiedades:
•	Número de autoparte (código único)
•	Nombre
•	Tipo (1: motor, 2: carrocería, 3: chasis, 4: interior)
•	Stock (cantidad disponible)
•	Precio




3.	Clase Entrega
Registra cada operación de venta o envío de autopartes a una empresa.
Propiedades:
•	ID de entrega
•	Fecha de entrega
•	Cantidad de unidades entregadas
•	Importe total de la entrega
•	Empresa asociada (a quién se le entregó)
•	Autoparte asociada (qué se entregó)

