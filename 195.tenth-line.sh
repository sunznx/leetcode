# Read from the file file.txt and output the tenth line to stdout.
cat file.txt | while read line; do
    let count=count+1;
    if [ $count == 10 ]; then
        echo $line;
    fi;
done
