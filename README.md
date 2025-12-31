# ft_printf

[English](#english) | [Español](#español)

---

## English

### Description

ft_printf is a 42 project that consists of recoding the `printf()` function from the C standard library. This project teaches you about variadic functions, string parsing, and handling different data types.

### Table of Contents

- [Objectives](#objectives)
- [Mandatory conversions](#mandatory-conversions)
- [Compilation](#compilation)
- [Usage](#usage)
- [Implementation](#implementation)
- [Testing](#testing)

### Objectives

The main goal is to recreate the `printf()` function with the following features:

- Manage variadic functions
- Implement different conversion specifiers
- Return the number of characters printed
- Do not implement the original function's buffer

### Mandatory conversions

Your `ft_printf` must handle the following converters:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer in hexadecimal format |
| `%d` | Prints a decimal number (base 10) |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal number |
| `%x` | Prints a number in hexadecimal (lowercase) |
| `%X` | Prints a number in hexadecimal (uppercase) |
| `%%` | Prints the percent symbol |

### Compilation

#### Makefile rules

```bash
# Compile the library
make

# Clean object files
make clean

# Clean everything (including libftprintf.a)
make fclean

# Recompile from scratch
make re
```

### Usage

#### Include in your code

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    count = ft_printf("Hello, %s!\n", "42");
    ft_printf("Characters printed: %d\n", count);
    
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Madrid");
    ft_printf("Pointer: %p\n", &count);
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Integer: %i\n", -42);
    ft_printf("Unsigned: %u\n", 4294967295u);
    ft_printf("Hex (lower): %x\n", 255);
    ft_printf("Hex (upper): %X\n", 255);
    ft_printf("Percent: %%\n");
    
    return (0);
}
```

#### Compile your program

```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
./program
```

### Implementation

#### Function prototype

```c
int ft_printf(const char *format, ...);
```

#### Suggested structure

```
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c          # Main function and parser
├── ft_print_char.c      # Handle %c
├── ft_print_string.c    # Handle %s
├── ft_print_pointer.c   # Handle %p
├── ft_print_number.c    # Handle %d and %i
├── ft_print_unsigned.c  # Handle %u
├── ft_print_hex.c       # Handle %x and %X
└── README.md
```

#### Key functions to implement

```c
// Main function
int ft_printf(const char *format, ...);

// Helper functions
int ft_print_char(char c);
int ft_print_string(char *str);
int ft_print_pointer(void *ptr);
int ft_print_number(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hex(unsigned int n, char format);
```

#### Using variadic functions

```c
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;
    
    va_start(args, format);
    count = parse_format(format, args);
    va_end(args);
    
    return (count);
}
```

### Testing

#### Basic tests

```c
// Return value test
int ret1 = ft_printf("Test\n");
int ret2 = printf("Test\n");
// ret1 must equal ret2

// Conversion tests
ft_printf("%c", 'A');
ft_printf("%s", "Hello");
ft_printf("%p", ptr);
ft_printf("%d", 42);
ft_printf("%i", -42);
ft_printf("%u", 4294967295u);
ft_printf("%x", 255);
ft_printf("%X", 255);
ft_printf("%%");
```

### Edge cases to consider

- NULL strings: `ft_printf("%s", NULL)`
- NULL pointers: `ft_printf("%p", NULL)`
- Minimum and maximum values: INT_MIN, INT_MAX, UINT_MAX
- Multiple converters in one call
- Consecutive converters without text: `ft_printf("%d%d", 1, 2)`

### Norm

This project must comply with 42's Norminette:

- Maximum 25 lines per function
- Maximum 5 functions per file
- No global variables
- Proper memory management
- No memory leaks

### Authorized functions

- `malloc`, `free`
- `write`
- `va_start`, `va_arg`, `va_copy`, `va_end` (stdarg.h)

### Tips

1. Start with the simplest converters (%c, %s, %%)
2. Test each converter individually before continuing
3. Handle edge cases from the beginning
4. Constantly compare with the original printf
5. The return value is as important as the output
6. Use helper functions to keep code clean

---

## Español

### Descripción

ft_printf es un proyecto de 42 que consiste en recodear la función `printf()` de la biblioteca estándar de C. Este proyecto te enseña sobre funciones variádicas, parsing de strings y manejo de diferentes tipos de datos.

### Tabla de Contenidos

- [Objetivos](#objetivos)
- [Conversiones obligatorias](#conversiones-obligatorias)
- [Compilación](#compilación-1)
- [Uso](#uso-1)
- [Implementación](#implementación-1)
- [Testing](#testing-1)

### Objetivos

El objetivo principal es recrear la función `printf()` con las siguientes características:

- Gestionar funciones variádicas
- Implementar diferentes especificadores de conversión
- Devolver el número de caracteres impresos
- No implementar el buffer de la función original

### Conversiones obligatorias

Tu `ft_printf` debe manejar los siguientes conversores:

| Especificador | Descripción |
|---------------|-------------|
| `%c` | Imprime un solo carácter |
| `%s` | Imprime un string |
| `%p` | Imprime un puntero en formato hexadecimal |
| `%d` | Imprime un número decimal (base 10) |
| `%i` | Imprime un entero en base 10 |
| `%u` | Imprime un número decimal sin signo |
| `%x` | Imprime un número en hexadecimal (minúsculas) |
| `%X` | Imprime un número en hexadecimal (mayúsculas) |
| `%%` | Imprime el símbolo de porcentaje |

### Compilación

#### Reglas del Makefile

```bash
# Compilar la biblioteca
make

# Limpiar archivos objeto
make clean

# Limpiar todo (incluyendo libftprintf.a)
make fclean

# Recompilar desde cero
make re
```

### Uso

#### Inclusión en tu código

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    count = ft_printf("Hello, %s!\n", "42");
    ft_printf("Caracteres impresos: %d\n", count);
    
    ft_printf("Carácter: %c\n", 'A');
    ft_printf("String: %s\n", "Madrid");
    ft_printf("Puntero: %p\n", &count);
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Entero: %i\n", -42);
    ft_printf("Sin signo: %u\n", 4294967295u);
    ft_printf("Hex (min): %x\n", 255);
    ft_printf("Hex (may): %X\n", 255);
    ft_printf("Porcentaje: %%\n");
    
    return (0);
}
```

#### Compilación de tu programa

```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o programa
./programa
```

### Implementación

#### Prototipo de la función

```c
int ft_printf(const char *format, ...);
```

#### Estructura sugerida

```
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c          # Función principal y parser
├── ft_print_char.c      # Manejo de %c
├── ft_print_string.c    # Manejo de %s
├── ft_print_pointer.c   # Manejo de %p
├── ft_print_number.c    # Manejo de %d y %i
├── ft_print_unsigned.c  # Manejo de %u
├── ft_print_hex.c       # Manejo de %x y %X
└── README.md
```

#### Funciones clave a implementar

```c
// Función principal
int ft_printf(const char *format, ...);

// Funciones auxiliares
int ft_print_char(char c);
int ft_print_string(char *str);
int ft_print_pointer(void *ptr);
int ft_print_number(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hex(unsigned int n, char format);
```

#### Uso de funciones variádicas

```c
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;
    
    va_start(args, format);
    count = parse_format(format, args);
    va_end(args);
    
    return (count);
}
```

### Testing

#### Tests básicos

```c
// Test de retorno
int ret1 = ft_printf("Test\n");
int ret2 = printf("Test\n");
// ret1 debe ser igual a ret2

// Test de conversiones
ft_printf("%c", 'A');
ft_printf("%s", "Hello");
ft_printf("%p", ptr);
ft_printf("%d", 42);
ft_printf("%i", -42);
ft_printf("%u", 4294967295u);
ft_printf("%x", 255);
ft_printf("%X", 255);
ft_printf("%%");
```

### Casos edge a considerar

- Strings NULL: `ft_printf("%s", NULL)`
- Punteros NULL: `ft_printf("%p", NULL)`
- Valores mínimos y máximos: INT_MIN, INT_MAX, UINT_MAX
- Múltiples conversores en una llamada
- Conversores seguidos sin texto: `ft_printf("%d%d", 1, 2)`

### Norma

Este proyecto debe cumplir con la Norminette de 42:

- Máximo 25 líneas por función
- Máximo 5 funciones por archivo
- Sin variables globales
- Gestión adecuada de memoria
- Sin leaks de memoria

### Funciones autorizadas

- `malloc`, `free`
- `write`
- `va_start`, `va_arg`, `va_copy`, `va_end` (stdarg.h)

### Consejos

1. Empieza por los conversores más simples (%c, %s, %%)
2. Testea cada conversor individualmente antes de continuar
3. Gestiona los casos edge desde el principio
4. Compara constantemente con el printf original
5. El valor de retorno es tan importante como la salida
6. Usa funciones auxiliares para mantener el código limpio

---

## Author / Autor

adruz-to - 42 Málaga

## License / Licencia

This project is part of the 42 curriculum. / Este proyecto es parte del curriculum de 42.
