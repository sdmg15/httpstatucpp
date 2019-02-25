**HttpStatucpp**

This is a simple command line utility that let you get the meaning of 
http status codes right in your terminal.

# Building and running

 ##Requirements

* CMake (min 3.13)
* Clang or g++ 7.3.0

**NB :** This was tested only on Ubuntu 18.08 (Bionic)
## Building 

If all requirements are met, before building you need to set the `pathDatabase`
environment variable. The variable holds the path to the `database` folder. If no 
such variable is provided the build may fail.

`~$ export pathDatabase=/path/to/database/folder`

Run this command to inform CMake about the build process 
`~$ cmake CMakeLists.txt` 

then run `~$ make `

The resulted binary will be located inside the `build` directory.

## Running 

Before running make sure you are in the `build` folder.

Here is an example on how to run the command : 

`~$ ./httpstatucpp code 404`

# Todo 
 [x] code success -- display all success status codes
 
 [x] code errors -- display all errors status codes
 
 [x] code informational -- display all informational status codes
 
 [x] code redirection -- display all redirection status codes 
 
 [x] code serverError -- display all serverError status codes 
 
 [x] Enhance displaying of the result
    