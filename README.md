# TP_Parcours

Méthodes de la classe Cercle --> Méthode Description


double circumference() -->	Retourne la circonférence du cercle (2 × π × rayon).

double area() --> Retourne l'aire du cercle (π × rayon²).

void draw() -->	Dessine le cercle .

void translate(Point T) -->	Déplace tout le cercle pour que son centre aille au point T.

void resize(double ratio) --> Redimensionne le cercle par un facteur ratio (rayon × ratio) tout en gardant son centre fixe.

bool equals(Circle circle) -->	Vérifie si deux cercles sont égaux (même centre et même rayon).



Méthodes de la classe Square --> Méthode Description


double side() --> Retourne la longueur du côté du carré.

double perimeter() --> Retourne le périmètre du carré (4 × côté).

double area() --> Retourne l'aire du carré (côté²).

Point center() --> Retourne le centre du carré (milieu des deux coins opposés A et C).

void draw() --> Dessine le carré.

void translate(Point T) --> Déplace tout le carré pour que son centre aille au point T.

void resize(double ratio) --> Redimensionne le carré par un facteur ratio tout en gardant son centre fixe.

void rotate(double angle) --> Fait pivoter le carré d'un angle donné (en radians, dans le sens antihoraire) autour de son centre.

bool equals(Square square) --> Vérifie si deux carrés sont égaux (mêmes coins A et C).

Circle inscribedCircle() --> Retourne le cercle inscrit dans le carré (cercle tangent aux 4 côtés).

Circle circumscribedCircle() --> Retourne le cercle circonscrit au carré (cercle passant par les 4 sommets).



Méthodes de la classe Triangle --> Méthode Description


double perimeter() --> Retourne le périmètre du triangle (somme des 3 côtés).

double area() --> Retourne l'aire du triangle (formule de Héron ou base×hauteur/2).

Point center() -->	Retourne le centre de gravité du triangle (intersection des médianes).

void draw() -->	Dessine le triangle.

void translate(Point T) -->	Déplace tout le triangle pour que son centre de gravité aille au point T.

void resize(double ratio) -->	Redimensionne le triangle par un facteur ratio tout en gardant son centre de gravité fixe.

void rotate(double angle) -->	Fait pivoter le triangle d'un angle donné (sens antihoraire) autour de son centre de gravité.

bool equals(Triangle triangle) -->	Vérifie si deux triangles sont égaux (mêmes sommets).

bool isRightAngled() -->	Vérifie si le triangle est rectangle (présence d'un angle droit).

bool isEquilateral() -->	Vérifie si le triangle est équilatéral (3 côtés égaux).

bool isIsoceles() -->	Vérifie si le triangle est isocèle (au moins 2 côtés égaux).

Circle inscribedCircle() -->	Retourne le cercle inscrit dans le triangle (cercle tangent aux 3 côtés).

Circle circumscribedCircle() -->	Retourne le cercle circonscrit au triangle (cercle passant par les 3 sommets).