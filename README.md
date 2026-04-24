# Simple Shell

## 📌 Description

Simple Shell est une implémentation basique d’un interpréteur de commandes UNIX développée en C dans le cadre du programme Holberton School.

Ce shell permet d’exécuter des commandes système, de gérer des processus via `fork` et `execve`, et de reproduire un comportement minimal similaire à `/bin/sh`.

---

## ⚙️ Fonctionnalités

* Affichage d’un prompt (`$`) en mode interactif
* Lecture de l’entrée utilisateur avec `getline`
* Parsing des arguments (gestion des espaces, tabulations, retours ligne)
* Exécution de commandes système (`ls`, `pwd`, etc.)
* Recherche automatique dans la variable `PATH`
* Gestion des chemins absolus (`/bin/ls`)
* Built-ins :

  * `exit` → quitte le shell
  * `env` → affiche les variables d’environnement
* Mode non-interactif supporté (pipes, redirections simples)

---

## 🧠 Concepts utilisés

* `fork()` : création de processus
* `execve()` : exécution de programme
* `wait()` : synchronisation parent/enfant
* `stat()` : vérification des fichiers
* Variables d’environnement (`environ`)
* Parsing avec `strtok`

---

## 📁 Structure du projet

```
.
├── main.c              # Boucle principale du shell
├── main.h              # Header + prototypes
├── functions.c         # find_path, parse_line, exec, env
```

---

## 🔨 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
```

---

## ▶️ Utilisation

### Mode interactif

```bash
./simple_shell
$
```

### Exemples

```bash
$ ls
main.c  main.h  functions.c

$ pwd
/home/user/simple_shell

$ /bin/ls
main.c  main.h  functions.c

$ env
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
HOME=/home/user
...

$ exit
```

---

### Mode non-interactif

```bash
echo "ls" | ./simple_shell
```

```bash
cat commands.txt | ./simple_shell
```

---

## ⚠️ Limitations

* Pas de gestion :

  * des arguments avancés (`ls -l`)
  * des pipes (`|`)
  * des redirections (`>`, `<`)
  * des variables (`$HOME`)
* Taille fixe du tableau d’arguments
* Parsing simple basé sur `strtok`

---

## 🛠️ Améliorations possibles

* Gestion des pipes et redirections
* Support des arguments complexes
* Gestion des erreurs plus détaillée
* Implémentation d’un historique
* Ajout d’un compteur de commandes
* Sécurisation mémoire avancée

---


Projet réalisé dans le cadre de Holberton School.
