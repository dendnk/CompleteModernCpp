#pragma once

/*
*	std:: variant
*	- is a type-safe replacement for unio type
*	- just like union, it uses the storage of the largets member
*	- the first member is always default initialized if variant is default constructed
*	- alternatively, you can initialize any member of the variant during construction
*	- members are destroyed properly
*	- throw bad_variant_access on invalid access*
*/

void VariantMain();
