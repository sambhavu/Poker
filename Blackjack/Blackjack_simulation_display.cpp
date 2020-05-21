#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstdlib> 
#include<conio.h>
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
	int myvalue; 
	
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
	void show_ohand(); 
	
	void bet();
	 
	void show_next(); 
	void get_score(vector<string> h);
	void get_oscore(vector<string> h); 
	
	bool stand; 
	bool bust; 
	bool obust; 
	
	int score, oscore; 
	
	
};  

void poker:: show_ohand()
{
	
	cout<<"\nD["<<ohand[0]<<"]\n";
}

void poker::bet()
{
	int amount;
	//cout<<"Money: $"<<money<<"\n";
	//cout<<"Enter Bet Amount: $";
	//cin>> amount; 
	int enoughmoney=1;
	
	/*
	while(enoughmoney)
	{ 
		if(amount>money)
		{
		cout<<"Not Enough Money\nEnter Bet Amount $\n:";
			cin>>amount; 
		 }
		 else{
		 	enoughmoney=0;
		 }
	 } 
	 
	 */
	 
	 if(myvalue<18)
	 {
	 	amount=money*.05; 
	 }
	 else if(myvalue<21){ 
	 	amount=money*.1; 
	 }
	 else if(myvalue==21)
	 {
	 	amount=money*.95; 
	 }
	 
	 bet_amount=amount; 
	 money=money-amount;
	 pot=pot+amount+amount;
	
}




void poker::show_hand()
{
	int size;
	size=hand.size(); 
	
	cout<<"\nH[";
	
	for(int i=0; i<size; i++) 
	{
		
	   cout<<hand[i]<<" ";
    }
    
    cout<<"]\n"; 
}

    


void poker:: get_score(vector<string> h) 
{
	int s;

	string card; 
	int value=0; 
    char v; 
    bool doubled =false; 
    char m; 

stand=false; 

 do
 { 
 	bust=false;
 	s= hand.size();
 	myvalue=0;
	for(int i=0; i<s; i++)
	{
		
		card=hand[i];
		v=card.at(0); 
		
		if(v=='2')
		{
			myvalue+=2; 
		}
		
		else if (v=='3') 
		{
			myvalue+=3;
		}
		else if(v=='4') 
		{
			myvalue+=4;
		}
		else if(v=='5')
		{
			myvalue+=5; 
		}
		else if(v=='6')
		{
			myvalue+=6; 
		}
		else if(v=='7')
		{
			myvalue+=7; 
		}
		else if(v=='8')
		{
			myvalue+=8; 
		}
		else if(v=='9')
		{
			myvalue+=9; 
		}
		else if(v=='t' || v=='j' || v=='q' || v=='k') 
		{
			myvalue+=10; 
		}
		
		else if(v=='a')
		{
			if(myvalue+11 > 21)
			{
				myvalue+=1; 
			}
			
			else{
				
			    myvalue+=11; 
			} 
		}
	} 
	score=myvalue;
	if(myvalue>21)
	{
		bust=true; 
		//cout<<"\nScore: "<<value<<" BUST\n"; 
		stand=true;
		break;
	}
	
//	cout<<"POT: $"<<pot<<"\n"; 
	//cout<<"\nValue: "<<value<<"\n"; 
    bet(); 
	
	/*
	if(doubled)
	{
		score=value; 
		stand=true; 
	}*/
		
	//cout<<"\n d:done \n h: hit\n b: double down\n s: split\n:"; 
	//cin>>m; 
	
	if(myvalue>18)
	{
		stand=true;
		score=myvalue; 
	}
	
	else
	{
		get_hand(); 
		//show_hand(); 
	}
	
	/*
	else if(m=='b')
	{
		pot=pot+bet_amount; 
		bet_amount=bet_amount*2; 
		get_hand(); 
		bool doubled= true; 
		get_score(hand); 
		
	}*/
	
	/*
	else if(m=='s')
	{
		
		cout<<"\nsplit not yet functional";
		
	}*/
	
		
	
	
}while(!stand); 
		
		
		
	} 
	


void poker:: get_oscore(vector<string> h)
{
	int s;
	
	string card; 
	int value=0; 
    char v; 
    bool ace=false; 
    bool doubled =false; 
    char m; 

stand=false; 

 do
 {
 	s= ohand.size();
 	value=0;
 	obust=false;
 	//cout<<"\nD[";
	for(int i=0; i<s; i++)
	{
		//cout<<ohand[i]<<" "; 
		
		card=ohand[i];
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
				
			    value+=11; 
			} 
		}
	} 
	//cout<<"]\n";
	
	if(value>21)
	{
		//cout<<"Dealer Bust\n"; 
		obust=true; 
		stand=true; 
		break;
	}
		
	else if(value<21 && value>=17)
	{
		//cout<<"Dealer is Done\n"; 
		stand=true;
		oscore=value; 
		obust=false;
		break;
	}
	
	else if(value<17)
	{
		//cout<<"Dealer Hit\n"; 
		get_o_hand(); 
		//show_ohand(); 
	}
	
	
	}while(!stand); 
	


}



void poker:: play()
{
	string move; 
	char gameplay; 
	int dealer; 
	int pnl; 
	
		for(int i=0; i<=3; i++)
{
	while(money>2)
		
		{
			//cout<<"\nMoney $"<<money;
			
			pot=0; 
			dealer=0;
			
			
			pnl=money; 
			
			dealer=0; 
			reset_deck(); 
			get_hand(); 
			get_hand(); 
			get_o_hand(); 
			get_o_hand(); 
			stand=false; 
			//show_ohand(); 
			//show_hand(); 
			
			bust=false;
			obust=false;
			
			
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
			cout<<"************************************\n";
			cout<<"\nstarted with:: "<<pnl;
			cout<<"\nCurrent Money:: "<<money;
			cout<<"\nPot:: "<<pot;  
			cout<<"\n\n******SCORE******\n";
			cout<<"Your Score: "<<score;
			cout<<"\nDealer score: "<<oscore;
			cout<<"\n\nDid you bust: "<<bust; 
			cout<<"\n Did the dealer bust: "<<obust; 
			cout<<"\n";
			
			
			
			
			if(bust && obust) 
			{
				//cout<<"Both Busted, split\n";
				money+=pot/2;
				dealer+=pot/2; 
				
			}
			else if(bust)
			{
				//cout<<"You Busted\n"; 
				dealer+=pot; 
			}
			else if(obust)
			{
				//cout<<"Dealer Busted\n"; 
				money=money+pot; 
			} 
			else if(score>oscore) 
			{
				//cout<<"You won\n";
				
				money=money+pot; 
			}
			else if(oscore>score)
			{
				//cout<<"Dealer Won\n";
				dealer+=pot; 
			}
			else if(score==oscore)
			{
				//cout<<"Even score, Split Pot\n"; 
				money+=pot/2; 
				dealer+=pot/2; 
			}
			else{
				//cout<<"\nFailure to split pot";
			}
			
			/*
			
			cout<<"\nYour Winnings: $"<<money-pnl;
			cout<<"\nDealer Winnings: $"<<dealer;
			*/
			cout<<money<<"\n";
		}
	}
	/*
	cout<<"\n***BLACKJACK RESULTS***\n\nCash in Amount: $"<<CashinAmount; 
	cout<<"\nExit with $"<<money;
	cout<<"\nProfit $"<<money-CashinAmount; 
	*/
	
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
	ohand.clear(); 
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
	 cout<<"BlackJack Simulation\n";
     cout<<"Cash in Chips: ";
     cin>> CashinAmount; 
     money=CashinAmount;
     cout<<"\n\n";
     clrscr();
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
