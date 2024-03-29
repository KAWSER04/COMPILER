#include <bits/stdc++.h> 
using namespace std; 
int isOperator(char input) 
{ 
	switch (input) { 
	case '+': 
		return 1; 
	case '-': 
		return 1; 
	case '*': 
		return 1; 
	case '^': 
		return 1; 
	case '%': 
		return 1; 
	case '/': 
		return 1; 
	case '(': 
		return 1; 
	} 
	return 0; 
} 

// to check if the input character is an operand 
int isOperand(char input) 
{ 
	if (input >= 65 && input <= 90 
		|| input >= 97 && input <= 122) 
		return 1; 
	return 0; 
} 
int inPrec(char input) 
{ 
	switch (input) { 
	case '+': 
	case '-': 
		return 2; 
	case '*': 
	case '%': 
	case '/': 
		return 4; 
	case '^': 
		return 5; 
	case '(': 
		return 0; 
	} 
} 

int outPrec(char input) 
{ 
	switch (input) { 
	case '+': 
	case '-': 
		return 1; 
	case '*': 
	case '%': 
	case '/': 
		return 3; 
	case '^': 
		return 6; 
	case '(': 
		return 100; 
	} 
} 

// function to convert infix to postfix 
void inToPost(char* input) 
{ 
	stack<char> s; 

	// while input is not NULL iterate 
	int i = 0; 
	while (input[i] != '\0') { 

		// if character an operand 
		if (isOperand(input[i])) { 
			printf("%c", input[i]); 
		} 

		// if input is an operator, push 
		else if (isOperator(input[i])) { 
			if (s.empty() 
				|| outPrec(input[i]) > inPrec(s.top())) 
				s.push(input[i]); 
			else { 
				while (!s.empty() 
					&& outPrec(input[i]) < inPrec(s.top())) { 
					printf("%c", s.top()); 
					s.pop(); 
				} 
				s.push(input[i]); 
			} 
		} 

		// condition for opening bracket 
		else if (input[i] == ')') { 
			while (s.top() != '(') { 
				printf("%c", s.top()); 
				s.pop(); 

				// if opening bracket not present 
				if (s.empty()) { 
					printf("Wrong input\n"); 
					exit(1); 
				} 
			} 

			// pop the opening bracket. 
			s.pop(); 
		} 
		i++; 
	} 

	// pop the remaining operators 
	while (!s.empty()) { 
		if (s.top() == '(') { 
			printf("\n Wrong input\n"); 
			exit(1); 
		} 
		printf("%c", s.top()); 
		s.pop(); 
	} 
} 

// Driver code 
int main() 
{ 
	char input[] = "(A-B)*(D/E)"; 
	inToPost(input); 
	return 0; 
} 

