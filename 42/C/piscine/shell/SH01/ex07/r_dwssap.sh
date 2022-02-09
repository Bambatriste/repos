cat /etc/passwd |grep -v '#'| cut -d : -f 1 | awk '!(NR%2)'  |rev | sort -rg | sed -n ''$FT_LINE1','$FT_LINE2'p' | sed  "s/$/, /" | tr -d "\n'" | sed "s/, $/./" | tr -d "\n"
