#include <iostream>
#include <fstream>

struct Coord
{
	int line;
	int col;
};


int check(char a[6][6]){
	int i, j, ok1 = 0;
	for(i = 0; i<6; i+=2)
	{
		for(j = 0; j < 6; j+=2){
			if(a[i][j] == '_'){
				ok1 = 1;
			}

			if(i == j && i == 0){
				if(a[i][j] == a[i+2][j+2] || a[i][j]==a[i-2][j-2]){
					
					if(a[i][j]==a[i+4][j+4] || a[i][j]==a[i+4][j+4]){
						if(a[i][j] == 'X' || a[i][j] == '0'){
						return 1;
					}
					}
				}
			}
			if(i+j == 4){
			
					if(a[i][j] == a[i+2][j-2] || a[i][j]==a[i-2][j+2]){
						
					if(a[i][j] == a[i+4][j-4] || a[i][j]==a[i-4][j+4]){

						if(a[i][j] == 'X' || a[i][j] == '0'){
						return 1;
					}
					}
				}
			}

		if(a[i][j] == a[i][j+2] || a[i][j]==a[i][j+2]){
					if(a[i][j]==a[i][j+4] || a[i][j]==a[i][j-4]){
						if(a[i][j] == 'X' || a[i][j] == '0'){
						return 1;
					}

					}
				}

				if(a[i][j] == a[i+2][j] || a[i][j] == a[i-2][j]){
					if(a[i][j]==a[i+4][j] || a[i][j]==a[i-4][j]){
						if(a[i][j] == 'X' || a[i][j] == '0'){
						return 1;
					}

					}
				}
			
	
	}
	}
	if(ok1 == 0){
		return 2;
	}
}

void danger(char a[6][6], Coord &p, char &t){
	int i, j;

	for(i=0; i<6; i+=2){
		for(j=0; j<6; j+=2){

			if((a[i-2][j] == a[i+2][j]) && a[i-2][j] == t){
				if(a[i][j] == '_' ){
					p.line = i;
					p.col = j;
				}
			}
			if(a[i][j] == a[i+2][j] || a[i][j] == a[i-2][j]){

				if(a[i][j] == t){

					if(a[i+4][j] == '_'){

				p.line = i+4;
				p.col = j;

			}
			else{
				if(a[i-2][j] == '_'){
					p.line = i-2;
					p.col = j;
				}

			}
			}
		}

			if((a[i][j-2] == a[i][j+2]) && a[i][j-2] == t) {
				if(a[i][j] == '_'){
					p.line = i;
					p.col = j;
				}
			}

				if(a[i][j] == a[i][j+2] || a[i][j] == a[i][j-2]){
				if(a[i][j] == t){
					if(a[i][j+4] == '_'){
				p.line = i;
				p.col = j+4;
			}
			else{
				if(a[i][j-2] == '_'){
					p.line = i;
					p.col = j-2;
				}

			}
			}
		}

		if((a[i-2][j-2] == a[i+2][j+2]) && a[i-2][j-2] == t){
				if(a[i][j] == '_'){
					p.line = i;
					p.col = j;
				}
			}

				if(a[i][j] == a[i+2][j+2] || a[i][j] == a[i-2][j-2]){
				if(a[i][j] == t){
					if(a[i+4][j+4] == '_'){
				p.line = i+4;
				p.col = j+4;
			}
			else{
				if(a[i-2][j-2] == '_'){
					p.line = i-2;
					p.col = j-2;
				}

			}
			}
		}

		if((a[i+2][j-2] == a[i-2][j+2]) && a[i+2][j-2] == t){
				if(a[i][j] == '_'){
					p.line = i;
					p.col = j;
				}
			}



				if(a[i][j] == a[i+2][j-2] || a[i][j] == a[i-2][j+2]){
				if(a[i][j] == t){
					if(a[i+4][j-4] == '_'){
				p.line = i+4;
				p.col = j-4;
			}
			else{
				if(a[i-2][j+2] == '_'){
					p.line = i-2;
					p.col = j+2;
				}

			}
			}
		}

		
		}
	}

}


void print (char a[6][6]) {
	int i, j;
	for(i = 0; i<6; i+=2){
		for(j =0 ; j< 6; j+=2){
			
			std::cout<<a[i][j]<<" ";
		
		}
		std::cout<<std::endl;
	

}
}

int fill (char a[6][6]) {
	int i, j;
	char x = 'X';
	char o = '0';

	Coord p;
	p.line = -1;
	p.col = -1;
	danger(a, p, o);

	if(p.line != -1){


		a[p.line][p.col] = '0';
		return 1;
	}

		danger(a, p, x);
	
	if(p.line != -1){


		a[p.line][p.col] = '0';
		return 1;
	}
	
	for(i=0; i<6; i+=2){
		for(j=0; j<6; j+=2){

			if((a[i][j] == '_') && ((a[i][j-2] == '0' && a[i][j+2] == '_')
			 || (a[i][j+2]=='0' && a[i][j-2] == '_') || 
				(a[i-2][j]=='0' && a[i+2][j] == '_')
			 || (a[i+2][j]=='0' && a[i-2][j] == '_')
			  || (a[i-2][j-2]=='0' && a[i+2][j+2] == '_')))
				{

				a[i][j] = '0';
				return 1;
				
			}
			
		
		}
	}
	for(i=0; i<6; i+=2){
		for(j=0; j<6; j+=2){

			if((a[i][j] == '_') && (a[i][j-2] == '0' || a[i][j+2]=='0'
			 || a[i-2][j]=='0' || a[i+2][j]=='0' || a[i-2][j-2]=='0')){
				a[i][j] = '0';
				return 1;
				
			}
				if(a[i][j] == '_'){

				a[i][j] = '0';
				return 1;
				
			}
			
		
		}
	}


}

int main(){

char a[6][6];

int i, j, lx, cx, ok = 0;
Coord p;


for(i = 0; i < 6; i+=2){
	for(j = 0; j<6; j+=2){
		a[i][j] = '_';
	}
}
for(i = 1; i < 6; i+=2){
	for(j = 0; j<6; j+=2){
		a[i][j] = ' ';
	}
}

int start;

	std::cout<<"Insert 1 if you want to start, 0 if you don't: ";
	std::cin>>start;

while(check(a) != 1){

	if(start == 1){
		std::cout<<"Insert coords for x: ";
	std::cin>>lx>>cx;
	


	while(a[2*(lx-1)][2*(cx-1)] != '_'){

		std::cout<<"WRONG COORDS!"<<std::endl;

		std::cout<<"Insert coords x: ";
	std::cin>>lx>>cx;
	}
	
	 a[2*(lx-1)][2*(cx-1)] = 'X';
	 
	

	 if(check(a) == 1 || check(a) == 2){

	 	std::cout<<"GAME OVER"<<std::endl;
	 	print(a);
	 	return 0;
	 }
	}
	start = 1;

	if(a[2][2] == '_'){
		a[2][2] = '0';
	}
	else{
	
	 fill(a);
	}

	print(a);
	start = 1;

	if(check(a) == 1 || check(a) == 2){

	 	std::cout<<"GAME OVER"<<std::endl;
	 	print(a);
	 	return 0;
	 }
	
	

}


	return 0;
}