````markdown
# pipex

> Projet de l'école 42 visant à reproduire le comportement du pipe (`|`) de Bash, en manipulant les entrées/sorties et les processus en C.

---

## 🎯 Objectif

Le projet `pipex` a pour but de vous familiariser avec :

- la duplication des descripteurs de fichiers (`dup2`),
- l’exécution de commandes avec `execve`,
- la création de processus via `fork`,
- et l’utilisation des tubes (`pipe`) pour communiquer entre deux programmes.

---

## 💡 Comportement attendu

Votre programme doit reproduire le comportement suivant :

```bash
< infile command1 | command2 > outfile
````

En C :

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Par exemple :

```bash
./pipex infile "ls -l" "wc -l" outfile
```

Doit produire le même résultat que :

```bash
< infile ls -l | wc -l > outfile
```

---
## ⚙️ Compilation

```bash
make
```

Puis exécution :

```bash
./pipex infile "cmd1" "cmd2" outfile
```

---

## 🚨 Gestion des erreurs

Le programme doit gérer correctement :

* Fichier introuvable
* Commande invalide
* Permission refusée
* Mauvais nombre d’arguments

---

## 🔁 Bonus (si réalisés)

* Gestion d’un nombre illimité de commandes (mode multi-pipe) :

  ```bash
  ./pipex infile "cmd1" "cmd2" "cmd3" "cmd4" outfile
  ```

* Support de `here_doc` :

  ```bash
  ./pipex here_doc LIMITER "cmd1" "cmd2" outfile
  ```

---

## 📚 Fonctions autorisées

* `open`, `close`, `read`, `write`
* `pipe`, `dup`, `dup2`, `execve`
* `fork`, `wait`, `waitpid`, `access`
* `malloc`, `free`, `perror`, `strerror`
* `exit`

---

## ✅ Compétences développées

* Manipulation bas-niveau des fichiers et processus
* Communication entre processus (IPC)
* Parsing et gestion fine des chemins (`PATH`)
* Compréhension du shell et de l’environnement Unix

---

## 👤 Auteur

Nicolas **Martin**
[École 42](https://42.fr)

---
