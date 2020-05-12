#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstdlib> 
using namespace std;

class poker	
{
	public: 
	const int blind = 50; 
	int CashinAmount;
	
	
	std::vector<string> deck;
	std::vector<int> dealt_cards;
	std::vector<string> hand; 
	
	poker();
	void play(); 
	
	void reset_deck();
	string deal_card(); 
	void get_hand();
	void show_hand();
	
	
};

void poker::show_hand()
{
	cout<<hand[0]<<"\n"<<hand[1]<<"\n"; 
}

void poker:: play()
{
	string move; 
	
	while(CashinAmount>0)
	{
		reset_deck();
		get_hand();
		show_hand();
		
		
		
	}
	
}


void poker::get_hand()
{
	std::string c1;
	std::string c2; 
	
	c1=deal_card();
	c2=deal_card();
	
	hand.push_back(c1);
	hand.push_back(c2); 
	
}
void poker::reset_deck(){
	
	deck.clear();
	hand.clear();
	dealt_cards.clear();
	
	std::vector<string> type;
	std::vector<string> value;
	
	
	type.push_back("d");
	type.push_back("s");
	type.push_back("h");
	type.push_back("c");
	
	std::string v;
	
	for(int i=2; i<=10; i++)
	{
		v=std::to_string(i);
		value.push_back(v);
	}
	
	value.push_back("j");
	value.push_back("q");
	value.push_back("k");
	value.push_back("a");
	
	std::string card;
	
	int i, j;
	
	i=value.size();
	j=type.size();
	
	for(int k=0; k<i; k++) 
	{
		for(int d=0; d<=3; d++)
		{
			card=value[k]+type[d];
			deck.push_back(card);
		}
		
	}
	
}



poker::poker()
{
	 cout<<"b: bet, c: check, f: fold\nBlinds : 50 \n";
     cout<<"Cash in Chips: ";
     cin>> CashinAmount; 
     
     play();
	 
}


string poker::deal_card()
{
	//pick random card from deck 
	//remove card from deck
	//return card 
	int cards;
	int thecard; 
	int dealt;
	
	bool different = 1;
	int check;
	
    std::string card; 
    
    cards=deck.size(); 
	thecard=rand() % cards; 
	
	dealt=dealt_cards.size();
	
	if(dealt==0)
	{
		dealt_cards.push_back(thecard);
		card=deck[thecard]; 
	    return card;
	}
	
	else{
	
	    while(different)
	    {
	    	check = 0; 
	    	
		    for(int i=0; i<dealt; i++)
		    { 
		    	if(thecard==dealt_cards[i])
		    	{
		    		thecard=rand() % cards; 
		    		check=1;
		    		break;
		    	}
		    }
		    
		    if(check==0)
		    {
		    	different=0;
		    }
		    
	    }
	}
	
	
	
    dealt_cards.push_back(thecard);
	card=deck[thecard]; 
	return card;
	
} 


int main()
{
	poker player;
	
}
