/*
    00110001	31	1
    87654321
    00650001

    6x5x1=31

    01000001 65      A
    12345678
*/

#include <iostream>
#include <vector>

struct Data
{
    std::vector<int> Binary;

    std::vector<std::string> TextV;

    Data()
    {
        Binary.push_back(31); TextV.push_back("1");
    }

    std::string BtT(int v)
    {
        std::string Text;

        std::cout << "ccc";

        for(int i = 0; i < Binary.size(); i++)
        {
            if(v == Binary[i]) Text = TextV[i];
            else std::cout << "false";
        }

        return Text;
    }
};

int multiple(std::vector<int> n)
{
    int g = 1;
    int h;
    int sum;


    for(int i = 0; i < n.size(); i++)
    {
        std::cout << "\nn " << n[i];

        if(n[i] == 1) h += n[i];
        else g *= n[i];

        std::cout << "\ng " << g;
    }
    sum = g+h;

    return sum;
}

int main()
{
    Data data;

    std::vector<std::string>box;

    std::vector<int>num;

    std::string in = "001100011011110101101110";

    //00110001 10111101 01101110

    std::cout << "Str " << in << std::endl;

    if(in.size() > 8)
    {
        std::string newin = in;

        for(int i = 0; i < in.size(); i+=8)
        {
            std::string newin = in;

            newin = newin.substr(i);
            newin.erase(8);

            std::cout << "\ni = " << newin << std::endl;

            box.push_back(newin);
        }
    }

    for(int i = 0; i < box.size(); i++)
    {
        std::cout << "\n\n" << i << "." << box[i] << std::endl;

        for(int y = 0; y < box[i].size(); y++)
        {
            std::string r = box[i];
            r = r.substr(y);
            r.erase(1);

            std::cout << std::endl << r;

            char t[box[i].size()+1];
            strcpy(t, box[i].c_str());

            std::cout << " " << t[y];

            char d[sizeof(t)];
            d[0] = t[7];
            d[1] = t[6];
            d[2] = t[5];
            d[3] = t[4];
            d[4] = t[3];
            d[5] = t[2];
            d[6] = t[1];
            d[7] = t[0];

            std::cout << " " << d[y];

            if(d[y] == '1')
            {
                std::cout << " Mkay = ";

                std::cout << y+1;

                num.push_back(y+1);
            }
            else std::cout << " NKay NUL";

            std::cout << " " << y;

            if(y >= 7)
            {
                for(int u = 0; u < num.size(); u++)
                {
                    int b = multiple(num);
                    std::cout << " " << box[i] << " = " << b << " : " << data.BtT(b);
                    num.clear();
                }
            }

        }



    }

    return 0;
}
