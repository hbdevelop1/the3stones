

void * operatornew(size_t  size, char const *filename, int line)
{
	void *ptr = //(void *)malloc(size);
		::operator new(size);

	return(ptr);
};



void main5()
{
	//char *c;=new("",4) char;	delete c;
}