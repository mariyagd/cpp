### Classes

#### classe PhoneBook 
- doit contenir un tableau 
- au maximum 8 contacts 
- doit avoir une méthode pour ajouter un contact au répertoire
- doit vérifier que le répertoire n'est pas déjà plein
- doit avoir une méthode pour supprimer un contact du répertoire
- doit avoir une méthode pour afficher tous les contacts du répertoire.

#### classe Contact
doit avoir les propriétés suivantes :
- un nom 
- un numéro de téléphone 
- une adresse 
- un surnom 
- un lourd secret
- La classe Contact doit avoir un constructeur pour initialiser ces propriétés.
- La classe Contact doit avoir une méthode pour afficher ses propriétés.

Au lancement du programme, le répertoire est vide et l’utilisateur peut entrer une
commande.

### Commandes qui peuvent être entrées:
#### ADD
- first name (prénom), 
- last name (nom de famille)
- nickname (surnom)
- phone number (numéro de téléphone)
- darkest secret (son plus lourd secret). 
- 
- Les champs d’un contact enregistré ne peuvent être vides.

#### SEARCH
Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
first name, last name et nickname.
◦ Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
par un pipe (’|’).

#### EXIT
Le programme quitte et les contacts sont perdus à jamais !