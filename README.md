# Trabajo Practico Integrador - AutoPartes

Integrantes:  
- Acosta Ramón Agustin 
- Guillermo Hernandez.

 Tipo de proyecto: Gestión.

## INTRODUCCIÓN
El sistema a desarrollar permitirá gestionar, principalmente, las entregas de autopartes a distintas empresas. Para esto contará con un menú principal y una serie de submenúes que serán la interfaz gráfica para la gestión de las empresas, las autopartes y las entregas realizadas.

## DESCRIPCIÓN DETALLADA DEL SISTEMA

El objetivo principal del programa es llevar el control de las autopartes que fabrica la proveedora, así como de las empresas a las que provee.
La aplicación permitirá gestionar tanto la información básica de empresas y autopartes como también generar distintos reportes y consultas de interés para la proveedora.
Entre sus principales funcionalidades se incluyen:

- Identificar qué componente fue entregado en cada operación.
- Saber a qué empresa se le realizó la entrega correspondiente.
- Registrar y consultar la fecha de la entrega, la cantidad de unidades entregadas y el importe total.
- Generar un reporte con el producto más vendido y el menos vendido, permitiendo analizar el movimiento de stock.
- Controlar el stock disponible de cada autoparte, incluyendo un sistema de gestión de stock crítico que alerta sobre piezas con pocas unidades.
- Consultar el historial de entregas realizadas para un seguimiento detallado de las operaciones efectuadas.

De esta manera, la aplicación brinda por una parte, soluciona problemas reales de abastecimiento de stock. Por otra parte y mas importante, el sistema será una herramienta para  administrar tanto el registro de clientes y productos como la gestión de entregas, stock y reportes de la proveedora de autopartes.

## SALIDAS DEL SISTEMA

La aplicación elaborará tres tipos de salidas, categorizadas en Listados, Consultas e Informes:
-	Listados: 
1.	Listado de empresas: ordenados por su nombre o categoría
2.	Listado de autopartes: ordenados por su nombre, stock/cantidad o tipo
3.	Listado de ventas: ordenados fecha o cliente
4.	Listado de personal: ordenados por rol o apellido
   
-	Consultas: 
1.	Clientes:  por su nombre, categoría, Id
2.	Ventas: por cliente, autoparte, fecha
3.	 Autoparte: por nombre, tipo, precio, Id
   
-	Informes: 
1.	Recaudación total anual y por mes
2.	Recaudación por cliente
3.	Recaudación por autoparte(Menor recaudación y mayor)

## ARCHIVO

-	Clientes.dat
-	Autopartes.dat
-	Venta.dat
-	DetalleVentas.dat
-	Personal.dat

## CLASES

 Venta
-	_idVenta : int
-	_fechaEntrega : int 
-	_idCliente : int
-	_importeTotal : float
-	_idPersonal : int

Cliente (Empresas)
-	_idCliente : int
-	_categoria: char[20] (para el tipo de empresa como talleres, consecionaria, distribuidoras, otros)
-	_direccion: char[50]
-	_nombre : char[20]
-	_telefono : int
-	_cuit: char[10]
-	_mail : char[100]

Autoparte (Stock)
-	_idAutoparte : int
-	_nombre : char[20]
-	_tipo :int 
-	_stock : int
-	_precio : float

DetalleVenta
-	_idDetalle : int
-	_idVenta : int
-	_idAutoparte : int
-	_cantidad : int
-	_precio : float
  
Personal
-	_id:int
-	_nombre:char[20]
-	_apellido:char[20]
-	_dni : int
-	_rol:char[20]
-	_telefono : char[15]
-	_mail : char[40]
