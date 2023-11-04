#!/bin/bash

# Exports Aseprite files as horizontal spritesheets in "name-tag.png" format.

aseprite="/Applications/Aseprite.app/Contents/MacOS/aseprite -b"

for sprite in assets/aseprite/*; do
    name=$(basename sprite)

    echo "Exporting $sprite"
    for tag in $($aseprite --list-tags $sprite); do
        $aseprite --tag $tag $sprite --sheet "assets/sprites/$name-$tag.png" > /dev/null
    done
done
