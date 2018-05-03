

StringSet::StringSet()
{
	maximum = 2;
	current = 0;
	set = new set[maximum];
}

StringSet::StringSet(const StringSet & str)
{
	current = str.current;
	maximum = str.maximum;

	set = new set[maximum];

	for (int i = 0; i < current; i++){
		set[i] = str.set[i];
	}
}

StringSet::~StringSet()
{
	delete[] set;

}

bool StringSet::insert(string str)
{

	for (int x = 0; x < current; x++){
		if (str == set[x]){
			return false;
		}
	}

	if (current >= maximum){
		string* temp = new string[maximum];
		for(int i = 0; i < current; i++){
			temp[i] = set[i];
		}
		maximum *= 2;

		set = new string[maximum];

		for (int j = 0; j < current; j++){
			set[j] = temp[j];
		}
		delete[] temp;
	}
	set[current] = str;
	current++;

	return true;
}

bool StringSet::remove(string str)
{
	if(current == 0){
		return false;
	}
	
	for (int i = 0; i < current; i++){
		if(set[i] == str){
			se[i] = set[current-1];
			current--;
			return true;
		}
	}
	return false;
}

int StringSet::find(string str)
{
	for (int i = 0; i < current; i++){
		if (set[i] == str){
			return i;
		}
	}
	return -1;
}

int StringSet::size()
{
	return length;
}