# TP 2 Bases du Génie Logiciel -- Makefile & Tests & Réponses


#Réponses


#Reponse 1

#Makefile
J'ai remplacé le script build.sh par un Makefile.
En assurant de nettoyer le projet.
j'ai utilisé aussi la compilation séparée
Pour le lancement des tests avec la commande Make check on peut appeler la cible lors des tests'

On a fait une commande Make couverture pour le test de couverture

'

#Reponse 2

#Test de Parse_args
-La fonction Parse_args est testee dans main.
-Le premier test est choisis de telle sorte l'un n'a pas d'argument et l'autre a deux arguments
-Le deuxième test est choisis de telle sorte l'argument n'est pas valide car argc=2
-Le troisème test est valide car il respecte les entrées de la fonction./
-Non car tous les cas possibles sont testes

#Reponse 3
On a fait l'implementation de chacune des fonctions dans queens.c dans l'odre avec un ensemble de tests pour chacune des fonctions dans test_queens.c

On a fait aussi le test du programme finalise avec differentes tailles de grilles et on voit que le programme  repond bien au probleme pose


#Reponse 4 Bonus
On a utile llvm pour calculer la couverture de code obtenu durant les tests.
Et on a un taux de couverture atteint jusqu'à 100% avec test_queens'
Vous jetez un oeil sur test_queens.c.gcov


#Reponse 5 Bonus
On a utilise la fonction rdtsc.h pour mesurer le nombre de cycles en fonction de la taille n de l'echequier.
Et on voit que pour plusieurs mesures repetees , y a une petite instabilite car il y a toujours une difference de mesure avec la precedente.

Pour transformer le nombre de cycles mesure par RTDSC en temps Par exepmle si on note cette mesure par Mes,pour la tranformer en Temps; on prend cette mesure Mes et on le divise par la frequence du CPU de la machine.
donc on la formule suivante pour cela :
Temps=Mes/fcpu. le temps sera en seconde
 
On voit que la courbe du nombre de cycles  en fonction de la taille de l'echequier est exponnentielle donc la complexite est de la forme n^n(n puissance n) .








