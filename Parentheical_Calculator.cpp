/*

  
   Language : C++
   Compiler used : MingW TDM-GCC 4.9.2


                                       */



#include <iostream>
#include <sstream>
#include <cmath>
#include <string.h>





using namespace std;





void tellpos (string a , int &a_ )  {
	
	
	if (a == "+" || a == "-") {
		
		a_ = 10;
		
	}
	
	
	
		
	
		if (a == "*" || a=="/") {
			
		a_ =20;
		
	}
	
		if (a == "^") {
		
		a_=30;
		
	}
	
	
	
	
}














int main ()  {
	
	
	
	cout << "Enter the expression with round-brackets, For example (g^((a+b)*(c+d))) :  ";

 
 string h = "(1+(23*34-(45/56^62)*73)*8)";
 
 
 
 cin >> h;
 	
	string LogicalExp[150];
	
	int location=-1;
	
	string plus = "";
	
	
	
	
	
	for (int y =0 ; y <= h.length() ; y++)  {
		
		
		
		if ( h[y] == '+' || h[y] == '-' || h[y] == '*' || h[y] == '/' || h[y] == '^'  || h[y] == '('  || h[y] == ')')  {
			
			++location;
			
			LogicalExp[location] = plus;
			
			plus="";
			
			++location;
			
			LogicalExp[location] = h[y];
			
			
		}
		
		
		else {
			
			plus += h[y];
			
							
		}
		
		
		
		
	}
	
		++location;
			
			LogicalExp[location] = plus;
			


	

int storeascii =0;


int curr=0;

	int stack_length;




 int lastseen;
  
  string final_expression;
  
  int pos=0;
  
  string stack[100];
  
  string expression[100];
  
    int pos_for_ep=0;
	
	
	
	
	for (int go=0 ; go <= location; go++ )  {
		
		

		if (LogicalExp[go] == ")") {
			
	
			for ( int stack_length = pos;  stack[stack_length] != "(" ; --stack_length) {
				
				
			++pos_for_ep;
				
						
			expression[pos_for_ep] = stack[stack_length];
			
	

				
	
			--pos;
			}  
			
			
				--pos;
			
				
			continue;
			
		}
		
		
		
		if (LogicalExp[go] == "(") {
			
			++pos;
			
		 stack[pos] = "(";
			
	
			
	continue;
		}
		
		
	
		
		if (LogicalExp[go] != "+" && LogicalExp[go] != "-" && LogicalExp[go] != "*" && LogicalExp[go] != "/" && LogicalExp[go] != "^" && LogicalExp[go] != ")" ) {
			
		
			++pos_for_ep;
			
			expression[pos_for_ep] = LogicalExp[go];
			
		}
		
		
		
		if (LogicalExp[go] == "+" || LogicalExp[go] == "-" || LogicalExp[go] == "*" || LogicalExp[go] == "/" || LogicalExp[go] == "^") {
			
			
			
		if (stack[pos] == "+" || stack[pos] == "-"  || stack[pos] == "*" || stack[pos] ==  "/" || stack[pos] == "^")   {
			
			
			tellpos(stack[pos] , storeascii);
			
			tellpos(LogicalExp[go] , curr);
			
			
			
			
			
	if ( curr - storeascii > 0 ) {
	
	++pos;
 
stack[pos] =  LogicalExp[go];


	
}
			
			
			

if (curr - storeascii <= 0) {
	
 
 	++pos_for_ep;
			
	expression[pos_for_ep] = stack[pos];
 
 
 stack[pos] = LogicalExp[go];


	
}

		

			
		}
		
	
		else {
			++pos;
			
			stack[pos] =  LogicalExp[go];
			
			
		}
	
		
		}
		
	



 
 	
 }
 


	
	
	int stac[100];
	int count=0;
	
	while (count < 100) {
		
		stac[count] = 0;
		
		count++;
		
	}
	
	
	int locatio=-1;
	
	int elem=0;
	int value=0;
	int valuep=0;
	
	
	
	for ( int a = 0 ;   a <= location  ; a++  )  {
		
		
		if (expression[a] == "") {
 	continue;
 		
	 }
 	
	
		
		if (expression[a] == "+" || expression[a] == "-" || expression[a] == "*" || expression[a] == "/" || expression[a] == "^"  ) {
			
			
			value = stac[locatio];
			valuep = stac[locatio-1];
			
	
		
		 if (expression[a] == "+") {
		 	
		stac[locatio-1] = valuep + value;
		 	
		 	
		 	
		 }
			
			
		  if (expression[a] == "-") {
		 	
		 	stac[locatio-1] = valuep - value;
		 	
		 }
			
			
		 if (expression[a] == "*") {
		 	
		 	stac[locatio-1] = valuep * value;
		 	
		 }
			
			
			 if (expression[a] == "/") {
		 	
		 	stac[locatio-1] = valuep / value;
		 	
		 }
			
			
			 if (expression[a] == "^") {
		 	
		 	stac[locatio-1] = pow(valuep,value);
		 	
		 }
					
			
			
			--locatio;
			
			
			
		}
		
		
		
		else {
			
			stringstream toint(expression[a]);
			
			toint >> elem;
			
			
			++locatio;
			
			stac[locatio] = elem;
			
			
			
		}
		
		
		
		
	}
	
	
	
	cout << "\n\nFinal Answer : " << stac[0];
	
	system("PAUSE >NUL");
	
	
	

	
	
}
