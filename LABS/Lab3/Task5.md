## TASK 5

```sh
read -p "Enter directory path: " source_dir

if [[ -d $source_dir ]]; then
    backup_file="backup_$(date +%Y%m%d_%H%M%S).tar.gz"
    tar -czf "$backup_file" "$source_dir"
    echo "Backup Created Successfully!"
    echo "Backup File: $backup_file"
else
    echo "Error: Directory Not Found!"
fi
```

## OUTPUT:

![image](https://github.com/user-attachments/assets/3edb2d41-7d47-4607-9a22-1a2ddc81822a)
