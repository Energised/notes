#pragma once

// ******************************************************************************************************************
// For each element in iterator range
// ******************************************************************************************************************
template<typename IT_SRC, // Iterator type for the src container
         typename F>      // Mapping function type
void my_for_each(IT_SRC begin_src, IT_SRC end_src,
	             F func) {

	while (begin_src != end_src) {
		// Function may observe or modify the value at the iterator
		func( *(begin_src++) );
	}
}

template<typename IT_SRC, // Iterator type for the src container
         typename F>      // Mapping function type
void my_for_each_n(IT_SRC begin_src, 
	               const size_t N,
	               F func) {

	// Increment for N elements
	for (size_t i = 0; i < N; i++) {
		// Function may observe or modify the value at the iterator
		func( *(begin_src++) );
	}
}

// ******************************************************************************************************************
// Equality between iterator ranges
// ******************************************************************************************************************
template<typename IT_SRC_0, // Iterator type for the first src container
	     typename IT_SRC_1> // Iterator type for the second src container
bool my_equal(IT_SRC_0 begin_src_0, IT_SRC_0 end_src_0,
	          IT_SRC_1 begin_src_1) {

	while (begin_src_0 != end_src_0) {
		// Return false as soon as we find a single not equal pair
		if ( !( *(begin_src_0++) == *(begin_src_1++) ) ) {
			return false;
		}
	}
	// If we reach here we know every element passed the comparison
	return true;
}

template<typename IT_SRC_0, // Iterator type for the first src container
	     typename IT_SRC_1, // Iterator type for the second src container
	     typename F>        // Equality predicate function type
bool my_equal(IT_SRC_0 begin_src_0, IT_SRC_0 end_src_0,
	          IT_SRC_1 begin_src_1,
	          F eq_cmp) {

	while (begin_src_0 != end_src_0) {
		// Return false as soon as we find a single not equal pair
		if ( !eq_cmp( *(begin_src_0++), *(begin_src_1++) ) ) {
			return false;
		}
	}
	// If we reach here we know every element passed the comparison
	return true;
}

// ******************************************************************************************************************
// Find matching value in iterator range. Linear search
// ******************************************************************************************************************
template<typename IT_SRC, // Iterator type for the src container
	     typename T>      // Target value type
IT_SRC my_find(IT_SRC begin_src, IT_SRC end_src,
		       const T &value) {

	while (begin_src != end_src) {
		// Test if the value at the current iterator is the value we are searching for
		if ( *(begin_src) == value ) {
			// Return iterator to the matching element
			return begin_src;
		}
		// Increment iterator if this is not the value we are looking for ( *jedi wave* )
		begin_src++;
	}
	// At this point begin_src == end_src so return either...
	return begin_src;
}

template<typename IT_SRC, // Iterator type for the src container
         typename F>      // Predicate function type
IT_SRC my_find_if(IT_SRC begin_src, IT_SRC end_src,
		          F predicate) {

	while (begin_src != end_src) {
		// Test if the value at the current iterator is the value we are searching for
		if ( predicate( *(begin_src) ) ) {
			// Return iterator to the matching element
			return begin_src;
		}
		// Increment iterator if this is not the value we are looking for ( *jedi wave* )
		begin_src++;
	}
	// At this point begin_src == end_src so return either...
	return begin_src;
}

// ******************************************************************************************************************
// Copy values between iterator ranges
// ******************************************************************************************************************
template<typename IT_SRC, // Iterator type for the src container
	     typename IT_DST> // Iterator type for the dst container
void my_copy(IT_SRC begin_src, IT_SRC end_src,
	         IT_DST begin_dst) {

	while (begin_src != end_src) {
		// Invoke copy assignment from element in src to element in dst
		*(begin_dst++) = *(begin_src++);
	}
}

template<typename IT_SRC, // Iterator type for the src container
	     typename IT_DST, // Iterator type for the dst container
	     typename F>      // Predicate function type
void my_copy_if(IT_SRC begin_src, IT_SRC end_src,
	            IT_DST begin_dst,
	            F predicate) {

	while (begin_src != end_src) {
		// Test if each src element passes the predicate
		if ( predicate( *(begin_src) ) ) {
			// Only increment dst iterator if we pass the predicate
			// Invoke copy assignment from element in src to element in dst
			*(begin_dst++) = *(begin_src); 
		}
		// Always increment src iterator
		begin_src++; 
	}
}

// ******************************************************************************************************************
// Use of using to make a concrete reference to a template type
// ******************************************************************************************************************
template<typename T> 
class my_vector {
private:
	T data; // T is only visible as a type within this class definition

public:

	using value_type = T;

	// ... implementation omitted ...

	// Usage example
	// value_type can be used to recover internal type T after definition. 
	// i.e.
	// my_vector<  T>::value_type ==   T
	// my_vector<int>::value_type == int
	//
	// Can be used as concrete type for instantiation...
	// my_vector<int>::value_type value = 42; 
	// int value = 42;
};

// ******************************************************************************************************************
// Pseudo iterator that calls push_back() internally
// ******************************************************************************************************************
template<typename C>
struct my_push_back_iterator {
	// Reference to the container to call push_back() on...
	C &container;

	// Constructor - Capture the modifyable reference.
	my_push_back_iterator(C &_container) : container(_container) {}

	// Iterators need to be able to be post-fix incremented, i.e. (it++) 
	// even though this pseudo iterator does not do anything when it does.
	my_push_back_iterator operator++(int) {
		// Do nothing
		return *this;
	}

	// Overloaded dereference operator
	// Pseudo iterator uses this as opportunity to create a new value, 
	// add it to the container using push_back(),
	// and return a reference to it so that it can be copy assigned a proper value.
	//
	// Need to use typename key word given C is a template parameter. 
	// We need to force to compiler to evaluate C so we can access its internal value_type type.
	typename C::value_type& operator*() {
		container.push_back( C::value_type() ); // value_type must be default constructible
		return container.back(); // Return reference to the element now at the end of the container
	}
};

// ******************************************************************************************************************
// Transformation on one or two iterator ranges
// ******************************************************************************************************************
template<typename IT_SRC, // Iterator type for the src container
	     typename IT_DST, // Iterator type for the dst container
	     typename F>      // Transformation function type
void my_transform(IT_SRC begin_src, IT_SRC end_src, 
	              IT_DST begin_dst, 
	              F func) {

	while (begin_src != end_src) {
		// Equivalent to my_copy with a function applied to convert the value
		// potentially to a different type or transform it in some way...
		*(begin_dst++) = func( *(begin_src++) );
	}
}

template<typename IT_SRC_0, // Iterator type for the first src container
	     typename IT_SRC_1, // Iterator type for the second src container
	     typename IT_DST,   // Iterator type for the dst container
	     typename F>        // Transformation function type
void my_transform(IT_SRC_0 begin_src_0, IT_SRC_0 end_src_0, 
	              IT_SRC_1 begin_src_1, 
	              IT_DST begin_dst, 
	              F func) {

	while (begin_src_0 != end_src_0) {
		// Two input values go in, one result value comes out and is assigned to the dst iterator
		*(begin_dst++) = func( *(begin_src_0++), *(begin_src_1++) );
	}
}