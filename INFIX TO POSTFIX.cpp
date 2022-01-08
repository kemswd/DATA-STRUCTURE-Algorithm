#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
void fast(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}
// Function to convert Infix expression to postfix
string infixToPostfix(string expression);
// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char op1, char op2);
// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool IsOperand(char c);
int main()
{
	fast();
    string expression;
	cout << "Enter Infix Expression \n";
	getline(cin, expression);
	string postfix = infixToPostfix(expression);
	cout << "Output = " << postfix << "\n";

return 0;
}
string infixToPostfix(string expression){
    stack<char> s;
    string postfix="";
    for(int i=0;i<expression.length();i++){
        if (expression[i] == ' ' || expression[i] == ',') continue;
        else if(IsOperator(expression[i])){
            while(!s.empty()&& s.top()!='('&& HasHigherPrecedence(s.top(),expression[i])){
                    postfix+=s.top();
                    s.pop();
                  }
                  s.push(expression[i]);
        }
        else if (IsOperand(expression[i])){
            postfix+=expression[i];
        }
        else if(expression[i]=='('){
             s.push(expression[i]);
        }
        else if(expression[i]==')'){
            while(!s.empty()&& s.top()!='('){
                     postfix+=s.top();
                     s.pop();
                  }
                  s.pop();
            }
    }
    while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}

	return postfix;
}
bool IsOperand(char c){
    if(c>='0'&&c<='9')      return true;
    if(c>= 'a'&& c<= 'z')   return true;
    if(c>= 'A'&& c<= 'Z')   return true;
    return false;
}
bool IsOperator(char C){
   if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}
int HasHigherPrecedence(char op1, char op2){
    int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

    if(op1Weight==op2Weight)    return true;
    return op1Weight > op2Weight ? true : false;
}
