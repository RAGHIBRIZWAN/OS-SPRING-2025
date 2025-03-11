```sh
plier(){
	res=1
	for num in "$@";
	do
		((res *= num))
	done
	
	echo "result = $res"
}

plier $@
```

# OUTPUT:
![image](https://github.com/user-attachments/assets/0d1bc098-1420-443c-b26d-b9d3cbfeffe3)
