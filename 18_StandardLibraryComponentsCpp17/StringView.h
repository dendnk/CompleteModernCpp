#pragma once

/*
*	std::string_view
*
*	Allows to deal with strings (sequence of constant character) without allocating memory
*	Can be considered as a kind of reference to a character sequence. Cannot modify the character sequence throught the string_view
*	Can be used where evere a non-modifiable string is required
*	It simply stores a pointer to the character array along with its length
*	It is fast and cheap to copy
*	It should be used carefully - it can lead to bugs
*
*	Properties
*
*	Underlying sequence is read-only
*	It can be accessed throught data() method
*		- may return a nullptr (if sequence doesn't exist)
*		- a character sequence may (contain / not contain) null terminator
*
*	We can only :
*		- assign a new value
*		- swap values
*		- shrink it to subset of character sequence
*
*	It is not guaranteed to be null-terminated
*		- consequently, may not work with C string functions
*
*	No allocator support
*
*	The advantage using std::string_view - we can use it with any kind of string
*	Such as QString from QT library or C string from MFC, even use string from com.
*	In com string represented as binary strings
*
*	When to use std::string_view
*		Don't pass in functions that accept C-style string because it might not have a null terminator
*		Do not return string_view to string from a function
*		Do not assign temporary strings to strings view
*		Avoid as class members
*
*/

void StringViewMain();
