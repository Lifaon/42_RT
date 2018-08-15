# ![dof](screenshots/depth_of_field.jpg)
## 'RT' stands for RayTracer
The objective of the project was to create computer generated images. It was a 4 people school project, made from scratch and entirely in C.

## Installing
#### Linux and Mac portability.<br>
You first need to have gtk+3 installed locally.<br>
- Linux :
```
$ apt-get install libgtk-3-dev
```
- Mac _(takes time)_ :
```
$ brew install gtk+3
```
Then run :
```
$ make
```

## Usage
The programm takes in argument a scene written in json. Multiple scenes are directly available in the directory with the same name.
```
$ ./rt 'file_name
```
Clustering calculations are implemented. You can run the programm simultaneously on different computers as long as you're connected to the same network<br>
- To run the programm as the host :
```
$ ./rt 'file_name' -host 'number of clients'
```
- To run the programm as a client _(IP host was given when running the programm as a host)_ :
```
$ ./rt 'file_name' -client 'IP host'
```
