#include "queens.h"
#include <assert.h>
#include <stdlib.h>

/* check_same_diagonal: returns true iff queens (c0,r0) and (c1,r1) are in the
 * same diagonal. */
static bool check_same_diagonal(const int c0, const int r0,
                                const int c1, const int r1) {
	    const int x = abs(c0 - c1);
        const int y = abs(r0 - r1);
        return y==x;
}

/* check_column_ok: returns true iff the placement (c,r) is ok with all queens
 * to the left of column c already placed in queen_row.
 * precondition: queen_row must be at least of size c. */
static bool check_column_ok(const int c, const int r, const int queen_row[]) {
  bool a = true;
  for(int j=0 ; j < c; j++)
	a = a & !check_same_diagonal(c, r, j, queen_row[j]);
  return a;
  //assert(false);
}

/* find_available: returns an available row higher than min.
 * If no row is found returns -1 */
static int find_available(const int min, const int n, const bool available[]) {
  for(int i = min; i < n; i++)
	if(available[i])
	 return i;
  return -1;
}

/* _find_solution: tries to find a solution to the n-queens problems by filling
 * columns from c to n.
 * queen_row contains the row positions for columns lower than c.
 * available contains the available rows to fill columns higher or equal to c.
 */
static bool _find_solution(const int n, const int c, int queen_row[],
                           bool available[]) {
    if(c == n)
		return true;

	int k;
	int _q;
	bool _kv[n];
	
	for(int i = 0; i < n; i++)
		_kv[i] = available[i];
  
	for(;;){
		k = find_available(0,n,_kv);
		if(k == -1)
			return false;
		_kv[k] = false;

		if(check_column_ok(c,k,queen_row)){
			_q = queen_row[c];
			queen_row[c] = k;
			available[k] = false;
			
			if(_find_solution(n,c+1,queen_row,available))
				break;
			available[k] = true;
			queen_row[c] = _q;
		}
	}
	return true;
  //assert(false);
}

/* find_solution: returns true iff a n-queens solution is found.
 * queens_row is an int array of size n that will be
 * overwritten with the solution.
 *
 * if a solution is found, queens_row[c] will contain the row number for queen
 * at column c.
 * */
bool find_solution(const int n, int queen_row[]) {
  bool available[n];
  for (int i = 0; i < n; i++) {
    available[i] = true;
  }
  return _find_solution(n, 0, queen_row, available);
}
