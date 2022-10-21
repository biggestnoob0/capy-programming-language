#include "SyntaxParser.h"

vector<Identifier *> SyntaxParser::ParseAllIdentifiers(const vector<IdentifierAttributes> &linesInFile)
{
	DataTypeMap typeMap{};
	vector<Identifier*> allIdentifiers{};
	for (size_t lineIndex = 0; lineIndex < linesInFile.size(); lineIndex++)
	{
		vector<string> currentIdentifierExpressions{};
		vector<AllTypes> currentIdentifierExpressionTypes{};
		IdentifierAttributes line = linesInFile.at(lineIndex);
		int size = line.attributes.size();
		if (line.initialised)
		{
			// non zero pos for loop below token iterator loop
			int equalsPos{1};
			for (int tokenIterator = size - 1; tokenIterator >= 0; tokenIterator--)
			{
				string token = line.attributes.at(tokenIterator);
				char firstChar = token.at(0);
				AllTypes dataType{};
				if (firstChar == '=' && token.size() == 1)
				{
					equalsPos = tokenIterator;
					break;
				}
				if (firstChar == '!')
				{
					firstChar = token.at(1);
				}
				if (std::isdigit(firstChar) || firstChar == '-' && token.size() > 1)
				{
					int dots = std::count(token.begin(), token.end(), '.');
					dataType = NumberSyntaxChecker(token, dots, lineIndex);
					
					currentIdentifierExpressions.push_back(token);
					currentIdentifierExpressionTypes.push_back(dataType);
				}
				else
				{
					// else if non-numerical
					switch (firstChar)
					{
					case '\'':
						dataType = CharSyntaxChecker(token, lineIndex);

						currentIdentifierExpressions.push_back(token);
						currentIdentifierExpressionTypes.push_back(dataType);

						break;
					case '\"':
						dataType = StringSyntaxChecker(token, lineIndex);

						currentIdentifierExpressions.push_back(token);
						currentIdentifierExpressionTypes.push_back(dataType);

						break;
					case 't':
						dataType = BoolTrueSyntaxChecker(token, lineIndex);

						currentIdentifierExpressions.push_back(token);
						currentIdentifierExpressionTypes.push_back(dataType);

						break;
					case 'f':
						dataType = BoolFalseSyntaxChecker(token, lineIndex);

						currentIdentifierExpressions.push_back(token);
						currentIdentifierExpressionTypes.push_back(dataType);

						break;
					case '+':
						if (token.size() == 1)
						{
							currentIdentifierExpressions.push_back(token);
							currentIdentifierExpressionTypes.push_back(Addition);
						}
						break;
					case '-':
						if (token.size() == 1)
						{
							currentIdentifierExpressions.push_back(token);
							currentIdentifierExpressionTypes.push_back(Subtraction);
						}
						break;
					case '*':
						if (token.size() == 1)
						{
							currentIdentifierExpressions.push_back(token);
							currentIdentifierExpressionTypes.push_back(Multiplication);
						}
						break;
					case '/':
						if (token.size() == 1)
						{
							currentIdentifierExpressions.push_back(token);
							currentIdentifierExpressionTypes.push_back(Division);
						}
						break;

					case '%':
						if (token.size() == 1)
						{
							currentIdentifierExpressions.push_back(token);
							currentIdentifierExpressionTypes.push_back(Modulus);
						}
						break;
					}

					if (token == "&&")
					{
						currentIdentifierExpressions.push_back(token);
						currentIdentifierExpressionTypes.push_back(AND);
					}
					else if (token == "||")
					{
						currentIdentifierExpressions.push_back(token);
						currentIdentifierExpressionTypes.push_back(OR);
					}
				}
			}
		}
		AllTypes dataType{};
		string name{};
		string token = line.attributes.at(0);
		if (typeMap.typesMapped.find(token) != typeMap.typesMapped.end())
		{
			dataType = typeMap.typesMapped.at(token);

			token = line.attributes.at(1);
			if (std::isalpha(token.at(0)))
			{
				name = token;
			}
			else
			{
				Error error{"The first character in a variable name must be an alpha character", (int)lineIndex, "SYNTAX-ERROR"};
			}
		}
		else if (token == "usign")
		{
			token = line.attributes.at(1);
			if (typeMap.typesMapped.find("usign " + token) != typeMap.typesMapped.end())
			{
				dataType = typeMap.typesMapped.at("usign " + token);

				token = line.attributes.at(2);
				if (std::isalpha(token.at(0)))
				{
					name = token;
				}
				else
				{
					Error error{"The first character in a variable name must be an alpha character", (int)lineIndex, "SYNTAX-ERROR"};
				}
			}
			else
			{
				Error error{"Invalid type", (int)lineIndex, "SYNTAX-ERROR"};
			}
		}
		else
		{
			Error error{"Invalid or missing type/keyword", (int)lineIndex, "SYNTAX-ERROR"};
		}
		allIdentifiers.push_back(new Identifier(currentIdentifierExpressions, currentIdentifierExpressionTypes, name, dataType, (int)lineIndex));
	}
	return allIdentifiers;
}
AllTypes SyntaxParser::CharSyntaxChecker(string &token, size_t &lineIndex)
{
	// if only 1 character
	if (token.size() == 3)
	{
		return Character;
	}
	else
	{
		// if null character
		if (token.size() == 2 && token == "\'\'")
		{
			return Character;
		}
		else
		{
			Error error{"Expected a single character", (int)lineIndex, "SYNTAX-ERROR"};
			return ERROR_TYPE;
		}
	}
}

AllTypes SyntaxParser::StringSyntaxChecker(string &token, size_t &lineIndex)
{
	// if 1 or more characters and quote at end
	if (token.size() >= 3 && token.at(token.size() - 1) == '\"')
	{
		return String;
	}
	else
	{
		Error error{"Expected a quote mark before the end of line", (int)lineIndex, "SYNTAX-ERROR"};
		return ERROR_TYPE;
	}
}

AllTypes SyntaxParser::NumberSyntaxChecker(string &token, int &dots, size_t &lineIndex)
{
	for (size_t i = 0; i < token.size(); i++)
	{
		if (!std::isdigit(token.at(i)))
		{
			if (token.at(i) == '.')
			{
				continue;
			}
			return ERROR_TYPE;
		}
	}
	if (dots == 0)
	{
		if (token.size() > 9)
		{
			return Int64;
		}
		else
		{
			return Integer;
		}
	}
	else if (dots == 1)
	{
		return DoubleNumber;
	}
	else
	{
		Error error{"More than 1 decimal point", (int)lineIndex, "SYNTAX-ERROR"};
		return ERROR_TYPE;
	}
}

AllTypes SyntaxParser::BoolTrueSyntaxChecker(string &token, size_t &lineIndex)
{
	if (token == "true" || token == "!true")
	{
		return Boolean;
	}
	Error error{"No quote marks specified", (int)lineIndex, "SYNTAX-ERROR"};
	return ERROR_TYPE;
}

AllTypes SyntaxParser::BoolFalseSyntaxChecker(string &token, size_t &lineIndex)
{
	if (token == "false" || token == "!false")
	{
		return Boolean;
	}
	Error error{"No quote marks specified", (int)lineIndex, "SYNTAX-ERROR"};
	return ERROR_TYPE;
}
