# Tutorials
> Tutorial of SDL2

[SDL2 - Installation][sdl2]

## Install
to install run as `sudo` user

```
sudo ./install_SDL2.sh
```

## Using

to use this tutorial you only need to run the `make` command

```bash
make demo1
make demo2
make demo3
```

This demos compiles into an `a.out` file in the directory. just run it and it as an executable file

```
./a.out
```

## Libraries
The functions used are in tutorial folder

## Problems found
### Unable to init Server
```
Unable to init SDL: Failed to connect to the Mir Server
```
#### Solution
I found this problem using the vagrant without gui interface, I switched to a ubuntu with visual interface.

<!-- Links -->
[sdl2]:https://intranet.hbtn.io/concepts/52
