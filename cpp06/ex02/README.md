### dynamic_cast conversion


Safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy.


A downcast can also be performed with static_cast, which avoids the cost of the runtime check, but it's only safe if the program can guarantee (through some other logic) that the object pointed to by expression is definitely Derived.

Tests:
- Je vérifie si le pointeur est `nullptr` ;
- Si le pointeur est `nullptr`,je ne peux pas l'envoyer dans `indentify(Base &p)` ;
- Je vérifie le multiple héritage.
