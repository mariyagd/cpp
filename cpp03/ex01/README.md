
#### Energy Points
- nécessaires pour attaquer ou se réparer
- si un objet a 0 _energy points_ -> il ne peut pas attaquer ou se réparer mais il est toujours vivant.

#### Hit Points
- points de vie
- si un objet a 0 _hit points_, il est mort! donc il ne peut attaquer ni se réparer.

#### Damage Attack 

- si un objet A attaque un objet B avec X _damage points_, l'objet B subit X dégats, c'est-à-dire il perds X _hit points_.

#### Ordre des appels aux constructeurs et déstructeurs

Lorsqu’une classe dérivée hérite des membres, ces membres peuvent être initialisés **uniquement** par le constructeur de la classe de base. Ce pourquoi le constructeur de la classe de base est appelé en premier, et ensuite on appelle le constructeur de la classe dérivée (ordre: base→derived).

Le constructeur paramétré d’une classe de base doit être appelé depuis le constructeur paramétré de la classe dérivée et non depuis le constructeur par défaut ( de la classe dérivée).

Les destructeurs sont appelés en ordre inverse (derived→base). Il ne faut jamais appeler explicitement le constructeur de la classe de base dans le constructeur de la classe dérivée (sauf s’il y a `new`).

Le déstructeur de la class dérivée appelle automatiquement le déstructeur de la classe de base.
