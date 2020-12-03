#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


bool fibon_elem(int, int &);
vector<int> fibon_elem_2(int size);

void ex2_1() {
  int pos, elem;
  char ch;
  bool more = true;

  while(more)
  {
	cout << "Please enter a position: ";
	cin >> pos;

	if (fibon_elem(pos, elem))
	  cout << "elemetn # " << pos
	  << " is " << elem << endl;
	else
	  cout << "Sorry, could not find this element # "
	  << pos << endl;

	cout << "Would you like to try again? (y/n) ";
	cin >> ch;
	if (ch != 'y' || ch != 'Y')
	  more = false;
  }	
}


void ex2_2() {

}




/****** by reference or by value ******/
void display(vector<int> *vec) {
  if (!vec) {
	cout << "display(): the vector pointer is 0 \n";
	return;
  }

  for (int ix = 0; ix < vec->size(); ++ix)
	cout << (*vec)[ix] << ' ';
  cout << endl;
}

ofstream ofil("text_out1.txt");
// void swap(int vall, int val2) {
void swap(int &vall, int &val2) {
  ofil << "swap( " << vall
	<< ", " << val2 << ") \n";

  int temp = vall;
  vall = val2;
  val2 = temp;

  ofil << "after swap(): vall " << vall
	<< " val2: " << val2 << "\n";
}

void bubble_sort(vector<int> &vec) {
  for (int ix = 0; ix < vec.size(); ++ix)
	for (int jx = ix + 1; jx < vec.size(); ++jx)
	  if (vec[ix] > vec[jx]){
		// 调试输出信息
		ofil << "about to call swap!"
		<< "ix: " << ix << " jx:" << jx << '\t'
		<< " swapping:" << vec[ix]
		<< " with " << vec[jx] << endl;
	    swap(vec[ix], vec[jx]);
		}
}

void pass_reference() {
  // test: by reference or by valud 
  int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2 };
  vector<int> vec(ia, ia + 8);

  cout << "vector before sort: ";
  display(&vec);
  bubble_sort(vec);

  cout << "vector after sort: ";
  display(&vec);
}





int main() {
  // ex2_1();

  //pass_reference();
   vector<int> fibon;
   fibon = fibon_elem_2(5);
   for (int ix = 0; ix < fibon.size(); ix++) {
	 cout << fibon[ix] << ' ';
   }

  system("pause");
}


bool fibon_elem(int pos, int &elem) {
  if (pos <= 0 || pos > 1024) {
	elem = 0;
	return false;
  }

  elem = 1;
  int n_2 = 1, n_1 = 1;

  for (int ix = 3; ix <= pos; ++ix) {
	elem = n_2 + n_1;
	n_2 = n_1;
	n_1 = elem;
  }

  return elem;
}

vector<int> fibon_elem_2(int size) {
  if (size <= 0 || size > 1024) {
	cerr << "Warning: fibon_seq(): "
	  << size << "not supported -- reas";
	  size = 8;
  }

  vector<int> elems(size);
  for (int ix = 0; ix < size; ++ix)
	if (ix == 0 || ix == 1)
	  elems[ix] = 1;
	else
	  elems[ix] = elems[ix - 1] + elems[ix - 2];
  
  return elems;
}