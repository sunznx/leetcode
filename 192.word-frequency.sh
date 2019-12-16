# CreateTime: 2019-12-16 22:02:45
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt| tr -s ' ' '\n' | sort | uniq -c | sort -rn | awk '{print $2,$1}'
