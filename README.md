# ProgramaFletes_C

Una empresa de fletes, dispone de 10 vehículos, y desea organizar la recaudación y cantidad de viajes de
sus vehículos en un determinado mes.
1.) De cada auto se conoce
- Patente del vehiculo (7 caracteres)
- Apellido y nombre del propietario (60 caracteres)
Utilizar función Carga para guardar estos datos.
2.)Además, cada vez que se realiza un flete (un viaje), se tiene la siguiente información:
- Día del flete (considerar 1 a 30)
- Patente del vehiculo (7 caracteres)
- Importe del flete
Si el día del flete corresponde a la segunda quincena (día >15) , se realiza un descuento del 5% de descuento
sobre el importe del viaje.
Esta información termina con Día del flete igual a cero.

2.1.) Si la patente del vehiculo no existe indicar “Patente Inexistente” en el programa principal.
Utilizar función BusquedaVe

2.2.) Utilizar función LeeControlDia para leer y controlar, el Nro. de dia

3.) Con las informaciones anteriores, realizar e informar el siguiente resumen:

3.1.) Un listado donde figure la recaudación de cada vehiculo en cada día.

                               LISTADO DE RECAUDACION
Patente vehiculo /     DIA 1     2       3 .......................... 28     29      30
BS123AA                xx.xx    x.xx    xx.xx                        x.xx   x.xx    xx.xx
CJU236                 xx.xx    x.xx    x.xx                         xx.xx  xx.xx   xx.xx
:
AA888AA                xx.xx    x.xx    xxx.xx                       xx.xx  xxx.xx  xx.xx

Utilizar para el informe la función ListadoRecau

3.2.) Un listado, ORDENADO en forma descendente por cantidad de fletes (viajes) de cada vehiculo.
                        CANTIDAD DE VIAJES POR VEHICULO
          APELLIDO Y NOMBRE DEL PROPIETARIO           CANTIDAD
                    xxxxxxxxx                           xxx
Utilizar función ORDEN y para el informe la función ListadoCantidad

3.3.) Vehiculo (patente) de máxima cantidad de fletes realizados. Funcion Maximo e InformeMaximo

3.4.) Indicar que vehículos (patente) NO realizaron viajes el día 1.
