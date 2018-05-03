
class StringSet
{
public:

	StringSet();

	StringSet(const StringSet & str);

	~StringSet();

	bool insert(string str);

	bool remove(string str);

	int find(string str);

	int size()const;

	StringSet unions(const StringSet & str) const;

	StringSet intersection(const StringSet & str) const;

	StringSet difference(const StringSet & str) const;

private:

	int maximum;

	string* set;

	int current;
};