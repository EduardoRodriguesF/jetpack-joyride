#!/bin/bash

# Exports Aseprite files as horizontal spritesheets in "name-tag.png" format.

aseprite="/Applications/Aseprite.app/Contents/MacOS/aseprite -b"

for sprite in assets/aseprite/*; do
    name=$(basename $sprite)
    name="${name%.*}"

    echo ""
    echo "$sprite:"
    for tag in $($aseprite --list-tags $sprite); do
        dest="$name-$tag.png" 
        echo $dest

        $aseprite --tag $tag $sprite --sheet "assets/sprites/$dest" > /dev/null
    done
done
