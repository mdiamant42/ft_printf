# ft_printf

Ce projet, réalisé dans le cadre de l'école 42, consiste à recréer la fonction printf de la bibliothèque C standard.

## Description

La fonction `ft_printf` est une version simplifiée de la fonction printf de la bibliothèque standard de C. Elle permet de formater et d'afficher du texte avec des spécificateurs de conversion, tels que `%s`, `%d`, `%c`, `%x`, `%f`, etc.

## Utilisation

Pour utiliser la fonction `ft_printf`, incluez le fichier `ft_printf.h` dans votre programme. Appelez ensuite la fonction en utilisant le même format que la fonction printf standard.

Exemple d'utilisation :
```c
#include "ft_printf.h"

int main() {
    ft_printf("Bonjour, le nombre est %d et le caractère est %c\n", 42, 'A');
    return (0);
}
```

## Compilation

Compilez votre programme en incluant les fichiers sources de `ft_printf`.

Exemple de compilation : `gcc -Wall -Wextra -Werror ft_printf.c ft_utils.c your_file.c`

## Ressources

Pour plus de détails sur le projet ft_printf, référez-vous au sujet fourni par l'école 42.
