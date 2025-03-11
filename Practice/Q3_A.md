```sh
pos=0
neg=0
zero=0
numbers=()

for ((i = 0; i < 10; i++))
do
    read -p "Enter number $((i + 1)): " num

    numbers+=("$num")  # Store the number

    if [[ $num -gt 0 ]]; then
        ((pos++))
    elif [[ $num -lt 0 ]]; then
        ((neg++))
    else
        ((zero++))
    fi
done

echo "Positive numbers: $pos"
echo "Negative numbers: $neg"
echo "Zeroes: $zero"

for ((i = 0; i < 9; i++))
do
    for ((j = 0; j < 9 - i; j++))
    do
        if [[ ${numbers[j]} -gt ${numbers[j+1]} ]]; then
            temp=${numbers[j]}
            numbers[j]=${numbers[j+1]}
            numbers[j+1]=$temp
        fi
    done
done

echo "Numbers in ascending order: ${numbers[*]}"
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/e990089d-0523-4599-9339-7bcb4b737a10)
