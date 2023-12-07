# Number Theory Projects
Hey all, this repository is simply a place where I can bring the things I'm learning in Number Theory to life with code. I love experimenting around with things and seeing how what I've learned actually works. The functions in this project will all likely be very simple implementations of the idea.

Here is what I have created so far:
1. `power-mod n p m`: Computes the value of $n^p\ mod\ m$.
2. `qr n`: Calculates and lists all the quadratic residues of $n$.

## Creating & Running the Functions

I made this project the perfect excuse for me to get more accustomed to Makefiles and `make`. Most of this is experimental as I still have a lot to learn. However, in case you decide to clone this repository and try these functions out yourself, here's how it works:
- There's a parent `Makefile` at the root directory of this repository. It's in charge of running recursive `make` calls to the subdirectories within this repository.
- Each subdirectory has its own `Makefile` that compiles its specfic binary.
- All binaries are placed within the `bin/` directory at the root level. As you can see, this directory will appear empty on github. This is because I have added `bin/*` to the `.gitignore`.

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

## Final thoughts