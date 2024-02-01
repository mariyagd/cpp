Mettre en œuvre une fonction permettant d'ajouter plusieurs nombres à la fois à la classe Span.
Cela signifie créer une fonction membre qui prend une plage d'itérateurs (range of iterators) 
en entrée et qui ajoute tous les éléments de cette plage à l'objet Span.

- `addNumber()`
Lorsque vous utilisez la fonction addNumber, vous ajoutez un nombre à la fois à la classe Span. Par conséquent, si vous avez 100 nombres à ajouter à votre Span, vous devez appeler la fonction addNumber 100 fois.
Cette approche est simple, mais peut être fastidieuse si vous avez un grand nombre de nombres à ajouter.
 
- `addRange()`
Lorsque vous utilisez la fonction addRange, vous pouvez ajouter une plage de nombres à la classe Span en une seule fois. Cela signifie que vous pouvez ajouter 100 nombres à la fois sans avoir à appeler la fonction addNumber de manière répétée.
Cette approche est plus efficace en termes de nombre d'appels de fonction, car elle évite la répétition de l'appel à addNumber pour chaque élément de la plage. Au lieu de cela, vous ajoutez tous les éléments de la plage en une seule opération.