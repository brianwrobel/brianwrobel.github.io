/*
Brian Wrobel
CSCE 121 200
Homework 7 Problem 2
*/

/*
Write a program that reads in different kinds of publications
and prints them out formatted correctlty
*/

#include "std_lib_facilities_4.h"

//--------------------------------------------------------------

//Vector ref Class from Programming Principles and Practice Using C++
template<class T> class Vector_ref {
	vector<T*> v;
	vector<T*> owned;
public:
	Vector_ref() {}
	Vector_ref(T& a) { push_back(a); }
	Vector_ref(T& a, T& b);
	Vector_ref(T& a, T& b, T& c);
	Vector_ref(T* a, T* b = 0, T* c = 0, T* d = 0)
	{
		if (a) push_back(a);
		if (b) push_back(b);
		if (c) push_back(c);
		if (d) push_back(d);
	}

	~Vector_ref() { for (int i = 0; i<owned.size(); ++i) delete owned[i]; }

	void push_back(T& s) { v.push_back(&s); }
	void push_back(T* p) { v.push_back(p); owned.push_back(p); }

	T& operator[](int i) { return *v[i]; }
	const T& operator[](int i) const { return *v[i]; }

	int size() const { return v.size(); }

private:	// prevent copying
	Vector_ref(const Vector<T>&);
	Vector_ref& operator=(const Vector<T>&);
};

//--------------------------------------------------------------

//virtual class for which different types of publications are stored
class Publications 
{
public:
	//virtual function used by derived classes
	virtual string write_publication()=0;
};

//--------------------------------------------------------------

//Stores information on Books which can be formatted and read out
class Book : public Publications
{
public:
	Book(string author_last, string author_first, string title, string publication_city, string publishing_company, int date);

	//return functions (not necessary for this assignment)
	string get_author_first(){ return author_first; }
	string get_author_last(){ return author_last; }
	string get_title(){ return title; }
	string get_publication_city(){ return publication_city; }
	string get_publishing_company(){ return publishing_company; }
	int get_date(){ return date; }
	

	//edit functions(not necessary for this assignment)
	void edit_author_first(string a){ author_first = a; }
	void edit_author_last(string a){ author_last = a; }
	void edit_title(string t){ title = t; }
	void edit_publication_city(string city){ publication_city = city; }
	void edit_publishing_company(string company){ publishing_company = company; }
	void edit_date(int d){ date = d; }

	//prints book information in correct format
	string write_publication();

private:
	string author_first;
	string author_last;
	string title;
	string publication_city;
	string publishing_company;

	int date;
};

//--------------------------------------------------------------

//constructor for book
Book::Book(string a_l, string a_f, string t, string p_city, string p_company, int d)
{
	author_last = a_l;
	author_first = a_f;
	title = t;
	publication_city = p_city;
	publishing_company = p_company;
	date = d;
}

//--------------------------------------------------------------

//prints book information in correct format
//returned as a string
string Book::write_publication()
{
	ostringstream output;
	output << author_last << ", " << author_first << ". _" << title << "_. "
		<< publication_city << ": " << publishing_company << ", "
		<< date << ".";
	return output.str();
}

//--------------------------------------------------------------

//Stores information on Encyclopedia_Articles which can be edited and read out
class Encyclopedia_Article : public Publications
{
public:
	Encyclopedia_Article(string title_article, string title_encyclopedia, int date);

	//return functions(not necessary for this assignment)
	string get_title_article(){ return title_article; }
	string get_title_encyclopedia(){ return title_encyclopedia; }
	int get_date(){ return date; }
	

	//edit functions(not necessary for this assignment)
	void get_title_article(string title){ title_article = title; }
	string get_title_encyclopedia(string title){ title_encyclopedia = title; }
	void edit_date(int d){ date = d; }
	
	//prints out Encyclopedia_Article information in correct format
	string write_publication();

protected:
	
private:
	string title_article;
	string title_encyclopedia;

	int date;
};

//--------------------------------------------------------------

//constructor for Encyclopedia Article
Encyclopedia_Article::Encyclopedia_Article(string t_article, string t_encyclopedia, int d)
{
	title_article = t_article;
	title_encyclopedia = t_encyclopedia;
	date = d;
}

//--------------------------------------------------------------

//prints out Encyclopedia_Article information in correct format
//returns as a string
string Encyclopedia_Article::write_publication()
{
	ostringstream output;
	output << "\"" << title_article << ".\" _" << title_encyclopedia << "_. " << date << ".";
	return output.str();
}

//--------------------------------------------------------------

//Stores information about Journal Articles which can be edited and read out
class Journal_Article : public Publications
{
public:
	Journal_Article(string author_last, string author_first, string title, string journal, int date, int volume, int issue, int start_page, int end_page);

