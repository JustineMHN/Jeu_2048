# Jeu_2048

Le jeu 2048 est un puzzle numérique populaire dans lequel le joueur combine des tuiles numériques pour atteindre la valeur 2048.
Le code est écrit en C++ et utilise la bibliothèque standard pour la manipulation des vecteurs et des fonctions d'affichage console.

# Fonctionnalités Principales

1. Initialisation de la Grille
   La fonction initializeGrid initialise la grille du jeu avec deux tuiles aléatoires au début de la partie. Elle utilise la fonction addRandomTile pour placer une tuile de valeur 2 ou 4 dans une case vide de la grille.

2. Affichage de la Grille
   La fonction printGrid affiche la grille actuelle dans la console. Elle utilise la fonction system("cls") pour effacer l'écran sur un système Windows.

3. Déplacement des Tuiles
   Les fonctions moveLeft, moveRight, moveUp, et moveDown gèrent les déplacements des tuiles vers la gauche, la droite, le haut, et le bas, respectivement. Elles fusionnent également les tuiles adjacentes de même valeur.

4. Ajout de Tuiles Aléatoires
   La fonction addRandomTile ajoute une nouvelle tuile (2 ou 4) de manière aléatoire dans une case vide de la grille.

5. Vérification de la Victoire
   La fonction checkWin vérifie si le joueur a atteint la valeur 2048 sur la grille, indiquant ainsi une victoire.

6. Vérification du Match Nul
   La fonction checkDraw vérifie s'il y a un match nul en examinant la grille pour des mouvements possibles et des cases vides.

7. Entrées Utilisateur
   Le jeu accepte les entrées utilisateur pour déplacer les tuiles. Les touches 'g', 'y', 'j', et 'n' représentent respectivement la gauche, le haut, la droite, et le bas.

# Structure du Code

Le code est structuré de manière à séparer clairement les différentes fonctionnalités du jeu. Les fonctions sont modulaires, ce qui facilite la compréhension et la maintenance du code.

# Utilisation de la Console

Le jeu est conçu pour être utilisé dans la console. Les mouvements sont effectués en utilisant les touches du clavier, offrant une expérience utilisateur simple.
