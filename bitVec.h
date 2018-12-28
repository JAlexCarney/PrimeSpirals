class BitVec
{
	private:
	char* data;
	int len;
	public:
	BitVec(int length);
	bool getVal(int pos);
	int getLen();
	void setVal(int pos);
	void delVal(int pos);
	void print();
};
