# 42 Lausanne - get_next_line
# get_next_line
This project as part of my 42 school curriculum`get_next_line` is a C function that reads a file line by line. It operates in a loop, reading the next line from the file until the end is reached. The function uses a buffer, defined by `BUFFER_SIZE`, to control how much of the file is read at a time.
## Key Functions
- `malloc()`, `free()`
- `read()`
- `ft_strchr()`, `ft_strlen()`, `ft_strdup()`, `ft_substr()`, `ft_strjoin()`
## Process
1. **Variable Initialization**: Utilizes `save` (static) and `buf` to hold and store data.

2. **File Descriptor Validation**: Employs `read()` to validate the file descriptor.
3. **BUFFER_SIZE Verification and Memory Allocation**: Ensures `BUFFER_SIZE` > 0, allocates memory for `buf` and `save`. 
4. **File Reading**: Reads the file in a loop, appending a null character at the end, joining the buffer content to `save`, freeing `save` and assigning it new data, and checking for a newline character in the buffer.

5. **Line Verification and Value Return**: Locates the newline character in `save`, subtracts the line from the start to the newline character, and returns the line. If no newline character is found, it checks for a null character and returns NULL or the value of `save` accordingly.
## Code Excepts
The function `init_check` initializes a structure and checks if the file descriptor is valid. If the file descriptor is valid, it returns 1; otherwise, it returns 0.

The function `read_check` reads the file and returns the character at the current position. If the current position is greater than or equal to the maximum position, it reads the file again and resets the current position to 0.

The `main` function opens a file and prints the lines read by `get_next_line`.
