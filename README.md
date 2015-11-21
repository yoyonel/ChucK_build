# ChucK/miniAudicle build from sources under Linux

# ChucK
[ChucK : Release](http://chuck.cs.princeton.edu/release/)

## Linux
(to build your own):
- source
- dependency: [libsndfile](http://www.mega-nerd.com/libsndfile/)
- ALSA, JACK, or OSS
(you should already have one)
- gcc, lex, yacc, make
(you better have these)

(and/or)
- miniAudicle
(experimental integrated IDE/VM)

## libsndfile
![logo](http://www.mega-nerd.com/libsndfile/libsndfile.jpg)

Libsndfile is a C library for reading and writing files containing sampled sound (such as MS Windows WAV and the Apple/SGI AIFF format) through one standard library interface.

Web: [http://www.mega-nerd.com/libsndfile/](http://www.mega-nerd.com/libsndfile/)

Here is the latest version. It is available in the following formats:

+ Source code as a .tar.gz : [libsndfile-1.0.25.tar.gz](http://www.mega-nerd.com/libsndfile/files/libsndfile-1.0.25.tar.gz) and (GPG signature).

./configure --prefix=/home/latty/__DEV__/__LOISIRS__/__MUSICS__/chuck/extern/build

Compiling some other packages against libsndfile may require
the addition of '/home/latty/__DEV__/__LOISIRS__/__MUSICS__/chuck/extern/build/lib/pkgconfig' to the
PKG_CONFIG_PATH environment variable.

A priori la lib libsndfile-1 est surement présente dans le système (Linux)

## ChucK : Build/Install Instructions
[http://chuck.cs.princeton.edu/doc/build/](http://chuck.cs.princeton.edu/doc/build/)

A priori pas trop de difficultés pour compiler cette lib sous Linux/Mint/Ubuntu.  
Le makefile n'est pas super évolué, faudrait voir pour effectuer une version CMake (plus propre/structuré).

```bash
.../chuck-1.3.5.2/src$
                      make -j linux-alsa
                      sudo cp chuck /usr/bin/;sudo chmod 755 /usr/bin/chuck
                      make clean
                      chuck --version

chuck version: 1.3.5.2 (chimera)
   linux (alsa) : 64-bit
   http://chuck.cs.princeton.edu/
   http://chuck.stanford.edu/
```

## Patch (Linux)
Il faut patch la lib pour avoir un son sur Linux.  
=> [Google Doc: Chuck - Linux, Mint](https://docs.google.com/document/d/1tvKwSEOIinuNdVqAXCmYIKZIHW2MgLaAero91Js-AoU/edit?usp=sharing)

Use a text-editor (preferably one that shows line-numbers) to open the file:  
geany src/RtAudio/RtAudio.cpp  

- Find line ~5660: 
```c++ 
sprintf( name, "hw:%d,%d", card, subdevice );
```

Revise this to read:
```c++
//sprintf( name, "hw:%d,%d", card, subdevice );  // commented out  
sprintf( name, "pulse" );
```

- Find line ~5699: 
```c++ 
int openMode = SND_PCM_ASYNC;
```

Revise this to read:
```c++
int openMode = SND_PCM_ASYNC;
printf( "pcm name %s\n", name );  // line inserted
```

## Test
La version *alsa* semble poser des pbs:  
`chuck]: RtApiAlsa::probeDeviceOpen: unable to synchronize input and output devices.`

Du coup, je suis passé à la version *pulse*:
```bash
.../chuck-1.3.5.2/src$
                      make -j linux-pulse
                      sudo cp chuck /usr/bin/;sudo chmod 755 /usr/bin/chuck
                      make clean
```
Puis on peut tester via les *examples* fournis:
```bash
chuck-1.3.5.2/examples/book/digital-artists/chapter1$ chuck WowExample.ck
```

# miniAudicle
*integrated development + performance environment for ChucK*
![http://audicle.cs.princeton.edu/mini/images/photoshop.jpg](http://audicle.cs.princeton.edu/mini/images/photoshop.jpg)

Site web: [http://audicle.cs.princeton.edu/mini/](http://audicle.cs.princeton.edu/mini/)

## [Linux](http://audicle.cs.princeton.edu/mini/linux/)
[![editeur](http://audicle.cs.princeton.edu/mini/images/mini-linux.png)](http://audicle.cs.princeton.edu/mini/linux/)

Pour les dernières release de l'éditeur: [http://audicle.cs.princeton.edu/mini/release/files/](http://audicle.cs.princeton.edu/mini/release/files/)  
Dernière source disponible: ![source](http://audicle.cs.princeton.edu/icons/compressed.gif) [miniAudicle-1.3.5.1.tgz](http://audicle.cs.princeton.edu/mini/release/files/miniAudicle-1.3.5.1.tgz)	22-Apr-2015 06:12	19M	 

### Build Instruction: [Linux](https://raw.githubusercontent.com/ccrma/miniAudicle/miniAudicle-1.3.3/notes/README.linux)
*On systems with apt-get available, running the following command with the full
list of packages will ensure that all necessary packages are installed.*
```bash
$ sudo apt-get install make gcc g++ bison flex libasound2-dev libsndfile1-dev \
libqt4-dev libqscintilla2-dev [libpulse-dev] [libjack-jackd2-dev]
```

```bash
miniAudicle-1.3.5.1/src$
                          make -j linux-pulse
                          sudo cp miniAudicle /usr/bin/;sudo chmod 755 /usr/bin/miniAudicle
                          make clean
```
A noter que l'éditeur miniAudicle contient une version de ChucK qui tourne sans problème (ni patch) => `miniAudicle-1.3.5.1/src/chuck`
