```

                       _____ _   _ _____    ____    _  _____ _____ ____     ___  _____ 
                      |_   _| | | | ____|  / ___|  / \|_   _| ____/ ___|   / _ \|  ___|
                        | | | |_| |  _|   | |  _  / _ \ | | |  _| \___ \  | | | | |_   
                        | | |  _  | |___  | |_| |/ ___ \| | | |___ ___) | | |_| |  _|  
                        |_| |_| |_|_____|  \____/_/   \_\_| |_____|____/   \___/|_|    

                                       ____  _   _ _____ _     _     
                                      / ___|| | | | ____| |   | |    
                                      \___ \| |_| |  _| | |   | |    
                                       ___) |  _  | |___| |___| |___ 
                                      |____/|_| |_|_____|_____|_____|
                                                                      
```

## ASH: The ALX Shell
The gates of shell is a shell program built during the ALX SE program as a final project for the first trimester, it helps student to understand the advanced
concepts behind the shell program include process, system call, bit manipulation, file managment, error handling ...

## Getting ASH
In order to install the shell and get benefits of it's features you need to clone the current project, and compile it.
You need to make sure that this shell tested and garantees work based on `gcc-4.8` and the `C90` standard.

## Features
Some of the main featurs of this shell includes - 

* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* Hndling the “end of file” condition (Ctrl+D)
* Hanling the command line with arguments
* Handle the PATH
* Support the exit features and the exit status
* Handle the Ctrl-C to not terminate the shell
* Handling the command seperator `;`
* Handling `&&` and `||` logical operators
* Handle variable replacements `$?` and `$$`
* Handle the comments `#`
* Support the history feature
* Support the file input

## Builtins
* The exit builtin `exit [STATUS]`
* The change directory `cd [DIRECTORY] | [OPTION]`
* Display the environnment variables `env`
* Initialize a new environnment variables or created if not match `setenv [VARIABLE] [VALUE]`
* Remove an environnment variable `unsetenv [VARIABLE]`
* Support the aliases `alias [name [='value'] ...]`
* Display help `help [BUILTIN]`
* Display history `history`

## Authors
Egwuchika Tochukwu - Software Engineer - [Linkedin](https://www.linkedin.com/TochukwuEgwuchika/)
Iyamu Hope Nosa - Software Engineer - [Linkedin](https://www.linkedin.com/in/iyamuhope)
