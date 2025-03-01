## TASK 4

```sh
read -p "Enter the file or directory name: " file

if [[ -e $file ]]; 
then
    echo "$file exists"

    if [[ -f $file ]]; 
    then
        echo "$file is a Regular File"
    elif [[ -d $file ]]; 
    then
        echo "$file is a Directory"
    fi

    if [[ -r $file ]]; 
    then
        echo "Readable"
    else
        echo "Not Readable"
    fi

    if [[ -w $file ]]; then
        echo "Writable"
    else
        echo "Not Writable"
    fi

    if [[ -x $file ]]; 
    then
        echo "Executable"
    else
        echo "Not Executable"
    fi

    if [[ -s $file ]];
    then
        echo "File is Not Empty"
    else
        echo "File is Empty"
    fi

    if [[ $file == .* ]]; 
    then
        echo "It is a Hidden File"
    else
    	echo "It is not a Hidden File"
    fi

else
    echo "$file does not exist"
fi
```

## OUTPUT:
![image](https://github.com/user-attachments/assets/c9ed236e-ebba-4021-9c74-3db035bab32d)
