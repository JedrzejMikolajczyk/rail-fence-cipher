#include <iostream>
#include <string>

std::string cipher(std::string text, int height, bool reversed)
{
    if (height == 1)
		return text;
    if(height < 1)
    {
        std::cout<<"Invalid fence's height"<<std::endl;
        return "0";
    }

	std::string result;
	std::string* railFence = new std::string[height];//creating a string for each row
	int k = 0, step = 1;
	for (int i = 0; i < text.size(); i++)
	{
		railFence[k] += text[i];
		k += step;
		if (k == height -1 || k == 0)//when iterator reaches the highest or lowest row it goes back
			step = step * (-1);
	}
	if(reversed)
		for (int i = 0; i < height; i++)
		{
			result += railFence[height - 1 - i];//starts reading from the bottom
		}
	else
		for (int i = 0; i < height; i++)
		{
			result += railFence[i];//starts reading from the top
		}
	return result;
}

int main()
{
	std::string text, result;
	int h;
	bool reversed = 0;
	std::cout << "Enter a text you want to encrypt\n";
	getline(std::cin, text);
	std::cout << "Enter the fence's height\n";
	std::cin >> h;
	std::cout << "Type in 0 if you want the zig-zag to start from the top or 1 if you want it to start from the bottom\n";
	std::cin >> reversed;
	std::cout << cipher(text, h, reversed);
	return 0;
}

