# AiSD #

## General ##

### Name ###

AiSD is a transliteration from russian АиСД, which is an abbrevation from "Алгоритмы и структуры данных". Last means "Algorithms and Data Structures".

### Description ###

"Algorithms and Data Structures" (see section "Name") is a high school course from Immanuel Kant Baltic Federal University authored by Grigoriev S. A. Code in this project contains solutions for issues given in that course.

Current implementation of AiSD is made with C99 (ANSI C99) standard of C language and aims to be crossplatform. Makefiles are used as a build system.

## Structure ##

AiSD contains solutions for many issues. Each group of solutions for similiar issues placed in its own folder named after category of those issues.

Every such folder contains:

* `Makefile` - makefile to build solutions in current folder;
* `input.txt` - example of input for given solutions;
* `src` - folder with solutions themselves and for subroutines sources, all in `*.c` files;
* `inc` - folder with header files for subroutines sources;
* `obj`, `lib`, `bin` - special folders with intermediate results whish appear while solutions are being compiled.

## Copyright ##

### License ###

AiSD is currently licensed under LGPLv3 - GNU Lesser General Public License ([original text on gnu.org](https://www.gnu.org/licenses/lgpl-3.0-standalone.html)).

### Copyright holder ###

No matter of license type, author of AiSD is **kryvashek**, and rights to decide what to do with project and which license to use belongs to **kryvashek** too.
If **kryvashek** will not like what you do with this software - he will find you, sue you and piss on your body afterwards.