# Examen Parcial 3

[Link del repositorio](https://github.com/pinchiguillo/Examen_parcial_3)

- Alejandro Abanades Abanades
- Javier Aguado Abajo

## Parte 1: Preguntas de elección múltiple (20%)

¿Cuál es la principal diferencia entre la estructura básica del programa en C y C++?
- a) C utiliza cout y cin mientras que C++ utiliza printf y scanf.
- **b) C utiliza printf y scanf mientras que C++ utiliza std::cout y std::cin.**
- c) No hay ninguna diferencia.
- d) C++ utiliza printf y scanf mientras que C utiliza std::cout y std::cin.

¿Qué es un espacio de nombres en C++?
- **a) Una característica que permite agrupar entidades como clases, objetos y funciones bajo un nombre.**
- b) Una manera de definir variables.
- c) Una función de la biblioteca estándar.
- d) Un tipo de ciclo en C++.

En programación orientada a objetos en C++, ¿qué es una clase?
- a) Una agrupación de funciones.
- b) Un tipo de variable.
- **c) Un tipo de dato primitivo.**
- d) Una plantilla para crear objetos, proporciona una definición inicial para el estado (miembros de datos) y el comportamiento (miembros de la función).

¿Qué son los templates en C++?
- a) Un tipo especial de clase.
- **b) Permiten la creación de funciones y clases genéricas, es decir, que pueden trabajar con cualquier tipo de datos.**
- c) Una forma de definir variables.
- d) Una característica específica de C.

## Parte 2: Pregunta de desarrollo de código (80%)


En el marco de la globalización y la creciente tendencia de intercambio académico, las universidades internacionales están experimentando un auge en la diversidad de su población estudiantil. Estos estudiantes provienen de diferentes partes del mundo, con culturas, idiomas y antecedentes educativos distintos. Con tal diversidad, la administración académica enfrenta el desafío de gestionar de manera eficiente y personalizada la información de cada estudiante.

El "Centro Global de Estudios Avanzados" (CGEA) es una de esas universidades internacionales que ha decidido abordar este desafío. Con campus en cinco continentes y una comunidad estudiantil de más de 40,000 alumnos, el CGEA ha identificado la necesidad de modernizar su sistema de gestión académica para ofrecer un mejor servicio a sus estudiantes y, al mismo tiempo, optimizar sus procesos internos.

Para ello, han contratado a una firma de desarrollo de software especializada en soluciones educativas. La primera fase del proyecto consiste en evaluar y decidir qué lenguaje de programación es el más adecuado para implementar el nuevo sistema. Dado que el equipo de desarrollo tiene experiencia tanto en C como en C++, han decidido realizar una comparativa entre ambos lenguajes utilizando una estructura básica: la información del estudiante.

Instrucciones para la Pregunta de Desarrollo de Código:



## Rúbrica

(30%) Implementación de la estructura Estudiante:

- La estructura Estudiante está correctamente implementada tanto en C como en C++.
(20%) Implementación de la función mostrarEstudiante():

- La función mostrarEstudiante() está correctamente implementada y muestra correctamente todos los campos de una instancia de Estudiante.
(30%) Comparación entre las dos implementaciones:

- Se proporciona una comparación clara y correcta entre las implementaciones de C y C++.
(20%) Calidad del código:

Todo el código está bien comentado, bien organizado, sigue buenas prácticas de programación y se compila sin errores ni advertencias en CLion.
Importante:

Todos los códigos deben ser originales. Se utilizarán herramientas de detección de plagio para verificar la originalidad del código.
El código debe estar bien documentado y organizado.
Se debe incluir un archivo README con instrucciones sobre cómo compilar y ejecutar el programa.
El código debe compilarse sin errores ni advertencias en CLion.

## Componentes del desarrollo
Implementar tanto en **C++** como en **C**
- Implementa una estructura llamada Estudiante con los campos: nombre, edad, y promedio.
- Desarrolla la función mostrarEstudiante() que muestre todos los campos de la estructura.
- Añade a la estructura Estudiante una lista o vector de materias en las que está inscrito.
- Implementa funciones para agregar, eliminar y mostrar estas materias.
- Diseña una clase o estructura Asistencia que contenga: fecha, materia y estado (asistió, falta, tardanza).
- Integra esta estructura con Estudiante y desarrolla funciones para registrar y mostrar la asistencia.
- Manejo de Excepciones:

## Conclusión:

Con base en tu experiencia y las implementaciones desarrolladas:

### ¿Cuál de los dos lenguajes consideras más adecuado para el proyecto del CGEA?
C++ es más adecuado para el proyecto debido a su soporte para programación orientada a objetos, manejo de excepciones, bibliotecas modernas, y su capacidad para gestionar datos complejos de forma eficiente.
### ¿Qué recomendaciones harías al equipo de desarrollo del CGEA para la siguiente fase del proyecto?
- Seguir una extructura lo mas modular posible, para fatilitar una mayor escalabilidad
- Implementar control de excepciones como si el usuario fuera tu enemigo (lo es)
- Crear un conjunto de reglas al inicio. Como el uso de camel_case...
