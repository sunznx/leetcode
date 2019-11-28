# CreateTime: 2019-11-28 14:53:25
# Read from the file file.txt and output the tenth line to stdout.
cat file.txt | awk 'NR==10{print $0}'
