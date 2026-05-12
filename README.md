# TP_Parcours

## Description du Projet

Ce projet est une application C++ qui implémente des formes géométriques (Cercle, Carré, Triangle) avec des méthodes pour :
- Calculer des propriétés géométriques (périmètre, aire, circonférence)
- Effectuer des transformations (translation, rotation, redimensionnement)
- Afficher les formes graphiquement
- Vérifier l'égalité et les propriétés spéciales des formes

Le projet utilise la bibliothèque **CTurtle** le rendu graphique et les dessins.

## Environnement et Compilation

### Architecture du Projet

```
├── include/          - Fichiers d'en-tête (headers)
│   ├── shapes/       - Headers pour les formes (Circle, Square, Triangle)
│   └── *.hpp         - Headers pour Point, draw, etc.
├── src/              - Fichiers source implémentation
│   └── shapes/       - Implémentations des formes
├── test/             - Fichiers de tests unitaires
├── main.cpp          - Programme principal
├── makefile          - Script de compilation automatique
├── TP.pdf            - Sujet du TP
└── Licence           - Licence du projet
```

### Makefile - Configuration Multi-Plateforme

Le Makefile a été modifié pour supporter **Windows et Linux** automatiquement grace à une détection automatique de l'OS, sur Windows les flags `-lgdi32 -luser32` sont ajoutés et sur Linux les flags `-lX11`

Pour compiler avec Make, il suffit de faire la commande,
```bash
make -B
./main
```
Et pour nettoyer les fichiers de compilation, il suffit de faire la commande,
```bash
make clean
```

### Compilation Manuelle (si Makefile indisponible)

**Windows :**
```bash
g++ -std=c++23 -Iinclude -o main src/*.cpp src/shapes/*.cpp test/*.cpp main.cpp -lgdi32 -luser32
./main
```

**Linux :**
```bash
g++ -std=c++23 -Iinclude -o main src/*.cpp src/shapes/*.cpp test/*.cpp main.cpp -lX11
./main
```

## Wiki des Méthodes

### Méthodes de la classe Point

double distance(Point B) --> Retourne la distance entre l'instance du point et le point B.

bool eqauls(Point B) --> Vérifie si deux points sont égaux (même coordonnées).

### Méthodes de la classe Circle

double circumference() --> Retourne la circonférence du cercle (2 × π × rayon).

double area() --> Retourne l'aire du cercle (π × rayon²).

void draw() --> Dessine le cercle.

void translate(Point T) --> Déplace tout le cercle d'un vecteur T.

void resize(double ratio) --> Redimensionne le cercle par un facteur ratio (rayon × ratio) tout en gardant son centre fixe.

bool equals(Circle circle) --> Vérifie si deux cercles sont égaux (même centre et même rayon).

### Méthodes de la classe Square

double side() --> Retourne la longueur du côté du carré.

double perimeter() --> Retourne le périmètre du carré (4 × côté).

double area() --> Retourne l'aire du carré (côté²).

Point center() --> Retourne le centre du carré (milieu des deux coins opposés A et C).

void draw() --> Dessine le carré.

void translate(Point T) --> Déplace tout le carré d'un vecteur T.

void resize(double ratio) --> Redimensionne le carré par un facteur ratio tout en gardant son centre fixe.

void rotate(double angle) --> Fait pivoter le carré d'un angle donné (en radians, dans le sens trigonométrique) autour de son centre.

bool equals(Square square) --> Vérifie si deux carrés sont égaux (mêmes coins A et C).

Circle inscribedCircle() --> Retourne le cercle inscrit dans le carré (cercle tangent aux 4 côtés).

Circle circumscribedCircle() --> Retourne le cercle circonscrit au carré (cercle passant par les 4 sommets).

### Méthodes de la classe Triangle

double perimeter() --> Retourne le périmètre du triangle (somme des 3 côtés).

double area() --> Retourne l'aire du triangle (formule de Héron).

Point center() --> Retourne le centre de gravité du triangle (intersection des médianes).

void draw() --> Dessine le triangle.

void translate(Point T) --> Déplace tout le triangle d'un vecteur T.

void resize(double ratio) --> Redimensionne le triangle par un facteur ratio tout en gardant son centre de gravité fixe.

void rotate(double angle) --> Fait pivoter le triangle d'un angle donné (sens trigonométrique) autour de son centre de gravité.

bool equals(Triangle triangle) --> Vérifie si deux triangles sont égaux (mêmes sommets).

bool isRightAngled() --> Vérifie si le triangle est rectangle (présence d'un angle droit).

bool isEquilateral() --> Vérifie si le triangle est équilatéral (3 côtés égaux).

bool isIsoceles() --> Vérifie si le triangle est isocèle (au moins 2 côtés égaux).

Circle inscribedCircle() --> Retourne le cercle inscrit dans le triangle (cercle tangent aux 3 côtés).

Circle circumscribedCircle() --> Retourne le cercle circonscrit au triangle (cercle passant par les 3 sommets).


## Notes

- **Standard C++** : Le projet utilise C++23 pour bénéficier des dernières fonctionnalités du langage
- **Dépendances** : CImg (en-tête uniquement) et CImg pour les graphiques
- **Plateforme testée** : Windows et Linux
- **Compilateur** : g++ (MinGW sur Windows, natif sur Linux)