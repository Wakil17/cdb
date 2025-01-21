Wakil Youssouf 3SI4
# Base de Données de Voitures

Ce projet implémente une base de données simple pour stocker des informations sur des voitures, utilisant une structure d'arbre binaire de recherche.

## Compilation

Pour compiler le projet, assurez-vous d'avoir GCC installé sur votre système, puis suivez ces étapes :

1. Ouvrez un terminal et naviguez vers le répertoire du projet.
2. Exécutez la commande suivante : `make`
3. Si la compilation réussit, un exécutable nommé "db" sera créé dans le dossier "bin".

## Exécution

Pour lancer le programme, utilisez la commande suivante : `./bin/db`

## Commandes disponibles

Une fois le programme lancé, vous pouvez utiliser les commandes suivantes :

1. Insérer une nouvelle voiture : `insert <id> <marque> <modele>`  
   Exemple : `insert 1 BMW M3`

2. Afficher toutes les voitures : `select`

3. Supprimer une voiture (non implémenté) : `delete <id>`

4. Quitter le programme : `exit`

## Persistance des données

Les données sont automatiquement sauvegardées dans un fichier nommé "database.txt" à chaque modification et lors de la fermeture du programme. Au démarrage, le programme charge automatiquement les données de ce fichier s'il existe.

## Tests

Pour tester le programme, vous pouvez suivre ces étapes :

1. Lancez le programme.
2. Insérez quelques voitures :  
   `insert 1 BMW M3`  
   `insert 2 Audi A4`  
   `insert 3 Mercedes C200`

3. Affichez le contenu de la base de données : `select`

4. Quittez le programme : `exit`

## Limitations connues

- La fonction de suppression n'est pas encore implémentée.
- La recherche par marque et par ID n'est pas opérationnelle dans cette version, mais des tests commentés dans le fichier `tree.c` montrent que la logique est présente.
- Problème de persistance : les données sont supprimées après l'arrêt du programme.
