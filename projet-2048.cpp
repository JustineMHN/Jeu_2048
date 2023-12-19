#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

const int SIZE = 4;

// Fonction pour ajouter une tuile (2 ou 4) de manière aléatoire
void addRandomTile(vector<vector<int>>& grid)
{
    vector<pair<int, int>> emptyCells;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (grid[i][j] == 0)
            {
                emptyCells.push_back(make_pair(i, j));
            }
        }
    }
    if (emptyCells.size() > 0)
    {
        int index = rand() % emptyCells.size();
        int value = (rand() % 2 + 1) * 2; // 2 ou 4 avec probabilité 50%
        int x = emptyCells[index].first;
        int y = emptyCells[index].second;
        grid[x][y] = value;
    }
}

// Fonction pour initialiser la grille avec des valeurs aléatoires
void initializeGrid(vector<vector<int>>& grid)
{
    srand(time(0));
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            grid[i][j] = 0;
        }
    }
    // Ajoutez deux valeurs aléatoires au début du jeu
    addRandomTile(grid);
    addRandomTile(grid);
}


// Fonction pour afficher la grille
void printGrid(const vector<vector<int>>& grid)
{
    system("cls"); // Efface l'écran (Windows)
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fonction pour effectuer un mouvement vers la gauche
void moveLeft(vector<vector<int>>& grid)
{
    // Variable pour suivre si une fusion a eu lieu pendant le mouvement
    bool merged = false;

    for (int row = 0; row < SIZE; ++row)
    {
        // Déplacez les tuiles vers la gauche (poussez les zéros à droite)
        for (int col = 0; col < SIZE; ++col)
        {
            for (int nextCol = col + 1; nextCol < SIZE; ++nextCol)
            {
                if (grid[row][nextCol] != 0)
                {
                    if (grid[row][col] == 0)
                    {
                        // Déplacez la tuile non nulle vers la case vide
                        grid[row][col] = grid[row][nextCol];
                        grid[row][nextCol] = 0;
                        merged = true;
                        col--; // Vérifiez à nouveau la case actuelle
                    }
                    else if (grid[row][col] == grid[row][nextCol])
                    {
                        // Fusionnez les tuiles de même valeur
                        grid[row][col] *= 2;
                        grid[row][nextCol] = 0;
                        merged = true;
                        break;
                    }
                }
            }
        }
    }

    // Après avoir fusionné et déplacé les tuiles, ajoutez une nouvelle tuile aléatoire
    if (merged)
    {
        addRandomTile(grid);
    }
}

// Fonction pour effectuer un mouvement vers la droite
void moveRight(vector<vector<int>>& grid)
{
    bool merged = false;

    for (int row = 0; row < SIZE; ++row)
    {
        for (int col = SIZE - 1; col >= 0; --col)
        {
            for (int prevCol = col - 1; prevCol >= 0; --prevCol)
            {
                if (grid[row][prevCol] != 0)
                {
                    if (grid[row][col] == 0)
                    {
                        grid[row][col] = grid[row][prevCol];
                        grid[row][prevCol] = 0;
                        merged = true;
                        col++;
                    }
                    else if (grid[row][col] == grid[row][prevCol])
                    {
                        grid[row][col] *= 2;
                        grid[row][prevCol] = 0;
                        merged = true;
                        break;
                    }
                }
            }
        }
    }

    if (merged)
    {
        addRandomTile(grid);
    }
}

// Fonction pour effectuer un mouvement vers le haut
void moveUp(vector<vector<int>>& grid)
{
    bool merged = false;

    for (int col = 0; col < SIZE; ++col)
    {
        for (int row = 0; row < SIZE; ++row)
        {
            for (int nextRow = row + 1; nextRow < SIZE; ++nextRow)
            {
                if (grid[nextRow][col] != 0)
                {
                    if (grid[row][col] == 0)
                    {
                        grid[row][col] = grid[nextRow][col];
                        grid[nextRow][col] = 0;
                        merged = true;
                        row--;
                    }
                    else if (grid[row][col] == grid[nextRow][col])
                    {
                        grid[row][col] *= 2;
                        grid[nextRow][col] = 0;
                        merged = true;
                        break;
                    }
                }
            }
        }
    }

    if (merged)
    {
        addRandomTile(grid);
    }
}

// Fonction pour effectuer un mouvement vers le bas
void moveDown(vector<vector<int>>& grid)
{
    bool merged = false;

    for (int col = 0; col < SIZE; ++col)
    {
        for (int row = SIZE - 1; row >= 0; --row)
        {
            for (int prevRow = row - 1; prevRow >= 0; --prevRow)
            {
                if (grid[prevRow][col] != 0)
                {
                    if (grid[row][col] == 0)
                    {
                        grid[row][col] = grid[prevRow][col];
                        grid[prevRow][col] = 0;
                        merged = true;
                        row++;
                    }
                    else if (grid[row][col] == grid[prevRow][col])
                    {
                        grid[row][col] *= 2;
                        grid[prevRow][col] = 0;
                        merged = true;
                        break;
                    }
                }
            }
        }
    }

    if (merged)
    {
        addRandomTile(grid);
    }
}

// Fonction pour vérifier si le joueur a atteint 2048
bool checkWin(const vector<vector<int>>& grid)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (grid[i][j] == 2048)
            {
                return true;
            }
        }
    }
    return false;
}

