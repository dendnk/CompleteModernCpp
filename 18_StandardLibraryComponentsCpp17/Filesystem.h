#pragma once


/*
*	Filesystem
*
*	C++17 added support for working with filesystem components
*
*	Adopted from Boost.Filesystem, it was adjusted to new language standards and made consistent with other parts of the library
*
*	Provide facilities for performing following operations:
*		- manipulation of filesystem path
*		- create, move, rename, delete directories
*		- list contents of a given directory
*		- get info about path, file permissions, and etc.
*
*	To create read and write files, it will still use the stream library classes (ofstream, ifstream, fstream)
*
*	The facilities are provided in <filesystem> header under std::filesystem namespace
*		- path					- allows manipulation of paths that represents existing fils anddirectories
*		- directory_entry		- represents a path with additional information such as file size, file times, etc
*		- directory_iterator	- an iterator that iterates over the the contents of directory
*		- functions for working with directories
*		- and much more
*
*	Two ways to indicate failure:
*		- many functions will throw std::filesystem_error exception
*		- returning an error code
*/


void FilesystemMain();
