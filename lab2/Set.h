class Set {
	int n;
	int* elems;
public:
	Set();
	Set(int k);
	Set(int k, int* mas);
	Set(const Set& ob);
	~Set() { delete[]elems; }
	void CheckElement(int k);
	int GetCardinality() { return n; }
	int GetOneElem(int i) { return elems[i]; }
	void GiveMemory(int k);
	Set operator+(Set ob);
	Set operator-(Set ob);
	Set operator*(Set ob);
	friend Set Build_set(Set ob1, Set ob2);
};
