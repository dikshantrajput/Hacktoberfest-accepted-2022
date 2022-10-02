#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define ull unsigned long long int
#define pushb push_back
#define popb pop_back
#define INF 1e18+9
#define endl '\n'
#define Mod 1000000007
#define MAX 1000001

using namespace std;

// Pattern 1
void printPattern1(int n){
	for(int row=1;row<=n;row++){
		for(int col=1;col<=n;col++){
			cout << "*";
		}
		cout << endl;
	}
}

// Pattern 2
void printPattern2(int n){
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout << "*";
		}
		cout << endl;
	}
}

// Pattern 3
void printPattern3(int n){
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout << col;
		}
		cout << endl;
	}
}

// Pattern 4
void printPattern4(int n){
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout << row;
		}
		cout << endl;
	}
}

// Pattern 5
void printPattern5(int n){
	for(int row=1;row<=n;row++){
		for(int col=n-row+1;col>=1;col--){
			cout << "*";
		}
		cout << endl;
	}
}

// Pattern 6
void printPattern6(int n){
	int count = 1;
	for(int row=1;row<=n;row++){
		count = 1;
		for(int col=n-row+1;col>=1;col--){
			cout << count;
			count++;
		}
		cout << endl;
	}
}


// Pattern 7
void printPattern7(int n){
	for(int row=1;row<=n;row++){
			for(int space=1; space<=n-row; space++){
				cout<< " ";
			}
			for(int entry=1;entry<=2*row-1;entry++){
				cout << "*";
			}
			cout << endl;
	}
}

// Pattern 8
void printPattern8(int n){
for(int row=n;row>=1;row--){
			for(int space=1; space<=n-row; space++){
				cout<< " ";
			}
			for(int entry=1;entry<=2*row-1;entry++){
				cout << "*";
			}
			cout << endl;
	}	
}

// Pattern 9
void printPattern9(int n){
	for(int row=1;row<=n;row++){
			for(int space=1; space<=n-row; space++){
				cout<< " ";
			}
			for(int entry=1;entry<=2*row-1;entry++){
				cout << "*";
			}
			cout << endl;
		}

	for(int row=n;row>=1;row--){
			for(int space=1; space<=n-row; space++){
				cout<< " ";
			}
			for(int entry=1;entry<=2*row-1;entry++){
				cout << "*";
			}
			cout << endl;
		}
		
	}

// Pattern 10
void printPattern10(int n){
	for(int row=1;row<=n;row++){
			for(int entry=1;entry<=row;entry++){
				cout << "*";
			}
			cout << endl;
		}

	for(int row=n;row>=1;row--){
			for(int entry=1;entry<=row;entry++){
				cout << "*";
			}
			cout << endl;
		}
		
	}

// Pattern 11
void printPattern11(int n){
	for(int row=1;row<=n;row++){
			for(int col=1;col<=row;col++){
			((col-row)%2 == 0) ? cout <<"1 " : cout<<"0 ";
			}
			cout << endl;
		}
	}

// Pattern 12
void printPattern12(int n){
	for(int row=1;row<=n;row++){
		for(int col1=1;col1<=row;col1++){
			cout << col1;
		}
		
		for(int space=1; space<=2*n-(2*row); space++){
				cout<< " ";
		}

		for(int col2=row;col2>=1;col2--){
			cout << col2;
		}

		cout << endl;
	}
}

// Pattern 13
void printPattern13(int n){
	int count = 1;
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout << count << " ";
			count++;
		}
		cout << endl;
	}
}

// Pattern 14
void printPattern14(int n){
	char ch = 'A';
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout << ch;
			ch++;
		}
		cout << endl;
		ch = 'A';
	}
}

// Pattern 15
void printPattern15(int n){
	char ch = 'A';
	for(int row=1;row<=n;row++){
		for(int col=1;col<=n-row+1;col++){
			cout << ch;
			ch++;
		}
		cout << endl;
		ch = 'A';
	}
}

// Pattern 16
void printPattern16(int n){
	char ch = 'A';
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout << ch;
		}
		cout << endl;
		ch++;
	}
}

// Pattern 17
void printPattern17(int n){
	char ch = 'A';
	for(int row=1;row<=n;row++){
		for(int col=1;col<=row;col++){
			cout << ch;
		}
		cout << endl;
		ch++;
	}
}

// Pattern 18
void printPattern18(int n){
	char ch = 'A';
	for(int row=1;row<=n;row++){
			for(int space=1; space<=n-row; space++){
				cout<< " ";
			}
			for(int entry=1;entry<=row;entry++){
				cout << ch;
				ch++;
			}
			ch = 'A' + row - 2;
			for(int entry=1;entry<=row-1;entry++){
				cout << ch;
				ch--;
			}

			cout << endl;
			ch = 'A';
	}
}

// Pattern 19
void printPattern19(int n){
	char ch = 65+n-1;
	for(int row=1; row <=n; row++){
        for(int col=1; col  <= row; col++){
            cout << ch ;
            ch++;
        }
        ch = 65+n-1- row ;
        cout << "\n";
    }
}

// Pattern 20
void printPattern20(int n){

	//top half
	for(int row=0; row <=n-1; row++){
        
        for(int col1=n-row;col1>=1;col1--){
            cout << "*";
        }

        for(int space=1; space <= row*2; space++){
        	cout << " ";
        }

        for(int col2=n-row;col2>=1;col2--){
            cout << "*";
        }
        cout << "\n";
    }

    //bottom Half
    for(int row=n-1; row >=0; row--){
        
        for(int col1=n-row;col1>=1;col1--){
            cout << "*";
        }

        for(int space=1; space <= row*2; space++){
        	cout << " ";
        }

        for(int col2=n-row;col2>=1;col2--){
            cout << "*";
        }
        cout << "\n";
    }
}

// Pattern 21
void printPattern21(int n){

	//top Half
    for(int row=n-1; row >=0; row--){
        
        for(int col1=n-row;col1>=1;col1--){
            cout << "*";
        }

        for(int space=1; space <= row*2; space++){
        	cout << " ";
        }

        for(int col2=n-row;col2>=1;col2--){
            cout << "*";
        }
        cout << "\n";
    }

	//bottom half
	for(int row=1; row <=n-1; row++){
        
        for(int col1=n-row;col1>=1;col1--){
            cout << "*";
        }

        for(int space=1; space <= row*2; space++){
        	cout << " ";
        }

        for(int col2=n-row;col2>=1;col2--){
            cout << "*";
        }
        cout << "\n";
    }    
}

// Pattern 22
void printPattern22(int n){
	for(int row=1; row <=n; row++){

		//middle part
		if(row>1 && row<n){
        
        	cout << "*";

			for(int space=1; space  <= n-3; space++){
           		cout << " ";
			}

			cout << "*";
		}

		//top and bottom part
		else{
			for(int col3=1; col3  <= n-1; col3++){
           		cout << "*";
			}

		}
        cout << "\n";
	}
}

int main()
{
   int size=0,choice=0;
   cin >> size >> choice;
   switch(choice){
   	case 1: printPattern1(size);
   	break;
   	case 2: printPattern2(size);
   	break;
   	case 3: printPattern3(size);
   	break;
   	case 4: printPattern4(size);
   	break;
   	case 5: printPattern5(size);
   	break;
   	case 6: printPattern6(size);
   	break;
   	case 7: printPattern7(size);
   	break;
   	case 8: printPattern8(size);
   	break;
   	case 9: printPattern9(size);
   	break;
   	case 10: printPattern10(size);
   	break;
   	case 11: printPattern11(size);
   	break;
   	case 12: printPattern12(size);
   	break;
   	case 13: printPattern13(size);
   	break;
   	case 14: printPattern14(size);
   	break;
   	case 15: printPattern15(size);
   	break;
   	case 16: printPattern16(size);
   	break;
   	case 17: printPattern17(size);
   	break;
   	case 18: printPattern18(size);
   	break;
   	case 19: printPattern19(size);
   	break;
   	case 20: printPattern20(size);
   	break;
   	case 21: printPattern21(size);
   	break;
   	case 22: printPattern22(size);
   	break;
   }
   return 0;
}