	//return functions(not necessary for this assignment)
	string get_author_first(){ return author_first; }
	string get_author_last(){ return author_last; }
	string get_title(){ return title; }
	string get_journal(){ return journal; }
	int get_date(){ return date; }
	int get_volume(){ return volume; }
	int get_issue(){ return issue; }
	int get_start_page(){ return start_page; }
	int get_end_page(){ return end_page; }

	
	//edit functions(not necessary for this assignment)
	void edit_author_first(string a){ author_first = a; }
	void edit_author_last(string a){ author_last = a; }
	void edit_title(string t){ title = t; }
	void edit_journal(string j){ journal = j; }
	void edit_date(int d){ date = d; } 
	void edit_volume(int v){ volume = v; }
	void edit_issue(int i){ issue = i; } 
	void edit_start_page(int s){ start_page = s; }
	void edit_end_page(int e){ end_page = e; } 
	
	//prints out Journal_Article information in correct format
	string write_publication();

private:
	string author_first;
	string author_last;
	string title;
	string journal;
	
	int date;
	int volume;
	int issue;
	int start_page;
	int end_page;
};

//--------------------------------------------------------------

//constructor for Journal_Article
Journal_Article::Journal_Article(string a_l, string a_f, string t, string j, int d, int v, int i, int s_page, int e_page)
{
	author_last = a_l;
	author_first = a_f;
	title = t;
	journal = j;
	date = d;
	volume = v;
	issue = i;
	start_page = s_page;
	end_page = e_page;
}

//--------------------------------------------------------------

//prints out Journal_Article information in correct format
//returns as a string
string Journal_Article::write_publication()
{
	ostringstream output;
	output << author_last << ", " << author_first << ". (" << date << ") \""
		<< title << ".\" _" << journal << "_ " << volume << "(" << issue << "):"
		<< start_page << "-" << end_page << ".";
	return output.str();
}

//--------------------------------------------------------------

//reads in unformatted publication information 
//input: vector of publications which the data is stored in
void read_in_file(vector<Publications*>& P)
{

	string ifile_name = "hw7pr2.txt";		//input file name
	cout << "Please enter the name of the publication file you would like to import\n"
		<< "(default: hw7pr2.txt)\n";
		
	cin >> ifile_name;

	//opening the file
	ifstream ist{ ifile_name };
	if (!ist){ error("can't open input file"); }

	//while the stream is good, read the file
	while (ist)
	{
		char ch;
		ist >> ch;
		switch (ch)
		{
			
		case 'B':	//reading in a book
		{
				string author_last;
				ist >> author_last;
				author_last = author_last.substr(0, author_last.size() - 1);

				string author_first;
				ist >> author_first;

				string title;
				ist.ignore();
				getline(ist, title);

				string publication_city;
				getline(ist, publication_city);
					
				string publishing_company;
				getline(ist, publishing_company);

				int date;
				ist >> date;
					
				Book* b = new Book{ author_last, author_first, title, publication_city, publishing_company, date };
				P.push_back(b);

				break;

		}
			
		case 'E':		//reading in a Encylcopedia article
		{
					string title_article;
					ist.ignore();
					getline(ist, title_article);

					string title_encyclopedia;
					getline(ist, title_encyclopedia);

					int date;
					ist >> date;

					Encyclopedia_Article* e = new Encyclopedia_Article{ title_article, title_encyclopedia, date };
					P.push_back(e);
					break;
		}
		case 'J':		//reading in a journal article
		{
					string author_last;
					ist >> author_last;
					author_last = author_last.substr(0, author_last.size() - 1);

					string author_first;
					ist >> author_first;

					string title;
					ist.ignore();
					getline(ist, title);

					string journal;
					getline(ist, journal);

					int volume;
					ist >> volume;

					int issue;
					ist >> issue;

					int start_page;
					ist >> start_page;


					int end_page;
					ist >> end_page;
						
					int date;
					ist >> date;

					Journal_Article* j= new Journal_Article{ author_last, author_first, title, journal, date, volume, issue, start_page, end_page };
					P.push_back(j);
					break;
		}
		default :
			error("file format not valid");
			break;
		
		}
	}	
	return;
}


//--------------------------------------------------------------

//prints out different publications in the correct format by calling write_publication
//Input: a vector of Publications that are read out
void read_out_file(vector<Publications*> P)
{
	string ofile_name = "hw7pr2o.txt";		//output file name
	cout << "Please enter the name of the file you would like to export to\n"
		<< "(default: hw7pr2o.txt)\n";
	cin >> ofile_name;

	//opening the file
	ofstream ost{ ofile_name };
	if (!ost){ error("can't open output file"); }
	for (int i = 0; i < P.size(); i++)
	{
		string out = P[i]->write_publication();
		ost << out << "\n";
	}
	return;
}

//--------------------------------------------------------------

int main(){

	try
	{
		vector<Publications*> P;
		read_in_file(P);		//reads in unformatted data
		
		read_out_file(P);	//reads out formatted data
		return 0;
		
	}

		catch (runtime_error e)
		{
			cerr << "runtime_error" << e.what() << "\n";
		}

}