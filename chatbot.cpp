/*
 	 Problem Statement:
 	 	 	 	 	 Develop an elementary chatbot for any suitable customer interaction
 	 	 	 	 	 application.
 */

#include<bits/stdc++.h>
using namespace std;

class Chatbot
{
    private:
        vector<pair<vector<string>, vector<string>>> data;

    public:

        Chatbot()
        {
            data =
            	{
                    {
                    	{ "HI", "HELLO" },  { "HI THERE!", "HOW ARE YOU?", "HI!" }
                    },
					{
						{ "FINE" }, { "OK." }
					},
            		{

						{ "WHAT IS YOUR NAME?" }, { "MY NAME IS CHATBOT.", "YOU CAN CALL ME CHATBOT.","WHY DO YOU WANT TO KNOW MY NAME?" }
                	},
                    {
                    	{ "HOW ARE YOU?" }, { "I'M DOING FINE!", "I'M DOING WELL AND YOU?", "WHY DO YOU WANT TO KNOW HOW AM I DOING?" }
                    },
                    {
                    	{ "WHO ARE YOU?" }, { "I'M AN A.I PROGRAM.", "I THINK THAT YOU KNOW WHO I'M.", "WHY ARE YOU ASKING?" }
                    },
                    {
                    	{ "ARE YOU INTELLIGENT?" }, { "YES, OFCORSE.", "WHAT DO YOU THINK?", "ACTUALY, I'M VERY INTELLIGENT!" }
                    },
                    {
                    	{ "ARE YOU REAL?" }, { "DOES THAT QUESTION REALLY MATERS TO YOU?", "WHAT DO YOU MEAN BY THAT?", "I'M AS REAL AS I CAN BE." }
                    },
					{
						{ "BYE" }, { "GOODBYE!!", "BYE-BYE!!" }
					}
                };
        }
//		transform(input.begin(),input.end(),input.begin(),::toupper);
//		data[i].first.begin()
        void response(string input)
        {
        	transform(input.begin(), input.end(), input.begin(), ::toupper);

            for(unsigned int i=0; i<data.size(); i++)
            {
                if(find(data[i].first.begin(), data[i].first.end(), input) != data[i].first.end())
                {
                	int res = rand() % data[i].second.size();
                	
                    cout << "\tCHATBOT : " << data[i].second[res] << "\n";
                    return;
                }
                else if(input == "STOP")
                {
                	cout << "\n\t THANK YOU...!!";
                	exit(0);
                }
            }

            cout << "\tCHATBOT : SORRY, I AM NOT GETTING...\n";
        }
};

int main()
{
    string input;
    Chatbot obj;

    cout<<"\t\t=========== ChatBot ===========\n\n"<<endl;

    while(true)
    {
        cout << "\tYOU : ";
        getline(cin, input);

        obj.response(input);
        cout << "\n";
    }

    return 0;
}
