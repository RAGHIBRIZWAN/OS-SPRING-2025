## TASK 3

```sh
read -p "Enter the filename: " filename

if [[ -f $filename ]];
then
    echo "Current date and time: $(date)" >> $filename
    echo "Append successfully!"
elif [[ ! -f $filename ]]; 
then
    touch $filename
    echo "File not found! Creating new file..."
    echo "Current date and time: $(date)" >> $filename
    echo "Append successfully!"
else
    echo "Error occurred!"
fi
```

## OUTPUT:

![image](https://github.com/user-attachments/assets/e20c1307-c21d-4807-b8f0-084a8f223282)
