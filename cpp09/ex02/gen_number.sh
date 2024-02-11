#!/bin/bash

# Vérification du nombre d'arguments
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <nombre_de_nombres>"
    exit 1
fi

# Nombre de nombres à générer
count=$1

# Générer et afficher les nombres uniques séparés par des espaces
existing_nums=()
while [ "${#existing_nums[@]}" -lt "$count" ]; do
    num=$((RANDOM % count + 1))
    if [ "${existing_nums[num]}" != "1" ]; then
        existing_nums[num]="1"
        echo -n "$num "
    fi
done
echo "" # Saut de ligne à la fin