// Fonction pour vérifier si un mouvement est possible
bool isMovePossible(const vector<vector<int>>& grid)
{
    // Vérifiez s'il y a une tuile adjacente ayant la même valeur
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            // Vérifiez à droite
            if (j + 1 < SIZE && grid[i][j] == grid[i][j + 1])
            {
                return true;
            }
            // Vérifiez en bas
            if (i + 1 < SIZE && grid[i][j] == grid[i + 1][j])
            {
                return true;
            }
        }
    }

    // Vérifiez s'il y a des cases vides
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (grid[i][j] == 0)
            {
                return true;
            }
        }
    }

    return false; // Aucun mouvement possible
}

// Fonction pour vérifier s'il y a un match nul
bool checkDraw(const vector<vector<int>>& grid)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (grid[i][j] == 0)
            {
                return false; // Il y a encore des zéros, le jeu continue
            }
        }
    }

    // Si on arrive ici, la grille est pleine, vérifiez s'il y a des mouvements possibles
    if (isMovePossible(grid)) {
        return false; // Il y a des mouvements possibles, le jeu continue
    }

    return true; // Aucun mouvement possible, c'est un match nul
}



// Fonction principale du jeu
int main()
{
    vector<vector<int>> grid(SIZE, vector<int>(SIZE, 0));

    initializeGrid(grid);
    printGrid(grid);
    cout << "Utilisez les fleches ou les touches 'g' (gauche), 'y' (haut), 'j' (droite) et 'n' (bas) pour deplacer les tuiles, ou 'q' pour quitter." << endl;

    char move;
    while (true)
    {
        move = _getch(); // Attend une entrée clavier
        switch (move)
        {
        case 'g':
        case 75: // Flèche gauche
            moveLeft(grid);
            break;
        case 'y':
        case 72: // Flèche haut
            moveUp(grid);
            break;
        case 'j':
        case 77: // Flèche droite
            moveRight(grid);
            break;
        case 'n':
        case 80: // Flèche bas
            moveDown(grid);
            break;
        case 'q':
            exit(0); // Quitte le jeu si 'q' est pressé
            break;
        default:
            cout << "Utilisez les fleches ou les touches 'g' (gauche), 'y' (haut), 'j' (droite) et 'n' (bas) pour deplacer les tuiles, ou 'q' pour quitter." << endl;
            break;
        }

        printGrid(grid);
        // Vérifiez si le joueur a atteint 2048 ou s'il y a un match nul
        if (checkWin(grid)) {
            cout << "Vous avez gagné ! Félicitations !" << endl;
            break;
        }
        if (checkDraw(grid)) {
            cout << "Match nul. Il n'y a plus de mouvements possibles." << endl;
            break;
        }

    }
    return 0;
}
