# Simple Shell

## Description

Simple Shell est un interpréteur de commandes UNIX minimaliste écrit en C.
Il lit les commandes saisies par l'utilisateur, les analyse, puis les exécute en utilisant les appels système `fork()` et `execve()`.

Le shell supporte également la recherche des exécutables via la variable d’environnement `PATH`.

---

## Fonctionnalités

- Affichage d’un prompt en mode interactif (`$ `)
- Exécution de commandes système (ex: `ls`, `pwd`, `echo`, etc.)
- Recherche des commandes dans le `PATH`
- Exécution directe des chemins absolus (ex: `/bin/ls`)
- Support du mode interactif et non-interactif
- Commandes internes :
  - `exit` : quitter le shell
  - `env` : afficher les variables d’environnement

---

## Compilation

Compilez le projet avec `gcc` :

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell