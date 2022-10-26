#pragma once


/*
*	Parallel STL algorithms
*
*	By default STL algorithms will execute serially, that means all the operations are performed in the algorithm are performed on a single thread
*
*	C++17 provides overloads to these algorithms that can now execute parallelly
*
*	Algorithms that can be parallelized accept a new template pareameter called execution policy
*		- used to disambiguate the calls to overloads of the algorithm
*
*	This can be used to inform the algorithm if it should execute serially or parallelly
*
*	std::algorithm(execution_policy, begin, end, other args);
*
*
*	Execution Policies
*	- all policies existing in <execution> header and in std::execution namespace
*	- each policy = is an individual type (separate class)
*
*	sequenced_policy - seq
*		- the execution will not be parallelized and will perform operations sequentially element by element
*		- same as invoking algorithms from C++14
*
*	parallel_policy - par
*		- indicates the algorithm should execute parallelly
*		- might use threads from a thread pool for execution along with the calling thread
*
*	parallel_unsequenced_policy - par_unseq
*		- indicates the execution may be parallelized, vectorized or migrated across threads
*		(Vectorization - process, by which multiple instructions can be executed in parallel.
*		These are executed by special instructions provided by the CPU)
*
*	New parrallel algorithms that was added in C++17 :
*		for_each
*		for_each_n
*		reduce
*		exclusive_scan
*		inclusive_scan
*		transform_reduce
*		transform_exclusive_scan
*		transform_inclusive_scan
*
*	Parrallel algorithms everywhere?
*
*		- backward compatibility
*		- can use both input & output iterators
*		- synchronization is expensive
*		- parallelized algorithms terminate on exceptions, sequence do not
*		- do not give good perfromance for operations on small numbaer of elements due to overhead
*/

void ParallelAlgorithmsMain();
