#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstdlib> 
using namespace std;

vector<string> testv =
{
	"qc",
	"jc",
	"ac",
	"3d",
	"kc",
	"tc",
};

vector<string> straight = 

{
	"a",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"t",
	"j",
	"q",
	"k",
	"a",
	"2",
	"3",
	"4",
	"5",
}; 
	


class poker	
{
	public: 
	
	int CashinAmount;
	int money;
	int pot;
	int bet_amount; 
	
	
	std::vector<string> deck;
	std::vector<int> dealt_cards;
	std::vector<string> hand; 
	std::vector<string> ohand; //opponents hand
	std::vector<string> table;

	
	poker();
	void play(); 
	
	void reset_deck();
	string deal_card(); 
	void get_hand();
	void get_o_hand(); 
	void show_hand();
	
	void bet();
	 
	void show_next(); 
	void get_score(vector<string> h);
	void get_oscore(vector<string> h); 
	
	bool stand; 
	bool bust; 
	bool obust; 
	
	int score, oscore; 
	
	
};  


void poker::bet()
{
	int amount;
	cout<<"Enter Bet Amount \n:";
	cin>> amount; 
	int enoughmoney=1;
	
	while(enoughmoney)
	{ 
		if(amount>money)
		{
		cout<<"Not Enough Money\nEnter Bet Amount \n:";
			cin>>amount; 
		 }
		 else{
		 	enoughmoney=0;
		 }
	 } 
	 
	 money=money-amount;
	 pot=pot+amount;
	
}




void poker::show_hand()
{
	cout<<"\nH[";
	cout<<hand[0]<<" "<<hand[1]<<"]\n"; 
}


void poker:: get_score(vector<string> h) 
{
	int s;
	s= hand.size();
	string card; 
	int value=0; 
    char v; 
    bool ace=false; 
    bool doubled =false; 
    char m; 

stand=false; 

 while(!stand)
 {
	for(int i=0; i<s; i++)
	{
		card=hand[i];
		v=card.at(0); 
		
		if(v=='2')
		{
			value+=2; 
		}
		
		else if (v=='3') 
		{
			value+=3;
		}
		else if(v=='4') 
		{
			value+=4;
		}
		else if(v=='5')
		{
			value+=5; 
		}
		else if(v=='6')
		{
			value+=6; 
		}
		else if(v=='7')
		{
			value+=7; 
		}
		else if(v=='8')
		{
			value+=8; 
		}
		else if(v=='9')
		{
			value+=9; 
		}
		else if(v=='t' || v=='j' || v=='q' || v=='k') 
		{
			value+=10; 
		}
		
		else if(v=='a')
		{
			if(value+11 > 21)
			{
				value+=1; 
			}
			
			else{
				
			    ace=true; 
			} 
		}
	} 
	
	if(value>21)
	{
		bust=true; 
		cout<<"\nBUST"; 
		break;
	}
	
	if(doubled)
	{
		score=value; 
		stand=true; 
	}
		
	cout<<value<<"\n d:done \n h: hit, d: double down\n s: split"; 
	cin>>m; 
	
	if(m=='d')
	{
		stand=true;
		score=value; 
	}
	
	else if(m=='h')
	{
		get_hand(); 
	}
	
	else if(m=='d')
	{
		pot=pot+bet_amount; 
		bet_amount=bet_amount*2; 
		get_hand(); 
		bool doubled= true; 
		get_score(hand); 
		
	}
	
		
	else if(m=='s')
	{
		
		
	}
	
		
	
	
}
		
		
		
	} 
	


void poker:: get_oscore(vector<string> h)
{
	
}



void poker:: play()
{
	string move; 
	char gameplay; 
	int dealer; 
	int pnl; 
	
	while(money>0)
	{  
		cout<<"\nPlay Again? Y N \n "; 
		cin>> gameplay; 
		
		if(gameplay == 'Y')
		{
			cout<<"\nMoney $"<<money;
			
			pnl=money; 
			dealer=0; 
			reset_deck(); 
			get_hand(); 
			get_hand(); 
			get_o_hand(); 
			get_o_hand(); 
			stand=false; 
			show_hand(); 
			
			//finish my hand 
			
			while(!stand) 
			{
				get_score(hand); 
				
			} 
			
			stand=false; 
			
			
			//finish dealer hand 
			
			while(!stand)
			{
				get_oscore(ohand); 
			}
			
			if(bust && obust) 
			{
				money+=pot/2;
				dealer=pot/2; 
				
			}
			else if(bust)
			{
				dealer=pot; 
			}
			else if(obust)
			{
				money+=pot; 
			} 
			else if(score>oscore) 
			{
				money+=pot; 
			}
			else if(oscore>score)
			{
				dealer=pot; 
			}
			else if(score==oscore)
			{
				money+=pot/2; 
				dealer+=pot/2; 
			}
			else{
				cout<<"\nFailure to split pot";
			}
			
			
			
			cout<<"\nYour Winnings: $"<<money-pnl;
			cout<<"\nDealer Winnings: $"<<Dealer;
			
			
		}
		
		else{
		
		    break;
			
		}
	}
	
	cout<<"Cash in Amount: $"<<CashinAmount; 
	cout<<"\nExit with $"<<money;
	cout<<"\nProfit $"<<money-CashinAmount; 
	
}


void poker::get_hand()
{
	std::string c1;
	
	c1=deal_card();
	
	hand.push_back(c1);
	
}

void poker::get_o_hand()
{
	std::string c1;
	
	
	c1=deal_card();
	
	
	ohand.push_back(c1);
	
}



void poker::reset_deck(){
	
	deck.clear();
	hand.clear();
	dealt_cards.clear();
	table.clear(); 
	
	std::vector<string> type;
	std::vector<string> value;
	
	
	type.push_back("d");
	type.push_back("s");
	type.push_back("h");
	type.push_back("c");
	
	std::string v;
	
	for(int i=2; i<=9; i++)
	{
		v=std::to_string(i);
		value.push_back(v);
	}
	
	value.push_back("t");
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
	 cout<<"Equity Calculator: n for next \n";
     cout<<"Cash in Chips: ";
     cin>> CashinAmount; 
     money=CashinAmount;
     cout<<"\n\n";
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
