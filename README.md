qtile
=====

This project contains a file called Cartographer that is an example class showing how to write an A* best path algorithm. It is not perfect but I will try to improve it with time.


A few examples [underwhelming pictures](http://imgur.com/a/6aEvR)



<iframe title="YouTube video player" width="480" height="390" src="http://www.youtube.com/watch?v=wKKv6OllU5M?autoplay=1" frameborder="0" allowfullscreen></iframe>

usage
====

Press `space bar` to regenerate the path
`Escape` to close the program

deps
====
- libGL
- libSFML2.0
- jnxlibc (included)

installation
============
- Update the submodule and install it 

```
cd jnxlibc
cmake .
make
sudo make install
```
Build qtile 
```
cmake .
make
./qtile #run
```

![tile](http://i.imgur.com/LZnHgX3.png)

Auto generates best path

![tile2](http://i.imgur.com/yRhU2no.png =200x200)
