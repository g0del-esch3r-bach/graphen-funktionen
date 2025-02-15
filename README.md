Graph Theory Season 3.
* sanitize.cpp sanitizes the raw adjacency matrix data into a readable format
* elements.cpp takes in an adjacency matrix and value alpha and outputs the two values that we need for the cost function (average path length L, number of edges E) as well as the cost function itself
* costfunc.cpp loops over all graphs of some fixed # of vertices (given N and alpha) and outputs the optimal graph (minimizing the cost func)
* critval.cpp is the same as costfunc.cpp, but alpha is close to the critical value, (N+1)/(N+4)
* onecostfunc.cpp take in an adjacency matrix and alpha and outputs the cost function value