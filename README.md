# Number Theory Projects
Hey all, this repository is simply a place where I can bring the things I'm learning in Number Theory to life with code. I love experimenting around with things and seeing how what I've learned actually works. The functions in this project will all likely be very simple implementations of the idea.

Here is what I have created so far:
1. `power-mod n p m`: Computes the value of $n^p\ mod\ m$.
2. `qr n`: Calculates and lists all the quadratic residues of $n$.

## Creating & Running the Functions

I made this project the perfect excuse for me to get more accustomed to Makefiles and `make`. Most of this is experimental as I still have a lot to learn. However, in case you decide to clone this repository and try these functions out yourself, here's how it works:
- There's a parent `Makefile` at the root directory of this repository. It's in charge of running recursive `make` calls to the subdirectories within this repository.
- Each subdirectory has its own `Makefile` that compiles its specfic binary.
- All binaries are placed within the `bin/` directory at the root level. If the `bin/` directory doesn't exist, you can create it by navigating to the root directory and running `mkdir bin/`.

*(All Makefiles were coded to work for Windows/Linux (WSL2). If you are unable to compile due to OS errors I would suggest looking up the required changes and make them in the Makefiles)*

### Creating the binary files

In order to create all binaries and be able to run any given function, simply nagivate to the root directory of this repository and run `make`. You should see an output like this:
```sh
make -C power-mod
make[1]: Entering directory '/.../numbertheory/power-mod'
gcc -Werror -Wall -Wpedantic -g -c power-mod.c -o power-mod.o
gcc -Werror -Wall -Wpedantic -g -c find-remainder-bf.c -o find-remainder-bf.o
gcc -Werror -Wall -Wpedantic -g -c find-remainder-dp.c -o find-remainder-dp.o
gcc -Werror -Wall -Wpedantic -g power-mod.o find-remainder-bf.o find-remainder-dp.o -o ../bin/power-mod
make[1]: Leaving directory '/.../numbertheory/power-mod'
make -C quadratic-residue
make[1]: Entering directory '/.../numbertheory/quadratic-residue'
gcc -Werror -Wall -Wpedantic -g -c qr.c -o qr.o
gcc -Werror -Wall -Wpedantic -g qr.o -o ../bin/qr -lm
make[1]: Leaving directory '/.../numbertheory/quadratic-residue'
```

### Running the binary files

Now that you have compiled the binary files, you can run them normally. Remember that all binary files are created and stored within the `bin/` directory. This means you have to either prepend `bin/` to the executable's name or navigate to the directory and run via `./exec-name`.

For example, if you want to run `power-mod` in the root directory, you would simply run:
```sh
$ bin/power-mod 4 1000 83
```

### Cleaning up

The parent `Makefile` has a `clean` rule. Similar to the creation of the binaries, it will go into each subdirectory and run the `clean` rule of its `Makefile`. This will remove all object files (`*.o`) from the subdirectories and empty the `bin/` directory. 
To call this, simply run `make clean` in the root directory. You should now see an output like this:
```sh
make -C power-mod clean
make[1]: Entering directory '/.../numbertheory/power-mod'
rm -f power-mod.o find-remainder-bf.o find-remainder-dp.o ../bin/power-mod
make[1]: Leaving directory '/.../numbertheory/power-mod'
make -C quadratic-residue clean
make[1]: Entering directory '/.../numbertheory/quadratic-residue'
rm -f qr.o ../bin/qr
make[1]: Leaving directory '/.../numbertheory/quadratic-residue'
```
Your `bin/` directory should now be empty and all subdirectories should no longer have any `.o` files!

## Final thoughts

Taking a course on Number Theory has been a super fun and exciting experience since I got exposure to a completely new side of mathematics. I want to learn more about this stuff in the future and am always looking to apply my knowledge of math within computer science (especially with things like cryptography!). 

Again, this is just an experimental playground for me in my Number Theory journey, so I'm bound to make mistakes here and there. Feel free to correct me or suggest changes to my code, or even tell me new ideas to implement! Thanks for stopping by and I hope you enjoyed your stay :D
