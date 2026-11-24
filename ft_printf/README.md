*This project has been created as part of the 42 curriculum by timbert.*

# ft_printf

## Description

Le but de ce projet est de recoder la fonction printf() de la libc en respectant le prototype suivant :

`int ft_printf(const char *, ...);`

La fonction doit gérer les conversions suivants : cspdiuxX%

| Conversion | Description |
|---|---|
| `%c` | Un caractère |
| `%s` | Une chaîne de caractères (`(null)` si `NULL`) |
| `%p` | Un pointeur au format hexadécimal (`(nil)` si `NULL`) |
| `%d` / `%i` | Un entier signé en base 10 |
| `%u` | Un entier non signé en base 10 |
| `%x` / `%X` | Un entier non signé en hexadécimal (minuscules / majuscules) |
| `%%` | Le caractère `%` |

Comme `printf`, la fonction retourne le nombre de caractères écrits.

## Explication et justification de l'algorithme

`ft_printf` parcourt la chaîne de format caractère par caractère : tant que le caractère n'est pas `%`, il est écrit directement avec `write`. Quand un `%` est rencontré, `check_caract` lit le caractère suivant et appelle la fonction d'affichage correspondante (`print_char`, `print_str`, `print_nb`, `print_unsigned`, `print_hexa`, `print_ptr`).

La `va_list` est passée par pointeur pour que chaque `va_arg` fasse avancer la lecture des arguments dans `ft_printf`. Les nombres sont affichés de façon récursive (chiffres de poids fort d'abord), ce qui évite tout `malloc` ou tableau temporaire. `print_nb` utilise un `long` pour gérer `INT_MIN`, et une seule fonction hexadécimale gère les minuscules et majuscules grâce à une chaîne de base passée en paramètre.

Chaque fonction retourne le nombre de caractères écrits, additionnés dans un compteur renvoyé par `ft_printf`.

## Instructions

### Compilation

Tous les fichiers sont à la racine du dépôt. Depuis celle-ci :

```sh
make          # compile libftprintf.a (règle all)
make clean    # supprime les fichiers objets
make fclean   # supprime les fichiers objets et libftprintf.a
make re       # fclean puis all
```

Le Makefile compile avec `cc -Wall -Wextra -Werror` puis crée l'archive avec `ar`.

### Utilisation

Inclure le header dans votre code, puis lier la bibliothèque à la compilation.

```c
#include "ft_printf.h"

int	main(void)
{
	char	*ptr = "Oui";

	ft_printf("%s %d, voici l'adresse de mon pointeur : %p !\n", "Salut", 42, ptr);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o demo
./demo
```

## Resources

- Pages `man 3` de printf
- La Norme de 42 (norminette)
- [StackOverflow](https://stackoverflow.com)
- Testeurs : Francinette, nda-cunh/printf_tester

### Utilisation de l'IA

L'IA m'a servi d'outil de soutien pour certaines tâches :

- **Explication de concepts** : Notamment pour les listes variadiques.
- **Génération de tests** : Pour tester mon code dans tous les sens.
- **Documentation** : Aide à la rédaction de ce README.