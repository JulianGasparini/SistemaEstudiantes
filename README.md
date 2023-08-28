# SistemaEstudiantes

# Sistema de Estudiantes en C
Proyecto universatorio realizado en C/C++ durante el primer cuatrimestre de 2023. Consiste en el desarrollo de un sistema de estudiantes en C. El sistema tiene como objetivo permitir el manejo de estudiantes y materias, brindando funcionalidades como el alta, listado y búsqueda de estudiantes, así como también el alta y listado de materias. Además, los estudiantes podrán anotarse en varias materias y rendirlas.

## Funcionalidades
El sistema cuenta con las siguientes funcionalidades:

Alta y listado de estudiantes: Permite dar de alta a un estudiante en el sistema y listar todos los estudiantes registrados.

Búsqueda de estudiantes por nombre: Permite buscar estudiantes en base a su nombre, mostrando los resultados que coincidan parcial o totalmente con el nombre ingresado.

Búsqueda de estudiantes por rango de edad: Permite buscar estudiantes en base a un rango de edad especificado, mostrando aquellos que se encuentren dentro del rango.

Alta y listado de materias: Permite dar de alta una materia en el sistema y listar todas las materias registradas.

Anotarse en una materia: Permite a un estudiante anotarse en una materia específica.

Rendir una materia: Permite a un estudiante rendir una materia en la cual esté inscripto.

## Estructuras de datos utilizadas
Para el almacenamiento de los estudiantes se ha decidido utilizar listas enlazadas para almacenar tanto los estudiantes como las materias. Esto permite una gestión eficiente de los datos y un fácil acceso a los mismos.
Para el almacenamiento de las materias y sus correlativas se utilizaron hashtables y un sistema de bits que permite el rapido y ligero manejo en memoria.

## Limitaciones
El sistema ha sido diseñado para manejar un gran listado de estudiantes y materias. Sin embargo, es importante tener en cuenta que, en situaciones en las que la cantidad de datos sea muy grande, el sistema puede volverse inmanejable debido a limitaciones de memoria o capacidad de procesamiento. El sistema se puede llegar a tornar lento con el tiempo.

## Ideas implementadas (no obligatorias)
En este proyecto, se han implementado algunas ideas adicionales que suman puntos:

Paginado: El sistema cuenta con paginado para mostrar los resultados de búsqueda o listados de manera más ordenada y legible, evitando la sobrecarga de información en una sola visualización.

Elección de estudiante/materia de un listado reducido: En caso de que la cantidad de estudiantes o materias sea muy grande, el sistema permite realizar búsquedas o listados reducidos mediante filtros o criterios de selección, facilitando la elección de un estudiante o materia específica.

Estadísticas de estudiantes y materias: Se han incorporado funcionalidades para calcular estadísticas relacionadas con los estudiantes y las materias, como promedios, porcentajes de aprobación, entre otros.

Árboles de correlatividad de materias: El sistema permite establecer correlatividades entre las materias, de manera que se controla si un estudiante puede anotarse en una materia en base a las materias que haya aprobado previamente.

Manejo de materias desaprobadas: El sistema contempla la situación en la que una materia anterior está desaprobada, permitiendo que el estudiante pueda anotarse en la materia, pero con una advertencia sobre la correlatividad y la necesidad de aprobar la materia anterior.

Cálculo de promedios: Se ha implementado la funcionalidad de calcular promedios de notas para cada estudiante, permitiendo evaluar su desempeño académico.

Mejoras en la interfaz de usuario: Se han realizado mejoras en la interfaz de usuario para que sea más intuitiva y amigable, facilitando la interacción con el sistema.

## Conclusiones
El sistema de estudiantes en C desarrollado cumple con los requerimientos planteados en la consigna del TP final. Se ha buscado realizar un diseño creativo y práctico, utilizando estructuras de datos eficientes y considerando posibles limitaciones en el manejo de grandes cantidades de datos. Además, se han implementado ideas adicionales que suman puntos, brindando funcionalidades extras y mejorando la experiencia del usuario.
