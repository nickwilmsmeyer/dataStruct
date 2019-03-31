//Nick Wilmsmeyer & Brandon Olson
//Data Structures Project 1
//Infix Expression Parser

#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Evaluator {
public:
	void build();
	void reorder();
	int operate(char op);
	void show();
	void showOp();
	stack <int> valStack;
	stack <char> opStack;
};
void Evaluator::build() {
	
}


int Evaluator::operate(char op) { //after building stack, this will execute operation to give user the desired output while draining the stack
	if (opStack.empty())
		throw ("Stack is empty");
	int rhs = opStack.top();
	opStack.pop();
	if (opStack.empty())
		throw ("Stack is empty");
	int lhs = opStack.top();
	opStack.pop();
	int result = 0;
	bool bRes;
	switch (op) {
	case '!': bRes = false;
	case '*': result = lhs * rhs;
		break;
	case '/': result = lhs / rhs;
		break;
	case '%': result = lhs % rhs;
		break;
	case '+': result = lhs + rhs;
		break;
	case '-': result = lhs - rhs;
		break;
	
}

//prints valStack when it is not empty by printing top element of stack then popping element, until it is empty
void Evaluator::show() {
	while (!valStack.empty()) {
		cout << valStack.top();
		valStack.pop();
	}
}

//prints opStack when it is not empty by printing top element of stack then popping element, until it is empty
void Evaluator::showOp() {
	while (!opStack.empty()) {
		cout << opStack.top();
		opStack.pop();
	}
}

void Evaluator::build() {
	int pre = 0;
	string fin;
	string str = "3^2+2*4";
	
	for (int i = 0, i < str.length(); i++) {
		valStack.push(str.substr(i,1));
	}
}
//build function to build stack
//then read stack
//reorder stack

int main() {
	Evaluator eval;
	int result = eval.eval("!!!3+2");
	return 0;
}

int evalPostfix(string expr)
{
	// stack is holding input numbers
	stack<int> stack;

	for (string::iterator it = expr.begin(); it != expr.end(); it++) {
		char letter = *it;
		// simply push digits to stack
		if (isdigit(letter)) {
			// char -> int conversion
			stack.push(letter - '0');
		}
		else {
			// doing actual operations
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			int result;
			switch (letter) {
			case '+': result = b + a; break;
			case '-': result = b - a; break;
			case '*': result = b * a; break;
			case '/': result = b / a; break;
			case '%': result = b % a; break;
			case '--': result = b - 1; break;
			case '++': result = b + 1; break;
			case '^': result = (int)pow((double)b, a); break;
			case '||':
				if ((a == 1) || (b == 1))
					result = 1;
				else
					result = 0;
				break;
			case '&&':
				if ((a == 1) && (b == 1))
					result = 1;
				else
					result = 0;
				break;
			case '==':
				if (a == b)
					result = 1;
				else
					result = 0;
				break;
			case '!=':
				if (a != b)
					result = 1;
				else
					result = 0;
				break;
			case '<':
				if (b < a)
					result = 1;
				else
					result = 0;
				break;
			case '>':
				if (b > a)
					result = 1;
				else
					result = 0;
				break;
			case '<=':
				if (b <= a)
					result = 1;
				else
					result = 0;
				break;
			case '>=':
				if (b >= a)
					result = 1;
				else
					result = 0;
				break;
			case '!': b = 0;
			}
			stack.push(result);
		}
	}
	return stack.top();
}


int precedence(char op)
{
	switch (op) {
	case '| |': return 1;
	case '& &': return 2;
	case '==': return 3;
	case '!=': return 3;
	case '>': return 4;
	case '<': return 4;
	case '>=': return 4;
	case '<=': return 4;
	case '+': return 5;
	case '-': return 5;
	case '*': return 6;
	case '/': return 6;
	case '%': return 6;
	case '^': return 7;
	case '--': return 8;
	case '++': return 8;
	case '!': return 8;

	}
	return 0;
}
