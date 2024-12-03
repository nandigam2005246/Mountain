/*
https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/?envType=daily-question&envId=2024-12-02
*/

#include <sstream>
#include <string>
#include <iostream>

class Solution {
public:
	int isPrefixOfWord(std::string sentence, std::string searchWord) {

		std::stringstream s(sentence);
		std::string word;
		int wordCount = 0;

		while (s >> word)
		{
			int charCount = 0;
			int j = 0;

			if (word.length() >= searchWord.length())
			{
				for (int i = 0; word[i] != '\0'; i++)
				{
					if (searchWord[j] == word[i])
					{
						charCount++;
					}
					else
					{
						break;
					}
					j++;
				}
				wordCount++;
			}

			else
			{
				wordCount++;
				continue;
			}

			if (charCount == searchWord.length())
			{
				return wordCount;
			}
		}
		return -1;
	}
};

int main()
{
	std::string sentence = "i love eating burger";
	std::string searchWord = "burg";
	Solution obj;
	std::cout << obj.isPrefixOfWord(sentence, searchWord) << std::endl;

	return 0;
}