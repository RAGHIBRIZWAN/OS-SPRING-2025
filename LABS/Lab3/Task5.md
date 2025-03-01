## TASK 5

```sh
#!/bin/bash

read -p "Enter directory path: " source_dir

if [[ -d $source_dir ]]; then
    backup_file="backup_$(date +%Y%m%d_%H%M%S).tar.gz"
    tar -czf "$backup_file" "$source_dir"
    echo "✅ Backup Created Successfully!"
    echo "Backup File: $backup_file"
else
    echo "Error: Directory Not Found!"
fi
```

## OUTPUT:

![image](https://github.com/user-attachments/assets/386b9651-9b8a-443c-b436-32d172206faf)
