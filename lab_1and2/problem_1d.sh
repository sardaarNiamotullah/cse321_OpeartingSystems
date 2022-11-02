for i in {1..20}; do printf "This is line number: $i \n" >> fileForCounting.txt; done
sed -n '5,17p' fileForCounting.txt