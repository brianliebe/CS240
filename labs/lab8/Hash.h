#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <vector>

class Hash {
	private:
		std::vector<std::pair<std::string, std::string>> array;
		unsigned int arrSize;
	public:
		Hash (unsigned int size);
		bool insert (std::string key, std::string value);
		bool remove (std::string key);
		std::string find (std::string key);
		bool empty();
		int size();
		void printHash();
		int hasher (std::string key);
};

#endif

/*

use vectors of pairs, so vector<string, string>

If there's a collision, just resize the array. If size = 5, use # % 5, but adding 5 then 15 causes a collision.
So, you'd just increase the size of the array. Find a prime number b/w 1.5-2.0 X 5, so 7-10. The only prime is 7.
Now the size is 7. You'd then re-hash the numbers so 15->1 and 5->5. If you get a collision while rehashing, you'd
just perform the same operation until there aren't any collisions. (This will leave empty spots).

*/
