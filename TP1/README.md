**Binôme** : AHMIM Dina / SERDEL Quentin

# TP1 

## Question 2.1:
```
./tp1q1_2
```
Il nous a été demandé d'exacerber le problème à l'aide de la fonction *sleep*, ce qui a été fait à la ligne 45 dans la fonction *receiver*.
Ce qui rend encore plus lent  l'éxecution. 

## Question 2.2:
```
./tp1q1_2
```
Afin de résoudre le problème, le mutex m est bloqué après l'envoi de *sender* puis est attendu avec le signal dans *receiver* avant d'être débloqué.

## Question 2.3:
```
./tp1q1_2
```
La même logique que la question précédente est employée ici sauf qu'il y a une subtilité étant donné que nous avons 3 *receiver* 
Dans la fonction *sender* il y aura 6 attentes de sémaphore (2 pour chaque *receiver*) ce qui bloquera le thread (l'initialisation étant à 0 et la fonction *sem_wait* décrémente le conteur) jusqu'à l'appel d'un *sem_post* des *receiver* qui le débloquera en incrémentant.

## Question 3:
```
./tp1q3
```

### safe_send: 
Un mutex est bloqué puis la fonction *send* est appelée, ce n'est que lorsque le message est entièrement envoyé que le mutex sera débloqué pour permettre au programme de continuer. 

### test:
Nous avons ajouté une fonction *task_test* similaire à *task* mais qui éxecute *send* au lieu de *safe_send*. 
Puis dans le main, nous faisons appel aux fonctions *clock_gettime* pour avoir les temps d'éxecution. 8 threads sont crées, 4 qui utiliseront *send* et 4 qui utiliseront *safe_send*  
Ainsi, nous pouvons voir les latences que crée notre solution.