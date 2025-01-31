# 🎲 Sudoku-En-C

![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Languages](https://img.shields.io/badge/C++-73.8%25-purple.svg) ![Languages](https://img.shields.io/badge/C-26.2%25-blue.svg)

Un jeu de Sudoku classique implémenté en C++ avec une interface console interactive et un générateur de grilles intelligent.

## 📋 Structure du Projet

```
Sudoku-En-C/
├── Sudoku.cpp       # Code source principal
├── Sudoku.h         # Déclarations des classes et fonctions
├── Sudoku.o         # Fichier objet compilé
├── Sudoku.exe       # Exécutable du jeu
├── stdafx.cpp       # Précompilation des en-têtes
├── stdafx.h         # En-têtes précompilés
├── targetver.h      # Version cible Windows
└── Sudoku.vcxproj   # Projet Visual Studio
```

## ✨ Fonctionnalités

- 🎮 Interface console intuitive
- 🔢 Générateur de grilles automatique
- 📝 Validation en temps réel des entrées
- 💾 Sauvegarde/Chargement de partie
- 🎯 Plusieurs niveaux de difficulté
- 🔍 Système d'indices
- ⏱️ Mode contre la montre

## 🛠️ Installation

### Prérequis
- Compilateur C++ (Visual Studio ou G++)
- CMake (optionnel)
- Windows/Linux/MacOS

### Compilation

#### Avec Visual Studio
```bash
# Ouvrir Sudoku.vcxproj
# Build > Build Solution
```

#### Avec G++
```bash
g++ -o Sudoku.exe Sudoku.cpp stdafx.cpp
```

## 🎮 Comment Jouer

1. **Contrôles**
   - Touches numériques (1-9) : Entrer un chiffre
   - Flèches : Déplacer le curseur
   - ESPACE : Effacer une case
   - H : Indice
   - S : Sauvegarder
   - L : Charger
   - Q : Quitter

2. **Règles du Sudoku**
   - Remplir la grille 9x9 avec les chiffres 1 à 9
   - Chaque ligne doit contenir tous les chiffres de 1 à 9
   - Chaque colonne doit contenir tous les chiffres de 1 à 9
   - Chaque bloc 3x3 doit contenir tous les chiffres de 1 à 9

## 🎯 Niveaux de Difficulté

- **Facile** : 35-40 chiffres donnés
- **Moyen** : 30-34 chiffres donnés
- **Difficile** : 25-29 chiffres donnés
- **Expert** : 20-24 chiffres donnés

## 💡 Fonctionnalités Techniques

- **Générateur de Grilles**
  - Algorithme de backtracking
  - Garantie d'une solution unique
  - Difficulté paramétrable

- **Validation**
  - Vérification instantanée des entrées
  - Détection des conflits
  - Surlignage des erreurs

- **Système de Score**
  - Points basés sur la difficulté
  - Bonus de temps
  - Pénalités pour les indices utilisés

## 🔧 Configuration

Modifiez les paramètres dans `Sudoku.h` :
```cpp
#define GRID_SIZE 9
#define MAX_HINTS 3
#define SAVE_FILE "sudoku_save.txt"
```

## 🐛 Dépannage

- **Problème d'affichage** : Vérifiez la taille de la fenêtre console
- **Erreurs de compilation** : Assurez-vous d'avoir les bons en-têtes précompilés
- **Sauvegarde échouée** : Vérifiez les permissions d'écriture

## 📈 Performances

- Génération de grille < 1 seconde
- Validation instantanée
- Mémoire utilisée < 10MB

## 🤝 Contribution

1. Fork le projet
2. Créez votre branche (`git checkout -b feature/AmeliorationSudoku`)
3. Committez vos changements (`git commit -m 'Ajout nouvelle fonctionnalité'`)
4. Push vers la branche (`git push origin feature/AmeliorationSudoku`)
5. Ouvrez une Pull Request

## 📝 License

Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.

## 👥 Auteurs

- **MouradOuammou** - *Développement initial*

## 🙏 Remerciements

- Inspiré des règles classiques du Sudoku
- La communauté C++ pour ses contributions
- Les testeurs du projet

---
⭐ Si vous aimez ce projet, n'hésitez pas à lui donner une étoile ! ⭐
