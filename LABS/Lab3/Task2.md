## TASK 2

```sh
read -p "Enter the sentence: " sen

count=0
len=${#sen}

for ((i = 0; i < $len; i++))
do
    ch=${sen:$i:1}

    if [[ $ch == "a" || $ch == "e" || $ch == "i" || $ch == "o" || $ch == "u" || $ch == "A" || $ch == "E" || $ch == "I" || $ch == "O" || $ch == "U" ]];
    then
        ((count++))
    fi
done

echo "Number of vowels: $count"
```

## OUTPUT:
![image](https://github.com/user-attachments/assets/a477cf69-b791-4fd0-9f1d-ab2fbc99d673)
