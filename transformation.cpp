#include <iostream>
#include <stack>
#include <algorithm>
#include<cmath>
using namespace std;


bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    return true;
    }
    else {
    return false;
    }
}

//Function to find precedence of operators.
int pre(char c)
{
	if(c == '^')// exponent operator, highest precedence//
	{
		return(3);
	}
	else if(c == '*' || c == '/')
	{
		return(2);
	}
	else if(c == '+' || c == '-')  // lowest precedence //
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int isOperator2(char ch) {
   if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
      return 1;    //character is an operator
   return -1;   //not an operator
}
float scanNum(char ch) {
   int value;
   value = ch;
   return float(value-'0');   //return float from character
}
int isOperand(char ch) {
   if(ch >= '0' && ch <= '9')
      return 1;   //character is an operand
   return -1;   //not an operand
}
float operation(int a, int b, char op) {
   //Perform operation
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a); //find b^a
}



//infixtopostfix
string infixtopostfix(string s){
   //empty stack
   stack<int> a;
   //empty expression
   string t="";
   //iterating input string
   for(int i=0;i<s.size();++i){
       //operand,must be an english letter and it must be appended

       if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) t+=s[i];

       else if(s[i]=='(') a.push(s[i]);

       else if(s[i]==')') {
               //popping off till '(' is found or stack is empty
               while(!a.empty()&&a.top()!='(') { t+=a.top();a.pop();}
               //if '(' is not found then thereis some error
               if(a.empty()) return "Parenthesis are not matching";
               else a.pop();
       }
       //operand case
       else
       {
       while(!a.empty()&&pre(a.top())>=pre(s[i])) {t+=a.top();a.pop();}
       a.push(s[i]);
       }

   }
   //stack will have some operators left in it, which needs to be appended
   while(!a.empty()) {t+=a.top();a.pop();}
return t;
}


//infixtoprefix
string infixtoprefix(stack<char> s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
    if (infix[i] == '(') {
        infix[i] = ')';
    }
    else if (infix[i] == ')') {
        infix[i] = '(';
    }
    }
    for (int i = 0; i < infix.length(); i++) {
    if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
        prefix += infix[i];
    }
    else if (infix[i] == '(') {
        s.push(infix[i]);
    }
    else if (infix[i] == ')') {
        while ((s.top() != '(') && (!s.empty())) {
        prefix += s.top();
        s.pop();
        }

        if (s.top() == '(') {
        s.pop();
        }
    }
    else if (isOperator(infix[i])) {
        if (s.empty()) {
        s.push(infix[i]);
        }
    else {
        if (pre(infix[i]) > pre(s.top())) {
        s.push(infix[i]);
        }
        else if ((pre(infix[i]) == pre(s.top()))
        && (infix[i] == '^')) {
        while ((pre(infix[i]) == pre(s.top()))
        && (infix[i] == '^')) {
        prefix += s.top();
        s.pop();
        }
        s.push(infix[i]);
        }
        else if (pre(infix[i]) == pre(s.top())) {
            s.push(infix[i]);
        }
        else {
            while ((!s.empty()) && (pre(infix[i]) < pre(s.top()))) {
                prefix += s.top();
                s.pop();
                }
                    s.push(infix[i]);
            }
        }
    }
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

//postevaluation
float postfixEval(string postfix) {
   int a, b;
   stack<float> stk;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++) {
      //read elements and perform postfix evaluation
      if(isOperator2(*it) != -1) {
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));
      }else if(isOperand(*it) > 0) {
         stk.push(scanNum(*it));
      }
   }
   return stk.top();
}

int main(){

string post;
stack<char>stack;
string infix, prefix;
string s;
int choice;
bool ProgramOn = true;
while (ProgramOn != false){
cout << "\n\n**********************************************\n";
cout << " WELCOME TO TRANSFORMATION EXPRESSION PROGRAM\n\n";
cout << " 1 - INFIX TO POSTFIX Expression\n";
cout << " 2 - INFIX TO PREFIX Eexpression\n";
cout << " 3 - POSTFIX Evaluation\n";
cout << " 4 - Exit.\n";
cout << " \nEnter your choice : ";

cin >> choice;

switch (choice)
{
case 1:

cout<<"\nEnter a INFIX Expression to convert POSTFIX : ";
cin>>s;
cout<<"\nThe POSTFIX is : ";
cout<<infixtopostfix(s)<<endl;
return 0;

break;
case 2:
cout<<"\nEnter a INFIX Expression to convert PREFIX : ";
cin>>infix;

prefix = infixtoprefix(stack, infix);
cout<<"\nThe PREFIX is : ";
cout<<prefix<<endl;
return 0;

break;
case 3:

cout<<"Enter operand and operator for POSTFIX Evaluation : ";
cin>>post;
cout << "\nThe result is: "<<postfixEval(post);
return 0;

break;


case 4:
cout << "\nEnd of Program.\n\n";

cout << "**************************************" << endl;
        cout << "**************************************" << endl;
        cout << "*******    T H A N K  Y O U    *******" << endl;
        cout << "*******    F O R  U S I N G    *******" << endl;
        cout << "******* T H I S  P R O G R A M *******" << endl;
        cout << "**************************************" << endl;
        cout << "**************************************" << endl;
ProgramOn = false;
break;


default:
cout << "Not a Valid Choice. \n";
cout << "Choose again.\n";
cin >> choice;
break;
}

}
return 0;
}
