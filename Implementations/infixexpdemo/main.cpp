#include <iostream>
#include "stackds.h"

using namespace std;
using namespace algolib;

std::vector<char> GetPostfixFromInfix(std::string exp);
	bool is_leftPrecedenceGreaterOrEqual(const char &op1, const char &op2);
	char is_operator(const char &);
	char is_operand(const char &);

int main()
{
    std::string expressionQ("A+(B*C-(D/E^F)*G)*H");

	auto expressionP = GetPostfixFromInfix(expressionQ);

	for (auto& e : expressionP)
		cout << e << ' ';
    cout << endl;
}

	std::vector<char> GetPostfixFromInfix(std::string exp)
	{
		// Remove space
		exp.erase(std::remove_if(exp.begin(), exp.end(), [](char c) { return std::isspace(static_cast<unsigned char>(c)); }), exp.end());
		std::vector<char> PostfixP;

		Stack<char> STACK(exp.length());

		STACK.Push('(');
		exp.append(")");
		for (uint32 i = 0; i < exp.length() && !STACK.IsEmpty(); i++)
		{
			if (exp[i] == '(')
				STACK.Push('(');
			else if (is_operator(exp[i]))
			{
				while (!STACK.IsEmpty())
				{
					char opr = STACK.PopAndGetTop();
					if (is_operator(opr) && is_leftPrecedenceGreaterOrEqual(opr, exp[i]))
					{
						PostfixP.push_back(opr);
					}
					else
					{
						STACK.Push(opr);
						break;
					}
				}
				STACK.Push(exp[i]);
			}
			else if (is_operand(exp[i]))
			{
				PostfixP.push_back(exp[i]);
			}

			if (exp[i] == ')')
			{
				while (!STACK.IsEmpty())
				{
					char popped = STACK.PopAndGetTop();
					if (popped == '(')
					{
						break;
					}
					PostfixP.push_back(popped);
				}
			}
		}

		return PostfixP;
	}

	char is_operand(const char &val)
	{
		if (!is_operator(val) && val != ')' && val != '(')
			return val;
		else
			return '\0';
	}

	char is_operator(const char &val)
	{
		switch (val)
		{
		case '-':
		case '+':
		case '*':
		case '/':
		case '^':
			return val;
		default:
			return '\0';
		}
	}

	bool is_leftPrecedenceGreaterOrEqual(const char &op1, const char &op2)
	{
		static std::map<const char, int> Map = {{'^', 501}, {'/', 500}, {'*', 499}, {'+', 498}, {'-', 497}};

		if (Map[op1] >= Map[op2])
			return true;
		else
			return false;
	}