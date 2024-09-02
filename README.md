# How to clone

- Clone with submodules:

git clone --recurse-submodules git@github.com:MaximIJ/cppGameEngine.git

- Clone without submodules:

git clone git@github.com:MaximIJ/cppGameEngine.git \
git submodule init \
git submodule update

# Info

This repo will be used to implement my own game engine using c/cpp.

To handle windows and inputs I will use SDL:

https://libsdl.org/

The main objetive of the project is to get more advanced knowledge of the c/cpp programing languages.

Secondary goals are getting better at managing different git utilities and makefiles

# TODO's

- Create tags and branches and try to pull different version of the repository using this
tag's and branches.

- Create github Actions to automatically test that everything works before being able to push
to the master branch.
