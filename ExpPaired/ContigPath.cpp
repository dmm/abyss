#include "ContigPath.h"
#include <algorithm>
#include <istream>
#include <iterator>
#include <ostream>

using namespace std;

/** Write a path. */
ostream& operator<<(ostream& out, const ContigPath& object)
{
	vector<MergeNode>::const_iterator last = object.end() - 1;
	copy(object.begin(), last, ostream_iterator<MergeNode>(out, " "));
	return out << *last;
}

/** Read a path. */
istream& operator>>(istream& in, ContigPath& object)
{
	copy(istream_iterator<MergeNode>(in),
			istream_iterator<MergeNode>(),
			back_inserter(object));
	return in;
}
