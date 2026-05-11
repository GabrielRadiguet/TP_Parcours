# TP_Parcours

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