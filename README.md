qtile
=====

This project contains a file called Cartographer that is an example class showing how to write an A* best path algorithm. It is not perfect but I will try to improve it with time.


[![Alt text for your video](http://img.youtube.com/vi/wKKv6OllU5M/0.jpg)](http://www.youtube.com/watch?v=wKKv6OllU5M)

A few more examples [underwhelming pictures](http://imgur.com/a/6aEvR)

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
